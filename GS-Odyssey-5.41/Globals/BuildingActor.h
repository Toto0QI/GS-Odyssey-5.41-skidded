#pragma once

namespace BuildingActor
{
    FName (*PickLootTierGroupAthena)(ABuildingContainer* BuildingContainer, FName* OutLootTierGroup, FName LootTierGroup);

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("OnDamageServer"))
		{
			ABuildingSMActor* BuildingActor = (ABuildingSMActor*)Object;
			auto Params = (Params::BuildingActor_OnDamageServer*)Parms;

			if (!BuildingActor || !Params->InstigatedBy || !Params->DamageCauser)
				return;

			AFortPlayerController* PlayerController = (AFortPlayerController*)Params->InstigatedBy;
			AFortWeapon* Weapon = (AFortWeapon*)Params->DamageCauser;
			AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

			if (!Pawn || BuildingActor->bDestroyed)
				return;

            if (BuildingActor->HasAuthority())
            {
                UFortWorldItem* ItemInstance = Inventory::GetItemInstance(PlayerController, Weapon->ItemEntryGuid);

                if (!ItemInstance)
                    return;

                UFortItemDefinition* WeaponItemDefinition = ItemInstance->GetItemDefinitionBP();

                if (!WeaponItemDefinition)
                    return;

                if (BuildingActor->IsA(ABuildingSMActor::StaticClass()) && WeaponItemDefinition->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
                {
                    UFortResourceItemDefinition* ResourceItemDefinition = Globals::GetKismetLibrary()->K2_GetResourceItemDefinition(BuildingActor->ResourceType);

                    if (!ResourceItemDefinition)
                        return;

                    if (BuildingActor->BuildingResourceAmountOverride.RowName.IsValid())
                    {
                        UKismetStringLibrary* StringLibrary = Globals::GetStringLibrary();
                        UFortPlaylistAthena* Playlist = Globals::GetPlaylist();

                        if (!StringLibrary || !Playlist)
                        {
                            FN_LOG(LogBuildingActor, Error, "[ABuildingActor::OnDamageServer] Failed to get StringLibrary/Playlist.");
                            return;
                        }

                        TSoftObjectPtr<UCurveTable> ResourceRatesObjectPtr = Playlist->ResourceRates;

                        UCurveTable* CurveTable = nullptr;

                        if (ResourceRatesObjectPtr.ObjectID.AssetPathName.IsValid())
                        {
                            CurveTable = StaticLoadObject<UCurveTable>(StringLibrary->Conv_NameToString(ResourceRatesObjectPtr.ObjectID.AssetPathName).CStr());
                        }

                        if (!CurveTable)
                            CurveTable = StaticLoadObject<UCurveTable>(L"/Game/Athena/Balance/DataTables/AthenaResourceRates.AthenaResourceRates");

                        if (!CurveTable)
                        {
                            FN_LOG(LogBuildingActor, Error, "[ABuildingActor::OnDamageServer] Failed to get CurveTable.");
                            return;
                        }

                        EEvaluateCurveTableResult OutResult;
                        FString ContextString;
                        float OutXY;

                        Globals::GetFunctionLibrary()->EvaluateCurveTableRow(CurveTable, BuildingActor->BuildingResourceAmountOverride.RowName, 0.f, &OutResult, &OutXY, ContextString);

                        int PotentialResourceCount = OutXY / (BuildingActor->GetMaxHealth() / Params->Damage);
                        int ResourceCount = round(PotentialResourceCount);

                        if (ResourceCount > 0)
                        {
                            PlayerController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, PotentialResourceCount, false, (Params->Damage == 100.f));

                            FFortItemEntry ItemEntry;
                            Inventory::CreateDefaultItemEntry(&ItemEntry, ResourceItemDefinition, ResourceCount, 0);
                            Inventory::SetStateValue(&ItemEntry, EFortItemEntryState::ShouldShowItemToast, 1);
                            Inventory::AddInventoryItem(PlayerController, &ItemEntry, FGuid());
                        }
                    }
                }
            }
		}
	}

	void InitBuildingActor()
	{
        uintptr_t AddressPickLootTierGroupAthena = MinHook::FindPattern(Patterns::PickLootTierGroupAthena);

        PickLootTierGroupAthena = decltype(PickLootTierGroupAthena)(AddressPickLootTierGroupAthena);

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}