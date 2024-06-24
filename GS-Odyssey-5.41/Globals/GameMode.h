#pragma once

namespace GameMode
{
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

			if (!bWorldReady)
				return;

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
		else if (FunctionName.contains("OnAircraftExitedDropZone"))
		{
			AFortGameModeAthena* GameMode = (AFortGameModeAthena*)Object;

			if (!GameMode)
			{
				FN_LOG(LogGameMode, Error, "[AFortGameModeAthena::OnAircraftExitedDropZone] Failed to get GameMode/World");
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

	void InitGameMode()
	{
		uintptr_t PatternApplyCharacterCustomization = MinHook::FindPattern(Patterns::ApplyCharacterCustomization);

		ApplyCharacterCustomization = decltype(ApplyCharacterCustomization)(PatternApplyCharacterCustomization);

		FN_LOG(LogInit, Log, "InitGameMode Success!");
	}
}