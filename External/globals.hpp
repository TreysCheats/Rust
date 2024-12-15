#pragma once
#include "common.hpp"

struct t_weaponInfo {
	Vector4 recoilValue{};
	Vector4 spreadValue{};
	Vector2 swayValue{};
	bool automatic{};

	bool hasSetRecoil = false;
	bool hasSetSpread = false;
	bool hasSetSway = false;
};

class ezpz {
public:
	const int screen_w = GetSystemMetrics(SM_CXSCREEN);
	const int screen_h = GetSystemMetrics(SM_CYSCREEN);
	const int screen_center_x = screen_w / 2;
	const int screen_center_y = screen_h / 2;

	std::string weapon_name = "";
	std::unordered_map<std::string, t_weaponInfo> weapon_map{};
	t_weaponInfo weapon_info{};
} globals;