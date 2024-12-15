#pragma once
#include "../../common.hpp"

inline std::vector<std::pair<std::string, std::string>> shortStrings = {
	{ "stone", "stone ore" },
	{ "metal", "metal ore" },
	{ "sulfur", "sulfur ore" },
	{ "wood-pile", "wood pile" },

	{ "collectable/mushroom", "mushroom" },
	{ "collectable/pumpkin", "pumpkin" },
	{ "collectable/corn", "corn" },
	{ "collectable/potato", "potato" },

	{ "collectable/wood", "wood pickup" },
	{ "collectable/stone", "stone pickup" },
	{ "collectable/metal", "metal pickup" },
	{ "collectable/sulfur", "sulfur pickup" },
	{ "collectable/hemp", "hemp pickup" },
	{ "collectable/diesel", "diesel pickup" },
};

class c_prefab {
private:
	std::string _className = "", _prefabName = "";
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	std::string className() {
		if (getAddress() == 0) return "";

		uint64_t objPtr = memory.read<uint64_t>(getAddress() + 0x0);
		if (objPtr == 0) return "";

		uint64_t namePtr = memory.read<uint64_t>(objPtr + 0x10);
		if (namePtr == 0) return "";

		return memory.read_str(namePtr + 0x0);
	}
	std::string prefabName(bool shortName = false) {
		if (getAddress() == 0) return "";

		uint64_t cachePtr = memory.read<uint64_t>(getAddress() + 0x10);
		if (cachePtr == 0) return "";

		uint64_t entityPtr = memory.read<uint64_t>(cachePtr + 0x30);
		if (entityPtr == 0) return "";

		uint64_t namePtr = memory.read<uint64_t>(entityPtr + 0x60);
		if (namePtr == 0) return "";

		std::string name = memory.read_str(namePtr + 0x0);
		if (!shortName || name == "") return name;

		for (auto& pair : shortStrings) {
			if (name.find(pair.first) != std::string::npos) {
				return pair.second;
			}
		}

		return name;
	}
	Vector3 position() {
		uint64_t cachePtr = memory.read<uint64_t>(getAddress() + 0x10);
		if (cachePtr == 0) return Vector3().zero();

		uint64_t entityPtr = memory.read<uint64_t>(cachePtr + 0x30);
		if (entityPtr == 0) return Vector3().zero();

		uint64_t entityPtr2 = memory.read<uint64_t>(entityPtr + 0x30);
		if (entityPtr2 == 0) return Vector3().zero();

		uint64_t transformPtr = memory.read<uint64_t>(entityPtr2 + 0x8);
		if (transformPtr == 0) return Vector3().zero();

		uint64_t positionPtr = memory.read<uint64_t>(transformPtr + 0x38);
		if (positionPtr == 0) return Vector3().zero();

		return memory.read<Vector3>(positionPtr + 0x90);
	}
};