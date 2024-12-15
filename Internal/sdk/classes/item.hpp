#pragma once
#include "../../common.hpp"
#include "itemdefinition.hpp"
#include "baseprojectile.hpp"

class c_item {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	c_ItemDefinition* itemDefinition() {
		return memory.read<c_ItemDefinition*>(getAddress() + oItem::oItemDefinition);
	}
	c_BaseProjectile* baseProjectile() {
		return memory.read<c_BaseProjectile*>(getAddress() + oItem::oBaseProjectile);
	}
	bool valid() {
		return baseProjectile();
	}
};