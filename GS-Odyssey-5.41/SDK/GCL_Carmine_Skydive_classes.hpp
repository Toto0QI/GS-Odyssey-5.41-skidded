#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCL_Carmine_Skydive

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass GCL_Carmine_Skydive.GCL_Carmine_Skydive_C
// 0x0010 (0x0430 - 0x0420)
class AGCL_Carmine_Skydive_C final : public AFortGameplayCueNotify_Looping
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0420(0x0008)(Transient, DuplicateTransient)
	class AFortPawn*                              Player;                                            // 0x0428(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GCL_Carmine_Skydive(int32 EntryPoint);
	void K2_HandleGameplayCue(class AActor* MyTarget, EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void ReceiveBeginPlay();
	void UserConstructionScript();

	void OnWhileActiveParticleSystemActivate(class UParticleSystemComponent* WhileActiveParticleSysComponent, const struct FGameplayCueParameters& Parameters) const;
	void OnWhileActiveParticleSystemDeactivate(class UParticleSystemComponent* WhileActiveParticleSysComponent, const struct FGameplayCueParameters& Parameters) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GCL_Carmine_Skydive_C">();
	}
	static class AGCL_Carmine_Skydive_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGCL_Carmine_Skydive_C>();
	}
};

}
