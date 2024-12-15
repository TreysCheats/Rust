#include "ui.hpp"

void menu::init() {
    inited = true;

    drawing::screenCenter = ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f);

    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    style.WindowBorderSize = 0.f;
    style.ChildBorderSize = 0.f;
    style.PopupBorderSize = 1.f;
    style.FrameBorderSize = 0.f;

    style.WindowRounding = 6.0f;
    style.ChildRounding = 6.0f;
    style.FrameRounding = 2.0f;
    style.PopupRounding = 2.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding = 2.0f;
    style.TabRounding = 4.0f;

    colors[ImGuiCol_WindowBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.14f, 0.14f, 0.18f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.65f, 0.04f, 0.18f, 0.39f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.65f, 0.04f, 0.18f, 0.78f);
    colors[ImGuiCol_Button] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);

}
void menu::ui() {
    if (!active) exit(0);
    if (!inited) init();

    ImGui::Begin("ez.lua", &active, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNavInputs);
    {
        ImGui::SetWindowPos(ImVec2(500, 500), ImGuiCond_Once);
        ImGui::SetWindowSize(ImVec2(375, 400), ImGuiCond_Once);

        ImGui::Checkbox("stone ore", &options.oreVisuals["stone ore"].first);
        ImGui::Checkbox("metal ore", &options.oreVisuals["metal ore"].first);
        ImGui::Checkbox("sulfur ore", &options.oreVisuals["sulfur ore"].first);
        ImGui::Checkbox("wood pile", &options.oreVisuals["wood pile"].first);

        ImGui::Separator();

        ImGui::Checkbox("mushroom", &options.foodVisuals["mushroom"].first);
        ImGui::Checkbox("pumpkin", &options.foodVisuals["pumpkin"].first);
        ImGui::Checkbox("potato", &options.foodVisuals["potato"].first);
        ImGui::Checkbox("corn", &options.foodVisuals["corn"].first);

        ImGui::Separator();

        ImGui::Checkbox("wood", &options.collectableVisuals["wood"].first);
        ImGui::Checkbox("stone", &options.collectableVisuals["stone"].first);
        ImGui::Checkbox("metal", &options.collectableVisuals["metal"].first);
        ImGui::Checkbox("sulfur", &options.collectableVisuals["sulfur"].first);
        ImGui::Checkbox("hemp", &options.collectableVisuals["hemp"].first);
        ImGui::Checkbox("diesel", &options.collectableVisuals["diesel"].first);

        ImGui::Separator();

        ImGui::Checkbox("bear", &options.animalVisuals["bear"].first);
        ImGui::Checkbox("stag", &options.animalVisuals["stag"].first);
        ImGui::Checkbox("wolf", &options.animalVisuals["wolf"].first);
        ImGui::Checkbox("pig", &options.animalVisuals["pig"].first);
        ImGui::Checkbox("horse", &options.animalVisuals["horse"].first);
        ImGui::Checkbox("chicken", &options.animalVisuals["chicken"].first);
        ImGui::Checkbox("shark", &options.animalVisuals["shark"].first);
    }
    ImGui::End();

    /*
    ImGui::Begin("ez.lua", &active, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNavInputs);
    {
        ImGui::SetWindowPos(ImVec2(500, 500), ImGuiCond_Once);
        ImGui::SetWindowSize(ImVec2(375, 400), ImGuiCond_Once);

        if (ImGui::Button("Aimbot", ImVec2(84, 19))) { menu::tab = 0; }                     ImGui::SameLine();
        if (ImGui::Button("Visuals", ImVec2(84, 19))) { menu::tab = 1; }                    ImGui::SameLine();
        if (ImGui::Button("Misc", ImVec2(83, 19))) { menu::tab = 2; }                       ImGui::SameLine();
        if (ImGui::Button("Config", ImVec2(83, 19))) { menu::tab = 3; }
        ImGui::Separator();

        switch (menu::tab) {
        case 0: // aimbot
            if (ImGui::Button("Aimbot##a0", ImVec2(114, 19))) { menu::aTab = 0; }           ImGui::SameLine();
            if (ImGui::Button("Exploits##a0", ImVec2(114, 19))) { menu::aTab = 1; }         ImGui::SameLine();
            if (ImGui::Button("Visuals##a0", ImVec2(114, 19))) { menu::aTab = 2; }
            ImGui::Separator();

            if (menu::aTab == 0) {
                ImGui::Checkbox("Enabled", &cheats.aimbot.enabled);

                ImGui::Checkbox("TargetWounded", &cheats.aimbot.targetWounded); ImGui::SameLine();
                ImGui::Checkbox("TargetFriendly", &cheats.aimbot.targetFriendly); ImGui::SameLine();
                ImGui::Checkbox("TargetNPC", &cheats.aimbot.targetNPC);

                ImGui::Checkbox("pSilent", &cheats.aimbot.pSilent); ImGui::SameLine();
                ImGui::Checkbox("pSilentHeli", &cheats.aimbot.pSilentHeli);

                ImGui::Checkbox("Smoothing", &cheats.aimbot.smoothing);
                ImGui::Checkbox("HitChance", &cheats.aimbot.hitChance);
                if (cheats.aimbot.smoothing) ImGui::SliderFloat("Smoothing Value", &cheats.aimbot.smoothingValue, 0, 100, "%.0f");
                if (cheats.aimbot.hitChance) ImGui::SliderFloat("Hit Chance", &cheats.aimbot.hitChanceValue, 0, 100, "%.0f");

                ImGui::SliderFloat("Aimbot Fov", &cheats.aimbot.aimFov, 0, 250, "%.0f");
                ImGui::SliderFloat("pSilent Fov", &cheats.aimbot.pAimFov, 0, 500, "%.0f");
            }
            if (menu::aTab == 1) {
                ImGui::Checkbox("MagicBullet (4m)", &cheats.aimbot.magicBullet);
                ImGui::Checkbox("Boneoverride", &cheats.aimbot.boneOverride);
            }
            if (menu::aTab == 2) {
                ImGui::Checkbox("SimulateProjectile", &cheats.aimbot.simProjectile);    ImGui::SameLine();  ImGui::ColorEdit4("##simulateProjectile", cheats.aimbot.simProjectileColor, cef);
                ImGui::Checkbox("AimMarker", &cheats.aimbot.aimMarker);                 ImGui::SameLine();  ImGui::ColorEdit4("##aimMarker", cheats.aimbot.aimMarkerColor, cef);
                ImGui::Checkbox("Crosshair", &cheats.aimbot.crosshair);                 ImGui::SameLine();  ImGui::ColorEdit4("##crosshair", cheats.aimbot.crosshairColor, cef);
                ImGui::Checkbox("Fov Circle", &cheats.aimbot.fovCircle);                ImGui::SameLine();  ImGui::ColorEdit4("##fovCircle", cheats.aimbot.fovCircleColor, cef);
                ImGui::Checkbox("pSilent Fov Circle", &cheats.aimbot.pSilentFovCircle); ImGui::SameLine();  ImGui::ColorEdit4("##pSilentFovCircle", cheats.aimbot.pSilentFovCircleColor, cef);
                ImGui::Checkbox("Target Snapline", &cheats.aimbot.targetSnapline);      ImGui::SameLine();  ImGui::ColorEdit4("##targetSnapline", cheats.aimbot.targetSnaplineColor, cef);
                ImGui::Checkbox("Hitmarker", &cheats.aimbot.hitmarker);
            }

            break;
        case 1: // visuals
            if (ImGui::Button("Players")) { menu::vTab = 0; }                               ImGui::SameLine();
            if (ImGui::Button("Resources")) { menu::vTab = 1; }                             ImGui::SameLine();
            if (ImGui::Button("Lootables")) { menu::vTab = 2; }                             ImGui::SameLine();
            if (ImGui::Button("World")) { menu::vTab = 3; }                                 ImGui::SameLine();
            if (ImGui::Button("Deployables", ImVec2(84, 19))) { menu::vTab = 4; }
            ImGui::Separator();

            if (menu::vTab == 0) {
                ImGui::Text("Player Visuals");

                ImGui::Checkbox("Players##1", &cheats.visuals.players);            ImGui::SameLine();      ImGui::ColorEdit4("##players", cheats.visuals.playerColor, cef);
                ImGui::Checkbox("Scientists", &cheats.visuals.scientists);      ImGui::SameLine();      ImGui::ColorEdit4("##scientists", cheats.visuals.scientistColor, cef);
                ImGui::Checkbox("Visible", &cheats.visuals.visible);            ImGui::SameLine();      ImGui::ColorEdit4("##visible", cheats.visuals.visibleColor, cef);
                ImGui::Checkbox("Wounded", &cheats.visuals.wounded);            ImGui::SameLine();      ImGui::ColorEdit4("##wounded", cheats.visuals.woundedColor, cef);
                ImGui::Checkbox("Sleeper", &cheats.visuals.sleeper);            ImGui::SameLine();      ImGui::ColorEdit4("##sleeper", cheats.visuals.sleeperColor, cef);
                ImGui::Checkbox("RainbowHands", &cheats.visuals.rainbowHands);
                ImGui::Checkbox("Fov Arrows", &cheats.visuals.fovArrows);

                ImGui::Separator();
                ImGui::Text("Customization");

                ImGui::Checkbox("Username", &cheats.visuals.name);
                ImGui::Checkbox("Box", &cheats.visuals.box);
                ImGui::Checkbox("Skeleton", &cheats.visuals.skeleton);
                ImGui::Checkbox("Health Bar", &cheats.visuals.healthbar);
                ImGui::Checkbox("HeldItem", &cheats.visuals.heldItem);
                ImGui::Checkbox("Outside", &cheats.visuals.outside);
                ImGui::Checkbox("TeamID", &cheats.visuals.teamID);
                ImGui::Checkbox("Hotbar", &cheats.visuals.hotbar);
                ImGui::Checkbox("Clothing", &cheats.visuals.clothing);
                ImGui::Checkbox("ViewDirection", &cheats.visuals.viewDirection);
                ImGui::SliderFloat("PlayerDistance", &cheats.visuals.playerDistance, 500, 5000, "%.0f");
            }
            if (menu::vTab == 1) {
                ImGui::Text("Ore");

                ImGui::Checkbox("Stone", &cheats.visuals.oreVisuals["stone ore"].first);         ImGui::SameLine();      ImGui::ColorEdit4("##stoneOre", cheats.visuals.oreVisuals["stone ore"].second.data(), cef);
                ImGui::Checkbox("Metal", &cheats.visuals.oreVisuals["metal ore"].first);         ImGui::SameLine();      ImGui::ColorEdit4("##metalOre", cheats.visuals.oreVisuals["metal ore"].second.data(), cef);
                ImGui::Checkbox("Sulfur", &cheats.visuals.oreVisuals["sulfur ore"].first);       ImGui::SameLine();      ImGui::ColorEdit4("##sulfurOre", cheats.visuals.oreVisuals["sulfur ore"].second.data(), cef);
                ImGui::Checkbox("Wood Pile", &cheats.visuals.oreVisuals["wood pile"].first);     ImGui::SameLine();      ImGui::ColorEdit4("##woodPile", cheats.visuals.oreVisuals["wood pile"].second.data(), cef);
                ImGui::SliderFloat("Ore Dist", &cheats.visuals.oreDistance, 0, 500, "%.0f");

                ImGui::Separator();
                ImGui::Text("Food");

                ImGui::Checkbox("Corn", &cheats.visuals.foodVisuals["corn"].first);              ImGui::SameLine();      ImGui::ColorEdit4("##corn", cheats.visuals.foodVisuals["corn"].second.data(), cef);
                ImGui::Checkbox("Mushroom", &cheats.visuals.foodVisuals["mushroom"].first);      ImGui::SameLine();      ImGui::ColorEdit4("##mushroom", cheats.visuals.foodVisuals["mushroom"].second.data(), cef);
                ImGui::Checkbox("Pumpkin", &cheats.visuals.foodVisuals["pumpkin"].first);        ImGui::SameLine();      ImGui::ColorEdit4("##pumpkin", cheats.visuals.foodVisuals["pumpkin"].second.data(), cef);
                ImGui::Checkbox("Potato", &cheats.visuals.foodVisuals["potato"].first);          ImGui::SameLine();      ImGui::ColorEdit4("##potato", cheats.visuals.foodVisuals["potato"].second.data(), cef);
                ImGui::SliderFloat("Food Dist", &cheats.visuals.foodDistance, 0, 500, "%.0f");

                ImGui::Separator();
                ImGui::Text("Collectables");

                ImGui::Checkbox("Hemp", &cheats.visuals.collectableVisuals["hemp"].first);          ImGui::SameLine();      ImGui::ColorEdit4("##hemp", cheats.visuals.collectableVisuals["hemp"].second.data(), cef);
                ImGui::Checkbox("Stone##1", &cheats.visuals.collectableVisuals["stone"].first);     ImGui::SameLine();      ImGui::ColorEdit4("##stone", cheats.visuals.collectableVisuals["stone"].second.data(), cef);
                ImGui::Checkbox("Metal##1", &cheats.visuals.collectableVisuals["metal"].first);     ImGui::SameLine();      ImGui::ColorEdit4("##metal", cheats.visuals.collectableVisuals["metal"].second.data(), cef);
                ImGui::Checkbox("Sulfur##1", &cheats.visuals.collectableVisuals["sulfur"].first);   ImGui::SameLine();      ImGui::ColorEdit4("##sulfur", cheats.visuals.collectableVisuals["sulfur"].second.data(), cef);
                ImGui::Checkbox("Wood", &cheats.visuals.collectableVisuals["wood"].first);          ImGui::SameLine();      ImGui::ColorEdit4("##wood", cheats.visuals.collectableVisuals["wood"].second.data(), cef);
                ImGui::Checkbox("Diesel", &cheats.visuals.collectableVisuals["diesel"].first);      ImGui::SameLine();      ImGui::ColorEdit4("##diesel", cheats.visuals.collectableVisuals["diesel"].second.data(), cef);
                ImGui::SliderFloat("Collectable Dist", &cheats.visuals.collectableDistance, 0, 500, "%.0f");

                ImGui::Separator();
                ImGui::Text("Animals");

                ImGui::Checkbox("Bear", &cheats.visuals.animalVisuals["bear"].first);            ImGui::SameLine();      ImGui::ColorEdit4("##bear", cheats.visuals.animalVisuals["bear"].second.data(), cef);
                ImGui::Checkbox("Stag", &cheats.visuals.animalVisuals["stag"].first);            ImGui::SameLine();      ImGui::ColorEdit4("##stag", cheats.visuals.animalVisuals["stag"].second.data(), cef);
                ImGui::Checkbox("Wolf", &cheats.visuals.animalVisuals["wolf"].first);            ImGui::SameLine();      ImGui::ColorEdit4("##wolf", cheats.visuals.animalVisuals["wolf"].second.data(), cef);
                ImGui::Checkbox("Pig", &cheats.visuals.animalVisuals["pig"].first);              ImGui::SameLine();      ImGui::ColorEdit4("##pig", cheats.visuals.animalVisuals["pig"].second.data(), cef);
                ImGui::Checkbox("Horse", &cheats.visuals.animalVisuals["horse"].first);          ImGui::SameLine();      ImGui::ColorEdit4("##horse", cheats.visuals.animalVisuals["horse"].second.data(), cef);
                ImGui::Checkbox("Chicken", &cheats.visuals.animalVisuals["chicken"].first);      ImGui::SameLine();      ImGui::ColorEdit4("##horse", cheats.visuals.animalVisuals["chicken"].second.data(), cef);
                ImGui::Checkbox("Shark", &cheats.visuals.animalVisuals["shark"].first);          ImGui::SameLine();      ImGui::ColorEdit4("##shark", cheats.visuals.animalVisuals["shark"].second.data(), cef);
                ImGui::SliderFloat("Animal Dist", &cheats.visuals.animalDistance, 0, 500, "%.0f");
            }
            if (menu::vTab == 2) {
                ImGui::Text("Containers");

                ImGui::Checkbox("Airdrop", &cheats.visuals.air);                    ImGui::SameLine();      ImGui::ColorEdit4("##airdrop", cheats.visuals.airColor, cef);
                ImGui::Checkbox("Locked Crate", &cheats.visuals.lCrate);            ImGui::SameLine();      ImGui::ColorEdit4("##lCrate", cheats.visuals.lCrateColor, cef);
                ImGui::Checkbox("Normal Crate", &cheats.visuals.nCrate);            ImGui::SameLine();      ImGui::ColorEdit4("##nCrate", cheats.visuals.nCrateColor, cef);
                ImGui::Checkbox("Military Crate", &cheats.visuals.milCrate);        ImGui::SameLine();      ImGui::ColorEdit4("##milCrate", cheats.visuals.milCrateColor, cef);
                ImGui::Checkbox("Elite Crate", &cheats.visuals.eCrate);             ImGui::SameLine();      ImGui::ColorEdit4("##eCrate", cheats.visuals.eCrateColor, cef);
                ImGui::Checkbox("Tool Crate", &cheats.visuals.tCrate);              ImGui::SameLine();      ImGui::ColorEdit4("##tCrate", cheats.visuals.tCrateColor, cef);
                ImGui::Checkbox("Adv. Water Crate", &cheats.visuals.awCrate);       ImGui::SameLine();      ImGui::ColorEdit4("##awCrate", cheats.visuals.awCrateColor, cef);
                ImGui::Checkbox("Basic Water Crate", &cheats.visuals.bwCrate);      ImGui::SameLine();      ImGui::ColorEdit4("##bwCrate", cheats.visuals.bwCrateColor, cef);
                ImGui::Checkbox("Medical Crate", &cheats.visuals.medCrate);         ImGui::SameLine();      ImGui::ColorEdit4("##medCrate", cheats.visuals.medCrateColor, cef);
                ImGui::Checkbox("Food Crate", &cheats.visuals.fCrate);              ImGui::SameLine();      ImGui::ColorEdit4("##fCrate", cheats.visuals.fCrateColor, cef);
                ImGui::Checkbox("Basic Crate", &cheats.visuals.bCrate);             ImGui::SameLine();      ImGui::ColorEdit4("##bCrate", cheats.visuals.bCrateColor, cef);
                ImGui::Checkbox("Normal Barrel", &cheats.visuals.nBarrel);          ImGui::SameLine();      ImGui::ColorEdit4("##nCrate", cheats.visuals.nBarrelColor, cef);
                ImGui::Checkbox("Oil Barrel", &cheats.visuals.oBarrel);             ImGui::SameLine();      ImGui::ColorEdit4("##oCrate", cheats.visuals.oBarrelColor, cef);
                ImGui::SliderFloat("Container Distance", &cheats.visuals.crateDistance, 0, 500, "%.0f");

                ImGui::Separator();
                ImGui::Text("Other");

                ImGui::Checkbox("Player Corpse", &cheats.visuals.pCorpse);          ImGui::SameLine();      ImGui::ColorEdit4("##pCorpse", cheats.visuals.pCorpseColor, cef);
                ImGui::Checkbox("Scientist Corpse", &cheats.visuals.sCorpse);       ImGui::SameLine();      ImGui::ColorEdit4("##sCorpse", cheats.visuals.sCorpseColor, cef);
                ImGui::Checkbox("Animal Corpse", &cheats.visuals.aCorpse);          ImGui::SameLine();      ImGui::ColorEdit4("##aCorpse", cheats.visuals.aCorpseColor, cef);
                ImGui::Checkbox("Backpack", &cheats.visuals.backpack);              ImGui::SameLine();      ImGui::ColorEdit4("##backpack", cheats.visuals.backpackColor, cef);
                ImGui::Checkbox("Dropped Items", &cheats.visuals.dItems);           ImGui::SameLine();      ImGui::ColorEdit4("##dItems", cheats.visuals.dItemsColor, cef);
                ImGui::Checkbox("Dropped Weapons", &cheats.visuals.dWeapons);       ImGui::SameLine();      ImGui::ColorEdit4("##dWeapons", cheats.visuals.dWeaponsColor, cef);
                ImGui::SliderFloat("Other Distance", &cheats.visuals.otherDistance, 0, 500, "%.0f");
            }
            if (menu::vTab == 3) {
                ImGui::Text("Vehicles");

                ImGui::Checkbox("Patrol Heli", &cheats.visuals.heli);                       ImGui::SameLine();      ImGui::ColorEdit4("##heli", cheats.visuals.heliColor, cef);
                ImGui::Checkbox("Bradley", &cheats.visuals.brad);                           ImGui::SameLine();      ImGui::ColorEdit4("##brad", cheats.visuals.bradColor, cef);
                ImGui::Checkbox("Cargoship", &cheats.visuals.cargo);                        ImGui::SameLine();      ImGui::ColorEdit4("##cargo", cheats.visuals.cargoColor, cef);
                ImGui::Checkbox("Minicopter", &cheats.visuals.mini);                        ImGui::SameLine();      ImGui::ColorEdit4("##mini", cheats.visuals.miniColor, cef);
                ImGui::Checkbox("Scrap Heli", &cheats.visuals.sHeli);                       ImGui::SameLine();      ImGui::ColorEdit4("##sHeli", cheats.visuals.sHeliColor, cef);
                ImGui::Checkbox("Attack Heli", &cheats.visuals.aHeli);                      ImGui::SameLine();      ImGui::ColorEdit4("##aHeli", cheats.visuals.aHeilColor, cef);
                ImGui::Checkbox("RHIB", &cheats.visuals.RHIB);                              ImGui::SameLine();      ImGui::ColorEdit4("##rhib", cheats.visuals.rhibColor, cef);
                ImGui::Checkbox("Rowboat", &cheats.visuals.row);                            ImGui::SameLine();      ImGui::ColorEdit4("##row", cheats.visuals.rowColor, cef);
                ImGui::Checkbox("Submarine", &cheats.visuals.sub);                          ImGui::SameLine();      ImGui::ColorEdit4("##sub", cheats.visuals.subColor, cef);
                ImGui::SliderFloat("Vehicle Dist", &cheats.visuals.vehicleDistance, 0, 1000, "%.0f");

                ImGui::Separator();
                ImGui::Text("Misc Visuals");

                ImGui::Checkbox("Cave", &cheats.visuals.cave);                              ImGui::SameLine();      ImGui::ColorEdit4("##cave", cheats.visuals.caveColor, cef);
                ImGui::Checkbox("Raid", &cheats.visuals.raid);                              ImGui::SameLine();      ImGui::ColorEdit4("##raid", cheats.visuals.raidColor, cef);
                ImGui::Checkbox("Save Position", &cheats.visuals.pos);                      ImGui::SameLine();      ImGui::ColorEdit4("##pos", cheats.visuals.posColor, cef);
                ImGui::Checkbox("Save House", &cheats.visuals.house);                       ImGui::SameLine();      ImGui::ColorEdit4("##house", cheats.visuals.houseColor, cef);
            }
            if (menu::vTab == 4) {
                ImGui::Text("Traps");

                ImGui::Checkbox("Auto Turret", &cheats.visuals.turret);                     ImGui::SameLine();      ImGui::ColorEdit4("##turret", cheats.visuals.turretColor, cef);
                if (cheats.visuals.turret) ImGui::SliderFloat("##turretValue", &cheats.visuals.tDist, 0, 500, "%.0f");

                ImGui::Checkbox("Shotgun Trap", &cheats.visuals.shotgun);                   ImGui::SameLine();      ImGui::ColorEdit4("##shotgun", cheats.visuals.shotgunColor, cef);
                if (cheats.visuals.shotgun) ImGui::SliderFloat("##shotgunValue", &cheats.visuals.shotgunDist, 0, 500, "%.0f");

                ImGui::Checkbox("Sam Site", &cheats.visuals.sam);                           ImGui::SameLine();      ImGui::ColorEdit4("##sam", cheats.visuals.samColor, cef);
                if (cheats.visuals.sam) ImGui::SliderFloat("##samValue", &cheats.visuals.samDist, 0, 500, "%.0f");

                ImGui::Checkbox("Flame Trap", &cheats.visuals.flame);                       ImGui::SameLine();      ImGui::ColorEdit4("##flame", cheats.visuals.flameColor, cef);
                if (cheats.visuals.flame) ImGui::SliderFloat("##flameValue", &cheats.visuals.flameDist, 0, 500, "%.0f");

                ImGui::Checkbox("Snap Trap", &cheats.visuals.snap);                         ImGui::SameLine();      ImGui::ColorEdit4("##snap", cheats.visuals.snapColor, cef);
                if (cheats.visuals.snap) ImGui::SliderFloat("##snapValue", &cheats.visuals.snapDist, 0, 500, "%.0f");

                ImGui::Checkbox("Landmine", &cheats.visuals.landmine);                      ImGui::SameLine();      ImGui::ColorEdit4("##landmine", cheats.visuals.landmineColor, cef);
                if (cheats.visuals.landmine) ImGui::SliderFloat("##landmineVale", &cheats.visuals.landmineDist, 0, 500, "%.0f");

                ImGui::Separator();
                ImGui::Text("Deployables");

                ImGui::Checkbox("Tool Cupboard", &cheats.visuals.tc);                      ImGui::SameLine();      ImGui::ColorEdit4("##tc", cheats.visuals.tcColor, cef);
                ImGui::Checkbox("Sleeping Bag", &cheats.visuals.bag);                      ImGui::SameLine();      ImGui::ColorEdit4("##bag", cheats.visuals.bagColor, cef);
                ImGui::Checkbox("Stash Hidden", &cheats.visuals.stashH);                   ImGui::SameLine();      ImGui::ColorEdit4("##stashH", cheats.visuals.stashHColor, cef);
                ImGui::Checkbox("Stash Unhidden", &cheats.visuals.stashUH);                ImGui::SameLine();      ImGui::ColorEdit4("##stashUH", cheats.visuals.stashUHColor, cef);
            }

            break;
        case 2: // misc
            if (ImGui::Button("Automations", ImVec2(85, 19))) { menu::mTab = 0; }          ImGui::SameLine();
            if (ImGui::Button("Utility", ImVec2(83, 19))) { menu::mTab = 1; }          ImGui::SameLine();
            if (ImGui::Button("Combat", ImVec2(83, 19))) { menu::mTab = 2; }          ImGui::SameLine();
            if (ImGui::Button("Visuals##2", ImVec2(83, 19))) { menu::mTab = 3; }
            ImGui::Separator();

            if (menu::mTab == 0) {
                ImGui::Checkbox("AutoFarmOre", &cheats.misc.afOre);
                ImGui::Checkbox("AutoFarmTree", &cheats.misc.afTree);
                ImGui::Checkbox("AutoUpgrade", &cheats.misc.autoUpgrade);
            }
            if (menu::mTab == 1) {
                ImGui::Checkbox("Debug Camera", &cheats.misc.dCamera);
                ImGui::Checkbox("3rd Person", &cheats.misc.third);
                ImGui::Checkbox("Flyhack", &cheats.misc.fly);
                ImGui::Checkbox("Interactive Noclip", &cheats.misc.iNoclip);
                ImGui::Checkbox("OnLadder", &cheats.misc.onLadder);
                ImGui::Checkbox("OmniSprint", &cheats.misc.omni);
                ImGui::Checkbox("AntiFlyViolations", &cheats.misc.antiFly);
                ImGui::Checkbox("Spinbot", &cheats.misc.spinBot);
                ImGui::Checkbox("Spiderman", &cheats.misc.spiderman);
                ImGui::Checkbox("Smaller Hitbox", &cheats.misc.hitbox);
                ImGui::Checkbox("Infinite Jump", &cheats.misc.infJump);
                ImGui::Checkbox("Walk On Water", &cheats.misc.jesus);
                ImGui::Checkbox("Autorun", &cheats.misc.autorun);
                ImGui::Checkbox("Increase Height", &cheats.misc.increaseHeight);
                ImGui::Checkbox("No Fall", &cheats.misc.noFall);
                ImGui::Checkbox("No Slowdown", &cheats.misc.noSlow);
                ImGui::Checkbox("No Aimblock", &cheats.misc.noAimblock);
                ImGui::Checkbox("No Blackout", &cheats.misc.noBlackout);
                ImGui::Checkbox("No Collision", &cheats.misc.noCollision);
                ImGui::Checkbox("Instant Loot", &cheats.misc.instantLoot);
                ImGui::Checkbox("Instant Revive", &cheats.misc.instantRevive);
                ImGui::Checkbox("Instant Drink", &cheats.misc.instantDrink);
                ImGui::Checkbox("Instant Heal", &cheats.misc.instantHeal);
                ImGui::Checkbox("Instant Heal Friend", &cheats.misc.instantHealFriend);
            }
            if (menu::mTab == 2) {
                ImGui::Checkbox("Recoil", &cheats.misc.recoil);
                if (cheats.misc.recoil) {
                    ImGui::SliderFloat("Recoil X", &cheats.misc.recoilX, 0, 100, "%.0f");
                    ImGui::SliderFloat("Recoil Y", &cheats.misc.recoilY, 0, 100, "%.0f");
                }
                ImGui::Checkbox("FullAuto", &cheats.misc.fullAuto);
                ImGui::Checkbox("FastFire", &cheats.misc.fastFire);
                ImGui::Checkbox("NoSway", &cheats.misc.noSway);
                ImGui::Checkbox("NoSpread", &cheats.misc.noSpread);
                ImGui::Checkbox("Increased Velocity", &cheats.misc.increaseVelocity);
                if (cheats.misc.increaseVelocity) ImGui::SliderFloat("##velocityValue", &cheats.misc.velocityValue, 0, 5, "%.0f");
                ImGui::Checkbox("ThickBullet", &cheats.misc.thickBullet);
                if (cheats.misc.thickBullet) ImGui::SliderFloat("##thickBullet", &cheats.misc.thickBulletValue, 0, 1, "%.2f");
                ImGui::Checkbox("Weapon Spammer", &cheats.misc.weaponSpammer);
                ImGui::Checkbox("Instant Eoka", &cheats.misc.instantEoka);
                ImGui::Checkbox("No Melee Slowdown", &cheats.misc.noMeleeSlow);
                ImGui::Checkbox("No Melee Punch", &cheats.misc.noMeleePunch);
                ImGui::Checkbox("2x Melee Distance", &cheats.misc.meleeIncrease);
                ImGui::Checkbox("Fast Bow", &cheats.misc.fastBow);
                ImGui::Checkbox("Instant Charge", &cheats.misc.instantCharage);
                ImGui::Checkbox("No Movement Penalty", &cheats.misc.noMovementPenalty);
            }
            if (menu::mTab == 3) {
                ImGui::Text("Visuals");
                ImGui::Checkbox("Day Hack", &cheats.misc.dayHack);
                if (cheats.misc.dayHack) ImGui::SliderFloat("##dayHack", &cheats.misc.dayHackValue, 0, 100, "%.0f");
                ImGui::Checkbox("Sky Changer", &cheats.misc.skyChanger);
                if (cheats.misc.skyChanger) ImGui::SliderFloat("##skyChanger", &cheats.misc.skyChangerValue, 0, 100, "%.0f");
                ImGui::Checkbox("Ambient", &cheats.misc.ambient);
                ImGui::Checkbox("Bright Stars", &cheats.misc.brightStars);
                ImGui::Checkbox("FOV Changer", &cheats.misc.fovChanger);
                if (cheats.misc.fovChanger) ImGui::SliderFloat("##fovChanger", &cheats.misc.fovChangerValue, 0, 180, "%.0f");
                ImGui::Checkbox("Draw Colliders", &cheats.misc.drawColliders);

                ImGui::Separator();
                ImGui::Text("Removals");

                ImGui::Checkbox("No Flash", &cheats.misc.noFlash);
                ImGui::Checkbox("No Rain", &cheats.misc.noRain);
                ImGui::Checkbox("No Fog", &cheats.misc.noFog);
                ImGui::Checkbox("No Wind", &cheats.misc.noWind);
                ImGui::Checkbox("No Water Blur", &cheats.misc.noWaterBlur);
                ImGui::Checkbox("No Smoke", &cheats.misc.noSmoke);
                ImGui::Checkbox("No Grass", &cheats.misc.noGrass);
                ImGui::Checkbox("Remove Layers", &cheats.misc.removeLayers);
            }

            break;
        case 3:
            break;
        }
    }
    ImGui::End();
    */
}
void menu::render() {
    if (cheats.aimbot.crosshair) drawing::drawCrosshair(ImColor(cheats.aimbot.crosshairColor));

    camera.setPosition(memory.read<Vector3>(camera.getObject() + 0x454));
    camera.setVmatrix(memory.read<vmatrix_t>(camera.getObject() + 0x100)); // 0x100 seems to work but it points to things behind me
    
    // ore esp
    for (int i = 0; i < globals.maps["ore"].size(); i++) {
        c_prefab* prefab = globals.maps["ore"][i];
    
        std::string prefabName = prefab->prefabName(true);
        Vector3 pos = prefab->position();
        if (pos == Vector3().zero()) continue;
    
        if (options.oreVisuals.count(prefabName) && !options.oreVisuals[prefabName].first) continue;
        
        Vector2 screen;
        if (w2s(pos, screen)) {
            drawing::drawText(screen.toImVec2(), options.oreVisuals[prefabName].second.data(), prefabName.c_str());
        }
    }

    /*
    // food esp
    for (int i = 0; i < globals.maps["food"].size(); i++) {
        c_prefab* prefab = globals.maps["food"][i];

        std::string prefabName = prefab->prefabName(true);
        std::cout << "prefabName: " << prefabName << std::endl;
        Vector3 pos = prefab->position();
        if (pos == Vector3().zero()) continue;

        if (options.foodVisuals.count(prefabName) && !options.foodVisuals[prefabName].first) continue;

        Vector2 screen;
        if (w2s(pos, screen)) {
            drawing::drawText(screen.toImVec2(), options.foodVisuals[prefabName].second.data(), prefabName.c_str());
        }
    }
    */

    /*
    // collectible esp
    for (int i = 0; i < globals.maps["collectible"].size(); i++) {
        c_prefab* prefab = globals.maps["collectible"][i];

        std::string prefabName = prefab->prefabName(true);
        //std::cout << "prefabName: " << prefabName << std::endl;
        Vector3 pos = prefab->position();
        if (pos == Vector3().zero()) continue;

        if (options.collectableVisuals.count(prefabName) && !options.collectableVisuals[prefabName].first) continue;

        Vector2 screen;
        if (w2s(pos, screen)) {
            drawing::drawText(screen.toImVec2(), options.collectableVisuals[prefabName].second.data(), prefabName.c_str());
        }
    }

    // animal esp
    for (int i = 0; i < globals.maps["animal"].size(); i++) {
        c_prefab* prefab = globals.maps["animal"][i];

        std::string prefabName = prefab->prefabName();
        Vector3 pos = prefab->position();
        if (pos == Vector3().zero()) continue;

        if (options.animalVisuals.count(prefabName) && !options.animalVisuals[prefabName].first) continue;

        Vector2 screen;
        if (w2s(pos, screen)) {
            drawing::drawText(screen.toImVec2(), options.animalVisuals[prefabName].second.data(), prefabName.c_str());
        }
    }
    */
}