#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace Pawn
{
	/* -------------------------------------- AFortPlayerPawnOG -------------------------------------- */
	/* ----------------------------------------- AFortPawnOG ----------------------------------------- */
	void (*OnDeathServerOG)(AFortPawn* Pawn, float Damage, const FGameplayTagContainer& DamageTags, const FVector& Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext);
;
	

	/* --------------------------------------- AFortPlayerPawn --------------------------------------- */

	/*
	 * Rewrite AFortPlayerPawn::ServerHandlePickup (1.8)
	 *
	 * - https://imgur.com/pKR6Nlh
	 * - https://imgur.com/Yi6yLaC
	 */
	void ServerHandlePickup(AFortPlayerPawn* PlayerPawn, AFortPickup* Pickup, float InFlyTime, const FVector& InStartDirection, bool bPlayPickupSound)
	{
		if (!PlayerPawn || !Pickup)
			return;

		float FlyTime = InFlyTime / PlayerPawn->PickupSpeedMultiplier;

		Pickup->PickupLocationData.PickupGuid = PlayerPawn->LastEquippedWeaponGUID;
		Pickup->SetPickupTarget(PlayerPawn, FlyTime, InStartDirection, bPlayPickupSound);
	}

	void ServerHandlePickupWithSwap(AFortPlayerPawn* PlayerPawn, AFortPickup* Pickup, const FGuid& Swap, float InFlyTime, const FVector& InStartDirection, bool bPlayPickupSound)
	{
		if (!PlayerPawn || !Pickup)
			return;

		float FlyTime = InFlyTime / PlayerPawn->PickupSpeedMultiplier;

		Pickup->PickupLocationData.PickupGuid = PlayerPawn->LastEquippedWeaponGUID;
		Pickup->SetPickupTarget(PlayerPawn, FlyTime, InStartDirection, bPlayPickupSound);
	}

	/*
	 * OnCapsuleBeginOverlap handles the event when a player's capsule (collision component) overlaps with another object, typically a pickup item.
	 *
	 * - Retrieves parameters from the stack:
	 *		- `OverlappedComp`: The component that triggered the overlap.
	 *		- `OtherActor`: The other actor involved in the overlap (likely a pickup).
	 *		- `OtherComp`, `OtherBodyIndex`, `bFromSweep`, `SweepResult`: Additional overlap parameters.
	 * - Checks if the player controller is valid and if the other actor is a valid pickup object.
	 * - Calculates a delay for auto-picking up the dropped item:
	 *		- Evaluates a curve table to determine the repickup delay based on player-specific factors.
	 * - Validates conditions for auto-pickup:
	 *		- Ensures `GAutoResourceGathering` is enabled.
	 *		- Confirms that the player is not in certain states (e.g., down but not out, skydiving).
	 *		- Checks that the item can be auto-picked, hasn’t been picked up, and wasn't recently dropped by the player within the repickup delay.
	 * - Retrieves the item definition and calculates the player's current quantity of the item, considering both the inventory and queued pickups.
	 * - If the player’s total quantity of the item does not exceed the max stack size and allows for additional stacks, adds the pickup to the auto-pickup queue.
	 * - Finally, calls `ServerHandlePickup` to initiate the auto-pickup process with a generated fly time for the pickup animation.
	 */
	void OnCapsuleBeginOverlap(AFortPlayerPawn* PlayerPawn, FFrame& Stack, void* Ret)
	{
		UPrimitiveComponent* OverlappedComp = nullptr;
		AActor* OtherActor = nullptr;
		UPrimitiveComponent* OtherComp = nullptr;
		int32 OtherBodyIndex = -1;
		bool bFromSweep = true;
		FHitResult SweepResult = FHitResult();

		Stack.StepCompiledIn(&OverlappedComp);
		Stack.StepCompiledIn(&OtherActor);
		Stack.StepCompiledIn(&OtherComp);
		Stack.StepCompiledIn(&OtherBodyIndex);
		Stack.StepCompiledIn(&bFromSweep);
		Stack.StepCompiledIn(&SweepResult);

		Stack.Code += Stack.Code != nullptr;

		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
		if (!PlayerController) return;

		AFortPickup* Pickup = Cast<AFortPickup>(OtherActor);
		if (!Pickup) return;

		float RepickupDelay = PlayerPawn->AutoPickupDropRepickupDelay.GetValueAtLevel(0);

		if (!GAutoResourceGathering)
			return;

		if (!PlayerPawn->bIsDBNO ||
			!PlayerPawn->bIsSkydiving)
		{
			if (Pickup->bPickedUp || !Pickup->bWeaponsCanBeAutoPickups)
				return;

			if (!Pickup->bServerStoppedSimulation && (Pickup->PawnWhoDroppedPickup == PlayerPawn))
				return;

			if (Pickup->PawnWhoDroppedPickup == PlayerPawn)
			{
				const float LastDropPickupTime = Pickup->LastDropPickupTime();
				const float TimeSeconds = PlayerPawn->GetWorld()->GetTimeSeconds();

				if ((TimeSeconds - LastDropPickupTime) <= RepickupDelay)
					return;
			}
			
			UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(Pickup->PrimaryPickupItemEntry.ItemDefinition);
			if (!WorldItemDefinition) return;

			int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WorldItemDefinition);

			for (int32 i = 0; i < PlayerPawn->QueuedAutoPickups.Num(); i++)
			{
				AFortPickup* QueuedAutoPickup = PlayerPawn->QueuedAutoPickups[i];
				if (!QueuedAutoPickup) continue;

				UFortWorldItemDefinition* QueuedWorldItemDefinition = Cast<UFortWorldItemDefinition>(QueuedAutoPickup->PrimaryPickupItemEntry.ItemDefinition);
				if (!QueuedWorldItemDefinition) continue;

				if (QueuedWorldItemDefinition != WorldItemDefinition)
					continue;

				ItemQuantity += QueuedAutoPickup->PrimaryPickupItemEntry.Count;
			}

			if (ItemQuantity >= WorldItemDefinition->MaxStackSize && !WorldItemDefinition->bAllowMultipleStacks)
				return;

			PlayerPawn->QueuedAutoPickups.Add(Pickup);

			float InFlyTime = Globals::GenFlyTime();
			PlayerPawn->ServerHandlePickup(Pickup, InFlyTime, FVector(), true);
		}
	}

	/*
	 * OnDeathServer is triggered when a player pawn dies on the server, handling additional actions specific to player death.
	 *
	 * - Attempts to cast the pawn’s controller to `AFortPlayerControllerAthena` to check if it’s a player in Athena mode.
	 * - If the controller is valid and belongs to `AFortPlayerControllerAthena`:
	 *		- Calls `ServerDropAllItems` to drop all items from the player's inventory on death.
	 *		- Calls `ResetInventory` to clear the player's world inventory after dropping items.
	 */
	void OnDeathServer(AFortPawn* Pawn, float Damage, const FGameplayTagContainer& DamageTags, const FVector& Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, const FGameplayEffectContextHandle& EffectContext)
	{
		OnDeathServerOG(Pawn, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(Pawn->Controller);
		if (!PlayerControllerAthena) return;

		if (PlayerControllerAthena)
		{
			PlayerControllerAthena->ServerDropAllItems(nullptr);
			Inventory::ResetInventory(PlayerControllerAthena->WorldInventory);
		}
	}

	void MovingEmoteStopped(AFortPawn* Pawn, FFrame& Stack, void* Ret)
	{
		Stack.Code += Stack.Code != nullptr;

		Pawn->bMovingEmote = false;
	}

	void InitPawn()
	{
		AFortPlayerPawnAthena* FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();
		UClass* FortPlayerPawnAthenaClass = AFortPlayerPawnAthena::StaticClass();

		/* --------------------------------------- AFortPlayerPawn --------------------------------------- */

		MinHook::HookVTable(FortPlayerPawnAthenaDefault, 0xD40 / 8, ServerHandlePickup, nullptr, "AFortPlayerPawn::ServerHandlePickup");
		MinHook::HookVTable(FortPlayerPawnAthenaDefault, 0xD30 / 8, ServerHandlePickupWithSwap, nullptr, "AFortPlayerPawn::ServerHandlePickupWithSwap");

		UFunction* OnCapsuleBeginOverlapFunc = FortPlayerPawnAthenaClass->GetFunction("FortPlayerPawn", "OnCapsuleBeginOverlap");
		MinHook::HookFunctionExec(OnCapsuleBeginOverlapFunc, OnCapsuleBeginOverlap, nullptr);

		/* ------------------------------------------ AFortPawn ------------------------------------------ */

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x14B4330), OnDeathServer, (LPVOID*)(&OnDeathServerOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x14B4330));

		UFunction* MovingEmoteStoppedFunc = FortPlayerPawnAthenaClass->GetFunction("FortPawn", "MovingEmoteStopped");
		MinHook::HookFunctionExec(MovingEmoteStoppedFunc, MovingEmoteStopped, nullptr);

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, L"InitPawn Success!");
	}
}