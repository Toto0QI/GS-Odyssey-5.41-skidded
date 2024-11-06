#pragma once
#include <map>

namespace Functions
{
	AFortAthenaSupplyDrop* (*SpawnSupplyDrop)(AFortAthenaMapInfo* MapInfo, const FVector& Location, const FRotator& Rotation, UClass* SupplyDropClass, float TraceStartZ, float TraceEndZ);
	FVector (*PickSupplyDropLocation)(AFortAthenaMapInfo* MapInfo, FVector* OutSpawnLocation, FVector* CenterLocation, float Radius);
	UWorld* (*GetWorldFromContextObject)(UEngine* Engine, const UObject* Object, EGetWorldErrorMode ErrorMode);

	bool IsPlayerBuildableClasse(UClass* BuildableClasse)
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (!BuildableClasse || !GameState)
			return false;

		TArray<TSubclassOf<ABuildingActor>> BuildingActorClasses = GameState->BuildingActorClasses;

		if (BuildingActorClasses.IsValid())
		{
			for (int32 i = 0; i < BuildingActorClasses.Num(); i++)
			{
				TSubclassOf<ABuildingActor> BuildingActorClasse = BuildingActorClasses[i];
				if (!BuildingActorClasse.Get()) continue;

				if (BuildingActorClasse.Get() == BuildableClasse)
					return true;
			}
		}

