#pragma once
#include "../../common.hpp"

class c_PlayerEyes {
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	void setViewOffset(Vector3 viewOffset) {
		memory.write<Vector3>(getAddress() + oPlayerEyes::oViewOffset, viewOffset);
	}
	Vector3 getViewOffset() {
		return memory.read<Vector3>(getAddress() + oPlayerEyes::oViewOffset);
	}
};