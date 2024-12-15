#pragma once
#include "../../common.hpp"

class c_prefab {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	std::string className() {
		return memory.read_str(memory.read_chain(getAddress(), { 0x10 })); // 0x0	-> 0x10	-> 0x0
	}
	std::string prefabName() {
		return memory.read_str(memory.read_chain(getAddress() + 0x10, { 0x30, 0x60 })); // 0x10 -> 0x30 -> 0x60 -> 0x0
	}
	Vector3 position() {
		return memory.read<Vector3>(memory.read_chain(getAddress() + 0x10, { 0x30, 0x30, 0x8, 0x38 }) + 0x90);
	}
};