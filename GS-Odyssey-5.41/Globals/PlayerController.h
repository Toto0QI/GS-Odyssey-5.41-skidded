#pragma once

namespace PlayerController
{
	ABuildingSMActor* (*ReplaceBuildingActor)(ABuildingSMActor* BuildingActor, int32 a2, TSubclassOf<ABuildingSMActor> BuildingClass, int32 BuildingLevel, int32 RotationIterations, bool bMirrored, AFortPlayerController* PlayerController);
	EFortStructuralGridQueryResults (*CanAddBuildingActorToGrid)(UObject* WorldContextObject, UClass* BuildingClass, const FVector& BuildLoc, const FRotator& BuildRot, bool bMirrored, TArray<ABuildingActor*>* ExistingBuildings);
	bool (*CheckBeginEditBuildingActor)(ABuildingSMActor* BuildingActorToEdit, AFortPlayerController* PlayerController);
	int32 (*GetRepairResourceAmount)(ABuildingSMActor* BuildingActorToRepair, AFortPlayerController* PlayerController);
	int32 (*GetCreateResourceAmount)(AFortPlayerController* PlayerController, const FBuildingClassData& BuildingClassData);
	int32 (*PayRepairCosts)(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair);
	int32 (*PayBuildingCosts)(AFortPlayerController* PlayerController, const FBuildingClassData& BuildingClassData);
	void (*ModifyLoadedAmmo)(void* a1, const FGuid& ItemGuid, int32 CorrectAmmo);
	EDeathCause (*ToDeathCause)(FGameplayTagContainer TagContainer, char bWasDBNOIg);
	bool (*EquipWeaponDefinition)(UFortWeaponItemDefinition* WeaponItemDefinition, UFortWorldItem* WorldItem, AFortPlayerController* PlayerController);
	bool (*EquipDecoDefinition)(UFortDecoItemDefinition* DecoItemDefinition, UFortWorldItem* WorldItem, AFortPlayerController* PlayerController);
	bool (*EquipContextTrapDefinition)(UFortContextTrapItemDefinition* ContextTrapItemDefinition, UFortWorldItem* WorldItem, AFortPlayerController* PlayerController);

	void ServerBeginEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit)
	{
		if (BuildingActorToEdit &&
			PlayerController->MyFortPawn &&
			CheckBeginEditBuildingActor(BuildingActorToEdit, PlayerController))
		{
			AFortPlayerStateZone* PlayerState = Cast<AFortPlayerStateZone>(PlayerController->PlayerState);

			if (PlayerState)
			{
				Functions::SetEditingPlayer(BuildingActorToEdit, PlayerState);

				UFortGameData* GameData = Globals::GetGameData();
				TSoftObjectPtr<UFortEditToolItemDefinition> EditToolItem = GameData->EditToolItem;
				UFortEditToolItemDefinition* EditToolItemDefinition = EditToolItem.Get();

				if (!EditToolItemDefinition)
				{
					std::string AssetPathName = EditToolItem.ObjectID.AssetPathName.ToString();
					EditToolItemDefinition = StaticLoadObject<UFortEditToolItemDefinition>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
				}

				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(EditToolItemDefinition, false));

				// 7FF66F5D3F40
				bool (*sub_7FF66F985640)(UFortWeaponItemDefinition* WeaponItemDefinition, UFortWorldItem* WorldItem, AFortPlayerController* PlayerController) = decltype(sub_7FF66F985640)(0xF83F40 + uintptr_t(GetModuleHandle(0)));

				if (WorldItem && EditToolItemDefinition && sub_7FF66F985640(EditToolItemDefinition, WorldItem, PlayerController))
				{
					AFortWeap_EditingTool* EditingTool = Cast<AFortWeap_EditingTool>(PlayerController->MyFortPawn->CurrentWeapon);

					if (EditingTool)
						Functions::SetEditingActor(EditingTool, BuildingActorToEdit);
				}
			}
		}
	}

	void ServerEditBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, int32 RotationIterations, bool bMirrored)
	{
		if (BuildingActorToEdit &&
			BuildingActorToEdit->EditingPlayer == PlayerController->PlayerState &&
			!BuildingActorToEdit->bDestroyed)
		{
			Functions::SetEditingPlayer(BuildingActorToEdit, nullptr);

			int32 CurrentBuildingLevel = BuildingActorToEdit->CurrentBuildingLevel;
			ReplaceBuildingActor(BuildingActorToEdit, 1, NewBuildingClass, CurrentBuildingLevel, RotationIterations, bMirrored, PlayerController);

			AFortGameMode* GameMode = Globals::GetGameMode();

			if (GameMode)
			{
				// 7FF61CAA91D0
				//void (*sub_7FF61CAA91D0)(AFortGameMode* GameMode, AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit) = decltype(sub_7FF61CAA91D0)(0xF83F40 + uintptr_t(GetModuleHandle(0)));
			}
		}
	}

	void ServerEndEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToStopEditing)
	{
		if (BuildingActorToStopEditing &&
			PlayerController->MyFortPawn &&
			BuildingActorToStopEditing->EditingPlayer == PlayerController->PlayerState &&
			!BuildingActorToStopEditing->bDestroyed)
		{
			Functions::SetEditingPlayer(BuildingActorToStopEditing, nullptr);

			UFortGameData* GameData = Globals::GetGameData();
			TSoftObjectPtr<UFortEditToolItemDefinition> EditToolItem = GameData->EditToolItem;
			UFortEditToolItemDefinition* EditToolItemDefinition = EditToolItem.Get();

			if (!EditToolItemDefinition)
			{
				std::string AssetPathName = EditToolItem.ObjectID.AssetPathName.ToString();
				EditToolItemDefinition = StaticLoadObject<UFortEditToolItemDefinition>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(EditToolItemDefinition, false));

			// 7FF66F5D3F40
			bool (*sub_7FF66F985640)(UFortWeaponItemDefinition * WeaponItemDefinition, UFortWorldItem* WorldItem, AFortPlayerController* PlayerController) = decltype(sub_7FF66F985640)(0xF83F40 + uintptr_t(GetModuleHandle(0)));

			if (WorldItem && EditToolItemDefinition && sub_7FF66F985640(EditToolItemDefinition, WorldItem, PlayerController))
			{
				AFortWeap_EditingTool* EditingTool = Cast<AFortWeap_EditingTool>(PlayerController->MyFortPawn->CurrentWeapon);

				if (EditingTool)
					Functions::SetEditingActor(EditingTool, nullptr);
			}
		}
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms, bool* bCallOG)
	{
		if (!Object || !Function)
			return;

		if (!Object->IsA(AFortPlayerController::StaticClass()))
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ServerReadyToStartMatch"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			UFortPlaylistAthena* Playlist = Globals::GetPlaylist();

			if (!PlayerController || !Playlist)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerReadyToStartMatch] Failed to get PlayerController/Playlist!");
				return;
			}

			AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;
			AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);

			if (Pawn && PlayerState)
			{
				// 7FF66EC68170
				void (*ClearAllAbilities)(UAbilitySystemComponent* AbilitySystemComponent) = decltype(ClearAllAbilities)(0x618170 + uintptr_t(GetModuleHandle(0)));
				ClearAllAbilities(PlayerState->AbilitySystemComponent);

				static UFortAbilitySet* DefaultAbilities = Globals::GetGameData()->GenericPlayerAbilitySet.Get();

#ifdef DEBUGS
				TArray<TSoftObjectPtr<UFortGameplayModifierItemDefinition>> ModifierList = Playlist->ModifierList;


#endif // DEBUGS

				Abilities::GrantGameplayAbility(DefaultAbilities, Pawn);
				Abilities::GrantGameplayEffect(DefaultAbilities, Pawn);
				GameMode::ApplyCharacterCustomization(PlayerState, Pawn);
			}

			FFortAthenaLoadout CustomizationLoadout = PlayerController->CustomizationLoadout;
			UAthenaPickaxeItemDefinition* Pickaxe = CustomizationLoadout.Pickaxe;

			UFortWeaponMeleeItemDefinition* PickaxeDefinition = nullptr;

			if (!Pickaxe || !Pickaxe->WeaponDefinition)
				PickaxeDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

			if (Pickaxe->WeaponDefinition)
				PickaxeDefinition = Pickaxe->WeaponDefinition;

			/*FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, PickaxeDefinition, 1, 0, 0, 0.f);

			Inventory::AddInventoryItem(PlayerController, ItemEntry);*/

			Inventory::SetupInventory(PlayerController, PickaxeDefinition);

