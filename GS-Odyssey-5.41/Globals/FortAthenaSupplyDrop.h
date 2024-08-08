#pragma once

namespace FortAthenaSupplyDrop
{
	void (*SpawningLootOnDestruction)(AFortAthenaSupplyDrop* SupplyDrop, AController* EventInstigator);

	void SpawningLootOnDestructionHook(AFortAthenaSupplyDrop* SupplyDrop, AController* EventInstigator)
	{
		if (!SupplyDrop)
		{
			FN_LOG(LogAthenaSupplyDrop, Error, "[AFortAthenaSupplyDrop::SpawningLootOnDestruction] failed to get SupplyDrop!");
			return;
		}

		FN_LOG(LogAthenaSupplyDrop, Debug, "[AFortAthenaSupplyDrop::SpawningLootOnDestruction] called!");

		AFortGameStateAthena* GameState = Globals::GetGameState();

		if (GameState && GameState->MapInfo)
		{
			AFortAthenaMapInfo* MapInfo = GameState->MapInfo;

			if (!SupplyDrop->IsA(MapInfo->LlamaClass))
			{
				FN_LOG(LogAthenaSupplyDrop, Error, "[AFortAthenaSupplyDrop::SpawningLootOnDestruction] SupplyDrop is not a LlamaClass!");
				return;
			}

			const FName SearchLootTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaLlama");

			bool bSuccess;
			std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(SearchLootTierGroup, -1, &bSuccess);

			if (!bSuccess)
			{
				FN_LOG(LogPlayerController, Error, "[AFortAthenaSupplyDrop::SpawningLootOnDestruction] Failed to get LootToDrops!");
				return;
			}

			for (auto& LootToDrop : LootToDrops)
				UFortKismetLibrary::K2_SpawnPickupInWorld(SupplyDrop, (UFortWorldItemDefinition*)LootToDrop.ItemDefinition, LootToDrop.Count, SupplyDrop->K2_GetActorLocation(), FVector(), 0, true, true, false);
		}

		SpawningLootOnDestruction(SupplyDrop, EventInstigator);
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (!Object->IsA(AFortAthenaSupplyDrop::StaticClass()))
			return;

		if (FunctionName.contains("SpawnPickup"))
		{
			AFortAthenaSupplyDrop* SupplyDrop = (AFortAthenaSupplyDrop*)Object;
			auto Params = (Params::FortAthenaSupplyDrop_SpawnPickup*)Parms;

			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;
			AFortPawn* TriggeringPawn = Params->TriggeringPawn;

			if (!SupplyDrop || !ItemDefinition || !TriggeringPawn)
			{
				FN_LOG(LogAthenaSupplyDrop, Error, "[AFortAthenaSupplyDrop::SpawnPickup] failed to get SupplyDrop!");
				return;
			}

			FN_LOG(LogAthenaSupplyDrop, Debug, "[AFortAthenaSupplyDrop::SpawnPickup] called!");

			int32 NumberToSpawn = Params->NumberToSpawn;

			const FVector& Position = Params->Position;
			const FVector& Direction = Params->Direction;

			UFortKismetLibrary::K2_SpawnPickupInWorld(SupplyDrop, ItemDefinition, NumberToSpawn, Position, Direction, 0, true, true, false);
		}
	}

	void InitFortAthenaSupplyDrop()
	{
		static auto FortAthenaSupplyDropDefault = AFortAthenaSupplyDrop::GetDefaultObj();

		uintptr_t AddressSpawningLootOnDestruction = MinHook::FindPattern(Patterns::SpawningLootOnDestruction);

		MH_CreateHook((LPVOID)(AddressSpawningLootOnDestruction), SpawningLootOnDestructionHook, (LPVOID*)(&SpawningLootOnDestruction));
		MH_EnableHook((LPVOID)(AddressSpawningLootOnDestruction));

		FN_LOG(LogInit, Log, "FortAthenaSupplyDrop Success!");
	}
}