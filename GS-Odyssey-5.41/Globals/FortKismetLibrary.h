#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace FortKismetLibrary
{
	/* ------------------------------------- UFortKismetLibraryOG ------------------------------------ */



	/* -------------------------------------- UFortKismetLibrary ------------------------------------- */

	/*
	 * GetAIDirector retrieves the AI Director for a given world context.
	 *
	 * - Retrieves the world context object from the stack frame to determine the active game world.
	 * - Attempts to get the world from the context object; if unsuccessful, returns a null AI Director.
	 * - Casts the game mode to `AFortGameModeZone` to access zone-specific functionality.
	 * - If the cast is successful, assigns the AI Director from the game mode to the return pointer.
	 * - If the cast or world retrieval fails, sets the AI Director to null and returns.
	 */
	AFortAIDirector* GetAIDirector(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortAIDirector** Ret)
	{
		UObject* WorldContextObject = nullptr;

		Stack.StepCompiledIn(&WorldContextObject);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			AFortGameModeZone* GameModeZone = Cast<AFortGameModeZone>(World->AuthorityGameMode);

			if (GameModeZone)
			{
				*Ret = GameModeZone->AIDirector;
				return *Ret;
			}
		}

		*Ret = nullptr;
		return *Ret;
	}

	/*
	 * GetAIGoalManager retrieves the AI Goal Manager for a given world context.
	 *
	 * - Retrieves the world context object from the stack frame to determine the active game world.
	 * - Attempts to get the world from the context object; if unsuccessful, returns a null AI Goal Manager.
	 * - Casts the game mode to `AFortGameModeZone` to access zone-specific functionality.
	 * - If the cast is successful, assigns the AI Goal Manager from the game mode to the return pointer.
	 * - If the cast or world retrieval fails, sets the AI Goal Manager to null and returns.
	 */
	AFortAIGoalManager* GetAIGoalManager(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortAIGoalManager** Ret)
	{
		UObject* WorldContextObject = nullptr;

		Stack.StepCompiledIn(&WorldContextObject);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (World)
		{
			AFortGameModeZone* GameModeZone = Cast<AFortGameModeZone>(World->AuthorityGameMode);

			if (GameModeZone)
			{
				*Ret = GameModeZone->AIGoalManager;
				return *Ret;
			}
		}

		*Ret = nullptr;
		return *Ret;
	}

	/*
	 * Rewrite UFortKismetLibrary::PickLootDrops (1.1)
	 *
	 * - https://imgur.com/6xCTrE9
	 */
	bool PickLootDrops(UFortKismetLibrary* KismetLibrary, FFrame& Stack, bool* Ret)
	{
		UObject* WorldContextObject = nullptr;
		TArray<FFortItemEntry> OutLootToDrop = {};
		FName TierGroupName = FName(0);
		int32 WorldLevel = -1;
		int32 ForcedLootTier = -1;

		Stack.StepCompiledIn(&WorldContextObject);
		TArray<FFortItemEntry>& LootToDrops = Stack.StepCompiledInRef<TArray<FFortItemEntry>>(&OutLootToDrop);
		Stack.StepCompiledIn(&TierGroupName);
		Stack.StepCompiledIn(&WorldLevel);
		Stack.StepCompiledIn(&ForcedLootTier);

		Stack.Code += Stack.Code != nullptr;

		FFortItemEntry::FreeItemEntries(&OutLootToDrop);

		FName LootTierKey = FName(0);
		int32 LootTier = -1;

		bool bResult = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, TierGroupName, WorldLevel, 0, ForcedLootTier, FGameplayTagContainer());

		if (bResult)
		{
			*Ret = Loots::PickLootDrops(&LootToDrops, WorldLevel, LootTierKey, 0, 0, FGameplayTagContainer(), false, false);
			return *Ret;
		}

		*Ret = false;
		return *Ret;
	}

	/*
	 * K2_SpawnPickupInWorld spawns a pickup item in the game world at a specified location, with customizable options for quantity, rotation, and pickup behavior.
	 *
	 * - Retrieves various parameters from the stack frame:
	 *		- `WorldContextObject`: Provides the context to determine the world.
	 *		- `ItemDefinition`: Specifies the type of item to spawn.
	 *		- `NumberToSpawn`: Determines the quantity of the item.
	 *		- `Position` and `Direction`: Define the spawn location and toss direction.
	 *		- `OverrideMaxStackCount`: Overrides the default max stack count, if specified.
	 *		- `bToss`: Enables tossing the item upon spawn.
	 *		- `bRandomRotation`: Randomizes rotation on spawn if set to true.
	 *		- `bBlockedFromAutoPickup`: Blocks auto-pickup if set to true.
	 * - Ensures both `World` and `ItemDefinition` are valid; if not, returns null.
	 * - Creates an `FFortItemEntry` with the specified item and quantity.
	 * - Sets up `FFortCreatePickupData` with spawn information and flags for random rotation.
	 * - Calls `CreatePickupFromData` to spawn the pickup item in the world.
	 * - If the pickup is successfully created:
	 *		- Tosses the item in the specified direction if `bToss` is true.
	 *		- Sets the `bWeaponsCanBeAutoPickups` flag based on `bBlockedFromAutoPickup`.
	 * - Frees the item entry memory and returns the created pickup.
	 */
	AFortPickup* K2_SpawnPickupInWorld(UFortKismetLibrary* KismetLibrary, FFrame& Stack, AFortPickup** Ret)
	{
		UObject* WorldContextObject = nullptr;
		UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 NumberToSpawn = 1;
		FVector Position = FVector();
		FVector Direction = FVector();
		int32 OverrideMaxStackCount = 0;
		bool bToss = true;
		bool bRandomRotation = true;
		bool bBlockedFromAutoPickup = false;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);
		Stack.StepCompiledIn(&OverrideMaxStackCount);
		Stack.StepCompiledIn(&bToss);
		Stack.StepCompiledIn(&bRandomRotation);
		Stack.StepCompiledIn(&bBlockedFromAutoPickup);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

		if (!World || !ItemDefinition || (NumberToSpawn < 1))
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
		CreatePickupData.World = World;
		CreatePickupData.ItemEntry = &ItemEntry;
		CreatePickupData.SpawnLocation = &Position;
		CreatePickupData.SpawnRotation = nullptr;
		CreatePickupData.PlayerController = nullptr;
		CreatePickupData.OverrideClass = nullptr;
		CreatePickupData.NullptrIdk = nullptr;
		CreatePickupData.bRandomRotation = bRandomRotation;
		CreatePickupData.PickupSourceTypeFlags = 0;

		AFortPickup* Pickup = AFortPickup::CreatePickupFromData(&CreatePickupData);

		if (Pickup)
		{
			Pickup->TossPickup(Direction, nullptr, OverrideMaxStackCount, bToss);
			Pickup->bWeaponsCanBeAutoPickups = !bBlockedFromAutoPickup;
		}

		ItemEntry.FreeItemEntry();

		*Ret = Pickup;
		return *Ret;
	}

	/*
	 * GiveItemToInventoryOwner gives a specified item to an inventory owner, optionally notifying the player with a visual pickup.
	 *
	 * - Retrieves parameters from the stack:
	 *		- `InventoryOwner`: The owner of the inventory (typically a player).
	 *		- `ItemDefinition`: The item type to give.
	 *		- `NumberToGive`: The quantity of the item.
	 *		- `bNotifyPlayer`: If true, the item will be visually shown as a pickup; otherwise, it directly adds to inventory.
	 * - Retrieves the player controller from the inventory owner interface; exits if invalid or if no item definition is provided.
	 * - Retrieves the world context using the player controller; if invalid, the function exits.
	 * - Creates an item entry with the specified item definition and quantity.
	 * - If `bNotifyPlayer` is true:
	 *		- Spawns the item as a pickup in front of the player pawn.
	 *		- Sets the player pawn as the pickup target to visually notify the player.
	 * - If `bNotifyPlayer` is false:
	 *		- Sets a flag to display a toast notification to the player.
	 *		- Directly adds the item to the player’s inventory.
	 * - Frees the item entry memory after adding or spawning.
	 */
	void GiveItemToInventoryOwner(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		TScriptInterface<class IFortInventoryOwnerInterface> InventoryOwner;
		class UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 NumberToGive = 1;
		bool bNotifyPlayer = true;

		Stack.StepCompiledIn(&InventoryOwner);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);

		Stack.Code += Stack.Code != nullptr;

		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner.GetInterface());

		if (!PlayerController || !ItemDefinition)
			return;

		UWorld* World = GEngine->GetWorldFromContextObject(PlayerController, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
			return;

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToGive, -1, -1, -1.0f);

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (bNotifyPlayer && PlayerPawn)
		{
			FVector SpawnLocation = PlayerPawn->K2_GetActorLocation();

			AFortPickup* Pickup = AFortPickup::CreatePickup(World, &ItemEntry, &SpawnLocation);

			if (Pickup)
			{
				const FVector& StartDirection = FVector({ 0, 0, 0 });
				Pickup->SetPickupTarget(PlayerPawn, -1.0f, StartDirection);
			}
		}
		else
		{
			ItemEntry.SetStateValue(EFortItemEntryState::ShouldShowItemToast, 1);
			Inventory::AddInventoryItem(PlayerController, ItemEntry);
		}

		ItemEntry.FreeItemEntry();
	}

	/*
	 * K2_GiveBuildingResource gives a specified amount of a building resource (Wood, Stone, or Metal) to a player
	 *
	 * - Retrieves parameters from the stack:
	 *		- `Controller`: The player controller receiving the resource.
	 *		- `ResourceType`: The type of resource to give.
	 *		- `ResourceAmount`: The amount of the resource to give.
	 * - Uses the resource type to get the appropriate item definition.
	 * - Checks for a valid controller and resource item definition; if either is missing, exits.
	 * - Calls `K2_GiveItemToPlayer` to add the specified resource to the player’s inventory.
	 */
	void K2_GiveBuildingResource(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		AFortPlayerController* Controller = nullptr;
		EFortResourceType ResourceType = EFortResourceType::Wood;
		int32 ResourceAmount = 1;

		Stack.StepCompiledIn(&Controller);
		Stack.StepCompiledIn(&ResourceType);
		Stack.StepCompiledIn(&ResourceAmount);

		Stack.Code += Stack.Code != nullptr;

		UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(ResourceType);

		if (!Controller || !ResourceItemDefinition)
			return;

		UFortKismetLibrary::K2_GiveItemToPlayer(Controller, ResourceItemDefinition, ResourceAmount, false);
	}

	/*
	 * K2_GiveItemToAllPlayers gives a specified item to all players in the game world.
	 *
	 * - Retrieves parameters from the stack:
	 *		- `WorldContextObject`: Provides context to access the game world.
	 *		- `ItemDefinition`: The item type to give.
	 *		- `NumberToGive`: The quantity of the item to give to each player.
	 *		- `bNotifyPlayer`: If true, the item will be visually shown as a pickup for each player.
	 * - Gets all player controllers in the game world.
	 * - For each player controller, checks for validity and calls `K2_GiveItemToPlayer` to add the item to each player’s inventory.
	 */
	void K2_GiveItemToAllPlayers(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		UObject* WorldContextObject = nullptr;
		UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 NumberToGive = 1;
		bool bNotifyPlayer = true;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);

		Stack.Code += Stack.Code != nullptr;

		TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

		for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
			if (!PlayerController) return;

			UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, NumberToGive, bNotifyPlayer);
		}
	}

	/*
	 * K2_GiveItemToPlayer gives a specified item to a single player, optionally notifying them with a pickup.
	 *
	 * - Retrieves parameters from the stack:
	 *		- `PlayerController`: The player controller to receive the item.
	 *		- `ItemDefinition`: The item type to give.
	 *		- `NumberToGive`: The quantity of the item.
	 *		- `bNotifyPlayer`: If true, the item will be visually shown as a pickup; otherwise, it directly adds to inventory.
	 * - Checks for a valid player controller and item definition; if either is missing, exits.
	 * - Retrieves the world context; if invalid, exits.
	 * - Creates an item entry with the specified item definition and quantity.
	 * - If `bNotifyPlayer` is true:
	 *		- Spawns the item as a pickup at the player's location.
	 *		- Sets the player pawn as the pickup target to visually notify the player.
	 * - If `bNotifyPlayer` is false:
	 *		- Sets a flag to display a toast notification to the player.
	 *		- Directly adds the item to the player’s inventory.
	 * - Frees the item entry memory after adding or spawning.
	 */
	void K2_GiveItemToPlayer(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		AFortPlayerController* PlayerController = nullptr;
		UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 NumberToGive = 1;
		bool bNotifyPlayer = true;

		Stack.StepCompiledIn(&PlayerController);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToGive);
		Stack.StepCompiledIn(&bNotifyPlayer);	

		Stack.Code += Stack.Code != nullptr;

		if (!PlayerController || !ItemDefinition)
			return;

		UWorld* World = GEngine->GetWorldFromContextObject(PlayerController, EGetWorldErrorMode::LogAndReturnNull);

		if (!World)
			return;

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToGive, -1, -1, -1.0f);

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (bNotifyPlayer && PlayerPawn)
		{
			FVector SpawnLocation = PlayerPawn->K2_GetActorLocation();

			AFortPickup* Pickup = AFortPickup::CreatePickup(World, &ItemEntry, &SpawnLocation);

			if (Pickup)
			{
				const FVector& StartDirection = FVector({ 0, 0, 0 });
				Pickup->SetPickupTarget(PlayerPawn, -1.0f, StartDirection);
			}
		}
		else
		{
			ItemEntry.SetStateValue(EFortItemEntryState::ShouldShowItemToast, 1);
			Inventory::AddInventoryItem(PlayerController, ItemEntry);
		}

		ItemEntry.FreeItemEntry();
	}

	/*
	 * K2_RemoveItemFromAllPlayers removes a specified amount of an item from all players in the game world.
	 *
	 * - Retrieves parameters from the stack:
	 *		- `WorldContextObject`: Provides context to access the game world.
	 *		- `ItemDefinition`: The item type to be removed.
	 *		- `AmountToRemove`: The quantity of the item to remove from each player.
	 * - Gets all player controllers in the game world.
	 * - For each player controller, checks for validity and calls `K2_RemoveItemFromPlayer` to remove the item from each player’s inventory.
	 */
	void K2_RemoveItemFromAllPlayers(UFortKismetLibrary* KismetLibrary, FFrame& Stack, void* Ret)
	{
		UObject* WorldContextObject = nullptr;
		UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 AmountToRemove = 1;

		Stack.StepCompiledIn(&WorldContextObject);
		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&AmountToRemove);

		Stack.Code += Stack.Code != nullptr;

		TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

		for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
			if (!PlayerController) return;

			UFortKismetLibrary::K2_RemoveItemFromPlayer(PlayerController, ItemDefinition, AmountToRemove, false);
		}
	}

	/*
	 * K2_RemoveItemFromPlayer removes a specified amount of an item from a single player's inventory based on the item definition.
	 *
	 * - Checks for a valid player controller and item definition; if either is missing, exits and returns 0.
	 * - Attempts to find an existing item in the player's inventory that matches the specified item definition.
	 * - If the item is found:
	 *		- Calculates the final item count after removal.
	 *		- Ensures the final count is not negative (sets to 0 if less than zero).
	 *		- Calls `RemoveInventoryItem` to remove the specified amount from the player's inventory.
	 * - Returns the final count of the item after removal.
	 */
	int32 K2_RemoveItemFromPlayer(AFortPlayerController* PlayerController, UFortWorldItemDefinition* ItemDefinition, int32 AmountToRemove, bool bForceRemoval)
	{
		if (!PlayerController || !ItemDefinition)
			return 0;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ItemDefinition, false));

		if (WorldItem)
		{
			int32 ItemCount = WorldItem->ItemEntry.Count;
			int32 FinalCount = ItemCount - AmountToRemove;

			if (FinalCount < 0)
				FinalCount = 0;

			PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, AmountToRemove, false, bForceRemoval);

			return FinalCount;
		}

		return 0;
	}

	/*
	 * K2_RemoveItemFromPlayerByGuid removes a specified amount of an item from a single player's inventory based on the item GUID.
	 *
	 * - Checks for a valid player controller; if invalid, exits and returns 0.
	 * - Attempts to find an existing item in the player's inventory using the specified GUID.
	 * - If the item is found:
	 *		- Calculates the final item count after removal.
	 *		- Ensures the final count is not negative (sets to 0 if less than zero).
	 *		- Calls `RemoveInventoryItem` to remove the specified amount from the player's inventory.
	 * - Returns the final count of the item after removal.
	 */
	int32 K2_RemoveItemFromPlayerByGuid(AFortPlayerController* PlayerController, const FGuid& ItemGuid, int32 AmountToRemove, bool bForceRemoval)
	{
		if (!PlayerController)
			return 0;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(ItemGuid));

		if (WorldItem)
		{
			int32 ItemCount = WorldItem->ItemEntry.Count;
			int32 FinalCount = ItemCount - AmountToRemove;

			if (FinalCount < 0)
				FinalCount = 0;

			PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, AmountToRemove, false, bForceRemoval);

			return FinalCount;
		}

		return 0;
	}

	void InitFortKismetLibrary()
	{
		/* -------------------------------------- UFortKismetLibrary ------------------------------------- */

		UFunction* GetAIDirectorFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "GetAIDirector");
		MinHook::HookFunctionExec(GetAIDirectorFunc, GetAIDirector, nullptr);

		UFunction* GetAIGoalManagerFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "GetAIGoalManager");
		MinHook::HookFunctionExec(GetAIGoalManagerFunc, GetAIGoalManager, nullptr);

		UFunction* PickLootDropsFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "PickLootDrops");
		MinHook::HookFunctionExec(PickLootDropsFunc, PickLootDrops, nullptr);

		UFunction* K2_SpawnPickupInWorldFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "K2_SpawnPickupInWorld");
		MinHook::HookFunctionExec(K2_SpawnPickupInWorldFunc, K2_SpawnPickupInWorld, nullptr);

		UFunction* GiveItemToInventoryOwnerFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "GiveItemToInventoryOwner");
		MinHook::HookFunctionExec(GiveItemToInventoryOwnerFunc, GiveItemToInventoryOwner, nullptr);

		UFunction* K2_GiveBuildingResourceFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "K2_GiveBuildingResource");
		MinHook::HookFunctionExec(K2_GiveBuildingResourceFunc, K2_GiveBuildingResource, nullptr);

		UFunction* K2_GiveItemToAllPlayersFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "K2_GiveItemToAllPlayers");
		MinHook::HookFunctionExec(K2_GiveItemToAllPlayersFunc, K2_GiveItemToAllPlayers, nullptr);

		UFunction* K2_GiveItemToPlayerFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "K2_GiveItemToPlayer");
		MinHook::HookFunctionExec(K2_GiveItemToPlayerFunc, K2_GiveItemToPlayer, nullptr);

		UFunction* K2_RemoveItemFromAllPlayersFunc = UFortKismetLibrary::StaticClass()->GetFunction("FortKismetLibrary", "K2_RemoveItemFromAllPlayers");
		MinHook::HookFunctionExec(K2_RemoveItemFromAllPlayersFunc, K2_RemoveItemFromAllPlayers, nullptr);

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xEBE880), K2_RemoveItemFromPlayer, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xEBE880));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xEBE8A0), K2_RemoveItemFromPlayerByGuid, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xEBE8A0));

		FN_LOG(LogInit, Log, "InitFortKismetLibrary Success!");
	}
}