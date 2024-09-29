#pragma once

namespace GameMode
{
	void (*RemoveFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController, AFortPlayerStateAthena* PlayerState, AFortPlayerPawnAthena* Pawn, UFortWeaponItemDefinition* WeaponItemDefinition, EDeathCause DeathCause, char a7);
	void (*AddFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController);
	void (*ApplyCharacterCustomization)(AFortPlayerState* PlayerState, AFortPawn* Pawn);
	void (*HandleMatchHasStarted)(AFortGameModeAthena* GameMode);

	bool bPreReadyToStartMatch = false;
	bool bWorldReady = false;

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
		AFortPlayerPawn* PlayerPawn = SpawnDefaultPawnFor(GameModeBase, PlayerController, StartSpot);

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

		// 7FF66F7BC760 (Je suis sévèrement autiste)
		void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
		SetShield(PlayerPawn, 0);

		GameMode::ApplyCharacterCustomization(PlayerState, PlayerPawn);

		UFortWeaponMeleeItemDefinition* WeaponMeleeItemDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");
		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

		if (PlayerControllerAthena)
		{
			UAthenaPickaxeItemDefinition* Pickaxe = PlayerControllerAthena->CustomizationLoadout.Pickaxe;

			if (Pickaxe->WeaponDefinition)
				WeaponMeleeItemDefinition = Pickaxe->WeaponDefinition;
		}

		Inventory::SetupInventory(PlayerController, WeaponMeleeItemDefinition);

		FN_LOG(LogHooks, Log, "AGameModeBase::SpawnDefaultPawnFor - called!");

		return PlayerPawn;
	}

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
				AFortGameModeAthena* GameMode = Cast<AFortGameModeAthena>(Globals::GetGameMode());
				AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

				if (!GameMode || !GameState)
					return;

				FName MatchState = GameMode->GetMatchState();

				if (GameMode->NumPlayers + GameMode->NumBots > 0 &&
					MatchState.ToString() == "WaitingToStart")
				{
					FName InProgress = UKismetStringLibrary::Conv_StringToName(L"InProgress");

					HandleMatchHasStarted(GameMode);

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
			AGameModeBase* GameModeBase = (AGameModeBase*)Object;
			auto Params = (Params::GameModeBase_HandleStartingNewPlayer*)Parms;

			if (!GameModeBase || !Params->NewPlayer)
			{
				FN_LOG(LogGameMode, Error, "[AGameModeBase::HandleStartingNewPlayer] Failed to get GameModeBase/NewPlayer");
				return;
			}

			if (bWorldReady)
			{
				AActor* PlayerStart = GameModeBase->ChoosePlayerStart(Params->NewPlayer);

				if (!PlayerStart)
				{
					FN_LOG(LogGameMode, Error, "[AGameModeBase::HandleStartingNewPlayer] Failed to get PlayerStart!");
					return;
				}

				/*AFortPlayerController* PlayerController = Cast<AFortPlayerController>(Params->NewPlayer);
				
				if (PlayerController)
				{
					UFortWeaponMeleeItemDefinition* WeaponMeleeItemDefinition = FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");
					AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(PlayerController);

					if (PlayerControllerAthena)
					{
						UAthenaPickaxeItemDefinition* Pickaxe = PlayerControllerAthena->CustomizationLoadout.Pickaxe;

						if (Pickaxe->WeaponDefinition)
							WeaponMeleeItemDefinition = Pickaxe->WeaponDefinition;
					}

					Inventory::SetupInventory(PlayerController, WeaponMeleeItemDefinition);
				}*/

				const FVector& PlayerStartLocation = PlayerStart->K2_GetActorLocation();
				const FRotator& PlayerStartRotation = PlayerStart->K2_GetActorRotation();

				Util::SpawnPlayer((AFortPlayerController*)Params->NewPlayer, PlayerStartLocation, PlayerStartRotation, true);
			}
		}
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