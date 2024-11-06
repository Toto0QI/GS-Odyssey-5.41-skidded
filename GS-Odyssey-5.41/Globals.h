#pragma once

uintptr_t InventoryOwnerOffset = 0x680;

#define CHEATS
// #define DEBUGS
#define SIPHON
#define QUESTS
#define ANTICHEAT
// #define LATEGAME
#define BOTS

template<typename T = UObject>
static T* Cast(UObject* Object)
{
	if (Object && Object->IsA(T::StaticClass()))
	{
		return (T*)Object;
	}

	return nullptr;
}

/** Global engine pointer. Can be 0 so don't use without checking. */
UEngine* GEngine = *(UEngine**)(uintptr_t(GetModuleHandleW(0)) + 0x5524898);

/* Automatically pick up ammo and other resources. */
bool GAutoResourceGathering = *(bool*)(uintptr_t(GetModuleHandleW(0)) + 0x4DADCA4);

namespace Globals
{
	UFortEngine* GetFortEngine()
	{
		return Cast<UFortEngine>(GEngine);
	}

	UWorld* GetWorld(bool SkipCheck = false)
	{
		UEngine* Engine = GetFortEngine();

		if (Engine)
		{
			if (Engine->GameViewport)
				return Engine->GameViewport->World;
		}

		return nullptr;
	}

	TArray<ULocalPlayer*> GetLocalPlayers()
	{
		UGameEngine* Engine = GetFortEngine();

		if (Engine)
		{
			if (Engine->GameInstance)
				return Engine->GameInstance->LocalPlayers;
		}
	}

	AFortPlayerController* GetServerPlayerController()
	{
		return Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));
	}

	AFortGameMode* GetGameMode()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameMode* GameMode = Cast<AFortGameMode>(World->AuthorityGameMode);

			if (GameMode)
				return GameMode;
		}

		return nullptr;
	}

	AFortGameState* GetGameState()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameState* GameState = Cast<AFortGameState>(World->GameState);

			if (GameState)
				return GameState;
		}

		return nullptr;
	}

	UFortPlaylistAthena* GetPlaylist()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(GetGameState());

		if (GameState)
		{
			UFortPlaylistAthena* PlaylistAthena = GameState->CurrentPlaylistData;

			if (PlaylistAthena)
				return PlaylistAthena;
		}

		return nullptr;
	}

	UFortGameData* GetGameData()
	{
		UFortAssetManager* AssetManager = Cast<UFortAssetManager>(GetFortEngine()->AssetManager);

		if (AssetManager)
		{
			UFortGameData* GameData = AssetManager->GameData;

			if (GameData)
				return GameData;
		}

		return nullptr;
	}

	template <typename T>
	static T* GetDataTableRowFromName(UDataTable* DataTable, FName RowName)
	{
		if (!DataTable)
			return nullptr;

		auto& RowMap = DataTable->GetRowMap();

		for (int i = 0; i < RowMap.Elements.Elements.Num(); ++i)
		{
			auto& Pair = RowMap.Elements.Elements.Data[i].ElementData.Value;

			if (Pair.Key() != RowName)
				continue;

			return (T*)Pair.Value();
		}

		return nullptr;
	}

	float GenFlyTime()
	{
		float MaxTime; // [rsp+48h] [rbp+10h] BYREF
		float MinTime; // [rsp+50h] [rbp+18h] BYREF

		UCurveVector* PickupSplineCurve = GetGameData()->PickupSplineCurve;
		if (!PickupSplineCurve)
			return 1.5f;
		PickupSplineCurve->GetTimeRange(&MinTime, &MaxTime);
		float PickupSplineRandomMax = GetGameData()->PickupSplineRandomMax;
		return (float)(MaxTime - MinTime) * (float)((float)((float)((float)rand() * 0.000030518509f) * (float)(PickupSplineRandomMax - 1.0f)) + 1.0f);
	}
}