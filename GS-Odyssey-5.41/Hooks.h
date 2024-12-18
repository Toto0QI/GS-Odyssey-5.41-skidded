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
	void (*GetPlayerViewPoint)(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation);
	void (*ProcessEvent)(UObject* Object, UFunction* Function, void* Parms);
	void (*DispatchRequest)(UMcpProfileGroup* McpProfileGroup, FProfileHttpRequest* ProfileHttpRequest);
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

	void DispatchRequestHook(UMcpProfileGroup* McpProfileGroup, FProfileHttpRequest* ProfileHttpRequest)
	{
		*(int32*)(__int64(ProfileHttpRequest) + 0x28) = 3;

		DispatchRequest(McpProfileGroup, ProfileHttpRequest);
	}

	FVector GetPawnViewLocation(APawn* Pawn)
	{
		return Pawn->K2_GetActorLocation() + FVector(0.f, 0.f, Pawn->BaseEyeHeight);
	}

	void GetPlayerViewPointHook(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		APawn* Pawn = PlayerController->Pawn;
		ASpectatorPawn* SpectatorPawn = PlayerController->GetSpectatorPawn();

		if (Pawn)
		{
			out_Location = Pawn->K2_GetActorLocation();
			out_Rotation = PlayerController->GetControlRotation();
			return;
		}
		else if (SpectatorPawn && PlayerController->HasAuthority())
		{
			out_Location = SpectatorPawn->K2_GetActorLocation();
			out_Rotation = ((APlayerController*)SpectatorPawn->Owner)->GetControlRotation();
			return;
		}
		else if (!SpectatorPawn && !Pawn)
		{
			out_Location = PlayerController->LastSpectatorSyncLocation;
			out_Rotation = PlayerController->LastSpectatorSyncRotation;
			return;
		}

		GetPlayerViewPoint(PlayerController, out_Location, out_Rotation);
	}

	int32 CubeIndex = 561;

	bool bLogs = false;

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
		{
			ProcessEvent(Object, Function, Parms);
			return;
		}

		bool bCallOG = true;

#ifdef ANTICHEAT
		AntiCheatOdyssey::ProcessEventHook(Object, Function, Parms);
#endif // ANTICHEAT

#ifdef BOTS
		BotOdyssey::ProcessEventHook(Object, Function, Parms);
