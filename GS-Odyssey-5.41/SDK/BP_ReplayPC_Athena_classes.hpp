#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ReplayPC_Athena

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ReplayPC_Athena.BP_ReplayPC_Athena_C
// 0x00A8 (0x20B8 - 0x2010)
class ABP_ReplayPC_Athena_C final : public AFortReplaySpectatorAthena
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x2010(0x0008)(Transient, DuplicateTransient)
	TMap<float, class USoundMix*>                 PlaybackRateMap;                                   // 0x2018(0x0050)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	float                                         CurrentPlayRate;                                   // 0x2068(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsFast;                                           // 0x206C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3E4C[0x3];                                     // 0x206D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UAudioComponent*                        SpeedupLoop;                                       // 0x2070(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        SlowdownLoop;                                      // 0x2078(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsHudVisible;                                     // 0x2080(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3E4D[0x7];                                     // 0x2081(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAudioComponent*                        ZoomOutLoop;                                       // 0x2088(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        ZoomInLoop;                                        // 0x2090(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsSkydivingAudioEnabled;                          // 0x2098(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bIsTargetParachuting;                              // 0x2099(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bIsTargetSkydiving;                                // 0x209A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3E4E[0x5];                                     // 0x209B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UAudioComponent*                        SkydivingAudioLoop;                                // 0x20A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsPaused;                                         // 0x20A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3E4F[0x7];                                     // 0x20A9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             CurrentSkydivingSound;                             // 0x20B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_BP_ReplayPC_Athena(int32 EntryPoint);
	void Looping_Audio_Update();
	void Handle_Parachute_Audio_State();
	void On_Pause_State_Changed(bool bPaused);
	void OnZoomInBegin();
	void OnZoomInEnd();
	void OnZoomOutBegin();
	void OnZoomOutEnd();
	void OnReplayHudVisibilityChanged(const EHudVisibilityState IsVisible);
	void _Speedup_Loops(float Playback_Multiplier);
	void OnNotifyNewPlaybackMultiplier(float NewMultiplier);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	class USoundBase* GetSkydivingSound();
	void SetSkydivingAudioEnabled(bool Enabled);
	void IsGameplayCamera(bool* Param_IsGameplayCamera);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ReplayPC_Athena_C">();
	}
	static class ABP_ReplayPC_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ReplayPC_Athena_C>();
	}
};

}
