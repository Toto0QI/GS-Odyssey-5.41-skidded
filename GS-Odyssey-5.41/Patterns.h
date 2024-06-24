#pragma once

namespace Patterns
{
	// Base
	constexpr const char* FMemoryFree = "48 85 C9 74 2E 53 48 83 EC 20 48 8B D9";
	constexpr const char* FMemoryMalloc = "48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 8B DA 48 8B 0D ? ? ? ? 48 85 C9 75 0C";
	constexpr const char* FMemoryRealloc = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F1 41 8B D8 48 8B 0D ? ? ? ? 48 8B FA";

	// BuildingActor
	constexpr const char* PickLootTierGroupAthena = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 65 48 8B 04 25 ? ? ? ? 48 8B F2 8B 0D ? ? ? ? 49 8B D8";

	// FortPickup
	constexpr const char* PickupDelay = "40 53 56 57 48 83 EC 30 4C 89 6C 24 ? 48 8B F1";
	constexpr const char* PickupCombine = "4C 8B DC 53 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 83 B9 ? ? ? ? ? 48 8B D9";

	// GameMode
	constexpr const char* AddFromAlivePlayers = "48 85 D2 0F 84 ? ? ? ? 56 57 48 83 EC 78";
	constexpr const char* RemoveFromAlivePlayers = "4C 89 4C 24 ? 4C 89 44 24 ? 55 41 54 41 55 41 56 41 57 48 8D 6C 24 ?";

	// Pawn
	constexpr const char* HandlePickup = "40 55 53 56 41 54 48 8D 6C 24 B8";

	// PlayerController
	constexpr const char* RemoveInventoryItem = "48 83 EC 48 80 B9 ? ? ? ? ? 74 22 0F 10 02 0F B6 44 24 ?";
	constexpr const char* ModifyLoadedAmmo = "40 53 48 83 EC 30 80 B9 ? ? ? ? ? 41 8B D8 75 3F"; // (1.7.2 - 12.10)
	constexpr const char* PayRepairCosts = "40 57 41 54 41 55 41 57 48 83 EC 78";
	constexpr const char* PayBuildingCosts = "48 89 5C 24 18 56 57 41 56 48 83 EC 50 48 83 3A 00";
	constexpr const char* CantBuild = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 41 56 48 83 EC 50 49 8B E9 4D 8B F0 48 8B DA 48 8B F1";
	constexpr const char* ReplaceBuildingActor = "48 8B C4 44 89 48 20 55 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 48 89 70 E8 33 FF 40 38 3D ? ? ? ? 48 8B F1";
	constexpr const char* ToDeathCause = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 0F B6 FA 48 8B D9 E8 ? ? ? ? 33 F6";

	// Beacon
	constexpr const char* InitHost = "48 8B C4 48 81 EC B8 00 00 00 48 89 58 18";
	constexpr const char* InitListen = "48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 50 48 8B BC 24 80 00 00 00";
	constexpr const char* Listen = "E8 ? ? ? ? 84 C0 75 73 80 3D ? ? ? ? ? 72 6A 45 33 C0 48 8D 95 ? ? ? ? 48 8B CF E8 ? ? ? ? 83 78 08 00 74 05 48 8B 08 EB 07";
	constexpr const char* SetWorld = "48 89 5C 24 ? 57 48 83 EC 20 48 8B FA 48 8B D9 48 8B 91 ? ? ? ? 48 85 D2 74 28";
	constexpr const char* TickFlush = "4C 8B DC 55 49 8D AB 98 FE FF FF 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 00 01 00 00 49 89 5B 18 48 8D 05 ? ? ? ?";
	constexpr const char* ServerReplicateActors = "4C 8B DC 55 49 8D AB ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B 41 30 45 33 C0";

	// Abilities
	constexpr const char* InternalTryActivateAbility = "4C 89 4C 24 20 4C 89 44 24 18 89 54 24 10 55 53 56";
	constexpr const char* GiveAbility = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 83 B9 ? ? ? ? ? 49 8B E8 4C 8B F2 48 8B F9 7E 56";
	constexpr const char* CreateDefaultObject = "4C 8B DC 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 83 B9 ? ? ? ? ? 48 8B F9";
	constexpr const char* GiveAbilityAndActivateOnce = "48 89 5C 24 ? 55 56 57 48 8B EC 48 83 EC 70 49 8B 40 10 49 8B D8";

