#pragma once

enum ENetMode
{
	NM_Standalone,
	NM_DedicatedServer,
	NM_ListenServer,
	NM_Client,
	NM_MAX,
};

namespace Hooks
{
	void (*GetPlayerViewPoint)(AFortPlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation);
	void (*ProcessEvent)(UObject* Object, UFunction* Function, void* Parms);
	void (*DispatchRequest)(__int64 a1, __int64* a2);
	void (*PickupCombine)(AFortPickup* Pickup);
	void (*PickupDelay)(AFortPickup* Pickup);

	uintptr_t GIsClient()
	{
		return __int64(GetModuleHandleW(0)) + 0x531F204;
	}

	uintptr_t GIsServer()
	{
		return __int64(GetModuleHandleW(0)) + 0x531F205;
	}

	ENetMode ReturnNetMode()
	{
		return ENetMode::NM_DedicatedServer;
	}

	bool LocalSpawnPlayActorHook()
	{
		return true;
	}

	void KickPlayerHook()
	{
		return;
	}

	__int64* ChangingGameSessionIdHook(__int64 a1, __int64 a2)
	{
		return 0;
	}

	char CollectGarbageInternalHook()
	{
		return 0;
	}

	void DispatchRequestHook(__int64 a1, __int64* a2)
	{
		*(int32*)(__int64(a2) + 0x28) = 3;

		DispatchRequest(a1, a2);
	}

	void GetPlayerViewPointHook(AFortPlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		AFortPawn* Pawn = (AFortPawn*)PlayerController->Pawn;

		if (Pawn)
		{
			out_Location = Pawn->K2_GetActorLocation();
			out_Rotation = PlayerController->GetControlRotation();
			return;
		}

		return GetPlayerViewPoint(PlayerController, out_Location, out_Rotation);
	}

