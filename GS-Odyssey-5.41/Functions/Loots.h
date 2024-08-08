#pragma once
#include <random>

namespace Loots
{
	std::vector<FFortLootPackageData*> GetAvailableLootPackageData(UDataTable* AthenaLootPackages, FName LootPackageID)
	{
		std::vector<FFortLootPackageData*> AvailableLootPackageData;

		TArray<FName> RowNames;
		UDataTableFunctionLibrary::GetDataTableRowNames(AthenaLootPackages, &RowNames);

		for (int i = 0; i < RowNames.Num(); i++)
		{
			FName RowName = RowNames[i];

			FFortLootPackageData* LootPackageData = Globals::GetDataTableRowFromName<FFortLootPackageData>(AthenaLootPackages, RowName);
			if (!LootPackageData) continue;

			if (LootPackageData->LootPackageID != LootPackageID)
				continue;

			AvailableLootPackageData.push_back(LootPackageData);
		}

		return AvailableLootPackageData;
	}

	std::vector<FFortLootTierData*> GetAvailableLootTierData(UDataTable* AthenaLootTierData, FName SearchLootTierGroup, int32 LootTier)
	{
		std::vector<FFortLootTierData*> AvailableLootTierData;

		TArray<FName> RowNames;
		UDataTableFunctionLibrary::GetDataTableRowNames(AthenaLootTierData, &RowNames);

		for (int i = 0; i < RowNames.Num(); i++)
		{
			FName RowName = RowNames[i];

			FFortLootTierData* LootTierData = Globals::GetDataTableRowFromName<FFortLootTierData>(AthenaLootTierData, RowName);
			if (!LootTierData) continue;

			if (!LootTierData->TierGroup.ToString().contains(SearchLootTierGroup.ToString()))
				continue;

			if (LootTierData->LootTier != LootTier && LootTier != -1)
				continue;

			AvailableLootTierData.push_back(LootTierData);
		}

		return AvailableLootTierData;
	}

	FFortLootPackageData* ChooseWeightedRandomLootPackageData(std::vector<FFortLootPackageData*>& AvailableLootPackageData)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::vector<double> Weights;

		for (auto& LootPackageData : AvailableLootPackageData)
		{
			Weights.push_back(LootPackageData->Weight);
		}

		std::discrete_distribution<> dist(Weights.begin(), Weights.end());
		int ChosenIndex = dist(gen);

