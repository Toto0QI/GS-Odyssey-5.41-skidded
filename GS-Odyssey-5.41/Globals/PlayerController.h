#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace PlayerController
{
	/* -------------------------------- AFortPlayerControllerAthenaOG -------------------------------- */
	void (*ServerAttemptAircraftJumpOG)(AFortPlayerControllerAthena* PlayerControllerAthena, const FRotator& ClientRotation);
	void (*ServerThankBusDriverOG)(AFortPlayerControllerAthena* PlayerControllerAthena);
	void (*ServerPlaceMapCursorOG)(AFortPlayerControllerAthena* PlayerControllerAthena, const FVector_NetQuantize& CursorPos);
	void (*ServerRemoveMapCursorOG)(AFortPlayerControllerAthena* PlayerControllerAthena);
	/* --------------------------------- AFortPlayerControllerZoneOG --------------------------------- */
	void (*ClientOnPawnDiedOG)(AFortPlayerControllerZone* PlayerController, const FFortPlayerDeathReport& DeathReport);
	/* ----------------------------------- AFortPlayerControllerOG ----------------------------------- */
	void (*ServerReadyToStartMatchOG)(AFortPlayerController* PlayerController);
	void (*ServerAttemptInteractOG)(AFortPlayerController* PlayerController, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData);
	/* ------------------------------------- PlayerControllerOG -------------------------------------- */
	void (*ServerChangeNameOG)(APlayerController* PlayerController, const FString& S);
	/* ----------------------------------------------------------------------------------------------- */



	/* --------------------------------- AFortPlayerControllerAthena --------------------------------- */

	void ServerAttemptAircraftJump(AFortPlayerControllerAthena* PlayerControllerAthena, const FRotator& ClientRotation)
	{
		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());
		if (!GameModeAthena) return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);
		if (!GameStateAthena) return;

		int32 AircraftIndex = GameStateAthena->GetAircraftIndex(PlayerControllerAthena->PlayerState);
		AFortAthenaAircraft* AthenaAircraft = GameStateAthena->GetAircraft(AircraftIndex);

		if (AthenaAircraft && PlayerControllerAthena->IsInAircraft())
		{
#if 0
			// 7FF66F24DCC0
			void (*SpawnPlayerFromAircraft)(AFortGameModeAthena* GameModeAthena, AFortPlayerControllerAthena* PlayerControllerAthena) = decltype(SpawnPlayerFromAircraft)(0xBFDCC0 + uintptr_t(GetModuleHandle(0)));
			SpawnPlayerFromAircraft(GameModeAthena, PlayerControllerAthena);
#else
			GameModeAthena->SpawnDefaultPawnFor(PlayerControllerAthena, AthenaAircraft);
			PlayerControllerAthena->SetControlRotation(ClientRotation);
#endif
		}

		ServerAttemptAircraftJumpOG(PlayerControllerAthena, ClientRotation);
	}

	void ServerThankBusDriver(AFortPlayerControllerAthena* PlayerControllerAthena)
	{
		ServerThankBusDriverOG(PlayerControllerAthena);
	}

	void ServerPlaceMapCursor(AFortPlayerControllerAthena* PlayerControllerAthena, const FVector_NetQuantize& CursorPos)
	{
		ServerPlaceMapCursorOG(PlayerControllerAthena, CursorPos);
	}

	void ServerRemoveMapCursor(AFortPlayerControllerAthena* PlayerControllerAthena)
	{
		ServerRemoveMapCursorOG(PlayerControllerAthena);
	}

	void ServerPlaySquadQuickChatMessage(AFortPlayerControllerAthena* PlayerControllerAthena, const FAthenaQuickChatActiveEntry& ChatEntry, const FUniqueNetIdRepl& SenderID)
	{

	}

	/* ---------------------------------- AFortPlayerControllerZone ---------------------------------- */

	void ClientOnPawnDied(AFortPlayerControllerZone* PlayerControllerZone, const FFortPlayerDeathReport& DeathReport)
	{
		AFortPlayerPawnAthena* PlayerPawn = Cast<AFortPlayerPawnAthena>(PlayerControllerZone->MyFortPawn);
		AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerControllerZone->PlayerState);

		if (!PlayerPawn || !PlayerState)
			return;

		AFortPlayerStateAthena* KillerPlayerState = Cast<AFortPlayerStateAthena>(DeathReport.KillerPlayerState);
		AFortPlayerPawnAthena* KillerPawn = Cast<AFortPlayerPawnAthena>(DeathReport.KillerPawn);
		AActor* DamageCauser = DeathReport.DamageCauser;

		FGameplayTagContainer TagContainer = PlayerPawn ? *(FGameplayTagContainer*)(__int64(PlayerPawn) + 0x1188) : FGameplayTagContainer();

		float Distance = KillerPawn ? KillerPawn->GetDistanceTo(PlayerPawn) : 0;

		EDeathCause DeathCause = AFortPlayerStateAthena::ToDeathCause(TagContainer, PlayerPawn->bIsDBNO);

		FDeathInfo DeathInfo = FDeathInfo();
		DeathInfo.FinisherOrDowner = KillerPlayerState ? KillerPlayerState : PlayerState;
		DeathInfo.bDBNO = PlayerPawn->bIsDBNO;
		DeathInfo.DeathCause = DeathCause;
		DeathInfo.Distance = (DeathCause == EDeathCause::FallDamage) ? PlayerPawn->LastFallDistance : Distance;
		DeathInfo.DeathLocation = PlayerPawn->K2_GetActorLocation();
		DeathInfo.bInitialized = true;

		PlayerState->PawnDeathLocation = DeathInfo.DeathLocation;

		PlayerState->DeathInfo = DeathInfo;
		PlayerState->OnRep_DeathInfo();

		if (KillerPlayerState && PlayerState != KillerPlayerState)
		{
			KillerPlayerState->KillScore++;
			KillerPlayerState->OnRep_Kills();

			KillerPlayerState->ClientReportKill(PlayerState);

#ifdef SIPHON
			AFortPlayerControllerAthena* KillerPlayerController = Cast<AFortPlayerControllerAthena>(KillerPlayerState->Owner);

			if (KillerPlayerController)
				Functions::GiveSiphonBonus(KillerPlayerController, KillerPawn);
#endif // SIPHON
		}

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerControllerZone);
		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (PlayerControllerAthena && GameModeAthena && GameStateAthena)
		{
			FAthenaMatchTeamStats TeamStats = FAthenaMatchTeamStats();
			TeamStats.Place = GameStateAthena->PlayersLeft;
			TeamStats.TotalPlayers = GameStateAthena->TotalPlayers;

			PlayerControllerAthena->ClientSendTeamStatsForPlayer(TeamStats);

			UAthenaPlayerMatchReport* MatchReport = PlayerControllerAthena->MatchReport;

			if (MatchReport)
			{
				MatchReport->bHasMatchStats = true;
				MatchReport->bHasTeamStats = true;
				MatchReport->TeamStats = TeamStats;
				MatchReport->bHasRewards = true;
				MatchReport->EndOfMatchResults = FAthenaRewardResult();
			}

			AFortPlayerStateAthena* CorrectKillerPlayerState = (KillerPlayerState && KillerPlayerState == PlayerState) ? nullptr : KillerPlayerState;
			UFortWeaponItemDefinition* KillerWeaponItemDefinition = nullptr;

			if (DamageCauser)
			{
				AFortProjectileBase* ProjectileBase = Cast<AFortProjectileBase>(DamageCauser);
				AFortWeapon* Weapon = Cast<AFortWeapon>(DamageCauser);

				if (ProjectileBase)
				{
					AFortWeapon* ProjectileBaseWeapon = Cast<AFortWeapon>(ProjectileBase->Owner);

					if (ProjectileBaseWeapon)
						KillerWeaponItemDefinition = ProjectileBaseWeapon->WeaponData;
				}
				else if (Weapon)
					KillerWeaponItemDefinition = Weapon->WeaponData;
			}

			if (GameStateAthena->GamePhase < EAthenaGamePhase::EndGame)
			{
				GameModeAthena->RemoveFromAlivePlayers(PlayerControllerAthena, CorrectKillerPlayerState, KillerPawn, KillerWeaponItemDefinition, DeathCause);

				if (GameModeAthena->bAllowSpectateAfterDeath)
				{
					APawn* PlayerToSpectate = KillerPawn;

					if (!PlayerToSpectate || PlayerToSpectate == PlayerPawn)
					{
						TArray<AFortPlayerPawn*> FortPlayerPawns;
						UFortKismetLibrary::GetAllFortPlayerPawns(PlayerControllerAthena, &FortPlayerPawns);

						for (int32 i = 0; i < FortPlayerPawns.Num(); i++)
						{
							AFortPlayerPawn* FortPlayerPawn = FortPlayerPawns[i];
							if (!FortPlayerPawn) continue;

							if (PlayerPawn == FortPlayerPawn)
								continue;

							PlayerToSpectate = FortPlayerPawn;
							break;
						}
					}

					TArray<FFortSpectatorAthenaItem> SpectatorArray = PlayerState->Spectators.SpectatorArray;

					for (int32 i = 0; i < SpectatorArray.Num(); i++)
					{
						FFortSpectatorAthenaItem Spectator = SpectatorArray[i];
						AFortPlayerStateAthena* SpectatorPlayerState = Spectator.PlayerState;
						if (!SpectatorPlayerState) continue;

						AFortPlayerControllerAthena* SpectatorPlayerController = Cast<AFortPlayerControllerAthena>(SpectatorPlayerState->Owner);
						if (!SpectatorPlayerController) continue;

						if (PlayerToSpectate)
						{
							SpectatorPlayerController->PlayerToSpectateOnDeath = PlayerToSpectate;
							UKismetSystemLibrary::K2_SetTimer(SpectatorPlayerController, L"SpectateOnDeath", 3.0f, false);
						}
					}

					if (PlayerToSpectate && PlayerToSpectate != PlayerPawn)
					{
						PlayerControllerAthena->PlayerToSpectateOnDeath = PlayerToSpectate;
						UKismetSystemLibrary::K2_SetTimer(PlayerControllerAthena, L"SpectateOnDeath", 3.0f, false);
					}
				}
			}
		}

		ClientOnPawnDiedOG(PlayerControllerZone, DeathReport);
	}

	/* ------------------------------------ AFortPlayerController ------------------------------------ */

	/*
	 * ServerReadyToStartMatch prepares the player to start a match:
	 *
	 * - Checks if the player is not ready, then continues.
	 * - Clears abilities and grants a default ability set.
	 * - Equips the player with a pickaxe or default.
	 * - Sets up the player's inventory and enables cheats if enabled.
	 */
	void ServerReadyToStartMatch(AFortPlayerController* PlayerController)
	{
		if (!PlayerController->bReadyToStartMatch)
		{
			AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);
			if (!PlayerState) return;

			UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;
			
			if (AbilitySystemComponent)
			{
				AbilitySystemComponent->ClearAllAbilities();

				UFortGameData* GameData = Globals::GetGameData();
				UFortAbilitySet* GenericPlayerAbilitySet = GameData->GenericPlayerAbilitySet.Get();

				if (!GenericPlayerAbilitySet)
				{
					const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(GameData->GenericPlayerAbilitySet.ObjectID.AssetPathName);
					GenericPlayerAbilitySet = StaticLoadObject<UFortAbilitySet>(AssetPathName.CStr());
				}

				if (GenericPlayerAbilitySet)
				{
					Abilities::GrantGameplayAbility(GenericPlayerAbilitySet, AbilitySystemComponent);
					Abilities::GrantGameplayEffect(GenericPlayerAbilitySet, AbilitySystemComponent);
				}

				Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);
			}

			PlayerState->ApplyCharacterCustomization(PlayerController->MyFortPawn);

			AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);
			UFortWeaponMeleeItemDefinition* PickaxeItemDefinition = nullptr;

			if (PlayerControllerAthena)
			{
				UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = PlayerControllerAthena->CustomizationLoadout.Pickaxe;

				if (AthenaPickaxeItemDefinition)
					PickaxeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

				if (!PickaxeItemDefinition)
				{
					UFortGameData* GameData = Globals::GetGameData();
					UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = GameData->DefaultPickaxeSkin;

					if (DefaultPickaxeSkin)
						PickaxeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
				}
			}

			Inventory::SetupInventory(PlayerController, PickaxeItemDefinition);

			APlayerCameraManager* PlayerCameraManager = PlayerController->PlayerCameraManager;

			if (PlayerCameraManager)
			{
				PlayerCameraManager->ViewRollMin = 0.0f;
				PlayerCameraManager->ViewRollMax = 0.0f;
			}

