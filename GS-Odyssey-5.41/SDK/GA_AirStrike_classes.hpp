#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_AirStrike

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "GAT_GenericActiveAbilityNoCommit_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_AirStrike.GA_AirStrike_C
// 0x01A0 (0x0B80 - 0x09E0)
class UGA_AirStrike_C final : public UGAT_GenericActiveAbilityNoCommit_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_AirStrike_C;                     // 0x09E0(0x0008)(Transient, DuplicateTransient)
	struct FGameplayTag                           EventComplete;                                     // 0x09E8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           EventActivation;                                   // 0x09F0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class AFortAbilityDecoTool*                   DecoTool;                                          // 0x09F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 Prj_Bomb;                                          // 0x0A00(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               Prj_SpawnDirection;                                // 0x0A08(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	float                                         Prj_Gravity;                                       // 0x0A14(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DelayBetweenBombs;                                 // 0x0A18(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HeightToSpawnBombs;                                // 0x0A1C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ExplosionRadius;                                   // 0x0A20(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_363C[0xC];                                     // 0x0A24(0x000C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             BombInitTransform;                                 // 0x0A30(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	int32                                         AbilityMultiplier;                                 // 0x0A60(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_363D[0x4];                                     // 0x0A64(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTag                           EC_Explode;                                        // 0x0A68(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FFortGameplayEffectContainerSpec       EC_ExplodeReturn;                                  // 0x0A70(0x0080)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FVector>                        CurrentUnprocessedPositionsArray;                  // 0x0AF0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	int32                                         ForLoopCounter;                                    // 0x0B00(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Debug;                                             // 0x0B04(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_363E[0x3];                                     // 0x0B05(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  TC_BombCountUpgrade_01;                            // 0x0B08(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_BombCountUpgrade_02;                            // 0x0B28(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_BombCountUpgrade_03;                            // 0x0B48(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	int32                                         BaseBombCount;                                     // 0x0B68(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_363F[0x4];                                     // 0x0B6C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimMontage*                           ActivateMontage;                                   // 0x0B70(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_AirStrike(int32 EntryPoint);
	void Success_6C69A64746D8F71A616C83A25170911C(class AActor* SpawnedActor);
	void DidNotSpawn_6C69A64746D8F71A616C83A25170911C(class AActor* SpawnedActor);
	void Triggered_48B4C8FD48399FA7A5F50D96227846DD(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Cancelled_48B4C8FD48399FA7A5F50D96227846DD(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void Completed_48B4C8FD48399FA7A5F50D96227846DD(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag);
	void GetAttributeValue();
	void SetupAbility(class UAbilitySystemComponent* AbilitySystemComponent);
	void K2_ActivateAbility();

	struct FTransform GetCustomAbilitySourceTransform() const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_AirStrike_C">();
	}
	static class UGA_AirStrike_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_AirStrike_C>();
	}
};

}