#endif // BOTS-

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				/*FFortItemEntry ItemEntry;
				Inventory::MakeItemEntry(&ItemEntry, Globals::GetGameData()->WoodItemDefinition, 30, 0, 0, 1.0f);

				FVector SpawnLocation = Pawn->K2_GetActorLocation();
				FRotator SpawnRotation = FRotator({ 0, 0, 0 });

				FFortCreatePickupData CreatePickupData = FFortCreatePickupData();
				CreatePickupData.World = Globals::GetWorld();
				CreatePickupData.ItemEntry = &ItemEntry;
				CreatePickupData.SpawnLocation = &SpawnLocation;
				CreatePickupData.SpawnRotation = &SpawnRotation;
				CreatePickupData.PlayerController = nullptr;
				CreatePickupData.OverrideClass = nullptr;
				CreatePickupData.NullptrIdk = nullptr;
				CreatePickupData.bRandomRotation = true;
				CreatePickupData.PickupSourceTypeFlags = 0;

				Inventory::CreatePickupFromData(&CreatePickupData);*/
			}

			if (GetAsyncKeyState(VK_F2) & 0x1)
			{

			}

			if (GetAsyncKeyState(VK_F3) & 0x1)
			{
				AFortPlayerControllerAthena* PlayerController = Cast<AFortPlayerControllerAthena>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerController || !PlayerController->WorldInventory)
					return;
				
				AFortPlayerPawnAthena* PlayerPawn = Cast<AFortPlayerPawnAthena>(PlayerController->MyFortPawn);
				AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

				if (!PlayerPawn || !PlayerState)
					return;

			}

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController || !PlayerController->Pawn)
					return;
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				/*
					OdysseyLog: LogHook: Debug: Index not found: 0x0, Offset: 0xc17a88, IdaAddress [00007FF66F267A88] - Pleins de Free Memory
					OdysseyLog: LogHook: Debug: Index not found: 0x1, Offset: 0xc3b978, IdaAddress [00007FF66F28B978] - Baka
					OdysseyLog: LogHook: Debug: Index not found: 0x2, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x3, Offset: 0xc26310, IdaAddress [00007FF66F276310] - Return un truc zebi jsp quoi ------- Return un role je crois
					OdysseyLog: LogHook: Debug: Index not found: 0x4, Offset: 0x2ccbb0, IdaAddress [00007FF66E91CBB0] - WITH_SERVER_CODE (return 1)
					OdysseyLog: LogHook: Debug: Index not found: 0x5, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x6, Offset: 0x3992a0, IdaAddress [00007FF66E9E92A0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x7, Offset: 0x11b3850, IdaAddress [00007FF66F803850] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0x8, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0x9, Offset: 0xc24970, IdaAddress [00007FF66F274970] - GetCurrentWeapon
					OdysseyLog: LogHook: Debug: Index not found: 0xa, Offset: 0xc269f0, IdaAddress [00007FF66F2769F0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xb, Offset: 0xc28ad0, IdaAddress [00007FF66F278AD0] - Return un truc zebi jsp quoi
					OdysseyLog: LogHook: Debug: Index not found: 0xc, Offset: 0x11beef0, IdaAddress [00007FF66F80EEF0] - ModifyDurability
					OdysseyLog: LogHook: Debug: Index not found: 0xd, Offset: 0x11d8640, IdaAddress [00007FF66F828640] - ModifyLoadedAmmo
					OdysseyLog: LogHook: Debug: Index not found: 0xe, Offset: 0x11c60b0, IdaAddress [00007FF66F8160B0] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0xf, Offset: 0x11c6010, IdaAddress [00007FF66F816010] - Un truc stw je crois
					OdysseyLog: LogHook: Debug: Index not found: 0x10, Offset: 0xc28550, IdaAddress [00007FF66F278550] - La fonction est énorme
					OdysseyLog: LogHook: Debug: Index not found: 0x11, Offset: 0x11a9910, IdaAddress [00007FF66F7F9910] - UFortItem* FindExistingItemForDefinition(void* InventoryOwner, const UFortItemDefinition* ItemDefinition, bool bInStorageVault)
					OdysseyLog: LogHook: Debug: Index not found: 0x12, Offset: 0x11a9c40, IdaAddress [00007FF66F7F9C40] - bool (*FindItemInstancesFromDefinition)(void* InventoryOwner, UFortItemDefinition* ItemDefinition, TArray<UFortItem*>& ItemArray)
					OdysseyLog: LogHook: Debug: Index not found: 0x13, Offset: 0x11ae410, IdaAddress [00007FF66F7FE410] - UFortItem* GetInventoryItemWithGuid(void* InventoryOwner, const FGuid& ItemGuid)
					OdysseyLog: LogHook: Debug: Index not found: 0x14, Offset: 0x11d1cc0, IdaAddress [00007FF66F821CC0] - RemoveInventoryItem
					OdysseyLog: LogHook: Debug: Index not found: 0x15, Offset: 0xc17ba0, IdaAddress [00007FF66F267BA0] - Pleins de Free Memory ------------------------- Je crois qu'on change de class
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
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

				if (!PlayerPawn)
					return;

#ifdef BOTS
				AAIBotOdyssey* BotOdyssey = CreateBotOdyssey();

				if (BotOdyssey)
				{
					BotOdyssey->SetTargetActor(PlayerPawn);
				}
#endif // BOTS
			}

			if (GetAsyncKeyState(VK_F7) & 0x1)
			{
				bLogs = bLogs ? false : true;
				FN_LOG(LogHooks, Log, L"bLogs set to %i", bLogs);
				return;
			}

			if (GetAsyncKeyState(VK_F9) & 0x1)
			{
				AFortPlayerController* PlayerControllerGGGG = Cast<AFortPlayerController>(UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0));

				if (!PlayerControllerGGGG)
					return;

				AFortPlayerPawn* PlayerPawnFFFF = PlayerControllerGGGG->MyFortPawn;

				if (!PlayerPawnFFFF)
					return;


				AAthena_PlayerController_C* PlayerControllerAthena = Util::SpawnActor<AAthena_PlayerController_C>(AAthena_PlayerController_C::StaticClass());
				AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

				if (PlayerControllerAthena && GameModeAthena)
				{
					// 7FF66F247000
					void (*ChoosePlayerTeam)(AFortGameModeAthena* GameModeAthena, AFortPlayerControllerAthena* PlayerController) = decltype(ChoosePlayerTeam)(0xBF7000 + uintptr_t(GetModuleHandle(0)));
					ChoosePlayerTeam(GameModeAthena, PlayerControllerAthena);

					GameModeAthena->AddFromAlivePlayers(PlayerControllerAthena);

					AFortInventory* WorldInventory = PlayerControllerAthena->WorldInventory;

					if (!WorldInventory)
					{
						WorldInventory = Util::SpawnActor<AFortInventory>(AFortInventory::StaticClass());

						if (WorldInventory)
						{
							WorldInventory->SetOwner(PlayerControllerAthena);
							WorldInventory->OnRep_Owner();

							PlayerControllerAthena->WorldInventory = WorldInventory;
							PlayerControllerAthena->bHasInitializedWorldInventory = true;
							PlayerControllerAthena->WorldInventory->HandleInventoryLocalUpdate();
						}
					}

					AFortQuickBars* QuickBars = PlayerControllerAthena->QuickBars;

					if (!QuickBars)
					{
						QuickBars = Util::SpawnActor<AFortQuickBars>(AFortQuickBars::StaticClass());

						if (QuickBars)
						{
							QuickBars->SetOwner(PlayerControllerAthena);
							QuickBars->OnRep_Owner();

							PlayerControllerAthena->QuickBars = QuickBars;
							PlayerControllerAthena->OnRep_QuickBar();
						}
					}

					AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerControllerAthena, PlayerPawnFFFF->K2_GetActorLocation(), FRotator(), true);
					AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerControllerAthena->PlayerState);
					UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

					if (!AbilitySystemComponent)
						AbilitySystemComponent = Cast<UFortAbilitySystemComponent>(UGameplayStatics::SpawnObject(UFortAbilitySystemComponent::StaticClass(), PlayerState));

					if (PlayerPawn && PlayerState && AbilitySystemComponent)
					{
						PlayerPawn->bCanBeDamaged = true;

						// 7FF66EC68170
						void (*ClearAllAbilities)(UAbilitySystemComponent* AbilitySystemComponent) = decltype(ClearAllAbilities)(0x618170 + uintptr_t(GetModuleHandle(0)));
						ClearAllAbilities(PlayerState->AbilitySystemComponent);

						UFortAbilitySet* DefaultAbilities = Globals::GetGameData()->GenericPlayerAbilitySet.Get();

						Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
						Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
						Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);

						PlayerState->ApplyCharacterCustomization(PlayerPawn);
					}
				}
			}

			if (GetAsyncKeyState(VK_F10) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				void* InventoryOwnerInterface = PlayerController->GetInterfaceAddress(IFortInventoryOwnerInterface::StaticClass());

				TScriptInterface<IFortInventoryOwnerInterface> ScriptInterface{};
				ScriptInterface.SetInterface(InventoryOwnerInterface);
				ScriptInterface.SetObject(PlayerController);

				UFortKismetLibrary::GiveItemToInventoryOwner(ScriptInterface, Globals::GetGameData()->WoodItemDefinition, 10, true);

				FN_LOG(LogHooks, Log, L"GiveItemToInventoryOwner");
			}

			if (GetAsyncKeyState(VK_F12) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"SPAWNLLAMA", PlayerController);
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
			AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

			if (!GameModeAthena)
				return;

			AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

			if (!GameStateAthena)
				return;

			if (!GameModeAthena->bWorldIsReady)
			{
				float ServerWorldTimeSeconds = UGameplayStatics::GetTimeSeconds(GameModeAthena) + GameStateAthena->ServerWorldTimeSecondsDelta;
				float Duration = 300.0f; // Seconds

				UFortPlaylistAthena* PlaylistAthena = Globals::GetPlaylist();

				if (PlaylistAthena && GameStateAthena)
				{
					/*GameStateAthena->WarmupCountdownStartTime = Duration;
					GameStateAthena->WarmupCountdownEndTime = ServerWorldTimeSeconds + Duration;

					GameModeAthena->WarmupEarlyCountdownDuration = ServerWorldTimeSeconds;
					GameModeAthena->WarmupCountdownDuration = Duration;*/

					for (int32 i = 0; i < PlaylistAthena->AdditionalLevels.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevel = PlaylistAthena->AdditionalLevels[i];

						FName FoundationName = AdditionalLevel.ObjectID.AssetPathName;
						if (!FoundationName.IsValid()) continue;

						bool bSuccess = false;
						ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GameStateAthena, AdditionalLevel, FVector(), FRotator(), &bSuccess);

						if (bSuccess)
						{
							FName LevelName = AdditionalLevel.ObjectID.AssetPathName;
							if (!LevelName.IsValid()) continue;

							GameStateAthena->AdditionalPlaylistLevelsStreamed.Add(LevelName);
						}
					}

					GameStateAthena->OnRep_AdditionalPlaylistLevelsStreamed();
				}

				Functions::InitializeTreasureChests();
				Functions::InitializeAmmoBoxs();
				Functions::InitializeLlamas();
				Functions::InitializeConsumableBGAs();

				Functions::FillVendingMachines();

				FN_LOG(LogHooks, Log, L"OnWorldReady called!");
				GameModeAthena->bWorldIsReady = true;
			}
		}

		if (bLogs)
		{
			if (!FunctionName.contains("Tick") &&
				!FunctionName.contains("Visual") &&
				!FunctionName.contains("Clown Spinner") &&
				!FunctionName.contains("CustomStateChanged") &&
				!FunctionName.contains("ReceiveBeginPlay") &&
				!FunctionName.contains("OnAttachToBuilding") &&
				!FunctionName.contains("OnWorldReady") &&
				!FunctionName.contains("K2_GetActorLocation") &&
				!FunctionName.contains("ReceiveDrawHUD") &&
				!FunctionName.contains("ServerUpdateCamera") &&
				!FunctionName.contains("ServerMove") &&
				!FunctionName.contains("ContrailCheck") &&
				!FunctionName.contains("GetViewTarget") &&
				!FunctionName.contains("GetAllActorsOfClass") &&
				!FunctionName.contains("ClientAckGoodMove") &&
				!FunctionName.contains("ReadyToEndMatch") &&
				!FunctionName.contains("Check Closest Point") &&
				!FunctionName.contains("ServerTriggerCombatEvent") &&
				!FunctionName.contains("UpdateTime") &&
				!FunctionName.contains("OnUpdateMusic") &&
				!FunctionName.contains("UpdateStateEvent") &&
				!FunctionName.contains("ServerTouchActiveTime") &&
				!FunctionName.contains("OnCheckIfSurrounded") &&
				!FunctionName.contains("ServerFireAIDirectorEventBatch") &&
				!FunctionName.contains("ServerTriggerCombatEventBatch") &&
				!FunctionName.contains("UserConstructionScript") &&
				!FunctionName.contains("K2_OnReset") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ReceiveUnpossessed") &&
				!FunctionName.contains("ClientGotoState") &&
				!FunctionName.contains("K2_OnEndViewTarget") &&
				!FunctionName.contains("K2_OnBecomeViewTarget") &&
				!FunctionName.contains("ClientSetViewTarget") &&
				!FunctionName.contains("ServerClientPawnLoaded") &&
				!FunctionName.contains("ReceiveEndPlay") &&
				!FunctionName.contains("OnPerceptionStimuliSourceEndPlay") &&
				!FunctionName.contains("HandleOnHUDElementVisibilityChanged") &&
				!FunctionName.contains("OnHUDElementVisibilityChanged") &&
				!FunctionName.contains("HandleInteractionChanged") &&
				!FunctionName.contains("BlueprintModifyCamera") &&
				!FunctionName.contains("BlueprintModifyPostProcess") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("ServerFireAIDirectorEvent") &&
				!FunctionName.contains("ServerTryActivateAbility") &&
				!FunctionName.contains("ClientActivateAbilitySucceed") &&
				!FunctionName.contains("ServerSetSpectatorLocation") &&
				!FunctionName.contains("CanJumpInternal") &&
				!FunctionName.contains("K2_OnMovementModeChanged") &&
				!FunctionName.contains("OnJumped") &&
				!FunctionName.contains("ServerModifyStat") &&
				!FunctionName.contains("OnLanded") &&
				!FunctionName.contains("ReceiveHit") &&
				!FunctionName.contains("OnWalkingOffLedge") &&
				!FunctionName.contains("ServerEndAbility") &&
				!FunctionName.contains("Execute") &&
				!FunctionName.contains("OnDamagePlayEffects") &&
				!FunctionName.contains("OnMontageStarted") &&
				!FunctionName.contains("OnNewDamageNumber") &&
				!FunctionName.contains("BP_GetTokenizedDescriptionText") &&
				!FunctionName.contains("GameplayCue_InstantDeath") &&
				!FunctionName.contains("K2_GetActorRotation") &&
				!FunctionName.contains("K2_DestroyActor") &&
				!FunctionName.contains("OnDetachFromBuilding") &&
				!FunctionName.contains("OnRep_bAlreadySearched") &&
				!FunctionName.contains("OnSetSearched") &&
				!FunctionName.contains("GetAircraft") &&
				!FunctionName.contains("BeginSpawningActorFromClass") &&
				!FunctionName.contains("BlueprintInitializeAnimation") &&
				!FunctionName.contains("BlueprintUpdateAnimation") &&
				!FunctionName.contains("BlueprintPostEvaluateAnimation") &&
				!FunctionName.contains("FinishSpawningActor") &&
				!FunctionName.contains("PawnUniqueIDSet") &&
				!FunctionName.contains("OnRep_Owner") &&
				!FunctionName.contains("OnRep_Pawn") &&
				!FunctionName.contains("Possess") &&
				!FunctionName.contains("ReceivePossessed") &&
				!FunctionName.contains("ClientRestart") &&
				!FunctionName.contains("SetControlRotation") &&
				!FunctionName.contains("ClientRetryClientRestart") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena_Generic") &&
				!FunctionName.contains("ExecuteUbergraph_PlayerPawn_Athena") &&
				!FunctionName.contains("ServerAcknowledgePossession") &&
				!FunctionName.contains("IsInAircraft") &&
				!FunctionName.contains("FindPlayerStart") &&
				!FunctionName.contains("SpawnDefaultPawnFor") &&
				!FunctionName.contains("MustSpectate") &&
				!FunctionName.contains("GetDefaultPawnClassForController") &&
				!FunctionName.contains("On Game Phase Change") &&
				!FunctionName.contains("ClientAdjustPosition") &&
				!FunctionName.contains("Movement Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("Holding Audio Crossfader__UpdateFunc") &&
				!FunctionName.contains("OnUpdateDirectionalLightForTimeOfDay") &&
				!FunctionName.contains("OnMontageEnded") &&
				!FunctionName.contains("ServerCancelAbility") &&
				!FunctionName.contains("K2_ActivateAbility") &&
				!FunctionName.contains("ServerHandleMissionEvent_ToggledCursorMode") &&
				!FunctionName.contains("OnBlendOut_") &&
				!FunctionName.contains("ClientEndAbility") &&
				!FunctionName.contains("OnSafeZoneStateChange") &&
				!FunctionName.contains("ClientVeryShortAdjustPosition") &&
				!FunctionName.contains("OnDayPhaseChange") &&
				!FunctionName.contains("On Day Phase Change") &&
				!FunctionName.contains("K2_OnStartCrouch") &&
				!FunctionName.contains("K2_OnEndCrouch") &&
				!FunctionName.contains("On Player Won") &&
				!FunctionName.contains("ClientFinishedInteractionInZone") &&
				!FunctionName.contains("ClientReceiveKillNotification") &&
				!FunctionName.contains("ReceiveCopyProperties") &&
				!FunctionName.contains("K2_OnLogout") &&
				!FunctionName.contains("ClientReceiveLocalizedMessage") &&
				!FunctionName.contains("ClientCancelAbility") &&
				!FunctionName.contains("ServerFinishedInteractionInZoneReport") &&
				!FunctionName.contains("FallingTimeline__UpdateFunc") &&
				!FunctionName.contains("BndEvt__InterceptCollision_K2Node_ComponentBoundEvent_5_ComponentBeginOverlapSignature__DelegateSignature") &&
				!FunctionName.contains("ReceiveActorBeginOverlap") &&
				!FunctionName.contains("Conv_StringToName") &&
				!FunctionName.contains("OnRep_GamePhase") &&
				!FunctionName.contains("K2_OnSetMatchState") &&
				!FunctionName.contains("StartPlay") &&
				!FunctionName.contains("StartMatch") &&
				!FunctionName.contains("OnAircraftEnteredDropZone") &&
				!FunctionName.contains("ServerShortTimeout") &&
				!FunctionName.contains("UpdateStateWidgetContent") &&
				!FunctionName.contains("PreConstruct") &&
				!FunctionName.contains("Construct") &&
				!FunctionName.contains("OnCurrentTextStyleChanged") &&
				!FunctionName.contains("UpdateButtonState") &&
				!FunctionName.contains("OnBangStateChanged") &&
				!FunctionName.contains("OnPlayerInfoChanged") &&
				!FunctionName.contains("Update") &&
				!FunctionName.contains("OnBeginIntro") &&
				!FunctionName.contains("HandleQuickBarChangedBP") &&
				!FunctionName.contains("HandleInventoryUpdatedEvent") &&
				!FunctionName.contains("OnActivated") &&
				!FunctionName.contains("OnBeginOutro") &&
				!FunctionName.contains("HandleActiveWidgetDeactivated") &&
				!FunctionName.contains("OnDeactivated") &&
				!FunctionName.contains("OnStateStarted") &&
				!FunctionName.contains("SetRenderTransform") &&
				!FunctionName.contains("OnAnimationFinished") &&
				!FunctionName.contains("ReadyToStartMatch") &&
				!FunctionName.contains("SetWidthOverride") &&
				!FunctionName.contains("SetHeightOverride") &&
				!FunctionName.contains("HandleMinimizeFinished") &&
				!FunctionName.contains("ServerUpdateLevelVisibility") &&
				!FunctionName.contains("OnDayPhaseChanged") &&
				!FunctionName.contains("On Game Phase Step Changed") &&
				!FunctionName.contains("SetColorAndOpacity") &&
				!FunctionName.contains("OnAnimationStarted") &&
				!FunctionName.contains("UpdateMessaging") &&
				!FunctionName.contains("ServerSendLoadoutConfig") &&
				!FunctionName.contains("CalculateBaseMagnitude") &&
				!FunctionName.contains("ClientRegisterWithParty") &&
				!FunctionName.contains("InitializeHUDForPlayer") &&
				!FunctionName.contains("ClientSetHUD") &&
				!FunctionName.contains("ClientEnableNetworkVoice") &&
				!FunctionName.contains("ClientUpdateMultipleLevelsStreamingStatus") &&
				!FunctionName.contains("ClientFlushLevelStreaming") &&
				!FunctionName.contains("ClientOnGenericPlayerInitialization") &&
				!FunctionName.contains("ClientCapBandwidth") &&
				!FunctionName.contains("K2_PostLogin") &&
				!FunctionName.contains("OnRep_bHasStartedPlaying") &&
				!FunctionName.contains("ServerChoosePart") &&
				!FunctionName.contains("SetOwner") &&
				!FunctionName.contains("OnRep_QuickBar") &&
				!FunctionName.contains("HandleStartingNewPlayer") &&
				!FunctionName.contains("ServerUpdateMultipleLevelsVisibility") &&
				!FunctionName.contains("ServerSetPartyOwner") &&
				!FunctionName.contains("PlayerCanRestart") &&
				!FunctionName.contains("ServerCreateCombatManager") &&
				!FunctionName.contains("ServerCreateAIDirectorDataManager") &&
				!FunctionName.contains("EnableSlot") &&
				!FunctionName.contains("DisableSlot") &&
				!FunctionName.contains("ServerSetShowHeroBackpack") &&
				!FunctionName.contains("ServerSetShowHeroHeadAccessories") &&
				!FunctionName.contains("ServerSetClientHasFinishedLoading") &&
				!FunctionName.contains("ServerReadyToStartMatch") &&
				!FunctionName.contains("Received_Notify") &&
				!FunctionName.contains("Received_NotifyBegin") &&
				!FunctionName.contains("AnimNotify_LeftFootStep") &&
				!FunctionName.contains("AnimNotify_RightFootStep") &&
				!FunctionName.contains("Completed_") &&
				!FunctionName.contains("InputActionHoldStopped") &&
				!FunctionName.contains("ServerCurrentMontageSetPlayRate") &&
				!FunctionName.contains("ServerSetReplicatedTargetData") &&
				!FunctionName.contains("Triggered_") &&
				!FunctionName.contains("ActorHasTag") &&
				!FunctionName.contains("RandomIntegerInRange") &&
				!FunctionName.contains("GetItemDefinitionBP") &&
				!FunctionName.contains("CreateTemporaryItemInstanceBP") &&
				!FunctionName.contains("SetOwningControllerForTemporaryItem") &&
				!FunctionName.contains("OnRep_PrimaryQuickBar") &&
				!FunctionName.contains("OnRep_SecondaryQuickBar") &&
				!FunctionName.contains("ServerSetupWeakSpotsOnBuildingActor") &&
				!FunctionName.contains("OnStartDirectionEffect") &&
				!FunctionName.contains("SetReplicates") &&
				!FunctionName.contains("ServerCurrentMontageSetNextSectionName") &&
				!FunctionName.contains("NetFadeOut") &&
				!FunctionName.contains("OnFadeOut") &&
				!FunctionName.contains("NetOnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("GameplayCue") &&
				!FunctionName.contains("ReceiveActorEndOverlap") &&
				!FunctionName.contains("PhysicsVolumeChanged") &&
				!FunctionName.contains("ServerAddItemInternal") &&
				!FunctionName.contains("FortClientPlaySound") &&
				!FunctionName.contains("OnCapsuleBeginOverlap") &&
				!FunctionName.contains("GetPlayerController") &&
				!FunctionName.contains("TossPickup") &&
				!FunctionName.contains("OnRep_PrimaryPickupItemEntry") &&
				!FunctionName.contains("ServerActivateSlotInternal") &&
				!FunctionName.contains("EquipWeaponDefinition") &&
				!FunctionName.contains("OnInitAlteration") &&
				!FunctionName.contains("OnInitCosmeticAlterations") &&
				!FunctionName.contains("K2_OnUnEquip") &&
				!FunctionName.contains("GetItemGuid") &&
				!FunctionName.contains("InternalServerSetTargeting") &&
				!FunctionName.contains("ServerReleaseInventoryItemKey") &&
				!FunctionName.contains("OnPawnMontageBlendingOut") &&
				!FunctionName.contains("OnSetTargeting") &&
				!FunctionName.contains("OnRep_DefaultMetadata") &&
				!FunctionName.contains("GetDataTableRowNames") &&
				!FunctionName.contains("GetMaxDurability") &&
				!FunctionName.contains("OnRep_PickupLocationData") &&
				!FunctionName.contains("GetControlRotation") &&
				!FunctionName.contains("OnVisibilitySetEvent") &&
				!FunctionName.contains("ShouldShowSoundIndicator") &&
				!FunctionName.contains("WaitForPawn") &&
				!FunctionName.contains("OnProjectileStopDelegate") &&
				!FunctionName.contains("Handle Parachute Audio State") &&
				!FunctionName.contains("GetDistanceTo") &&
				!FunctionName.contains("GetSpectatorPawn") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("OnHitCrack") &&
				!FunctionName.contains("EvaluateGraphExposedInputs_ExecuteUbergraph_Fortnite_M_Avg_Player_AnimBlueprint_AnimGraphNode_"))
			{
				FN_LOG(Logs, Log, L"FunctionName: [%s], Object: [%s]", Function->GetFullName().c_str(), Object->GetName().c_str());
			}
		}

		if (bCallOG)
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
				FN_LOG(LogHooks, Error, L"[AFortDecoTool::ServerSpawnDeco] Failed to get PlayerController!");
				return Result;
			}

			AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

			if (!PlayerState)
			{
				FN_LOG(LogHooks, Error, L"[AFortDecoTool::ServerSpawnDeco] Failed to get PlayerState!");
				return Result;
			}

			Result->bPlayerPlaced = true;
			Result->Team = PlayerState->TeamIndex;
		}

		return Result;
	}

	// 7FF66F481290
	UClass** sub_7FF66F481290Hook(__int64 a1, UClass** OutGameSessionClass)
	{
		//*OutGameSessionClass = AFortGameSessionDedicatedAthena::StaticClass();
		//*OutGameSessionClass = AFortGameSessionDedicated::StaticClass();
		*OutGameSessionClass = AFortGameSession::StaticClass();
		return OutGameSessionClass;
	}

	void InitalizePoiManager(AFortPoiManager* PoiManager)
	{
		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, L"Function [InitalizePoiManager] successfully hooked with Offset [0x%llx], IdaAddress [%p], GameMode: [%s]", (unsigned long long)Offset, IdaAddress, PoiManager->GetName().c_str());
	}

	// 7FF66F6694B0
	void (*Restart)(AFortGameSessionDedicated* GameSession);
	void RestartHook(AFortGameSessionDedicated* GameSession)
	{
		Restart(GameSession);
	}

	void CollectGarbageHook()
	{
		FN_LOG(LogMinHook, Log, L"CollectGarbageHook called!");
	}

