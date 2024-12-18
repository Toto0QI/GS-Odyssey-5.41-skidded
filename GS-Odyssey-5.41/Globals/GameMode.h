#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace GameMode
{
	/* ------------------------------------ AFortGameModeAthenaOG ------------------------------------ */
	bool (*ReadyToStartMatchOG)(AFortGameModeAthena* GameModeAthena);
	void (*HandlePostSafeZonePhaseChangedOG)(AFortGameModeAthena* GameModeAthena);
	bool (*StartAircraftPhaseOG)(AFortGameModeAthena* GameModeAthena);



	/* ------------------------------------- AFortGameModeAthena ------------------------------------- */

	bool ReadyToStartMatch(AFortGameModeAthena* GameModeAthena)
	{
		AFortGameStateAthena* GameStateAthena = Cast<AFortGameStateAthena>(GameModeAthena->GameState);

		if (GameStateAthena && !GameStateAthena->bPlaylistDataIsLoaded)
		{
			FURL URL;
			URL.Port = 7777;
			Beacon::ListenServer(GameModeAthena->GetWorld(), URL);

			int32 PlaylistId = 2; // Solo
			// int32 PlaylistId = 10; // Duo
			// int32 PlaylistId = 9; // Squad
			// int32 PlaylistId = 35; // Playground 
			// int32 PlaylistId = 50; // 50VS50
			// int32 PlaylistId = 140; // Bling Solo 
			// int32 PlaylistId = 44; // Close Solo
			// int32 PlaylistId = 185; // Soaring Solo

			UFortPlaylistAthena* PlaylistAthena = GameModeAthena->PlaylistManager->GetPlaylistByPlaylistId(PlaylistId);

			if (PlaylistAthena)
			{
				Functions::SetPlaylistData(GameModeAthena, PlaylistAthena);

				FN_LOG(LogGameMode, Log, L"[AGameMode::ReadyToStartMatch] AISettings: %s", GameModeAthena->AISettings->GetName().c_str());
				FN_LOG(LogGameMode, Log, L"[AGameMode::ReadyToStartMatch] AIDirector: %s", GameModeAthena->AIDirector->GetName().c_str());
				FN_LOG(LogGameMode, Log, L"[AGameMode::ReadyToStartMatch] AIGoalManager: %s", GameModeAthena->AIGoalManager->GetName().c_str());
				FN_LOG(LogGameMode, Log, L"[AGameMode::ReadyToStartMatch] PlaylistAthena: %s", PlaylistAthena->GetName().c_str());
				FN_LOG(LogGameMode, Log, L"[AGameMode::ReadyToStartMatch] Choose Playlist Finish!");

				GameStateAthena->bPlaylistDataIsLoaded = true;
			}
		}

		return ReadyToStartMatchOG(GameModeAthena);
	}

	AFortPlayerPawn* SpawnDefaultPawnFor(AFortGameModeAthena* GameModeAthena, AController* NewPlayer, AActor* StartSpot)
	{
		if (!NewPlayer || !StartSpot)
			return nullptr;

		AFortPlayerControllerAthena* PlayerControllerAthena = Cast<AFortPlayerControllerAthena>(NewPlayer);
		AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(NewPlayer->PlayerState);

		if (!PlayerControllerAthena || !PlayerStateAthena)
			return nullptr;

		AFortPlayerPawn* PlayerPawn = GameModeAthena->SpawnDefaultPawnFor(PlayerControllerAthena, StartSpot);
		
		if (!PlayerPawn)
			return nullptr;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerStateAthena->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->ClearAllAbilities();

			UFortGameData* GameData = Globals::GetGameData();
			UFortAbilitySet* DefaultAbilities = Functions::LoadAbilitySet(GameData->GenericPlayerAbilitySet);

			Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);
		}

		PlayerStateAthena->ApplyCharacterCustomization(PlayerPawn);

		UFortWeaponMeleeItemDefinition* PickaxeItemDefinition = nullptr;

		if (PlayerControllerAthena)
		{
			UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = PlayerControllerAthena->CustomizationLoadout.Pickaxe;

			if (AthenaPickaxeItemDefinition)
				PickaxeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

			if (!PickaxeItemDefinition)
			{
				UFortGameData* GameData = Globals::GetGameData();
				UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = GameData->DefaultPickaxeSkin;

				if (DefaultPickaxeSkin)
					PickaxeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
			}
		}

		Inventory::SetupInventory(PlayerControllerAthena, PickaxeItemDefinition);

		return PlayerPawn;
	}

	void HandlePostSafeZonePhaseChanged(AFortGameModeAthena* GameModeAthena)
	{
		FN_LOG(LogGameMode, Log, L"[AFortGameModeAthena::HandlePostSafeZonePhaseChanged] GameModeAthena: %s", GameModeAthena->GetName().c_str());
		FN_LOG(LogGameMode, Log, L"[AFortGameModeAthena::HandlePostSafeZonePhaseChanged] called!");

		HandlePostSafeZonePhaseChangedOG(GameModeAthena);
	}

	bool StartAircraftPhase(AFortGameModeAthena* GameModeAthena)
	{
		TArray<AFortPlayerController*> AllFortPlayerController = UFortKismetLibrary::GetAllFortPlayerControllers(GameModeAthena, true, true);

		for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
		{
			AFortPlayerController* PlayerController = AllFortPlayerController[i];
			if (!PlayerController) continue;

			Inventory::ResetInventory(PlayerController->WorldInventory);
		}

		return StartAircraftPhaseOG(GameModeAthena);
	}

	void InitGameMode()
	{
		AFortGameModeAthena* FortGameModeAthenaDefault = AFortGameModeAthena::GetDefaultObj();
		UClass* FortGameModeAthenaClass = AFortGameModeAthena::StaticClass();

		/* ------------------------------------- AFortGameModeAthena ------------------------------------- */

		MinHook::HookVTable(FortGameModeAthenaDefault, 0x7D8 / 8, ReadyToStartMatch, (LPVOID*)(&ReadyToStartMatchOG), "AFortGameModeAthena::ReadyToStartMatch");
		MinHook::HookVTable(FortGameModeAthenaDefault, 0x610 / 8, SpawnDefaultPawnFor, nullptr, "AFortGameModeAthena::SpawnDefaultPawnFor");

		uintptr_t PatternHandlePostSafeZonePhaseChanged = MinHook::FindPattern(Patterns::HandlePostSafeZonePhaseChanged);
		uintptr_t PatternStartAircraftPhase = MinHook::FindPattern(Patterns::StartAircraftPhase);

		MH_CreateHook((LPVOID)(PatternHandlePostSafeZonePhaseChanged), HandlePostSafeZonePhaseChanged, (LPVOID*)(&HandlePostSafeZonePhaseChangedOG));
		MH_EnableHook((LPVOID)(PatternHandlePostSafeZonePhaseChanged));

		MH_CreateHook((LPVOID)(PatternStartAircraftPhase), StartAircraftPhase, (LPVOID*)(&StartAircraftPhaseOG));
		MH_EnableHook((LPVOID)(PatternStartAircraftPhase));

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, L"InitGameMode Success!");
	}
}