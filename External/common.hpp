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
#include <cmath>

/* memory */
#include "dependencies/controller/memory.hpp"

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