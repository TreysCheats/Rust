#pragma once
#include "../../common.hpp"

class c_ItemDefinition {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	std::string getShortName() {
		std::wstring shortName = memory.read_wstr(memory.read<uint64_t>(getAddress() + oItemDefinition::oShortname) + 0x14);
		return std::string(shortName.begin(), shortName.end());
	}
	std::string getDisplayName() {
		std::cout << std::hex << getAddress() << std::dec << std::endl;
		uint64_t namePtr = memory.read_chain(getAddress() + 0x28, { 0x18 });
		std::wstring displayName = memory.read_wstr(namePtr + 0x14);
		return (displayName.length() > 128 || displayName.empty()) ? "none" : std::string(displayName.begin(), displayName.end());
	}
};