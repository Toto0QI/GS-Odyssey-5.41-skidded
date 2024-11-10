#pragma once

#ifdef BOTS
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

	AFortPlayerControllerAthena* GetFortAIPlayerController() const
	{
		return Cast<AFortPlayerControllerAthena>(AIPlayerController);
	}

	APawn* GetAIPawn() const
	{
		return AIPawn;
	}

	AFortPlayerPawnAthena* GetFortAIPawn() const
	{
		return  Cast<AFortPlayerPawnAthena>(AIPawn);
	}

	AActor* GetTargetActor() const
	{
		return TargetActor;
	}

	EAIBotAction GetBotAction() const
	{
		return BotAction;
	}

	EAthenaGamePhase GetGamePhase()
	{
		AFortGameStateAthena* GameState = Cast<AFortGameStateAthena>(Globals::GetGameState());

		if (GameState)
			return GameState->GamePhase;

		return EAthenaGamePhase::None;
	}

	void SetAIPawn(APawn* NewAIPawn)
	{
		if (AIPawn != NewAIPawn)
		{
			AIPawn = NewAIPawn;
			AIPawn->SetActorTickEnabled(true);
		}
	}

	void SetAIPlayerController(APlayerController* NewAIPlayerController)
	{
		if (AIPlayerController != NewAIPlayerController)
		{
			AIPlayerController = NewAIPlayerController;
			AIPlayerController->SetActorTickEnabled(true);
		}
	}

	void SetTargetActor(AActor* NewTargetActor)
	{
		if (TargetActor != NewTargetActor)
		{
			TargetActor = NewTargetActor;
		}
	}

	void SetBotAction(EAIBotAction NewBotAction)
	{
		if (BotAction != NewBotAction)
		{
			BotAction = NewBotAction;
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
			GameModeAthena->AddFromAlivePlayers(FortAIPlayerControllerAthena);
	}

	AFortPlayerStateAthena* InitPlayerState() const
	{
		if (!AIPlayerController)
			return nullptr;

		void (*InitPlayerState)(AController* Controller) = decltype(InitPlayerState)(AIPlayerController->VTable[0xD5]);
		InitPlayerState(AIPlayerController);

		return Cast<AFortPlayerStateAthena>(AIPlayerController->PlayerState);
	}

	AFortInventory* InitWorldInventory() const
	{
		AFortPlayerController* FortAIPlayerController = GetFortAIPlayerController();

		if (!FortAIPlayerController)
			return nullptr;

		AFortInventory* WorldInventory = FortAIPlayerController->WorldInventory;

		if (!WorldInventory)
		{
			WorldInventory = Util::SpawnActor<AFortInventory>(AFortInventory::StaticClass());

			if (WorldInventory)
			{
				WorldInventory->SetOwner(FortAIPlayerController);
				WorldInventory->OnRep_Owner();

				FortAIPlayerController->WorldInventory = WorldInventory;
				FortAIPlayerController->bHasInitializedWorldInventory = true;
				FortAIPlayerController->WorldInventory->HandleInventoryLocalUpdate();
			}
		}

		return WorldInventory;
	}

	AFortQuickBars* InitQuickBars() const
	{
		AFortPlayerController* FortAIPlayerController = GetFortAIPlayerController();

		if (!FortAIPlayerController)
			return nullptr;

		AFortQuickBars* QuickBars = FortAIPlayerController->QuickBars;

		if (!QuickBars)
		{
			QuickBars = Util::SpawnActor<AFortQuickBars>(AFortQuickBars::StaticClass());

			if (QuickBars)
			{
				QuickBars->SetOwner(FortAIPlayerController);
				QuickBars->OnRep_Owner();

				FortAIPlayerController->QuickBars = QuickBars;
				FortAIPlayerController->OnRep_QuickBar();
			}
		}

		return QuickBars;
	}

	void InitAbilities() const
	{
		AFortPlayerController* FortAIPlayerController = GetFortAIPlayerController();

		if (!FortAIPlayerController)
			return;

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(FortAIPlayerController->PlayerState);

		if (!PlayerState)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

		if (!AbilitySystemComponent)
			AbilitySystemComponent = Cast<UFortAbilitySystemComponent>(UGameplayStatics::SpawnObject(UFortAbilitySystemComponent::StaticClass(), PlayerState));

		AFortPlayerPawn* PlayerPawn = FortAIPlayerController->MyFortPawn;

		if (AbilitySystemComponent && PlayerPawn)
		{
			// 7FF66EC68170
			void (*ClearAllAbilities)(UAbilitySystemComponent* AbilitySystemComponent) = decltype(ClearAllAbilities)(0x618170 + uintptr_t(GetModuleHandle(0)));
			ClearAllAbilities(PlayerState->AbilitySystemComponent);

			UFortAbilitySet* DefaultAbilities = Globals::GetGameData()->GenericPlayerAbilitySet.Get();

			Abilities::GrantGameplayAbility(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantGameplayEffect(DefaultAbilities, AbilitySystemComponent);
			Abilities::GrantModifierAbilityFromPlaylist(AbilitySystemComponent);
		}
	}

	void InitStartInventory() const
	{
		AFortPlayerControllerAthena* FortAIPlayerController = Cast<AFortPlayerControllerAthena>(GetFortAIPlayerController());

		if (!FortAIPlayerController)
			return;

		UAthenaPickaxeItemDefinition* AthenaPickaxeItemDefinition = FortAIPlayerController->CustomizationLoadout.Pickaxe;
		UFortWeaponMeleeItemDefinition* WeaponMeleeItemDefinition = nullptr;

		if (AthenaPickaxeItemDefinition)
			WeaponMeleeItemDefinition = AthenaPickaxeItemDefinition->WeaponDefinition;

		if (!WeaponMeleeItemDefinition)
		{
			UAthenaPickaxeItemDefinition* DefaultPickaxeSkin = Globals::GetGameData()->DefaultPickaxeSkin;

			if (DefaultPickaxeSkin)
				WeaponMeleeItemDefinition = DefaultPickaxeSkin->WeaponDefinition;
		}

		if (WeaponMeleeItemDefinition)
		{
			Inventory::SetupInventory(FortAIPlayerController, WeaponMeleeItemDefinition);

			AFortInventory* WorldInventory = FortAIPlayerController->WorldInventory;

			if (WorldInventory)
			{
				WorldInventory->Inventory.MarkArrayDirty();
				WorldInventory->HandleInventoryLocalUpdate();

				UFortWorldItem* WorldItem = Cast<UFortWorldItem>(FortAIPlayerController->K2_FindExistingItemForDefinition(WeaponMeleeItemDefinition, false));

				if (WorldItem)
					FortAIPlayerController->ServerExecuteInventoryItem(WorldItem->ItemEntry.ItemGuid);
			}
		}
	}

	void ApplyCustomization() const
	{
		AFortPlayerControllerAthena* FortAIPlayerController = GetFortAIPlayerController();

		if (!FortAIPlayerController)
			return;

		AFortPlayerState* PlayerState = Cast<AFortPlayerState>(FortAIPlayerController->PlayerState);

		if (!PlayerState)
			return;

		AFortPlayerPawn* PlayerPawn = FortAIPlayerController->MyFortPawn;

		if (!PlayerPawn)
			return;

		PlayerState->ApplyCharacterCustomization(PlayerPawn);

		UAthenaCharacterItemDefinition* AthenaCharacterItemDefinition = FortAIPlayerController->CustomizationLoadout.Character;
		UAthenaBackpackItemDefinition* AthenaBackpackItemDefinition = FortAIPlayerController->CustomizationLoadout.Backpack;

		if (AthenaCharacterItemDefinition)
		{
			UFortHeroType* HeroDefinition = AthenaCharacterItemDefinition->HeroDefinition;
			if (!HeroDefinition) return;

			for (int32 i = 0; i < HeroDefinition->Specializations.Num(); i++)
			{
				TSoftObjectPtr<UFortHeroSpecialization> Specialization = HeroDefinition->Specializations[i];
				UFortHeroSpecialization* HeroSpecialization = Specialization.Get();

				if (!HeroSpecialization)
				{
					const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(Specialization.ObjectID.AssetPathName); // ToString doesn't work idk
					HeroSpecialization = StaticLoadObject<UFortHeroSpecialization>(AssetPathName.CStr());
				}

				if (!HeroSpecialization)
					continue;

				bool bChooseGender = false;
				for (int32 j = 0; j < HeroSpecialization->CharacterParts.Num(); j++)
				{
					TSoftObjectPtr<UCustomCharacterPart> CharacterPart = HeroSpecialization->CharacterParts[j];
					UCustomCharacterPart* CustomCharacterPart = CharacterPart.Get();

					if (!CustomCharacterPart)
					{
						const FString& AssetPathName = UKismetStringLibrary::Conv_NameToString(CharacterPart.ObjectID.AssetPathName); // ToString doesn't work idk
						CustomCharacterPart = StaticLoadObject<UCustomCharacterPart>(AssetPathName.CStr());
					}

					if (!CustomCharacterPart)
						continue;

					PlayerPawn->ServerChoosePart(CustomCharacterPart->CharacterPartType, CustomCharacterPart);

					if (!bChooseGender)
					{
						PlayerPawn->ServerChooseGender(CustomCharacterPart->GenderPermitted);
						bChooseGender = true;
					}
				}
			}
		}
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
		TArray<UAthenaCosmeticItemDefinition*> AllSkyDiveContrailItems = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaSkyDiveContrail);
		return Cast<UAthenaSkyDiveContrailItemDefinition>(AllSkyDiveContrailItems[std::rand() % AllSkyDiveContrailItems.Num()]);
	}

	UAthenaGliderItemDefinition* ChooseRandomGlider() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllGliderItems = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaGlider);
		return Cast<UAthenaGliderItemDefinition>(AllGliderItems[std::rand() % AllGliderItems.Num()]);
	}

	UAthenaPickaxeItemDefinition* ChooseRandomPickaxe() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllPickaxeItems = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaPickaxe);
		return Cast<UAthenaPickaxeItemDefinition>(AllPickaxeItems[std::rand() % AllPickaxeItems.Num()]);
	}

	UAthenaCharacterItemDefinition* ChooseRandomCharacter() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllCharacterItems = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaCharacter);
		return Cast<UAthenaCharacterItemDefinition>(AllCharacterItems[std::rand() % AllCharacterItems.Num()]);
	}

	UAthenaBackpackItemDefinition* ChooseRandomBackpack() const
	{
		TArray<UAthenaCosmeticItemDefinition*> AllBackpackItems = UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaBackpack);
		return Cast<UAthenaBackpackItemDefinition>(AllBackpackItems[std::rand() % AllBackpackItems.Num()]);
	}

	void ChooseRandomCosmetics() const
	{
		AFortPlayerControllerAthena* FortAIPlayerControllerAthena = GetFortAIPlayerController();

		if (FortAIPlayerControllerAthena)
		{
			FFortAthenaLoadout* CustomizationLoadout = &FortAIPlayerControllerAthena->CustomizationLoadout;
			if (!CustomizationLoadout) return;

			UFortniteAutomationBlueprintLibrary::GetAllAthenaCosmetics(EFortItemType::AthenaCharacter); // à tester les trikiz

			CustomizationLoadout->SkyDiveContrail = ChooseRandomSkyDiveContrail();
			CustomizationLoadout->Glider = ChooseRandomGlider();
			CustomizationLoadout->Pickaxe = ChooseRandomPickaxe();
			CustomizationLoadout->Character = ChooseRandomCharacter();
			CustomizationLoadout->Backpack = ChooseRandomBackpack();
			return;

			// 7FF66F7FB320
			/*FFortAthenaLoadout* (*GetAthenaLoadoutWithOverrides)(AFortPlayerController * PlayerController, FFortAthenaLoadout * PrimaryAthenaLoadout, FFortAthenaLoadout * AthenaLoadout) = decltype(GetAthenaLoadoutWithOverrides)(0x11AB320 + uintptr_t(GetModuleHandle(0)));
			FFortAthenaLoadout* AthenaLoadoutWithOverrides = GetAthenaLoadoutWithOverrides(FortAIPlayerControllerAthena, &FortAIPlayerControllerAthena->CustomizationLoadout, &CustomizationLoadout);

			if (AthenaLoadoutWithOverrides)
			{
				// 7FF66F265030
				FFortAthenaLoadout* (*CopyAthenaLoadout)(FFortAthenaLoadout* PrimaryAthenaLoadout, FFortAthenaLoadout* AthenaLoadout) = decltype(CopyAthenaLoadout)(0xC15030 + uintptr_t(GetModuleHandle(0)));
				CopyAthenaLoadout(&FortAIPlayerControllerAthena->CustomizationLoadout, AthenaLoadoutWithOverrides);
			}*/
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
				InitPlayerState();
				InitPlayerTeam();
				InitAlivePlayers();
				InitWorldInventory();
				InitQuickBars();

				ChooseRandomCosmetics();

				FortAIPlayerController->ServerChangeName(L"Odyssey BOT");

				GameModeAthena->HandleStartingNewPlayer(FortAIPlayerController);

				if (FortAIPlayerController->Pawn)
					SetAIPawn(FortAIPlayerController->Pawn);

				InitAbilities();
				InitStartInventory();
				
				ApplyCustomization();

				if (FortAIPlayerController->Pawn)
				{
					FortAIPlayerController->Pawn->SetNetDormancy(ENetDormancy::DORM_Awake);
					FortAIPlayerController->Pawn->FlushNetDormancy();
					FortAIPlayerController->Pawn->ForceNetUpdate();
				}

				SetBotAction(EAIBotAction::Warmup);
			}
		}
	}

	void TeleportBotPos(const FVector& Position) const
	{
		if (!AIPawn)
			return;

		AIPawn->K2_TeleportTo(Position, FRotator());
		AIPawn->SetReplicateMovement(true);
		AIPawn->OnRep_ReplicateMovement();
		AIPawn->SetReplicates(true);
		AIPawn->ForceNetUpdate();
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

	PlayerController->K2_DestroyActor();
	return nullptr;
}

