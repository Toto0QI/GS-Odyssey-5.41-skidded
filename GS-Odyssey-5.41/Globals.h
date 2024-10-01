#pragma once

uintptr_t IdkOffset = 0x680;

#define CHEATS
// #define DEBUGS
#define SIPHON
#define ANTICHEAT
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

// 0x0040 (0x0040 - 0x0000)
struct FFortCreatePickupData final
{
public:
	UWorld*										  World;					                         // 0x0000(0x0008)()
	FFortItemEntry*								  ItemEntry;									     // 0x0008(0x0008)()
	const FVector*								  SpawnLocation;									 // 0x0010(0x0008)()
	const FRotator*								  SpawnRotation;                                     // 0x0018(0x0008)()
	AFortPlayerController*						  PlayerController;									 // 0x0020(0x0008)()
	UClass*										  OverrideClass;									 // 0x0028(0x0008)()
	void*									      NullptrIdk;										 // 0x0030(0x0008)()
	bool										  bRandomRotation;									 // 0x0038(0x0001)()
	uint8                                         Pad_1[0x3];                                        // 0x0039(0x0003)()
	uint32										  PickupSourceTypeFlags;						     // 0x003C(0x0004)()
};

namespace Globals
{
	UFortEngine* GetFortEngine()
	{
		return *(UFortEngine**)(uintptr_t(GetModuleHandleW(0)) + 0x5524898); // GEngine
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
			UFortPlaylistAthena* Playlist = GameState->CurrentPlaylistData;

			if (Playlist)
				return Playlist;
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
}