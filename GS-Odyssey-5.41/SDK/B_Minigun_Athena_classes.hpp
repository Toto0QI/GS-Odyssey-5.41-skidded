#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Minigun_Athena

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "B_Ranged_Generic_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Minigun_Athena.B_Minigun_Athena_C
// 0x0070 (0x0FE0 - 0x0F70)
class AB_Minigun_Athena_C final : public AB_Ranged_Generic_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_B_Minigun_Athena_C;                 // 0x0F70(0x0008)(Transient, DuplicateTransient)
	class UStaticMeshComponent*                   BarrelGlowFX;                                      // 0x0F78(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        SpinUpSound;                                       // 0x0F80(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        SpinDownSound;                                     // 0x0F88(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_MinigunChargeUp;                                 // 0x0F90(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         SpinAudioVolumeTimeline_Volume_18EF57D9444836E65E22B6A5DFE3BF4A; // 0x0F98(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            SpinAudioVolumeTimeline__Direction_18EF57D9444836E65E22B6A5DFE3BF4A; // 0x0F9C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_61F9[0x3];                                     // 0x0F9D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     SpinAudioVolumeTimeline;                           // 0x0FA0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BarrelGlow_MuzzleGlowOpacity_6AA244864FFB6D03BB4DAA82CADCA13E; // 0x0FA8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            BarrelGlow__Direction_6AA244864FFB6D03BB4DAA82CADCA13E; // 0x0FAC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_61FA[0x3];                                     // 0x0FAD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     BarrelGlow;                                        // 0x0FB0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               MuzzleGlowMID;                                     // 0x0FB8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHasPlayedSpinUpSound;                             // 0x0FC0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_61FB[0x3];                                     // 0x0FC1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         SpinUpAudioVolumeMultiplier;                       // 0x0FC4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        CurrentSpinAudioComponent;                         // 0x0FC8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CurrentAmmo;                                       // 0x0FD0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bPlayedSpinUpAudio;                                // 0x0FD4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bPlayedSpinDownAudio;                              // 0x0FD5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_61FC[0x2];                                     // 0x0FD6(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         SpinVolumeMultiplier;                              // 0x0FD8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_Minigun_Athena(int32 EntryPoint);
	void OnWeaponAttached();
	void Start_Spin_Down_Audio();
	void Start_Spin_Up_Audio();
	void OnAmmoCountChanged();
	void StopBarrelGlow();
	void MakeBarrelGlow();
	void OnInitCosmeticAlterations(const struct FFortCosmeticModification& CosmeticMod, class UMaterialInstanceDynamic* DynamicMaterialInstance);
	void OnChargeDown();
	void OnChargeUp();
	void OnPlayWeaponFireFX(bool bPersistentFire, bool bSecondaryFire);
	void SpinAudioVolumeTimeline__UpdateFunc();
	void SpinAudioVolumeTimeline__FinishedFunc();
	void BarrelGlow__UpdateFunc();
	void BarrelGlow__FinishedFunc();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Minigun_Athena_C">();
	}
	static class AB_Minigun_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Minigun_Athena_C>();
	}
};

}