#ifdef CHEATS
			if (!PlayerController->CheatManager)
				PlayerController->CheatManager = (UCheatManager*)UGameplayStatics::SpawnObject(UCheatManager::StaticClass(), PlayerController);

			// UFortCheatManager

#ifdef DEBUGS
			UCheatManager* CheatManager = PlayerController->CheatManager;

			if (CheatManager)
			{
				//CheatManager->ChangeSize(100.f);
			}
#endif // DEBUGS

#endif // CHEATS
		}
		else if (FunctionName.contains("ServerDropAllItems"))
		{
			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerDropAllItems] call!");
		}
		else if (FunctionName.contains("ServerModDurability"))
		{
			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerModDurability] call!");
		}
		else if (FunctionName.contains("ServerModifyStat"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerModifyStat*)Parms;

			/*FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerModifyStat] StatName: %s, Amount: %i, ModType: %i, bForceStatSave: %i",
				Params->StatName.ToString().c_str(), Params->Amount, Params->ModType, Params->bForceStatSave);*/

			// PlayerController->ModifyStat(Params->StatName, Params->Amount, Params->ModType, Params->bForceStatSave); // appelle ServerModifyStat
		}
		else if (FunctionName.contains("ServerRemoveInventoryItem"))
		{
			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerRemoveInventoryItem] call!");
		}
		else if (FunctionName.contains("ServerRemoveInventoryStateValue"))
		{
			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerRemoveInventoryStateValue] call!");
		}
		else if (FunctionName.contains("ServerSetInventoryStateValue"))
		{
			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerSetInventoryStateValue] call!");
		}
		else if (FunctionName.contains("ServerCombineInventoryItems"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerCombineInventoryItems*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCombineInventoryItems] Failed to get PlayerController!");
				return;
			}

			UFortWorldItem* TargetWorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->TargetItemGuid));
			UFortWorldItem* SourceWorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->SourceItemGuid));
			
			if (!TargetWorldItem || !SourceWorldItem)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCombineInventoryItems] Failed to get TargetWorldItem/SourceWorldItem!");
				return;
			}

			UFortWorldItemDefinition* TargetItemDefinition = Cast<UFortWorldItemDefinition>(TargetWorldItem->ItemEntry.ItemDefinition);
			UFortWorldItemDefinition* SourceItemDefinition = Cast<UFortWorldItemDefinition>(SourceWorldItem->ItemEntry.ItemDefinition);

			if (!TargetItemDefinition || !SourceItemDefinition)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCombineInventoryItems] Failed to get TargetItemDefinition/SourceItemDefinition!");
				return;
			}

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
		else if (FunctionName.contains("ServerItemWillBeDestroyed"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerItemWillBeDestroyed*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerItemWillBeDestroyed] Failed to get PlayerController!");
				return;
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->DestroyedItemGuid));

			if (!WorldItem)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerItemWillBeDestroyed] Failed to get WorldItem!");
				return;
			}

			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::ServerItemWillBeDestroyed] ItemDefinition: %s, Count: %i", WorldItem->ItemEntry.ItemDefinition->GetName().c_str(), Params->Count);
		}
		else if (FunctionName.contains("ServerAttemptAircraftJump")) // Rewrite
		{
			AFortPlayerControllerAthena* PlayerController = Cast<AFortPlayerControllerAthena>(Object);
			auto Params = (Params::FortPlayerControllerAthena_ServerAttemptAircraftJump*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get PlayerController!");
				return;
			}

			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get PlayerState!");
				return;
			}

			if (PlayerController->IsInAircraft() && !PlayerController->Pawn)
			{
				AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

				if (!GameState)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get GameState!");
					return;
				}

				// 7FF66F239300
				int32 (*GetAircraftIndex)(AFortGameStateAthena* GameState, AFortPlayerStateAthena* PlayerState) = decltype(GetAircraftIndex)(0xBE9300 + uintptr_t(GetModuleHandle(0)));
				int32 AircraftIndex = GetAircraftIndex(GameState, PlayerState);

				AFortAthenaAircraft* Aircraft = GameState->GetAircraft(AircraftIndex);

				if (!Aircraft)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get Aircraft!");
					return;
				}

				GameMode::SpawnDefaultPawnForHook(Globals::GetGameMode(), PlayerController, Aircraft);

				PlayerController->SetControlRotation(Params->ClientRotation);
			}
		}
		else if (FunctionName.contains("ServerExecuteInventoryItem")) // Rewrite
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerExecuteInventoryItem*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerExecuteInventoryItem] Failed to get PlayerController!");
				return;
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->ItemGuid));

			if (!WorldItem)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerExecuteInventoryItem] Failed to get WorldItem!");
				return;
			}

			UFortWeaponItemDefinition* WeaponItemDefinition = Cast<UFortWeaponItemDefinition>(WorldItem->ItemEntry.ItemDefinition);

			if (WeaponItemDefinition)
			{
				UFortDecoItemDefinition* DecoItemDefinition = Cast<UFortDecoItemDefinition>(WeaponItemDefinition);

				if (DecoItemDefinition)
				{
					UFortContextTrapItemDefinition* ContextTrapItemDefinition = Cast<UFortContextTrapItemDefinition>(DecoItemDefinition);

					if (ContextTrapItemDefinition)
					{
						EquipContextTrapDefinition(ContextTrapItemDefinition, WorldItem, PlayerController);
						return;
					}

					EquipDecoDefinition(DecoItemDefinition, WorldItem, PlayerController);
					return;
				}

				EquipWeaponDefinition(WeaponItemDefinition, WorldItem, PlayerController);
			}
		}
		else if (FunctionName.contains("ServerAttemptInventoryDrop")) // Rewrite
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerAttemptInventoryDrop*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInventoryDrop] Failed to get PlayerController!");
				return;
			}

			UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->ItemGuid));
			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

			if (WorldItem && PlayerPawn)
			{
				UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(WorldItem->ItemEntry.ItemDefinition);

				FVector SpawnLocation = PlayerPawn->K2_GetActorLocation();
				FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();

				SpawnLocation.Z += 40.0f;

				if (ItemDefinition && ItemDefinition->bCanBeDropped)
				{
					const FGuid& ItemGuid = WorldItem->ItemEntry.ItemGuid;

					if (WorldItem->ItemEntry.Count <= 0)
					{
						FN_LOG(LogPlayerController, Warning, "[AFortPlayerController::ServerAttemptInventoryDrop] The item [%s] has a count of [%i] deletion of the item.", ItemDefinition->GetName().c_str(), WorldItem->ItemEntry.Count);
						Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);
					}
					else if (WorldItem->ItemEntry.Count == Params->Count)
					{
						Inventory::RemoveItem(PlayerController->WorldInventory, ItemGuid);

						FFortItemEntry NewItemEntry;
						Inventory::CreateItemEntry(&NewItemEntry);
						Inventory::CopyItemEntry(&NewItemEntry, &WorldItem->ItemEntry);

						Inventory::SetStateValue(&NewItemEntry, EFortItemEntryState::FromDroppedPickup, 1);

						float RandomAngle = UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

						FRotator RandomRotation = PlayerRotation;
						RandomRotation.Yaw += RandomAngle;

						float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
						FVector Direction = UKismetMathLibrary::GetForwardVector(RandomRotation);

						FVector FinalLocation = SpawnLocation + Direction * RandomDistance;

						Inventory::SpawnPickup(PlayerPawn, NewItemEntry, SpawnLocation, FinalLocation, true);
						Inventory::FreeItemEntry(&NewItemEntry);
					}
					else if (WorldItem->ItemEntry.Count >= Params->Count)
					{
						int32 NewCount = WorldItem->ItemEntry.Count - Params->Count;

						Inventory::ModifyCountItem(PlayerController->WorldInventory, ItemGuid, NewCount);

						FFortItemEntry NewItemEntry;
						Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, Params->Count, WorldItem->ItemEntry.Level, WorldItem->ItemEntry.LoadedAmmo, WorldItem->ItemEntry.Durability);

						Inventory::SetStateValue(&NewItemEntry, EFortItemEntryState::FromDroppedPickup, 1);

						float RandomAngle = UKismetMathLibrary::RandomFloatInRange(-60.0f, 60.0f);

						FRotator RandomRotation = PlayerRotation;
						RandomRotation.Yaw += RandomAngle;

						float RandomDistance = UKismetMathLibrary::RandomFloatInRange(500.0f, 600.0f);
						FVector Direction = UKismetMathLibrary::GetForwardVector(RandomRotation);

						FVector FinalLocation = SpawnLocation + Direction * RandomDistance;

						Inventory::SpawnPickup(PlayerPawn, NewItemEntry, SpawnLocation, FinalLocation, true);
						Inventory::FreeItemEntry(&NewItemEntry);
					}
				}
			}
		}
		else if (FunctionName.contains("ServerAttemptInteract"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerAttemptInteract*)Parms;

			AActor* ReceivingActor = Params->ReceivingActor;

			if (!PlayerController || !ReceivingActor)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get PlayerController/ReceivingActor!");
				return;
			}

			AAthenaSupplyDrop_C* AthenaSupplyDrop = Cast<AAthenaSupplyDrop_C>(ReceivingActor);

			// Remake: Function'AthenaSupplyDrop_C:SpawnLoot'
			if (AthenaSupplyDrop)
			{
				FVector LootSpawnLocation;
				AthenaSupplyDrop->GetLootSpawnLocation(&LootSpawnLocation);

				int32 LootLevel = UFortKismetLibrary::GetLootLevel(AthenaSupplyDrop);

				TArray<FFortItemEntry> LootToDrops;
				bool bSuccess = UFortKismetLibrary::PickLootDrops(AthenaSupplyDrop, &LootToDrops, AthenaSupplyDrop->LootTableName, LootLevel, -1);

				if (!bSuccess)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed PickLootDrops!");
					return;
				}

				for (int32 i = 0; i < LootToDrops.Num(); i++)
				{
					FFortItemEntry LootToDrop = LootToDrops[i];
					UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);
					if (!WorldItemDefinition) continue;

					FVector LootSpawnDirection = LootSpawnLocation;
					AthenaSupplyDrop->SpawnPickup(WorldItemDefinition, LootToDrop.Count, nullptr, LootSpawnLocation, LootSpawnDirection);
				}
			}

			ABuildingItemCollectorActor* ItemCollectorActor = Cast<ABuildingItemCollectorActor>(ReceivingActor);

			if (ItemCollectorActor)
			{
				UFortWorldItemDefinition* ActiveInputItem = ItemCollectorActor->ActiveInputItem;

				if (!ActiveInputItem)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get ActiveInputItem!");
					return;
				}

				*bCallOG = false;

				FVector ItemCollectorLocation = ItemCollectorActor->K2_GetActorLocation();
				FVector ItemCollectorRightVector = ItemCollectorActor->GetActorRightVector() * 70.f;

				FVector SpawnLocation = ItemCollectorLocation + ItemCollectorRightVector;

				SpawnLocation.Z += 40;

				FRotator SpawnRotation = FRotator({ 0, 0, 0 });

				TArray<FColletorUnitInfo> ItemCollections = ItemCollectorActor->ItemCollections;

				for (int32 i = 0; i < ItemCollections.Num(); i++)
				{
					FColletorUnitInfo ItemCollection = ItemCollections[i];

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

#ifdef CHEATS
					if (PlayerController->bInfiniteAmmo)
						InputCost = 0;
#endif // CHEATS

					if (InputCost > WorldItem->ItemEntry.Count)
						break;

					if (Inventory::RemoveInventoryItem(PlayerController, WorldItem->ItemEntry.ItemGuid, InputCost))
					{
						TArray<FFortItemEntry> OutputItemEntry = ItemCollection.OutputItemEntry;

						for (auto& ItemEntry : OutputItemEntry)
						{
							UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry.ItemDefinition);
							if (!ItemDefinition) continue;

							FFortItemEntry NewItemEntry;
							Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, ItemEntry.Count, ItemEntry.Level, ItemEntry.LoadedAmmo, ItemEntry.Durability);

							FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
							CreatePickupData.World = Globals::GetWorld();
							CreatePickupData.ItemEntry = &NewItemEntry;
							CreatePickupData.SpawnLocation = &SpawnLocation;
							CreatePickupData.SpawnRotation = &SpawnRotation;
							CreatePickupData.PlayerController = nullptr;
							CreatePickupData.OverrideClass = nullptr;
							CreatePickupData.NullptrIdk = nullptr;
							CreatePickupData.bRandomRotation = true;
							CreatePickupData.PickupSourceTypeFlags = 0;

							AFortPickup* Pickup = Inventory::CreatePickupFromData(&CreatePickupData);

							if (Pickup)
							{
								FVector FinalLocation = SpawnLocation;
								Pickup->TossPickup(FinalLocation, nullptr, 0, true);
							}

							Inventory::FreeItemEntry(&NewItemEntry);
						}
					}

					Functions::VendingMachinePlayVendFX(ItemCollectorActor);
					ItemCollectorActor->bCurrentInteractionSuccess = true;
					return;
				}

				Functions::VendingMachinePlayVendFailFX(ItemCollectorActor);
				ItemCollectorActor->bCurrentInteractionSuccess = false;
			}

