#pragma once

enum class EAIBotAction : uint8
{
	None = 0,
	Warmup = 1,
	Aircraft = 2,
	Skydive = 3,
	Looting = 4,
	Fighting = 5,
	Building = 6,
	Dancing = 7,
	EndGame = 8,
	EAIBotAction_MAX
};

class AAIBotOdyssey final
{
public:
	static inline std::map<APlayerController*, AAIBotOdyssey*> BotOdysseyMap;

	APlayerController* AIPlayerController = nullptr;
	APawn* AIPawn = nullptr;
	AActor* TargetActor = nullptr;
	EAIBotAction BotAction = EAIBotAction::None;

	APlayerController* GetAIPlayerController() const
	{
		return AIPlayerController;
	}

	AFortPlayerController* GetFortAIPlayerController() const
	{
		return Cast<AFortPlayerController>(AIPlayerController);
	}

	APawn* GetAIPawn() const
	{
		return AIPawn;
	}

	AFortPlayerPawn* GetFortAIPawn() const
	{
		return  Cast<AFortPlayerPawn>(AIPawn);
	}

	EAthenaGamePhase GetGamePhase()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState)
			return GameState->GamePhase;

		return EAthenaGamePhase::None;
	}

	void SetAIPlayerController(APlayerController* InPC)
	{
		if (AIPlayerController != InPC)
		{
			AIPlayerController = InPC;
		}
	}

	void InitPlayerTeam() const
	{
		AFortPlayerControllerAthena* FortAIPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(GetFortAIPlayerController());
		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

		if (FortAIPlayerControllerAthena && GameModeAthena)
		{
			// 7FF66F247000
			void (*ChoosePlayerTeam)(AFortGameModeAthena* GameMode, AFortPlayerControllerAthena* PlayerController) = decltype(ChoosePlayerTeam)(0xBF7000 + uintptr_t(GetModuleHandle(0)));
			ChoosePlayerTeam(GameModeAthena, FortAIPlayerControllerAthena);
		}
	}

	void InitAlivePlayers() const
	{
		AFortPlayerControllerAthena* FortAIPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(GetFortAIPlayerController());
		AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

		if (FortAIPlayerControllerAthena && GameModeAthena)
			GameMode::AddFromAlivePlayers(GameModeAthena, FortAIPlayerControllerAthena);
	}

	AFortPlayerStateAthena* InitPlayerStateBot() const
	{
		AFortPlayerStateAthena* PlayerState = Cast<AFortPlayerStateAthena>(GetAIPlayerController());

		if (!PlayerState)
		{
			PlayerState = Util::SpawnActor<AFortPlayerStateAthena>(AFortPlayerStateAthena::StaticClass());

			if (PlayerState)
			{
				PlayerState->SetOwner(AIPlayerController);
				PlayerState->OnRep_Owner();

				AIPlayerController->PlayerState = PlayerState;
				AIPlayerController->OnRep_PlayerState();

				PlayerState->bIsABot = true;
			}
		}

		return PlayerState;
	}

	TArray<UAthenaCosmeticItemDefinition*> GetAllCosmeticItems() const
	{
		static TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems;

		if (AllCosmeticItems.Num() > 0)
			return AllCosmeticItems;

		for (int32 i = 0; i < UObject::GObjects->Num(); i++)
		{
			UObject* GObject = UObject::GObjects->GetByIndex(i);

			if (!GObject)
				continue;

			if (GObject->IsA(UAthenaCosmeticItemDefinition::StaticClass()))
			{
				UAthenaCosmeticItemDefinition* CosmeticItemDefinition = Cast<UAthenaCosmeticItemDefinition>(GObject);
				if (!CosmeticItemDefinition) continue;

				AllCosmeticItems.Add(CosmeticItemDefinition);
			}
		}

		return AllCosmeticItems;
	}

	UAthenaSkyDiveContrailItemDefinition* ChooseRandomSkyDiveContrail() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems = GetAllCosmeticItems();
		static TArray<UAthenaSkyDiveContrailItemDefinition*> AllSkyDiveContrailItems;

		if (AllSkyDiveContrailItems.Num() <= 0)
		{
			for (int32 i = 0; i < AllCosmeticItems.Num(); i++)
			{
				UAthenaSkyDiveContrailItemDefinition* SkyDiveContrailItemDefinition = Cast<UAthenaSkyDiveContrailItemDefinition>(AllCosmeticItems[i]);

				if (!SkyDiveContrailItemDefinition)
					continue;

				AllSkyDiveContrailItems.Add(SkyDiveContrailItemDefinition);
			}
		}

		int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllSkyDiveContrailItems.Num());
		return AllSkyDiveContrailItems[RandomIndex];
	}

	UAthenaGliderItemDefinition* ChooseRandomGlider() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems = GetAllCosmeticItems();
		static TArray<UAthenaGliderItemDefinition*> AllGliderItems;

		if (AllGliderItems.Num() <= 0)
		{
			for (int32 i = 0; i < AllCosmeticItems.Num(); i++)
			{
				UAthenaGliderItemDefinition* GliderItemDefinition = Cast<UAthenaGliderItemDefinition>(AllCosmeticItems[i]);

				if (!GliderItemDefinition)
					continue;

				AllGliderItems.Add(GliderItemDefinition);
			}
		}

		int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllGliderItems.Num());
		return AllGliderItems[RandomIndex];
	}

	UAthenaPickaxeItemDefinition* ChooseRandomPickaxe() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems = GetAllCosmeticItems();
		static TArray<UAthenaPickaxeItemDefinition*> AllPickaxeItems;

		if (AllPickaxeItems.Num() <= 0)
		{
			for (int32 i = 0; i < AllCosmeticItems.Num(); i++)
			{
				UAthenaPickaxeItemDefinition* PickaxeItemDefinition = Cast<UAthenaPickaxeItemDefinition>(AllCosmeticItems[i]);

				if (!PickaxeItemDefinition)
					continue;

				AllPickaxeItems.Add(PickaxeItemDefinition);
			}
		}

		int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllPickaxeItems.Num());
		return AllPickaxeItems[RandomIndex];
	}

	UAthenaCharacterItemDefinition* ChooseRandomCharacter() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems = GetAllCosmeticItems();
		static TArray<UAthenaCharacterItemDefinition*> AllCharacterItems;

		if (AllCharacterItems.Num() <= 0)
		{
			for (int32 i = 0; i < AllCosmeticItems.Num(); i++)
			{
				UAthenaCharacterItemDefinition* CharacterItemDefinition = Cast<UAthenaCharacterItemDefinition>(AllCosmeticItems[i]);

				if (!CharacterItemDefinition)
					continue;

				AllCharacterItems.Add(CharacterItemDefinition);
			}
		}

		int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllCharacterItems.Num());
		return AllCharacterItems[RandomIndex];
	}

	UAthenaBackpackItemDefinition* ChooseRandomBackpack() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCosmeticItems = GetAllCosmeticItems();
		static TArray<UAthenaBackpackItemDefinition*> AllBackpackItems;

		if (AllBackpackItems.Num() <= 0)
		{
			for (int32 i = 0; i < AllCosmeticItems.Num(); i++)
			{
				UAthenaBackpackItemDefinition* BackpackItemDefinition = Cast<UAthenaBackpackItemDefinition>(AllCosmeticItems[i]);

				if (!BackpackItemDefinition)
					continue;

				AllBackpackItems.Add(BackpackItemDefinition);
			}
		}

		int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllBackpackItems.Num());
		return AllBackpackItems[RandomIndex];
	}

	void ChooseRandomCosmetics() const
	{
		AFortPlayerControllerAthena* FortAIPlayerControllerAthena = Cast<AFortPlayerControllerAthena>(GetFortAIPlayerController());

		if (FortAIPlayerControllerAthena)
		{
			/*FFortAthenaLoadout* CustomizationLoadout = &FortAIPlayerControllerAthena->CustomizationLoadout;
			CustomizationLoadout->SkyDiveContrail = Cast<UAthenaSkyDiveContrailItemDefinition>(ChooseRandomCosmecticWithClass(UAthenaSkyDiveContrailItemDefinition::StaticClass()));
			CustomizationLoadout->Glider = Cast<UAthenaGliderItemDefinition>(ChooseRandomCosmecticWithClass(UAthenaGliderItemDefinition::StaticClass()));
			CustomizationLoadout->Pickaxe = Cast<UAthenaPickaxeItemDefinition>(ChooseRandomCosmecticWithClass(UAthenaPickaxeItemDefinition::StaticClass()));
			CustomizationLoadout->Character = Cast<UAthenaCharacterItemDefinition>(ChooseRandomCosmecticWithClass(UAthenaCharacterItemDefinition::StaticClass()));
			CustomizationLoadout->Backpack = Cast<UAthenaBackpackItemDefinition>(ChooseRandomCosmecticWithClass(UAthenaBackpackItemDefinition::StaticClass()));*/

			FFortAthenaLoadout CustomizationLoadout;
			/*CustomizationLoadout.BannerIconId = FString(0);
			CustomizationLoadout.BannerColorId = FString(0);*/
			CustomizationLoadout.SkyDiveContrail = ChooseRandomSkyDiveContrail();
			CustomizationLoadout.Glider = ChooseRandomGlider();
			CustomizationLoadout.Pickaxe = ChooseRandomPickaxe();
			CustomizationLoadout.Character = ChooseRandomCharacter();
			CustomizationLoadout.Hat = nullptr;
			CustomizationLoadout.Backpack = ChooseRandomBackpack();
			CustomizationLoadout.LoadingScreen = nullptr;
			CustomizationLoadout.BattleBus = nullptr;
			CustomizationLoadout.VehicleDecoration = nullptr;
			CustomizationLoadout.CallingCard = nullptr;
			CustomizationLoadout.MapMarker = nullptr;
			CustomizationLoadout.VictoryPose = nullptr;
			CustomizationLoadout.MusicPack = nullptr;
			CustomizationLoadout.WeaponSkin = nullptr;
			CustomizationLoadout.PetSkin = nullptr;

			// 7FF66F7FB320
			FFortAthenaLoadout* (*GetAthenaLoadoutWithOverrides)(AFortPlayerController* PlayerController, FFortAthenaLoadout * PrimaryAthenaLoadout, FFortAthenaLoadout * AthenaLoadout) = decltype(GetAthenaLoadoutWithOverrides)(0x11AB320 + uintptr_t(GetModuleHandle(0)));
			FFortAthenaLoadout* AthenaLoadoutWithOverrides = GetAthenaLoadoutWithOverrides(FortAIPlayerControllerAthena, &FortAIPlayerControllerAthena->CustomizationLoadout, &CustomizationLoadout);

			if (AthenaLoadoutWithOverrides)
			{
				// 7FF66F265030
				FFortAthenaLoadout* (*CopyAthenaLoadout)(FFortAthenaLoadout* PrimaryAthenaLoadout, FFortAthenaLoadout* AthenaLoadout) = decltype(CopyAthenaLoadout)(0xC15030 + uintptr_t(GetModuleHandle(0)));
				CopyAthenaLoadout(&FortAIPlayerControllerAthena->CustomizationLoadout, AthenaLoadoutWithOverrides);
			}
		}
	}

	void InitBotOdyssey(APlayerController* InPC)
	{
		if (!InPC)
			return;

		if (GetGamePhase() == EAthenaGamePhase::Warmup)
		{
			SetAIPlayerController(InPC);

			AFortPlayerController* FortAIPlayerController = GetFortAIPlayerController();
			AFortGameModeAthena* GameModeAthena = Cast<AFortGameModeAthena>(Globals::GetGameMode());

			if (FortAIPlayerController && GameModeAthena)
			{
				FortAIPlayerController->ServerChangeName(L"Odyssey BOT");

				InitPlayerTeam();
				InitAlivePlayers();
				// ChooseRandomCosmetics();

				GameModeAthena->HandleStartingNewPlayer(FortAIPlayerController);

				if (FortAIPlayerController->MyFortPawn)
				{
					GameMode::ApplyCharacterCustomization((AFortPlayerState*)FortAIPlayerController->PlayerState, FortAIPlayerController->MyFortPawn);
				}
			}

			/*AFortPlayerStateAthena* PlayerState = InitPlayerStateBot();

			

			if (GameMode)
				GameMode->HandleStartingNewPlayer(AIPlayerController);*/
			
		}
	}
};

static AAIBotOdyssey* CreateBotOdyssey()
{
	AAthena_PlayerController_C* PlayerController = Util::SpawnActor<AAthena_PlayerController_C>(AAthena_PlayerController_C::StaticClass());

	if (PlayerController)
	{
		AAIBotOdyssey* NewClass = new AAIBotOdyssey;

		NewClass->InitBotOdyssey(PlayerController);
		AAIBotOdyssey::BotOdysseyMap.insert_or_assign(PlayerController, NewClass);

		return NewClass;
	}

	return nullptr;
}

static AAIBotOdyssey* FindOrCreateBotOdyssey(APlayerController* PlayerController)
{
	AAIBotOdyssey* BotOdyssey = nullptr;

	if (!PlayerController)
		return BotOdyssey;

	for (auto& Find : AAIBotOdyssey::BotOdysseyMap)
	{
		if (Find.first == PlayerController)
		{
			BotOdyssey = Find.second;
			break;
		}
	}

	if (!BotOdyssey)
		BotOdyssey = CreateBotOdyssey();

	return BotOdyssey;
}