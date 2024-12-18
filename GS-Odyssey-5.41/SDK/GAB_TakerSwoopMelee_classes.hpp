#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_TakerSwoopMelee

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AIModule_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_TakerSwoopMelee.GAB_TakerSwoopMelee_C
// 0x0090 (0x0988 - 0x08F8)
class UGAB_TakerSwoopMelee_C final : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08F8(0x0008)(Transient, DuplicateTransient)
	bool                                          Debug;                                             // 0x0900(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3CA8[0x7];                                     // 0x0901(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATakerPawn_C*                           Taker;                                             // 0x0908(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RotationRateWhenSwooping;                          // 0x0910(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3CA9[0x4];                                     // 0x0914(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTag                           TC_NPCAbilityAttackMeleeSwoop;                     // 0x0918(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           SwoopTransitionMontage;                            // 0x0920(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           SwoopAttackEndMontage;                             // 0x0928(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SwoopTimeout;                                      // 0x0930(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SwoopMoveAcceptRadius;                             // 0x0934(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class AActor*>                         ActorsHitThisTargetSelection;                      // 0x0938(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	bool                                          AbilityEnded;                                      // 0x0948(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3CAA[0x7];                                     // 0x0949(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AActor*>                         ActorsHitThisSwoop;                                // 0x0950(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	TArray<class AActor*>                         ActorsHitThisTargetSelectionFiltered;              // 0x0960(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	bool                                          MovingSlowly;                                      // 0x0970(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3CAB[0x7];                                     // 0x0971(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortAbilityTask_MoveAI*                SwoopMove;                                         // 0x0978(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MeleeInProgress;                                   // 0x0980(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3CAC[0x3];                                     // 0x0981(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         DebugSwoopAttackTime;                              // 0x0984(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GAB_TakerSwoopMelee(int32 EntryPoint);
	void SlowSpeedCancel();
	void K2_OnEndAbility(bool bWasCancelled);
	void SwoopTimeoutComplete();
	void BeginOutroDeceleration();
	void Taker_Overlapped_An_Actor(class AActor* OverlappedActor, class AActor* OtherActor);
	void K2_ActivateAbility();
	void OnCompleted_A05A301D40A4F2A62FAD9A94D3EB7A15();
	void OnBlendOut_A05A301D40A4F2A62FAD9A94D3EB7A15();
	void OnInterrupted_A05A301D40A4F2A62FAD9A94D3EB7A15();
	void OnCancelled_A05A301D40A4F2A62FAD9A94D3EB7A15();
	void Targeted_DE47BE5C495BECAF17E854B5C7774E8D(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Cancelled_DE47BE5C495BECAF17E854B5C7774E8D(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Triggered_90CCC07C4CF88E3BB6C7268A426DBA5F(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Cancelled_90CCC07C4CF88E3BB6C7268A426DBA5F(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Completed_90CCC07C4CF88E3BB6C7268A426DBA5F(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void OnComplete_A8D9EDC44514CE30149C4C924AB5FB2A();
	void OnInterrupted_A8D9EDC44514CE30149C4C924AB5FB2A();
	void OnCancelled_A8D9EDC44514CE30149C4C924AB5FB2A();
	void OnRequestFailed_A8D9EDC44514CE30149C4C924AB5FB2A();
	void OnMoveFinished_A8D9EDC44514CE30149C4C924AB5FB2A(EPathFollowingResult Result, class AAIController* AIController);

	bool K2_CanActivateAbility(const struct FGameplayAbilityActorInfo& ActorInfo, struct FGameplayTagContainer* RelevantTags) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_TakerSwoopMelee_C">();
	}
	static class UGAB_TakerSwoopMelee_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_TakerSwoopMelee_C>();
	}
};

}