		return false;
	}

	bool IsOnSameTeam(AFortPlayerStateAthena* PlayerState, ABuildingSMActor* BuildingSMActor)
	{
		if (!PlayerState || !BuildingSMActor)
			return false;

		EFortTeam PlayerTeam = PlayerState->TeamIndex;
		EFortTeam BuildingTeam = BuildingSMActor->Team;

		if (PlayerTeam == BuildingTeam)
			return true;

		if (BuildingTeam == EFortTeam::Spectator && !BuildingSMActor->bPlayerPlaced)
			return true;

		return false;
	}

	// 7FF66F3270B0
	void SetEditingPlayer(ABuildingSMActor* BuildingActor, AFortPlayerStateZone* EditingPlayer)
	{
		if (BuildingActor->HasAuthority() && (!BuildingActor->EditingPlayer || !EditingPlayer))
		{
			BuildingActor->SetNetDormancy(ENetDormancy(2 - (EditingPlayer != 0)));
			BuildingActor->ForceNetUpdate();
			BuildingActor->EditingPlayer = EditingPlayer;
		}
	}

	// 7FF66F986F80
	void SetEditingActor(AFortWeap_EditingTool* EditingTool, ABuildingSMActor* BuildingActor)
	{
		if (EditingTool->HasAuthority())
		{
			EditingTool->EditActor = BuildingActor;
			EditingTool->OnRep_EditActor();
		}
	}

	UFortGameplayAbility* LoadGameplayAbility(TSoftClassPtr<UClass> SoftGameplayAbility)
	{
		UClass* GameplayAbilityClass = SoftGameplayAbility.Get();

		if (!GameplayAbilityClass)
		{
			const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(SoftGameplayAbility.ObjectID.AssetPathName);
			GameplayAbilityClass = StaticLoadObject<UClass>(AssetPathName.CStr());
		}

		if (GameplayAbilityClass)
			return Cast<UFortGameplayAbility>(GameplayAbilityClass->CreateDefaultObject());

		return nullptr;
	}

	int GetRandomRarity(const std::map<int32, float>& RarityAndWeight) 
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		std::vector<float> weights;

		for (const auto& kv : RarityAndWeight) 
		{
			weights.push_back(kv.second);
		}

		std::discrete_distribution<> dist(weights.begin(), weights.end());

		return dist(gen);
	}

	void SpawnLootOnFloorLoot(ABuildingContainer* BuildingContainer)
	{
		if (!BuildingContainer->bAlreadySearched)
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

						Inventory::SetDurability(&LootToDrop, NewDurability);
						Inventory::SetStateValue(&LootToDrop, EFortItemEntryState::DurabilityInitialized, 1);
					}

					FVector SpawnLocation = BuildingContainer->K2_GetActorLocation();

					SpawnLocation.Z += 45;

					AFortPickup* Pickup = AFortPickup::CreatePickup(
						BuildingContainer->GetWorld(),
						&LootToDrop,
						&SpawnLocation,
						nullptr,
						nullptr,
						nullptr,
						true,
						(uint32)EFortPickupSourceTypeFlag::FloorLoot);

					if (Pickup)
						Pickup->TossPickup(SpawnLocation, nullptr, 0, true);
				}
			}

			BuildingContainer->K2_DestroyActor();
		}
	}

	FVector GetLootSpawnLocation(AFortAthenaSupplyDrop* AthenaSupplyDrop)
	{
		if (!AthenaSupplyDrop)
			return FVector();

		UFunction* GetLootSpawnLocationFunc = nullptr;

		if (GetLootSpawnLocationFunc == nullptr)
			GetLootSpawnLocationFunc = AthenaSupplyDrop->Class->GetFunction("AthenaSupplyDrop_Llama_C", "GetLootSpawnLocation");

		struct AthenaSupplyDrop_Llama_C_GetLootSpawnLocation final
		{
		public:
			FVector LootSpawnLocation;
			uint8 Pad_01[0x40];
		};

		AthenaSupplyDrop_Llama_C_GetLootSpawnLocation GetLootSpawnLocationParms{};

		if (GetLootSpawnLocationFunc)
			AthenaSupplyDrop->ProcessEvent(GetLootSpawnLocationFunc, &GetLootSpawnLocationParms);

		return std::move(GetLootSpawnLocationParms.LootSpawnLocation);
	}

	FName GetLootTableName(AFortAthenaSupplyDrop* AthenaSupplyDrop)
	{
		if (!AthenaSupplyDrop)
			return FName(0);

		const UStruct* Clss = AthenaSupplyDrop->Class;

		for (UField* Field = Clss->Children; Field; Field = Field->Next)
		{
			if (Field->HasTypeFlag(EClassCastFlags::NameProperty) && Field->GetName() == "LootTableName")
			{
				int32 LootTableNameOffset = ((UProperty*)Field)->Offset;
				return *(FName*)(__int64(AthenaSupplyDrop) + LootTableNameOffset);
			}
		}

		return FName(0);
	}

	void VendingMachinePlayVendFX(ABuildingItemCollectorActor* ItemCollectorActor)
	{
		if (!ItemCollectorActor)
			return;

		UFunction* PlayVendFXFunc = nullptr;

		if (PlayVendFXFunc == nullptr)
			PlayVendFXFunc = ItemCollectorActor->Class->GetFunction("B_Athena_VendingMachine_C", "PlayVendFX");

		if (PlayVendFXFunc)
			ItemCollectorActor->ProcessEvent(PlayVendFXFunc, nullptr);
	}

	void VendingMachinePlayVendFailFX(ABuildingItemCollectorActor* ItemCollectorActor)
	{
		if (!ItemCollectorActor)
			return;

		UFunction* PlayVendFailFXFunc = nullptr;

		if (PlayVendFailFXFunc == nullptr)
			PlayVendFailFXFunc = ItemCollectorActor->Class->GetFunction("B_Athena_VendingMachine_C", "PlayVendFailFX");

		if (PlayVendFailFXFunc)
			ItemCollectorActor->ProcessEvent(PlayVendFailFXFunc, nullptr);
	}

	void FillVendingMachine(ABuildingItemCollectorActor* ItemCollectorActor, std::map<int32, float> RarityAndWeight)
	{
		if (!ItemCollectorActor)
			return;

		int32 RandomRarity = GetRandomRarity(RarityAndWeight);

		if (RandomRarity == 0)
		{
			ItemCollectorActor->K2_DestroyActor();
			return;
		}

		// Get Real Rarity
		RandomRarity -= 1;

		// 0 = Common
		// 1 = UnCommon
		// 2 = Rare
		// 3 = Epic
		// 4 = Legendary

		TArray<FColletorUnitInfo> ItemCollections = ItemCollectorActor->ItemCollections;

		for (int32 i = 0; i < ItemCollections.Num(); i++)
		{
			FColletorUnitInfo& ItemCollection = ItemCollections[i];
			UFortWorldItemDefinition* InputItem = ItemCollection.InputItem;
			if (!InputItem) continue;

			int32 LootLevel = UFortKismetLibrary::GetLootLevel(ItemCollectorActor);

			TArray<FFortItemEntry> LootToDrops;
			bool bValidLoot = false;

			do
			{
				FName LootTierKey = FName(0);
				int32 LootTier = -1;

				bool bSuccess = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, ItemCollectorActor->DefaultItemLootTierGroupName, LootLevel, 0, RandomRarity, ItemCollectorActor->StaticGameplayTags);
				if (!bSuccess) continue;

				Loots::PickLootDrops(&LootToDrops, LootLevel, LootTierKey, 0, 0, ItemCollectorActor->StaticGameplayTags, false, false);

				bValidLoot = true;
				if (LootToDrops.Num() > 0)
				{
					UFortWorldItemDefinition* LootToDropDefinition = Cast<UFortWorldItemDefinition>(LootToDrops[0].ItemDefinition);

					for (const FColletorUnitInfo& OtherItemCollection : ItemCollections)
					{
						if (OtherItemCollection.OutputItem == LootToDropDefinition)
						{
							bValidLoot = false;
							break;
						}
					}
				}

			} while (!bValidLoot);

			if (ItemCollections[i].OutputItemEntry.Num() > 0)
				ItemCollections[i].OutputItemEntry.Free();

			for (auto& LootToDrop : LootToDrops)
				ItemCollections[i].OutputItemEntry.Add(LootToDrop);

			if (ItemCollections[i].OutputItemEntry.IsValidIndex(0))
				ItemCollections[i].OutputItem = Cast<UFortWorldItemDefinition>(ItemCollections[i].OutputItemEntry[0].ItemDefinition);
		}

		ItemCollectorActor->StartingGoalLevel = RandomRarity;
	}

	void FillVendingMachines()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState && GameState->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

			TArray<AActor*> VendingMachines;
			UGameplayStatics::GetAllActorsOfClass(MapInfo, MapInfo->VendingMachineClass, &VendingMachines);

			FString ContextString;
			EEvaluateCurveTableResult Result;

			FScalableFloat VendingMachineRarityCount = MapInfo->VendingMachineRarityCount;

			std::map<int32, float> RarityAndWeight;

			// 0 = Destroy - RarityCount: 1.00, Value: 1.00
			// 1 = Common - RarityCount: 0.25, Value: 1.00
			// 2 = UnCommon - RarityCount: 0.75, Value: 1.00
			// 3 = Rare - RarityCount: 0.75, Value: 1.00
			// 4 = Epic - RarityCount: 0.70, Value: 1.00
			// 5 = Legendary - RarityCount: 0.30, Value: 1.00

			for (int32 i = 0; i < 6; i++)
			{
				float RarityCountXY;
				UDataTableFunctionLibrary::EvaluateCurveTableRow(VendingMachineRarityCount.Curve.CurveTable, VendingMachineRarityCount.Curve.RowName, i, &Result, &RarityCountXY, ContextString);

				RarityAndWeight[i] = (RarityCountXY * VendingMachineRarityCount.Value);
			}

			for (int32 i = 0; i < VendingMachines.Num(); i++)
			{
				ABuildingItemCollectorActor* VendingMachine = Cast<ABuildingItemCollectorActor>(VendingMachines[i]);
				if (!VendingMachine) continue;

				FillVendingMachine(VendingMachine, RarityAndWeight);
			}

			if (VendingMachines.Num() > 0)
				VendingMachines.Free();
		}
	}

	void InitializeTreasureChests()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState && GameState->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

			EEvaluateCurveTableResult OutResult;
			FString ContextString;

			float MinSpawnPercentXY; // 50%
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->TreasureChestMinSpawnPercent.Curve.CurveTable, MapInfo->TreasureChestMinSpawnPercent.Curve.RowName, 0.f, &OutResult, &MinSpawnPercentXY, ContextString);

			float MaxSpawnPercentXY; // 70%
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->TreasureChestMaxSpawnPercent.Curve.CurveTable, MapInfo->TreasureChestMaxSpawnPercent.Curve.RowName, 0.f, &OutResult, &MaxSpawnPercentXY, ContextString);

			TArray<AActor*> TreasureChests;
			UGameplayStatics::GetAllActorsOfClass(MapInfo, MapInfo->TreasureChestClass, &TreasureChests);

			int32 TotalTreasureChests = TreasureChests.Num();
			int32 MinTreasureChestsToKeep = UKismetMathLibrary::FFloor((TotalTreasureChests * (MinSpawnPercentXY / 100.f)) * MapInfo->TreasureChestMinSpawnPercent.Value);
			int32 MaxTreasureChestsToKeep = UKismetMathLibrary::FFloor((TotalTreasureChests * (MaxSpawnPercentXY / 100.f)) * MapInfo->TreasureChestMaxSpawnPercent.Value);

			int32 NumTreasureChestsToKeep = UKismetMathLibrary::RandomIntegerInRange(MinTreasureChestsToKeep, MaxTreasureChestsToKeep);

			for (int32 i = TotalTreasureChests - 1; i >= NumTreasureChestsToKeep; --i)
			{
				int32 IndexToDestroy = UKismetMathLibrary::RandomIntegerInRange(0, i);

				TreasureChests[IndexToDestroy]->K2_DestroyActor();
				TreasureChests.Remove(IndexToDestroy);
			}

			if (TreasureChests.Num() > 0)
				TreasureChests.Free();
		}
	}

	void InitializeAmmoBoxs()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState && GameState->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

			EEvaluateCurveTableResult OutResult;
			FString ContextString;

			float MinSpawnPercentXY; // 65%
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->AmmoBoxMinSpawnPercent.Curve.CurveTable, MapInfo->AmmoBoxMinSpawnPercent.Curve.RowName, 0.f, &OutResult, &MinSpawnPercentXY, ContextString);

			float MaxSpawnPercentXY; // 80%
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->AmmoBoxMaxSpawnPercent.Curve.CurveTable, MapInfo->AmmoBoxMaxSpawnPercent.Curve.RowName, 0.f, &OutResult, &MaxSpawnPercentXY, ContextString);

			TArray<AActor*> AmmoBoxs;
			UGameplayStatics::GetAllActorsOfClass(MapInfo, MapInfo->AmmoBoxClass, &AmmoBoxs);

			int32 TotalAmmoBoxs = AmmoBoxs.Num();
			int32 MinAmmoBoxsToKeep = UKismetMathLibrary::FFloor((TotalAmmoBoxs * (MinSpawnPercentXY / 100.f)) * MapInfo->AmmoBoxMinSpawnPercent.Value);
			int32 MaxAmmoBoxsToKeep = UKismetMathLibrary::FFloor((TotalAmmoBoxs * (MaxSpawnPercentXY / 100.f)) * MapInfo->AmmoBoxMaxSpawnPercent.Value);

			int32 NumAmmoBoxsToKeep = UKismetMathLibrary::RandomIntegerInRange(MinAmmoBoxsToKeep, MaxAmmoBoxsToKeep);

			for (int32 i = TotalAmmoBoxs - 1; i >= NumAmmoBoxsToKeep; --i)
			{
				int32 IndexToDestroy = UKismetMathLibrary::RandomIntegerInRange(0, i);

				AmmoBoxs[IndexToDestroy]->K2_DestroyActor();
				AmmoBoxs.Remove(IndexToDestroy);
			}

			if (AmmoBoxs.Num() > 0)
				AmmoBoxs.Free();
		}
	}

	void InitializeLlamas()
	{
		return;

		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState && GameState->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

			EEvaluateCurveTableResult OutResult;
			FString ContextString;

			float QuantityMinXY; // 3
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->LlamaQuantityMin.Curve.CurveTable, MapInfo->LlamaQuantityMin.Curve.RowName, 0.f, &OutResult, &QuantityMinXY, ContextString);

			float QuantityMaxXY; // 3
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->LlamaQuantityMax.Curve.CurveTable, MapInfo->LlamaQuantityMax.Curve.RowName, 0.f, &OutResult, &QuantityMaxXY, ContextString);

			const int32 QuantityMinToSpawn = UKismetMathLibrary::FFloor(QuantityMinXY * MapInfo->LlamaQuantityMin.Value);
			const int32 QuantityMaxToSpawn = UKismetMathLibrary::FFloor(QuantityMaxXY * MapInfo->LlamaQuantityMax.Value);
			
			int32 QuantityNumToSpawn = UKismetMathLibrary::RandomIntegerInRange(QuantityMinToSpawn, QuantityMaxToSpawn);

			// or try AFortAthenaSupplyDrop::GetSupplyDropSpawnData(float* MinSpawnHeight, float* MaxSpawnHeight);

			float MinPlacementHeightXY;
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->SupplyDropMinPlacementHeight.Curve.CurveTable, MapInfo->SupplyDropMinPlacementHeight.Curve.RowName, 0, &OutResult, &MinPlacementHeightXY, ContextString);

			float MaxPlacementHeightXY;
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->SupplyDropMaxPlacementHeight.Curve.CurveTable, MapInfo->SupplyDropMaxPlacementHeight.Curve.RowName, 0, &OutResult, &MaxPlacementHeightXY, ContextString);

			const float MinPlacementHeight = MinPlacementHeightXY * MapInfo->SupplyDropMinPlacementHeight.Value;
			const float MaxPlacementHeight = MaxPlacementHeightXY * MapInfo->SupplyDropMaxPlacementHeight.Value;

			TSubclassOf<AFortAthenaSupplyDrop> LlamaClass = MapInfo->LlamaClass;

			QuantityNumToSpawn = 1000;

			int32 Recurcives = 0;
			for (int32 i = 0; i < QuantityNumToSpawn; i++)
			{
				FVector SpawnCenter = FVector(1, 1, 10000);

				FVector SpawnLocation = FVector(0, 0, 0);
				PickSupplyDropLocation(MapInfo, &SpawnLocation, &SpawnCenter, 100000.0f);

				FN_LOG(LogFunctions, Log, "%i - PickSupplyDropLocation - SpawnLocation: [X: %.2f, Y: %.2f, Z: %.2f]", i, SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);

				if (SpawnLocation.IsZero())
				{
					if (Recurcives >= 100)
						break;

					QuantityNumToSpawn++;
					Recurcives++;
				}

				FRotator SpawnRotation = FRotator(0, 0, 0);
				SpawnRotation.Yaw = UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f);

				SpawnSupplyDrop(MapInfo, SpawnLocation, SpawnRotation, LlamaClass, MaxPlacementHeight, MinPlacementHeight);
			}
		}
	}

	void SetPlaylistData(AFortGameModeAthena* GameModeAthena, UFortPlaylistAthena* PlaylistAthena)
	{
		if (!GameModeAthena || !PlaylistAthena)
			return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameStateAthena)
		{
			// 7FF66F2504C0
			void (*SetCurrentPlaylistId)(AFortGameModeAthena* GameModeAthena, int32 NewPlaylistId) = decltype(SetCurrentPlaylistId)(0xC004C0 + uintptr_t(GetModuleHandle(0)));
			SetCurrentPlaylistId(GameModeAthena, PlaylistAthena->PlaylistId);

			GameStateAthena->CurrentPlaylistData = PlaylistAthena;
			GameStateAthena->OnRep_CurrentPlaylistData();

			GameStateAthena->AirCraftBehavior = PlaylistAthena->AirCraftBehavior;

			GameModeAthena->AISettings = PlaylistAthena->AISettings;

			AFortGameSession* GameSession = GameModeAthena->FortGameSession;

			if (GameSession)
			{
				GameSession->MaxPlayers = PlaylistAthena->MaxPlayers;
				GameSession->MaxPartySize = PlaylistAthena->MaxSocialPartySize;

				GameSession->SessionName = UKismetStringLibrary::Conv_StringToName(L"OdysseySession");
			}
		}
	}

	bool HasGameplayTags(TArray<FGameplayTag> GameplayTags, FName TagNameRequired)
	{
		const FString& TagNameRequiredString = UKismetStringLibrary::Conv_NameToString(TagNameRequired);
		const FString& TagNameRequiredLower = UKismetStringLibrary::ToLower(TagNameRequiredString);

		for (int32 j = 0; j < GameplayTags.Num(); j++)
		{
			FGameplayTag GameplayTag = GameplayTags[j];

			FName TagName = GameplayTag.TagName;
			if (!TagName.IsValid()) continue;

			const FString& TagNameString = UKismetStringLibrary::Conv_NameToString(TagName);
			const FString& TagNameLower = UKismetStringLibrary::ToLower(TagNameString);

			if (TagNameLower == TagNameRequiredLower)
				return true;
		}

		return false;
	}

	TArray<UFortItemDefinition*> PickOnlyAthena(TArray<UFortItemDefinition*> AllItems)
	{
		static TArray<UFortItemDefinition*> AllAthenaItems;

		if (AllAthenaItems.Num() > 0)
			return AllAthenaItems;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortItemDefinition* ItemDefinition = AllItems[i];

			if (!ItemDefinition)
				continue;

			const FString& PathName = UKismetSystemLibrary::GetPathName(ItemDefinition);

			if (!PathName.ToString().contains("/Game/Athena/Items"))
				continue;

			AllAthenaItems.Add(ItemDefinition);
		}

		return AllAthenaItems;
	}

	TArray<UFortItemDefinition*> GetAllItems(bool bOnlyAthena = false)
	{
		static TArray<UFortItemDefinition*> AllItems;

		if (AllItems.Num() > 0)
			return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;

		for (int32 i = 0; i < UObject::GObjects->Num(); i++)
		{
			UObject* GObject = UObject::GObjects->GetByIndex(i);

			if (!GObject)
				continue;

			if (GObject->IsA(UFortItemDefinition::StaticClass()))
			{
				UFortItemDefinition* ItemDefinition = Cast<UFortItemDefinition>(GObject);
				if (!ItemDefinition) continue;

				AllItems.Add(ItemDefinition);
			}
		}

		return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;
	}

	TArray<UFortWorldItemDefinition*> GetAllItemsWithClass(bool bOnlyAthena, UClass* Class)
	{
		TArray<UFortItemDefinition*> AllItems = GetAllItems(bOnlyAthena);
		TArray<UFortWorldItemDefinition*> AllItemsWithClass;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortItemDefinition* ItemDefinition = AllItems[i];

			if (!ItemDefinition)
				continue;

			if (ItemDefinition->IsA(Class))
			{
				UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(ItemDefinition);
				if (!WorldItemDefinition) continue;

				AllItemsWithClass.Add(WorldItemDefinition);
			}
		}

		return AllItemsWithClass;
	}

	TArray<UFortWeaponItemDefinition*> GetAllItemsWithTag(const FName& TagNameRequired, TArray<UFortWorldItemDefinition*> BlackListWorldItemDefinitions, TArray<EFortRarity> BlackListRaritys, TArray<EFortItemType> BlackListItemTypes)
	{
		TArray<UFortItemDefinition*> AllItems = GetAllItems(true);
		TArray<UFortWeaponItemDefinition*> AllItemsWithTag;

		if (!TagNameRequired.IsValid())
			return AllItemsWithTag;

		for (int32 i = 0; i < AllItems.Num(); i++)
		{
			UFortWeaponItemDefinition* WeaponRangedItemDefinition = Cast<UFortWeaponItemDefinition>(AllItems[i]);
			if (!WeaponRangedItemDefinition) continue;

			bool bBlacklistItem = false;
			for (int32 j = 0; j < BlackListWorldItemDefinitions.Num(); j++)
			{
				UFortWorldItemDefinition* BlackListWorldItemDefinition = BlackListWorldItemDefinitions[j];
				if (!BlackListWorldItemDefinition) continue;

				if (BlackListWorldItemDefinition == WeaponRangedItemDefinition)
				{
					bBlacklistItem = true;
					break;
				}
			}

			if (bBlacklistItem)
				continue;

			bool bBlackListRariry = false;
			for (int32 j = 0; j < BlackListRaritys.Num(); j++)
			{
				EFortRarity BlackListRarity = BlackListRaritys[j];

				if (BlackListRarity == WeaponRangedItemDefinition->Rarity)
				{
					bBlackListRariry = true;
					break;
				}
			}

			if (bBlackListRariry)
				continue;

			bool bBlackListItemType = false;
			for (int32 j = 0; j < BlackListItemTypes.Num(); j++)
			{
				EFortItemType BlackListItemType = BlackListItemTypes[j];

				if (BlackListItemType == WeaponRangedItemDefinition->ItemType)
				{
					bBlackListItemType = true;
					break;
				}
			}

			if (bBlackListItemType)
				continue;

			TArray<FGameplayTag> GameplayTags = WeaponRangedItemDefinition->GameplayTags.GameplayTags;

			const FString& TagNameRequiredString = UKismetStringLibrary::Conv_NameToString(TagNameRequired);
			const FString& TagNameRequiredLower = UKismetStringLibrary::ToLower(TagNameRequiredString);

			bool bFindTagName = false;
			for (int32 j = 0; j < GameplayTags.Num(); j++)
			{
				FGameplayTag GameplayTag = GameplayTags[j];

				FName TagName = GameplayTag.TagName;
				if (!TagName.IsValid()) continue;

				const FString& TagNameString = UKismetStringLibrary::Conv_NameToString(TagName);
				const FString& TagNameLower = UKismetStringLibrary::ToLower(TagNameString);

				if (TagNameLower == TagNameRequiredLower)
				{
					bFindTagName = true;
					break;
				}
			}

			if (!bFindTagName)
				continue;

			AllItemsWithTag.Add(WeaponRangedItemDefinition);
		}

		return AllItemsWithTag;
	}

	UFortWeaponItemDefinition* ChooseRandomItemWithFilter(const FName& TagNameRequired, TArray<UFortWorldItemDefinition*> BlackListWorldItemDefinitions = {}, TArray<EFortRarity> BlackListRarity = {}, TArray<EFortItemType> BlackListItemTypes = {})
	{
		TArray<UFortWeaponItemDefinition*> AllItemsWithTag = GetAllItemsWithTag(TagNameRequired, BlackListWorldItemDefinitions, BlackListRarity, BlackListItemTypes);
		return AllItemsWithTag[std::rand() % AllItemsWithTag.Num()];
	}

