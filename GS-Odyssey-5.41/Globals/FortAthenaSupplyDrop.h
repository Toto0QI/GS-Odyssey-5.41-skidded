#pragma once

struct AthenaSupplyDrop_Llama_C_GetLootSpawnLocation final
{
public:
	struct FVector                                LootSpawnLocation;                                 // 0x0000(0x000C)(Parm, OutParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_RandomFloatInRange_ReturnValue;           // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetComponentLocation_ReturnValue;      // 0x0010(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_RandomUnitVector_ReturnValue;             // 0x001C(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Multiply_VectorFloat_ReturnValue;         // 0x0028(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue;             // 0x0034(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue1;            // 0x0040(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

namespace FortAthenaSupplyDrop
{
	void (*SpawningLootOnDestruction)(AFortAthenaSupplyDrop* SupplyDrop, AController* EventInstigator);

	void SpawningLootOnDestructionHook(AFortAthenaSupplyDrop* SupplyDrop, AController* EventInstigator)
	{
		UFunction* GetLootSpawnLocationFunc = nullptr;

		if (GetLootSpawnLocationFunc == nullptr)
			GetLootSpawnLocationFunc = SupplyDrop->Class->GetFunction("AthenaSupplyDrop_Llama_C", "GetLootSpawnLocation");

		AthenaSupplyDrop_Llama_C_GetLootSpawnLocation GetLootSpawnLocationParms{};

		if (GetLootSpawnLocationFunc)
			SupplyDrop->ProcessEvent(GetLootSpawnLocationFunc, &GetLootSpawnLocationParms);

		FVector LootSpawnLocation = std::move(GetLootSpawnLocationParms.LootSpawnLocation);

		int32 LootLevel = UFortKismetLibrary::GetLootLevel(SupplyDrop);

		TArray<FFortItemEntry> LootToDrops;
		bool bSuccess = UFortKismetLibrary::PickLootDrops(SupplyDrop, &LootToDrops, UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaLlama"), LootLevel, -1); // SupplyDrop->LootTableName

		if (!bSuccess)
		{
			FN_LOG(LogPlayerController, Error, "[AFortAthenaSupplyDrop::SpawningLootOnDestruction] Failed PickLootDrops!");
			return;
		}

		for (int32 i = 0; i < LootToDrops.Num(); i++)
		{
			FFortItemEntry LootToDrop = LootToDrops[i];
			UFortWorldItemDefinition* WorldItemDefinition = Cast<UFortWorldItemDefinition>(LootToDrop.ItemDefinition);
			if (!WorldItemDefinition) continue;

			FVector LootSpawnDirection = FVector({ 0, 0, 0 });
			SupplyDrop->SpawnPickup(WorldItemDefinition, LootToDrop.Count, nullptr, LootSpawnLocation, LootSpawnDirection);
		}

		SpawningLootOnDestruction(SupplyDrop, EventInstigator);
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms, bool* bCallOG)
	{
		if (!Object || !Function)
			return;

		if (!Object->IsA(AFortAthenaSupplyDrop::StaticClass()))
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("SpawnPickup"))
		{
			AFortAthenaSupplyDrop* SupplyDrop = (AFortAthenaSupplyDrop*)Object;
			auto Params = (Params::FortAthenaSupplyDrop_SpawnPickup*)Parms;

			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;
			AFortPawn* TriggeringPawn = Params->TriggeringPawn;

			if (!SupplyDrop || !ItemDefinition)
			{
				FN_LOG(LogAthenaSupplyDrop, Error, "[AFortAthenaSupplyDrop::SpawnPickup] failed to get SupplyDrop!");
				return;
			}

			int32 NumberToSpawn = Params->NumberToSpawn;

			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, 0.f);

			FVector Direction = Params->Direction;

			FVector SpawnLocation = Params->Position;
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
				Pickup->TossPickup(SpawnLocation, nullptr, 0, true);
			}

			Params->ReturnValue = Pickup;

			*bCallOG = false;
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