#pragma once
#include <map>

namespace Functions
{
	AFortAthenaSupplyDrop* (*SpawnSupplyDrop)(AFortAthenaMapInfo* MapInfo, const FVector& Location, const FRotator& Rotation, UClass* SupplyDropClass, float TraceStartZ, float TraceEndZ);
	UWorld* (*GetWorldFromContextObject)(UEngine* Engine, const UObject* Object, EGetWorldErrorMode ErrorMode);

	bool IsPlayerBuildableClasse(UClass* BuildableClasse)
	{
		AFortGameStateAthena* GameState = Globals::GetGameState();

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

			return false;
		}

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

	void SummonFloorLoots()
	{
		UBlueprintGeneratedClass* FloorLootClass = FindObjectFast<UBlueprintGeneratedClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");
		UBlueprintGeneratedClass* FloorLootWarmupClass = FindObjectFast<UBlueprintGeneratedClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_Warmup.Tiered_Athena_FloorLoot_Warmup_C");

		if (FloorLootClass && FloorLootWarmupClass)
		{
			TArray<AActor*> FloorLootsResult;
			UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), FloorLootClass, &FloorLootsResult);

			TArray<AActor*> FloorLootWarmupResult;
			UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), FloorLootWarmupClass, &FloorLootWarmupResult);

			TArray<AActor*> FloorLoots;

			for (int i = 0; i < FloorLootsResult.Num(); i++)
				FloorLoots.Add(FloorLootsResult[i]);

			if (FloorLootsResult.Num() > 0)
				FloorLootsResult.Free();

			for (int i = 0; i < FloorLootWarmupResult.Num(); i++)
				FloorLoots.Add(FloorLootWarmupResult[i]);

			if (FloorLootWarmupResult.Num() > 0)
				FloorLootWarmupResult.Free();

			for (int i = 0; i < FloorLoots.Num(); i++)
			{
				ABuildingContainer* FloorLoot = (ABuildingContainer*)FloorLoots[i];
				if (!FloorLoot) continue;

				bool bSuccess;
				std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(FloorLoot->SearchLootTierGroup, 0, &bSuccess);

				if (!bSuccess)
					continue;

				FVector FloorLootLoc = FloorLoot->K2_GetActorLocation();

				FloorLootLoc.Z += 50;

				for (auto& LootToDrop : LootToDrops)
				{
					if (LootToDrop.Count <= 0)
						continue;

					Inventory::SpawnPickup(nullptr, &LootToDrop, FloorLootLoc, true);
				}
			}

			FN_LOG(LogFunctions, Log, "Successful summon FloorLoots!");

			if (FloorLoots.Num() > 0)
				FloorLoots.Free();
		}
	}

	void FillVendingMachines()
	{
		AFortGameStateAthena* GameState = Globals::GetGameState();

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
				ABuildingItemCollectorActor* VendingMachine = (ABuildingItemCollectorActor*)VendingMachines[i];
				if (!VendingMachine) continue;

				int32 RandomRarity = GetRandomRarity(RarityAndWeight);

				if (RandomRarity == 0)
				{
					VendingMachine->K2_DestroyActor();
					continue;
				}

				// Get Real Rarity
				RandomRarity -= 1;

				// 0 = Common
				// 1 = UnCommon
				// 2 = Rare
				// 3 = Epic
				// 4 = Legendary

				// Loot_AthenaVending
				const FName& LootTierGroup = VendingMachine->DefaultItemLootTierGroupName;

				TArray<FColletorUnitInfo> ItemCollections = VendingMachine->ItemCollections;

				for (int32 j = 0; j < ItemCollections.Num(); j++)
				{
					FColletorUnitInfo ItemCollection = ItemCollections[j];

					UFortWorldItemDefinition* InputItem = ItemCollection.InputItem;
					if (!InputItem) continue;

					Retry:

					bool bSuccess;
					std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(LootTierGroup, RandomRarity, &bSuccess);

					if (!bSuccess)
					{
						FN_LOG(LogFunctions, Error, "Failed to get loot to drops at %i", j);
						continue;
					}

					for (int32 k = j; k >= 0; k--)
					{
						FColletorUnitInfo ItemCollectionCheck = ItemCollections[k];

						UFortWorldItemDefinition* InputItemCheck = ItemCollectionCheck.InputItem;
						if (!InputItemCheck) continue;

						if (!ItemCollections[j].OutputItemEntry.IsValid())
							continue;

						UFortItemDefinition* ItemDefinitionCheck = ItemCollections[j].OutputItemEntry[0].ItemDefinition;
						if (!ItemDefinitionCheck || !LootToDrops[0].ItemDefinition) continue;

						if (ItemDefinitionCheck == LootToDrops[0].ItemDefinition)
						{
							LootToDrops.clear();
							goto Retry;
						}
					}

					if (ItemCollections[j].OutputItemEntry.Num() > 0)
						ItemCollections[j].OutputItemEntry.Free();

					for (auto& LootToDrop : LootToDrops)
						ItemCollections[j].OutputItemEntry.Add(LootToDrop);
				}

				VendingMachine->StartingGoalLevel = RandomRarity;
			}

			if (VendingMachines.Num() > 0)
				VendingMachines.Free();
		}
	}

	void InitializeTreasureChests()
	{
		AFortGameStateAthena* GameState = Globals::GetGameState();

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
		AFortGameStateAthena* GameState = Globals::GetGameState();

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
		AFortGameStateAthena* GameState = Globals::GetGameState();

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

			float MinPlacementHeightXY;
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->SupplyDropMinPlacementHeight.Curve.CurveTable, MapInfo->SupplyDropMinPlacementHeight.Curve.RowName, 0, &OutResult, &MinPlacementHeightXY, ContextString);

			float MaxPlacementHeightXY;
			UDataTableFunctionLibrary::EvaluateCurveTableRow(MapInfo->SupplyDropMaxPlacementHeight.Curve.CurveTable, MapInfo->SupplyDropMaxPlacementHeight.Curve.RowName, 0, &OutResult, &MaxPlacementHeightXY, ContextString);

			const float MinPlacementHeight = MinPlacementHeightXY * MapInfo->SupplyDropMinPlacementHeight.Value;
			const float MaxPlacementHeight = MaxPlacementHeightXY * MapInfo->SupplyDropMaxPlacementHeight.Value;

			TSubclassOf<AFortAthenaSupplyDrop> LlamaClass = MapInfo->LlamaClass;

			int32 Recurcives = 0;

			QuantityNumToSpawn = 10000;

			for (int32 i = 0; i < QuantityNumToSpawn; i++)
			{
				FVector Location = FVector(0, 0, 10000);
			
				// Fortnite use SafeZone
				Location.X = Globals::GetMathLibrary()->RandomFloatInRange(-100000.f, 100000.f);
				Location.Y = Globals::GetMathLibrary()->RandomFloatInRange(-100000.f, 100000.f);

				FRotator Rotation = FRotator();

				// Random Rotation
				Rotation.Yaw = UKismetMathLibrary::RandomFloatInRange(0.f, 360.f);

				AFortAthenaSupplyDrop* Llama = SpawnSupplyDrop(MapInfo, Location, Rotation, LlamaClass, MaxPlacementHeight, MinPlacementHeight);

				if (!Llama || Llama->K2_GetActorLocation().Z <= 0)
				{
					if (Recurcives > 500)
						break;

					Recurcives++;
					QuantityNumToSpawn++;
					continue;
				}
			}
		}
	}

	TArray<UFortWorldItemDefinition*> PickOnlyAthena(TArray<UFortWorldItemDefinition*> AllItems)
	{
		static TArray<UFortWorldItemDefinition*> AllAthenaItems;

		if (AllAthenaItems.Num() > 0)
			return AllAthenaItems;

		for (int i = 0; i < AllItems.Num(); i++)
		{
			UFortWorldItemDefinition* ItemDefinition = AllItems[i];

			if (!ItemDefinition)
				continue;

			const FString& PathName = UKismetSystemLibrary::GetPathName(ItemDefinition);

			if (!PathName.ToString().contains("/Game/Athena/Items"))
				continue;

			AllAthenaItems.Add(ItemDefinition);
		}

		return AllAthenaItems;
	}

	TArray<UFortWorldItemDefinition*> GetAllItems(bool bOnlyAthena = false)
	{
		static TArray<UFortWorldItemDefinition*> AllItems;

		if (AllItems.Num() > 0)
			return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;

		for (int i = 0; i < UObject::GObjects->Num(); i++)
		{
			UObject* GObject = UObject::GObjects->GetByIndex(i);

			if (!GObject)
				continue;

			if (GObject->IsA(UFortWeaponRangedItemDefinition::StaticClass()) ||
				GObject->IsA(UFortAmmoItemDefinition::StaticClass()) ||
				GObject->IsA(UFortWeaponMeleeItemDefinition::StaticClass()) ||
				GObject->IsA(UFortResourceItemDefinition::StaticClass()) || 
				GObject->IsA(UFortContextTrapItemDefinition::StaticClass()) ||
				GObject->IsA(UFortTrapItemDefinition::StaticClass()))
			{
				UFortWorldItemDefinition* ItemDefinition = (UFortWorldItemDefinition*)GObject;
				if (!ItemDefinition) continue;

				AllItems.Add(ItemDefinition);
			}
		}

		return bOnlyAthena ? PickOnlyAthena(AllItems) : AllItems;
	}

	void InitFunctions()
	{
		uintptr_t AddressGetWorldFromContextObject = MinHook::FindPattern(Patterns::GetWorldFromContextObject);
		uintptr_t AddressSpawnSupplyDrop = MinHook::FindPattern(Patterns::SpawnSupplyDrop);

		GetWorldFromContextObject = decltype(GetWorldFromContextObject)(AddressGetWorldFromContextObject);
		SpawnSupplyDrop = decltype(SpawnSupplyDrop)(AddressSpawnSupplyDrop);

		FN_LOG(LogInit, Log, "InitFunctions Success!");
	}
}