#ifdef DEBUGS
			ABuildingProp* BuildingProp = Cast<ABuildingProp>(ReceivingActor);

			if (BuildingProp)
			{
				static UClass* HiddenStarClass = StaticLoadObject<UClass>(L"/Game/Athena/Items/QuestInteractables/HiddenStars/Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C");

				if (HiddenStarClass)
				{
					if (true)
					{
						static UFunction* Func = nullptr;

						if (Func == nullptr)
							Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_HiddenStar_Parent_C", "ThisQuestObjectiveComplete");

						if (Func)
						{
							BuildingProp->ProcessEvent(Func, &PlayerController->MyFortPawn);

							FN_LOG(LogPlayerController, Debug, "HiddenStarClass - Func: %s", Func->GetName().c_str());
						}
						
					}

					FN_LOG(LogPlayerController, Debug, "HiddenStarClass - BuildingProp: %s", BuildingProp->GetName().c_str());
				}
			}
#endif // DEBUGS

			ReceivingActor->ForceNetUpdate();
		}
		else if (FunctionName.contains("ServerCreateBuildingActor")) // Rewrite
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerCreateBuildingActor*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			const FBuildingClassData& BuildingClassData = Params->BuildingClassData;

			const FVector& BuildLoc = Params->BuildLoc;
			const FRotator& BuildRot = Params->BuildRot;

			TSubclassOf<ABuildingSMActor> BuildingClass = BuildingClassData.BuildingClass;

			if (!Functions::IsPlayerBuildableClasse(BuildingClass.Get()))
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get BuildingClass or is not the player buildable classe!");
				return;
			}

			TArray<ABuildingActor*> ExistingBuildings;
			EFortStructuralGridQueryResults QueryResults = CanAddBuildingActorToGrid(PlayerController, BuildingClass, BuildLoc, BuildRot, Params->bMirrored, &ExistingBuildings);

			if (QueryResults == EFortStructuralGridQueryResults::CanAdd)
			{
				ABuildingSMActor* BuildingActor = Util::SpawnActor<ABuildingSMActor>(BuildingClass, BuildLoc, BuildRot);

				if (!BuildingActor)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to spawn BuildingActor!");
					return;
				}

				const float Distance = PlayerPawn->GetDistanceTo(BuildingActor);

				if (Distance > 1750)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Maximum distance is 1750, your distance is %.2f.", Distance);
					BuildingActor->SilentDie();
					return;
				}

