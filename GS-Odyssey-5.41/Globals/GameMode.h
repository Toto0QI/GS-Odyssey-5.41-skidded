#pragma once

namespace GameMode
{
	void (*RemoveFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController, AFortPlayerStateAthena* PlayerState, AFortPlayerPawnAthena* Pawn, UFortWeaponItemDefinition* WeaponItemDefinition, EDeathCause DeathCause, char a7);
	void (*AddFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController);
	void (*ApplyCharacterCustomization)(AFortPlayerState* PlayerState, AFortPawn* Pawn);
	void (*HandleMatchHasStarted)(AFortGameModeAthena* GameMode);

	bool bPreReadyToStartMatch = false;
	bool bWorldReady = false;

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ReadyToStartMatch"))
		{
			if (!bPreReadyToStartMatch)
			{
				//Globals::GetFortEngine(true);
				Globals::GetWorld(true);

				FN_LOG(LogHooks, Debug, "bPreReadyToStartMatch called!");

				bPreReadyToStartMatch = true;
			}
			else if (bPreReadyToStartMatch && bWorldReady)
			{
				AFortGameModeAthena* GameMode = Globals::GetGameMode();
				AFortGameStateAthena* GameState = Globals::GetGameState();

				if (!GameMode || !GameState)
					return;

				FName MatchState = GameMode->GetMatchState();

				if (GameMode->NumPlayers + GameMode->NumBots > 0 &&
					MatchState.ToString() == "WaitingToStart")
				{
					FName InProgress = UKismetStringLibrary::Conv_StringToName(L"InProgress");

					HandleMatchHasStarted(Globals::GetGameMode());

					GameMode->MatchState = InProgress;
					GameMode->K2_OnSetMatchState(InProgress);

					Functions::InitializeTreasureChests();
					Functions::InitializeAmmoBoxs();
					Functions::InitializeLlamas();

					Functions::FillVendingMachines();
				}
			}
		}
		else if (FunctionName.contains("HandleStartingNewPlayer"))
		{
			AGameModeBase* GameMode = (AGameModeBase*)Object;
			auto Params = (Params::GameModeBase_HandleStartingNewPlayer*)Parms;

			if (!GameMode || !Params->NewPlayer)
			{
				FN_LOG(LogGameMode, Error, "[AGameModeBase::HandleStartingNewPlayer] Failed to get GameMode/NewPlayer");
				return;
			}

			if (bWorldReady)
			{
				AActor* PlayerStart = GameMode->ChoosePlayerStart(Params->NewPlayer);

				if (!PlayerStart)
				{
					FN_LOG(LogGameMode, Error, "[AGameModeBase::HandleStartingNewPlayer] Failed to get PlayerStart!");
					return;
				}

				const FVector& PlayerStartLocation = PlayerStart->K2_GetActorLocation();
				const FRotator& PlayerStartRotation = PlayerStart->K2_GetActorRotation();

				Util::SpawnPlayer((AFortPlayerControllerAthena*)Params->NewPlayer, PlayerStartLocation, PlayerStartRotation, true);
			}
		}
	}

	APlayerPawn_Athena_C* SpawnDefaultPawnForHook(AGameModeBase* GameMode, AController* NewPlayer, AActor* StartSpot)
	{
		FTransform SpawnTransform = StartSpot->GetTransform();

		APlayerPawn_Athena_C* PlayerPawn = (APlayerPawn_Athena_C*)GameMode->SpawnDefaultPawnAtTransform(NewPlayer, SpawnTransform);

		if (!PlayerPawn)
		{
			FN_LOG(LogGameMode, Error, "[AGameModeBase::SpawnDefaultPawnFor] failed to spawn PlayerPawn!");
			return nullptr;
		}

		PlayerPawn->SetMaxHealth(100);
		PlayerPawn->SetHealth(100);
		PlayerPawn->SetMaxShield(100);

		// 7FF66F7BC760 (Je suis sévèrement autiste)
		void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));

		SetShield(PlayerPawn, 0);

		GameMode::ApplyCharacterCustomization((AFortPlayerState*)NewPlayer->PlayerState, PlayerPawn);

		FN_LOG(LogGameMode, Error, "[AGameModeBase::SpawnDefaultPawnFor] called!");

		return PlayerPawn;
	}

	void InitGameMode()
	{
		static auto FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();

		uintptr_t PatternSpawnDefaultPawnFor = MinHook::FindPattern(Patterns::SpawnDefaultPawnFor);

		MH_CreateHook((LPVOID)(PatternSpawnDefaultPawnFor), SpawnDefaultPawnForHook, nullptr);
		MH_EnableHook((LPVOID)(PatternSpawnDefaultPawnFor));

		uintptr_t PatternAddFromAlivePlayers = MinHook::FindPattern(Patterns::AddFromAlivePlayers);
		uintptr_t PatternRemoveFromAlivePlayers = MinHook::FindPattern(Patterns::RemoveFromAlivePlayers);
		uintptr_t PatternApplyCharacterCustomization = MinHook::FindPattern(Patterns::ApplyCharacterCustomization);
		uintptr_t PatternHandleMatchHasStarted = MinHook::FindPattern(Patterns::HandleMatchHasStarted);

		AddFromAlivePlayers = decltype(AddFromAlivePlayers)(PatternAddFromAlivePlayers);
		RemoveFromAlivePlayers = decltype(RemoveFromAlivePlayers)(PatternRemoveFromAlivePlayers);
		ApplyCharacterCustomization = decltype(ApplyCharacterCustomization)(PatternApplyCharacterCustomization);
		HandleMatchHasStarted = decltype(HandleMatchHasStarted)(PatternHandleMatchHasStarted);

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}