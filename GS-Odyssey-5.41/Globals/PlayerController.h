#pragma once

namespace PlayerController
{
	ABuildingSMActor* (*ReplaceBuildingActor)(ABuildingSMActor* BuildingActor, int32 a2, TSubclassOf<ABuildingSMActor> BuildingClass, int32 BuildingLevel, int32 RotationIterations, bool bMirrored, AFortPlayerController* PlayerController);
	bool (*CantBuild)(UWorld* World, TSubclassOf<ABuildingSMActor> BuildingClass, const FVector& BuildLoc, const FRotator& BuildRot, bool bMirrored, TArray<ABuildingSMActor*>* OutBuildingsToBeDestroyed);
	int32 (*PayRepairCosts)(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToRepair);
	int32 (*PayBuildingCosts)(AFortPlayerController* PlayerController, FBuildingClassData BuildingClassData);
	void (*ModifyLoadedAmmo)(void* a1, const FGuid& ItemGuid, int32 CorrectAmmo);
	EDeathCause (*ToDeathCause)(FGameplayTagContainer TagContainer, char bWasDBNOIg);

	/*void SelfCompletedUpdatedQuest(UFortQuestManager* QuestManager, AFortPlayerController* QuestOwner, UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange, const AFortPlayerState* AssistingPlayer, bool ObjectiveCompleted, bool QuestCompleted)
	{
		__int64 v6; // r14
		__int64 v11; // rdi
		__int64 v12; // rax
		__int64 v13; // r8
		__int64 v14; // rcx
		__int64 v15; // rax
		__int64 v16; // rdi
		__int64 v17; // rax
		__int64 v18; // rcx
		__int64 v19; // rax
		__int64 v20; // rdx
		__int64 v21; // rsi
		__int64 v22; // rax
		__int64 v23; // rcx
		__int64 v24; // r8
		__int64 v25; // rax
		char v26; // di
		__int128* v27; // rax
		__int64 v28; // rsi
		__int64 v29; // rax
		__int64 v30; // rcx
		__int64 v31; // r8
		__int64 v32; // rax
		__int64* v33; // rax
		char v34; // cl
		__int64 v35; // rsi
		char v36; // di
		wchar_t* v37; // rdx
		wchar_t* v38; // rcx
		__int64 v39; // rdi
		__int64 v40; // rax
		__int64 v41; // rcx
		__int64 v42; // rax
		__int64 v43; // rdx
		__int64 v44; // [rsp+40h] [rbp-41h] BYREF
		__int128 v45[2]; // [rsp+50h] [rbp-31h] BYREF
		__int128 v46; // [rsp+70h] [rbp-11h] BYREF
		__int128 v47; // [rsp+80h] [rbp-1h]
		int v48; // [rsp+D0h] [rbp+4Fh]

		if (QuestDef)
		{
			v6 = 0i64;
			v11 = *(_QWORD*)(QuestManager + 32);
			if (!v11)
				goto LABEL_12;
			v12 = UFortRegisteredPlayerInfo::StaticClass();
			v13 = *(_QWORD*)(v11 + 16);
			v14 = v12 + 48;
			v15 = *(int*)(v12 + 56);
			if ((int)v15 > *(_DWORD*)(v13 + 56))
				goto LABEL_12;
			if (*(_QWORD*)(*(_QWORD*)(v13 + 48) + 8 * v15) != v14)
				goto LABEL_12;
			v16 = sub_7FF6B95F1890(v11);
			if (!v16)
				goto LABEL_12;
			v17 = AFortPlayerControllerAthena::StaticClass();
			v18 = *(_QWORD*)(v16 + 16);
			v19 = v17 + 48;
			v20 = *(int*)(v19 + 8);
			if ((int)v20 > *(_DWORD*)(v18 + 56))
				goto LABEL_12;
			if (*(_QWORD*)(*(_QWORD*)(v18 + 48) + 8 * v20) == v19
				&& (v21 = *(_QWORD*)(v16 + 584)) != 0
				&& (v22 = AFortPlayerStateAthena::StaticClass(),
					v23 = *(_QWORD*)(v21 + 16),
					v24 = v22 + 48,
					v25 = *(int*)(v22 + 56),
					(int)v25 <= *(_DWORD*)(v23 + 56))
				&& *(_QWORD*)(*(_QWORD*)(v23 + 48) + 8 * v25) == v24)
			{
				v26 = 1;
				v27 = (__int128*)sub_7FF6BB0DD2E0(v21, (__int64)v45);
				v6 = *(_QWORD*)v27;
			}
			else
			{
			LABEL_12:
				v26 = 2;
				DWORD2(v46) = 0;
				v27 = &v46;
			}
			*(_QWORD*)v27 = 0i64;
			v48 = *((_DWORD*)v27 + 2);
			*((_QWORD*)v27 + 1) = 0i64;
			if ((v26 & 2) != 0)
			{
				v26 &= ~2u;
				if ((_QWORD)v46)
					FMemory::Free(v46);
			}
			if ((v26 & 1) != 0)
			{
				v26 &= ~1u;
				if (*(_QWORD*)&v45[0])
					FMemory::Free(*(__int64*)&v45[0]);
			}
			v28 = *(_QWORD*)(QuestOwner + 584);
			if (v28
				&& (v29 = AFortPlayerStateAthena::StaticClass(),
					v30 = *(_QWORD*)(v28 + 16),
					v31 = v29 + 48,
					v32 = *(int*)(v29 + 56),
					(int)v32 <= *(_DWORD*)(v30 + 56))
				&& *(_QWORD*)(*(_QWORD*)(v30 + 48) + 8 * v32) == v31)
			{
				v33 = (__int64*)sub_7FF6BB0DD2E0(v28, (__int64)v45);
				v34 = 4;
				v35 = *v33;
			}
			else
			{
				v33 = (__int64*)&v46;
				v35 = 0i64;
				v34 = 8;
			}
			v36 = v34 | v26;
			*v33 = 0i64;
			v33[1] = 0i64;
			if ((v36 & 8) != 0)
			{
				v36 &= ~8u;
				if ((_QWORD)v46)
					FMemory::Free(v46);
			}
			if ((v36 & 4) != 0 && *(_QWORD*)&v45[0])
				FMemory::Free(*(__int64*)&v45[0]);
			if ((unsigned __int8)byte_7FF6BDB3AD40 >= 6u)
			{
				v44 = *(_QWORD*)(QuestDef + 24);
				sub_7FF6B9F4C3D0(&v44, &v46);
				v37 = &Str1;
				v38 = &Str1;
				*(_QWORD*)&v45[0] = qword_7FF6BDB3AD44;
				if (DWORD2(v46))
					v38 = (wchar_t*)v46;
				if (v48)
					v37 = (wchar_t*)v6;
				UELog(0i64, 0, (__int64)v45, 6i64, (__int64)L"%s updated their own quest %s", v37, v38);
				if ((_QWORD)v46)
					FMemory::Free(v46);
			}
			v39 = sub_7FF6B99E1B30(QuestManager, QuestDef);
			if (v39)
			{
				v40 = AFortPlayerControllerAthena::StaticClass();
				v41 = *(_QWORD*)(QuestOwner + 16);
				v42 = v40 + 48;
				v43 = *(int*)(v42 + 8);
				if ((int)v43 <= *(_DWORD*)(v41 + 56) && *(_QWORD*)(*(_QWORD*)(v41 + 48) + 8 * v43) == v42)
				{
					*(_QWORD*)&v47 = __PAIR64__(DeltaChange, CompletionCount);
					DWORD2(v47) = *(_DWORD*)(v39 + 368);
					*(_QWORD*)&v46 = QuestDef;
					*((_QWORD*)&v46 + 1) = BackendName;
					v45[1] = v47;
					v45[0] = v46;
					sub_7FF6B9D4B650(QuestOwner, v45);
				}
			}
			if (v35)
				FMemory::Free(v35);
			if (v6)
				FMemory::Free(v6);
		}
	}*/

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

