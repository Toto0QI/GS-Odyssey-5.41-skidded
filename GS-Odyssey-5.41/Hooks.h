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
	ABuildingTrap* (*ServerSpawnDeco)(AFortDecoTool* DecoTool, UClass* Class, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType);
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

	int32 CubeIndex = 561;

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

	void PickupAddInventoryOwnerInterfaceHook(AFortPickup* Pickup, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner)
	{
		if (!Pickup)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupAddInventoryOwnerInterface] Failed to get Pickup.");
			return;
		}

		FFortPickupLocationData* PickupLocationData = &Pickup->PickupLocationData;
		FFortItemEntry* ItemEntry = &Pickup->PrimaryPickupItemEntry;

		if (!PickupLocationData || !ItemEntry)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupAddInventoryOwnerInterface] Failed to get PickupLocationData/ItemEntry!");
			return;
		}

		UObject* ObjectRef = InventoryOwner.GetObjectRef();

		FN_LOG(LogHooks, Debug, "PickupAddInventoryOwnerInterfaceHook - ObjectRef: %s", ObjectRef->GetName().c_str());
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

				UFortResourceItemDefinition;
			}

			if (GetAsyncKeyState(VK_F2) & 0x1)
			{

			}

			if (GetAsyncKeyState(VK_F3) & 0x1)
			{
				TArray<AActor*> OutActors;
				UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), ACUBE_C::StaticClass(), &OutActors);

				for (int32 i = 0; i < OutActors.Num(); i++)
				{
					ACUBE_C* CUBE = (ACUBE_C*)OutActors[i];
					if (!CUBE) continue;

					CUBE->Next(CubeIndex);

					CubeIndex++;

					FN_LOG(LogHooks, Debug, "CubeIndex: %i", CubeIndex);
				}


				// 7FF66F6694B0
				/*char (*Restart)(AFortGameSessionDedicated* GameSession) = decltype(Restart)(0x10194B0 + uintptr_t(GetModuleHandle(0)));

				char Result = Restart((AFortGameSessionDedicated*)Globals::GetGameMode()->FortGameSession);

				GameMode::bPreReadyToStartMatch = false;
				GameMode::bWorldReady = false;

				FN_LOG(LogHooks, Debug, "Restart called, Result: %i", Result);*/

			}

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				Pawn->K2_TeleportTo(FVector(0, 0, 5000), FRotator());

				AFortGameModeAthena;
				AFortGameStateAthena;

				UKismetGuidLibrary::NewGuid();

				UKismetMathLibrary::Abs(10.f);

				/*UAthenaSeasonItemDefinition* Season5 = StaticLoadObject<UAthenaSeasonItemDefinition>(L"/Game/Athena/Items/Seasons/AthenaSeason5.AthenaSeason5");

				if (Season5)
				{
					FN_LOG(LogHooks, Debug, "SeasonNumber: %i", Season5->SeasonNumber);
					FN_LOG(LogHooks, Debug, "NumSeasonLevels: %i", Season5->NumSeasonLevels);
					FN_LOG(LogHooks, Debug, "NumBookLevels: %i", Season5->NumBookLevels);
					FN_LOG(LogHooks, Debug, "SeasonStorefront: %s", Season5->SeasonStorefront.ToString().c_str());
					FN_LOG(LogHooks, Debug, "FreeLevelsThatNavigateToBattlePass: %i", Season5->FreeLevelsThatNavigateToBattlePass.Num());
					FN_LOG(LogHooks, Debug, "FreeLevelsThatAutoOpenTheAboutScreen: %i", Season5->FreeLevelsThatAutoOpenTheAboutScreen.Num());

					TArray<FAthenaRewardScheduleLevel> BookXpScheduleFrees = Season5->BookXpScheduleFree.Levels;

					for (int32 i = 0; i < BookXpScheduleFrees.Num(); i++)
					{
						FAthenaRewardScheduleLevel BookXpScheduleFree = BookXpScheduleFrees[i];

						for (int32 j = 0; j < BookXpScheduleFree.Rewards.Num(); j++)
						{
							FAthenaRewardItemReference Reward = BookXpScheduleFree.Rewards[j];

							if (!Reward.ItemDefinition.Get())
								continue;

							FN_LOG(LogHooks, Debug, "[%i] - BookXpScheduleFrees - ItemDefinition: %s, Quantity: %i", i, Reward.ItemDefinition.Get()->GetName().c_str(), Reward.Quantity);
						}
					}

					TArray<FAthenaRewardScheduleLevel> BookXpSchedulePaids = Season5->BookXpSchedulePaid.Levels;

					for (int32 i = 0; i < BookXpSchedulePaids.Num(); i++)
					{
						FAthenaRewardScheduleLevel BookXpSchedulePaid = BookXpSchedulePaids[i];

						for (int32 j = 0; j < BookXpSchedulePaid.Rewards.Num(); j++)
						{
							FAthenaRewardItemReference Reward = BookXpSchedulePaid.Rewards[j];

							if (!Reward.ItemDefinition.Get())
								continue;

							FN_LOG(LogHooks, Debug, "[%i] - BookXpSchedulePaids - ItemDefinition: %s, Quantity: %i", i, Reward.ItemDefinition.Get()->GetName().c_str(), Reward.Quantity);
						}
					}

					TArray<FAthenaRewardItemReference> SeasonGrantsToEveryones = Season5->SeasonGrantsToEveryone.Rewards;

					for (int32 i = 0; i < SeasonGrantsToEveryones.Num(); i++)
					{
						FAthenaRewardItemReference SeasonGrantsToEveryone = SeasonGrantsToEveryones[i];

						if (!SeasonGrantsToEveryone.ItemDefinition.Get())
							continue;

						FN_LOG(LogHooks, Debug, "[%i] - BookXpSchedulePaids - ItemDefinition: %s, Quantity: %i, i", i, SeasonGrantsToEveryone.ItemDefinition.Get()->GetName().c_str(), SeasonGrantsToEveryone.Quantity);
					}
				}*/
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Globals::GetGameplayStatics()->GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				static auto Nigger = FindObjectFast<UFortWeaponRangedItemDefinition>("/Game/Athena/Items/Weapons/WID_Pistol_HandCannon_Athena_SR_Ore_T03.WID_Pistol_HandCannon_Athena_SR_Ore_T03");

				FFortItemEntry ItemEntry;
				Inventory::CreateDefaultItemEntry(&ItemEntry, Nigger, 1, 0);

				Inventory::CreateSimplePickup(PlayerController, &ItemEntry, Pawn->K2_GetActorLocation(), FRotator());





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

				//MinHook::FindIndexVTable((UObject*)IdkDefault, 0x0, 0x21);
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
		else if (FunctionName.contains("OnWorldReady"))
		{
			if (!GameMode::bWorldReady)
			{
				AFortGameStateAthena* GameState = Globals::GetGameState();
				AFortGameModeAthena* GameMode = Globals::GetGameMode();

				// int32 PlaylistId = 2; // Solo
				//int32 PlaylistId = 10; // Duo
				// int32 PlaylistId = 9; // Squad
				int32 PlaylistId = 35; // Playground
				// int32 PlaylistId = 50; // 50VS50

				// int32 PlaylistId = 140; // Bling (Solo)

				// 7FF66F2504C0
				void (*SetCurrentPlaylistId)(AFortGameModeAthena* GameMode, int32 NewPlaylistId) = decltype(SetCurrentPlaylistId)(0xC004C0 + uintptr_t(GetModuleHandle(0)));

				SetCurrentPlaylistId(Globals::GetGameMode(), PlaylistId);

				// 7FF66F52DEC0
				UFortPlaylistAthena* (*GetPlaylistByPlaylistId)(UFortPlaylistManager* PlaylistManager, int32 PlaylistId) = decltype(GetPlaylistByPlaylistId)(0xEDDEC0 + uintptr_t(GetModuleHandle(0)));

				UFortPlaylistAthena* Playlist = GetPlaylistByPlaylistId(GameMode->PlaylistManager, PlaylistId);

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

					// GameState->OnRep_AdditionalPlaylistLevelsStreamed();

					GameState->AirCraftBehavior = Playlist->AirCraftBehavior;

					AFortGameSessionDedicated* GameSession = (AFortGameSessionDedicated*)Globals::GetGameMode()->GameSession;

					GameSession->MaxPlayers = Playlist->MaxPlayers;
					GameSession->MaxPartySize = Playlist->MaxSocialPartySize;

					GameMode->PlaylistManager;
					GameMode->CurrentZoneInstanceId;
				}

				Functions::SummonFloorLoots();

				FN_LOG(LogHooks, Debug, "OnWorldReady called!");

				GameMode::bWorldReady = true;
			}
		}

		ProcessEvent(Object, Function, Parms);
	}

	ABuildingTrap* ServerSpawnDecoHook(AFortDecoTool* DecoTool, UClass* Class, const FVector& Location, const FRotator& Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType)
	{
		ABuildingTrap* Result = ServerSpawnDeco(DecoTool, Class, Location, Rotation, AttachedActor, InBuildingAttachmentType);

		if (Result)
		{
			// 7FF66F971DB0
			AFortPlayerController* (*GetPlayerControllerFromInstigator)(AFortDecoTool* DecoTool) = decltype(GetPlayerControllerFromInstigator)(0x1321DB0 + uintptr_t(GetModuleHandle(0)));
			AFortPlayerController* PlayerController = GetPlayerControllerFromInstigator(DecoTool);

			if (!PlayerController)
			{
				FN_LOG(LogHooks, Error, "[AFortDecoTool::ServerSpawnDeco] Failed to get PlayerController!");
				return Result;
			}

			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (!PlayerState)
			{
				FN_LOG(LogHooks, Error, "[AFortDecoTool::ServerSpawnDeco] Failed to get PlayerState!");
				return Result;
			}

			Result->bPlayerPlaced = true;
			Result->Team = PlayerState->TeamIndex;
		}

		return Result;
	}

	AActor* (*BeginDeferredActorSpawnFromClass)(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, bool bNoCollisionFail, AActor* Owner);
	AActor* BeginDeferredActorSpawnFromClassHook(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, bool bNoCollisionFail, AActor* Owner)
	{
		if (!WorldContextObject)
			return nullptr;

		UFortBuildingInstructions;

		UClass* ActorClassNegro = ActorClass.Get();

		if (!ActorClassNegro)
		{
			uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
			uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

			FN_LOG(LogMinHook, Log, "Function [BeginDeferredActorSpawnFromClassHook] successfully hooked with Offset [0x%llx], IdaAddress [%p]", (unsigned long long)Offset, IdaAddress);
			return nullptr;
		}

		FN_LOG(LogHooks, Debug, "BeginDeferredActorSpawnFromClassHook WorldContextObject: %s, ActorClassNegro: %s", WorldContextObject->GetName().c_str(), ActorClassNegro->GetName().c_str());

		return BeginDeferredActorSpawnFromClass(WorldContextObject, ActorClass, SpawnTransform, bNoCollisionFail, Owner);
	}

	void (*sub_7FF66F247000)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController);
	void sub_7FF66F247000Hook(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController)
	{
		AFortGameSession;

		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "Function [sub_7FF66F247000Hook], Offset [0x%llx], IdaAddress [%p], GameMode: [%s], PlayerController: [%s]", (unsigned long long)Offset, IdaAddress, GameMode->GetName().c_str(), PlayerController->GetName().c_str());

		// Function [sub_7FF66F247000Hook], Offset [0xe3f06c], IdaAddress [00007FF66F48F06C], GameMode: [Athena_GameMode_C_0], PlayerState: [Athena_PlayerController_C_0]

		sub_7FF66F247000(GameMode, PlayerController);
	}

	void (*CreateDedicatedSession)(AFortGameSessionDedicated* GameSession);
	void CreateDedicatedSessionHook(AFortGameSessionDedicated* GameSession)
	{
		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "Function [CreateDedicatedSessionHook], Offset [0x%llx], IdaAddress [%p], GameSession: [%s]", (unsigned long long)Offset, IdaAddress, GameSession->GetName().c_str());

		// Function [CreateDedicatedSessionHook], Offset [0x6e6ac30a0], IdaAddress [00007FFD551130A0], GameMode: [FortGameSession_0], PlayerController: [FortGameSession_0]

		CreateDedicatedSession(GameSession);
	}

	__int64 (*Testergergre)(AFortPickup* Pickup);
	__int64 TestergergreHook(AFortPickup* Pickup)
	{
		FN_LOG(LogMinHook, Log, "TestergergreHook: %s", Pickup->GetName().c_str());
		return Testergergre(Pickup);
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
		uintptr_t AddressServerSpawnDeco = MinHook::FindPattern(Patterns::ServerSpawnDeco);

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
		MH_CreateHook((LPVOID)(AddressServerSpawnDeco), ServerSpawnDecoHook, (LPVOID*)(&ServerSpawnDeco));
		MH_EnableHook((LPVOID)(AddressServerSpawnDeco));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960), CollectGarbageInternalHook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x24FB490), BeginDeferredActorSpawnFromClassHook, (LPVOID*)(&BeginDeferredActorSpawnFromClass));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x24FB490));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xBF7000), sub_7FF66F247000Hook, (LPVOID*)(&sub_7FF66F247000));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xBF7000));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10084B0), CreateDedicatedSessionHook, (LPVOID*)(&CreateDedicatedSession));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10084B0));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEventHook, (LPVOID*)(&ProcessEvent));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		MinHook::HookVTable(AFortPickup::GetDefaultObj(), 0xBF, PickupAddInventoryOwnerInterfaceHook, nullptr, "PickupAddInventoryOwnerInterfaceHook");
		MinHook::HookVTable(AFortPickup::GetDefaultObj(), 0x159, TestergergreHook, (LPVOID*)(&Testergergre), "TestergergreHook");

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}