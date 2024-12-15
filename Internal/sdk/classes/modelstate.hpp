#pragma once
#include "../../common.hpp"

inline class c_ModelState {
public:
	static enum Flags
	{
		Ducked = 1,
		Jumped = 2,
		OnGround = 4,
		Sleeping = 8,
		Sprinting = 16,
		OnLadder = 32,
		Flying = 64,
		Aiming = 128,
		Prone = 256,
		Mounted = 512,
		Relaxed = 1024,
		OnPhone = 2048,
		Crawling = 4096,
		Loading = 8192,
		HeadLook = 16384,
		HasParachute = 32768
	};

	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	void setWaterLevel(float level) {
		memory.write<float>(getAddress() + oModelState::oWaterLevel, level);
	}
	bool hasFlag(Flags flag) {
		return (memory.read<int>(getAddress() + oModelState::oFlags)) & flag;
	}
	void setFlag(Flags flag) {
		int current_flags = memory.read<int>(getAddress() + oModelState::oFlags);
		memory.write<int>(getAddress() + oModelState::oFlags, current_flags |= flag);
	}
	void unsetFlag(Flags flag) {
		int current_flags = memory.read<int>(getAddress() + oModelState::oFlags);
		if (hasFlag(flag)) {
			current_flags -= flag;
			memory.write<int>(getAddress() + oModelState::oFlags, current_flags);
		}
	}
};