			FN_LOG(LogPlayerController, Debug, "ServerReadyToStartMatch called!");
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

					/*FFortAthenaLoadout CustomizationLoadout = PlayerController->CustomizationLoadout;
					UAthenaPickaxeItemDefinition* Pickaxe = CustomizationLoadout.Pickaxe;

					UFortWeaponMeleeItemDefinition* PickaxeDefinition = nullptr;

					if (!Pickaxe)
						PickaxeDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

					if (!Pickaxe->WeaponDefinition && !PickaxeDefinition)
						PickaxeDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

					if (Pickaxe->WeaponDefinition)
						PickaxeDefinition = Pickaxe->WeaponDefinition;

					Inventory::SetupInventory(PlayerController, PickaxeDefinition);*/
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
				if (ReceivingActor->IsA(ABuildingContainer::StaticClass()))
				{
					if (ReceivingActor->bAlreadySearched)
						return;

					FName LootTierGroup;
					BuildingActor::PickLootTierGroupAthena(ReceivingActor, &LootTierGroup, ReceivingActor->SearchLootTierGroup);

					if (LootTierGroup.IsValid())
					{
						bool bSuccess;
						std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(LootTierGroup, ReceivingActor->GetLootTier(), &bSuccess);

						if (!bSuccess)
						{
							FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerAttemptInteract] Failed to get LootToDrops!");
							return;
						}

						FFortSearchBounceData* SearchBounceData = &ReceivingActor->SearchBounceData;
						SearchBounceData->SearchAnimationCount++;

						const FVector& LootToDropLocation = ReceivingActor->K2_GetActorLocation() + ReceivingActor->GetActorForwardVector() * ReceivingActor->LootSpawnLocation_Athena.X + ReceivingActor->GetActorRightVector() * ReceivingActor->LootSpawnLocation_Athena.Y + ReceivingActor->GetActorUpVector() * ReceivingActor->LootSpawnLocation_Athena.Z;

						for (auto& LootToDrop : LootToDrops)
						{
							Inventory::SpawnPickup(nullptr, &LootToDrop, LootToDropLocation, true);
						}
					}

