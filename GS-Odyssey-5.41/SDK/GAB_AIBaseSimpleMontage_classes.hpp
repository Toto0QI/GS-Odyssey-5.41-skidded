#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_AIBaseSimpleMontage

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_AIBaseSimpleMontage.GAB_AIBaseSimpleMontage_C
// 0x0008 (0x0900 - 0x08F8)
class UGAB_AIBaseSimpleMontage_C : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08F8(0x0008)(Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_GAB_AIBaseSimpleMontage(int32 EntryPoint);
	void Cancelled_19E6A1264ED43B37D77327A113073715(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Completed_19E6A1264ED43B37D77327A113073715(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void K2_ActivateAbility();
	void Triggered_19E6A1264ED43B37D77327A113073715(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_AIBaseSimpleMontage_C">();
	}
	static class UGAB_AIBaseSimpleMontage_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_AIBaseSimpleMontage_C>();
	}
};

}