#ifdef SIPHON
	void ApplySiphonEffect(AFortPlayerState* PlayerState)
	{
		if (PlayerState)
		{
			UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

			if (AbilitySystemComponent)
			{
				FGameplayTag GameplayTag = FGameplayTag();
				GameplayTag.TagName = UKismetStringLibrary::Conv_StringToName(L"GameplayCue.Shield.PotionConsumed");

				AbilitySystemComponent->NetMulticast_InvokeGameplayCueAdded(GameplayTag, FPredictionKey(), FGameplayEffectContextHandle());
				AbilitySystemComponent->NetMulticast_InvokeGameplayCueExecuted(GameplayTag, FPredictionKey(), FGameplayEffectContextHandle());
			}
		}
	}

	void GiveSiphonBonus(AFortPlayerController* PlayerController, AFortPawn* Pawn, bool bGiveBuildingResource = true, bool bHealPlayer = true)
	{
		if (PlayerController)
		{
			if (bGiveBuildingResource)
			{
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Wood, 50);
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Stone, 50);
				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Metal, 50);
			}

			if (bHealPlayer)
			{
				float MaxHealth = Pawn->GetMaxHealth();
				float MaxShield = Pawn->GetMaxShield();

				float Health = Pawn->GetHealth();
				float Shield = Pawn->GetShield();

				float SiphonAmount = 50.0f;
				float RemainingSiphonAmount = SiphonAmount;

				if (Health < MaxHealth)
				{
					float NewHealth = UKismetMathLibrary::Clamp(Health + SiphonAmount, 0.0f, MaxHealth);

					Pawn->SetHealth(NewHealth);

					RemainingSiphonAmount -= (NewHealth - Health);
				}

				if (RemainingSiphonAmount > 0.0f)
				{
					float NewShield = UKismetMathLibrary::Clamp(Shield + RemainingSiphonAmount, 0.0f, MaxShield);

					Pawn->SetShield(NewShield);
				}
			}

			AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);

			if (PlayerState)
			{
				ApplySiphonEffect(PlayerState);
			}
		}
	}
