#pragma once
#include "../../common.hpp"

class c_BaseMounted {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	void setCanHoldItems(bool value) {
		memory.write<bool>(getAddress() + oBaseMountable::oCanWieldItems, value);
	}
};