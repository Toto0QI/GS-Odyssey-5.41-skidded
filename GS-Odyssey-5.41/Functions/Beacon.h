#pragma once

namespace Beacon
{
	bool (*InitHost)(AOnlineBeaconHost* OnlineBeaconHost);
	char (*InitListen)(UNetDriver* NetDriver, void* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error);
	void (*SetWorld)(UNetDriver* NetDriver, UWorld* World);
	void (*TickFlush)(UNetDriver* NetDriver, float DeltaSeconds);
	int32 (*ServerReplicateActors)(UReplicationGraph* ReplicationGraph, float DeltaSeconds);

	void TickFlushHook(UNetDriver* NetDriver, float DeltaSeconds)
	{
		if (NetDriver)
		{
			if (NetDriver->IsA(UIpNetDriver::StaticClass()) &&
				NetDriver->ClientConnections.Num() > 0 &&
				!NetDriver->ClientConnections[0]->InternalAck)
			{
				ServerReplicateActors((UReplicationGraph*)NetDriver->ReplicationDriver, DeltaSeconds);
			}
		}

		TickFlush(NetDriver, DeltaSeconds);
	}

	bool ListenHook(UWorld* World, FURL& InURL)
	{
		uintptr_t FuncCallAddress = (uintptr_t)_ReturnAddress();

		uintptr_t Offset = uintptr_t(FuncCallAddress) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		if (World && IdaAddress == 0x7FF670F1F3C9ULL) // Pu sa grand mère
		{
			UFortEngine* FortEngine = Globals::GetFortEngine();

			if (FortEngine)
			{
				AOnlineBeaconHost* Beacon = Util::SpawnActor<AOnlineBeaconHost>(AOnlineBeaconHost::StaticClass(), {}, {});
				UWorld* World = Globals::GetWorld();

				if (!Beacon || !World)
				{
					FN_LOG(LogBeacon, Error, "Failed to create Beacon or to get World!");
					return false;
				}

				Beacon->ListenPort = 7777 - 1;

				if (World->NetDriver)
				{
					FN_LOG(LogBeacon, Warning, "Beacon already created!");
					return false;
				}

				if (InitHost(Beacon))
				{
					World->NetDriver = Beacon->NetDriver;
					FN_LOG(LogBeacon, Log, "Beacon created successful!");
				}
				else
				{
					FN_LOG(LogBeacon, Error, "Failed to InitHost!");
					return false;
				}

				if (World->NetDriver)
				{
					World->NetDriver->World = World;
					World->NetDriver->NetDriverName = Globals::GetStringLibrary()->Conv_StringToName(L"GameNetDriver");

					// 7FF670F69750
					FLevelCollection* (*FindCollectionByType)(UWorld* World, int InType) = decltype(FindCollectionByType)(0x2919750 + uintptr_t(GetModuleHandle(0)));

					FLevelCollection* const SourceCollection = FindCollectionByType(World, 0); // ELevelCollectionType::DynamicSourceLevels
					if (SourceCollection)
					{
						SourceCollection->NetDriver = World->NetDriver;
					}
					FLevelCollection* const StaticCollection = FindCollectionByType(World, 2); // ELevelCollectionType::StaticLevels
					if (StaticCollection)
					{
						StaticCollection->NetDriver = World->NetDriver;
					}

					FString Error;
					if (!InitListen(World->NetDriver, World, InURL, true, Error))
					{
						FN_LOG(LogBeacon, Debug, "Failed to listen: %s", Error.ToString().c_str());

						SetWorld(World->NetDriver, NULL);
						World->NetDriver = NULL;

						FLevelCollection* const SourceCollection = FindCollectionByType(World, 0); // ELevelCollectionType::DynamicSourceLevels
						if (SourceCollection)
						{
							SourceCollection->NetDriver = nullptr;
						}
						FLevelCollection* const StaticCollection = FindCollectionByType(World, 2); // ELevelCollectionType::StaticLevels
						if (StaticCollection)
						{
							StaticCollection->NetDriver = nullptr;
						}

						return false;
					}

					SetWorld(World->NetDriver, World);

					/*World->LevelCollections[0].NetDriver = World->NetDriver;
					World->LevelCollections[1].NetDriver = World->NetDriver;*/

					uintptr_t PatternTickFlush = MinHook::FindPattern(Patterns::TickFlush);

					MH_CreateHook((LPVOID)(PatternTickFlush), TickFlushHook, (LPVOID*)(&TickFlush));
					MH_EnableHook((LPVOID)(PatternTickFlush));
				}
				else
				{
					FN_LOG(LogBeacon, Error, "Failed to listen!");
					return false;
				}

				FN_LOG(LogBeacon, Debug, "Listen on port: %i", InURL.Port);

				return true;
			}
		}

		return false;
	}

	void InitBeacon()
	{
		uintptr_t PatternInitHost = MinHook::FindPattern(Patterns::InitHost);
		uintptr_t PatternInitListen = MinHook::FindPattern(Patterns::InitListen);
		uintptr_t PatternSetWorld = MinHook::FindPattern(Patterns::SetWorld);
		uintptr_t PatternServerReplicateActors = MinHook::FindPattern(Patterns::ServerReplicateActors);

		InitHost = decltype(InitHost)(PatternInitHost);
		InitListen = decltype(InitListen)(PatternInitListen);
		SetWorld = decltype(SetWorld)(PatternSetWorld);
		ServerReplicateActors = decltype(ServerReplicateActors)(PatternServerReplicateActors);

		uintptr_t AddressListen = MinHook::FindPattern(Patterns::Listen, true, 0x1);

		MH_CreateHook((LPVOID)(AddressListen), ListenHook, nullptr);
		MH_EnableHook((LPVOID)(AddressListen));

		FN_LOG(LogInit, Log, "InitBeacon Success!");
	}
}