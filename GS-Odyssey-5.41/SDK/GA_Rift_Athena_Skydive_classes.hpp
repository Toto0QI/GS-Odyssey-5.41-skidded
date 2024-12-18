#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Rift_Athena_Skydive

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Rift_Athena_Skydive.GA_Rift_Athena_Skydive_C
// 0x00A0 (0x0998 - 0x08F8)
class UGA_Rift_Athena_Skydive_C final : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08F8(0x0008)(Transient, DuplicateTransient)
	class UAnimMontage*                           FallingAnimation;                                  // 0x0900(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Hangtimee;                                         // 0x0908(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3EFF[0x4];                                     // 0x090C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USkeletalMeshComponent*                 VehicleSkelMesh;                                   // 0x0910(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FScalableFloat                         Hangtime;                                          // 0x0918(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                           EventTag;                                          // 0x0940(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FScalableFloat                         KickFromVehicle_;                                  // 0x0948(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	class USoundBase*                             LocalPlayerSound;                                  // 0x0970(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 GameplayCueGE;                                     // 0x0978(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerPawn*                        PlayerPawn;                                        // 0x0980(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHolstered;                                        // 0x0988(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3F00[0x7];                                     // 0x0989(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   RiftSkydiveHolster;                                // 0x0990(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Rift_Athena_Skydive(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void SetPlayerToSkydive();
	void K2_ActivateAbility();
	void OnChange_16E0EB444DDAC48E8E9CC99B762C0DC5(EMovementMode NewMovementMode);
	void OnBlendOut_AA0523504B7CA4F488E1E6A11F48308A();
	void OnCancelled_AA0523504B7CA4F488E1E6A11F48308A();
	void OnCompleted_AA0523504B7CA4F488E1E6A11F48308A();
	void OnInterrupted_AA0523504B7CA4F488E1E6A11F48308A();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Rift_Athena_Skydive_C">();
	}
	static class UGA_Rift_Athena_Skydive_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Rift_Athena_Skydive_C>();
	}
};

}