#ifdef CHEATS
				if (!PlayerController->bBuildFree)
#endif // CHEATS
				{
					UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActor->ResourceType);
					UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ResourceItemDefinition, false));

					if (!WorldItem)
					{
						BuildingActor->SilentDie();
						return;
					}

					int32 ResourceAmount = GetCreateResourceAmount(PlayerController, BuildingClassData);

					if (ResourceAmount > WorldItem->ItemEntry.Count)
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to create BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, WorldItem->ItemEntry.Count);
						BuildingActor->SilentDie();
						return;
					}
				}

				for (int32 i = 0; i < ExistingBuildings.Num(); i++)
				{
					ABuildingActor* ExistingBuilding = ExistingBuildings[i];
					if (!ExistingBuilding) continue;

					ExistingBuilding->K2_DestroyActor();
				}

				BuildingActor->CurrentBuildingLevel = BuildingClassData.UpgradeLevel;

				// 7FF66F2E9640
				void (*IdkButItsCool)(ABuildingSMActor* BuildingActor, int a2, int32 WorldPlayerId) = decltype(IdkButItsCool)(0xC99640 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool(BuildingActor, 1, PlayerState->WorldPlayerId);

				// 7FF66F2F6670
				void (*IdkButItsCool2)(ABuildingSMActor* BuildingActor, bool a2) = decltype(IdkButItsCool2)(0xCA6670 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool2(BuildingActor, true);

				// 7FF66F494630
				void (*IdkButItsCool3)(AFortGameMode* GameMode, AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActor) = decltype(IdkButItsCool3)(0xE44630 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool3(Globals::GetGameMode(), PlayerController, BuildingActor);

				PayBuildingCosts(PlayerController, BuildingClassData);
				BuildingActor->InitializeKismetSpawnedBuildingActor(BuildingActor, PlayerController, true);

				BuildingActor->bPlayerPlaced = true;
				BuildingActor->Team = PlayerState->TeamIndex;

				if (ExistingBuildings.Num() > 0)
					ExistingBuildings.Free();
			}
		}
		else if (FunctionName.contains("ServerRepairBuildingActor")) // Rewrite
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerRepairBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToRepair = Params->BuildingActorToRepair;

			if (!PlayerController || !BuildingActorToRepair)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get PlayerController/BuildingActorToRepair!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			if (!Functions::IsOnSameTeam(PlayerState, BuildingActorToRepair))
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] PlayerController (team: [%i]) and BuildingActorToRepair (team [%i]) is not on the same team!",
					PlayerState->TeamIndex, BuildingActorToRepair->Team);

				return;
			}

			const float Distance = PlayerPawn->GetDistanceTo(BuildingActorToRepair);

			if (Distance > 1000)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Maximum distance is 1000, your distance is %.2f.", Distance);
				return;
			}

