#pragma once

namespace GameMode
{
	void (*RemoveFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController, AFortPlayerStateAthena* PlayerState, AFortPlayerPawnAthena* PlayerPawn, UFortWeaponItemDefinition* WeaponItemDefinition, EDeathCause DeathCause, char a7);
	void (*AddFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController);
	void (*ApplyCustomizationToCharacter)(AFortPlayerState* PlayerState, AFortPlayerController* PlayerController, AFortPlayerPawn* PlayerPawn);
	void (*HandleMatchHasStarted)(AFortGameModeAthena* GameMode);

	bool bWorldIsReady = false;

	AFortPlayerPawn* SpawnDefaultPawnForHook(AFortGameMode* GameModeBase, AController* NewPlayer, AActor* StartSpot)
	{
		AFortPlayerController* PlayerController = Cast<AFortPlayerController>(NewPlayer);
		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(NewPlayer->PlayerState);

		if (!PlayerController || !PlayerState)
		{
			FN_LOG(LogGameMode, Error, "[AGameModeBase::SpawnDefaultPawnFor] failed to get PlayerController/PlayerState!");
			return nullptr;
		}

		// 7FF66F49A3C0
		AFortPlayerPawn* (*SpawnDefaultPawnFor)(AFortGameMode* GameMode, AFortPlayerController* PlayerController, AActor* StartSpot) = decltype(SpawnDefaultPawnFor)(0xE4A3C0 + uintptr_t(GetModuleHandle(0)));
		AFortPlayerPawn* PlayerPawn =  SpawnDefaultPawnFor(GameModeBase, PlayerController, StartSpot);

		if (!PlayerPawn)
		{
			FN_LOG(LogGameMode, Error, "[AGameModeBase::SpawnDefaultPawnFor] failed to spawn PlayerPawn!");
			return nullptr;
		}

		PlayerPawn->Owner = PlayerController;
		PlayerPawn->OnRep_Owner();

		PlayerController->Pawn = PlayerPawn;
		PlayerController->OnRep_Pawn();
		PlayerController->Possess(PlayerPawn);

		PlayerPawn->SetMaxHealth(100);
		PlayerPawn->SetHealth(100);
		PlayerPawn->SetMaxShield(100);

#ifdef LATEGAME
		void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
		SetShield(PlayerPawn, 100);
#else
		void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
		SetShield(PlayerPawn, 0);
#endif // LATEGAME

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->ClearAllAbilities();

			UFortAbilitySet* DefaultAbilities = Globals::GetGameData()->GenericPlayerAbilitySet.Get();

			Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);

#ifdef LATEGAME
			UFortGameplayModifierItemDefinition* GameplayModifierItemDefinition = FindObjectFast<UFortGameplayModifierItemDefinition>("/Game/Athena/Playlists/Velocity/RedeployGlider_Modifier.RedeployGlider_Modifier");
			
			if (!GameplayModifierItemDefinition)
				GameplayModifierItemDefinition = StaticLoadObject<UFortGameplayModifierItemDefinition>(L"/Game/Athena/Playlists/Velocity/RedeployGlider_Modifier.RedeployGlider_Modifier");

			if (GameplayModifierItemDefinition)
				Abilities::GrantModifierAbility(GameplayModifierItemDefinition, PlayerPawn);
#endif // LATEGAME
		}

		ApplyCustomizationToCharacter(PlayerState, PlayerController, PlayerPawn);

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);
		UFortWeaponMeleeItemDefinition* WeaponMeleeItemDefinition = nullptr;

		if (PlayerControllerAthena)
		{
			UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = PlayerControllerAthena->CustomizationLoadout.Pickaxe;

			if (AthenaPickaxeItemDefinition)
				WeaponMeleeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

			if (!WeaponMeleeItemDefinition)
			{
				UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = Globals::GetGameData()->DefaultPickaxeSkin;

				if (DefaultPickaxeSkin)
					WeaponMeleeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
			}

			PlayerControllerAthena->ClientOnPawnSpawned();
		}

		Inventory::SetupInventory(PlayerController, WeaponMeleeItemDefinition);    

#ifdef LATEGAME
		Functions::GiveLateGameInventory(PlayerController);