#endif // SIPHON

#ifdef LATEGAME
	void GiveLateGameInventory(AFortPlayerController* PlayerController)
	{
		UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Wood, 500);
		UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Stone, 300);
		UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Metal, 150);

		// Give All Ammos
		{
			TArray<UFortWorldItemDefinition*> AllAmmoItems = Functions::GetAllItemsWithClass(true, UFortAmmoItemDefinition::StaticClass());

			for (int32 i = 0; i < AllAmmoItems.Num(); i++)
			{
				UFortAmmoItemDefinition* AmmoItemDefinition = Cast<UFortAmmoItemDefinition>(AllAmmoItems[i]);
				if (!AmmoItemDefinition) continue;

				if (!AmmoItemDefinition->bCanBeDropped)
					continue;

				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, AmmoItemDefinition, ((AmmoItemDefinition->MaxStackSize / 4) + 1), false);
			}
		}

		// Assault Weapon
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Assault");

			TArray<EFortRarity> BlackListRarity;
			BlackListRarity.Add(EFortRarity::Handmade);
			BlackListRarity.Add(EFortRarity::Ordinary);

			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired, {}, BlackListRarity);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, RandomItemWithTag->MaxStackSize, false);

			if (BlackListRarity.IsValid())
				BlackListRarity.Free();
		}

		// Shotgun Weapon
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Shotgun");

			TArray<EFortRarity> BlackListRarity;
			BlackListRarity.Add(EFortRarity::Handmade);
			BlackListRarity.Add(EFortRarity::Ordinary);

			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired, {}, BlackListRarity);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, RandomItemWithTag->MaxStackSize, false);

			if (BlackListRarity.IsValid())
				BlackListRarity.Free();
		}

		// Smg Weapon
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Smg");

			TArray<EFortRarity> BlackListRarity;
			BlackListRarity.Add(EFortRarity::Handmade);
			BlackListRarity.Add(EFortRarity::Ordinary);

			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired, {}, BlackListRarity);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, RandomItemWithTag->MaxStackSize, false);

			if (BlackListRarity.IsValid())
				BlackListRarity.Free();
		}

		// Heal Weapon
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Athena.ItemAction.Consume");

			TArray<EFortRarity> BlackListRarity;
			BlackListRarity.Add(EFortRarity::Quality);
			BlackListRarity.Add(EFortRarity::Fine);

			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired, {}, BlackListRarity);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, RandomItemWithTag->MaxStackSize, false);

			if (BlackListRarity.IsValid())
				BlackListRarity.Free();
		}

		// Rota/Sniper Weapon
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Sniper"); // UKismetMathLibrary::RandomBool() ? UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Sniper") : UKismetStringLibrary::Conv_StringToName(L"Weapon.Ranged.Heavy.Grenade");
			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, RandomItemWithTag->MaxStackSize, false);
		}

		// Trap
		{
			const FName& TagNameRequired = UKismetStringLibrary::Conv_StringToName(L"Bacchus.Place.Trap.Damage");
			UFortWeaponItemDefinition* RandomItemWithTag = Functions::ChooseRandomItemWithFilter(TagNameRequired);

			if (RandomItemWithTag)
				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, RandomItemWithTag, 3, false);
		}
	}

	void StartSafeZone(AFortGameModeAthena* GameModeAthena)
	{
		if (!GameModeAthena)
			return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameStateAthena)
		{
			// 7FF66F254FC0
			bool (*StartSafeZonesPhase)(AFortGameModeAthena* GameModeAthena, bool a2) = decltype(StartSafeZonesPhase)(0xC04FC0 + uintptr_t(GetModuleHandle(0)));

			// 7FF66F254C70
			bool (*sub_7FF66F254C70)(AFortGameModeAthena* GameModeAthena, bool a2, bool a3) = decltype(sub_7FF66F254C70)(0xC04C70 + uintptr_t(GetModuleHandle(0)));
			sub_7FF66F254C70(GameModeAthena, true, true);

			GameStateAthena->SafeZonesStartTime = 0.0f;
		}
	}

	void InitLateGameSafeZone(AFortGameModeAthena* GameModeAthena)
	{
		if (!GameModeAthena)
			return;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameStateAthena)
		{
			StartSafeZone(GameModeAthena);
		}
	}
#endif // LATEGAME

	void InitFunctions()
	{
		uintptr_t AddressGetWorldFromContextObject = MinHook::FindPattern(Patterns::GetWorldFromContextObject);
		uintptr_t AddressSpawnSupplyDrop = MinHook::FindPattern(Patterns::SpawnSupplyDrop);
		uintptr_t AddressPickSupplyDropLocation = MinHook::FindPattern(Patterns::PickSupplyDropLocation);

		GetWorldFromContextObject = decltype(GetWorldFromContextObject)(AddressGetWorldFromContextObject);
		SpawnSupplyDrop = decltype(SpawnSupplyDrop)(AddressSpawnSupplyDrop);
		PickSupplyDropLocation = decltype(PickSupplyDropLocation)(AddressPickSupplyDropLocation);

		FN_LOG(LogInit, Log, "InitFunctions Success!");
	}
}