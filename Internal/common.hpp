#pragma once

/* libraries */
#include <unordered_map>
#include <immintrin.h>
#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <string>
#include <cmath>
#include <array>

/* imgui */
#include <d3d11.h>
#include <dxgi.h>
#include "dependencies/rendering/kiero/kiero.h"
#include "dependencies/rendering/imgui/imgui.h"
#include "dependencies/rendering/imgui/imgui_impl_win32.h"
#include "dependencies/rendering/imgui/imgui_impl_dx11.h"
#include "dependencies/rendering/imgui/imgui_internal.h"
#include "dependencies/rendering/imgui/ImGui Extensions/imgui_extensions.h"

/* ui */
#include "dependencies/rendering/drawing/ui.hpp"

/* memory */
#include "dependencies/controller/memory.hpp"
#include "dependencies/controller/decrypt.hpp"

/* utils */
#include "dependencies/utils/math.hpp"
#include "dependencies/utils/utils.hpp"

/* globals */
#include "globals.hpp"

/* sdk */
#include "sdk/offsets.hpp"
#include "sdk/classes/basemounted.hpp"
#include "sdk/classes/basenetworkable.hpp"
#include "sdk/classes/baseplayer.hpp"
#include "sdk/classes/baseprojectile.hpp"
#include "sdk/classes/bone.hpp"
#include "sdk/classes/camera.hpp"
#include "sdk/classes/item.hpp"
#include "sdk/classes/itemdefinition.hpp"
#include "sdk/classes/modelstate.hpp"
#include "sdk/classes/playereyes.hpp"
#include "sdk/classes/playerinput.hpp"
#include "sdk/classes/playermodel.hpp"
#include "sdk/classes/playerwalkmovement.hpp"
#include "sdk/classes/prefab.hpp"

/* misc */
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;