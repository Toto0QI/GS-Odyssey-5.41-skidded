#pragma once
#include <map>

namespace Functions
{
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
			Globals::GetGameplayStatics()->GetAllActorsOfClass(Globals::GetWorld(), FloorLootClass, &FloorLootsResult);

			TArray<AActor*> FloorLootWarmupResult;
			Globals::GetGameplayStatics()->GetAllActorsOfClass(Globals::GetWorld(), FloorLootWarmupClass, &FloorLootWarmupResult);

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
			Globals::GetGameplayStatics()->GetAllActorsOfClass(Globals::GetWorld(), MapInfo->VendingMachineClass, &VendingMachines);

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
				Globals::GetFunctionLibrary()->EvaluateCurveTableRow(VendingMachineRarityCount.Curve.CurveTable, VendingMachineRarityCount.Curve.RowName, i, &Result, &RarityCountXY, ContextString);

				FN_LOG(LogFunctions, Debug, "[%i] - RarityCount: %.2f, Value: %.2f", i, RarityCountXY, VendingMachineRarityCount.Value);

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

				FN_LOG(LogFunctions, Debug, "[%i] - VendingMachine: %s, RandomRarity: %i, LootTierGroup: %s", i, VendingMachine->GetName().c_str(), RandomRarity, LootTierGroup.ToString().c_str());
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

			float MinSpawnPercent; // 50%
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->TreasureChestMinSpawnPercent.Curve.CurveTable, MapInfo->TreasureChestMinSpawnPercent.Curve.RowName, 0.f, &OutResult, &MinSpawnPercent, ContextString);

			float MaxSpawnPercent; // 70%
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->TreasureChestMaxSpawnPercent.Curve.CurveTable, MapInfo->TreasureChestMaxSpawnPercent.Curve.RowName, 0.f, &OutResult, &MaxSpawnPercent, ContextString);

			TArray<AActor*> TreasureChests;
			Globals::GetGameplayStatics()->GetAllActorsOfClass(Globals::GetWorld(), MapInfo->TreasureChestClass, &TreasureChests);

			UKismetMathLibrary* MathLibrary = Globals::GetMathLibrary();

			int32 TotalTreasureChests = TreasureChests.Num();
			int32 MinTreasureChestsToKeep = MathLibrary->FFloor((TotalTreasureChests * (MinSpawnPercent / 100.f)) * MapInfo->TreasureChestMinSpawnPercent.Value);
			int32 MaxTreasureChestsToKeep = MathLibrary->FFloor((TotalTreasureChests * (MaxSpawnPercent / 100.f)) * MapInfo->TreasureChestMaxSpawnPercent.Value);

			int32 NumTreasureChestsToKeep = MathLibrary->RandomIntegerInRange(MinTreasureChestsToKeep, MaxTreasureChestsToKeep);

			for (int32 i = TotalTreasureChests - 1; i >= NumTreasureChestsToKeep; --i)
			{
				int32 IndexToDestroy = MathLibrary->RandomIntegerInRange(0, i);

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

			float MinSpawnPercent; // 65%
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->AmmoBoxMinSpawnPercent.Curve.CurveTable, MapInfo->AmmoBoxMinSpawnPercent.Curve.RowName, 0.f, &OutResult, &MinSpawnPercent, ContextString);

			float MaxSpawnPercent; // 80%
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->AmmoBoxMaxSpawnPercent.Curve.CurveTable, MapInfo->AmmoBoxMaxSpawnPercent.Curve.RowName, 0.f, &OutResult, &MaxSpawnPercent, ContextString);

			TArray<AActor*> AmmoBoxs;
			Globals::GetGameplayStatics()->GetAllActorsOfClass(Globals::GetWorld(), MapInfo->AmmoBoxClass, &AmmoBoxs);

			UKismetMathLibrary* MathLibrary = Globals::GetMathLibrary();

			int32 TotalAmmoBoxs = AmmoBoxs.Num();
			int32 MinAmmoBoxsToKeep = MathLibrary->FFloor((TotalAmmoBoxs * (MinSpawnPercent / 100.f)) * MapInfo->AmmoBoxMinSpawnPercent.Value);
			int32 MaxAmmoBoxsToKeep = MathLibrary->FFloor((TotalAmmoBoxs * (MaxSpawnPercent / 100.f)) * MapInfo->AmmoBoxMaxSpawnPercent.Value);

			int32 NumAmmoBoxsToKeep = MathLibrary->RandomIntegerInRange(MinAmmoBoxsToKeep, MaxAmmoBoxsToKeep);

			for (int32 i = TotalAmmoBoxs - 1; i >= NumAmmoBoxsToKeep; --i)
			{
				int32 IndexToDestroy = MathLibrary->RandomIntegerInRange(0, i);

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

			float QuantityMin;
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->LlamaQuantityMin.Curve.CurveTable, MapInfo->LlamaQuantityMin.Curve.RowName, 0.f, &OutResult, &QuantityMin, ContextString);

			float QuantityMax;
			Globals::GetFunctionLibrary()->EvaluateCurveTableRow(MapInfo->LlamaQuantityMax.Curve.CurveTable, MapInfo->LlamaQuantityMax.Curve.RowName, 0.f, &OutResult, &QuantityMax, ContextString);

			UKismetMathLibrary* MathLibrary = Globals::GetMathLibrary();

			int32 QuantityMinToSpawn = MathLibrary->FFloor(QuantityMin * MapInfo->LlamaQuantityMin.Value);
			int32 QuantityMaxToSpawn = MathLibrary->FFloor(QuantityMax * MapInfo->LlamaQuantityMax.Value);

			int32 QuantityNumToSpawn = MathLibrary->RandomIntegerInRange(QuantityMinToSpawn, QuantityMaxToSpawn);

			TSubclassOf<AFortAthenaSupplyDrop> LlamaClass = MapInfo->LlamaClass;

			int32 Recurcives = 0;

			// QuantityNumToSpawn = 50000;

			for (int32 i = 0; i < QuantityNumToSpawn; i++)
			{
				FVector Location = FVector(0, 0, 10000);

				Location.X = Globals::GetMathLibrary()->RandomFloatInRange(-100000.f, 100000.f);
				Location.Y = Globals::GetMathLibrary()->RandomFloatInRange(-100000.f, 100000.f);

				AFortAthenaSupplyDrop* LlamaForLocation = Util::SpawnActor<AFortAthenaSupplyDrop>(LlamaClass, Location, FRotator());

				if (!LlamaForLocation)
					continue;

				FVector FinalLocation = LlamaForLocation->FindGroundLocationAt(Location);

				LlamaForLocation->K2_DestroyActor();

				if (FinalLocation.Z == 10000 || FinalLocation.Z <= 0)
				{
					if (Recurcives > 500)
						break;

					Recurcives++;
					QuantityNumToSpawn++;
					continue;
				}

				FN_LOG(LogFunctions, Log, "FinalLocation: X: %.2f Y: %.2f Z: %.2f", FinalLocation.X, FinalLocation.Y, FinalLocation.Z);

				Util::SpawnActor<AFortAthenaSupplyDrop>(LlamaClass, FinalLocation, FRotator());
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

			const FString& PathName = Globals::GetSystemLibrary()->GetPathName(ItemDefinition);

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

		GetWorldFromContextObject = decltype(GetWorldFromContextObject)(AddressGetWorldFromContextObject);

		FN_LOG(LogInit, Log, "InitFunctions Success!");
	}
}