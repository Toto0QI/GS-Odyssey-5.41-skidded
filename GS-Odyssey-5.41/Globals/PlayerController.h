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

	void ServerBeginEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit)
	{
		if (BuildingActorToEdit &&
			PlayerController->MyFortPawn &&
			CheckBeginEditBuildingActor(BuildingActorToEdit, PlayerController))
		{
			AFortPlayerStateZone* PlayerState = (AFortPlayerStateZone*)PlayerController->PlayerState;

			if (PlayerState)
			{
				Functions::SetEditingPlayer(BuildingActorToEdit, PlayerState);

				TSoftObjectPtr<UFortEditToolItemDefinition> EditToolItem = Globals::GetGameData()->EditToolItem;

				UFortEditToolItemDefinition* EditTool = EditToolItem.Get();

				if (!EditTool)
				{
					std::string ItemPath = EditToolItem.ObjectID.SubPathString.ToString();
					EditTool = StaticLoadObject<UFortEditToolItemDefinition>(std::wstring(ItemPath.begin(), ItemPath.end()).c_str());
				}

				//__int64 Outer = sub_7FF61CD35B30(Idk, EditTool, 0);
				if (/*Outer &&*/ EditTool /*&& sub_7FF61CE48920(EditTool, Outer, PlayerController)*/)
				{
					AFortWeapon* CurrentWeapon = PlayerController->MyFortPawn->CurrentWeapon;

					if (CurrentWeapon && CurrentWeapon->IsA(AFortWeap_EditingTool::StaticClass()))
					{
						AFortWeap_EditingTool* EditingTool = (AFortWeap_EditingTool*)CurrentWeapon;

						Functions::SetEditingActor(EditingTool, BuildingActorToEdit);
					}
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

			// sub_7FF61C89CE20(PlayerController, "Edit", BuildingActorToEdit, 0);

			AFortGameMode* GameMode = Globals::GetGameMode();

			if (GameMode)
			{
				//sub_7FF61CAA91E0(GameMode, 4u, PlayerController, BuildingActorToEdit);
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

			TSoftObjectPtr<UFortEditToolItemDefinition> EditToolItem = Globals::GetGameData()->EditToolItem;

			UFortEditToolItemDefinition* EditTool = EditToolItem.Get();

			if (!EditTool)
			{
				std::string ItemPath = EditToolItem.ObjectID.SubPathString.ToString();
				EditTool = StaticLoadObject<UFortEditToolItemDefinition>(std::wstring(ItemPath.begin(), ItemPath.end()).c_str());
			}

			//__int64 v6 = sub_7FF61CD35B30(Idk, EditTool, nullptr);

			if (/*v6 &&*/ EditTool /*&& sub_7FF61CE48920(EditTool, v6, PlayerController)*/)
			{
				AFortWeapon* CurrentWeapon = PlayerController->MyFortPawn->CurrentWeapon;

				if (CurrentWeapon && CurrentWeapon->IsA(AFortWeap_EditingTool::StaticClass()))
				{
					AFortWeap_EditingTool* EditingTool = (AFortWeap_EditingTool*)CurrentWeapon;

					Functions::SetEditingActor(EditingTool, nullptr);
				}
			}
		}
	}



	void SelfCompletedUpdatedQuest(UFortQuestManager* QuestManager, AFortPlayerController* QuestOwner, const UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange)
	{
		if (QuestDef)
		{
			UFortQuestItem* QuestWithDefinition = QuestManager->GetQuestWithDefinition(QuestDef);

			if (QuestWithDefinition)
			{
				if (QuestOwner && QuestOwner->IsA(AFortPlayerControllerAthena::StaticClass()))
				{
					uint64_t v47 = ((uint64_t)DeltaChange << 32) | (uint32_t)CompletionCount;
					uint64_t v46 = reinterpret_cast<uint64_t>(QuestDef);
					v46 |= static_cast<uint64_t>(BackendName.ComparisonIndex) << 32;

					uint64_t v45[2];
					v45[1] = v47;
					v45[0] = v46;

					// sub_7FF6B9D4B650(reinterpret_cast<int64_t*>(QuestOwner), v45);
				}
			}
		}
	}

	int32 GetAircraftIndex(AFortGameStateAthena* GameState, AFortPlayerStateAthena* PlayerState)
	{
		int32 result; // rax
		__int64 v10; // [rsp+40h] [rbp+8h] BYREF

		if (!GameState->CurrentPlaylistData || GameState->AirCraftBehavior != EAirCraftBehavior::OpposingAirCraftForEachTeam)
			return 0;

		if (!Cast<AFortPlayerStateAthena>(PlayerState))
		{
			FN_LOG(LogGameState, Error, "AFortGameStateAthena::GetAircraftIndex called with an invalid PlayerState.");
			return 0;
		}

		auto IdkPlayerState = (void*)(__int64(PlayerState) + 0x3F0);

		int32 (*IdkFunc)(void* IdkPlayerState, __int64* OutIdk, __int64* Idk) = decltype(IdkFunc)(((UObject*)IdkPlayerState)->VTable[0x5]);

		__int64* (*IdkFunc2)(UFortPlaylistAthena* CurrentPlaylistData) = decltype(IdkFunc2)(GameState->CurrentPlaylistData->VTable[0xE]);

		result = IdkFunc(IdkPlayerState, &v10, IdkFunc2(GameState->CurrentPlaylistData));

		/*result = *(unsigned __int8*)(*(__int64(__fastcall**)(__int64, __int64*))(*(__int64*)(PlayerState + 0x3F0) + 40i64))(
			__int64(PlayerState) + 0x3F0,
			&v10)
			- (unsigned int)*(unsigned __int8*)(GameState->CurrentPlaylistData + 112i64);*/

		if ((EAthenaGamePhase)((int)GameState->GamePhase - 1) <= EAthenaGamePhase::Setup)
		{
			if (result >= 0)
				return result;

			return 0;
		}

		if (result < 0 || result >= GameState->Aircrafts.Num())
			return 0;

		return result;
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
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

			if (Pawn && PlayerController->PlayerState)
			{
				static UFortAbilitySet* DefaultAbilities = FindObjectFast<UFortAbilitySet>("/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_DefaultPlayer.GAS_DefaultPlayer");

#ifdef DEBUGS
				TArray<TSoftObjectPtr<UFortGameplayModifierItemDefinition>> ModifierList = Playlist->ModifierList;


#endif // DEBUGS

				Abilities::GrantGameplayAbility(DefaultAbilities, Pawn);
				Abilities::GrantGameplayEffect(DefaultAbilities, Pawn);
				GameMode::ApplyCharacterCustomization((AFortPlayerState*)Pawn->PlayerState, Pawn);
			}

			FFortAthenaLoadout CustomizationLoadout = PlayerController->CustomizationLoadout;
			UAthenaPickaxeItemDefinition* Pickaxe = CustomizationLoadout.Pickaxe;

			UFortWeaponMeleeItemDefinition* PickaxeDefinition = nullptr;

			if (!Pickaxe || !Pickaxe->WeaponDefinition)
				PickaxeDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

			if (Pickaxe->WeaponDefinition)
				PickaxeDefinition = Pickaxe->WeaponDefinition;

			// Setup Inventory
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
		else if (FunctionName.contains("ServerAttemptAircraftJump"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			auto Params = (Params::FortPlayerControllerAthena_ServerAttemptAircraftJump*)Parms;

			if (!PlayerController || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get PlayerController!");
				return;
			}

			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (PlayerController->IsInAircraft() && !PlayerController->Pawn)
			{
				AFortGameModeAthena* GameMode = Globals::GetGameMode();
				AFortGameStateAthena* GameState = Globals::GetGameState();

				if (!GameMode || !GameState)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get GameMode/GameState!");
					return;
				}

				if (GameState->MapInfo)
				{
					AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

					for (int32 i = 0; i < MapInfo->FlightInfos.Num(); i++)
					{
						FAircraftFlightInfo FlightInfo = MapInfo->FlightInfos[i];

						FVector_NetQuantize100 FlightStartLocation = FlightInfo.FlightStartLocation;
						FRotator FlightStartRotation = FlightInfo.FlightStartRotation;
						float FlightSpeed = FlightInfo.FlightSpeed;
						float TimeTillFlightEnd = FlightInfo.TimeTillFlightEnd;
						float TimeTillDropStart = FlightInfo.TimeTillDropStart;
						float TimeTillDropEnd = FlightInfo.TimeTillDropEnd;

						FN_LOG(LogPlayerController, Debug, "FlightStartLocation: [X: %.2f, Y: %.2f, Z: %.2f]", FlightStartLocation.X, FlightStartLocation.Y, FlightStartLocation.Z);
						FN_LOG(LogPlayerController, Debug, "FlightStartRotation: [Pitch: %.2f, Yaw: %.2f, Roll: %.2f]", FlightStartRotation.Pitch, FlightStartRotation.Yaw, FlightStartRotation.Roll);
						FN_LOG(LogPlayerController, Debug, "FlightSpeed: [%.2f]", FlightSpeed);
						FN_LOG(LogPlayerController, Debug, "TimeTillFlightEnd: [%.2f]", TimeTillFlightEnd);
						FN_LOG(LogPlayerController, Debug, "TimeTillDropStart: [%.2f]", TimeTillDropStart);
						FN_LOG(LogPlayerController, Debug, "TimeTillDropEnd: [%.2f]", TimeTillDropEnd);
					}
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

				const FVector& AircraftLocation = Aircraft->K2_GetActorLocation();

				Util::SpawnPlayer(PlayerController, AircraftLocation, FRotator(), false);

				PlayerController->SetControlRotation(Params->ClientRotation);
			}
		}
		else if (FunctionName.contains("ServerExecuteInventoryItem"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerExecuteInventoryItem*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerExecuteInventoryItem] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

			if (!Pawn)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerExecuteInventoryItem] Failed to get Pawn!");
				return;
			}

			UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, Params->ItemGuid);

			if (!ItemInstance)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerExecuteInventoryItem] Failed to get ItemInstance!");
				return;
			}

			UFortWeaponItemDefinition* ItemDefinition = (UFortWeaponItemDefinition*)ItemInstance->GetItemDefinitionBP();

			if (ItemDefinition)
			{
				if (ItemDefinition->IsA(UFortDecoItemDefinition::StaticClass()))
				{
					UFortDecoItemDefinition* DecoItemDefinition = (UFortDecoItemDefinition*)ItemDefinition;

					Pawn->PickUpActor(nullptr, DecoItemDefinition);
					Pawn->CurrentWeapon->ItemEntryGuid = ItemInstance->GetItemGuid();

					if (Pawn->CurrentWeapon->IsA(AFortDecoTool_ContextTrap::StaticClass()))
					{
						AFortDecoTool_ContextTrap* CurrentContextTrap = (AFortDecoTool_ContextTrap*)Pawn->CurrentWeapon;

						CurrentContextTrap->ContextTrapItemDefinition = (UFortContextTrapItemDefinition*)DecoItemDefinition;
					}

					return;
				}

				Pawn->EquipWeaponDefinition(ItemDefinition, ItemInstance->GetItemGuid());
			} 
		}
		else if (FunctionName.contains("ServerAttemptInventoryDrop"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerAttemptInventoryDrop*)Parms;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInventoryDrop] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

			if (!Pawn)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInventoryDrop] Failed to get Pawn");
				return;
			}

			UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, Params->ItemGuid);

			if (!ItemInstance)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerSpawnInventoryDrop] Failed to get ItemInstance!");
				return;
			}

			UFortWorldItemDefinition* ItemDefinition = (UFortWorldItemDefinition*)ItemInstance->GetItemDefinitionBP();
			FFortItemEntry ItemEntry = ItemInstance->ItemEntry;

			if (ItemDefinition && ItemDefinition->bCanBeDropped)
			{
				const FGuid& ItemGuid = ItemInstance->GetItemGuid();

				if (ItemEntry.Count <= 0)
				{
					Inventory::RemoveItemFromInventory(PlayerController, ItemGuid);

					FN_LOG(LogPlayerController, Warning, "[AFortPlayerController::ServerSpawnInventoryDrop] The item [%s] has a count of [%i] deletion of the item.", ItemDefinition->GetName().c_str(), ItemEntry.Count);
				}
				else if (ItemEntry.Count == Params->Count)
				{
					Inventory::SpawnPickup(Pawn, &ItemEntry, Pawn->K2_GetActorLocation(), true, true, ItemInstance->ItemEntry.ItemGuid);
					Inventory::RemoveItemFromInventory(PlayerController, ItemGuid);
				}
				else if (Params->Count < ItemEntry.Count)
				{
					int NewCount = ItemEntry.Count - Params->Count;

					if (NewCount > 0)
					{
						Inventory::ModifyCountItem(PlayerController, ItemGuid, NewCount);

						FFortItemEntry NewItemEntry;
						Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, Params->Count, ItemEntry.Level, ItemEntry.LoadedAmmo, ItemEntry.Durability);
						Inventory::SpawnPickup(Pawn, &NewItemEntry, Pawn->K2_GetActorLocation(), true);
					}
					else
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerSpawnInventoryDrop] The item [%s] has an invalid new count [%i].", ItemDefinition->GetName().c_str(), NewCount);
						return;
					}
				}

				Inventory::UpdateInventory(PlayerController->WorldInventory);
			}
		}
		else if (FunctionName.contains("ServerAttemptInteract"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerAttemptInteract*)Parms;

			ABuildingContainer* ReceivingActor = (ABuildingContainer*)Params->ReceivingActor;

			if (!PlayerController || !ReceivingActor)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get PlayerController/ReceivingActor!");
				return;
			}

			if (ReceivingActor->HasAuthority())
			{
				if (ReceivingActor->IsA(AFortAthenaSupplyDrop::StaticClass()))
				{
					static UClass* AthenaSupplyDropClass = FindObjectFast<UClass>("/Game/Athena/SupplyDrops/AthenaSupplyDrop.AthenaSupplyDrop_C");

					FName SearchLootTierGroup;
					
					if (ReceivingActor->IsA(AthenaSupplyDropClass))
					{
						SearchLootTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaSupplyDrop");
					}

					if (SearchLootTierGroup.IsValid())
					{
						bool bSuccess;
						std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(SearchLootTierGroup, -1, &bSuccess);

						if (!bSuccess)
						{
							FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get LootToDrops!");
							return;
						}

						for (auto& LootToDrop : LootToDrops)
							Inventory::SpawnPickup(nullptr, &LootToDrop, ReceivingActor->K2_GetActorLocation(), true);
					}
				}
				else if (ReceivingActor->IsA(ABuildingItemCollectorActor::StaticClass()))
				{
					ABuildingItemCollectorActor* BuildingItemCollector = (ABuildingItemCollectorActor*)ReceivingActor;
					UFortWorldItemDefinition* ActiveInputItem = BuildingItemCollector->ActiveInputItem;

					if (!ActiveInputItem)
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get ActiveInputItem!");
						return;
					}

					FVector ItemCollectorLocation = BuildingItemCollector->K2_GetActorLocation();
					FVector ItemCollectorRightVector = BuildingItemCollector->GetActorRightVector() * 70.f;

					FVector LootToDropLocation = ItemCollectorLocation + ItemCollectorRightVector;

					LootToDropLocation.Z += 40;

					FString ContextString;
					EEvaluateCurveTableResult Result;

					TArray<FColletorUnitInfo> ItemCollections = BuildingItemCollector->ItemCollections;

					for (int32 i = 0; i < ItemCollections.Num(); i++)
					{
						FColletorUnitInfo ItemCollection = ItemCollections[i];

						UFortWorldItemDefinition* InputItem = ItemCollection.InputItem;
						if (!InputItem) continue;

						if (InputItem != ActiveInputItem)
							continue;

						UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, InputItem);
						if (!ItemInstance) continue;

						FScalableFloat InputCount = ItemCollection.InputCount;

						float InputCostXY;
						UDataTableFunctionLibrary::EvaluateCurveTableRow(InputCount.Curve.CurveTable, InputCount.Curve.RowName, BuildingItemCollector->StartingGoalLevel, &Result, &InputCostXY, ContextString);

						int32 InputCost = (InputCostXY * InputCount.Value);

#ifdef CHEATS
						if (PlayerController->bInfiniteAmmo)
							InputCost = 0;
#endif // CHEATS

						if (InputCost > ItemInstance->GetNumInStack())
						{
							FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] the price of %s is %i while it only has %i",
								InputItem->GetDisplayName(false).ToString().c_str(), InputCost, ItemInstance->GetNumInStack());

							break;
						}

						if (Inventory::RemoveInventoryItem(PlayerController, ItemInstance->GetItemGuid(), InputCost))
						{
							TArray<FFortItemEntry> OutputItemEntry = ItemCollection.OutputItemEntry;

							for (auto& ItemEntry : OutputItemEntry)
							{
								UFortWorldItemDefinition* ItemDefinition = (UFortWorldItemDefinition*)ItemEntry.ItemDefinition;
								if (!ItemDefinition) continue;

								FFortItemEntry NewItemEntry;
								Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, ItemEntry.Count, ItemEntry.Level, ItemEntry.LoadedAmmo, ItemEntry.Durability);

								Inventory::SpawnPickup(nullptr, &NewItemEntry, LootToDropLocation, true);
							}

							Inventory::UpdateInventory(PlayerController->WorldInventory);
							BuildingItemCollector->bCurrentInteractionSuccess = true;
						}

						break;
					}
				}