					ReceivingActor->bAlreadySearched = true;
					ReceivingActor->OnRep_bAlreadySearched();
					ReceivingActor->BounceContainer();
				}
				else if (ReceivingActor->IsA(AFortAthenaSupplyDrop::StaticClass()))
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

			if (!PlayerController)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get PlayerController!");
				return;
			}

			AFortPlayerState* PlayerState = (AFortPlayerState*)PlayerController->PlayerState;

			if (!PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to get PlayerState!");
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

			// 7FF66F7EB6F0
			/*bool (*sub_7FF66F7EB6F0)(AFortPlayerController* PlayerController, UClass* BuildingClass, const FVector& BuildLoc, const FRotator& BuildRot, bool bMirrored, TArray<ABuildingSMActor*>* OutBuildingsToBeDestroyed) = decltype(sub_7FF66F7EB6F0)(0xC99640 + uintptr_t(GetModuleHandle(0)));

			TArray<ABuildingSMActor*> RealBuildingsToBeDestroyed;
			bool bRealCantBuild = sub_7FF66F7EB6F0(PlayerController, BuildingClass.Get(), BuildLoc, BuildRot, Params->bMirrored, &RealBuildingsToBeDestroyed);*/

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

				UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActor->ResourceType));

				if (!ItemInstance)
				{
					BuildingActor->K2_DestroyActor();
					return;
				}

				// 7FF66F7EA9E0
				int32 (*GetResourceAmount)(AFortPlayerController* PlayerController, const FBuildingClassData& BuildingClassData) = decltype(GetResourceAmount)(0x119A9E0 + uintptr_t(GetModuleHandle(0)));
				int32 ResourceAmount = GetResourceAmount(PlayerController, BuildingClassData);

				if (ResourceAmount > ItemInstance->GetNumInStack())
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerCreateBuildingActor] Failed to create BuildingActor, resource amount [%i] while player only has [%i]", ResourceAmount, ItemInstance->GetNumInStack());
					BuildingActor->K2_DestroyActor();
					return;
				}

				for (int i = 0; i < BuildingsToBeDestroyed.Num(); i++)
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
				void (*IdkButItsCool3)(AFortGameMode* GameMode, AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActor) = decltype(IdkButItsCool3)(0xE44630 + uintptr_t(GetModuleHandle(0)));

				IdkButItsCool3(Globals::GetGameMode(), PlayerController, BuildingActor);


				PayBuildingCosts(PlayerController, BuildingClassData);
				BuildingActor->InitializeKismetSpawnedBuildingActor(BuildingActor, PlayerController, true);

				BuildingActor->bPlayerPlaced = true;
				BuildingActor->Team = ((AFortPlayerStateAthena*)PlayerController->PlayerState)->TeamIndex;

				if (BuildingsToBeDestroyed.Num() > 0)
					BuildingsToBeDestroyed.Free();
			}
		}
		else if (FunctionName.contains("ServerRepairBuildingActor"))
		{
			AFortPlayerController* PlayerController = (AFortPlayerController*)Object;
			auto Params = (Params::FortPlayerController_ServerRepairBuildingActor*)Parms;

			ABuildingSMActor* BuildingActorToRepair = Params->BuildingActorToRepair;

			if (!PlayerController || !BuildingActorToRepair || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] Failed to get PlayerController/BuildingActorToRepair/PlayerState!");
				return;
			}

			if (BuildingActorToRepair->HasAuthority())
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToRepair))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerRepairBuildingActor] PlayerController (team: [%i]) and BuildingActorToRepair (team [%i]) is not on the same team!",
						((AFortPlayerStateAthena*)PlayerController->PlayerState)->TeamIndex, BuildingActorToRepair->Team);

					return;
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

			if (BuildingActorToEdit->HasAuthority())
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerBeginEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						((AFortPlayerStateAthena*)PlayerController->PlayerState)->TeamIndex, BuildingActorToEdit->Team);

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

				AFortWeap_EditingTool* EditTool = (AFortWeap_EditingTool*)PlayerController->MyFortPawn->EquipWeaponDefinition(EditToolDefinition, ItemInstance->GetItemGuid());

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

			if (!PlayerController || !BuildingActorToEdit || !PlayerController->PlayerState)
			{
				FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to get PlayerController/BuildingActorToEdit/PlayerState!");
				return;
			}

			if (BuildingActorToEdit->HasAuthority())
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToEdit))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] PlayerController (team: [%i]) and BuildingActorToEdit (team [%i]) is not on the same team!",
						((AFortPlayerStateAthena*)PlayerController->PlayerState)->TeamIndex, BuildingActorToEdit->Team);

					return;
				}

				ABuildingSMActor* BuildingActor = ReplaceBuildingActor(BuildingActorToEdit, 1, Params->NewBuildingClass, BuildingActorToEdit->CurrentBuildingLevel, Params->RotationIterations, Params->bMirrored, PlayerController);

				if (!BuildingActor)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEditBuildingActor] Failed to replace BuildingActor: [%s]", BuildingActorToEdit->GetName().c_str());
					return;
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

			if (BuildingActorToStopEditing->HasAuthority())
			{
				if (!UFortKismetLibrary::OnSameTeam(PlayerController, BuildingActorToStopEditing))
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] PlayerController (team: [%i]) and BuildingActorToStopEditing (team [%i]) is not on the same team!",
						((AFortPlayerStateAthena*)PlayerController->PlayerState)->TeamIndex, BuildingActorToStopEditing->Team);

					return;
				}

				static UFortEditToolItemDefinition* EditToolDefinition = FindObjectFast<UFortEditToolItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");

				if (!EditToolDefinition)
				{
					FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ServerEndEditingBuildingActor] Failed to get EditToolDefinition!");
					return;
				}

				AFortWeap_EditingTool* EditTool = (AFortWeap_EditingTool*)PlayerController->MyFortPawn->CurrentWeapon;

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

		if (!PlayerController)
		{
			FN_LOG(LogPlayerController, Error, "[AFortPlayerController::ModifyLoadedAmmo] Failed to get PlayerController!");
			return;
		}

		Inventory::ModifyLoadedAmmoItem(PlayerController, ItemGuid, CorrectAmmo);
		Inventory::UpdateInventory(PlayerController->WorldInventory);

		ModifyLoadedAmmo(a1, ItemGuid, CorrectAmmo);
	}

	void TestFunc01Hook()
	{
		FN_LOG(LogPlayerController, Debug, "TestFunc01Hook func called!");
	}

	void TestFunc02Hook()
	{
		FN_LOG(LogPlayerController, Debug, "TestFunc02Hook func called!");
	}

	void (*TestFunc03)(void* a1, __int64* a2, char a3);
	void TestFunc03Hook(void* a1, __int64* a2, char a3)
	{
		FN_LOG(LogPlayerController, Debug, "TestFunc03Hook func called!");

		TestFunc03(a1, a2, a3);
	}

	void TestFunc04Hook()
	{
		FN_LOG(LogPlayerController, Debug, "TestFunc04Hook func called!");

	}

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
		uintptr_t AddressPayBuildingCosts = MinHook::FindPattern(Patterns::PayBuildingCosts);
		uintptr_t AddressPayRepairCosts = MinHook::FindPattern(Patterns::PayRepairCosts);
		uintptr_t AddressCantBuild = MinHook::FindPattern(Patterns::CantBuild);
		uintptr_t AddressReplaceBuildingActor = MinHook::FindPattern(Patterns::ReplaceBuildingActor);
		uintptr_t AddressToDeathCause = MinHook::FindPattern(Patterns::ToDeathCause);

		MH_CreateHook((LPVOID)(AddressRemoveInventoryItem), RemoveInventoryItemHook, nullptr);
		MH_EnableHook((LPVOID)(AddressRemoveInventoryItem));
		MH_CreateHook((LPVOID)(AddressModifyLoadedAmmo), ModifyLoadedAmmoHook, (LPVOID*)(&ModifyLoadedAmmo));
		MH_EnableHook((LPVOID)(AddressModifyLoadedAmmo));

		PayBuildingCosts = decltype(PayBuildingCosts)(AddressPayBuildingCosts);
		PayRepairCosts = decltype(PayRepairCosts)(AddressPayRepairCosts);
		CantBuild = decltype(CantBuild)(AddressCantBuild);
		ReplaceBuildingActor = decltype(ReplaceBuildingActor)(AddressReplaceBuildingActor);
		ToDeathCause = decltype(ToDeathCause)(AddressToDeathCause);

		FN_LOG(LogInit, Log, "InitPlayerController Success!");
	}
}