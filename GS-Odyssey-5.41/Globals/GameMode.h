#pragma once

namespace GameMode
{
	void (*RemoveFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController, AFortPlayerStateAthena* PlayerState, AFortPlayerPawnAthena* Pawn, UFortWeaponItemDefinition* WeaponItemDefinition, EDeathCause DeathCause, char a7);
	void (*AddFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController);
	void (*ApplyCharacterCustomization)(AFortPlayerState* PlayerState, AFortPawn* Pawn);

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
				Globals::GetFortEngine(true);
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
					FName InProgress = Globals::GetStringLibrary()->Conv_StringToName(L"InProgress");

					GameState->GamePhase = EAthenaGamePhase::Warmup;
					GameState->OnRep_GamePhase(EAthenaGamePhase::None);

					GameMode->MatchState = InProgress;
					GameMode->K2_OnSetMatchState(InProgress);

					Functions::InitializeTreasureChests();
					Functions::InitializeAmmoBoxs();
					Functions::InitializeLlamas();

					Functions::FillVendingMachines();

					TArray<AActor*> OutActors;
					UGameplayStatics::GetAllActorsOfClass(Globals::GetWorld(), ACUBE_C::StaticClass(), &OutActors);

					for (int32 i = 0; i < OutActors.Num(); i++)
					{
						ACUBE_C* CUBE = (ACUBE_C*)OutActors[i];
						if (!CUBE) continue;

						/*CUBE->SpawnCube();
						CUBE->OnRep_CubeSpawn();*/

						CUBE->Next(560);
					}

					GameMode->StartPlay();
					GameMode->StartMatch();
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
		else if (FunctionName.contains("OnAircraftExitedDropZone"))
		{
			AFortGameModeAthena* GameMode = (AFortGameModeAthena*)Object;

			if (!GameMode)
			{
				FN_LOG(LogGameMode, Error, "[AFortGameModeAthena::OnAircraftExitedDropZone] Failed to get GameMode");
				return;
			}

			TArray<AFortPlayerController*> AllFortPlayerController = Globals::GetKismetLibrary()->GetAllFortPlayerControllers(GameMode, true, false);

			for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
			{
				AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)AllFortPlayerController[i];
				if (!PlayerController) continue;

				if (PlayerController->Pawn || !PlayerController->IsInAircraft())
					continue;

				PlayerController->ServerAttemptAircraftJump(PlayerController->GetControlRotation());
			}
		}
	}

	APlayerPawn_Athena_C* SpawnDefaultPawnFor(AGameModeBase* GameMode, AController* NewPlayer, AActor* StartSpot)
	{
		TSubclassOf<APawn> DefaultPawnClass = GameMode->DefaultPawnClass;

		if (DefaultPawnClass.Get())
		{
			FN_LOG(LogGameMode, Debug, "[AGameModeBase::SpawnDefaultPawnFor] DefaultPawnClass: %s", DefaultPawnClass.Get()->GetName().c_str());
		}

		FTransform SpawnTransform = StartSpot->GetTransform();

		APlayerPawn_Athena_C* PlayerPawn = (APlayerPawn_Athena_C*)GameMode->SpawnDefaultPawnAtTransform(NewPlayer, SpawnTransform);

		if (!PlayerPawn)
		{
			FN_LOG(LogGameMode, Error, "[AGameModeBase::SpawnDefaultPawnFor] failed to spawn PlayerPawn!");
			return nullptr;
		}

		// Function VTable [SpawnDefaultPawnFor] successfully hooked with Offset [0xc017a0], IdaAddress [00007FF66F2517A0]

		FN_LOG(LogGameMode, Debug, "[AGameModeBase::SpawnDefaultPawnFor] func called!");

		return PlayerPawn;
	}

	void InitGameMode()
	{
		static auto FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();

		uintptr_t PatternAddFromAlivePlayers = MinHook::FindPattern(Patterns::AddFromAlivePlayers);
		uintptr_t PatternRemoveFromAlivePlayers = MinHook::FindPattern(Patterns::RemoveFromAlivePlayers);
		uintptr_t PatternApplyCharacterCustomization = MinHook::FindPattern(Patterns::ApplyCharacterCustomization);

		AddFromAlivePlayers = decltype(AddFromAlivePlayers)(PatternAddFromAlivePlayers);
		RemoveFromAlivePlayers = decltype(RemoveFromAlivePlayers)(PatternRemoveFromAlivePlayers);
		ApplyCharacterCustomization = decltype(ApplyCharacterCustomization)(PatternApplyCharacterCustomization);

		MinHook::HookVTable(FortGameModeAthenaDefault, 0xC2, SpawnDefaultPawnFor, nullptr, "SpawnDefaultPawnFor");

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}