#ifdef DEBUGS
				else if (ReceivingActor->IsA(ABuildingProp::StaticClass()))
				{
					ABuildingProp* BuildingProp = (ABuildingProp*)ReceivingActor;

					static UClass* JigsawClass = StaticLoadObject<UClass>(L"/Game/Athena/Items/QuestInteractables/Llama_Puzzle/Prop_QuestInteractable_Jigsaw_Parent.Prop_QuestInteractable_Jigsaw_Parent_C");
					static UClass* HiddenStarClass = StaticLoadObject<UClass>(L"/Game/Athena/Items/QuestInteractables/HiddenStars/Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C");

					/*
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.UserConstructionScript
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Bob and Spin__FinishedFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Bob and Spin__UpdateFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Reveal__FinishedFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Reveal__UpdateFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Disappear__FinishedFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Disappear__UpdateFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Fade Out__FinishedFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Fade Out__UpdateFunc
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.QuestInitializedAndValid
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Star Reveal
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.ThisQuestObjectiveComplete
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.DeactivateHiddenStar
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.ReceiveBeginPlay
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.Star Hide
						Function Prop_QuestInteractable_HiddenStar_Parent.Prop_QuestInteractable_HiddenStar_Parent_C.ExecuteUbergraph_Prop_QuestInteractable_HiddenStar_Parent
					*/

					if (BuildingProp->IsA(JigsawClass))
					{
						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_Jigsaw_Parent_C", "StartRattle");

							BuildingProp->ProcessEvent(Func, nullptr);

							FN_LOG(LogPlayerController, Debug, "JigsawClass - Func: %s", Func->GetName().c_str());
						}

						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_Jigsaw_Parent_C", "Set Letter at Beginning");

							BuildingProp->ProcessEvent(Func, nullptr);

							FN_LOG(LogPlayerController, Debug, "JigsawClass - Func: %s", Func->GetName().c_str());
						}

						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_Jigsaw_Parent_C", "QuestUpdatedFromAnywhere");

							BuildingProp->ProcessEvent(Func, nullptr);

							FN_LOG(LogPlayerController, Debug, "JigsawClass - Func: %s", Func->GetName().c_str());
						}

						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_Jigsaw_Parent_C", "ThisQuestObjectiveComplete");

							BuildingProp->ProcessEvent(Func, &PlayerController->MyFortPawn);

							FN_LOG(LogPlayerController, Debug, "JigsawClass - Func: %s", Func->GetName().c_str());
						}

						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_Jigsaw_Parent_C", "PieceRattle");

							BuildingProp->ProcessEvent(Func, nullptr);

							FN_LOG(LogPlayerController, Debug, "JigsawClass - Func: %s", Func->GetName().c_str());
						}

						FN_LOG(LogPlayerController, Debug, "JigsawClass - BuildingProp: %s", BuildingProp->GetName().c_str());
					}
					else if (BuildingProp->IsA(HiddenStarClass))
					{
						if (true)
						{
							static UFunction* Func = nullptr;

							if (Func == nullptr)
								Func = BuildingProp->Class->GetFunction("Prop_QuestInteractable_HiddenStar_Parent_C", "ThisQuestObjectiveComplete");

							BuildingProp->ProcessEvent(Func, &PlayerController->MyFortPawn);

							FN_LOG(LogPlayerController, Debug, "HiddenStarClass - Func: %s", Func->GetName().c_str());
						}
	
						FN_LOG(LogPlayerController, Debug, "HiddenStarClass - BuildingProp: %s", BuildingProp->GetName().c_str());
					}

					for (UStruct* Clss = BuildingProp->Class; Clss; Clss = Clss->Super)
					{
						for (UField* Field = Clss->Children; Field; Field = Field->Next)
						{
							if (Field->HasTypeFlag(EClassCastFlags::Function))
							{
								UFunction* Test = (UFunction*)Field;

								FN_LOG(LogHooks, Debug, "Test: %s", Test->GetFullName().c_str());
							}
						}
					}
				}
