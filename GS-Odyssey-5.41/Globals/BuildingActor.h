#pragma once

namespace BuildingActor
{
    void (*ABuildingSMActor_PostUpdateOG)(ABuildingSMActor* BuildingActor);
    FName (*PickLootTierGroupAthena)(ABuildingContainer* BuildingContainer, FName* OutLootTierGroup, FName SearchLootTierGroup);
	void (*SelectMeshSetByLootTier)(ABuildingSMActor* BuildingActor, int32 LootTier);
	void (*SetMeshSet)(ABuildingSMActor* BuildingActor, FMeshSet MeshSet);
	bool (*OnSearchedContainer)(ABuildingContainer* BuildingContainer, AFortPlayerPawn* PlayerPawn);
	int32 (*DetermineMaxResourcesToSpawn)(ABuildingSMActor* BuildingSMActor, char a2);

	float GenFlyTime()
	{
		float MaxTime; // [rsp+48h] [rbp+10h] BYREF
		float MinTime; // [rsp+50h] [rbp+18h] BYREF

		UCurveVector* PickupSplineCurve = Globals::GetGameData()->PickupSplineCurve;
		if (!PickupSplineCurve)
			return 1.5f;
		PickupSplineCurve->GetTimeRange(&MinTime, &MaxTime);
		float PickupSplineRandomMax = Globals::GetGameData()->PickupSplineRandomMax;
		return (float)(MaxTime - MinTime) * (float)((float)((float)((float)rand() * 0.000030518509f) * (float)(PickupSplineRandomMax - 1.0f)) + 1.0f);
	}

	/*void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("OnDamageServer"))
		{
			ABuildingSMActor* BuildingSMActor = Cast<ABuildingSMActor>(Object);
			auto Params = (Params::BuildingActor_OnDamageServer*)Parms;

			if (!BuildingSMActor || !Params->InstigatedBy || !Params->DamageCauser)
				return;

			AFortPlayerController* PlayerController = (AFortPlayerController*)Params->InstigatedBy;
			AFortWeapon* Weapon = (AFortWeapon*)Params->DamageCauser;
			AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

			if (!PlayerPawn || BuildingSMActor->bDestroyed)
				return;

            if (BuildingSMActor->HasAuthority())
            {
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Weapon->ItemEntryGuid));

                if (!WorldItem)
                    return;

				UFortWeaponMeleeItemDefinition* WeaponItemDefinition = Cast<UFortWeaponMeleeItemDefinition>(WorldItem->GetItemDefinitionBP());

				if (WeaponItemDefinition)
				{
					UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingSMActor->ResourceType);

					if (!ResourceItemDefinition)
						return;

					if (BuildingSMActor->MaxResourcesToSpawn < 0)
					{
						BuildingSMActor->MaxResourcesToSpawn = DetermineMaxResourcesToSpawn(BuildingSMActor, 1);
					}

					int32 MaxResourcesToSpawn = BuildingSMActor->MaxResourcesToSpawn;
					float MaxHealth = BuildingSMActor->GetMaxHealth();
					float ResourceRatio = MaxResourcesToSpawn / MaxHealth;
					float ResourceDropAmount = ResourceRatio * Params->Damage;

					int32 PotentialResourceCount = (int32)ResourceDropAmount;

					bool bHasHealthLeft = BuildingSMActor->HasHealthLeft();
					bool bDestroyed = false;

					if (!bHasHealthLeft)
					{
						bDestroyed = true;

						int32 MinResourceCount = 0;

						if (!ResourceItemDefinition || (MinResourceCount = 1, ResourceRatio == 0.0))
							MinResourceCount = 0;

						if (PotentialResourceCount < MinResourceCount)
							PotentialResourceCount = MinResourceCount;

						if (BuildingSMActor->DestructionLootTierKey.IsValid())
						{
							int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingSMActor);

							TArray<FFortItemEntry> LootToDrops;
							Loots::PickLootDrops(&LootToDrops, LootLevel, BuildingSMActor->DestructionLootTierKey, 0, 0, BuildingSMActor->StaticGameplayTags, true, false);

							for (int32 i = 0; i < LootToDrops.Num(); i++)
							{
								FFortItemEntry LootToDrop = LootToDrops[i];
								UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

								if (!WorldItemDefinition)
								{
									FN_LOG(LogBuildingActor, Error, "Loot tier %s dropped entry with no item data!", BuildingSMActor->DestructionLootTierGroup.ToString().c_str());
									continue;
								}

								FVector ComponentLocation = BuildingSMActor->RootComponent->K2_GetComponentLocation();
								FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

								ComponentLocation.X += RandomDirection.X * 200.0f;
								ComponentLocation.Y += RandomDirection.Y * 200.0f;
								ComponentLocation.Z += RandomDirection.Z * 200.0f;

								FFortItemEntry ItemEntry;
								Inventory::MakeItemEntry(&ItemEntry, WorldItemDefinition, LootToDrop.Count, LootToDrop.Level, LootToDrop.LoadedAmmo, LootToDrop.Durability);

								Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);

								AFortPickup* Pickup = Inventory::CreateSimplePickup(Globals::GetWorld(), &ItemEntry, ComponentLocation, FRotator());

								if (Pickup)
								{
									FVector ConeDir = { 0, 0, 0 };
									FVector VectorInCone = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(ConeDir, 1.0f);

									float FlyTime = GenFlyTime();
									Pawn::SetPickupTarget(Pickup, PlayerPawn, (FlyTime + (i + 1) * 0.30000001192092896f), VectorInCone);
								}
							}

							if (LootToDrops.IsValid())
								LootToDrops.Free();
						}
					}

					if (PotentialResourceCount > 0)
					{
						FFortItemEntry ItemEntry;
						Inventory::MakeItemEntry(&ItemEntry, ResourceItemDefinition, PotentialResourceCount, 0, 0, 0.f);

						Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);

						FVector ComponentLocation = BuildingSMActor->RootComponent->K2_GetComponentLocation();
						FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

						ComponentLocation.X += RandomDirection.X * 200.0f;
						ComponentLocation.Y += RandomDirection.Y * 200.0f;
						ComponentLocation.Z += RandomDirection.Z * 200.0f;

						Inventory::AddInventoryItem(PlayerController, ItemEntry, FGuid());
						PlayerController->ClientReportDamagedResourceBuilding(BuildingSMActor, BuildingSMActor->ResourceType, PotentialResourceCount, bDestroyed, (Params->Damage == 100.0f));
					}
				}
            }
		}
	}*/