		return AvailableLootPackageData[ChosenIndex];
	}

	FFortLootTierData* ChooseWeightedRandomLootTierData(std::vector<FFortLootTierData*>& AvailableLootTierData)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::vector<double> Weights;

		for (auto& LootTierData : AvailableLootTierData)
		{
			Weights.push_back(LootTierData->Weight);
		}

		std::discrete_distribution<> dist(Weights.begin(), Weights.end());
		int ChosenIndex = dist(gen);

		return AvailableLootTierData[ChosenIndex];
	}

	int32 NumLootPackageDropsRound(float NumLootPackageDrops)
	{
		int IntegralPart = static_cast<int>(NumLootPackageDrops);
		float FractionalPart = NumLootPackageDrops - IntegralPart;

		std::random_device rd;
		std::mt19937 gen(rd());

		float DisToHalf = std::abs(FractionalPart - 0.5f);
		float ProbaToRoundUp = 1.0f - 2.0f * DisToHalf;

		std::uniform_real_distribution<float> distribution(0.0, 1.0);

		if (distribution(gen) < ProbaToRoundUp)
		{
			return IntegralPart + 1;
		}
		else
		{
			return IntegralPart;
		}
	}

	std::vector<FFortItemEntry> ChooseLootToDrops(FName SearchLootTierGroup, int32 LootTier, bool* bSuccess)
	{
		std::vector<FFortItemEntry> LootToDrops;

		UFortPlaylistAthena* Playlist = Globals::GetPlaylist();

		if (!Playlist)
		{
			*bSuccess = false;
			return LootToDrops;
		}

		TSoftObjectPtr<UDataTable> LootTierDataObjectPtr = Playlist->LootTierData;
		TSoftObjectPtr<UDataTable> LootPackagesObjectPtr = Playlist->LootPackages;

		UDataTable* LootTierData = nullptr;
		UDataTable* LootPackages = nullptr;

		if (LootTierDataObjectPtr.ObjectID.AssetPathName.IsValid() && LootPackagesObjectPtr.ObjectID.AssetPathName.IsValid())
		{
			bool bIsCompositeLootTierData = LootTierDataObjectPtr.ObjectID.AssetPathName.ToString().contains("Composite");
			bool bIsCompositeLootPackages = LootPackagesObjectPtr.ObjectID.AssetPathName.ToString().contains("Composite");

			UClass* LootTierDataClass = bIsCompositeLootTierData ? UCompositeDataTable::StaticClass() : UDataTable::StaticClass();
			UClass* LootPackagesClass = bIsCompositeLootPackages ? UCompositeDataTable::StaticClass() : UDataTable::StaticClass();

			const TCHAR* LootTierDataPath = UKismetStringLibrary::Conv_NameToString(LootTierDataObjectPtr.ObjectID.AssetPathName).CStr();
			const TCHAR* LootPackagesPath = UKismetStringLibrary::Conv_NameToString(LootPackagesObjectPtr.ObjectID.AssetPathName).CStr();

			LootTierData = (UDataTable*)StaticLoadObjectInternal(LootTierDataClass, nullptr, LootTierDataPath, nullptr, 0, nullptr, false);
			LootPackages = (UDataTable*)StaticLoadObjectInternal(LootPackagesClass, nullptr, LootPackagesPath, nullptr, 0, nullptr, false);
		}

		if (!LootTierData || !LootPackages)
		{
			LootTierData = StaticLoadObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client");
			LootPackages = StaticLoadObject<UDataTable>(L"/Game/Items/Datatables/AthenaLootPackages_Client.AthenaLootPackages_Client");
		}

		if (!LootTierData || !LootPackages)
		{
			*bSuccess = false;
			return LootToDrops;
		}

		std::vector<FFortLootTierData*> AvailableLootTierData = GetAvailableLootTierData(LootTierData, SearchLootTierGroup, LootTier);

		if (AvailableLootTierData.empty())
		{
			*bSuccess = false;
			return LootToDrops;
		}

		FFortLootTierData* ChooseLootTierData = ChooseWeightedRandomLootTierData(AvailableLootTierData);

		if (!ChooseLootTierData)
		{
			*bSuccess = false;
			return LootToDrops;
		}

		int32 NumLootPackageDrops = NumLootPackageDropsRound(ChooseLootTierData->NumLootPackageDrops);

		std::vector<FFortLootPackageData*> AvailableLootPackageData = GetAvailableLootPackageData(LootPackages, ChooseLootTierData->LootPackage);

		if (AvailableLootPackageData.empty())
		{
			*bSuccess = false;
			return LootToDrops;
		}

		for (int32 i = 0; i < AvailableLootPackageData.size(); i++)
		{
			FFortLootPackageData* LootPackageData = AvailableLootPackageData[i];
			if (!LootPackageData) continue;

			if (i > NumLootPackageDrops - 1)
				break;

			FFortLootPackageData* ChooseLootPackageData = nullptr;

			if (LootPackageData->LootPackageCall.IsValid())
			{
				FName LootPackageID = UKismetStringLibrary::Conv_StringToName(LootPackageData->LootPackageCall);
				std::vector<FFortLootPackageData*> AvailableLootPackageDataCall = GetAvailableLootPackageData(LootPackages, LootPackageID);

				if (AvailableLootPackageDataCall.empty())
					continue;

				ChooseLootPackageData = ChooseWeightedRandomLootPackageData(AvailableLootPackageDataCall);
			}
			else
			{
				ChooseLootPackageData = ChooseWeightedRandomLootPackageData(AvailableLootPackageData);
			}

			if (!ChooseLootPackageData)
				continue;

			UFortItemDefinition* ItemDefinition = ChooseLootPackageData->ItemDefinition.Get();

			if (!ItemDefinition)
			{
				std::string ItemPath = ChooseLootPackageData->ItemDefinition.ObjectID.SubPathString.ToString();

				ItemDefinition = StaticLoadObject<UFortItemDefinition>(std::wstring(ItemPath.begin(), ItemPath.end()).c_str());
			}

			if (!ItemDefinition || ChooseLootPackageData->Count <= 0)
				continue;

			auto it = std::find_if(LootToDrops.begin(), LootToDrops.end(),
				[ItemDefinition](const FFortItemEntry& entry) { return entry.ItemDefinition == ItemDefinition; });

			if (it != LootToDrops.end())
				continue;

			FFortItemEntry ItemEntry;
			Inventory::MakeItemEntry(&ItemEntry, (UFortWorldItemDefinition*)ItemDefinition, ChooseLootPackageData->Count, -1, -1, 0.f);

			LootToDrops.push_back(ItemEntry);
		}

		*bSuccess = (LootToDrops.size() > 0);
		return LootToDrops;
	}
}