	// Inventory
	constexpr const char* CreateSimplePickup = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 60 48 8B 01 49 8B D9";
	constexpr const char* CreatePickup = "48 89 5C 24 ? 55 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 41 08 48 8B D9";
	constexpr const char* CreateItemEntry = "48 89 5C 24 ? 57 48 83 EC 20 33 FF 48 C7 01 ? ? ? ? 48 89 79 18 48 8B D9 89 79 28";
	constexpr const char* CreateDefaultItemEntry = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 33 F6 48 C7 01 ? ? ? ? C7 41 ? ? ? ? ? 45 85 C0";
	constexpr const char* SetStateValue = "48 89 5C 24 ? 48 89 6C 24 ? 56 41 56 41 57 48 83 EC 20 48 63 81 ? ? ? ? 45 33 F6";
	constexpr const char* PickupInitialize = "48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 80 B9 ? ? ? ? ? 41 0F B6 E9 49 8B F8";
	constexpr const char* CopyItemEntry = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 30 8B 42 0C";
	constexpr const char* CopyItemEntry2 = "48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 E8 ? ? ? ? 48 8B D3 48 8B CF E8 ? ? ? ? 48 8B 5C 24 ? 48 8B C7";
	constexpr const char* GetItemInstance = "48 89 5C 24 ? 57 48 83 EC 30 48 8B D9 33 C0 48 8B 89 ? ? ? ? 48 8B FA 48 85 C9";
	constexpr const char* GetItemInstances = "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 30 45 33 F6 49 8B D8 48 8B FA";

	// Others
	constexpr const char* GetWorldFromContextObject = "48 89 5C 24 18 56 48 83 EC 40 41 8B D8";
	constexpr const char* InternalGetNetMode = "40 53 48 81 EC ? ? ? ? 48 83 79 ? ? 48 8B D9 74 0E";
	constexpr const char* ActorInternalGetNetMode = "48 89 5C 24 ? 57 48 83 EC 20 48 8B 01 48 8B D9 FF 90 ? ? ? ? 4C 8B 83 ? ? ? ? 48 8B F8";
	constexpr const char* GetPlayerViewPoint = "48 89 5C 24 ? 48 89 74 24 ? 55 41 56 41 57 48 8B EC 48 83 EC 40 48 8B F2 48 C7 45 ? ? ? ? ? 48 8B 55 38";
	constexpr const char* DispatchRequest = "48 89 5C 24 20 55 56 57 41 56 41 57 48 8B EC 48 83 EC 70 48 8B F1";
	constexpr const char* ApplyCharacterCustomization = "48 8B C4 48 89 50 10 55 57 48 8D 68 A1 48 81 EC ? ? ? ? 80 B9 ? ? ? ? ? 48 8B F9";
	constexpr const char* KickPlayer = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B F0 48 8B DA 48 85 D2 0F 84 ? ? ? ? 48 8B BA ? ? ? ? 48 85 FF";
	constexpr const char* ChangingGameSessionId = "40 55 56 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 01 4C 8B F2 48 8B F1 FF 90 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B D0";
	constexpr const char* LocalSpawnPlayActor = "40 55 53 56 57 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 40 48 8B D9 4D 8B F1 49 8B C9 4D 8B F8 48 8B F2";
	//constexpr const char* CollectGarbageInternal = "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 99 ? ? ? ? 48 8B F2 48 63 7B 08 8D 47 01 89 43 08 3B 43 0C 7E 0A 8B D7 48 8B CB E8 ? ? ? ? 48 8D 0C BF 48 8B D6 48 C1 E1 04 48 03 0B E8 ? ? ? ? 48 8B 5C 24 ? B0 01 48 8B 74 24 ? 48 83 C4 20 5F C3 48 8D 45 08 E9 ? ? ? ?";
}