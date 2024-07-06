#pragma once

namespace PlayerController
{
	ABuildingSMActor* (*ReplaceBuildingActor)(ABuildingSMActor* BuildingActor, int32 a2, TSubclassOf<ABuildingSMActor> BuildingClass, int32 BuildingLevel, int32 RotationIterations, bool bMirrored, AFortPlayerController* PlayerController);
	bool (*CantBuild)(UWorld* World, TSubclassOf<ABuildingSMActor> BuildingClass, const FVector& BuildLoc, const FRotator& BuildRot, bool bMirrored, TArray<ABuildingSMActor*>* OutBuildingsToBeDestroyed);
	int32 (*GetRepairResourceAmount)(ABuildingSMActor* BuildingActorToRepair, AFortPlayerController* PlayerController);
	int32 (*GetCreateResourceAmount)(AFortPlayerController* PlayerController, const FBuildingClassData& BuildingClassData);
	int32 (*PayRepairCosts)(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair);
	int32 (*PayBuildingCosts)(AFortPlayerController* PlayerController, const FBuildingClassData& BuildingClassData);
	void (*ModifyLoadedAmmo)(void* a1, const FGuid& ItemGuid, int32 CorrectAmmo);
	EDeathCause (*ToDeathCause)(FGameplayTagContainer TagContainer, char bWasDBNOIg);

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ServerReadyToStartMatch"))
		{
			AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerReadyToStartMatch] Failed to get PlayerController!");
				return;
			}

			AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

			if (Pawn && PlayerController->PlayerState)
			{
				static auto DefaultAbilities = FindObjectFast<UFortAbilitySet>("/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_DefaultPlayer.GAS_DefaultPlayer");

				Abilities::GrantGameplayAbility(DefaultAbilities, Pawn);
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
			UGameplayStatics* GameplayStatics = Globals::GetGameplayStatics();

			if (GameplayStatics && !PlayerController->CheatManager)
				PlayerController->CheatManager = (UCheatManager*)GameplayStatics->SpawnObject(UCheatManager::StaticClass(), PlayerController);

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

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get PlayerController!");
				return;
			}

			if (PlayerController->IsInAircraft() && !PlayerController->Pawn)
			{
				AFortGameStateAthena* GameState = Globals::GetGameState();

				if (!GameState)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get GameState!");
					return;
				}

				AFortAthenaAircraft* Aircraft = GameState->GetAircraft(0);

				if (!Aircraft)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerControllerAthena::ServerAttemptAircraftJump] Failed to get Aircraft!");
					return;
				}

				const FVector& AircraftLocation = Aircraft->K2_GetActorLocation();

				AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerController, AircraftLocation, {}, false);

				if (PlayerPawn && PlayerController->PlayerState)
				{
					PlayerPawn->SetMaxHealth(100);
					PlayerPawn->SetHealth(100);
					PlayerPawn->SetMaxShield(100);

					// 7FF66F7BC760 (Je suis sévèrement autiste)
					void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));

					SetShield(PlayerPawn, 0);

					GameMode::ApplyCharacterCustomization((AFortPlayerState*)PlayerController->PlayerState, PlayerPawn);

					Inventory::RemoveAllItemsFromInventory(PlayerController);
					Inventory::UpdateInventory(PlayerController->WorldInventory);
				}

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
					static UClass* AthenaSupplyDropLlamaClass = FindObjectFast<UClass>("/Game/Athena/SupplyDrops/Llama/AthenaSupplyDrop_Llama.AthenaSupplyDrop_Llama_C");
					static UClass* AthenaSupplyDropClass = FindObjectFast<UClass>("/Game/Athena/SupplyDrops/AthenaSupplyDrop.AthenaSupplyDrop_C");

					FName SearchLootTierGroup;

					if (ReceivingActor->IsA(AthenaSupplyDropLlamaClass))
					{
						SearchLootTierGroup = Globals::GetStringLibrary()->Conv_StringToName(L"Loot_AthenaLlama");
					}
					else if (ReceivingActor->IsA(AthenaSupplyDropClass))
					{
						SearchLootTierGroup = Globals::GetStringLibrary()->Conv_StringToName(L"Loot_AthenaSupplyDrop");
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
						{
							Inventory::SpawnPickup(nullptr, &LootToDrop, ReceivingActor->K2_GetActorLocation(), true);
						}
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
						Globals::GetFunctionLibrary()->EvaluateCurveTableRow(InputCount.Curve.CurveTable, InputCount.Curve.RowName, BuildingItemCollector->StartingGoalLevel, &Result, &InputCostXY, ContextString);

						int32 InputCost = (InputCostXY * InputCount.Value);

#ifdef CHEATS
						if (PlayerController->bBuildFree)
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

			TArray<ABuildingSMActor*> BuildingsToBeDestroyed;
			bool bCanBuild = !CantBuild(Globals::GetWorld(), BuildingClass, BuildLoc, BuildRot, Params->bMirrored, &BuildingsToBeDestroyed);

			if (bCanBuild)
			{
				ABuildingSMActor* BuildingActor = Util::SpawnActor<ABuildingSMActor>(BuildingClass, BuildLoc, BuildRot);

				if (!BuildingActor)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to spawn BuildingActor!");
					return;
				}

				float Distance = MyFortPawn->GetDistanceTo(BuildingActor);

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

					// Ban Def
					if (ResourceAmount > ItemInstance->GetNumInStack())
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to create BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, ItemInstance->GetNumInStack());
						BuildingActor->SilentDie();
						return;
					}
				}

				for (int32 i = 0; i < BuildingsToBeDestroyed.Num(); i++)
				{
					ABuildingSMActor* BuildingToBeDestroyed = BuildingsToBeDestroyed[i];
					if (!BuildingToBeDestroyed) continue;

					BuildingToBeDestroyed->K2_DestroyActor();
				}

				BuildingActor->CurrentBuildingLevel = BuildingClassData.UpgradeLevel;

				// 7FF66F2E9640
				void (*IdkButItsCool)(ABuildingSMActor* BuildingActor, int a2, int32 WorldPlayerId) = decltype(IdkButItsCool)(0xC99640 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool(BuildingActor, 1, PlayerState->WorldPlayerId);

				// 7FF66F2F6670
				void (*IdkButItsCool2)(ABuildingSMActor* BuildingActor, bool a2) = decltype(IdkButItsCool2)(0xCA6670 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool2(BuildingActor, true);

				// 7FF66F494630
				void (*IdkButItsCool3)(AFortGameMode* GameMode, AFortPlayerController * PlayerController, ABuildingSMActor * BuildingActor) = decltype(IdkButItsCool3)(0xE44630 + uintptr_t(GetModuleHandle(0)));
				IdkButItsCool3(Globals::GetGameMode(), PlayerController, BuildingActor);

				PayBuildingCosts(PlayerController, BuildingClassData);
				BuildingActor->InitializeKismetSpawnedBuildingActor(BuildingActor, PlayerController, true);

				BuildingActor->bPlayerPlaced = true;
				BuildingActor->Team = PlayerState->TeamIndex;

				if (BuildingsToBeDestroyed.Num() > 0)
					BuildingsToBeDestroyed.Free();
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
				// Ban Def
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToRepair))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] PlayerController (team: [%i]) and BuildingActorToRepair (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToRepair->Team);

					return;
				}

				float Distance = MyFortPawn->GetDistanceTo(BuildingActorToRepair);

				// Ban Def
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

					// Ban Def
					if (!ItemInstance)
					{
						FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get Resource Item Definition!");
						return;
					}

					int32 ResourceAmount = GetRepairResourceAmount(BuildingActorToRepair, PlayerController);

					// Ban Def
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

			if (BuildingActorToEdit->HasAuthority())
			{
				// Ban Def
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = FindObjectFast<UFortEditToolItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");

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

				EditTool->EditActor = BuildingActorToEdit;
				EditTool->OnRep_EditActor();
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

			if (BuildingActorToEdit->HasAuthority())
			{
				// Ban Def
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				float Distance = MyFortPawn->GetDistanceTo(BuildingActorToEdit);

				// Ban Def
				if (Distance > 1000)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Maximum distance is 1000, your distance is %.2f.", Distance);
					return;
				}

				// Ban Def
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
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToStopEditing))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToStopEditing (team [%i]) is not on the same team!",
						PlayerState->TeamIndex, BuildingActorToStopEditing->Team);

					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = FindObjectFast<UFortEditToolItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");

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

				EditTool->EditActor = nullptr;
				EditTool->OnRep_EditActor();
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

				float Idk01 = *(float*)(__int64(PlayerController) + 0x6C2);

				//Functions::SpectatePlayer(PlayerController, KillerPawn);

				FN_LOG(LogPlayerController, Debug, "[AFortPlayerControllerZone::ClientOnPawnDied] Idk01: %.2f", Idk01);

				/*FFortSpectatorAthenaItem SpectatorAthenaItem;
				SpectatorAthenaItem.PlayerState = PlayerState;

				PlayerState->Spectators.SpectatorArray.Add(SpectatorAthenaItem);
				PlayerState->Spectators.MarkItemDirty(SpectatorAthenaItem);
				PlayerState->Spectators.ArrayReplicationKey++;
				PlayerState->Spectators.OwningState = PlayerState;
				PlayerState->Spectators.MarkArrayDirty();*/

				AFortGameModeAthena* GameMode = Globals::GetGameMode();

				if (GameMode && GameMode->bAllowSpectateAfterDeath)
				{
					
				}


				/*FAthenaMatchStats Stats;
				Stats.StatBucket;
				Stats.MatchID;
				Stats.MatchEndTime;
				Stats.MatchPlatform;
				Stats.WeaponStats;

				PlayerController->ClientSendMatchStatsForPlayer(Stats);*/
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

	void ModifyLoadedAmmoHook(void* a1, const FGuid& ItemGuid, int32 CorrectAmmo)
	{
		AFortPlayerController* PlayerController = (AFortPlayerController*)(__int64(a1) - IdkOffset);

		AFortWeapon;

		if (!PlayerController)
		{
			FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ModifyLoadedAmmo] Failed to get PlayerController!");
			return;
		}

		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		//FN_LOG(LogMinHook, Log, "Function Exec [ModifyLoadedAmmoHook] successfully hooked with Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);

		Inventory::ModifyLoadedAmmoItem(PlayerController, ItemGuid, CorrectAmmo);
		Inventory::UpdateInventory(PlayerController->WorldInventory);

		ModifyLoadedAmmo(a1, ItemGuid, CorrectAmmo);
	}

	// 7FF66F979AF0
	/*void (*TestFunc)(AFortWeapon* Weapon, int a2);
	void TestFuncHook(AFortWeapon* Weapon, int a2)
	{
		if (!Weapon)
			return;

		int IdkButItsCool = (*(int*)(__int64(Weapon) + 0x9DC));

		FN_LOG(LogMinHook, Log, "Weapon: %s, a2: %i", Weapon->GetName().c_str(), a2);

		FN_LOG(LogMinHook, Log, "IdkButItsCool 1: %i", IdkButItsCool);
		TestFunc(Weapon, a2);
		FN_LOG(LogMinHook, Log, "IdkButItsCool 2: %i", IdkButItsCool);
	}*/

	void InitPlayerController()
	{
		static auto FortPlayerControllerAthenaDefault = FindObjectFast<AFortPlayerControllerAthena>("/Script/FortniteGame.Default__FortPlayerControllerAthena");

		static auto IdkDefault = (void*)(__int64(FortPlayerControllerAthenaDefault) + IdkOffset);

		/*MinHook::HookVTable((UObject*)IdkDefault, 0xC, TestFunc01Hook, nullptr, "TestFunc01Hook");
		MinHook::HookVTable((UObject*)IdkDefault, 0x1D, TestFunc02Hook, nullptr, "TestFunc02Hook");
		MinHook::HookVTable((UObject*)IdkDefault, 0x11, TestFunc03Hook, (LPVOID*)(&TestFunc03), "TestFunc03Hook");
		MinHook::HookVTable((UObject*)IdkDefault, 0x10, TestFunc04Hook, nullptr, "TestFunc04Hook");*/

		uintptr_t AddressRemoveInventoryItem = MinHook::FindPattern(Patterns::RemoveInventoryItem);
		uintptr_t AddressModifyLoadedAmmo = MinHook::FindPattern(Patterns::ModifyLoadedAmmo);
		uintptr_t AddressGetRepairResourceAmount = MinHook::FindPattern(Patterns::GetRepairResourceAmount);
		uintptr_t AddressGetCreateResourceAmount = MinHook::FindPattern(Patterns::GetCreateResourceAmount);
		uintptr_t AddressPayRepairCosts = MinHook::FindPattern(Patterns::PayRepairCosts);
		uintptr_t AddressPayBuildingCosts = MinHook::FindPattern(Patterns::PayBuildingCosts);
		uintptr_t AddressCantBuild = MinHook::FindPattern(Patterns::CantBuild);
		uintptr_t AddressReplaceBuildingActor = MinHook::FindPattern(Patterns::ReplaceBuildingActor);
		uintptr_t AddressToDeathCause = MinHook::FindPattern(Patterns::ToDeathCause);

		MH_CreateHook((LPVOID)(AddressRemoveInventoryItem), RemoveInventoryItemHook, nullptr);
		MH_EnableHook((LPVOID)(AddressRemoveInventoryItem));
		MH_CreateHook((LPVOID)(AddressModifyLoadedAmmo), ModifyLoadedAmmoHook, (LPVOID*)(&ModifyLoadedAmmo));
		MH_EnableHook((LPVOID)(AddressModifyLoadedAmmo));

		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1329AF0), TestFuncHook, (LPVOID*)(&TestFunc));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x1329AF0));*/

		GetRepairResourceAmount = decltype(GetRepairResourceAmount)(AddressGetRepairResourceAmount);
		GetCreateResourceAmount = decltype(GetCreateResourceAmount)(AddressGetCreateResourceAmount);
		PayRepairCosts = decltype(PayRepairCosts)(AddressPayRepairCosts);
		PayBuildingCosts = decltype(PayBuildingCosts)(AddressPayBuildingCosts);
		CantBuild = decltype(CantBuild)(AddressCantBuild);
		ReplaceBuildingActor = decltype(ReplaceBuildingActor)(AddressReplaceBuildingActor);
		ToDeathCause = decltype(ToDeathCause)(AddressToDeathCause);

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}