#ifdef CHEATS
			if (!PlayerController->bBuildFree)
#endif // CHEATS
			{
				UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActorToRepair->ResourceType);
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ResourceItemDefinition, false));

				if (!WorldItem)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get Resource Item Definition!");
					return;
				}

				int32 ResourceAmount = GetRepairResourceAmount(BuildingActorToRepair, PlayerController);

				if (ResourceAmount > WorldItem->ItemEntry.Count)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to repair BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, WorldItem->ItemEntry.Count);
					return;
				}
			}

			int32 ResourcesSpent = PayRepairCosts(PlayerController, BuildingActorToRepair);
			BuildingActorToRepair->RepairBuilding(PlayerController, ResourcesSpent);
		}
		/*else if (FunctionName.contains("ServerBeginEditingBuildingActor")) // Rewrite
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			auto Params = (Params::FortPlayerController_ServerBeginEditingBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToEdit = Params->BuildingActorToEdit;

			if (!PlayerController || !BuildingActorToEdit)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get PlayerController/BuildingActorToEdit!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			if (CheckBeginEditBuildingActor(BuildingActorToEdit, PlayerController))
			{
				if (!Functions::IsOnSameTeam(PlayerState, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				float Distance = PlayerPawn->GetDistanceTo(BuildingActorToEdit);

				if (Distance > 1000)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Maximum distance is 1000, your distance is %.2f.", Distance);
					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = Globals::GetGameData()->EditToolItem.Get();

				if (!EditToolDefinition)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get EditToolDefinition!");
					return;
				}

				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(EditToolDefinition, false));

				if (!WorldItem)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get WorldItem!");
					return;
				}

				AFortWeap_EditingTool* EditTool = Cast<AFortWeap_EditingTool>(PlayerPawn->EquipWeaponDefinition(EditToolDefinition, WorldItem->ItemEntry.ItemGuid));

				if (!EditTool)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get EditTool!");
					return;
				}

				Functions::SetEditingPlayer(BuildingActorToEdit, PlayerState);
				Functions::SetEditingActor(EditTool, BuildingActorToEdit);
			}
		}
		else if (FunctionName.contains("ServerEditBuildingActor")) // Rewrite
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerEditBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToEdit = Params->BuildingActorToEdit;

			if (!PlayerController || !BuildingActorToEdit)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get PlayerController/BuildingActorToEdit!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			if (PlayerState == BuildingActorToEdit->EditingPlayer && !BuildingActorToEdit->bDestroyed)
			{
				if (!Functions::IsPlayerBuildableClasse(Params->NewBuildingClass.Get()))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get BuildingClass or is not the player buildable classe!");
					return;
				}

				if (!PlayerPawn->CurrentWeapon || !PlayerPawn->CurrentWeapon->IsA(AFortWeap_EditingTool::StaticClass()))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get CurrentWeapon or is not the Editing Tool!");
					return;
				}

				ABuildingSMActor* BuildingActor = ReplaceBuildingActor(BuildingActorToEdit, 1, Params->NewBuildingClass, BuildingActorToEdit->CurrentBuildingLevel, Params->RotationIterations, Params->bMirrored, PlayerController);

				if (BuildingActor)
				{
					Functions::SetEditingPlayer(BuildingActorToEdit, nullptr);

					BuildingActor->bPlayerPlaced = true;
					BuildingActor->Team = PlayerState->TeamIndex;
				}
			}
		}
		else if (FunctionName.contains("ServerEndEditingBuildingActor")) // Rewrite
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerEndEditingBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToStopEditing = Params->BuildingActorToStopEditing;

			if (!PlayerController || !BuildingActorToStopEditing)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get PlayerController/BuildingActorToStopEditing!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			if (PlayerState == BuildingActorToStopEditing->EditingPlayer && !BuildingActorToStopEditing->bDestroyed)
			{
				static UFortEditToolItemDefinition* EditToolDefinition = Globals::GetGameData()->EditToolItem.Get();

				if (!EditToolDefinition)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get EditToolDefinition!");
					return;
				}

				AFortWeap_EditingTool* EditTool = Cast<AFortWeap_EditingTool>(PlayerPawn->CurrentWeapon);

				if (!EditTool)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get EditTool!");
					return;
				}

				Functions::SetEditingPlayer(BuildingActorToStopEditing, nullptr);
				Functions::SetEditingActor(EditTool, nullptr);
			}
		}*/
		else if (FunctionName.contains("ClientOnPawnDied"))
		{
			AFortPlayerControllerZone* PlayerControllerZone = Cast<AFortPlayerControllerZone>(Object);
			auto Params = (Params::FortPlayerControllerZone_ClientOnPawnDied*)Parms;

			if (!PlayerControllerZone)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerZone::ClientOnPawnDied] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawnAthena* PlayerPawn = Cast<AFortPlayerPawnAthena>(PlayerControllerZone->MyFortPawn);
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerControllerZone->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerZone::ClientOnPawnDied] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			const FFortPlayerDeathReport& DeathReport = Params->DeathReport;

			AFortPlayerStateAthena* KillerPlayerState = Cast<AFortPlayerStateAthena>(DeathReport.KillerPlayerState);
			AFortPlayerPawnAthena* KillerPawn = Cast<AFortPlayerPawnAthena>(DeathReport.KillerPawn);
			AActor* DamageCauser = DeathReport.DamageCauser;

			FGameplayTagContainer TagContainer = PlayerPawn ? *(FGameplayTagContainer*)(__int64(PlayerPawn) + 0x1188) : FGameplayTagContainer();

			float Distance = KillerPawn ? KillerPawn->GetDistanceTo(PlayerPawn) : 0;

			EDeathCause DeathCause = ToDeathCause(TagContainer, PlayerPawn->bIsDBNO);

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
				KillerPlayerState->ClientReportKill(PlayerState);
				KillerPlayerState->OnRep_Kills();