#endif // LATEGAME

		FN_LOG(LogHooks, Log, "AGameModeBase::SpawnDefaultPawnFor - called!");

		return PlayerPawn;
	}

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms, bool* bCallOG)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ReadyToStartMatch"))
		{
			AGameMode* GameMode = Cast<AGameMode>(Object);
			auto Params = (Params::GameMode_ReadyToStartMatch*)Parms;

			if (!GameMode)
				return;

			AFortGameMode* FortGameMode = Cast<AFortGameMode>(GameMode);

			if (!FortGameMode)
				return;

			AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(FortGameMode);
			AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(FortGameMode->GameState);

			if (GameModeAthena && GameStateAthena && !GameStateAthena->CurrentPlaylistData)
			{
#ifdef BOTS
				if (!GameModeAthena->AIDirector)
					GameModeAthena->AIDirector = Util::SpawnActor<AAthenaAIDirector>(AAthenaAIDirector::StaticClass());

				if (!GameModeAthena->AIGoalManager)
					GameModeAthena->AIGoalManager = Util::SpawnActor<AFortAIGoalManager>(AFortAIGoalManager::StaticClass());

				if (GameModeAthena->AIDirector)
				{
					GameModeAthena->AIDirector->Activate();
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] AIDirector spawned correctly");
				}

				if (GameModeAthena->AIGoalManager)
				{
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] AIGoalManager spawned correctly");
				}
#endif // BOTS
				FURL URL;
				URL.Port = 7777;
				Beacon::ListenServer(Globals::GetWorld(), URL);

				int32 PlaylistId = 2; // Solo - Marche
				// int32 PlaylistId = 10; // Duo
				// int32 PlaylistId = 9; // Squad
				// int32 PlaylistId = 35; // Playground 
				// int32 PlaylistId = 50; // 50VS50 - Marche
				// int32 PlaylistId = 140; // Bling Solo 
				// int32 PlaylistId = 44; // Close Solo
				// int32 PlaylistId = 185; // Soaring Solo

				// 7FF66F52DEC0
				UFortPlaylistAthena* (*GetPlaylistByPlaylistId)(UFortPlaylistManager* PlaylistManager, int32 PlaylistId) = decltype(GetPlaylistByPlaylistId)(0xEDDEC0 + uintptr_t(GetModuleHandle(0)));
				UFortPlaylistAthena* PlaylistAthena = GetPlaylistByPlaylistId(GameModeAthena->PlaylistManager, PlaylistId);

				if (PlaylistAthena)
				{
					Functions::SetPlaylistData(GameModeAthena, PlaylistAthena);

					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] AISettings: %s", GameModeAthena->AISettings->GetName().c_str());
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] AIDirector: %s", GameModeAthena->AIDirector->GetName().c_str());
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] AIGoalManager: %s", GameModeAthena->AIGoalManager->GetName().c_str());
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] PlaylistAthena: %s", PlaylistAthena->GetName().c_str());
					FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] Choose Playlist Finish!");
				}
			}

			if (FortGameMode->bWorldIsReady)
			{
				const FName& MatchState = GameMode->MatchState;

				if (GameMode->NumPlayers + GameMode->NumBots > 0 &&
					MatchState.ToString() == "WaitingToStart")
				{
					const FName& InProgress = UKismetStringLibrary::Conv_StringToName(L"InProgress");

					GameMode->MatchState = InProgress;
					GameMode->K2_OnSetMatchState(InProgress);

					AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(FortGameMode);

					if (GameModeAthena)
					{
						Functions::InitializeTreasureChests();
						Functions::InitializeAmmoBoxs();
						Functions::InitializeLlamas();

						Functions::FillVendingMachines();

#ifdef DEBUGS
						Functions::StartSafeZone(GameModeAthena);
#else
						HandleMatchHasStarted(GameModeAthena);
#endif // DEBUGS

						FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] GameSession: %s", GameModeAthena->GameSession->GetName().c_str());
						FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] GameMode: %s", GameModeAthena->GetName().c_str());
						FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] GameState: %s", GameModeAthena->GameState->GetName().c_str());
						FN_LOG(LogGameMode, Log, "[AGameMode::ReadyToStartMatch] ReadyToStartMatch Finish!");
					}
				}
			}
		}
		else if (FunctionName.contains("HandleStartingNewPlayer"))
		{
			AGameModeBase* GameModeBase = Cast<AGameModeBase>(Object);
			auto Params = (Params::GameModeBase_HandleStartingNewPlayer*)Parms;

			if (!GameModeBase || !Params->NewPlayer)
			{
				FN_LOG(LogGameMode, Error, "[AGameModeBase::HandleStartingNewPlayer] Failed to get GameModeBase/NewPlayer");
				return;
			}

			AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Params->NewPlayer);
			AFortGameMode* FortGameMode = Cast<AFortGameMode>(GameModeBase);

			if (!PlayerController || !FortGameMode)
				return;

			if (FortGameMode->bWorldIsReady)
			{
#ifdef DEBUGS
				AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerController, FVector({ 0, 0, 30000 }), FRotator(), true);

				if (PlayerPawn)
				{
					PlayerPawn->bIsSkydiving = true;
					PlayerPawn->OnRep_IsSkydiving(false);
					PlayerPawn->bCanBeDamaged = true;
				}
