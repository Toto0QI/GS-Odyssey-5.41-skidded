#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Trap_FloorJumpPadDirectional

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_TrapGeneric_classes.hpp"
#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Trap_FloorJumpPadDirectional.GA_Trap_FloorJumpPadDirectional_C
// 0x0068 (0x0990 - 0x0928)
class UGA_Trap_FloorJumpPadDirectional_C final : public UGA_TrapGeneric_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Trap_FloorJumpPadDirectional_C;  // 0x0928(0x0008)(Transient, DuplicateTransient)
	float                                         LaunchPitch;                                       // 0x0930(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LaunchStrength;                                    // 0x0934(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UForceFeedbackEffect*                   LaunchForceFeedback;                               // 0x0938(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerPawn*                        LaunchedPlayer;                                    // 0x0940(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           TC_LaunchTag;                                      // 0x0948(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 GE_PlayerLaunched;                                 // 0x0950(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class AActor*>                         OverlappingTargets;                                // 0x0958(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	class UClass*                                 GE_TrapImmunity;                                   // 0x0968(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayAbilityTargetDataHandle       TargetData;                                        // 0x0970(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_GA_Trap_FloorJumpPadDirectional(int32 EntryPoint);
	void Cancelled_9399FB2A485BD9AC6632A4B347C4BBE0(const struct FGameplayAbilityTargetDataHandle& Param_TargetData, const struct FGameplayTag& ApplicationTag);
	void K2_ActivateAbility();
	void PlayPlayerFX(class AFortPlayerPawn* Player, const struct FRotator& LaunchRotation, const struct FTransform& TrapTransform);
	void Targeted_9399FB2A485BD9AC6632A4B347C4BBE0(const struct FGameplayAbilityTargetDataHandle& Param_TargetData, const struct FGameplayTag& ApplicationTag);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Trap_FloorJumpPadDirectional_C">();
	}
	static class UGA_Trap_FloorJumpPadDirectional_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Trap_FloorJumpPadDirectional_C>();
	}
};

}
