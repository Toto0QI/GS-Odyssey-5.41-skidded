#pragma once

namespace Pawn
{
	void (*SetPickupTarget)(AFortPickup* Pickup, AFortPlayerPawn* Pawn, float InFlyTime, const FVector& InStartDirection, bool bPlayPickupSound);

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms, bool* bCallOG)
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

#ifdef ANTICHEAT
			UAntiCheatOdyssey* AntiCheatOdyssey = FindOrCreateAntiCheatOdyssey(PlayerController);

			if (AntiCheatOdyssey)
			{
				const float Distance = PlayerPawn->GetDistanceTo(Pickup);
				const float MaxDistance = AntiCheatOdyssey->GetMaxPickupDistance();

				if (Distance > MaxDistance && !PlayerPawn->bIsSkydiving)
				{
					const FString& PlayerName = AntiCheatOdyssey->GetPlayerName();

					if (PlayerName.IsValid())
					{
						AC_LOG(ACWarning, "Player [%s] tries to ServerHandlePickup when the distance is [%.2f] and the max is [%.2f]",
							AntiCheatOdyssey->GetPlayerName().ToString().c_str(), Distance, MaxDistance);
					}

					AntiCheatOdyssey->BanByAntiCheat(L"AC - You took a pickup too far away!");
					return;
				}
			}
#endif // ANTICHEAT

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

				if (PlayerController && PlayerController->WorldInventory)
				{
					FVector SpawnLocation = Pawn->K2_GetActorLocation();

					SpawnLocation.Z += 15.0f;

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

						FVector RandomOffset = UKismetMathLibrary::RandomUnitVector() * UKismetMathLibrary::RandomFloatInRange(400.0f, 600.0f);
						FVector FinalLocation = UKismetMathLibrary::Add_VectorVector(SpawnLocation, RandomOffset);

						Inventory::SpawnPickup(Pawn, NewItemEntry, SpawnLocation, FinalLocation, true);
						Inventory::FreeItemEntry(&NewItemEntry);
					}

					Inventory::ResetInventory(PlayerController->WorldInventory);
				}
			}
		}

#ifdef ANTICHEAT
		else if (FunctionName.contains("OnDamageServer"))
		{
			AFortPawn* Pawn = Cast<AFortPawn>(Object);
			auto Params = (Params::FortPawn_OnDamageServer*)Parms;

			AActor* DamageCauser = Params->DamageCauser;

			if (!Pawn || !DamageCauser)
				return;

			float Damage = Params->Damage;

			APlayerController* PlayerController = Cast<APlayerController>(Params->InstigatedBy);
			UAntiCheatOdyssey* AntiCheatOdyssey = FindOrCreateAntiCheatOdyssey(PlayerController);

			if (AntiCheatOdyssey)
			{
				AFortWeapon* Weapon = Cast<AFortWeapon>(DamageCauser);

				if (Weapon && Weapon->WeaponData)
				{
					UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(Weapon->WeaponData);

					if (!WorldItemDefinition)
						return;

					const float Distance = PlayerController->Pawn ? PlayerController->Pawn->GetDistanceTo(Pawn) : Weapon->GetDistanceTo(Pawn);

					EFortItemType ItemType = WorldItemDefinition->ItemType;

					if (ItemType == EFortItemType::WeaponHarvest)
					{
						const float MaxDistance = AntiCheatOdyssey->GetMaxPickaxeDistance();

						if (Distance > MaxDistance)
						{
							const FString& PlayerName = AntiCheatOdyssey->GetPlayerName();

							if (PlayerName.IsValid())
							{
								AC_LOG(ACWarning, "Player [%s] attempted to damage a player with a pickaxe at a distance of [%.2f] with a maximum of [%.2f]",
									AntiCheatOdyssey->GetPlayerName().ToString().c_str(), Distance, MaxDistance);
							}

							AntiCheatOdyssey->BanByAntiCheat(L"AC - You put pickaxe damage at too long a distance!");
							*bCallOG = false;
							return;
						}
					}
					else if (ItemType == EFortItemType::WeaponMelee)
					{

					}

					AC_LOG(ACLog, "Player [%s] attempted to damage a player at a distance of [%.2f]", AntiCheatOdyssey->GetPlayerName().ToString().c_str(), Distance);
					AC_LOG(ACLog, "ItemType: %i", ItemType);
				}
			}

			FN_LOG(LogPawn, Log, "Pawn: %s", Pawn->GetName().c_str());

			FN_LOG(LogPawn, Log, "DamageCauser: %s", DamageCauser->GetName().c_str());
			FN_LOG(LogPawn, Log, "Damage: %.2f", Damage);
			FN_LOG(LogPawn, Log, "InstigatedBy: %s", PlayerController->GetName().c_str());

			FHitResult HitInfo = Params->HitInfo;

			FN_LOG(LogPawn, Log, "Time: %.2f", HitInfo.Time);
			FN_LOG(LogPawn, Log, "Distance: %.2f", HitInfo.Distance);
			FN_LOG(LogPawn, Log, "Location: [X: %.2f, Y: %.2f, Z: %.2f]", HitInfo.Location.X, HitInfo.Location.Y, HitInfo.Location.Z);
			FN_LOG(LogPawn, Log, "ImpactPoint: [X: %.2f, Y: %.2f, Z: %.2f]", HitInfo.ImpactPoint.X, HitInfo.ImpactPoint.Y, HitInfo.ImpactPoint.Z);

			FN_LOG(LogPawn, Log, "AFortPawn::OnDamageServer called!");
		}
#endif // ANTICHEAT
	}


	void InitPawn()
	{
		static auto FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		uintptr_t PatternSetPickupTarget = MinHook::FindPattern(Patterns::SetPickupTarget);

		SetPickupTarget = decltype(SetPickupTarget)(PatternSetPickupTarget);

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}