	void SelectMeshSetByLootTierKey(ABuildingSMActor* BuildingActor, FName LootTierKey)
	{
		int32 LootTier = Loots::FindLootTierFromKey(LootTierKey);

		FTierMeshSets* MeshSets = nullptr;

		if (BuildingActor->AlternateMeshes.Num() > 0)
		{
			for (int32 i = 0; i < BuildingActor->AlternateMeshes.Num(); i++)
			{
				FTierMeshSets* AlternateMeshe = &BuildingActor->AlternateMeshes[i];
				int32 Tier = AlternateMeshe->Tier;

				if (Tier <= LootTier && (!MeshSets || MeshSets->Tier < Tier))
				{
					if (AlternateMeshe->MeshSets.Num() <= 0)
					{
						FN_LOG(LogBuildingActor, Warning, "No Alternative Mesh available for Building: %s at LootTier: %d", BuildingActor->GetName().c_str(), Tier);
					}
					else
					{
						MeshSets = AlternateMeshe;
					}
				}
			}

			if (MeshSets)
			{
				int32 AltMeshIdx = BuildingActor->AltMeshIdx;

				if (AltMeshIdx != -1)
				{
					SetMeshSet(BuildingActor, MeshSets->MeshSets[AltMeshIdx]);
				}
			}
		}

		FN_LOG(LogBuildingActor, Debug, "ABuildingSMActor::SelectMeshSet(FName LootTierKey) Building: %s, AltMeshIdx: %d", BuildingActor->GetName().c_str(), BuildingActor->AltMeshIdx);
	}