#ifdef ANTICHEAT
	// 7FF66ECBAF00
	bool (*NetSerialize)(FGameplayAbilityTargetDataHandle* AbilityTargetDataHandle, __int64& a2, UPackageMap* Map, bool& bOutSuccess);
	bool NetSerializeHook(FGameplayAbilityTargetDataHandle* AbilityTargetDataHandle, __int64& a2, UPackageMap* Map, bool& bOutSuccess)
	{
		bool bResult = NetSerialize(AbilityTargetDataHandle, a2, Map, bOutSuccess);

		if (bResult)
		{
			UIpConnection* IpConnection = Cast<UIpConnection>(Map->Outer);

			if (!IpConnection)
				return bResult;

			UAntiCheatOdyssey* AntiCheatOdyssey = FindOrCreateAntiCheatOdyssey(IpConnection->PlayerController);

			if (AntiCheatOdyssey)
			{
				uint8 DataNum = 0;

				if (*(int32*)(__int64(AbilityTargetDataHandle) + 0x18) <= 255)
					DataNum = *(int32*)(__int64(AbilityTargetDataHandle) + 0x18);

				if (DataNum > AntiCheatOdyssey->GetMaxDataNum())
				{
					const FString& PlayerName = AntiCheatOdyssey->GetPlayerName();

					if (PlayerName.IsValid())
					{
						AC_LOG(ACWarning, "Player [%s] is trying to damage multiplier", AntiCheatOdyssey->GetPlayerName().ToString().c_str());
					}

					AntiCheatOdyssey->BanByAntiCheat(L"AC - You tried to damage multiplier!");
				}
			}
		}

		return bResult;
	}