#else
				AActor* PlayerStart = GameModeBase->ChoosePlayerStart(Params->NewPlayer);

				if (PlayerStart)
				{
					const FVector& PlayerStartLocation = PlayerStart->K2_GetActorLocation();
					const FRotator& PlayerStartRotation = PlayerStart->K2_GetActorRotation();

					Util::SpawnPlayer(PlayerController, PlayerStartLocation, PlayerStartRotation, true);
				}
#endif // DEBUGS
			}
		}
	}

	void (*HandlePostSafeZonePhaseChanged)(AFortGameModeAthena* GameModeAthena);
	void HandlePostSafeZonePhaseChangedHook(AFortGameModeAthena* GameModeAthena)
	{
		if (!GameModeAthena)
			return;

		HandlePostSafeZonePhaseChanged(GameModeAthena);

		AFortSafeZoneIndicator* SafeZoneIndicator = GameModeAthena->SafeZoneIndicator;

		if (SafeZoneIndicator)
		{
			TArray<FVector> SafeZoneLocations = GameModeAthena->SafeZoneLocations;
			int32 SafeZonePhase = GameModeAthena->SafeZonePhase;

			const FVector NewSafeZoneLocation = SafeZoneLocations[SafeZonePhase];

			if (NewSafeZoneLocation.IsZero())
				return;

			FN_LOG(LogGameMode, Log, "[AFortGameModeAthena::HandlePostSafeZonePhaseChanged] - New SafeZoneLocation: (X: %.2f, Y: %.2f, Z: %.2f), SafeZonePhase: %i",
				NewSafeZoneLocation.X, NewSafeZoneLocation.Y, NewSafeZoneLocation.Z, SafeZonePhase);

#ifdef LATEGAME
			if (SafeZonePhase >= 1 && SafeZonePhase < 4)
			{
				UKismetSystemLibrary::ExecuteConsoleCommand(GameModeAthena, L"skipshrinksafezone", nullptr);
			}
#endif // LATEGAME
			
#ifdef SIPHON
			if (SafeZonePhase > 4)
			{
				TArray<AFortPlayerController*> AllFortPlayerController = UFortKismetLibrary::GetAllFortPlayerControllers(GameModeAthena, true, true);

				for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
				{
					AFortPlayerController* PlayerControllerAthena = Cast<AFortPlayerController>(AllFortPlayerController[i]);
					if (!PlayerControllerAthena) continue;

					AFortPlayerPawn* MyFortPawn = PlayerControllerAthena->MyFortPawn;
					if (!MyFortPawn) continue;

					Functions::GiveSiphonBonus(PlayerControllerAthena, MyFortPawn, true, false);
				}
			}
#endif // SIPHON
		}
	}

	// 7FF66F252D70
	bool (*StartAircraftPhase)(AFortGameModeAthena* GameModeAthena);
	bool StartAircraftPhaseHook(AFortGameModeAthena* GameModeAthena)
	{
		FN_LOG(LogGameMode, Log, "AFortGameModeAthena::StartAircraftPhase - GameModeAthena: %s", GameModeAthena->GetName().c_str());

#ifdef LATEGAME
		if (!GameModeAthena)
			return false;

		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameModeAthena && GameStateAthena)
		{
			FVector CenterPositionToSpawn = GameModeAthena->SafeZoneLocations[3];
			CenterPositionToSpawn.Z = 25000.0f;

			TArray<AFortPlayerController*> AllFortPlayerController = UFortKismetLibrary::GetAllFortPlayerControllers(GameModeAthena, true, true);

			for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
			{
				AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(AllFortPlayerController[i]);
				if (!PlayerControllerAthena) continue;

				AFortPlayerState* PlayerState = Cast<AFortPlayerState>(PlayerControllerAthena->PlayerState);
				if (!PlayerState) continue;

				if (PlayerControllerAthena->Pawn)
					PlayerControllerAthena->Pawn->K2_DestroyActor();

				AFortPlayerPawn* PlayerPawn = Util::SpawnPlayer(PlayerControllerAthena, CenterPositionToSpawn, FRotator(), false);

				if (PlayerPawn)
				{
					PlayerPawn->SetMaxHealth(100);
					PlayerPawn->SetHealth(100);
					PlayerPawn->SetMaxShield(100);

					void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
					SetShield(PlayerPawn, 100);

					PlayerPawn->bIsSkydiving = true;
					PlayerPawn->OnRep_IsSkydiving(false);

					Inventory::ResetInventory(PlayerControllerAthena->WorldInventory, false);

					if (PlayerState->AbilitySystemComponent)
					{
						// 7FF66EC68170
						void (*ClearAllAbilities)(UAbilitySystemComponent* AbilitySystemComponent) = decltype(ClearAllAbilities)(0x618170 + uintptr_t(GetModuleHandle(0)));
						ClearAllAbilities(PlayerState->AbilitySystemComponent);

						UFortAbilitySet* DefaultAbilities = Globals::GetGameData()->GenericPlayerAbilitySet.Get();

						Abilities::GrantGameplayAbility(DefaultAbilities, PlayerPawn);
						Abilities::GrantGameplayEffect(DefaultAbilities, PlayerPawn);
						Abilities::GrantModifierAbilityFromPlaylist(PlayerPawn);

						UFortGameplayModifierItemDefinition* GameplayModifierItemDefinition = FindObjectFast<UFortGameplayModifierItemDefinition>("/Game/Athena/Playlists/Velocity/RedeployGlider_Modifier.RedeployGlider_Modifier");

						if (!GameplayModifierItemDefinition)
							GameplayModifierItemDefinition = StaticLoadObject<UFortGameplayModifierItemDefinition>(L"/Game/Athena/Playlists/Velocity/RedeployGlider_Modifier.RedeployGlider_Modifier");

						if (GameplayModifierItemDefinition)
							Abilities::GrantModifierAbility(GameplayModifierItemDefinition, PlayerPawn);
					}

					Functions::GiveLateGameInventory(PlayerControllerAthena);
				}

				AddFromAlivePlayers(GameModeAthena, PlayerControllerAthena);
			}

			Functions::StartSafeZone(GameModeAthena);
		}

		return true;