	void ABuildingSMActor_PostUpdate(ABuildingSMActor* BuildingActor)
	{
		EFortBuildingPersistentState PersistentState = EFortBuildingPersistentState::Default;
		FName LootTierKey = BuildingActor->DestructionLootTierKey;

		if (BuildingActor->DestructionLootTierKey.IsValid())
		{
			SelectMeshSetByLootTierKey(BuildingActor, LootTierKey);
		}
		else
		{
			if (BuildingActor->DestructionLootTierGroup.IsValid())
			{
				int32 LootTier = -1;
				int32 ChooseLootTier;

				if (BuildingActor->DestructionLootTierChosenQuotaInfo.LootTierKey.ComparisonIndex > 0 || BuildingActor->DestructionLootTierChosenQuotaInfo.LootTierKey.Number > 0)
				{
					ChooseLootTier = BuildingActor->DestructionLootTierChosenQuotaInfo.LootTier;
					LootTierKey = BuildingActor->DestructionLootTierChosenQuotaInfo.LootTierKey;
					LootTier = ChooseLootTier;
				}
				else
				{
                    int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingActor);

					Loots::PickLootTierKeyAndLootTierFromTierGroup(&BuildingActor->DestructionLootTierKey, &LootTier, BuildingActor->DestructionLootTierGroup, LootLevel, 0, -1, BuildingActor->StaticGameplayTags);

					ChooseLootTier = LootTier;
				}

				SelectMeshSetByLootTier(BuildingActor, ChooseLootTier);
			}

			if (!Loots::IsLootDropPossible(BuildingActor->DestructionLootTierKey, L"ABuildingSMActor::AttemptSpawnResources", 0))
			{
				LootTierKey = FName(0);
				PersistentState = EFortBuildingPersistentState::Searched;
			}

			if (BuildingActor->AltMeshIdx != -1 && BuildingActor->bPersistToWorld)
			{
				AFortGameState* GameState = Globals::GetGameState();

				if (GameState && GameState->WorldManager)
				{
					/*void (*sub_7FF71A0147F0)(AFortWorldManager * WorldManager, ABuildingSMActor * BuildingActor, EFortBuildingPersistentState PersistentState, char a4) = decltype(sub_7FF71A0147F0)(0x5947F0 + uintptr_t(GetModuleHandle(0)));
					sub_7FF71A0147F0(GameState->WorldManager, BuildingActor, PersistentState, 1);*/
				}
			}
		}

		FN_LOG(LogBuildingActor, Debug, "ABuildingSMActor::PostUpdate() Building: %s, AltMeshIdx: %d", BuildingActor->GetName().c_str(), BuildingActor->AltMeshIdx);

