#pragma once
#include "../../common.hpp"
#include "basemounted.hpp"
#include "bone.hpp"
#include "item.hpp"
#include "modelstate.hpp"
#include "playereyes.hpp"
#include "playerinput.hpp"
#include "playermodel.hpp"
#include "playerwalkmovement.hpp"
#include "prefab.hpp"

class c_BasePlayer : c_prefab {
public:
	static enum Flags
	{
		Unused1 = 1,
		Unused2 = 2,
		IsAdmin = 4,
		ReceivingSnapshot = 8,
		Sleeping = 16,
		Spectating = 32,
		Wounded = 64,
		IsDeveloper = 128,
		Connected = 256,
		ThirdPersonViewmode = 1024,
		EyesViewmode = 2048,
		ChatMute = 4096,
		NoSprint = 8192,
		Aiming = 16384,
		DisplaySash = 32768,
		Relaxed = 65536,
		SafeZone = 131072,
		ServerFall = 262144,
		Incapacitated = 524288,
		Workbench1 = 1048576,
		Workbench2 = 2097152,
		Workbench3 = 4194304
	};

	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	c_PlayerModel* playerModel() {
		return memory.read<c_PlayerModel*>(getAddress() + oBaseEntity::oModel);
	}
	c_PlayerInput* playerInput() {
		return memory.read<c_PlayerInput*>(getAddress() + oBasePlayer::oPlayerInput);
	}
	c_PlayerEyes* eyes() {
		return memory.read<c_PlayerEyes*>(getAddress() + oBasePlayer::oEyes);
	}
	c_ModelState* modelState() {
		return memory.read<c_ModelState*>(getAddress() + oBasePlayer::oModelState);
	}
	c_PlayerWalkMovement* playerWalkMovement() {
		return memory.read<c_PlayerWalkMovement*>(getAddress() + oBasePlayer::oBaseMovement);
	}
	c_BaseMounted* mounted() {
		return memory.read<c_BaseMounted*>(getAddress() + oBasePlayer::oMountable);
	}

	bool isDead() {
		return memory.read<int>(getAddress() + oBaseCombatEntity::oLifestate); // 0 = alive, 1 = dead
	}
	std::string getName() {
		std::wstring name = memory.read_wstr(memory.read<uint64_t>(getAddress() + oBasePlayer::oDisplayName) + 0x14);
		if (name.length() > 32 || name.length() < 2)
			return "";
		return std::string(name.begin(), name.end());
	}
	float getDistance(Vector3 target) {
		c_bone* bone = getBone(bone_list::head);
		return bone->position().distance(target);
	}
	
	c_item* getHeldItem() {
		int active_id = memory.decrypt_ulong(memory.read<uint64_t>(getAddress() + oBasePlayer::oActiveItemID));
		if (active_id == 0) return nullptr;
		uint64_t inventory = memory.decrypt_inventory(memory.read<uint64_t>(getAddress() + oBasePlayer::oInventory));
		uint64_t belt = memory.read<uint64_t>(inventory + 0x60);
		uint64_t list = memory.read<uint64_t>(belt + 0x20);
		uint64_t contents = memory.read<uint64_t>(list + 0x10);
		for (int i = 0; i < 6; i++) {
			if (contents != 0) {
				c_item* item = memory.read<c_item*>(contents + 0x20 + (i * 0x8));
				if (!memory.valid(item->getAddress())) continue;
				uint64_t item_id = memory.read<uint64_t>(item->getAddress() + 0xD0);
				if (item_id == active_id) return item;
			}
		}
		return nullptr;
	}

	bool hasFlag(Flags flag) { return (memory.read<int>(getAddress() + oBasePlayer::oPlayerFlags)) & flag; }
	void setFlag(Flags flag) {
		int current_flags = memory.read<int>(getAddress() + oBasePlayer::oPlayerFlags);
		memory.write<int>(getAddress() + oBasePlayer::oPlayerFlags, current_flags |= flag);
	}
	void unsetFlag(Flags flag) {
		int current_flags = memory.read<int>(getAddress() + oBasePlayer::oPlayerFlags);
		if (hasFlag(flag)) {
			current_flags -= flag;
			memory.write<int>(getAddress() + oBasePlayer::oPlayerFlags, current_flags);
		}
	}
	c_bone* getBone(bone_list bone) {
		return memory.read<c_bone*>(memory.read_chain(getAddress() + oBaseEntity::oModel, { 0x50 }) + 0x20 + (bone * 0x8));
	}
};