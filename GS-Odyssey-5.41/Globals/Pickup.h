#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace Pickup
{
	/* ----------------------------------------- AFortPickupOG --------------------------------------- */

	bool (*PickupAddInventoryOwnerInterfaceOG)(AFortPickup* Pickup, void* InventoryOwner);
	void (*TossPickupOG)(AFortPickup* Pickup, const FVector& FinalLocation, class AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss);
	void (*OnServerStopCallbackOG)(AFortPickup* Pickup, const FHitResult& Hit);



	/* ------------------------------------------ AFortPickup ---------------------------------------- */

	/*
	 * PickupAddInventoryOwnerInterface adds a pickup item to the inventory of an owner implementing the inventory interface.
	 *
	 * - Validates `Pickup` and `InventoryOwner`; if either is invalid, exits and returns false.
	 * - Retrieves the player controller from the inventory owner interface; if invalid, exits.
	 * - Retrieves the player pawn associated with the controller; if invalid, exits.
	 * - Iterates through the player pawn's queued auto-pickups:
	 *		- Checks if the pickup is in the auto-pickup queue.
	 *		- Removes the pickup from the queue if found.
	 * - Adds the pickup item to the player's inventory using `AddInventoryItem`, passing in the item's entry data and unique pickup GUID.
	 * - Returns true to indicate the pickup was successfully added to the inventory.
	 */
	bool PickupAddInventoryOwnerInterface(AFortPickup* Pickup, void* InventoryOwner)
	{
		PickupAddInventoryOwnerInterfaceOG(Pickup, InventoryOwner);

		if (!Pickup || !InventoryOwner)
			return false;

		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return false;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return false;

		for (int32 i = 0; i < PlayerPawn->QueuedAutoPickups.Num(); i++)
		{
			AFortPickup* QueuedAutoPickup = PlayerPawn->QueuedAutoPickups[i];
			if (!QueuedAutoPickup) continue;

			if (QueuedAutoPickup == Pickup)
			{
				PlayerPawn->QueuedAutoPickups.Remove(i);
				break;
			}
		}

		Inventory::AddInventoryItem(PlayerController, Pickup->PrimaryPickupItemEntry, Pickup->PickupLocationData.PickupGuid);

		return true;
	}

	/*
	 * TossPickup:
	 * 
	 * - If a nearby pickup is found:
	 *		- Sets the `CombineTarget` in `PickupLocationData` to the closest pickup.
	 *		- Configures fly time, initial and final positions, and toss rest location for a smooth combination.
	 */
	void TossPickup(AFortPickup* Pickup, const FVector& FinalLocation, class AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss)
	{
		TossPickupOG(Pickup, FinalLocation, ItemOwner, OverrideMaxStackCount, bToss);

		if (Pickup->bTossedFromContainer)
			return;

		Inventory::CombineNearestPickup(Pickup, 300.0f);
	}

	/*
	 * OnServerStopCallback, the server detects that a pickup has stopped moving, allowing for additional actions like combining with nearby pickups.
	 *
	 * - Checks if the pickup is being destroyed or if combining is not enabled (`bCombinePickupsWhenTossCompletes`).
	 *		- If either condition is true, exits the function.
	 * - Calls `CombineNearestPickup` from the `Inventory` namespace, passing in the pickup and a radius of 500 units.
	 *		- This attempts to find and combine the pickup with the nearest compatible pickup within the specified radius.
	 */
	void OnServerStopCallback(AFortPickup* Pickup, const FHitResult& Hit)
	{
		OnServerStopCallbackOG(Pickup, Hit);

		if (Pickup->bActorIsBeingDestroyed || !Pickup->bCombinePickupsWhenTossCompletes)
			return;

		Inventory::CombineNearestPickup(Pickup, 400.0f);
	}

	/*
	 * CombinePickup combines the current pickup item with a target pickup if they are near each other and have compatible item definitions.
	 *
	 * - Retrieves the `CombineTarget` from `PickupLocationData` and ensures it’s valid and not being destroyed.
	 * - Checks if the item definitions of both pickups are the same to proceed with the combination.
	 * - Calculates the new total count and adjusts it to respect the max stack size:
	 *		- Adds any excess items that exceed the stack limit as a new pickup at the same location.
	 * - Sets the combined count for the target pickup and updates its network state.
	 * - If a new pickup is needed for excess items, creates it with the appropriate item entry and tosses it nearby.
	 * - Destroys the original pickup after completing the combination.
	 */
	void CombinePickup(AFortPickup* Pickup, FFrame& Stack, void* Ret)
	{
		Stack.Code += Stack.Code != nullptr;

		if (Pickup->bActorIsBeingDestroyed)
			return;

		AFortPickup* CombineTarget = Pickup->PickupLocationData.CombineTarget;

		if (!CombineTarget || CombineTarget->bActorIsBeingDestroyed)
			return;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(CombineTarget->PrimaryPickupItemEntry.ItemDefinition);
		if (!WorldItemDefinition) return;

		int32 NewCount = Pickup->PrimaryPickupItemEntry.Count + CombineTarget->PrimaryPickupItemEntry.Count;
		int32 CountToRemove = UKismetMathLibrary::Max(0, NewCount - WorldItemDefinition->MaxStackSize);
		NewCount = UKismetMathLibrary::Min(NewCount, WorldItemDefinition->MaxStackSize);

		CombineTarget->PrimaryPickupItemEntry.SetCount(NewCount);
		CombineTarget->FlushNetDormancy();

		if (CountToRemove > 0)
		{
			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, WorldItemDefinition, CountToRemove, Pickup->PrimaryPickupItemEntry.Level, Pickup->PrimaryPickupItemEntry.LoadedAmmo, Pickup->PrimaryPickupItemEntry.Durability);

			const FVector& SpawnLocation = CombineTarget->K2_GetActorLocation();

			AFortPickup* NewPickup = AFortPickup::CreatePickup(
				Pickup->GetWorld(),
				&ItemEntry,
				&SpawnLocation,
				nullptr,
				nullptr,
				nullptr,
				true,
				(uint32)EFortPickupSourceTypeFlag::Other);

			if (NewPickup)
			{
				NewPickup->TossPickup(SpawnLocation, nullptr, 0, true);
			}

			ItemEntry.FreeItemEntry();
		}

		Pickup->K2_DestroyActor();
	}

	void InitPickup()
	{
		AFortPickupAthena* FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();
		UClass* FortPickupAthenaClass = AFortPickupAthena::StaticClass();

		/* ------------------------------------------ AFortPickup ---------------------------------------- */

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xFA11C0), PickupAddInventoryOwnerInterface, (LPVOID*)(&PickupAddInventoryOwnerInterfaceOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xFA11C0));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xFABF80), TossPickup, (LPVOID*)(&TossPickupOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xFABF80));

		MinHook::HookVTable(FortPickupAthenaDefault, 0x630 / 8, OnServerStopCallback, (LPVOID*)(&OnServerStopCallbackOG), "AFortPickup::OnServerStopCallback");

		UFunction* OnRep_ServerImpactSoundFlashFunc = FortPickupAthenaClass->GetFunction("FortPickup", "OnRep_ServerImpactSoundFlash");
		MinHook::HookFunctionExec(OnRep_ServerImpactSoundFlashFunc, CombinePickup, nullptr);

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, L"InitPawn Success!");
	}
}