        ABuildingSMActor_PostUpdateOG(BuildingActor);
	}

	void ABuildingContainer_PostUpdate(ABuildingContainer* BuildingContainer, EFortBuildingPersistentState BuildingPersistentState, void* a3)
	{
		float v7;

		FName* LootTierKey = nullptr;
		int32 LootTier;
		int32 ChooseLootTier;

		if (BuildingPersistentState == EFortBuildingPersistentState::New)
		{
			v7 = 0.0f;

			// 7FF71AB8F090
			/*const TCHAR* (*FCommandLine_Get)() = decltype(FCommandLine_Get)(0x110F090 + uintptr_t(GetModuleHandle(0)));

			// 7FF71ABC5660
			bool (*FParse_Param)(const TCHAR * Stream, const TCHAR * Param) = decltype(FParse_Param)(0x1145660 + uintptr_t(GetModuleHandle(0)));*/

			bool bSpawnAllLoot = false; // FParse_Param(FCommandLine_Get(), L"SpawnAllLoot");

			if (bSpawnAllLoot)
				v7 = 1.0;

			if (BuildingContainer->SearchLootTierGroup.IsValid())
			{
				PickLootTierGroupAthena(BuildingContainer, &BuildingContainer->SearchLootTierGroup, BuildingContainer->SearchLootTierGroup);

				LootTier = -1;
				v7 = 1.0f;

				AFortGameState* GameState = Globals::GetGameState();
				AFortWorldManager* WorldManager = GameState->WorldManager;

				if (BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey.ComparisonIndex > 0 || BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey.Number > 0)
				{
					LootTierKey = &BuildingContainer->ContainerLootTierKey;
					ChooseLootTier = BuildingContainer->SearchLootTierChosenQuotaInfo.LootTier;

					BuildingContainer->ContainerLootTierKey = BuildingContainer->SearchLootTierChosenQuotaInfo.LootTierKey;

					LootTier = ChooseLootTier;
				}
				else
				{
                    int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

					LootTierKey = &BuildingContainer->ContainerLootTierKey;

					Loots::PickLootTierKeyAndLootTierFromTierGroup(&BuildingContainer->ContainerLootTierKey, &LootTier, BuildingContainer->SearchLootTierGroup, LootLevel, 0, -1, BuildingContainer->StaticGameplayTags);

					ChooseLootTier = LootTier;
				}

				SelectMeshSetByLootTier(BuildingContainer, ChooseLootTier);

				EFortBuildingPersistentState PersistentState = EFortBuildingPersistentState::Default;

				if (!bSpawnAllLoot && !BuildingContainer->bAlwaysMaintainLoot && !Loots::IsLootDropPossible(*LootTierKey, L"ABuildingContainer::PostUpdate", 0))
				{
					LootTierKey = nullptr;
					PersistentState = EFortBuildingPersistentState::Searched;

					OnSearchedContainer(BuildingContainer, nullptr);

					if (!BuildingContainer->bAlwaysShowContainer)
						v7 = 0.0f;
				}

				if (BuildingContainer->bPersistToWorld && GameState && GameState->WorldManager)
				{
					if (PersistentState == EFortBuildingPersistentState::Searched)
					{
						/*void (*sub_7FF71A0147F0)(AFortWorldManager * WorldManager, ABuildingSMActor * BuildingActor, EFortBuildingPersistentState PersistentState, char a4) = decltype(sub_7FF71A0147F0)(0x5947F0 + uintptr_t(GetModuleHandle(0)));
						sub_7FF71A0147F0(GameState->WorldManager, BuildingContainer, PersistentState, (BuildingContainer->AltMeshIdx == -1) ? 0 : 1);*/
					}
				}

				static UBlueprintGeneratedClass* FloorLootClass = FindObjectFast<UBlueprintGeneratedClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");
				static UBlueprintGeneratedClass* FloorLootWarmupClass = FindObjectFast<UBlueprintGeneratedClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_Warmup.Tiered_Athena_FloorLoot_Warmup_C");

				if (BuildingContainer->IsA(FloorLootClass) || BuildingContainer->IsA(FloorLootWarmupClass))
				{
					Functions::SpawnLootOnFloorLoot(BuildingContainer);
				}
			}

			float v6 = (float)rand() * 0.000030518509f;

			if ((float)((float)(v6 * 1.0f) + 0.0000000099999999f) > v7)
			{
				if (BuildingContainer->bBuriedTreasure)
				{
					OnSearchedContainer(BuildingContainer, nullptr);

					if (BuildingContainer->bPersistToWorld)
					{
						AFortWorldManager* WorldManager = Globals::GetGameState()->WorldManager;

						if (WorldManager)
						{
							/*void (*sub_7FF66CC33420)(AFortWorldManager * WorldManager, ABuildingSMActor * BuildingActor, EFortBuildingPersistentState PersistentState, char a4) = decltype(sub_7FF66CC33420)(0x613420 + uintptr_t(GetModuleHandle(0)));
							sub_7FF66CC33420(WorldManager, BuildingContainer, EFortBuildingPersistentState::Searched, 0);*/
						}
					}
				}
				else
				{
					/*void** VTable = BuildingContainer->VTable;
					v5 = (__int64)sub_7FF719FA3120();
					((void(__fastcall*)(ABuildingContainer*, _QWORD, _QWORD, _QWORD))VTable[0xF1])(
						BuildingContainer,
						*(_QWORD*)(v5 + 0x170),
						0i64,
						0i64);*/
				}

				BuildingContainer->ContainerLootTierKey = FName(0);
			}
		}
		else
		{
			if (BuildingContainer->ContainerLootTierKey.IsValid())
			{
				SelectMeshSetByLootTierKey(BuildingContainer, BuildingContainer->ContainerLootTierKey);
			}
			else
			{
                int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);
				LootTier = -1;

				Loots::PickLootTierKeyAndLootTierFromTierGroup(&BuildingContainer->ContainerLootTierKey, &LootTier, BuildingContainer->SearchLootTierGroup, LootLevel, 0, -1, BuildingContainer->StaticGameplayTags);

				SelectMeshSetByLootTier(BuildingContainer, LootTier);
			}

			if (BuildingPersistentState == EFortBuildingPersistentState::Searched)
			{
				OnSearchedContainer(BuildingContainer, nullptr);
			}
		}

		FN_LOG(LogBuildingActor, Debug, "ABuildingContainer::PostUpdate() on existing container Container: %s, ContainerLootTierKey: %s, AltMeshIdx: %d",
			BuildingContainer->GetName().c_str(), BuildingContainer->ContainerLootTierKey.ToString().c_str(), BuildingContainer->AltMeshIdx);
	}

    bool SpawnLoot(ABuildingContainer* BuildingContainer, AFortPlayerPawn* PlayerPawn)
    {
        if (!BuildingContainer->HasAuthority() || !PlayerPawn)
            return false;

        BuildingContainer->ForceNetUpdate();

        bool bHasNewAlreadySearched = false;

        if (!BuildingContainer->bAlreadySearched)
        {
			bool bIsAthena = UFortGlobals::IsInAthena();

			float LootSpawnLocationX = bIsAthena ? BuildingContainer->LootSpawnLocation_Athena.X : BuildingContainer->LootSpawnLocation.X;
			float LootSpawnLocationY = bIsAthena ? BuildingContainer->LootSpawnLocation_Athena.Y : BuildingContainer->LootSpawnLocation.Y;
			float LootSpawnLocationZ = bIsAthena ? BuildingContainer->LootSpawnLocation_Athena.Z : BuildingContainer->LootSpawnLocation.Z;

            FVector SpawnLocation = BuildingContainer->K2_GetActorLocation() + 
				BuildingContainer->GetActorForwardVector() * LootSpawnLocationX + 
				BuildingContainer->GetActorRightVector() * LootSpawnLocationY +
				BuildingContainer->GetActorUpVector() * LootSpawnLocationZ;

            UFortItemDefinition* LootTestingData = BuildingContainer->LootTestingData;

            if (LootTestingData)
            {
                FFortItemEntry ItemEntry;
                Inventory::MakeItemEntry(&ItemEntry, LootTestingData, 1, -1, -1, 1.0f);

                UFortWorldItemDefinition* ItemDefinition = Cast<UFortWorldItemDefinition>(ItemEntry.ItemDefinition);

                if (ItemDefinition && ItemDefinition->ItemType == EFortItemType::WeaponMelee || ItemDefinition->ItemType == EFortItemType::WeaponRanged)
                {
                    int32 ItemLevel = ItemEntry.Level;

                    float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

					Inventory::SetDurability(&ItemEntry, NewDurability);
                    Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DurabilityInitialized, 1);
                }

				FRotator SpawnRotation = FRotator({ 0, 0, 0 });

				FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
				CreatePickupData.World = Globals::GetWorld();
				CreatePickupData.ItemEntry = &ItemEntry;
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
					if (UFortGlobals::IsInAthena())
					{
						Pickup->TossPickup(SpawnLocation, nullptr, 0, true);
					}
					else
					{
						FVector InStartDirection = FVector({ 0, 0, 0 });
						InStartDirection.Z = 1.0f;

						Pawn::SetPickupTarget(Pickup, PlayerPawn, 0.0f, InStartDirection, true);
					}
				}
            }
            else if (BuildingContainer->ContainerLootTierKey.IsValid())
            {
                int32 LootLevel = UFortKismetLibrary::GetLootLevel(BuildingContainer);

                TArray<FFortItemEntry> LootToDrops;
                Loots::PickLootDrops(&LootToDrops, LootLevel, BuildingContainer->ContainerLootTierKey, 0, 0, BuildingContainer->StaticGameplayTags, true, false);

                BuildingContainer->HighestRarity = EFortRarity::Handmade;

                if (LootToDrops.Num() > 0)
                {
                    for (int32 i = 0; i < LootToDrops.Num(); i++)
                    {
                        FFortItemEntry LootToDrop = LootToDrops[i];
                        UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

                        if (!WorldItemDefinition)
                        {
                            UFortItemDefinition* ItemDefinition = LootToDrop.ItemDefinition;
                            FN_LOG(LogBuildingActor, Warning, "Attempted to spawn non-world item %s!", ItemDefinition->GetName().c_str());
                            continue;
                        }

                        EFortRarity Rarity = BuildingContainer->HighestRarity;

                        if (WorldItemDefinition->bCalculateRarityFromQualityAndTier)
                        {
                            unsigned __int8 Tier = (unsigned __int8)WorldItemDefinition->Tier;
                            unsigned __int8 Quality = (unsigned __int8)WorldItemDefinition->Quality;

                            if (Tier > 0)
                                Quality += (Tier - 1) / 2;

                            Rarity = EFortRarity::Legendary;

                            if (Quality <= 9)
                                Rarity = (EFortRarity)Quality;
                        }
                        else
                        {
                            Rarity = WorldItemDefinition->Rarity;
                        }

                        EFortRarity HighestRarity = BuildingContainer->HighestRarity;

                        if (HighestRarity < Rarity)
                            BuildingContainer->HighestRarity = Rarity;

                        if (WorldItemDefinition->ItemType == EFortItemType::WeaponMelee || WorldItemDefinition->ItemType == EFortItemType::WeaponRanged)
                        {
                            int32 ItemLevel = LootToDrop.Level;

                            float NewDurability = 1.0f * BuildingContainer->LootedWeaponsDurabilityModifier;

                            if (NewDurability != LootToDrop.Durability)
                            {
                                LootToDrop.Durability = NewDurability;
                                LootToDrop.bIsDirty = true;
                            }

                            Inventory::SetStateValue(&LootToDrop, EFortItemEntryState::DurabilityInitialized, 1);
                        }

						FRotator SpawnRotation = FRotator({ 0, 0, 0 });

						FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
						CreatePickupData.World = Globals::GetWorld();
						CreatePickupData.ItemEntry = &LootToDrop;
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
							if (UFortGlobals::IsInAthena())
							{
								Pickup->TossPickup(SpawnLocation, nullptr, 0, true);
							}
							else
							{
								FVector ConeDir = FVector({ 0, 0, 0 });
								FVector VectorInCone = UKismetMathLibrary::RandomUnitVectorInConeInRadians(ConeDir, 1.0f);

								float FlyTime = GenFlyTime();
								Pawn::SetPickupTarget(Pickup, PlayerPawn, (FlyTime + i * 0.30000001192092896f), VectorInCone, true);
							}
						}
                    }
                }
            }

            bHasNewAlreadySearched = true;
        }

        float LootNoiseRange = BuildingContainer->LootNoiseRange;

        if (LootNoiseRange > 0.0f)
        {
            USceneComponent* RootComponent = BuildingContainer->RootComponent;
            FVector ComponentLocation;

            if (RootComponent)
            {
                ComponentLocation = RootComponent->K2_GetComponentLocation();
            }
            else
            {
                ComponentLocation = FVector();
            }

            UFortAIFunctionLibrary::MakeNoiseEventAtLocation(PlayerPawn, LootNoiseRange, ComponentLocation);
        }

        if (!BuildingContainer->bDestroyed)
        {
            OnSearchedContainer(BuildingContainer, PlayerPawn);

            /*if (BuildingContainer->bPersistToWorld && WorldManager)
            {

            }*/
        }

        USceneComponent* PawnRootComponent = PlayerPawn->RootComponent;

        FVector StartDirection = FVector({ 0, 0, 0 });

        if (PawnRootComponent)
        {
            FVector PlayerLocation = PawnRootComponent->K2_GetComponentLocation();
            StartDirection = PlayerLocation;
        }
        else
        {
            StartDirection = FVector({ 0, 0, 0 });
        }

        FVector* DirectionPtr = &StartDirection;
        FRotator AdjustedRotation = FRotator({ 0, 0, 0 });

        AdjustedRotation.Pitch = DirectionPtr->X;

        USceneComponent* BuildingRootComponent = BuildingContainer->RootComponent;
        FVector AdjustedDirection = FVector({ 0, 0, 0 });

        if (BuildingRootComponent)
        {
            FVector BuildingLocation = BuildingRootComponent->K2_GetComponentLocation();
            AdjustedDirection = BuildingLocation;
        }
        else
        {
            AdjustedDirection = FVector({ 0, 0, 0 });
        }

        float YawDiff = AdjustedRotation.Yaw - AdjustedDirection.Y;
        float PitchDiff = AdjustedRotation.Pitch - AdjustedDirection.X;

        BuildingContainer->SearchBounceData.BounceNormal = FVector(0, 0, 0);
        FVector& BounceNormal = BuildingContainer->SearchBounceData.BounceNormal;

        BounceNormal.X = PitchDiff;
        BounceNormal.Y = YawDiff;

        float VectorLength = UKismetMathLibrary::Sqrt((BounceNormal.X * BounceNormal.X) + (BounceNormal.Y * BounceNormal.Y));

        if (VectorLength > 0.000000009999999f)
        {
            BounceNormal.X /= VectorLength;
            BounceNormal.Y /= VectorLength;
        }

        BuildingContainer->SearchBounceData.SearchAnimationCount++;
        BuildingContainer->BounceContainer();

        if (bHasNewAlreadySearched && BuildingContainer->bAlreadySearched && !UFortGlobals::IsInAthena())
        {
            if (BuildingContainer->bDestroyContainerOnSearch)
                BuildingContainer->K2_DestroyActor();
        }

        return true;
    }

	void HarvestLoot(ABuildingSMActor* BuildingSMActor, AFortPlayerPawn* PlayerPawn, float Damage, bool bJustHitWeakspot)
	{
		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(PlayerPawn->Controller);

		if (PlayerController)
		{
			EFortResourceType ResourceType = BuildingSMActor->ResourceType;

			UFortGameData* GameData = Globals::GetGameData();
			UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(ResourceType);

			if (!ResourceItemDefinition)
				return;

			if (BuildingSMActor->MaxResourcesToSpawn < 0)
			{
				BuildingSMActor->MaxResourcesToSpawn = DetermineMaxResourcesToSpawn(BuildingSMActor, 1);
			}

			float MaxResourcesToSpawn = BuildingSMActor->MaxResourcesToSpawn;
			float MaxHealth = BuildingSMActor->GetMaxHealth();
			float ResourceRatio = MaxResourcesToSpawn / MaxHealth;
			float ResourceDropAmount = ResourceRatio * Damage;

			int32 PotentialResourceCount = (int32)ResourceDropAmount;

			bool bHasHealthLeft = BuildingSMActor->HasHealthLeft();
			bool bDestroyed = false;

			if (!bHasHealthLeft)
			{
				bDestroyed = true;

				int32 MinResourceCount = 0;

				if (!ResourceItemDefinition || (MinResourceCount = 1, ResourceRatio == 0.0))
					MinResourceCount = 0;

				if (PotentialResourceCount < MinResourceCount)
					PotentialResourceCount = MinResourceCount;

				if (BuildingSMActor->DestructionLootTierKey.IsValid())
				{
					int32 WorldLevel = -1;

					AFortGameState* GameState = Cast<AFortGameState>(UGameplayStatics::GetGameState(BuildingSMActor));

					if (GameState)
						WorldLevel = GameState->WorldLevel;

					TArray<FFortItemEntry> LootToDrops;
					Loots::PickLootDrops(&LootToDrops, WorldLevel, BuildingSMActor->DestructionLootTierKey, 0, 0, BuildingSMActor->StaticGameplayTags, true, false);

					if (LootToDrops.Num() > 0)
					{
						for (int32 i = 0; i < LootToDrops.Num(); i++)
						{
							FFortItemEntry LootToDrop = LootToDrops[i];
							UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);

							if (!WorldItemDefinition)
							{
								FN_LOG(LogBuildingActor, Error, "Loot tier %s dropped entry with no item data!", BuildingSMActor->DestructionLootTierGroup.ToString().c_str());
								continue;
							}

							FVector ComponentLocation = BuildingSMActor->RootComponent->K2_GetComponentLocation();
							FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

							ComponentLocation.X += RandomDirection.X * 200.0f;
							ComponentLocation.Y += RandomDirection.Y * 200.0f;
							ComponentLocation.Z += RandomDirection.Z * 200.0f;

							FFortItemEntry ItemEntry;
							Inventory::MakeItemEntry(&ItemEntry, WorldItemDefinition, LootToDrop.Count, LootToDrop.Level, LootToDrop.LoadedAmmo, LootToDrop.Durability);

							Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);

							AFortPickup* Pickup = Inventory::CreateSimplePickup(Globals::GetWorld(), &ItemEntry, ComponentLocation, FRotator());

							if (Pickup)
							{
								FVector ConeDir = { 0, 0, 0 };
								FVector VectorInCone = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(ConeDir, 1.0f);

								float FlyTime = GenFlyTime();
								Pawn::SetPickupTarget(Pickup, PlayerPawn, (FlyTime + (i + 1) * 0.30000001192092896f), VectorInCone, true);
							}

							Inventory::FreeItemEntry(&ItemEntry);
						}
					}

					if (LootToDrops.IsValid())
						LootToDrops.Free();
				}
			}

			if (PotentialResourceCount > 0)
			{
				FFortItemEntry ItemEntry;
				Inventory::CreateDefaultItemEntry(&ItemEntry, ResourceItemDefinition, PotentialResourceCount, 0);

				Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::DoNotShowSpawnParticles, 1);

				FVector ComponentLocation = BuildingSMActor->RootComponent->K2_GetComponentLocation();
				FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

				ComponentLocation.X += RandomDirection.X * 200.0f;
				ComponentLocation.Y += RandomDirection.Y * 200.0f;
				ComponentLocation.Z += RandomDirection.Z * 200.0f;

				/*AFortPickup* Pickup = Inventory::CreateSimplePickup(Globals::GetWorld(), &ItemEntry, ComponentLocation, FRotator());

				if (Pickup)
				{
					if (BuildingSMActor->OwnerPersistentID == -1)
					{

					}

					float FlyTime = GenFlyTime();
					Pawn::SetPickupTarget(Pickup, PlayerPawn, FlyTime, RandomDirection, true);
					PlayerController->ClientReportDamagedResourceBuilding(BuildingSMActor, BuildingSMActor->ResourceType, PotentialResourceCount, bDestroyed, bJustHitWeakspot);
				}*/

				Inventory::AddInventoryItem(PlayerController, ItemEntry, FGuid());
				PlayerController->ClientReportDamagedResourceBuilding(BuildingSMActor, BuildingSMActor->ResourceType, PotentialResourceCount, bDestroyed, bJustHitWeakspot);

				Inventory::FreeItemEntry(&ItemEntry);
			}
		}
	}

	void InitBuildingActor()
	{
        static auto BuildingContainerDefault = ABuildingContainer::GetDefaultObj();

        uintptr_t AddressPickLootTierGroupAthena = MinHook::FindPattern(Patterns::PickLootTierGroupAthena);
		uintptr_t AddressSelectMeshSetByLootTier = MinHook::FindPattern(Patterns::SelectMeshSetByLootTier);
		uintptr_t AddressSetMeshSet = MinHook::FindPattern(Patterns::SetMeshSet);
		uintptr_t AddressOnSearchedContainer = MinHook::FindPattern(Patterns::OnSearchedContainer);
		uintptr_t AddressDetermineMaxResourcesToSpawn = MinHook::FindPattern(Patterns::DetermineMaxResourcesToSpawn);

        PickLootTierGroupAthena = decltype(PickLootTierGroupAthena)(AddressPickLootTierGroupAthena);
		SelectMeshSetByLootTier = decltype(SelectMeshSetByLootTier)(AddressSelectMeshSetByLootTier);
		SetMeshSet = decltype(SetMeshSet)(AddressSetMeshSet);
		OnSearchedContainer = decltype(OnSearchedContainer)(AddressOnSearchedContainer);
		DetermineMaxResourcesToSpawn = decltype(DetermineMaxResourcesToSpawn)(AddressDetermineMaxResourcesToSpawn);

        MinHook::HookVTable(BuildingContainerDefault, 0x1B9, SpawnLoot, nullptr, "SpawnLoot");
		MinHook::HookVTable(BuildingContainerDefault, 0xF5, ABuildingContainer_PostUpdate, nullptr, "ABuildingContainer::PostUpdate");
		MinHook::HookVTable(BuildingContainerDefault, 0x146, HarvestLoot, nullptr, "ABuildingSMActor::HarvestLoot");

		uintptr_t AddressABuildingSMActor_PostUpdate = MinHook::FindPattern(Patterns::ABuildingSMActor_PostUpdate);

		MH_CreateHook((LPVOID)(AddressABuildingSMActor_PostUpdate), ABuildingSMActor_PostUpdate, (LPVOID*)(&ABuildingSMActor_PostUpdateOG));
		MH_EnableHook((LPVOID)(AddressABuildingSMActor_PostUpdate));

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}