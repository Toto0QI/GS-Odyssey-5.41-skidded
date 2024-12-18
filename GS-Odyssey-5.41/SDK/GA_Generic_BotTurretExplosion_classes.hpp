#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Generic_BotTurretExplosion

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Generic_BotTurretExplosion.GA_Generic_BotTurretExplosion_C
// 0x0010 (0x0908 - 0x08F8)
class UGA_Generic_BotTurretExplosion_C final : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08F8(0x0008)(Transient, DuplicateTransient)
	struct FGameplayTag                           EC_Explosion;                                      // 0x0900(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Generic_BotTurretExplosion(int32 EntryPoint);
	void Cancelled_0AE6B0594940799A0AB506A647527DAE(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void K2_ActivateAbilityFromEvent(const struct FGameplayEventData& EventData);
	void Targeted_0AE6B0594940799A0AB506A647527DAE(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Generic_BotTurretExplosion_C">();
	}
	static class UGA_Generic_BotTurretExplosion_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Generic_BotTurretExplosion_C>();
	}
};

}

