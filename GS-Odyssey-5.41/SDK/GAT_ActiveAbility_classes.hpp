#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAT_ActiveAbility

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAT_ActiveAbility.GAT_ActiveAbility_C
// 0x0028 (0x0920 - 0x08F8)
class UGAT_ActiveAbility_C : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08F8(0x0008)(Transient, DuplicateTransient)
	struct FGameplayTag                           TC_AbilitiesGenericActiveAbilityActivate;          // 0x0900(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class FName                                   N_SavedCollisionChannel;                           // 0x0908(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 GE_KnockBackImmunity;                              // 0x0910(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FActiveGameplayEffectHandle            GEH_KnockBackImmunity;                             // 0x0918(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GAT_ActiveAbility(int32 EntryPoint);
	void K2_ActivateAbility();
	void SetPawnCollision(class AFortPawn* FortPawn, bool CollisionOn);
	void SetKnockbackImmunity(bool ImmunityOn);
	void SetHolsterWeaponWithName(class AFortPawn* Target_Fort_Pawn, bool ShouldHolster, bool PlayEquipAnim, bool ShowDebugPrintName);

	void ActiveAbilitySetup(class UAbilitySystemComponent* AbilitySystemComponent) const;
	bool K2_ShouldAbilityRespondToEvent(const struct FGameplayAbilityActorInfo& ActorInfo, const struct FGameplayEventData& Payload) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAT_ActiveAbility_C">();
	}
	static class UGAT_ActiveAbility_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAT_ActiveAbility_C>();
	}
};

}

