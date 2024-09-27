#pragma once

/*
	- GiveItemToInventoryOwner
	- K2_GiveBuildingResource
	- K2_GiveItemToAllPlayers
	- K2_GiveItemToPlayer
	- K2_RemoveItemFromAllPlayers
	- K2_RemoveItemFromPlayer
	- K2_RemoveItemFromPlayerByGuid
	- K2_SpawnPickupInWorld
	- PickLootDrops
*/

namespace FortKismetLibrary
{
	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms, bool* bCallOG)
	{
		if (!Object || !Function)
			return;

		if (!Object->IsA(UFortKismetLibrary::StaticClass()))
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("GiveItemToInventoryOwner"))
		{
			auto Params = (Params::FortKismetLibrary_GiveItemToInventoryOwner*)Parms;

			TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner = Params->InventoryOwner;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;
			int32 NumberToGive = Params->NumberToGive;
			bool bNotifyPlayer = Params->bNotifyPlayer;

			if (bNotifyPlayer)
			{

			}
			else
			{

			}
		}
		else if (FunctionName.contains("K2_GiveBuildingResource")) // Rewrite
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveBuildingResource*)Parms;

			UFortResourceItemDefinition* ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(Params->ResourceType);
			AFortPlayerController* Controller = Params->Controller;

			if (ResourceItemDefinition && Controller)
			{
				const int32 ResourceAmount = Params->ResourceAmount;

				UFortKismetLibrary::K2_GiveItemToPlayer(Controller, ResourceItemDefinition, ResourceAmount, true);
			}
		}
		else if (FunctionName.contains("K2_GiveItemToAllPlayers")) // Rewrite
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveItemToAllPlayers*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (WorldContextObject && ItemDefinition)
			{
				TArray<AFortPlayerController*> PlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

				for (int32 i = 0; i < PlayerControllers.Num(); i++)
				{
					AFortPlayerController* PlayerController = PlayerControllers[i];
					if (!PlayerController) continue;

					UFortKismetLibrary::K2_GiveItemToPlayer(PlayerController, ItemDefinition, Params->NumberToGive, Params->bNotifyPlayer);
				}
			}
		}
		else if (FunctionName.contains("K2_GiveItemToPlayer")) // Rewrite
		{
			auto Params = (Params::FortKismetLibrary_K2_GiveItemToPlayer*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;
			
			if (PlayerController && ItemDefinition)
			{
				FFortItemEntry ItemEntry;
				Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, Params->NumberToGive, -1, -1, -1.0f);

				if (Params->bNotifyPlayer && PlayerController->MyFortPawn)
				{
					FVector SpawnLocation = PlayerController->MyFortPawn->K2_GetActorLocation();
					FRotator SpawnRotation = FRotator({ 0, 0, 0 });

					UWorld* World = Functions::GetWorldFromContextObject(Globals::GetFortEngine(), PlayerController, EGetWorldErrorMode::LogAndReturnNull);

					FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
					CreatePickupData.World = World;
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
						FVector StartDirection = FVector({ 0, 0, 0 });
						Pawn::SetPickupTarget(Pickup, PlayerController->MyFortPawn, -1.0f, StartDirection, true);
					}
				}
				else
				{
					Inventory::AddInventoryItem(PlayerController, ItemEntry);
				}
			}
		}
		else if (FunctionName.contains("K2_RemoveItemFromAllPlayers"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromAllPlayers*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			if (WorldContextObject && ItemDefinition)
			{
				TArray<AFortPlayerController*> PlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(WorldContextObject, true, false);

				for (int32 i = 0; i < PlayerControllers.Num(); i++)
				{
					AFortPlayerController* PlayerController = PlayerControllers[i];
					if (!PlayerController) continue;

					UFortKismetLibrary::K2_RemoveItemFromPlayer(PlayerController, ItemDefinition, Params->AmountToRemove, true);
				}
			}
		}
		else if (FunctionName.contains("K2_RemoveItemFromPlayer"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromPlayer*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			Params->ReturnValue = 0;

			if (PlayerController && ItemDefinition)
			{
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_FindExistingItemForDefinition(ItemDefinition, false));

				if (WorldItem)
				{
					bool bForceRemoval = Params->bForceRemoval;

					int32 ItemCount = WorldItem->ItemEntry.Count;
					int32 FinalCount = ItemCount - Params->AmountToRemove;

					if (FinalCount < 0)
						FinalCount = 0;

					Params->ReturnValue = FinalCount;

					Inventory::RemoveInventoryItem(PlayerController, WorldItem->ItemEntry.ItemGuid, Params->AmountToRemove);
				}
			}

			*bCallOG = false;
		}
		else if (FunctionName.contains("K2_RemoveItemFromPlayerByGuid"))
		{
			auto Params = (Params::FortKismetLibrary_K2_RemoveItemFromPlayerByGuid*)Parms;

			AFortPlayerController* PlayerController = Params->PlayerController;

			Params->ReturnValue = 0;

			if (PlayerController)
			{
				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(PlayerController->K2_GetInventoryItemWithGuid(Params->ItemGuid));

				if (WorldItem)
				{
					bool bForceRemoval = Params->bForceRemoval;

					int32 ItemCount = WorldItem->ItemEntry.Count;
					int32 FinalCount = ItemCount - Params->AmountToRemove;

					if (FinalCount < 0)
						FinalCount = 0;

					Params->ReturnValue = FinalCount;

					Inventory::RemoveInventoryItem(PlayerController, WorldItem->ItemEntry.ItemGuid, Params->AmountToRemove);
				}
			}

			*bCallOG = false;
		}
		else if (FunctionName.contains("K2_SpawnPickupInWorld"))
		{
			auto Params = (Params::FortKismetLibrary_K2_SpawnPickupInWorld*)Parms;

			UObject* WorldContextObject = Params->WorldContextObject;
			UFortWorldItemDefinition* ItemDefinition = Params->ItemDefinition;

			Params->ReturnValue = nullptr;

			if (WorldContextObject && ItemDefinition)
			{
				UWorld* World = Functions::GetWorldFromContextObject(Globals::GetFortEngine(), WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

				FFortItemEntry ItemEntry;
				Inventory::MakeItemEntry(&ItemEntry, ItemDefinition, Params->NumberToSpawn, -1, -1, -1.0f);

				FVector SpawnLocation = Params->Position;
				FRotator SpawnRotation = FRotator({ 0, 0, 0 });

				FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
				CreatePickupData.World = World;
				CreatePickupData.ItemEntry = &ItemEntry;
				CreatePickupData.SpawnLocation = &SpawnLocation;
				CreatePickupData.SpawnRotation = &SpawnRotation;
				CreatePickupData.PlayerController = nullptr;
				CreatePickupData.OverrideClass = nullptr;
				CreatePickupData.NullptrIdk = nullptr;
				CreatePickupData.bRandomRotation = Params->bRandomRotation;
				CreatePickupData.PickupSourceTypeFlags = 0;

				AFortPickup* Pickup = Inventory::CreatePickupFromData(&CreatePickupData);

				if (Pickup)
				{
					Pickup->bWeaponsCanBeAutoPickups = !Params->bBlockedFromAutoPickup;

					FVector StartDirection = Params->Direction;
					Pickup->TossPickup(StartDirection, nullptr, Params->OverrideMaxStackCount, Params->bToss);
				}

				Params->ReturnValue = Pickup;
			}

			*bCallOG = false;
		}
		else if (FunctionName.contains("PickLootDrops"))
		{
			auto Params = (Params::FortKismetLibrary_PickLootDrops*)Parms;

			Params->ReturnValue = false;

			int32 WorldLevel = Params->WorldLevel;

			FName LootTierKey = FName(0);
			int32 LootTier = -1;

			bool bResult = Loots::PickLootTierKeyAndLootTierFromTierGroup(&LootTierKey, &LootTier, Params->TierGroupName, WorldLevel, 0, Params->ForcedLootTier, FGameplayTagContainer());

			if (bResult)
			{
				Params->ReturnValue = Loots::PickLootDrops(&Params->OutLootToDrop, WorldLevel, LootTierKey, 0, 0, FGameplayTagContainer(), false, false);
			}

			*bCallOG = false;
		}
	}

	void InitFortKismetLibrary()
	{
		static auto FortKismetLibraryDefault = UFortKismetLibrary::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitFortKismetLibrary Success!");
	}
}