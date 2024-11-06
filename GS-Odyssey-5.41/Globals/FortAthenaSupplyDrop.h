#pragma once

namespace FortAthenaSupplyDrop
{
	/* ----------------------------------- AFortAthenaSupplyDropOG ----------------------------------- */



	/* ------------------------------------ AFortAthenaSupplyDrop ------------------------------------ */

	AFortPickup* SpawnPickup(AFortAthenaSupplyDrop* SupplyDrop, FFrame& Stack, AFortPickup** Ret)
	{
		UFortWorldItemDefinition* ItemDefinition = nullptr;
		int32 NumberToSpawn = 1;
		AFortPawn* TriggeringPawn = nullptr;
		FVector Position = FVector();
		FVector Direction = FVector();

		Stack.StepCompiledIn(&ItemDefinition);
		Stack.StepCompiledIn(&NumberToSpawn);
		Stack.StepCompiledIn(&TriggeringPawn);
		Stack.StepCompiledIn(&Position);
		Stack.StepCompiledIn(&Direction);

		Stack.Code += Stack.Code != nullptr;

		UWorld* World = GEngine->GetWorldFromContextObject(SupplyDrop, EGetWorldErrorMode::LogAndReturnNull);

		if (!World || !ItemDefinition || (NumberToSpawn < 1))
		{
			*Ret = nullptr;
			return *Ret;
		}

		FFortItemEntry ItemEntry;
		Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, -1.0f);

		FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
		CreatePickupData.World = World;
		CreatePickupData.ItemEntry = &ItemEntry;
		CreatePickupData.SpawnLocation = &Position;
		CreatePickupData.SpawnRotation = nullptr;
		CreatePickupData.PlayerController = nullptr;
		CreatePickupData.OverrideClass = nullptr;
		CreatePickupData.NullptrIdk = nullptr;
		CreatePickupData.bRandomRotation = true;
		CreatePickupData.PickupSourceTypeFlags = 0;

		AFortPickup* Pickup = AFortPickup::CreatePickupFromData(&CreatePickupData);

		if (Pickup)
		{
			FRotator PlayerRotation = SupplyDrop->K2_GetActorRotation();
			PlayerRotation.Yaw += UKismetMathLibrary::RandomFloatInRange(-180.0f, 180.0f);

			float RandomDistance = UKismetMathLibrary::RandomFloatInRange(350.0f, 700.0f);
			FVector FinalDirection = UKismetMathLibrary::GetForwardVector(PlayerRotation);

			FVector FinalLocation = Position + FinalDirection * RandomDistance;

			Pickup->TossPickup(FinalLocation, nullptr, 0, true);
		}

		ItemEntry.FreeItemEntry();

		*Ret = Pickup;
		return *Ret;
	}

	void InitFortAthenaSupplyDrop()
	{
		AFortAthenaSupplyDrop* FortAthenaSupplyDropDefault = AFortAthenaSupplyDrop::GetDefaultObj();

		/* ------------------------------------ AFortAthenaSupplyDrop ------------------------------------ */

		UFunction* SpawnPickupFunc = AFortAthenaSupplyDrop::StaticClass()->GetFunction("FortAthenaSupplyDrop", "SpawnPickup");
		MinHook::HookFunctionExec(SpawnPickupFunc, SpawnPickup, nullptr);

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, "FortAthenaSupplyDrop Success!");
	}
}