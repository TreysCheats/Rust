#pragma once
#include "../../common.hpp"

class c_BaseProjectile {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	void setRecoil(bool value) {
		if (value) {
			if (!globals.weapon_map[globals.weapon_name].hasSetRecoil) {
				uint64_t recoilProperties = memory.read<uint64_t>(getAddress() + oBaseProjectile::oRecoil);
				Vector4 recoilValues = memory.read<Vector4>(recoilProperties + oRecoilProperties::oRecoilYawMin);
				if (recoilValues != Vector4(0.f, 0.f, 0.f, 0.f))
					globals.weapon_map[globals.weapon_name].recoilValue = recoilValues;
				memory.write<Vector4>(recoilProperties + oRecoilProperties::oRecoilYawMin, { 0.f, 0.f, 0.f, 0.f });
				globals.weapon_map[globals.weapon_name].hasSetRecoil = true;
			}
		}
		else {
			if (globals.weapon_map[globals.weapon_name].hasSetRecoil) {
				uint64_t recoilProperties = memory.read<uint64_t>(getAddress() + oBaseProjectile::oRecoil);
				memory.write<Vector4>(recoilProperties + oRecoilProperties::oRecoilYawMin, globals.weapon_map[globals.weapon_name].recoilValue);
				globals.weapon_map[globals.weapon_name].hasSetRecoil = false;
			}
		}
	}
	void setSpread(bool value) {
		if (value) {
			if (!globals.weapon_map[globals.weapon_name].hasSetSpread) {
				globals.weapon_map[globals.weapon_name].spreadValue = memory.read<Vector4>(getAddress() + oBaseProjectile::oAimCone);
				memory.write<Vector4>(getAddress() + oBaseProjectile::oAimCone, { -3.f, -3.f, -3.f, -3.f });
				globals.weapon_map[globals.weapon_name].hasSetSpread = true;
			}
		}
		else {
			if (globals.weapon_map[globals.weapon_name].hasSetSpread) {
				memory.write<Vector4>(getAddress() + oBaseProjectile::oAimCone, globals.weapon_map[globals.weapon_name].spreadValue);
				globals.weapon_map[globals.weapon_name].hasSetSpread = false;
			}
		}
	}
	void setSway(bool value) {
		if (value) {
			if (!globals.weapon_map[globals.weapon_name].hasSetSway) {
				globals.weapon_map[globals.weapon_name].swayValue = memory.read<Vector2>(getAddress() + oBaseProjectile::oAimSway);
				memory.write<Vector2>(getAddress() + oBaseProjectile::oAimSway, { 0.f, 0.f });
				globals.weapon_map[globals.weapon_name].hasSetSway = true;
			}
		}
		else {
			if (globals.weapon_map[globals.weapon_name].hasSetSway) {
				memory.write<Vector2>(getAddress() + oBaseProjectile::oAimSway, globals.weapon_map[globals.weapon_name].swayValue);
				globals.weapon_map[globals.weapon_name].hasSetSway = false;
			}
		}
	}
	void changeAutomatic(bool value) {
		memory.write<bool>(getAddress() + oBaseProjectile::oAutomatic, value);
		globals.weapon_map[globals.weapon_name].automatic = value;
	}

	void pushToMap() {
		if (globals.weapon_map.count(globals.weapon_name) <= 0)
			globals.weapon_map[globals.weapon_name] = globals.weapon_info;
	}
	bool isAiming() {
		return memory.read<bool>(getAddress() + oBaseProjectile::oAiming);
	}
	bool isReloading() {
		return memory.read<bool>(getAddress() + oBaseProjectile::oReloading);
	}
	int magazineCapacity() {
		uint64_t primaryMagazine = memory.read<uint64_t>(getAddress() + oBaseProjectile::oPrimaryMagazine);
		return memory.read<int>(primaryMagazine + 0x18); // oCapacity
	}
	int magazineSize() {
		uint64_t primaryMagazine = memory.read<uint64_t>(getAddress() + oBaseProjectile::oPrimaryMagazine);
		return memory.read<int>(primaryMagazine + 0x1C); // oContents
	}
};