#ifdef SIPHON
				AFortPlayerControllerAthena* KillerPlayerController = Cast<AFortPlayerControllerAthena>(KillerPlayerState->Owner);

				if (KillerPlayerController)
				{
					UFortKismetLibrary::K2_GiveBuildingResource(KillerPlayerController, EFortResourceType::Wood, 50);
					UFortKismetLibrary::K2_GiveBuildingResource(KillerPlayerController, EFortResourceType::Stone, 50);
					UFortKismetLibrary::K2_GiveBuildingResource(KillerPlayerController, EFortResourceType::Metal, 50);

					float MaxHealth = KillerPawn->GetMaxHealth();
					float MaxShield = KillerPawn->GetMaxShield();

					float Health = KillerPawn->GetHealth();
					float Shield = KillerPawn->GetShield();

					float SiphonAmount = 50.0f;
					float RemainingSiphonAmount = SiphonAmount;

					if (Health < MaxHealth)
					{
						float NewHealth = UKismetMathLibrary::Clamp(Health + SiphonAmount, 0.0f, MaxHealth);

						KillerPawn->SetHealth(NewHealth);

						RemainingSiphonAmount -= (NewHealth - Health);
					}

					if (RemainingSiphonAmount > 0.0f)
					{
						float NewShield = UKismetMathLibrary::Clamp(Shield + RemainingSiphonAmount, 0.0f, MaxShield);

						void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
						SetShield(KillerPawn, NewShield);
					}
				}
