#include "common.hpp"

std::vector<std::string> food = { "mushroom", "pumpkin", "potato", "corn" };
std::vector<std::string> collectible = { "wood", "stone", "metal", "sulfur", "hemp", "diesel" };
std::vector<std::string> animals = { "Bear", "Stag", "Wolf", "Pig", "RidableHorse", "Chicken", "Shark" };

void loopThread() {
	int delay = GetTickCount64();
	while (TRUE) {
		if (GetTickCount64() - delay >= 3000) {
			delay = GetTickCount64();

			std::cout << yellow << "[!] " << white << "clearing maps..." << std::endl;
			for (auto& map : globals.maps) {
				map.second.clear();
				map.second.shrink_to_fit();
			}
			std::cout << green << "[+] " << white << "finished clearing maps" << std::endl;

			std::cout << yellow << "[!] " << white << "looping through items and adding classes to maps..." << std::endl;
			uint64_t items = BaseNetworkable.getItems(); // only need to read the first 3000ish
			for (int i = 0; i < 3000; i++) {
				c_prefab* prefab = memory.read<c_prefab*>(items + 0x20 + (i * 0x8));
				if (prefab->getAddress() == 0x0) continue;

				std::string className = prefab->className();
				if (className == "") continue;

				if (className == "OreResourceEntity") globals.maps["ore"].push_back(prefab);
				else if (className == "CollectibleEntity") {
					std::string prefabName = prefab->prefabName();
					if (prefabName == "") continue;

					for (const auto& entry : food) {
						if (prefabName.find(entry) != std::string::npos) {
							globals.maps["food"].push_back(prefab);
							break;
						}
					}
					for (const auto& entry : collectible) {
						if (prefabName.find(entry) != std::string::npos) {
							globals.maps["collectible"].push_back(prefab);
							break;
						}
					}
				}
				/*
				for (const auto& entry : animals) {
					std::string prefabName = prefab->prefabName();
					if (prefabName == "") continue;

					if (prefabName.find(entry) != std::string::npos) {
						globals.maps["animals"].push_back(prefab);
						break;
					}
				}
				*/
			}
			std::cout << green << "[+] " << white << "finished looping through items" << std::endl;
		}
	}
}

bool initialized = false;
void hacks() {
	if (!memory.module) memory.module = (uint64_t)GetModuleHandleA("GameAssembly.dll");
	if (!initialized) {
		BaseNetworkable.init();
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)loopThread, NULL, NULL, NULL);
		
		initialized = true;
	}
}

#pragma region Data
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
#pragma endregion
#pragma region Function Declarations
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#pragma endregion
#pragma region ImGui Functions
LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) return true;
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}
void InitImGui() {
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	#pragma region ImGui
	if (!init) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice))) {
			pDevice->GetImmediateContext(&pContext);

			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;

			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();

			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

			InitImGui();
			init = true;
		}

		else return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	#pragma endregion

	#pragma region Keybinds
	if (GetAsyncKeyState(VK_INSERT) & 1) menu::active = !menu::active;
	if (GetAsyncKeyState(VK_END) & 1) {
		pDevice->Release();
		pSwapChain->Release();
		kiero::shutdown();
	}
	#pragma endregion
	#pragma region Hack Thread
	hacks();
	#pragma endregion
	#pragma region Drawing
	menu::render();
	#pragma endregion
	#pragma region Menu
	if (menu::active) menu::ui();
	#pragma endregion

	#pragma region ImGui
	ImGui::EndFrame();
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
	#pragma endregion
}
#pragma endregion
#pragma region Main Threads
DWORD WINAPI MainThread(LPVOID reserved) {
	bool init_hook = false;
	while (!init_hook) {
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	}
	return true;
}
BOOL WINAPI DllMain(HMODULE hMod, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		if (AllocConsole()) {
			SetConsoleTitleA("Rust Internal | TreyTheHot");
			freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		}
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
	}
	else if (reason == DLL_PROCESS_DETACH) kiero::shutdown();
	return true;
}
#pragma endregion