#endif // DEBUGS

				ReceivingActor->ForceNetUpdate();
			}
		}
		else if (FunctionName.contains("ServerCreateBuildingActor"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerCreateBuildingActor*)Parms;

			if (!PlayerController || !PlayerController->MyFortPawn || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get PlayerController/Pawn/PlayerState!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

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

				const float Distance = MyFortPawn->GetDistanceTo(BuildingActor);

				// Ban Def
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
					UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActor->ResourceType));

					// Ban Def
					if (!ItemInstance)
					{
						BuildingActor->SilentDie();
						return;
					}

					int32 ResourceAmount = GetCreateResourceAmount(PlayerController, BuildingClassData);

					if (ResourceAmount > ItemInstance->GetNumInStack())
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to create BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, ItemInstance->GetNumInStack());
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
		else if (FunctionName.contains("ServerRepairBuildingActor"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerRepairBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToRepair = Params->BuildingActorToRepair;

			if (!PlayerController || !PlayerController->MyFortPawn || !BuildingActorToRepair || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get PlayerController/Pawn/BuildingActorToRepair/PlayerState!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (BuildingActorToRepair->HasAuthority())
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToRepair))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] PlayerController (team: [%i]) and BuildingActorToRepair (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToRepair->Team);

					return;
				}

				const float Distance = MyFortPawn->GetDistanceTo(BuildingActorToRepair);

				// Ban Def Player
				if (Distance > 1000)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Maximum distance is 1000, your distance is %.2f.", Distance);
					return;
				}

