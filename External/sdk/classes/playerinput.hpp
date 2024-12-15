#pragma once
#include "../../common.hpp"

class c_PlayerInput {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	Vector2 getViewAngles() {
		return memory.read<Vector2>(getAddress() + oPlayerInput::oViewAngles);
	}
	void setViewAngles(Vector2 newAngle) {
		memory.write<Vector2>(getAddress() + oPlayerInput::oViewAngles, newAngle);
	}
	Vector4 getRotation() {
		return memory.read<Vector4>(getAddress() + oPlayerInput::oBodyRotation);
	}
};