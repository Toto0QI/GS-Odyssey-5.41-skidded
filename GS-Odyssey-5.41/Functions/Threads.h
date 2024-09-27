#pragma once

#include <iostream>
#include <string>

#include <curl/curl.h>

namespace Threads
{
	DWORD WINAPI CompletePickupCombine(LPVOID PickupParm)
	{
		AFortPickup* Pickup = (AFortPickup*)PickupParm;

		if (!Pickup)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::CompletePickupCombine] Failed to get Pickup!");
			return 0;
		}

		if (Pickup->bActorIsBeingDestroyed)
			return 0;

		FFortPickupLocationData* PickupLocationData = &Pickup->PickupLocationData;
		FFortItemEntry* PrimaryItemEntry = &Pickup->PrimaryPickupItemEntry;

		if (!PickupLocationData || !PrimaryItemEntry)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::CompletePickupCombine] Failed to get PickupLocationData/PrimaryItemEntry!");
			return 0;
		}

		AFortPickup* PickupToCombine = PickupLocationData->CombineTarget;

		if (!PickupToCombine)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::CompletePickupCombine] Failed to get PickupToCombine!");
			return 0;
		}

		if (PickupToCombine->bActorIsBeingDestroyed)
			return 0;

		FFortItemEntry* CombineItemEntry = &PickupToCombine->PrimaryPickupItemEntry;

		if (!CombineItemEntry)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::CompletePickupCombine] Failed to get CombineItemEntry!");
			return 0;
		}

		UFortWorldItemDefinition* ItemDefinition = (UFortWorldItemDefinition*)CombineItemEntry->ItemDefinition;

		if (!ItemDefinition)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::CompletePickupCombine] Failed to get ItemDefinition!");
			return 0;
		}

		float SleepTime = PickupLocationData->FlyTime * 1000;

		Sleep(SleepTime);

		int32 CountToRemove = 0;
		int32 NewCount = PrimaryItemEntry->Count + CombineItemEntry->Count;

		if (NewCount > ItemDefinition->MaxStackSize)
		{
			CountToRemove = NewCount - ItemDefinition->MaxStackSize;
			NewCount = ItemDefinition->MaxStackSize;
		}

		if (CountToRemove > 0)
		{
			FFortItemEntry NewItemEntry;
			Inventory::MakeItemEntry(&NewItemEntry, ItemDefinition, CountToRemove, PrimaryItemEntry->Durability, PrimaryItemEntry->Level, PrimaryItemEntry->LoadedAmmo);
			// Inventory::SpawnPickup(nullptr, &NewItemEntry, PickupToCombine->K2_GetActorLocation(), true);
		}

		CombineItemEntry->Count = NewCount;
		PickupToCombine->OnRep_PrimaryPickupItemEntry();
		PickupToCombine->ForceNetUpdate();

		Pickup->K2_DestroyActor();

		FN_LOG(LogHooks, Debug, "[AFortPickup::CompletePickupCombine] complete!");

		return 0;
	}
}