#ifdef CHEATS
				if (!PlayerController->bBuildFree)
#endif // CHEATS
				{
					UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActorToRepair->ResourceType));

					// Ban Def Player
					if (!ItemInstance)
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get Resource Item Definition!");
						return;
					}

					int32 ResourceAmount = GetRepairResourceAmount(BuildingActorToRepair, PlayerController);

					// Ban Def Player
					if (ResourceAmount > ItemInstance->GetNumInStack())
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to repair BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, ItemInstance->GetNumInStack());
						return;
					}
				}

				int32 ResourcesSpent = PayRepairCosts(PlayerController, BuildingActorToRepair);
				BuildingActorToRepair->RepairBuilding(PlayerController, ResourcesSpent);
			}
		}
		else if (FunctionName.contains("ServerBeginEditingBuildingActor"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			auto Params = (Params::FortPlayerController_ServerBeginEditingBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToEdit = Params->BuildingActorToEdit;

			if (!PlayerController || !BuildingActorToEdit || !PlayerController->MyFortPawn || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get PlayerController/BuildingActorToEdit/Pawn/PlayerState!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (BuildingActorToEdit->HasAuthority() && CheckBeginEditBuildingActor(BuildingActorToEdit, PlayerController))
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				float Distance = MyFortPawn->GetDistanceTo(BuildingActorToEdit);

				// Kick Player
				if (Distance > 1000)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Maximum distance is 1000, your distance is %.2f.", Distance);
					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = FindObjectFast<UFortEditToolItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");
				// static UFortEditToolItemDefinition* EditToolDefinition = Globals::GetGameData()->EditToolItem.Get();

				if (!EditToolDefinition)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get EditToolDefinition!");
					return;
				}

				UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, EditToolDefinition);

				if (!ItemInstance)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get ItemInstance!");
					return;
				}

				AFortWeap_EditingTool* EditTool = (AFortWeap_EditingTool*)MyFortPawn->EquipWeaponDefinition(EditToolDefinition, ItemInstance->GetItemGuid());

				if (!EditTool)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] Failed to get EditTool!");
					return;
				}

				Functions::SetEditingPlayer(BuildingActorToEdit, (AFortPlayerStateZone*)PlayerController->PlayerState);
				Functions::SetEditingActor(EditTool, BuildingActorToEdit);
			}
		}
		else if (FunctionName.contains("ServerEditBuildingActor"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerEditBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToEdit = Params->BuildingActorToEdit;

			if (!PlayerController || !PlayerController->MyFortPawn || !BuildingActorToEdit || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get PlayerController/Pawn/BuildingActorToEdit/PlayerState!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (BuildingActorToEdit->HasAuthority() && !BuildingActorToEdit->bDestroyed)
			{
				if (PlayerState != BuildingActorToEdit->EditingPlayer)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] PlayerController (EditingPlayer: [%s]) and BuildingActorToEdit (EditingPlayer [%s]) is not the same!",
						PlayerState->GetName().c_str(), BuildingActorToEdit->EditingPlayer->GetName().c_str());

					return;
				}

				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				// Ban Def Player
				if (!Functions::IsPlayerBuildableClasse(Params->NewBuildingClass.Get()))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get BuildingClass or is not the player buildable classe!");
					return;
				}

				if (!MyFortPawn->CurrentWeapon || !MyFortPawn->CurrentWeapon->IsA(AFortWeap_EditingTool::StaticClass()))
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
		else if (FunctionName.contains("ServerEndEditingBuildingActor"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerEndEditingBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToStopEditing = Params->BuildingActorToStopEditing;

			if (!PlayerController || !BuildingActorToStopEditing || !PlayerController->MyFortPawn || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get PlayerController/BuildingActorToStopEditing/Pawn/PlayerState!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (BuildingActorToStopEditing->HasAuthority())
			{
				if (PlayerState != BuildingActorToStopEditing->EditingPlayer)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] PlayerController (EditingPlayer: [%s]) and BuildingActorToStopEditing (EditingPlayer [%s]) is not the same!",
						PlayerState->GetName().c_str(), BuildingActorToStopEditing->EditingPlayer->GetName().c_str());

					return;
				}

				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToStopEditing))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToStopEditing (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToStopEditing->Team);

					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = FindObjectFast<UFortEditToolItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");
				// static UFortEditToolItemDefinition* EditToolDefinition = Globals::GetGameData()->EditToolItem.Get();

				if (!EditToolDefinition)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get EditToolDefinition!");
					return;
				}

				AFortWeap_EditingTool* EditTool = (AFortWeap_EditingTool*)MyFortPawn->CurrentWeapon;

				if (!EditTool)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get EditTool!");
					return;
				}

				Functions::SetEditingPlayer(BuildingActorToStopEditing, nullptr);
				Functions::SetEditingActor(EditTool, nullptr);
			}
		}
		else if (FunctionName.contains("ClientOnPawnDied"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			auto Params = (Params::FortPlayerControllerZone_ClientOnPawnDied*)Parms;

			if (!PlayerController || !PlayerController->MyFortPawn || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerZone::ClientOnPawnDied] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawnAthena* Pawn = (AFortPlayerPawnAthena*)PlayerController->MyFortPawn;
			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;
			
			if (!Pawn || !PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerZone::ClientOnPawnDied] Failed to get Pawn/PlayerState!");
				return;
			}

			const FFortPlayerDeathReport& DeathReport = Params->DeathReport;

			AFortPlayerStateAthena* KillerPlayerState = (AFortPlayerStateAthena*)DeathReport.KillerPlayerState;
			AFortPlayerPawnAthena* KillerPawn = (AFortPlayerPawnAthena*)DeathReport.KillerPawn;
			AActor* DamageCauser = DeathReport.DamageCauser;
			FGameplayTagContainer Tags = Pawn ? *(FGameplayTagContainer*)(__int64(Pawn) + 0x1188) : FGameplayTagContainer();

			float Distance = KillerPawn ? KillerPawn->GetDistanceTo(Pawn) : 0;

			FDeathInfo DeathInfo;
			DeathInfo.FinisherOrDowner = KillerPlayerState ? KillerPlayerState : PlayerState;
			DeathInfo.bDBNO = Pawn->bIsDBNO;
			DeathInfo.DeathCause = ToDeathCause(Tags, Pawn->bIsDBNO);
			DeathInfo.Distance = (DeathInfo.DeathCause == EDeathCause::FallDamage) ? Pawn->LastFallDistance : Distance;
			DeathInfo.DeathLocation = Pawn->K2_GetActorLocation();
			DeathInfo.bInitialized = true;

			if (KillerPlayerState && PlayerState != KillerPlayerState)
			{
				KillerPlayerState->KillScore++;
				KillerPlayerState->ClientReportKill(PlayerState);
				KillerPlayerState->OnRep_Kills();

				PlayerState->PawnDeathLocation = DeathInfo.DeathLocation;
			}

			PlayerState->DeathInfo = DeathInfo;
			PlayerState->OnRep_DeathInfo();

			if (!Pawn->bIsDBNO)
			{
				UAthenaPlayerMatchReport* MatchReport = PlayerController->GetMatchReport();

				FAthenaMatchTeamStats TeamStats;
				TeamStats.Place = Globals::GetGameState()->PlayersLeft;
				TeamStats.TotalPlayers = Globals::GetGameState()->TotalPlayers;

				FAthenaRewardResult EndOfMatchResults;
				EndOfMatchResults.LevelsGained = 999;
				EndOfMatchResults.BookLevelsGained = 999;
				EndOfMatchResults.TotalSeasonXpGained = 999;
				EndOfMatchResults.TotalBookXpGained = 999;
				EndOfMatchResults.PrePenaltySeasonXpGained = 999;
				EndOfMatchResults.XpMultipliers = {};
				EndOfMatchResults.Rewards = {};
				EndOfMatchResults.AntiAddictionMultiplier = 0.0f;

				if (MatchReport)
				{
					//MatchReport->InitialLevelInfo;
					MatchReport->bHasMatchStats = true;
					//MatchReport->MatchStats;
					MatchReport->bHasTeamStats = true;
					MatchReport->TeamStats = TeamStats;
					MatchReport->bHasRewards = true;
					MatchReport->EndOfMatchResults = EndOfMatchResults;
					//MatchReport->TravelRecord;
				}

				PlayerController->ClientSendEndBattleRoyaleMatchForPlayer(true, EndOfMatchResults);
				PlayerController->ClientSendTeamStatsForPlayer(TeamStats);

				AFortGameModeAthena* GameMode = Globals::GetGameMode();

				AFortPlayerStateAthena* CorrectPlayerState = (PlayerState == KillerPlayerState) ? nullptr : KillerPlayerState;

				UFortWeaponItemDefinition* WeaponItemDefinition = nullptr;

				if (DamageCauser)
				{
					if (DamageCauser->IsA(AFortProjectileBase::StaticClass()))
					{
						AFortWeapon* Weapon = (AFortWeapon*)(AFortProjectileBase*)DamageCauser->GetOwner();

						if (Weapon)
							WeaponItemDefinition = Weapon->WeaponData;
					}
					else if (DamageCauser->IsA(AFortWeapon::StaticClass()))
						WeaponItemDefinition = ((AFortWeapon*)DamageCauser)->WeaponData;
				}

				//RemoveFromAlivePlayers(GameMode, PlayerController, CorrectPlayerState, KillerPawn, WeaponItemDefinition, ToDeathCause(Tags, Pawn->bIsDBNO), 0);

				/*if (GameMode && GameMode->bAllowSpectateAfterDeath && KillerPawn)
				{
					PlayerController->PlayerToSpectateOnDeath = KillerPawn;

					// Thanks reboot for K2_SetTimer
					UKismetSystemLibrary::K2_ClearTimer(PlayerController, L"SpectateOnDeath");
					UKismetSystemLibrary::K2_SetTimer(PlayerController, L"SpectateOnDeath", 5.f, false);
				}*/
			}
		}
		else if (FunctionName.contains("ServerPlayEmoteItem"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerPlayEmoteItem*)Parms;

			UFortMontageItemDefinitionBase* EmoteAsset = Params->EmoteAsset;

			if (!PlayerController || !PlayerController->PlayerState || !EmoteAsset)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerPlayEmoteItem] Failed to get PlayerController/EmoteAsset!");
				return;
			}

			AFortPlayerPawn* MyFortPawn = PlayerController->MyFortPawn;

			if (!MyFortPawn)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerPlayEmoteItem] Failed to get Pawn!");
				return;
			}

			UGameplayAbility* Ability = nullptr;

			if (EmoteAsset->IsA(UAthenaToyItemDefinition::StaticClass()))
			{
				FN_LOG(LogPlayerController, Warning, "[AFortPlayerController::ServerPlayEmoteItem] EmoteAsset UAthenaToyItemDefinition is not valid for now!");
				return;
			}
			else if (EmoteAsset->IsA(UAthenaSprayItemDefinition::StaticClass()))
			{
				Ability = UGAB_Spray_Generic_C::GetDefaultObj();
			}
			else if (EmoteAsset->IsA(UAthenaDanceItemDefinition::StaticClass()))
			{
				Ability = UGAB_Emote_Generic_C::GetDefaultObj();
			}

			if (!Ability)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerPlayEmoteItem] Failed to get Ability for EmoteAsset: [%s]", EmoteAsset->GetName().c_str());
				return;
			}

			UAthenaDanceItemDefinition* DanceItem = (UAthenaDanceItemDefinition*)EmoteAsset;

			if (DanceItem)
			{
				MyFortPawn->bMovingEmote = DanceItem->bMovingEmote;
				MyFortPawn->EmoteWalkSpeed = DanceItem->WalkForwardSpeed;
			}

			FGameplayAbilitySpecHandle Handle{ rand() };

			FGameplayAbilitySpec Spec{ -1, -1, -1 };
			Spec.Ability = Ability;
			Spec.Level = 0;
			Spec.InputID = -1;
			Spec.Handle = Handle;
			Spec.SourceObject = EmoteAsset;

			FGameplayAbilitySpecHandle OutHandle;
			Abilities::GiveAbilityAndActivateOnce(((AFortPlayerStateAthena*)PlayerController->PlayerState)->AbilitySystemComponent, &OutHandle, Spec);
		}
		else if (FunctionName.contains("ServerPlaySquadQuickChatMessage"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
			auto Params = (Params::FortPlayerControllerAthena_ServerPlaySquadQuickChatMessage*)Parms;

			static UAthenaEmojiItemDefinition* EmojiComm = FindObjectFast<UAthenaEmojiItemDefinition>("/Game/Athena/Items/Cosmetics/Dances/Emoji/Emoji_Comm.Emoji_Comm");

			if (PlayerController && EmojiComm)
			{
				FN_LOG(LogPlayerController, Debug, "[AFortPlayerController::ServerPlayEmoteItem] EmojiComm: %s, Index: %i", EmojiComm->GetName().c_str(), EmojiComm->Index);

				PlayerController->ServerPlayEmoteItem(EmojiComm);
			}
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
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;

			if (PlayerController)
			{
				if (PlayerController->Pawn)
					PlayerController->ServerSuicide();

				PlayerController->ClientTravel(L"/Game/Maps/Frontend", ETravelType::TRAVEL_Absolute, false, FGuid());
			}
		}
	}

	bool RemoveInventoryItemHook(void* a1, const FGuid& ItemGuid, int32 Count, int a4, char a5)
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
			Inventory::UpdateInventory(PlayerController->WorldInventory);
			return true;
		}
