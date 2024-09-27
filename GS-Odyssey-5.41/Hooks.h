#pragma once

#undef min

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

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
		{
			ProcessEvent(Object, Function, Parms);
			return;
		}

		bool bCallOG = true;

		GameMode::ProcessEventHook(Object, Function, Parms);
		PlayerController::ProcessEventHook(Object, Function, Parms);
		Pawn::ProcessEventHook(Object, Function, Parms);
		FortKismetLibrary::ProcessEventHook(Object, Function, Parms, &bCallOG);
		Cheats::ProcessEventHook(Object, Function, Parms);
		FortAthenaSupplyDrop::ProcessEventHook(Object, Function, Parms, &bCallOG);
		BuildingActor::ProcessEventHook(Object, Function, Parms);

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
				TArray<AActor*> OutActors;
				UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), ACUBE_C::StaticClass(), &OutActors);

				for (int32 i = 0; i < OutActors.Num(); i++)
				{
					ACUBE_C* CUBE = (ACUBE_C*)OutActors[i];
					if (!CUBE) continue;

					CUBE->Next(CubeIndex);

					CubeIndex++;

					FN_LOG(LogHooks, Log, "CubeIndex: %i", CubeIndex);
				}

				// 7FF66F6694B0
				/*char (*Restart)(AFortGameSessionDedicated* GameSession) = decltype(Restart)(0x10194B0 + uintptr_t(GetModuleHandle(0)));

				char Result = Restart((AFortGameSessionDedicated*)Globals::GetGameMode()->FortGameSession);

				GameMode::bPreReadyToStartMatch = false;
				GameMode::bWorldReady = false;

				FN_LOG(LogHooks, Log, "Restart called, Result: %i", Result);*/

			}

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				FName LootTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaTreasure"); // Activity_Crafting_Ore_High_MediumMats

				TArray<FFortItemEntry> LootToDrops;
				bool bSuccess = UFortKismetLibrary::PickLootDrops(Globals::GetWorld(), &LootToDrops, LootTierGroup, -1, -1);

				for (auto& LootToDrop : LootToDrops)
				{
					if (!LootToDrop.ItemDefinition)
						continue;

					FN_LOG(LogBuildingActor, Log, "ItemDefinition: %s, Count: %i, Level: %i, Durability: %.2f", LootToDrop.ItemDefinition->GetName().c_str(), LootToDrop.Count, LootToDrop.Level, LootToDrop.Durability);
				}

				FN_LOG(LogBuildingActor, Log, "PickLootDrops - bSuccess: %i, LootToDrops: %i", bSuccess, LootToDrops.Num());

				/*FFortLootTierDataCheck LootTierDataCheck;
				LootTierDataCheck.TierGroup = LootTierGroup;
				LootTierDataCheck.LootTier = -1;
				LootTierDataCheck.QuotaLevel = ELootQuotaLevel::Unlimited;
				LootTierDataCheck.GameplayTags = FGameplayTagContainer();
				LootTierDataCheck.WorldLevel = -1;

				float TotalWeight = 0.0f;

				std::map<FName, FFortLootTierData*> LootTierDatas;

				UFortGameData* GameData = Globals::GetGameData();
				Loots::ChooseLootTierDatas(GameData, &LootTierDatas, &TotalWeight, LootTierDataCheck);

				for (auto& [LootTierKey, LootTierData] : LootTierDatas)
				{
					FN_LOG(LogBuildingActor, Log, "LootTierKey: %s, TierGroup: %s, LootPackage: %s", LootTierKey.ToString().c_str(), LootTierData->TierGroup.ToString().c_str(), LootTierData->LootPackage.ToString().c_str());
				}

				FN_LOG(LogBuildingActor, Log, "ChooseLootTierDatas - TotalWeight: %.2f", TotalWeight);*/

				// 1:1 mieux que Nathael OG God GS
				/*bool bSuccess2 = Loots::PickLootDrops(&LootToDrops, -1, LootTierKey, 0, 0, FGameplayTagContainer(), false, false);

				for (auto& LootToDrop : LootToDrops)
				{
					if (!LootToDrop.ItemDefinition)
						continue;

					FN_LOG(LogBuildingActor, Log, "ItemDefinition: %s, Count: %i, Level: %i, Durability: %.2f", LootToDrop.ItemDefinition->GetName().c_str(), LootToDrop.Count, LootToDrop.Level, LootToDrop.Durability);
				}

				FN_LOG(LogBuildingActor, Log, "PickLootDrops - bSuccess: %i, LootToDrops: %i", bSuccess2, LootToDrops.Num());*/
				return;

				AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);
				UFortPlaylistAthena* Playlist = Globals::GetPlaylist();

				if (!PlayerController || !Playlist)
					return;

				UFortRegisteredPlayerInfo* RegisteredPlayerInfo = UFortKismetLibrary::GetPlayerInfoFromUniqueID(PlayerController, PlayerController->GetGameAccountId());

				if (!RegisteredPlayerInfo)
					return;

				UFortMcpProfileAthena* AthenaProfile = RegisteredPlayerInfo->AthenaProfile;

				if (!AthenaProfile)
					return;

				AthenaProfile->EndBattleRoyaleGame({}, UKismetStringLibrary::Conv_IntToString(Playlist->PlaylistId), FAthenaMatchStats(), 0, 0, 0.f, true, true, {}, nullptr);

				UFortKismetLibrary::FortShippingLog(PlayerController, L"erergergergergerg", true);

				FN_LOG(LogHooks, Log, "PlayerController: %s, RegisteredPlayerInfo: %s, AthenaProfile: %s", PlayerController->GetName().c_str(), RegisteredPlayerInfo->GetName().c_str(), AthenaProfile->GetName().c_str());

				UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(PlayerController);
				AGameModeBase* GameMode = UGameplayStatics::GetGameMode(PlayerController);
				AGameStateBase* GameState = UGameplayStatics::GetGameState(PlayerController);

				FN_LOG(LogHooks, Log, "GameInstance: %s, GameMode: %s, GameState: %s", GameInstance->GetName().c_str(), GameMode->GetName().c_str(), GameState->GetName().c_str());

				TArray<UAthenaCosmeticItemDefinition*> AthenaCosmetics = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaCharacter);

				FN_LOG(LogHooks, Log, "AthenaCosmetics: %i", AthenaCosmetics.Num());

				for (int32 i = 0; i < AthenaCosmetics.Num(); i++)
				{
					UAthenaCosmeticItemDefinition* AthenaCosmetic = AthenaCosmetics[i];
					if (!AthenaCosmetic) continue;

					FN_LOG(LogHooks, Log, "[%i] - AthenaCosmetics - CosmeticItemDefinition: %s", i, AthenaCosmetic->GetName().c_str());
				}

				//UKismetGuidLibrary::NewGuid();

				//UKismetMathLibrary::Abs(10.f);

				/*UAthenaSeasonItemDefinition* Season5 = StaticLoadObject<UAthenaSeasonItemDefinition>(L"/Game/Athena/Items/Seasons/AthenaSeason5.AthenaSeason5");

				if (Season5)
				{
					FN_LOG(LogHooks, Log, "SeasonNumber: %i", Season5->SeasonNumber);
					FN_LOG(LogHooks, Log, "NumSeasonLevels: %i", Season5->NumSeasonLevels);
					FN_LOG(LogHooks, Log, "NumBookLevels: %i", Season5->NumBookLevels);
					FN_LOG(LogHooks, Log, "SeasonStorefront: %s", Season5->SeasonStorefront.ToString().c_str());
					FN_LOG(LogHooks, Log, "FreeLevelsThatNavigateToBattlePass: %i", Season5->FreeLevelsThatNavigateToBattlePass.Num());
					FN_LOG(LogHooks, Log, "FreeLevelsThatAutoOpenTheAboutScreen: %i", Season5->FreeLevelsThatAutoOpenTheAboutScreen.Num());

					TArray<FAthenaRewardScheduleLevel> BookXpScheduleFrees = Season5->BookXpScheduleFree.Levels;

					for (int32 i = 0; i < BookXpScheduleFrees.Num(); i++)
					{
						FAthenaRewardScheduleLevel BookXpScheduleFree = BookXpScheduleFrees[i];

						for (int32 j = 0; j < BookXpScheduleFree.Rewards.Num(); j++)
						{
							FAthenaRewardItemReference Reward = BookXpScheduleFree.Rewards[j];

							if (!Reward.ItemDefinition.Get())
								continue;

							FN_LOG(LogHooks, Log, "[%i] - BookXpScheduleFrees - ItemDefinition: %s, Quantity: %i", i, Reward.ItemDefinition.Get()->GetName().c_str(), Reward.Quantity);
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

							FN_LOG(LogHooks, Log, "[%i] - BookXpSchedulePaids - ItemDefinition: %s, Quantity: %i", i, Reward.ItemDefinition.Get()->GetName().c_str(), Reward.Quantity);
						}
					}

					TArray<FAthenaRewardItemReference> SeasonGrantsToEveryones = Season5->SeasonGrantsToEveryone.Rewards;

					for (int32 i = 0; i < SeasonGrantsToEveryones.Num(); i++)
					{
						FAthenaRewardItemReference SeasonGrantsToEveryone = SeasonGrantsToEveryones[i];

						if (!SeasonGrantsToEveryone.ItemDefinition.Get())
							continue;

						FN_LOG(LogHooks, Log, "[%i] - BookXpSchedulePaids - ItemDefinition: %s, Quantity: %i, i", i, SeasonGrantsToEveryone.ItemDefinition.Get()->GetName().c_str(), SeasonGrantsToEveryone.Quantity);
					}
				}*/
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

				if (!Pawn)
					return;

				auto Tiered_Chest_6_ParentClass = FindObjectFast<UBlueprintGeneratedClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Chest_6_Parent.Tiered_Chest_6_Parent_C");
				auto WID_Shotgun_Standard_Athena_UC_Ore_T03 = FindObjectFast<UFortWeaponRangedItemDefinition>("/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_UC_Ore_T03.WID_Shotgun_Standard_Athena_UC_Ore_T03");

				FVector SpawnLocation = Pawn->K2_GetActorLocation();
				SpawnLocation.X += 50;

				ABuildingContainer* BuildingContainer = Util::SpawnActor<ABuildingContainer>(Tiered_Chest_6_ParentClass, SpawnLocation);

				BuildingContainer->LootTestingData = WID_Shotgun_Standard_Athena_UC_Ore_T03;

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
					OdysseyLog: LogHook: Debug: Index not found: 0x11, Offset: 0x11a9910, IdaAddress [00007FF66F7F9910] - UFortItem* FindExistingItemForDefinition(void* idk, const UFortItemDefinition* ItemDefinition, bool bInStorageVault)
					OdysseyLog: LogHook: Debug: Index not found: 0x12, Offset: 0x11a9c40, IdaAddress [00007FF66F7F9C40] - bool (*FindItemInstancesFromDefinition)(void* idk, UFortItemDefinition* ItemDefinition, TArray<UFortItem*>& ItemArray)
					OdysseyLog: LogHook: Debug: Index not found: 0x13, Offset: 0x11ae410, IdaAddress [00007FF66F7FE410] - UFortItem* GetInventoryItemWithGuid(void* idk, const FGuid& ItemGuid)
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

				//MinHook::FindIndexVTable((UObject*)IdkDefault, 0x0, 0x21);
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				TArray<AFortPlayerController*> PlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(Globals::GetWorld(), true, true);
				AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(Globals::GetGameMode());

				for (int32 i = 0; i < PlayerControllers.Num(); i++)
				{
					AFortPlayerControllerAthena* PlayerController = Cast<AFortPlayerControllerAthena>(PlayerControllers[i]);
					if (!PlayerController) continue;

					AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(PlayerController->PlayerState);

					if (!PlayerController->Pawn && PlayerState)
					{
						GameMode->RestartPlayer(PlayerController);

						GameMode->ShouldReset(PlayerState);

						FTransform Transform;
						Transform.Rotation = FQuat({1, 1, 1, 1});
						Transform.Translation = FVector({0, 0, 3000});
						Transform.Scale3D = FVector({1, 1, 1});

						GameMode->RestartPlayerAtTransform(PlayerController, Transform);

						AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerController, FVector({ 0, 0, 3000 }), FRotator(), false);

						//UFortKismetLibrary::ApplyGlobalEnvironmentGameplayEffectToActor(PlayerPawn, UGE_Generic_Revive_C::StaticClass(), 0, FGameplayTagContainer());

						PlayerState->AbilitySystemComponent->BP_ApplyGameplayEffectToSelf(UGE_Generic_Revive_C::StaticClass(), 0.0f, FGameplayEffectContextHandle());

						PlayerController->OnPlayerStartedRespawn__DelegateSignature();

						PlayerController->ServerReadyToStartMatch();

						PlayerController->ServerRestartPlayer();
						PlayerController->ClientOnPawnRevived(PlayerController);

						PlayerController->bEnterCameraModeOnDeath = false;
						PlayerController->RespawnPlayerAfterDeath();

						PlayerPawn->SetMaxHealth(100);
						PlayerPawn->SetHealth(100);
						PlayerPawn->SetMaxShield(100);

						// 7FF66F7BC760 (Je suis sévèrement autiste)
						void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
						SetShield(PlayerPawn, 0);

						PlayerController->ClientReset();
						PlayerController->ClientRestart(PlayerPawn);
						PlayerController->ClientRetryClientRestart(PlayerPawn);	

						GameMode::AddFromAlivePlayers(GameMode, PlayerController);

						FN_LOG(LogHooks, Log, "IsDead [%i]", PlayerPawn->IsDead());
						FN_LOG(LogHooks, Log, "IsDBNO [%i]", PlayerPawn->IsDBNO());
					}
				}
			}

			if (GetAsyncKeyState(VK_F7) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"SPAWNLLAMA", PlayerController);

				return;

				TArray<AFortPlayerController*> PlayerControllers = UFortKismetLibrary::GetAllFortPlayerControllers(Globals::GetWorld(), true, true);

				for (int32 i = 0; i < PlayerControllers.Num(); i++)
				{
					AFortPlayerController* PlayerController = PlayerControllers[i];
					if (!PlayerController) continue;

					AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerController->PlayerState);

					if (PlayerState)
					{
						// 7FF66EC68170
						void (*ClearAllAbilities)(UAbilitySystemComponent* AbilitySystemComponent) = decltype(ClearAllAbilities)(0x618170 + uintptr_t(GetModuleHandle(0)));
						ClearAllAbilities(PlayerState->AbilitySystemComponent);
					}
				}

				/*AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"SPAWNLLAMA", PlayerController);*/
			}

			if (GetAsyncKeyState(VK_F9) & 0x1)
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)UGameplayStatics::GetPlayerController(Globals::GetWorld(), 0);

				if (!PlayerController)
					return;

				if (!PlayerController->CheatManager)
					PlayerController->CheatManager = (UCheatManager*)UGameplayStatics::SpawnObject(UCheatManager::StaticClass(), PlayerController);

				UKismetSystemLibrary::ExecuteConsoleCommand(PlayerController, L"toggledebugcamera", PlayerController);
			}

			if (GetAsyncKeyState(VK_F10) & 0x1)
			{
				// 7FF66F23FBE0
				void (*HandleMatchHasStarted)(AFortGameModeAthena* GameMode) = decltype(HandleMatchHasStarted)(0xBEFBE0 + uintptr_t(GetModuleHandle(0)));
				HandleMatchHasStarted(Cast<AFortGameModeAthena>(Globals::GetGameMode()));
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
				AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());
				AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(Globals::GetGameMode());

				int32 PlaylistId = 2; // Solo
				//int32 PlaylistId = 10; // Duo
				// int32 PlaylistId = 9; // Squad
				//int32 PlaylistId = 35; // Playground
				// int32 PlaylistId = 50; // 50VS50

				// int32 PlaylistId = 140; // Bling (Solo)

				// 7FF66F2504C0
				void (*SetCurrentPlaylistId)(AFortGameModeAthena* GameMode, int32 NewPlaylistId) = decltype(SetCurrentPlaylistId)(0xC004C0 + uintptr_t(GetModuleHandle(0)));

				SetCurrentPlaylistId(GameMode, PlaylistId);

				// 7FF66F52DEC0
				UFortPlaylistAthena* (*GetPlaylistByPlaylistId)(UFortPlaylistManager* PlaylistManager, int32 PlaylistId) = decltype(GetPlaylistByPlaylistId)(0xEDDEC0 + uintptr_t(GetModuleHandle(0)));

				UFortPlaylistAthena* Playlist = GetPlaylistByPlaylistId(GameMode->PlaylistManager, PlaylistId);

				if (GameState && Playlist)
				{
					GameState->CurrentPlaylistData = Playlist;
					GameState->OnRep_CurrentPlaylistData();

					FN_LOG(LogHooks, Log, "AdditionalLevels.Num() [%i]", Playlist->AdditionalLevels.Num());

					for (int32 i = 0; i < Playlist->AdditionalLevels.Num(); i++)
					{
						TSoftObjectPtr<UWorld> AdditionalLevel = Playlist->AdditionalLevels[i];

						if (!AdditionalLevel.Get())
							continue;

						FN_LOG(LogHooks, Log, "AdditionalLevel [%i]: %s", i, AdditionalLevel.Get()->GetFullName().c_str());
					}

					// GameState->OnRep_AdditionalPlaylistLevelsStreamed();

					GameState->AirCraftBehavior = Playlist->AirCraftBehavior;

					AFortGameSessionDedicated* GameSession = Cast<AFortGameSessionDedicated>(GameMode->GameSession);

					GameSession->MaxPlayers = Playlist->MaxPlayers;
					GameSession->MaxPartySize = Playlist->MaxSocialPartySize;

					GameMode->PlaylistManager;
					GameMode->CurrentZoneInstanceId;
				}

				GameMode->DefaultPawnClass = APlayerPawn_Athena_C::StaticClass();

				FN_LOG(LogHooks, Log, "OnWorldReady called!");

				GameMode::bWorldReady = true;
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

	// 00007FF66F5F11C0
	bool (*PickupAddInventoryOwnerInterface)(AFortPickup* Pickup, void* InterfaceAddress);
	bool PickupAddInventoryOwnerInterfaceHook(AFortPickup* Pickup, void* InterfaceAddress)
	{
		if (!Pickup)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupAddInventoryOwnerInterface] Failed to get Pickup.");
			return PickupAddInventoryOwnerInterface(Pickup, InterfaceAddress);
		}

		FFortPickupLocationData* PickupLocationData = &Pickup->PickupLocationData;
		FFortItemEntry* ItemEntry = &Pickup->PrimaryPickupItemEntry;

		if (!PickupLocationData || !ItemEntry)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupAddInventoryOwnerInterface] Failed to get PickupLocationData/ItemEntry!");
			return PickupAddInventoryOwnerInterface(Pickup, InterfaceAddress);
		}

		UObject* (*GetObjectByAddress)(void* InterfaceAddress) = decltype(GetObjectByAddress)(((UObject*)InterfaceAddress)->VTable[0x1]);
		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(GetObjectByAddress(InterfaceAddress));

		if (!PlayerController)
		{
			FN_LOG(LogHooks, Error, "[AFortPickup::PickupAddInventoryOwnerInterface] Failed to get PlayerController!");
			return PickupAddInventoryOwnerInterface(Pickup, InterfaceAddress);
		}

		Inventory::AddInventoryItem(PlayerController, *ItemEntry, PickupLocationData->PickupGuid);

		return PickupAddInventoryOwnerInterface(Pickup, InterfaceAddress);
	}

	// 7FF66F481290
	UClass** sub_7FF66F481290Hook(__int64 a1, UClass** OutGameSessionClass)
	{
		//*OutGameSessionClass = AFortGameSessionDedicatedAthena::StaticClass();
		*OutGameSessionClass = AFortGameSessionDedicated::StaticClass();
		return OutGameSessionClass;
	}

	AActor* (*SpawnActor)(UWorld* World, UClass* Class, FVector const* Location, FRotator const* Rotation, const FActorSpawnParameters& SpawnParameters);
	AActor* SpawnActorHook(UWorld* World, UClass* Class, FVector const* Location, FRotator const* Rotation, const FActorSpawnParameters& SpawnParameters)
	{
		if (Class && Class->IsA(AFortAthenaAircraft::StaticClass()))
		{
			
		}

		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "Function [SpawnActorHook] successfully hooked with Offset [0x%llx], IdaAddress [%p], Class: [%s]", (unsigned long long)Offset, IdaAddress, Class->GetName().c_str());

		return SpawnActor(World, Class, Location, Rotation, SpawnParameters);
	}

	AActor* (*RealSpawnActor)(UWorld* World, UClass* Class, __m128* a3, const FActorSpawnParameters& SpawnParameters);
	AActor* RealSpawnActorHook(UWorld* World, UClass* Class, __m128* a3, const FActorSpawnParameters& SpawnParameters)
	{
		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "Function [SpawnActorHook] successfully hooked with Offset [0x%llx], IdaAddress [%p], Class: [%s]", (unsigned long long)Offset, IdaAddress, Class->GetName().c_str());

		return RealSpawnActor(World, Class, a3, SpawnParameters);
	}

	void InitalizePoiManager(AFortPoiManager* PoiManager)
	{
		uintptr_t Offset = uintptr_t(_ReturnAddress()) - InSDKUtils::GetImageBase();
		uintptr_t IdaAddress = Offset + 0x7FF66E650000ULL;

		FN_LOG(LogMinHook, Log, "Function [InitalizePoiManager] successfully hooked with Offset [0x%llx], IdaAddress [%p], GameMode: [%s]", (unsigned long long)Offset, IdaAddress, PoiManager->GetName().c_str());
	}

	// 7FF66F6694B0
	void (*Restart)(AFortGameSessionDedicated* GameSession);
	void RestartHook(AFortGameSessionDedicated* GameSession)
	{
		GameMode::bPreReadyToStartMatch = false;
		GameMode::bWorldReady = false;

		Restart(GameSession);
	}

	char (*execPickLootDrops)(UFortKismetLibrary* a1, __int64* a2, __int64* a3);
	char execPickLootDropsHook(UFortKismetLibrary* a1, __int64* a2, __int64* a3)
	{
		FN_LOG(LogMinHook, Log, "execPickLootDropsHook called!");
		return execPickLootDrops(a1, a2, a3);
	}

	void test()
	{

	}

	void InitHook()
	{
		static auto FortPickupAthenaDefault = AFortPickupAthena::GetDefaultObj();
		static auto FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		MinHook::HookVTable(FortPickupAthenaDefault, 0xBF, PickupAddInventoryOwnerInterfaceHook, (LPVOID*)(&PickupAddInventoryOwnerInterface), "PickupAddInventoryOwnerInterface");

		MinHook::HookVTable(AFortPlayerPawnAthena::GetDefaultObj(), 0x196, test, nullptr, "AFortPlayerPawn::ServerReviveFromDBNO");
		MinHook::HookVTable(AFortPlayerControllerAthena::GetDefaultObj(), 0x396, test, nullptr, "AFortPlayerControllerZone::ClientOnPawnRevived");

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
		/*MH_CreateHook((LPVOID)(AddressPickupCombine), PickupCombineHook, (LPVOID*)(&PickupCombine));
		MH_EnableHook((LPVOID)(AddressPickupCombine));*/
		MH_CreateHook((LPVOID)(AddressDispatchRequest), DispatchRequestHook, (LPVOID*)(&DispatchRequest));
		MH_EnableHook((LPVOID)(AddressDispatchRequest));
		MH_CreateHook((LPVOID)(AddressGetPlayerViewPoint), GetPlayerViewPointHook, (LPVOID*)(&GetPlayerViewPoint));
		MH_EnableHook((LPVOID)(AddressGetPlayerViewPoint));
		MH_CreateHook((LPVOID)(AddressServerSpawnDeco), ServerSpawnDecoHook, (LPVOID*)(&ServerSpawnDeco));
		MH_EnableHook((LPVOID)(AddressServerSpawnDeco));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960), CollectGarbageInternalHook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x17C8960));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xE31290), sub_7FF66F481290Hook, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xE31290));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0xC56D70), InitalizePoiManager, nullptr);
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0xC56D70));
		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10194B0), RestartHook, (LPVOID*)(&Restart));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x10194B0));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + 0x145E6C0), execPickLootDropsHook, (LPVOID*)(&execPickLootDrops));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + 0x145E6C0));

		MH_CreateHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent), ProcessEventHook, (LPVOID*)(&ProcessEvent));
		MH_EnableHook((LPVOID)(InSDKUtils::GetImageBase() + Offsets::ProcessEvent));

		FN_LOG(LogInit, Log, "InitHook Success!");
	}
}