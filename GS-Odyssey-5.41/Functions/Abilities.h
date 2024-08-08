#pragma once

namespace Abilities
{
	FGameplayAbilitySpecHandle(*GiveAbilityAndActivateOnce)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* OutHandle, const FGameplayAbilitySpec& Spec);
	FGameplayAbilitySpecHandle(*GiveAbility)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle* Handle, FGameplayAbilitySpec Spec);
	char (*InternalTryActivateAbility)(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle, FPredictionKey InPredictionKey, UGameplayAbility** OutInstancedAbility, void* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData);
	UObject* (*CreateDefaultObject)(UClass* Class);
	FGameplayAbilitySpec* (*CreateDefaultAbilitySpec)(FGameplayAbilitySpec* AbilitySpec, UGameplayAbility* Ability, int32 Level, int32 InputID, UObject* SourceObject);
	FGameplayAbilitySpec* (*CopyAbilitySpec)(FGameplayAbilitySpec* PrimaryAbilitySpec, FGameplayAbilitySpec* AbilitySpec);

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

	void ApplyGameplayAbility(UClass* AbilityClass, AFortPawn* Pawn)
	{
		if (!AbilityClass || !Pawn)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = Pawn->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			FGameplayAbilitySpec AbilitySpec;
			CreateDefaultAbilitySpec(&AbilitySpec, (UGameplayAbility*)CreateDefaultObject(AbilityClass), 1, -1, nullptr);

			for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
			{
				auto& CurrentSpec = AbilitySystemComponent->ActivatableAbilities.Items[i];

				if (CurrentSpec.Ability == AbilitySpec.Ability)
					return;
			}

			FGameplayAbilitySpecHandle Handle;
			GiveAbility(AbilitySystemComponent, &Handle, AbilitySpec);
		}
	}

	void GrantGameplayAbility(UFortAbilitySet* AbilitySet, AFortPawn* Pawn)
	{
		if (!AbilitySet || !Pawn)
			return;

		for (int32 i = 0; i < AbilitySet->GameplayAbilities.Num(); i++)
		{
			TSubclassOf<UFortGameplayAbility> GameplayAbility = AbilitySet->GameplayAbilities[i];

			if (!GameplayAbility.Get())
				continue;

			ApplyGameplayAbility(GameplayAbility, Pawn);
		}
	}

	void GrantGameplayEffect(UFortAbilitySet* AbilitySet, AFortPawn* Pawn)
	{
		if (!AbilitySet || !Pawn || !Pawn->AbilitySystemComponent)
			return;

		UFortAbilitySystemComponent* AbilitySystemComponent = Pawn->AbilitySystemComponent;

		if (AbilitySystemComponent)
		{
			for (int32 i = 0; i < AbilitySet->GrantedGameplayEffects.Num(); i++)
			{
				FGameplayEffectApplicationInfoHard GrantedGameplayEffect = AbilitySet->GrantedGameplayEffects[i];

				if (!GrantedGameplayEffect.GameplayEffect.Get())
					continue;

				FGameplayEffectContextHandle EffectContext{};
				Pawn->AbilitySystemComponent->BP_ApplyGameplayEffectToSelf(GrantedGameplayEffect.GameplayEffect, GrantedGameplayEffect.Level, EffectContext);
			}
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
		static auto FortAbilitySystemComponentAthenaDefault = UFortAbilitySystemComponentAthena::GetDefaultObj();

		uintptr_t AddressGiveAbility = MinHook::FindPattern(Patterns::GiveAbility);
		uintptr_t AddressInternalTryActivateAbility = MinHook::FindPattern(Patterns::InternalTryActivateAbility);
		uintptr_t AddressCreateDefaultObject = MinHook::FindPattern(Patterns::CreateDefaultObject);
		uintptr_t AddressGiveAbilityAndActivateOnce = MinHook::FindPattern(Patterns::GiveAbilityAndActivateOnce);
		uintptr_t AddressCreateDefaultAbilitySpec = MinHook::FindPattern(Patterns::CreateDefaultAbilitySpec);
		uintptr_t AddressCopyAbilitySpec = MinHook::FindPattern(Patterns::CopyAbilitySpec);

		GiveAbility = decltype(GiveAbility)(AddressGiveAbility);
		InternalTryActivateAbility = decltype(InternalTryActivateAbility)(AddressInternalTryActivateAbility);
		CreateDefaultObject = decltype(CreateDefaultObject)(AddressCreateDefaultObject);
		GiveAbilityAndActivateOnce = decltype(GiveAbilityAndActivateOnce)(AddressGiveAbilityAndActivateOnce);
		CreateDefaultAbilitySpec = decltype(CreateDefaultAbilitySpec)(AddressCreateDefaultAbilitySpec);
		CopyAbilitySpec = decltype(CopyAbilitySpec)(AddressCopyAbilitySpec);

		MinHook::HookVTable(FortAbilitySystemComponentAthenaDefault, 0xF3, InternalServerTryActiveAbilityHook, nullptr, "InternalServerTryActiveAbility");

		FN_LOG(LogInit, Log, "InitAbilities Success!");
	}
}