#pragma once
#include "common.hpp"
#include "sdk/classes/prefab.hpp"

inline class c_cheats {
public:
	class c_aimbot {
	public:
		// AIMBOT
		bool enabled, prediction;
		bool targetWounded, targetFriendly, targetNPC;
		bool pSilent, pSilentHeli;
		bool smoothing, hitChance;
		float smoothingValue = 0, hitChanceValue = 70;
		float aimFov = 100, pAimFov = 250;

		// EXPLOITS
		bool magicBullet, boneOverride;
		std::string boneOverrideBone = "Head";

		// AIM VISUALS
		bool simProjectile, aimMarker, crosshair;
		bool fovCircle, pSilentFovCircle;
		bool targetSnapline, hitmarker;

		float simProjectileColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, aimMarkerColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, crosshairColor[4] = { 1.0f, 0.0f, 0.0f, 1.f };
		float fovCircleColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f }, pSilentFovCircleColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		float targetSnaplineColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	} aimbot;
	class c_visuals {
	public:
		// PLAYERS
		bool players, scientists;
		bool visible, wounded, sleeper;
		bool rainbowHands, fovArrows;

		bool name, box, skeleton, healthbar, heldItem, outside, teamID, hotbar, clothing, viewDirection;
		float playerDistance = 500.0f;
		std::string chamOption = "White";

		float playerColor[4] = { 0.f,1.f,1.f,1.f }, scientistColor[4] = { 1.f,0.f,1.f,1.f };
		float visibleColor[4] = { 1.f,0.f,0.f,1.f }, woundedColor[4] = { 0.f,1.f,1.f,1.f }, sleeperColor[4] = { 1.f,1.f,0.f,1.f };

		// RESOURCES
		std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> oreVisuals = {
			{ "stone ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "metal ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "sulfur ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "wood pile", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		};
		std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> foodVisuals = {
			{ "corn", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "mushroom", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "pumpkin", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "potato", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		};
		std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> collectableVisuals = {
			{ "hemp", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "wood", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "stone", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "metal", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "sulfur", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "diesel", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		};
		std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> animalVisuals = {
			{ "bear", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "stag", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "wolf", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "pig", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "horse", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "chicken", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "shark", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		};
		float oreDistance = 300.0f, foodDistance = 300.0f, collectableDistance = 300.0f, animalDistance = 300.0f;

		// LOOTABLES
		bool air, lCrate, nCrate, milCrate, eCrate, tCrate, awCrate, bwCrate, medCrate, fCrate, bCrate, nBarrel, oBarrel; // containers
		bool pCorpse, sCorpse, aCorpse, backpack, dItems, dWeapons; // other
		float crateDistance = 500.0f, otherDistance = 300.0f;

		float airColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, lCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, nCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, milCrateColor[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
		float eCrateColor[4] = { 1.0f, 0.0f, 1.0f, 1.0f }, tCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, awCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, bwCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
		float medCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, fCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, bCrateColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, nBarrelColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, oBarrelColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
		float pCorpseColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, sCorpseColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, aCorpseColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
		float backpackColor[4] = { 0.0f, 0.75f, 0.75f, 1.0f }, dItemsColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, dWeaponsColor[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

		// WORLD
		bool heli, brad, cargo, mini, sHeli, aHeli, RHIB, row, sub; // vehicles
		bool cave, raid, fuelAlert, samAlert, pos, house; // misc
		float vehicleDistance = 500.0f;

		float heliColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, bradColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, cargoColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, miniColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
		float aHeilColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, sHeliColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, rhibColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, rowColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, subColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
		float caveColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, raidColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, posColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, houseColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };

		// DEPLOYABLES
		bool turret, shotgun, sam, flame, snap, landmine; // traps
		bool tc, stashH, stashUH, bag;
		float tDist = 100.0f, shotgunDist = 25.0f, samDist = 150.0f, flameDist = 25.0f, snapDist = 25.0f, landmineDist = 25.0f, deployableDist = 300.0f;

		float turretColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }, shotgunColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }, samColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }, flameColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		float snapColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }, landmineColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
		float tcColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, stashHColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, stashUHColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }, bagColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f };

	} visuals;
	class c_misc {
	public:
		// AUTOMATIONS
		bool afOre, afTree, autoUpgrade;
		std::string upgradeMaterial = "Wood";

		// UTILITY
		bool dCamera, third, fly, iNoclip, onLadder, omni, antiFly, spinBot, spiderman, hitbox, infJump, jesus, autorun, increaseHeight;
		bool noFall, noSlow, noAimblock, noBlackout, noCollision;
		bool instantLoot, instantRevive, instantDrink, instantHeal, instantHealFriend;

		// COMBAT
		bool recoil, fullAuto, fastFire, noSway, noSpread, increaseVelocity, thickBullet, weaponSpammer;
		bool instantEoka, noMeleeSlow, noMeleePunch, meleeIncrease, fastBow, instantCharage, noMovementPenalty;
		float recoilX, recoilY, velocityValue, thickBulletValue;

		// VISUALS
		bool dayHack, skyChanger, ambient, brightStars, fovChanger, zoom, drawColliders; // visuals
		bool noFlash, noRain, noFog, noWind, noWaterBlur, noSmoke, noGrass, removeLayers; // removals

		float dayHackValue, skyChangerValue, fovChangerValue;

	} misc;
} cheats;
inline class fuck_this_shit {
public:
	// PLAYERS

	// RESOURCES
	std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> oreVisuals = {
			{ "stone ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "metal ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "sulfur ore", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
			{ "wood pile", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
	};
	std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> foodVisuals = {
		{ "mushroom", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "pumpkin", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "potato", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "corn", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
	};
	std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> collectableVisuals = {
		{ "wood pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "stone pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "metal pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "sulfur pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "hemp pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "diesel pickup", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
	};
	std::unordered_map<std::string, std::pair<bool, std::array<float, 4>>> animalVisuals = {
		{ "bear", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "stag", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "wolf", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "pig", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "horse", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "chicken", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
		{ "shark", { false, { 0.0f, 1.0f, 1.0f, 1.0f } } },
	};
	float oreDistance = 300.0f, foodDistance = 300.0f, collectableDistance = 300.0f, animalDistance = 300.0f;

	// LOOTABLES

	// DEPLOYABLES
} options;

struct t_weaponInfo {
	Vector4 recoilValue{};
	Vector4 spreadValue{};
	Vector2 swayValue{};
	bool automatic{};

	bool hasSetRecoil = false;
	bool hasSetSpread = false;
	bool hasSetSway = false;
};
inline class ezpz {
public:
	const int screen_w = GetSystemMetrics(SM_CXSCREEN);
	const int screen_h = GetSystemMetrics(SM_CYSCREEN);
	const int screen_center_x = screen_w / 2;
	const int screen_center_y = screen_h / 2;

	std::string weapon_name = "";
	std::unordered_map<std::string, t_weaponInfo> weapon_map{};
	t_weaponInfo weapon_info{};

	std::vector<c_prefab*> resourceMap{};
	std::vector<c_prefab*> collectibleMap{};
	std::vector<c_prefab*> animalMap{};

	std::unordered_map<std::string, std::vector<c_prefab*>> maps = {
		{ "ore", {} },
		{ "food", {} },
		{ "collectible", {} },
		{ "animal", {} },
	};
} globals;