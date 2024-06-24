#pragma once

namespace Abilities
{
	FGameplayAbilitySpecHandle(*GiveAbilityAndActivateOnce)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* OutHandle, const FGameplayAbilitySpec& Spec);
	FGameplayAbilitySpecHandle(*GiveAbility)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* Handle, FGameplayAbilitySpec Spec);
	char (*InternalTryActivateAbility)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle, FPredictionKey InPredictionKey, UGameplayAbility** OutInstancedAbility, void* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData);
	UObject* (*CreateDefaultObject)(UClass* Class);

	FGameplayAbilitySpec* FindAbilitySpecFromHandle(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle& Ability)
	{
		FGameplayAbilitySpec* Spec = nullptr;

		for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
		{
			if (AbilitySystemComponent->ActivatableAbilities.Items[i].Handle.Handle == Ability.Handle)
			{
				return Spec = &AbilitySystemComponent->ActivatableAbilities.Items[i];
			}
		}

		return Spec;
	}

	void ApplyGameplayAbility(UClass* AbilityClass, AFortPlayerPawn* Pawn)
	{
		if (!AbilityClass || !Pawn)
			return;

		auto AbilitySystemComponent = Pawn->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			auto GenerateNewSpec = [&]() -> FGameplayAbilitySpec
				{
					FGameplayAbilitySpecHandle Handle{ rand() };

					FGameplayAbilitySpec Spec{ -1, -1, -1, Handle, (UGameplayAbility*)CreateDefaultObject(AbilityClass), 1, -1, nullptr, 0, false, false, false };

					return Spec;
				};

			auto Spec = GenerateNewSpec();

			for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
			{
				auto& CurrentSpec = AbilitySystemComponent->ActivatableAbilities.Items[i];

				if (CurrentSpec.Ability == Spec.Ability)
					return;
			}

			GiveAbility(AbilitySystemComponent, &Spec.Handle, Spec);
		}
	}

	void GrantGameplayAbility(UFortAbilitySet* GameplayAbilitySet, AFortPlayerPawn* Pawn)
	{
		if (!GameplayAbilitySet || !Pawn)
			return;

		for (int i = 0; i < GameplayAbilitySet->GameplayAbilities.Num(); i++)
		{
			auto AbilityClass = GameplayAbilitySet->GameplayAbilities[i];

			if (!AbilityClass)
				continue;

			ApplyGameplayAbility(AbilityClass, Pawn);
		}
	}

	void InternalServerTryActiveAbilityHook(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle, bool InputPressed, const FPredictionKey& PredictionKey, const FGameplayEventData* TriggerEventData)
	{
		FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(AbilitySystemComponent, Handle);

		if (!Spec)
		{
			AbilitySystemComponent->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
			return;
		}

		UGameplayAbility* InstancedAbility = nullptr;
		Spec->InputPressed = true;

		if (!InternalTryActivateAbility(AbilitySystemComponent, Handle, PredictionKey, &InstancedAbility, nullptr, TriggerEventData))
		{
			AbilitySystemComponent->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
			Spec->InputPressed = false;
		}

		AbilitySystemComponent->ActivatableAbilities.MarkItemDirty(*Spec);
	}

	void InitAbilities()
	{
		static auto FortAbilitySystemComponentAthenaDefault = FindObjectFast<UObject>("/Script/FortniteGame.Default__FortAbilitySystemComponentAthena");

		uintptr_t AddressGiveAbility = MinHook::FindPattern(Patterns::GiveAbility);
		uintptr_t AddressInternalTryActivateAbility = MinHook::FindPattern(Patterns::InternalTryActivateAbility);
		uintptr_t AddressCreateDefaultObject = MinHook::FindPattern(Patterns::CreateDefaultObject);
		uintptr_t AddressGiveAbilityAndActivateOnce = MinHook::FindPattern(Patterns::GiveAbilityAndActivateOnce);

		GiveAbility = decltype(GiveAbility)(AddressGiveAbility);
		InternalTryActivateAbility = decltype(InternalTryActivateAbility)(AddressInternalTryActivateAbility);
		CreateDefaultObject = decltype(CreateDefaultObject)(AddressCreateDefaultObject);
		GiveAbilityAndActivateOnce = decltype(GiveAbilityAndActivateOnce)(AddressGiveAbilityAndActivateOnce);

		MinHook::HookVTable(FortAbilitySystemComponentAthenaDefault, 0xF3, InternalServerTryActiveAbilityHook, nullptr, "InternalServerTryActiveAbility");

		FN_LOG(LogInit, Log, "InitAbilities Success!");
	}
}