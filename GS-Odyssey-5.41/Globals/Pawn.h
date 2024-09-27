#pragma once

namespace Pawn
{
	void (*SetPickupTarget)(AFortPickup* Pickup, AFortPlayerPawn* Pawn, float InFlyTime, const FVector& InStartDirection, bool bPlayPickupSound);

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		if (!Object->IsA(AFortPawn::StaticClass()))
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ServerHandlePickupWithSwap")) // Finir la fonction
		{
			AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(Object);
			auto Params = (Params::FortPlayerPawn_ServerHandlePickupWithSwap*)Parms;

			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
			AFortPickup* Pickup = Params->Pickup;

			if (!PlayerPawn || !PlayerController || !Pickup)
			{
				FN_LOG(LogPawn, Error, "[AFortPlayerPawn::ServerHandlePickup] Failed to get PlayerPawn/PlayerController/Pickup!");
				return;
			}

			FN_LOG(LogPawn, Log, "[AFortPlayerPawn::ServerHandlePickupWithSwap] func called!");
		}
		else if (FunctionName.contains("ServerHandlePickup"))
		{
			AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(Object);
			auto Params = (Params::FortPlayerPawn_ServerHandlePickup*)Parms;

			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
			AFortPickup* Pickup = Params->Pickup;

			if (!PlayerPawn || !PlayerController || !Pickup)
			{
				FN_LOG(LogPawn, Error, "[AFortPlayerPawn::ServerHandlePickup] Failed to get PlayerPawn/PlayerController/Pickup!");
				return;
			}

			if (Pickup->bPickedUp)
				return;

			SetPickupTarget(Pickup, PlayerPawn, UKismetMathLibrary::RandomFloatInRange(0.40f, 0.54f), FVector(), true);

			FFortPickupLocationData* PickupLocationData = &Pickup->PickupLocationData;
			PickupLocationData->PickupGuid = PlayerPawn->LastEquippedWeaponGUID;
			Pickup->OnRep_PickupLocationData();
		}
		else if (FunctionName.contains("OnCapsuleBeginOverlap"))
		{
			AFortPlayerPawn* PlayerPawn = Cast<AFortPlayerPawn>(Object);
			auto Params = (Params::FortPlayerPawn_OnCapsuleBeginOverlap*)Parms;

			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);
			AActor* OtherActor = Params->OtherActor;

			if (!PlayerPawn || !PlayerController || !OtherActor)
				return;

			AFortPickup* Pickup = Cast<AFortPickup>(OtherActor);

			if (Pickup)
			{
				if (Pickup->bPickedUp || !Pickup->bWeaponsCanBeAutoPickups)
					return;

				if (!Pickup->bServerStoppedSimulation && Pickup->PawnWhoDroppedPickup)
					return;

				UFortItemDefinition* ItemDefinition = Pickup->PrimaryPickupItemEntry.ItemDefinition;

				if (ItemDefinition)
				{
					if (ItemDefinition->IsA(UFortAmmoItemDefinition::StaticClass()) ||
						ItemDefinition->IsA(UFortTrapItemDefinition::StaticClass()) ||
						ItemDefinition->IsA(UFortResourceItemDefinition::StaticClass()))
					{
						UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ItemDefinition, false));

						if (WorldItem)
						{
							if (WorldItem->ItemEntry.Count >= WorldItem->ItemEntry.ItemDefinition->MaxStackSize && !WorldItem->ItemEntry.ItemDefinition->bAllowMultipleStacks)
								return;
						}

						const FVector& InStartDirection = Params->OtherActor->K2_GetActorLocation();
						PlayerPawn->ServerHandlePickup(Pickup, 0.f, InStartDirection, true);
					}
				}
			}
		}
		else if (FunctionName.contains("OnDeathServer"))
		{
			AFortPawn* Pawn = Cast<AFortPawn>(Object);

			if (Pawn)
			{
				AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Pawn->Controller);

				if (!PlayerController)
					return;

				//TArray<UFortWorldItem*> ItemInstances;
				//Inventory::GetItemInstances(PlayerController->WorldInventory, &ItemInstances);

				if (PlayerController->WorldInventory)
				{
					const FVector& SpawnLocation = Pawn->K2_GetActorLocation();

					for (int32 i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
					{
						UFortWorldItem* ItemInstance = PlayerController->WorldInventory->Inventory.ItemInstances[i];
						if (!ItemInstance) continue;

						FFortItemEntry* ItemEntry = &ItemInstance->ItemEntry;
						if (!ItemEntry) continue;

						UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry->ItemDefinition);
						if (!ItemDefinition) continue;

						if (!ItemDefinition->bCanBeDropped)
							continue;

						FFortItemEntry NewItemEntry;
						Inventory::CreateItemEntry(&NewItemEntry);
						Inventory::CopyItemEntry(&NewItemEntry, &ItemInstance->ItemEntry);

						Inventory::SpawnPickup(Pawn, NewItemEntry, SpawnLocation, true);

						Inventory::FreeItemEntry(&NewItemEntry);
					}

					Inventory::ResetInventory(PlayerController->WorldInventory);
				}
			}
		}
	}


	void InitPawn()
	{
		static auto FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		uintptr_t PatternSetPickupTarget = MinHook::FindPattern(Patterns::SetPickupTarget);

		SetPickupTarget = decltype(SetPickupTarget)(PatternSetPickupTarget);

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}