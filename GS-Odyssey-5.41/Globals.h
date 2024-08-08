#pragma once

uintptr_t IdkOffset = 0x680;

#define CHEATS
#define DEBUGS

template<typename T = UObject>
static T* Cast(UObject* Object)
{
	if (Object && Object->IsA(T::StaticClass()))
	{
		return (T*)Object;
	}

	return nullptr;
}

namespace Globals
{
	UWorld* GetWorld(bool SkipCheck = false)
	{
		UEngine* Engine = UEngine::GetEngine();

		if (Engine)
		{
			if (Engine->GameViewport)
				return Engine->GameViewport->World;
		}

		return nullptr;
	}

	TArray<ULocalPlayer*> GetLocalPlayers()
	{
		UGameEngine* Engine = Cast<UGameEngine>(UEngine::GetEngine());

		if (Engine)
		{
			if (Engine->GameInstance)
				return Engine->GameInstance->LocalPlayers;
		}
	}

	AFortPlayerControllerAthena* GetServerPlayerController()
	{
		return Cast<AFortPlayerControllerAthena>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));
	}

	AFortGameModeAthena* GetGameMode()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(World->AuthorityGameMode);

			if (GameMode)
				return GameMode;
		}

		return nullptr;
	}

	AFortGameStateAthena* GetGameState()
	{
		UWorld* World = GetWorld();

		if (World)
		{
			AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(World->GameState);

			if (GameState)
				return GameState;
		}

		return nullptr;
	}

	UFortPlaylistAthena* GetPlaylist()
	{
		AFortGameStateAthena* GameState = GetGameState();

		if (GameState)
		{
			UFortPlaylistAthena* Playlist = GameState->CurrentPlaylistData;

			if (Playlist)
				return Playlist;
		}

		return nullptr;
	}

	UFortGameData* GetGameData()
	{
		UFortAssetManager* AssetManager = Cast<UFortAssetManager>(UEngine::GetEngine()->AssetManager);

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
}