#endif // SIPHON
			}

			AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerControllerZone);
			AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(Globals::GetGameMode());
			AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

			if (PlayerControllerAthena && GameMode && GameState)
			{
				FAthenaMatchTeamStats TeamStats = FAthenaMatchTeamStats();
				TeamStats.Place = GameState->PlayersLeft;
				TeamStats.TotalPlayers = GameState->TotalPlayers;

				PlayerControllerAthena->ClientSendTeamStatsForPlayer(TeamStats);

				FAthenaRewardResult RewardResult = FAthenaRewardResult();
				RewardResult.LevelsGained = 999;
				RewardResult.BookLevelsGained = 999;
				RewardResult.TotalSeasonXpGained = 999;
				RewardResult.TotalBookXpGained = 999;
				RewardResult.PrePenaltySeasonXpGained = 999;
				RewardResult.XpMultipliers = {};
				RewardResult.Rewards = {};
				RewardResult.AntiAddictionMultiplier = 0.0f;

				PlayerControllerAthena->ClientSendEndBattleRoyaleMatchForPlayer(true, RewardResult);

				UAthenaPlayerMatchReport* MatchReport = PlayerControllerAthena->MatchReport;

				if (MatchReport)
				{
					MatchReport->bHasMatchStats = true;
					MatchReport->bHasTeamStats = true;
					MatchReport->TeamStats = TeamStats;
					MatchReport->bHasRewards = true;
					MatchReport->EndOfMatchResults = RewardResult;
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

				if (GameState->GamePhase < EAthenaGamePhase::EndGame)
				{
					GameMode::RemoveFromAlivePlayers(GameMode, PlayerControllerAthena, CorrectKillerPlayerState, KillerPawn, KillerWeaponItemDefinition, DeathCause, 0);

					if (GameMode->bAllowSpectateAfterDeath)
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
								UKismetSystemLibrary::K2_SetTimer(SpectatorPlayerController, L"SpectateOnDeath", 5.0f, false);
							}
						}

						if (PlayerToSpectate && PlayerToSpectate != PlayerPawn)
						{
							PlayerControllerAthena->PlayerToSpectateOnDeath = PlayerToSpectate;
							UKismetSystemLibrary::K2_SetTimer(PlayerControllerAthena, L"SpectateOnDeath", 5.0f, false);
						}
					}
				}
			}
		}
		else if (FunctionName.contains("ServerPlayEmoteItem"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_ServerPlayEmoteItem*)Parms;

			UFortMontageItemDefinitionBase* EmoteAsset = Params->EmoteAsset;

			if (!PlayerController || !EmoteAsset)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerPlayEmoteItem] Failed to get PlayerController/EmoteAsset!");
				return;
			}

			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

			if (!PlayerPawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerPlayEmoteItem] Failed to get PlayerPawn/PlayerState!");
				return;
			}

			UGameplayAbility* GameplayAbility = nullptr;

			UAthenaToyItemDefinition* ToyItemDefinition = Cast<UAthenaToyItemDefinition>(EmoteAsset);
			UAthenaSprayItemDefinition* SprayItemDefinition = Cast<UAthenaSprayItemDefinition>(EmoteAsset);

			if (ToyItemDefinition)
			{
				UClass* ToySpawnAbility = ToyItemDefinition->ToySpawnAbility.Get();

				if (!ToySpawnAbility)
				{
					FN_LOG(LogPlayerController, Log, "if (!ToySpawnAbility)");

					std::string AssetPathName = ToyItemDefinition->ToySpawnAbility.ObjectID.AssetPathName.ToString();
					std::string SubPathString = ToyItemDefinition->ToySpawnAbility.ObjectID.SubPathString.ToString();

					std::string ObjectName = "BlueprintGeneratedClass " + AssetPathName;

					ToySpawnAbility = StaticLoadObject<UBlueprintGeneratedClass>(L"/Game/Abilities/Toys/Golf/Shared/GAB_Toy_GolfSwing.GAB_Toy_GolfSwing_C"); // UObject::FindObject<UBlueprintGeneratedClass>("BlueprintGeneratedClass GAB_Toy_GolfSwing.GAB_Toy_GolfSwing_C");

					FN_LOG(LogPlayerController, Log, "AssetPathName: [%s]", AssetPathName.c_str());
					FN_LOG(LogPlayerController, Log, "SubPathString: [%s]", SubPathString.c_str());

					/*
						OdysseyLog: LogPlayerController: Info: AssetPathName: [GAB_Toy_GolfSwing.GAB_Toy_GolfSwing_C]
						OdysseyLog: LogPlayerController: Info: SubPathString: []
						OdysseyLog: LogPlayerController: Info: ToyItemDefinition: TOY_005_GolfballElite
						OdysseyLog: LogPlayerController: Info: Object: Default__GAB_Toy_GolfSwing_C
						OdysseyLog: LogPlayerController: Info: ToySpawnAbility: BlueprintGeneratedClass GAB_Toy_GolfSwing.GAB_Toy_GolfSwing_C
						OdysseyLog: LogPlayerController: Info: CastFlags: 0
						OdysseyLog: LogPlayerController: Info: Flags: 2621489
						OdysseyLog: LogPlayerController: Info: DanceItemDefinition: TOY_005_GolfballElite
						OdysseyLog: LogPlayerController: Info: Step 1
						OdysseyLog: LogPlayerController: Info: Step 2
						OdysseyLog: LogPlayerController: Info: Step 3
					*/

					// ToySpawnAbility = StaticLoadObject<UClass>(std::wstring(AssetPathName.begin(), AssetPathName.end()).c_str());
				}

				FN_LOG(LogPlayerController, Log, "ToyItemDefinition: %s", ToyItemDefinition->GetName().c_str());

				// TOY_005_GolfballElite

				if (ToySpawnAbility)
				{
					UObject* Object = ToySpawnAbility->DefaultObject;

					FN_LOG(LogPlayerController, Log, "Object: %s", Object->GetName().c_str());
					FN_LOG(LogPlayerController, Log, "ToySpawnAbility: %s", ToySpawnAbility->GetFullName().c_str());
					FN_LOG(LogPlayerController, Log, "CastFlags: %i", ToySpawnAbility->CastFlags);
					FN_LOG(LogPlayerController, Log, "Flags: %i", Object->Flags);

					GameplayAbility = Cast<UGameplayAbility>(ToySpawnAbility->DefaultObject);
				}
			}
			else if (SprayItemDefinition)
			{
				GameplayAbility = UGAB_Spray_Generic_C::GetDefaultObj();
			}
			else
			{
				GameplayAbility = UGAB_Emote_Generic_C::GetDefaultObj();
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
				Abilities::CreateDefaultAbilitySpec(&AbilitySpec, GameplayAbility, 0, -1, EmoteAsset);

				FGameplayAbilitySpecHandle Handle;
				Abilities::GiveAbilityAndActivateOnce(PlayerState->AbilitySystemComponent, &Handle, AbilitySpec);
			}
		}
		else if (FunctionName.contains("ServerPlaySquadQuickChatMessage"))
		{
			AFortPlayerControllerAthena* PlayerController = Cast<AFortPlayerControllerAthena>(Object);
			auto Params = (Params::FortPlayerControllerAthena_ServerPlaySquadQuickChatMessage*)Parms;

			static UAthenaEmojiItemDefinition* EmojiComm = FindObjectFast<UAthenaEmojiItemDefinition>("/Game/Athena/Items/Cosmetics/Dances/Emoji/Emoji_Comm.Emoji_Comm");

			if (PlayerController && EmojiComm)
			{
				FN_LOG(LogPlayerController, Debug, "[AFortPlayerController::ServerPlayEmoteItem] EmojiComm: %s, Index: %i", EmojiComm->GetName().c_str(), EmojiComm->Index);

				PlayerController->ServerPlayEmoteItem(EmojiComm);
			}
		}
		else if (FunctionName.contains("SpawnToyInstance"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortPlayerController_SpawnToyInstance*)Parms;

			FN_LOG(LogPlayerController, Log, "[AFortPlayerController::SpawnToyInstance] - called!");
		}
		else if (FunctionName.contains("NotifyAbilityToSpawnToy"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);
			auto Params = (Params::FortToyAbilityInterface_NotifyAbilityToSpawnToy*)Parms;

			FN_LOG(LogPlayerController, Log, "[IFortToyAbilityInterface::NotifyAbilityToSpawnToy] - called!");
		}
		else if (FunctionName.contains("ServerAcknowledgePossession"))
		{
			APlayerController* PlayerController = (APlayerController*)Object;
			auto Params = (Params::PlayerController_ServerAcknowledgePossession*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[APlayerController::ServerAcknowledgePossession] Failed to get PlayerController!");
				return;
			}

			if (!Params->P)
			{
				FN_LOG(LogPlayerController, Error, "[APlayerController::ServerAcknowledgePossession] Failed to get Pawn!");
				return;
			}

			PlayerController->AcknowledgedPawn = Params->P;
		}
		else if (FunctionName.contains("ServerReturnToMainMenu"))
		{
			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Object);

			if (PlayerController)
			{
				if (PlayerController->Pawn)
					PlayerController->ServerSuicide();

				PlayerController->ClientTravel(L"/Game/Maps/Frontend", ETravelType::TRAVEL_Absolute, false, FGuid());
			}
		}
	}

	bool RemoveInventoryItemHook(void* a1, const FGuid& ItemGuid, int32 AmountToRemove, bool bForceRemoveFromQuickBars, bool bForceRemoval)
	{
		AFortPlayerController* PlayerController = (AFortPlayerController*)(__int64(a1) - IdkOffset);

		if (!PlayerController)
		{
			FN_LOG(LogPlayerController, Error, "[AFortPlayerController::RemoveInventoryItem] Failed to get PlayerController!");
			return false;
		}

#ifdef CHEATS
		if (PlayerController->bInfiniteAmmo)
		{
			PlayerController->WorldInventory->HandleInventoryLocalUpdate();
			return true;
		}
#endif // CHEATS


#ifdef DEBUGS
		//int TestEgal3 = (int)(__int64(a1) - 0x568);

		//FN_LOG(LogPlayerController, Log, "[AFortPlayerController::RemoveInventoryItem] TestEgal3: %i", TestEgal3);
#endif // DEBUGS

		return Inventory::RemoveInventoryItem(PlayerController, ItemGuid, AmountToRemove);
	}

	// Call in 7FF66F979AF0
	void ModifyLoadedAmmoHook(void* a1, const FGuid& ItemGuid, int32 CorrectAmmo)
	{
		AFortPlayerController* PlayerController = (AFortPlayerController*)(__int64(a1) - IdkOffset);

		if (!PlayerController)
		{
			FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ModifyLoadedAmmo] Failed to get PlayerController!");
			return;
		}

		Inventory::ModifyLoadedAmmoItem(PlayerController->WorldInventory, ItemGuid, CorrectAmmo);

		ModifyLoadedAmmo(a1, ItemGuid, CorrectAmmo);
	}

	void (*OnEnterAircraft)(AFortPlayerControllerAthena* PlayerController, AFortAthenaAircraft* AthenaAircraft);
	void OnEnterAircraftHook(AFortPlayerControllerAthena* PlayerController, AFortAthenaAircraft* AthenaAircraft)
	{
		if (!PlayerController)
		{
			FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::OnEnterAircraft] Failed to get PlayerController!");
			return;
		}

		if (PlayerController->WorldInventory)
			Inventory::ResetInventory(PlayerController->WorldInventory);

		OnEnterAircraft(PlayerController, AthenaAircraft);
	}

	void InitPlayerController()
	{
		static auto FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();

		auto IdkDefault = (void*)(__int64(FortPlayerControllerAthenaDefault) + IdkOffset);

		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x216, ServerBeginEditingBuildingActor, nullptr, "AFortPlayerController::ServerBeginEditingBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x212, ServerEditBuildingActor, nullptr, "AFortPlayerController::ServerEditBuildingActor");
		MinHook::HookVTable(FortPlayerControllerAthenaDefault, 0x214, ServerEndEditingBuildingActor, nullptr, "AFortPlayerController::ServerEndEditingBuildingActor");

		uintptr_t AddressRemoveInventoryItem = MinHook::FindPattern(Patterns::RemoveInventoryItem);
		uintptr_t AddressModifyLoadedAmmo = MinHook::FindPattern(Patterns::ModifyLoadedAmmo);
		uintptr_t AddressOnEnterAircraft = MinHook::FindPattern(Patterns::OnEnterAircraft);

		MH_CreateHook((LPVOID)(AddressRemoveInventoryItem), RemoveInventoryItemHook, nullptr);
		MH_EnableHook((LPVOID)(AddressRemoveInventoryItem));
		MH_CreateHook((LPVOID)(AddressModifyLoadedAmmo), ModifyLoadedAmmoHook, (LPVOID*)(&ModifyLoadedAmmo));
		MH_EnableHook((LPVOID)(AddressModifyLoadedAmmo));
		MH_CreateHook((LPVOID)(AddressOnEnterAircraft), OnEnterAircraftHook, (LPVOID*)(&OnEnterAircraft));
		MH_EnableHook((LPVOID)(AddressOnEnterAircraft));

		uintptr_t AddressGetRepairResourceAmount = MinHook::FindPattern(Patterns::GetRepairResourceAmount);
		uintptr_t AddressGetCreateResourceAmount = MinHook::FindPattern(Patterns::GetCreateResourceAmount);
		uintptr_t AddressPayRepairCosts = MinHook::FindPattern(Patterns::PayRepairCosts);
		uintptr_t AddressPayBuildingCosts = MinHook::FindPattern(Patterns::PayBuildingCosts);
		uintptr_t AddressCanAddBuildingActorToGrid = MinHook::FindPattern(Patterns::CanAddBuildingActorToGrid);
		uintptr_t AddressCheckBeginEditBuildingActor = MinHook::FindPattern(Patterns::CheckBeginEditBuildingActor);
		uintptr_t AddressReplaceBuildingActor = MinHook::FindPattern(Patterns::ReplaceBuildingActor);
		uintptr_t AddressToDeathCause = MinHook::FindPattern(Patterns::ToDeathCause);
		uintptr_t AddressEquipWeaponDefinition = MinHook::FindPattern(Patterns::EquipWeaponDefinition);
		uintptr_t AddressEquipDecoDefinition = MinHook::FindPattern(Patterns::EquipDecoDefinition);
		uintptr_t AddressEquipContextTrapDefinition = MinHook::FindPattern(Patterns::EquipContextTrapDefinition);

		GetRepairResourceAmount = decltype(GetRepairResourceAmount)(AddressGetRepairResourceAmount);
		GetCreateResourceAmount = decltype(GetCreateResourceAmount)(AddressGetCreateResourceAmount);
		PayRepairCosts = decltype(PayRepairCosts)(AddressPayRepairCosts);
		PayBuildingCosts = decltype(PayBuildingCosts)(AddressPayBuildingCosts);
		CanAddBuildingActorToGrid = decltype(CanAddBuildingActorToGrid)(AddressCanAddBuildingActorToGrid);
		CheckBeginEditBuildingActor = decltype(CheckBeginEditBuildingActor)(AddressCheckBeginEditBuildingActor);
		ReplaceBuildingActor = decltype(ReplaceBuildingActor)(AddressReplaceBuildingActor);
		ToDeathCause = decltype(ToDeathCause)(AddressToDeathCause);
		EquipWeaponDefinition = decltype(EquipWeaponDefinition)(AddressEquipWeaponDefinition);
		EquipDecoDefinition = decltype(EquipDecoDefinition)(AddressEquipDecoDefinition);
		EquipContextTrapDefinition = decltype(EquipContextTrapDefinition)(AddressEquipContextTrapDefinition);

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}