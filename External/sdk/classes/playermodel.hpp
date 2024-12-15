#pragma once
#include "../../common.hpp"

#define SKINTYPE_FEMALE 1

class c_PlayerModel {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	Vector3 targetVelocity() {
		return memory.read<Vector3>(getAddress() + 0x0); // newVelocity
	}
	bool isLocalPlayer() {
		return memory.read<bool>(getAddress() + 0x0); // isLocalPlayer
	}
	bool isNPC() {
		return memory.read<bool>(getAddress() + 0x0); // isNPC
	}
	bool isVisible() {
		return memory.read<bool>(getAddress() + 0x0); // isVisible
	}
};