	void PickupCombineHook(AFortPickup* Pickup)
	{
		if (!Pickup)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupCombine] Failed to get Pickup!");
			return;
		}

		CreateThread(0, 0, Threads::CompletePickupCombine, Pickup, 0, 0);

		PickupCombine(Pickup);
	}

	void PickupDelayHook(AFortPickup* Pickup)
	{
		if (!Pickup)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupDelay] Failed to get Pickup.");
			return;
		}

		FFortPickupLocationData* PickupLocationData = &Pickup->PickupLocationData;
		FFortItemEntry* ItemEntry = &Pickup->PrimaryPickupItemEntry;

		if (!PickupLocationData || !ItemEntry)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupDelay] Failed to get PickupLocationData/ItemEntry!");
			return;
		}

		UFortWorldItemDefinition* ItemDefinition = (UFortWorldItemDefinition*)ItemEntry->ItemDefinition;

		if (!ItemDefinition)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupDelay] Failed to get ItemDefinition!");
			return;
		}

		AFortPawn* Pawn = PickupLocationData->PickupTarget;

		if (!Pawn)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupDelay] Failed to get Pawn!");
			return;
		}

		AFortPlayerController* PlayerController = (AFortPlayerController*)Pawn->Controller;

		if (!PlayerController)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupDelay] Failed to get PlayerController!");
			return;
		}

		FGuid CurrentWepGuid = PickupLocationData->PickupGuid;

		Inventory::AddInventoryItem(PlayerController, ItemEntry, CurrentWepGuid);
		Inventory::UpdateInventory(PlayerController->WorldInventory);

		PickupDelay(Pickup);
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
		{
			ProcessEvent(Object, Function, Parms);
			return;
		}

		GameMode::ProcessEventHook(Object, Function, Parms);
		PlayerController::ProcessEventHook(Object, Function, Parms);
		Pawn::ProcessEventHook(Object, Function, Parms);
		BuildingActor::ProcessEventHook(Object, Function, Parms);
		FortKismetLibrary::ProcessEventHook(Object, Function, Parms);
		Cheats::ProcessEventHook(Object, Function, Parms);

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				
			}

			if (GetAsyncKeyState(VK_F2) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				static auto ItemDefinition = FindObjectFast<UFortWeaponRangedItemDefinition>("/Game/Athena/Items/Weapons/WID_Pistol_SemiAuto_Athena_R_Ore_T03.WID_Pistol_SemiAuto_Athena_R_Ore_T03");

				UFortKismetLibrary::K2_RemoveItemFromAllPlayers(PlayerController, ItemDefinition, 1);
			}

			if (GetAsyncKeyState(VK_F3) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				UFortKismetLibrary::K2_GiveBuildingResource(PlayerController, EFortResourceType::Wood, 100);

				// 7FF66F6694B0
				/*char (*Restart)(AFortGameSessionDedicated* GameSession) = decltype(Restart)(0x10194B0 + uintptr_t(GetModuleHandle(0)));

				char Result = Restart((AFortGameSessionDedicated*)Globals::GetGameMode()->FortGameSession);

				GameMode::bPreReadyToStartMatch = false;
				GameMode::bWorldReady = false;

				FN_LOG(LogHooks, Debug, "Restart called, Result: %i", Result);*/

			}

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				/*AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				UFortKismetLibrary::GetPlayerInfoFromUniqueID(PlayerController, FUniqueNetIdRepl());*/

				
				FPlayerBuildableClassContainer PlayerBuildableClasses0 = Globals::GetGameState()->PlayerBuildableClasses[0x0];

				for (int i = 0; i < PlayerBuildableClasses0.BuildingClasses.Num(); i++)
				{
					TSubclassOf<ABuildingSMActor> BuildingClasse = PlayerBuildableClasses0.BuildingClasses[i];
					if (!BuildingClasse.Get()) continue;

					FN_LOG(LogHooks, Error, "[%i] - BuildingClasse (0x0) : %s", i, BuildingClasse.Get()->GetName().c_str());
				}
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				static auto FortPlayerControllerAthenaDefault = (AFortPlayerControllerAthena*)(AFortPlayerControllerAthena::StaticClass())->DefaultObject;

				static auto IdkDefault = (void*)(__int64(FortPlayerControllerAthenaDefault) + IdkOffset);

				/*
					OdysseyLog: LogHook: Debug: Index not found: 0x0, Offset: 0xc17a88, IdaAddress [00007FF66F267A88] - Pleins de Free Memory
					OdysseyLog: LogHook: Debug: Index not found: 0x1, Offset: 0xc3b978, IdaAddress [00007FF66F28B978] - Baka
					OdysseyLog: LogHook: Debug: Index not found: 0x2, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x3, Offset: 0xc26310, IdaAddress [00007FF66F276310] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x4, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x5, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x6, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x7, Offset: 0x11b3850, IdaAddress [00007FF66F803850] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x8, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0x9, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0xa, Offset: 0xc269f0, IdaAddress [00007FF66F2769F0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xb, Offset: 0xc28ad0, IdaAddress [00007FF66F278AD0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xc, Offset: 0x11beef0, IdaAddress [00007FF66F80EEF0] - Peut être intéressent ressemble à RemoveInventoryItem
					OdysseyLog: LogHook: Debug: Index not found: 0xd, Offset: 0x11d8640, IdaAddress [00007FF66F828640] - ModifyLoadedAmmo
					OdysseyLog: LogHook: Debug: Index not found: 0xe, Offset: 0x11c60b0, IdaAddress [00007FF66F8160B0] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0xf, Offset: 0x11c6010, IdaAddress [00007FF66F816010] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0x10, Offset: 0xc28550, IdaAddress [00007FF66F278550] - La fonction est énorme
					OdysseyLog: LogHook: Debug: Index not found: 0x11, Offset: 0x11a9910, IdaAddress [00007FF66F7F9910] - Prends 3 paramètres et fait un truc avec l'ItemDefinition et le FortItem
					OdysseyLog: LogHook: Debug: Index not found: 0x12, Offset: 0x11a9c40, IdaAddress [00007FF66F7F9C40] - GetItemInstances
					OdysseyLog: LogHook: Debug: Index not found: 0x13, Offset: 0x11ae410, IdaAddress [00007FF66F7FE410] - GetItemInstance
					OdysseyLog: LogHook: Debug: Index not found: 0x14, Offset: 0x11d1cc0, IdaAddress [00007FF66F821CC0] - RemoveInventoryItem
					OdysseyLog: LogHook: Debug: Index not found: 0x15, Offset: 0xc17ba0, IdaAddress [00007FF66F267BA0] - Pleins de Free Memory
					OdysseyLog: LogHook: Debug: Index not found: 0x16, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x17, Offset: 0x1841460, IdaAddress [00007FF66FE91460] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x18, Offset: 0x2cccd0, IdaAddress [00007FF66E91CCD0] - WITH_SERVER_CODE (return 0)
					OdysseyLog: LogHook: Debug: Index not found: 0x19, Offset: 0x22cfbd0, IdaAddress [00007FF67091FBD0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x1a, Offset: 0x18403d0, IdaAddress [00007FF66FE903D0] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x1b, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x1c, Offset: 0x2e1a30, IdaAddress [00007FF66E931A30] - jsp wallah
					OdysseyLog: LogHook: Debug: Index not found: 0x1d, Offset: 0x22e46e0, IdaAddress [00007FF6709346E0] - Peut être intéressent à tester
					OdysseyLog: LogHook: Debug: Index not found: 0x1e, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x1f, Offset: 0x2cccd0, IdaAddress [00007FF66E91CCD0] - WITH_SERVER_CODE (return 0)
					OdysseyLog: LogHook: Debug: Index not found: 0x20, Offset: 0x2ccb70, IdaAddress [00007FF66E91CB70] - WITH_SERVER_CODE (nullsub)
					OdysseyLog: LogHook: Debug: Index not found: 0x21, Offset: 0x3530d0, IdaAddress [00007FF66E9A30D0] - WITH_SERVER_CODE (nullsub)
				*/

				MinHook::FindIndexVTable((UObject*)IdkDefault, 0x0, 0x21);
			}
		}
		else if (FunctionName.contains("ServerUpdatePhysicsParams"))
		{
			AFortAthenaVehicle* AthenaVehicle = (AFortAthenaVehicle*)Object;
			auto Params = (Params::FortAthenaVehicle_ServerUpdatePhysicsParams*)Parms;

			if (!AthenaVehicle)
				return;

			UPrimitiveComponent* RootComponent = (UPrimitiveComponent*)AthenaVehicle->RootComponent;

			if (RootComponent)
			{
				FReplicatedAthenaVehiclePhysicsState InState = Params->InState;

				// From Reboot
				InState.Rotation.X -= 2.5;
				InState.Rotation.Y /= 0.3;
				InState.Rotation.Z -= -2.0;
				InState.Rotation.W /= -1.2;

				FTransform Transform{};
				Transform.Translation = InState.Translation;
				Transform.Rotation = InState.Rotation;
				Transform.Scale3D = FVector{ 1, 1, 1 };

				RootComponent->K2_SetWorldTransform(Transform, false, nullptr, true);
				RootComponent->SetPhysicsLinearVelocity(InState.LinearVelocity, 0, FName());
				RootComponent->SetPhysicsAngularVelocity(InState.AngularVelocity, 0, FName());
			}
		}
		else if (FunctionName.contains("OnBuildingActorInitialized"))
		{
			ABuildingTrap* BuildingActor = (ABuildingTrap*)Object;

			if (BuildingActor && BuildingActor->IsA(ABuildingTrap::StaticClass()))
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)BuildingActor->GetOwningController();

				if (!PlayerController)
					return ProcessEvent(Object, Function, Parms);

				AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

				if (!PlayerState)
					return ProcessEvent(Object, Function, Parms);

				BuildingActor->bPlayerPlaced = true;

				BuildingActor->Team = PlayerState->TeamIndex;
				BuildingActor->OnRep_Team();

				FN_LOG(LogTest, Debug, "PlayerState->TeamIndex: %i", PlayerState->TeamIndex);
			}
		}
		else if (FunctionName.contains("OnWorldReady"))
		{
			if (!GameMode::bWorldReady)
			{
				AFortGameStateAthena* GameState = Globals::GetGameState();

				UFortPlaylistAthena* Playlist = UObject::FindObjectSlow<UFortPlaylistAthena>("FortPlaylistAthena Playlist_DefaultSolo.Playlist_DefaultSolo");

				if (GameState && Playlist)
				{
					GameState->CurrentPlaylistData = Playlist;
					GameState->OnRep_CurrentPlaylistData();

					FN_LOG(LogHooks, Debug, "AdditionalLevels.Num() [%i]", Playlist->AdditionalLevels.Num());

					for (int i = 0; i < Playlist->AdditionalLevels.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevel = Playlist->AdditionalLevels[i];

						if (!AdditionalLevel.Get())
							continue;

						FN_LOG(LogHooks, Debug, "AdditionalLevel [%i]: %s", i, AdditionalLevel.Get()->GetFullName().c_str());
					}

					//GameState->OnRep_AdditionalPlaylistLevelsStreamed();

					GameState->AirCraftBehavior = Playlist->AirCraftBehavior;
				}

				Functions::SummonFloorLoots();

				FN_LOG(LogHooks, Debug, "OnWorldReady called!");

				GameMode::bWorldReady = true;
			}
		}

		ProcessEvent(Object, Function, Parms);
	}

	void InitHook()
	{
		uintptr_t AddressLocalSpawnPlayActor = MinHook::FindPattern(Patterns::LocalSpawnPlayActor);
		uintptr_t AddressInternalGetNetMode = MinHook::FindPattern(Patterns::InternalGetNetMode);
		uintptr_t AddressActorInternalGetNetMode = MinHook::FindPattern(Patterns::ActorInternalGetNetMode);
		uintptr_t AddressChangingGameSessionId = MinHook::FindPattern(Patterns::ChangingGameSessionId);
		uintptr_t AddressKickPlayer = MinHook::FindPattern(Patterns::KickPlayer);
		uintptr_t AddressPickupCombine = MinHook::FindPattern(Patterns::PickupCombine);
		uintptr_t AddressPickupDelay = MinHook::FindPattern(Patterns::PickupDelay);
		uintptr_t AddressDispatchRequest = MinHook::FindPattern(Patterns::DispatchRequest);
		uintptr_t AddressGetPlayerViewPoint = MinHook::FindPattern(Patterns::GetPlayerViewPoint);
		//uintptr_t AddressCollectGarbageInternal = MinHook::FindPattern(Patterns::CollectGarbageInternal);

		MH_CreateHook((LPVOID)(AddressLocalSpawnPlayActor), LocalSpawnPlayActorHook, nullptr);
		MH_EnableHook((LPVOID)(AddressLocalSpawnPlayActor));
		MH_CreateHook((LPVOID)(AddressInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressActorInternalGetNetMode), ReturnNetMode, nullptr);
		MH_EnableHook((LPVOID)(AddressActorInternalGetNetMode));
		MH_CreateHook((LPVOID)(AddressChangingGameSessionId), ChangingGameSessionIdHook, nullptr);
		MH_EnableHook((LPVOID)(AddressChangingGameSessionId));
		MH_CreateHook((LPVOID)(AddressKickPlayer), KickPlayerHook, nullptr);
		MH_EnableHook((LPVOID)(AddressKickPlayer));
		MH_CreateHook((LPVOID)(AddressPickupCombine), PickupCombineHook, (LPVOID*)(&PickupCombine));
		MH_EnableHook((LPVOID)(AddressPickupCombine));
		MH_CreateHook((LPVOID)(AddressPickupDelay), PickupDelayHook, (LPVOID*)(&PickupDelay));
		MH_EnableHook((LPVOID)(AddressPickupDelay));
		MH_CreateHook((LPVOID)(AddressDispatchRequest), DispatchRequestHook, (LPVOID*)(&DispatchRequest));
		MH_EnableHook((LPVOID)(AddressDispatchRequest));
		MH_CreateHook((LPVOID)(AddressGetPlayerViewPoint), GetPlayerViewPointHook, (LPVOID*)(&GetPlayerViewPoint));
		MH_EnableHook((LPVOID)(AddressGetPlayerViewPoint));
		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960), CollectGarbageInternalHook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960));*/

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEventHook, (LPVOID*)(&ProcessEvent));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}