#ifdef CHEATS
			if (!PlayerController->CheatManager)
				PlayerController->CheatManager = (UCheatManager*)UGameplayStatics::SpawnObject(UCheatManager::StaticClass(), PlayerController);
#endif // CHEATS

			ServerReadyToStartMatchOG(PlayerController);
			PlayerController->bReadyToStartMatch = true;
			return;
		}

		ServerReadyToStartMatchOG(PlayerController);
	}

	/*
	 * ServerCombineInventoryItems combines two items in the player's inventory if they are identical and respects stack size limitations:
	 *
	 * - Retrieves the target and source items from the player’s inventory using their GUIDs.
	 * - Verifies that both items exist and have valid, matching item definitions.
	 * - Checks if the target item can accommodate more of the source item based on the maximum stack size.
	 * - If the new count exceeds the maximum stack size, sets the target item count to the max stack size and updates the source item with the overflow count.
	 * - If there’s no overflow, removes the source item from the inventory.
	 * - Updates the inventory to reflect the new item counts for both the target and source items as needed.
	 */
	void ServerCombineInventoryItems(AFortPlayerController* PlayerController, const FGuid& TargetItemGuid, const FGuid& SourceItemGuid)
	{
		UFortWorldItem* TargetWorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(TargetItemGuid));
		UFortWorldItem* SourceWorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(SourceItemGuid));

		if (!TargetWorldItem || !SourceWorldItem)
			return;

		UFortWorldItemDefinition* TargetItemDefinition = Cast<UFortWorldItemDefinition>(TargetWorldItem->ItemEntry.ItemDefinition);
		UFortWorldItemDefinition* SourceItemDefinition = Cast<UFortWorldItemDefinition>(SourceWorldItem->ItemEntry.ItemDefinition);

		if (!TargetItemDefinition || !SourceItemDefinition)
			return;

		if (TargetItemDefinition == SourceItemDefinition && TargetWorldItem->ItemEntry.Count < TargetItemDefinition->MaxStackSize)
		{
			int32 NewTargetCount = TargetWorldItem->ItemEntry.Count + SourceWorldItem->ItemEntry.Count;

			if (NewTargetCount > TargetItemDefinition->MaxStackSize)
			{
				int32 NewSourceCount = NewTargetCount - TargetItemDefinition->MaxStackSize;

				Inventory::ModifyCountItem(PlayerController->WorldInventory, SourceWorldItem->ItemEntry.ItemGuid, NewSourceCount);

				NewTargetCount = TargetItemDefinition->MaxStackSize;
			}
			else
			{
				Inventory::RemoveItem(PlayerController->WorldInventory, SourceWorldItem->ItemEntry.ItemGuid);
			}

			Inventory::ModifyCountItem(PlayerController->WorldInventory, TargetWorldItem->ItemEntry.ItemGuid, NewTargetCount);
		}
	}

	/*
	 * ServerAttemptInventoryDrop handles dropping an item from the player's inventory in the game world.
	 *
	 * - Checks if the drop count is valid (greater than zero).
	 * - Verifies that the player pawn exists, and is not in an invalid state (like skydiving or in an aircraft).
	 * - Retrieves the item from the player's inventory using the provided GUID.
	 * - Checks if the item is droppable, based on item definition properties.
	 * - If the item count is zero and should not be retained, removes it from inventory and logs the action.
	 * - Determines a spawn location in front of the player, applying an offset above ground level.
	 * - Creates a pickup object in the world if enough item count exists; otherwise, reduces the item count accordingly.
	 * - Randomizes the pickup spawn rotation and distance for a natural drop effect.
	 * - Sets the appropriate drop behavior (e.g., drop as pickup, destroy on drop).
	 */
	void ServerAttemptInventoryDrop(AFortPlayerController* PlayerController, const FGuid& ItemGuid, int32 Count)
	{
		if (Count < 1)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

		if (!PlayerPawn || PlayerPawn->bIsSkydiving)
			return;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

		if (PlayerControllerAthena)
		{
			if (PlayerControllerAthena->IsInAircraft())
				return;
		}

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(ItemGuid));

		if (!WorldItem || Count < 1)
			return;

		UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(WorldItem->ItemEntry.ItemDefinition);

		if (!WorldItemDefinition || !WorldItemDefinition->bCanBeDropped)
			return;

		if (WorldItem->ItemEntry.Count <= 0)
		{
			UFortWeaponRangedItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponRangedItemDefinition>(WorldItemDefinition);

			if (WeaponRangedItemDefinition && WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty)
				return;

			FN_LOG(LogPlayerController, Warning, "[AFortPlayerController::ServerAttemptInventoryDrop] The item [%s] has a count of [%i] deletion of the item.", WorldItemDefinition->GetName().c_str(), WorldItem->ItemEntry.Count);

			PlayerController->RemoveInventoryItem(ItemGuid, Count, true);
			return;
		}

		if (PlayerController->RemoveInventoryItem(ItemGuid, Count, false))
		{
			const float LootSpawnLocationX = 0.0f;
			const float LootSpawnLocationY = 0.0f;
			const float LootSpawnLocationZ = 60.0f;

			const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation() +
				PlayerPawn->GetActorForwardVector() * LootSpawnLocationX +
				PlayerPawn->GetActorRightVector() * LootSpawnLocationY +
				PlayerPawn->GetActorUpVector() * LootSpawnLocationZ;

			AFortPickup* Pickup = nullptr;

			if (WorldItem->ItemEntry.Count == Count)
			{
				FFortItemEntry NewItemEntry;
				NewItemEntry.CopyItemEntryWithReset(&WorldItem->ItemEntry);

				Pickup = AFortPickup::CreatePickup(
					PlayerController->GetWorld(), 
					&NewItemEntry, 
					&SpawnLocation,
					nullptr,
					nullptr,
					nullptr,
					true,
					(uint32)EFortPickupSourceTypeFlag::Tossed);

				NewItemEntry.FreeItemEntry();
			}
			else if (WorldItem->ItemEntry.Count >= Count)
			{
				FFortItemEntry NewItemEntry;
				Inventory::MakeItemEntry(&NewItemEntry, WorldItemDefinition, Count, WorldItem->ItemEntry.Level, WorldItem->ItemEntry.LoadedAmmo, WorldItem->ItemEntry.Durability);

				Pickup = AFortPickup::CreatePickup(
					PlayerController->GetWorld(), 
					&NewItemEntry, 
					&SpawnLocation,
					nullptr,
					nullptr,
					nullptr,
					true,
					(uint32)EFortPickupSourceTypeFlag::Tossed);

				NewItemEntry.FreeItemEntry();
			}

			if (Pickup)
			{
				FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();
				PlayerRotation.Yaw += UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

				float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
				FVector FinalDirection = UKismetMathLibrary::GetForwardVector(PlayerRotation);

				FVector FinalLocation = SpawnLocation + FinalDirection * RandomDistance;

				Pickup->PawnWhoDroppedPickup = PlayerPawn;
				Pickup->bCombinePickupsWhenTossCompletes = true;
				Pickup->TossPickup(FinalLocation, PlayerPawn, 0, true);
			}

			EWorldItemDropBehavior DropBehavior = WorldItemDefinition->DropBehavior;

			switch (DropBehavior)
			{
			case EWorldItemDropBehavior::DropAsPickup:

				break;
			case EWorldItemDropBehavior::DestroyOnDrop:
				if (Pickup)
				{
					Pickup->ForceNetUpdate();
					Pickup->K2_DestroyActor();
				}
				break;
			case EWorldItemDropBehavior::DropAsPickupDestroyOnEmpty:

				break;
			default:
				break;
			}
		}
	}

	void ServerAttemptInteract(AFortPlayerController* PlayerController, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData)
	{
		if (!ReceivingActor)
			return;

		ABuildingItemCollectorActor* ItemCollectorActor = Cast<ABuildingItemCollectorActor>(ReceivingActor);

		if (ItemCollectorActor)
		{
			UFortWorldItemDefinition* ActiveInputItem = ItemCollectorActor->ActiveInputItem;
			if (!ActiveInputItem) return;

			const float LootSpawnLocationX = ItemCollectorActor->LootSpawnLocation.X;
			const float LootSpawnLocationY = ItemCollectorActor->LootSpawnLocation.Y;
			const float LootSpawnLocationZ = ItemCollectorActor->LootSpawnLocation.Z;

			const FVector& SpawnLocation = ItemCollectorActor->K2_GetActorLocation() +
				ItemCollectorActor->GetActorForwardVector() * LootSpawnLocationX +
				ItemCollectorActor->GetActorRightVector() * LootSpawnLocationY +
				ItemCollectorActor->GetActorUpVector() * LootSpawnLocationZ;

			for (int32 i = 0; i < ItemCollectorActor->ItemCollections.Num(); i++)
			{
				const FColletorUnitInfo& ItemCollection = ItemCollectorActor->ItemCollections[i];

				UFortWorldItemDefinition* InputItem = ItemCollection.InputItem;
				if (!InputItem) continue;

				if (InputItem != ActiveInputItem)
					continue;

				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ActiveInputItem, false));
				if (!WorldItem) continue;

				float InputCostXY = 0.0f;

				FString ContextString;
				EEvaluateCurveTableResult Result;
				UDataTableFunctionLibrary::EvaluateCurveTableRow(ItemCollection.InputCount.Curve.CurveTable, ItemCollection.InputCount.Curve.RowName, ItemCollectorActor->StartingGoalLevel, &Result, &InputCostXY, ContextString);

				int32 InputCost = (InputCostXY * ItemCollection.InputCount.Value);

				if (PlayerController->bBuildFree)
					InputCost = 0;

				if (InputCost > WorldItem->ItemEntry.Count)
					break;

				if (PlayerController->RemoveInventoryItem(WorldItem->ItemEntry.ItemGuid, InputCost))
				{
					TArray<FFortItemEntry> OutputItemEntry = ItemCollection.OutputItemEntry;

					for (auto& ItemEntry : OutputItemEntry)
					{
						UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry.ItemDefinition);
						if (!ItemDefinition) continue;

						FFortItemEntry NewItemEntry;
						Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, ItemEntry.Count, ItemEntry.Level, ItemEntry.LoadedAmmo, ItemEntry.Durability);

						AFortPickup* Pickup = AFortPickup::CreatePickup(
							PlayerController->GetWorld(), 
							&NewItemEntry, 
							&SpawnLocation,
							nullptr,
							nullptr,
							nullptr,
							true,
							(uint32)EFortPickupSourceTypeFlag::Tossed);

						if (Pickup)
						{
							FVector FinalLocation = SpawnLocation;

							Pickup->bCombinePickupsWhenTossCompletes = true;

							UKismetMathLibrary::RandomUnitVectorInConeInRadians(FinalLocation, ItemCollectorActor->LootTossConeHalfAngle);
							Pickup->TossPickup(FinalLocation, nullptr, 0, ItemCollectorActor->bTossOnGround);
						}

						NewItemEntry.FreeItemEntry();
					}
				}

				Functions::VendingMachinePlayVendFX(ItemCollectorActor);
				ItemCollectorActor->bCurrentInteractionSuccess = true;
				return;
			}

			Functions::VendingMachinePlayVendFailFX(ItemCollectorActor);
			ItemCollectorActor->bCurrentInteractionSuccess = false;
			return;
		}

		ServerAttemptInteractOG(PlayerController, ReceivingActor, InteractComponent, InteractType, OptionalObjectData);
	}

	/*
	 * Rewrite AFortPlayerController::CheckCreateBuildingActor (1.8)
	 *
	 * - https://imgur.com/UMJlcl7
	 * - I'm too lazy to continue but basically it checks if it's valid
	 */
	bool CheckCreateBuildingActor(AFortPlayerController* PlayerController, FBuildingClassData& BuildingClassData)
	{
		UClass* BuildingClass = BuildingClassData.BuildingClass.Get();

		if (!BuildingClass)
			return false;

		UObject* BuildingClassDefault = BuildingClass->CreateDefaultObject();

		if (!BuildingClassDefault->IsA(ABuildingActor::StaticClass()))
			return false;

		if (!Functions::IsPlayerBuildableClasse(BuildingClass))
			return false;

		ABuildingSMActor* BuildingSMActorClassDefault = Cast<ABuildingSMActor>(BuildingClassDefault);

		if (BuildingSMActorClassDefault)
		{
			if (!PlayerController->bBuildFree)
			{
				int32 NumAvailableBuildingResources = UFortKismetLibrary::K2_GetNumAvailableBuildingResources(PlayerController, BuildingSMActorClassDefault->ResourceType);
				int32 ResourceAmount = PlayerController->GetCreateResourceAmount(BuildingClassData);

				if (NumAvailableBuildingResources < ResourceAmount)
					return false;
			}
		}

		return true;
	}

	/*
	 * Rewrite AFortPlayerController::ServerCreateBuildingActor (1.8)
	 *
	 * - https://imgur.com/45hEb1e
	 */
	void ServerCreateBuildingActor(AFortPlayerController* PlayerController, FBuildingClassData BuildingClassData, const FVector_NetQuantize10& BuildLoc, const FRotator& BuildRot, bool bMirrored, float SyncKey)
	{
		if (!CheckCreateBuildingActor(PlayerController, BuildingClassData))
			return;

		UClass* BuildingClass = BuildingClassData.BuildingClass.Get();
		if (!BuildingClass) return;

		TArray<ABuildingActor*> ExistingBuildings;
		EFortStructuralGridQueryResults GridQueryResults = PlayerController->CanPlaceBuilableClassInStructuralGrid(BuildingClass, BuildLoc, BuildRot, bMirrored, &ExistingBuildings);

		if (GridQueryResults == EFortStructuralGridQueryResults::CanAdd)
		{
			for (int32 i = 0; i < ExistingBuildings.Num(); i++)
			{
				ABuildingActor* ExistingBuilding = ExistingBuildings[i];
				if (!ExistingBuilding) continue;

				ExistingBuilding->K2_DestroyActor();
			}

			ABuildingSMActor* BuildingSMActor = Util::SpawnActor<ABuildingSMActor>(BuildingClass, BuildLoc, BuildRot);
			if (!BuildingSMActor) return;

			BuildingSMActor->CurrentBuildingLevel = BuildingClassData.UpgradeLevel;

			// Fortnite does lots of other things, I don't know if it's useful?
			// https://imgur.com/a/tGBE1to

			PlayerController->PayBuildingCosts(BuildingClassData);

			BuildingSMActor->InitializeKismetSpawnedBuildingActor(BuildingSMActor, PlayerController, true);
			BuildingSMActor->bPlayerPlaced = true;

			AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (PlayerStateAthena)
			{
				BuildingSMActor->Team = PlayerStateAthena->TeamIndex;
				BuildingSMActor->OnRep_Team();
			}
		}

		if (ExistingBuildings.IsValid())
			ExistingBuildings.Free();
	}

	/*
	 * Rewrite AFortPlayerController::ServerRepairBuildingActor (1.8)
	 *
	 * - https://imgur.com/rbKqG3z
	 */
	void ServerRepairBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair)
	{
		if (!BuildingActorToRepair ||
			!BuildingActorToRepair->GetWorld())
			return;

		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

		if (PlayerStateAthena)
		{
			if (!Functions::IsOnSameTeam(PlayerStateAthena, BuildingActorToRepair))
				return;
		}

		if (!PlayerController->bBuildFree)
		{
			int32 NumAvailableBuildingResources = UFortKismetLibrary::K2_GetNumAvailableBuildingResources(PlayerController, BuildingActorToRepair->ResourceType);
			int32 ResourceAmount = BuildingActorToRepair->GetRepairResourceAmount(PlayerController);

			if (NumAvailableBuildingResources < ResourceAmount)
				return;
		}

		int32 RepairCosts = PlayerController->PayRepairCosts(BuildingActorToRepair);
		BuildingActorToRepair->RepairBuilding(PlayerController, RepairCosts);

		// Are there any more needs?
		// https://imgur.com/5uafv8n
	}

	/*
	 * Rewrite AFortPlayerController::ServerBeginEditingBuildingActor (1.8)
	 *
	 * - https://imgur.com/A4PdpVl
	 */
	void ServerBeginEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit)
	{
		if (!BuildingActorToEdit)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		if (BuildingActorToEdit->CheckBeginEditBuildingActor(PlayerController))
		{
			AFortPlayerStateZone* PlayerStateZone = Cast<AFortPlayerStateZone>(PlayerController->PlayerState);
			if (!PlayerStateZone) return;

			BuildingActorToEdit->SetEditingPlayer(PlayerStateZone);

			UFortGameData* GameData = Globals::GetGameData();
			UFortEditToolItemDefinition* EditToolItemDefinition = GameData->EditToolItem.Get();

			if (!EditToolItemDefinition)
			{
				const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(GameData->EditToolItem.ObjectID.AssetPathName);
				EditToolItemDefinition = StaticLoadObject<UFortEditToolItemDefinition>(AssetPathName.CStr());
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(EditToolItemDefinition, false));

			if (WorldItem && 
				EditToolItemDefinition && 
				EditToolItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController))
			{
				AFortWeap_EditingTool* EditingTool = Cast<AFortWeap_EditingTool>(PlayerPawn->CurrentWeapon);

				if (EditingTool)
					EditingTool->SetEditingActor(BuildingActorToEdit);
			}
		}
	}

	/*
	 * Rewrite AFortPlayerController::ServerEditBuildingActor (1.8)
	 *
	 * - https://imgur.com/NkmbdiW
	 */
	void ServerEditBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, int32 RotationIterations, bool bMirrored)
	{
		if (!BuildingActorToEdit ||
			!BuildingActorToEdit->GetWorld() ||
			BuildingActorToEdit->EditingPlayer != PlayerController->PlayerState ||
			BuildingActorToEdit->bDestroyed)
			return;

		// This security is not in the real function but it allows you not to replace everything with anything
		if (!Functions::IsPlayerBuildableClasse(NewBuildingClass.Get()))
			return;

		BuildingActorToEdit->SetEditingPlayer(nullptr);

		int32 CurrentBuildingLevel = BuildingActorToEdit->CurrentBuildingLevel;
		BuildingActorToEdit->ReplaceBuildingActor(NewBuildingClass, CurrentBuildingLevel, RotationIterations, bMirrored, PlayerController);

		// The rest of the code does stuff with quests and stats
		// And I'm too lazy to find the function on the 5.41
		// https://imgur.com/7cy0KKR
	}

	/*
	 * Rewrite AFortPlayerController::ServerEndEditingBuildingActor (1.8)
	 *
	 * - https://imgur.com/5J6ibST
	 */
	void ServerEndEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToStopEditing)
	{
		if (!BuildingActorToStopEditing)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		if (BuildingActorToStopEditing->EditingPlayer != PlayerController->PlayerState ||
			BuildingActorToStopEditing->bDestroyed)
			return;

		BuildingActorToStopEditing->SetEditingPlayer(nullptr);

		UFortGameData* GameData = Globals::GetGameData();
		UFortEditToolItemDefinition* EditToolItemDefinition = GameData->EditToolItem.Get();

		if (!EditToolItemDefinition)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(GameData->EditToolItem.ObjectID.AssetPathName);
			EditToolItemDefinition = StaticLoadObject<UFortEditToolItemDefinition>(AssetPathName.CStr());
		}

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(EditToolItemDefinition, false));

		if (WorldItem &&
			EditToolItemDefinition &&
			EditToolItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController))
		{
			AFortWeap_EditingTool* EditingTool = Cast<AFortWeap_EditingTool>(PlayerPawn->CurrentWeapon);

			if (EditingTool)
				EditingTool->SetEditingActor(nullptr);
		}
	}

	/*
	 * ServerDropAllItems drops all items from the player's inventory into the game world, excluding a specified item.
	 *
	 * - Retrieves the player's pawn and world inventory; exits if either is invalid.
	 * - Iterates through the player's inventory to identify items that:
	 *		- Are droppable based on their item definition.
	 *		- Do not match the specified item to ignore.
	 * - Adds each valid item to a list of items to drop.
	 * - Defines a base spawn location slightly above the player’s position.
	 * - For each item in the drop list:
	 *		- Randomizes the spawn rotation and distance for natural scattering.
	 *		- Creates a pickup object in the world and sets its final drop location.
	 *		- Removes the item from the player's inventory.
	 */
	void ServerDropAllItems(AFortPlayerController* PlayerController, const UFortItemDefinition* IgnoreItemDef)
	{
		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		AFortInventory* WorldInventory = PlayerController->WorldInventory;

		if (!PlayerPawn || !WorldInventory)
			return;

		TArray<UFortWorldItem*> WorldItemToDrops;

		for (int32 i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* WorldItem = PlayerController->WorldInventory->Inventory.ItemInstances[i];
			if (!WorldItem) continue;

			FFortItemEntry* ItemEntry = &WorldItem->ItemEntry;
			if (!ItemEntry) continue;

			UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry->ItemDefinition);
			if (!ItemDefinition) continue;

			if (!ItemDefinition->bCanBeDropped || ItemDefinition == IgnoreItemDef)
				continue;

			WorldItemToDrops.Add(WorldItem);
		}

		const float LootSpawnLocationX = 0.0f;
		const float LootSpawnLocationY = 0.0f;
		const float LootSpawnLocationZ = 70.0f;

		const FVector& SpawnLocation = PlayerPawn->K2_GetActorLocation() +
			PlayerPawn->GetActorForwardVector() * LootSpawnLocationX +
			PlayerPawn->GetActorRightVector() * LootSpawnLocationY +
			PlayerPawn->GetActorUpVector() * LootSpawnLocationZ;

		for (int32 i = 0; i < WorldItemToDrops.Num(); i++)
		{
			UFortWorldItem* WorldItemToDrop = WorldItemToDrops[i];
			if (!WorldItemToDrop) continue;

			FFortItemEntry* ItemEntry = &WorldItemToDrop->ItemEntry;
			if (!ItemEntry) continue;

			FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();
			PlayerRotation.Yaw += UKismetMathLibrary::RandomFloatInRange(-180.0f, 180.0f);

			float RandomDistance = UKismetMathLibrary::RandomFloatInRange(350.0f, 700.0f);
			FVector FinalDirection = UKismetMathLibrary::GetForwardVector(PlayerRotation);

			FVector FinalLocation = SpawnLocation + FinalDirection * RandomDistance;

			FFortItemEntry NewItemEntry;
			NewItemEntry.CopyItemEntryWithReset(ItemEntry);

			if (PlayerController->RemoveInventoryItem(ItemEntry->ItemGuid, ItemEntry->Count, true, true))
			{
				AFortPickup* Pickup = AFortPickup::CreatePickup(
					PlayerController->GetWorld(), 
					&NewItemEntry, 
					&SpawnLocation,
					nullptr,
					nullptr,
					nullptr,
					true,
					(uint32)EFortPickupSourceTypeFlag::Tossed);

				if (Pickup)
				{
					Pickup->PawnWhoDroppedPickup = PlayerPawn;
					Pickup->bCombinePickupsWhenTossCompletes = true;
					Pickup->TossPickup(FinalLocation, PlayerPawn, 0, true);
				}
			}

			NewItemEntry.FreeItemEntry();
		}

		if (WorldItemToDrops.IsValid())
			WorldItemToDrops.Free();
	}

	/*
	 * ServerExecuteInventoryItem execute a weapon:
	 *
	 * - Get Inventory Item with ItemGuid.
	 * - Equips the player with a WeaponItemDefinition.
	 */
	void ServerExecuteInventoryItem(AFortPlayerController* PlayerController, const FGuid& ItemGuid)
	{
		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(ItemGuid));
		if (!WorldItem) return;

		UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WorldItem->ItemEntry.ItemDefinition);
		if (!WeaponItemDefinition) return;

		UFortGadgetItemDefinition* GadgetItemDefinition = Cast<UFortGadgetItemDefinition>(WeaponItemDefinition);

		if (GadgetItemDefinition)
		{
			WeaponItemDefinition = GadgetItemDefinition->GetDecoItemDefinition();
		}

		UFortDecoItemDefinition* DecoItemDefinition = Cast<UFortDecoItemDefinition>(WeaponItemDefinition);

		if (DecoItemDefinition)
		{
			DecoItemDefinition->EquipDecoDefinition(WorldItem, PlayerController);

			UFortContextTrapItemDefinition* ContextTrapItemDefinition = Cast<UFortContextTrapItemDefinition>(DecoItemDefinition);

			if (ContextTrapItemDefinition)
			{
				ContextTrapItemDefinition->EquipContextTrapDefinition(WorldItem, PlayerController);
			}

			return;
		}

		WeaponItemDefinition->EquipWeaponDefinition(WorldItem, PlayerController);
	}

	/*
	 * Rewrite AFortPlayerController::ServerPlayEmoteItem (1.8)
	 *
	 * - https://imgur.com/JzoSf26 
	 * - https://imgur.com/300J2E9 // not done
	 * - https://imgur.com/Z03MrUD
	 */
	void ServerPlayEmoteItem(AFortPlayerController* PlayerController, UFortMontageItemDefinitionBase* EmoteAsset)
	{
		if (!EmoteAsset)
			return;

		AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
		if (!PlayerPawn) return;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerPawn->AbilitySystemComponent;
		if (!AbilitySystemComponent) return;

		UFortGameplayAbility* GameplayAbility = nullptr;

		if (EmoteAsset->IsA(UAthenaSprayItemDefinition::StaticClass()))
		{
			UFortGameData* GameData = Globals::GetGameData();
			UFortGameplayAbility* SprayGameplayAbility = Functions::LoadGameplayAbility(GameData->SprayGameplayAbility);
			GameplayAbility = SprayGameplayAbility;
		}
		else if (EmoteAsset->IsA(UAthenaToyItemDefinition::StaticClass()))
		{
			UAthenaToyItemDefinition* ToyItemDefinition = Cast<UAthenaToyItemDefinition>(EmoteAsset);

			if (ToyItemDefinition)
			{
				UFortGameplayAbility* ToySpawnAbility = Functions::LoadGameplayAbility(ToyItemDefinition->ToySpawnAbility);
				GameplayAbility = ToySpawnAbility;
			}
		}

		if (!GameplayAbility && EmoteAsset->IsA(UAthenaDanceItemDefinition::StaticClass()))
		{
			UFortGameData* GameData = Globals::GetGameData();
			UFortGameplayAbility* EmoteGameplayAbility = Functions::LoadGameplayAbility(GameData->EmoteGameplayAbility);
			GameplayAbility = EmoteGameplayAbility;
		}

		if (GameplayAbility)
		{
			UAthenaDanceItemDefinition* DanceItemDefinition = Cast<UAthenaDanceItemDefinition>(EmoteAsset);

			if (DanceItemDefinition)
			{
				PlayerPawn->bMovingEmote = DanceItemDefinition->bMovingEmote;
				PlayerPawn->EmoteWalkSpeed = DanceItemDefinition->WalkForwardSpeed;
			}

			FGameplayAbilitySpec AbilitySpec;
			AbilitySpec.CreateDefaultAbilitySpec(GameplayAbility, GameplayAbility->GetAbilityLevel(), -1, EmoteAsset);

			FGameplayAbilitySpecHandle Handle;
			AbilitySystemComponent->GiveAbilityAndActivateOnce(&Handle, AbilitySpec);
		}
	}

	void ServerSetInventoryStateValue(AFortPlayerController* PlayerController, const FGuid& ItemGuid, const FFortItemEntryStateValue& StateValue)
	{

	}

	void ServerRemoveInventoryStateValue(AFortPlayerController* PlayerController, const FGuid& ItemGuid, EFortItemEntryState StateValueType)
	{

	}

	void ServerReturnToMainMenu(AFortPlayerController* PlayerController)
	{
		if (PlayerController->Pawn)
			PlayerController->ServerSuicide();

		PlayerController->ClientTravel(L"/Game/Maps/Frontend", ETravelType::TRAVEL_Absolute, false, FGuid());
	}

	void ServerCheat(AFortPlayerController* PlayerController, const FString& Msg)
	{
		
	}

	/* -------------------------------------- PlayerController --------------------------------------- */

	/*
	 *	Reimplantation of void APlayerController::AcknowledgePossession(APawn* P)
	*/
	void ServerAcknowledgePossession(APlayerController* PlayerController, APawn* P)
	{
		if (!PlayerController || !P)
			return;

		if (PlayerController->AcknowledgedPawn == P)
			return;

		PlayerController->AcknowledgedPawn = P;
	}

	/*
	 *	Reimplantation of void APlayerController::ServerChangeName(APawn* P)
	 *	Call in void APlayerController::SetName(const FString& S)
	 *	Source Code: https://github.com/EpicGames/UnrealEngine/blob/4.21/Engine/Source/Runtime/Engine/Private/PlayerController.cpp#L1814
	*/
	void ServerChangeName(APlayerController* PlayerController, const FString& S)
	{
		ServerChangeNameOG(PlayerController, S);
	}

	/* --------------------------------------- InventoryOwner ---------------------------------------- */

	/*
	 * RemoveInventoryItem removes or adjusts the count of a specified item from the player's inventory.
	 *
	 * - Validates that the removal count is greater than zero.
	 * - Retrieves the player controller based on the inventory owner and confirms that the specified item exists in the inventory.
	 * - Checks if the removal count is equal to or exceeds the item's current count:
	 *		- If the item has a special attribute allowing it to persist when empty, sets its count to zero.
	 *		- Otherwise, fully removes the item from the inventory.
	 * - If the removal count is less than the item’s count, reduces the item’s count by the specified amount.
	 * - Returns true if the item was successfully removed or adjusted, otherwise false.
	 */
	bool RemoveInventoryItem(void* InventoryOwner, const FGuid& ItemGuid, int32 Count, bool bForceRemoveFromQuickBars, bool bForceRemoval)
	{
		if (Count == 0)
			return true;

		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return false;

		UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(ItemGuid));
		if (!WorldItem) return false;

		FFortItemEntry* ItemEntry = &WorldItem->ItemEntry;
		if (!ItemEntry) return false;

		if (Count == -1)
		{
			Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);
			return true;
		}

		if (Count >= ItemEntry->Count)
		{
			UFortWeaponRangedItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponRangedItemDefinition>(ItemEntry->ItemDefinition);

			if (WeaponRangedItemDefinition && WeaponRangedItemDefinition->bPersistInInventoryWhenFinalStackEmpty)
			{
				int32 ItemQuantity = UFortKismetLibrary::K2_GetItemQuantityOnPlayer(PlayerController, WeaponRangedItemDefinition);

				if (ItemQuantity == 1)
				{
					Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, 0);
					return true;
				}
			}

			Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);
		}
		else if (Count < ItemEntry->Count)
		{
			int32 NewCount = ItemEntry->Count - Count;

			Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, NewCount);
		}
		else
			return false;

		return true;
	}

	/*
	 * ModLoadedAmmo modifies the loaded ammo count for a specific item in the player’s inventory.
	 *
	 * - Retrieves the player controller based on the inventory owner and confirms that the inventory exists.
	 * - Iterates through the item instances in the inventory:
	 *		- When the specified item GUID is found, updates the loaded ammo count to the specified value.
	 * - Performs the same update for replicated inventory entries to ensure synchronization.
	 * - Marks the item as "dirty" (modified) to reflect the ammo count change in the replicated entries.
	 */
	void ModLoadedAmmo(void* InventoryOwner, const FGuid& ItemGuid, int32 Count)
	{
		AFortPlayerController* PlayerController = AFortPlayerController::GetPlayerControllerFromInventoryOwner(InventoryOwner);
		if (!PlayerController) return;

		AFortInventory* WorldInventory = PlayerController->WorldInventory;
		if (!WorldInventory) return;

		for (int32 i = 0; i < WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			UFortWorldItem* ItemInstance = WorldInventory->Inventory.ItemInstances[i];
			if (!ItemInstance) continue;

			FFortItemEntry* ItemEntry = &WorldInventory->Inventory.ItemInstances[i]->ItemEntry;

			if (ItemEntry->ItemGuid == ItemGuid)
			{
				ItemEntry->SetLoadedAmmo(Count);
				break;
			}
		}

		// I think that normally you don't need to modify the value here but for me it doesn't work idk
		for (int32 i = 0; i < WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry* ReplicatedItemEntry = &WorldInventory->Inventory.ReplicatedEntries[i];

			if (ReplicatedItemEntry->ItemGuid == ItemGuid)
			{
				ReplicatedItemEntry->LoadedAmmo = Count;
				WorldInventory->Inventory.MarkItemDirty(*ReplicatedItemEntry);
				break;
			}
		}
	}

	bool ModDurability(void* InventoryOwner, const FGuid& ItemGuid, float DurabilityMod, bool bForceSet)
	{
		return false;
	}

	/* ----------------------------------------------------------------------------------------------- */

	void InitPlayerController()
	{
		AFortPlayerControllerAthena* FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();

		/* --------------------------------- AFortPlayerControllerAthena --------------------------------- */

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1DF8 / 8, ServerAttemptAircraftJump, (LPVOID*)(&ServerAttemptAircraftJumpOG), "AFortPlayerControllerAthena::ServerAttemptAircraftJump");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1E88 / 8, ServerThankBusDriver, (LPVOID*)(&ServerThankBusDriverOG), "AFortPlayerControllerAthena::ServerThankBusDriver");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1DE8 / 8, ServerPlaceMapCursor, (LPVOID*)(&ServerPlaceMapCursorOG), "AFortPlayerControllerAthena::ServerPlaceMapCursor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1DD8 / 8, ServerRemoveMapCursor, (LPVOID*)(&ServerRemoveMapCursorOG), "AFortPlayerControllerAthena::ServerRemoveMapCursor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1EA0 / 8, ServerPlaySquadQuickChatMessage, nullptr, "AFortPlayerControllerAthena::ServerPlaySquadQuickChatMessage");

		/* ---------------------------------- AFortPlayerControllerZone ---------------------------------- */

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x14DCFF0), ClientOnPawnDied, (LPVOID*)(&ClientOnPawnDiedOG));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x14DCFF0));

		/* ------------------------------------ AFortPlayerController ------------------------------------ */

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1278 / 8, ServerReadyToStartMatch, (LPVOID*)(&ServerReadyToStartMatchOG), "AFortPlayerController::ServerReadyToStartMatch");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1030 / 8, ServerCombineInventoryItems, nullptr, "AFortPlayerController::ServerCombineInventoryItems");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1020 / 8, ServerAttemptInventoryDrop, nullptr, "AFortPlayerController::ServerAttemptInventoryDrop");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1208 / 8, ServerAttemptInteract, (LPVOID*)(&ServerAttemptInteractOG), "AFortPlayerController::ServerAttemptInteract");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1080 / 8, ServerCreateBuildingActor, nullptr, "AFortPlayerController::ServerCreateBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1060 / 8, ServerRepairBuildingActor, nullptr, "AFortPlayerController::ServerRepairBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x10B0 / 8, ServerBeginEditingBuildingActor, nullptr, "AFortPlayerController::ServerBeginEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1090 / 8, ServerEditBuildingActor, nullptr, "AFortPlayerController::ServerEditBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x10A0 / 8, ServerEndEditingBuildingActor, nullptr, "AFortPlayerController::ServerEndEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xD50 / 8, ServerDropAllItems, nullptr, "AFortPlayerController::ServerDropAllItems");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF90 / 8, ServerExecuteInventoryItem, nullptr, "AFortPlayerController::ServerExecuteInventoryItem");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xDB0 / 8, ServerPlayEmoteItem, nullptr, "AFortPlayerController::ServerPlayEmoteItem");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF40 / 8, ServerSetInventoryStateValue, nullptr, "AFortPlayerController::ServerSetInventoryStateValue");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xF30 / 8, ServerRemoveInventoryStateValue, nullptr, "AFortPlayerController::ServerRemoveInventoryStateValue");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x1258 / 8, ServerReturnToMainMenu, nullptr, "AFortPlayerController::ServerReturnToMainMenu");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0xDA0 / 8, ServerCheat, nullptr, "AFortPlayerController::ServerCheat");

		/* -------------------------------------- PlayerController --------------------------------------- */

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x828 / 8, ServerAcknowledgePossession, nullptr, "APlayerController::ServerAcknowledgePossession");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x808 / 8, ServerChangeName, (LPVOID*)(&ServerChangeNameOG), "APlayerController::ServerChangeName");

		/* --------------------------------------- InventoryOwner ---------------------------------------- */

		UObject* InventoryOwnerDefault = (UObject*)(__int64(FortPlayerControllerAthenaDefault) + InventoryOwnerOffset);

		MinHook::HookVTable(InventoryOwnerDefault, 0x14, RemoveInventoryItem, nullptr, "RemoveInventoryItem");
		MinHook::HookVTable(InventoryOwnerDefault, 0xC, ModDurability, nullptr, "ModDurability");
		MinHook::HookVTable(InventoryOwnerDefault, 0xD, ModLoadedAmmo, nullptr, "ModLoadedAmmo");

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}