#else
		return StartAircraftPhase(GameModeAthena);
#endif // LATEGAME
	}

	void InitGameMode()
	{
		static auto FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();

		uintptr_t PatternSpawnDefaultPawnFor = MinHook::FindPattern(Patterns::SpawnDefaultPawnFor);
		uintptr_t PatternHandlePostSafeZonePhaseChanged = MinHook::FindPattern(Patterns::HandlePostSafeZonePhaseChanged);
		uintptr_t PatternStartAircraftPhase = MinHook::FindPattern(Patterns::StartAircraftPhase);

		MH_CreateHook((LPVOID)(PatternSpawnDefaultPawnFor), SpawnDefaultPawnForHook, nullptr);
		MH_EnableHook((LPVOID)(PatternSpawnDefaultPawnFor));
		MH_CreateHook((LPVOID)(PatternHandlePostSafeZonePhaseChanged), HandlePostSafeZonePhaseChangedHook, (LPVOID*)(&HandlePostSafeZonePhaseChanged));
		MH_EnableHook((LPVOID)(PatternHandlePostSafeZonePhaseChanged));
		MH_CreateHook((LPVOID)(PatternStartAircraftPhase), StartAircraftPhaseHook, (LPVOID*)(&StartAircraftPhase));
		MH_EnableHook((LPVOID)(PatternStartAircraftPhase));

		uintptr_t PatternAddFromAlivePlayers = MinHook::FindPattern(Patterns::AddFromAlivePlayers);
		uintptr_t PatternRemoveFromAlivePlayers = MinHook::FindPattern(Patterns::RemoveFromAlivePlayers);
		uintptr_t PatternApplyCustomizationToCharacter = MinHook::FindPattern(Patterns::ApplyCustomizationToCharacter);
		uintptr_t PatternHandleMatchHasStarted = MinHook::FindPattern(Patterns::HandleMatchHasStarted);

		AddFromAlivePlayers = decltype(AddFromAlivePlayers)(PatternAddFromAlivePlayers);
		RemoveFromAlivePlayers = decltype(RemoveFromAlivePlayers)(PatternRemoveFromAlivePlayers);
		ApplyCustomizationToCharacter = decltype(ApplyCustomizationToCharacter)(PatternApplyCustomizationToCharacter);
		HandleMatchHasStarted = decltype(HandleMatchHasStarted)(PatternHandleMatchHasStarted);

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}