#endif // CHEATS

		bool bResult = Inventory::RemoveInventoryItem(PlayerController, ItemGuid, Count);

		if (bResult)
			Inventory::UpdateInventory(PlayerController->WorldInventory);

		return bResult;
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

		Inventory::ModifyLoadedAmmoItem(PlayerController, ItemGuid, CorrectAmmo);
		Inventory::UpdateInventory(PlayerController->WorldInventory);

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

		Inventory::RemoveAllItemsFromInventory(PlayerController);
		Inventory::UpdateInventory(PlayerController->WorldInventory);

		OnEnterAircraft(PlayerController, AthenaAircraft);
	}

	void InitPlayerController()
	{
		static auto FortPlayerControllerAthenaDefault = AFortPlayerControllerAthena::GetDefaultObj();

		auto IdkDefault = (void*)(__int64(FortPlayerControllerAthenaDefault) + IdkOffset);

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

		GetRepairResourceAmount = decltype(GetRepairResourceAmount)(AddressGetRepairResourceAmount);
		GetCreateResourceAmount = decltype(GetCreateResourceAmount)(AddressGetCreateResourceAmount);
		PayRepairCosts = decltype(PayRepairCosts)(AddressPayRepairCosts);
		PayBuildingCosts = decltype(PayBuildingCosts)(AddressPayBuildingCosts);
		CanAddBuildingActorToGrid = decltype(CanAddBuildingActorToGrid)(AddressCanAddBuildingActorToGrid);
		CheckBeginEditBuildingActor = decltype(CheckBeginEditBuildingActor)(AddressCheckBeginEditBuildingActor);
		ReplaceBuildingActor = decltype(ReplaceBuildingActor)(AddressReplaceBuildingActor);
		ToDeathCause = decltype(ToDeathCause)(AddressToDeathCause);

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}