#endif // ANTICHEAT

	void InitHook()
	{
		static auto FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();
		static auto FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		uintptr_t AddressLocalSpawnPlayActor = MinHook::FindPattern(Patterns::LocalSpawnPlayActor);
		uintptr_t AddressInternalGetNetMode = MinHook::FindPattern(Patterns::InternalGetNetMode);
		uintptr_t AddressActorInternalGetNetMode = MinHook::FindPattern(Patterns::ActorInternalGetNetMode);
		uintptr_t AddressChangingGameSessionId = MinHook::FindPattern(Patterns::ChangingGameSessionId);
		uintptr_t AddressKickPlayer = MinHook::FindPattern(Patterns::KickPlayer);
		uintptr_t AddressPickupCombine = MinHook::FindPattern(Patterns::PickupCombine);
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
		MH_CreateHook((LPVOID)(AddressDispatchRequest), DispatchRequestHook, (LPVOID*)(&DispatchRequest));
		MH_EnableHook((LPVOID)(AddressDispatchRequest));
		MH_CreateHook((LPVOID)(AddressGetPlayerViewPoint), GetPlayerViewPointHook, (LPVOID*)(&GetPlayerViewPoint));
		MH_EnableHook((LPVOID)(AddressGetPlayerViewPoint));
		MH_CreateHook((LPVOID)(AddressServerSpawnDeco), ServerSpawnDecoHook, (LPVOID*)(&ServerSpawnDeco));
		MH_EnableHook((LPVOID)(AddressServerSpawnDeco));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xE31290), sub_7FF66F481290Hook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xE31290));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8E80), CollectGarbageHook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8E80));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xC56D70), InitalizePoiManager, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xC56D70));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10194B0), RestartHook, (LPVOID*)(&Restart));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10194B0));

#ifdef ANTICHEAT
		/*MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x66AF00), NetSerializeHook, (LPVOID*)(&NetSerialize));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x66AF00));*/
#endif // ANTICHEAT

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEventHook, (LPVOID*)(&ProcessEvent));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		FN_LOG(LogInit, Log, L"InitHook Success!");
	}
}