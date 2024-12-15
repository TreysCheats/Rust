#include "common.hpp"
#include "TlHelp32.h"

bool findClient() {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(pe32);
		if (Process32First(hSnap, &pe32)) {
			while (Process32Next(hSnap, &pe32)) {
				if (!_wcsicmp(pe32.szExeFile, L"RustClient.exe")) {
					memory.pid = pe32.th32ProcessID;
					break;
				}
			}
		}
		CloseHandle(hSnap);
		return true;
	}
	return false;
}
bool findModule() {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, memory.pid);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 me32;
		me32.dwSize = sizeof(me32);
		if (Module32First(hSnap, &me32)) {
			while (Module32Next(hSnap, &me32)) {
				if (!_wcsicmp(me32.szModule, L"GameAssembly.dll")) {
					memory.module = (uintptr_t)me32.modBaseAddr;
					break;
				}
			}
		}
		CloseHandle(hSnap);
		return true;
	}
	return false;
}
bool createHandle() {
	memory.handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, memory.pid);
	return memory.handle != INVALID_HANDLE_VALUE;
}

void shootInAir(c_ModelState* state, c_PlayerWalkMovement* movement) {
	state->setFlag(c_ModelState::Flags::OnGround);
	movement->setGrounded(1.f);
}
void spiderman(c_PlayerWalkMovement* movement) {
	movement->setGroundAngle(0.f);
	movement->setGroundAngleNew(0.f);
}
void infiniteJump(c_PlayerWalkMovement* movement) {
	movement->setGroundTime(99999.f);
	movement->setJumpTime(0.51f);
	movement->setLandTime(0.3f);
}
void onLadder(c_ModelState* state) {
	state->setFlag(c_ModelState::Flags::OnLadder);
}

int main() {
	findClient();
	findModule();
	createHandle();

	utils.print("\033[33m[Process Information]\n");
	utils.print(memory.pid == 0 ? "\033[31m[-] Failed to find RustClient.exe\n" : "\033[32m[+]\033[37m RustClient.exe PID: \033[36m" + std::to_string(memory.pid) + "\n");
	utils.print(memory.module == 0 ? "\033[31m[-] Failed to find GameAssembly.dll\n" : "\033[32m[+]\033[37m GameAssembly.dll Address: \033[36m0x" + utils.decToHex(memory.module) + "\n");
	utils.print(memory.handle == INVALID_HANDLE_VALUE ? "\033[31m[+] Failed to create handle\n" : "\033[32m[+]\033[37m ProcessHandle: \033[36m0x" + utils.decToHex((uint64_t)memory.handle) + "\n");
	utils.print("\n\033[33m[Cheat Information]\n");

	BaseNetworkable.init();
	
	std::unordered_map<std::string, int> count;
	uint64_t items = BaseNetworkable.getItems();
	for (int i = 0; i < 10000; i++) {
		c_prefab* entity = memory.read<c_prefab*>(items + 0x20 + (i * 0x8));
		std::string name = entity->className();
		//count[name]++;
		if (name == "CollectibleEntity") {
			std::cout << entity->prefabName() << std::endl;
		}
	}

	for (const auto& entry : count) {
		std::cout << "[+] " << entry.second << "x " << entry.first << std::endl;
	}

	//uint64_t items = BaseNetworkable.getItems();
	//for (int i = 0; i < 500; i++) {
	//	c_prefab* entity = memory.read<c_prefab*>(items + 0x20 + (i * 0x8));
	//	if (entity->className() == "OreResourceEntity") {
	//		std::string name = entity->prefabName();
	//		Vector3 pos = entity->position();
	//
	//		if (name.find("metal") != std::string::npos) name = "metal ore";
	//		if (name.find("stone") != std::string::npos) name = "stone ore";
	//		if (name.find("sulfur") != std::string::npos) name = "sulfur ore";
	//		if (name.find("wood-pile") != std::string::npos) name = "wood pile";
	//
	//		std::cout << name << " @ (" << pos.x << ", " << pos.y << ", " << pos.z << ") [0x" << std::hex << entity->getAddress() << std::dec << "] [" << i << "]" << std::endl;
	//	}
	//}
}

// TODO:
// get view matrix and print out calculations for esp. then make it an internal
// fix prefab.hpp

/*

Reload Bar:
	- BaseProjectile -> isReloading
	- BaseProjectile -> reloadTime

*/