static AAIBotOdyssey* FindBotOdyssey(APlayerController* PlayerController)
{
	AAIBotOdyssey* BotOdyssey = nullptr;

	for (auto& Find : AAIBotOdyssey::BotOdysseyMap)
	{
		if (Find.first == PlayerController)
		{
			BotOdyssey = Find.second;
			break;
		}
	}

	return BotOdyssey;
}

static AAIBotOdyssey* FindOrCreateBotOdyssey(APlayerController* PlayerController)
{
	AAIBotOdyssey* BotOdyssey = nullptr;

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

namespace BotOdyssey
{
	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			for (auto& Find : AAIBotOdyssey::BotOdysseyMap)
			{
				AAIBotOdyssey* BotOdyssey = Find.second;
				if (!BotOdyssey) continue;

				AFortPlayerControllerAthena* FortAIPlayerController = BotOdyssey->GetFortAIPlayerController();
				if (!FortAIPlayerController) continue;

				EAIBotAction BotAction = BotOdyssey->GetBotAction();

				switch (BotAction)
				{
				case EAIBotAction::None:
					break;
				case EAIBotAction::Warmup:
					break;
				case EAIBotAction::Aircraft:
					if (FortAIPlayerController->IsInAircraft())
					{

						FortAIPlayerController->ServerThankBusDriver();
					}
					break;
				case EAIBotAction::Skydive:
					break;
				case EAIBotAction::Looting:
					break;
				case EAIBotAction::Fighting:
					break;
				case EAIBotAction::Building:
					break;
				case EAIBotAction::Dancing:
					break;
				case EAIBotAction::EndGame:
					break;
				default:
					break;
				}
			}
		}
	}
}
#endif // BOTS