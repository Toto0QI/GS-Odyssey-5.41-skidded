#pragma once

namespace FortKismetLibrary
{
	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("K2_GiveBuildingResource"))
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveBuildingResource*)Parms;

			AFortPlayerController* Controller = Params->Controller;

			if (!Controller)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_GiveBuildingResource] failed to get Controller!");
				return;
			}

			const EFortResourceType& ResourceType = Params->ResourceType;

			UFortResourceItemDefinition* ResourceItemDefinition = Globals::GetKismetLibrary()->K2_GetResourceItemDefinition(ResourceType);

			if (!ResourceItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_GiveBuildingResource] failed to get ResourceItemDefinition!");
				return;
			}

			int32 ResourceAmount = Params->ResourceAmount;

			UFortKismetLibrary::K2_GiveItemToPlayer(Controller, ResourceItemDefinition, ResourceAmount, true);
		}
		else if (FunctionName.contains("K2_GiveItemToAllPlayers"))
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveItemToAllPlayers*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (!WorldContextObject || !ItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_GiveItemToAllPlayers] failed to get WorldContextObject/ItemDefinition!");
				return;
			}

			TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

			int32 NumberToGive = Params->NumberToGive;
			bool bNotifyPlayer = Params->bNotifyPlayer;

			for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
			{
				AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
				if (!PlayerController) continue;

				UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, NumberToGive, bNotifyPlayer);
			}
		}
		else if (FunctionName.contains("K2_GiveItemToPlayer"))
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveItemToPlayer*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (!PlayerController || !ItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_GiveItemToPlayer] failed to get PlayerController/ItemDefinition!");
				return;
			}

			int32 NumberToGive = Params->NumberToGive;
			bool bNotifyPlayer = Params->bNotifyPlayer;

			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToGive, -1, -1, 0.f);

			if (bNotifyPlayer && PlayerController->MyFortPawn)
			{
				AFortPickup* Pickup = Inventory::CreateSimplePickup(PlayerController, &ItemEntry, PlayerController->MyFortPawn->K2_GetActorLocation(), FRotator());

				if (!Pickup)
				{
					FN_LOG(LogInventory, Error, "[UFortKismetLibrary::K2_GiveItemToPlayer] failed to spawn Pickup!");
					return;
				}

				Pawn::SetPickupTarget(Pickup, PlayerController->MyFortPawn, -1.0f, FVector());
			}
			else
			{
				FGuid CurrentWeaponGuid;

				if (PlayerController->MyFortPawn)
					CurrentWeaponGuid = PlayerController->MyFortPawn->CurrentWeapon ? PlayerController->MyFortPawn->CurrentWeapon->ItemEntryGuid : FGuid();

				Inventory::AddInventoryItem(PlayerController, &ItemEntry, CurrentWeaponGuid);
			}
		}
		else if (FunctionName.contains("K2_RemoveItemFromAllPlayers"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromAllPlayers*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (!WorldContextObject || !ItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_GiveItemToAllPlayers] failed to get WorldContextObject/ItemDefinition!");
				return;
			}

			TArray<AFortPlayerController*> AllFortPlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

			int32 AmountToRemove = Params->AmountToRemove;

			for (int32 i = 0; i < AllFortPlayerControllers.Num(); i++)
			{
				AFortPlayerController* PlayerController = AllFortPlayerControllers[i];
				if (!PlayerController) continue;

				UFortKismetLibrary::K2_RemoveItemFromPlayer(PlayerController, ItemDefinition, AmountToRemove, true);
			}
		}
		else if (FunctionName.contains("K2_RemoveItemFromPlayerByGuid"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromPlayerByGuid*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;

			if (!PlayerController)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_RemoveItemFromPlayerByGuid] failed to get PlayerController!");
				return;
			}

			const FGuid& ItemGuid = Params->ItemGuid;

			UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, ItemGuid);

			if (ItemInstance)
			{
				int32 AmountToRemove = Params->AmountToRemove;

				bool bSuccess = Inventory::RemoveInventoryItem(PlayerController, ItemInstance->GetItemGuid(), AmountToRemove);

				if (bSuccess)
					Inventory::UpdateInventory(PlayerController->WorldInventory);
			}
		}
		else if (FunctionName.contains("K2_RemoveItemFromPlayer"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromPlayer*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (!PlayerController || !ItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_RemoveItemFromPlayer] failed to get PlayerController/ItemDefinition!");
				return;
			}

			UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, ItemDefinition);

			if (ItemInstance)
			{
				int32 AmountToRemove = Params->AmountToRemove;

				bool bSuccess = Inventory::RemoveInventoryItem(PlayerController, ItemInstance->GetItemGuid(), AmountToRemove);

				if (bSuccess)
					Inventory::UpdateInventory(PlayerController->WorldInventory);
			}
		}
		else if (FunctionName.contains("K2_SpawnPickupInWorld"))
		{
			auto Params = (Params::FortKismetLibrary_K2_SpawnPickupInWorld*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (!WorldContextObject || !ItemDefinition)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_SpawnPickupInWorld] failed to get WorldContextObject/ItemDefinition!");
				return;
			}

			int32 NumberToSpawn = Params->NumberToSpawn;

			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, NumberToSpawn, -1, -1, 0.f);

			const FVector& Position = Params->Position;
			const FVector& Direction = Params->Direction;

			AFortPickup* Pickup = Inventory::CreateSimplePickup(WorldContextObject, &ItemEntry, Position, FRotator());

			if (!Pickup)
			{
				FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_SpawnPickupInWorld] failed to spawn Pickup!");
				return;
			}

			int32 OverrideMaxStackCount = Params->OverrideMaxStackCount;
			bool bToss = Params->bToss;

			Pickup->TossPickup(Position, nullptr, OverrideMaxStackCount, bToss);

			bool bRandomRotation = Params->bRandomRotation;
			bool bBlockedFromAutoPickup = Params->bBlockedFromAutoPickup;

			Pickup->bRandomRotation = bRandomRotation;
		}
	}

	int32 (*K2_RemoveItemFromPlayerByGuid)(UObject* Context, void* Stack, void* Ret);
	int32 K2_RemoveItemFromPlayerByGuidHook(UObject* Context, void* Stack, void* Ret)
	{

		FN_LOG(LogKismetLibrary, Error, "[UFortKismetLibrary::K2_RemoveItemFromPlayerByGuid] called!");

		return K2_RemoveItemFromPlayerByGuid(Context, Stack, Ret);
	}

	void InitFortKismetLibrary()
	{
		static auto FortKismetLibraryDefault = FindObjectFast<UFortKismetLibrary>("/Script/FortniteGame.Default__FortKismetLibrary");

		static auto regererg = FindObjectFast<UFunction>("/Script/FortniteGame.FortKismetLibrary.GiveItemToInventoryOwner");

		MinHook::HookFunctionExec(regererg, K2_RemoveItemFromPlayerByGuidHook, (LPVOID*)(&K2_RemoveItemFromPlayerByGuid));


		FN_LOG(LogInit, Log, "InitFortKismetLibrary Success!");
	}
}