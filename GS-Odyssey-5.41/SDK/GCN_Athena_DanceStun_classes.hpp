#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCN_Athena_DanceStun

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GCN_Athena_DanceStun.GCN_Athena_DanceStun_C
// 0x0050 (0x0470 - 0x0420)
class AGCN_Athena_DanceStun_C final : public AFortGameplayCueNotify_Looping
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0420(0x0008)(Transient, DuplicateTransient)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0428(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        AnimPivot;                                         // 0x0430(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         OutroAnim_Scale_1822DA5D44681175D96B369D2350B5A1;  // 0x0438(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            OutroAnim__Direction_1822DA5D44681175D96B369D2350B5A1; // 0x043C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4243[0x3];                                     // 0x043D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     OutroAnim;                                         // 0x0440(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         IntroAnim_BallScale_B22BD0D945C252484DAB94BD6D5DC469; // 0x0448(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            IntroAnim__Direction_B22BD0D945C252484DAB94BD6D5DC469; // 0x044C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4244[0x3];                                     // 0x044D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     IntroAnim;                                         // 0x0450(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPlayerPawnAthena*                  PlayerPawn;                                        // 0x0458(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                BallOffset;                                        // 0x0460(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GCN_Athena_DanceStun(int32 EntryPoint);
	void AnimateOut();
	void AnimateIn();
	void ReceiveTick(float DeltaSeconds);
	void OutroAnim__UpdateFunc();
	void OutroAnim__FinishedFunc();
	void IntroAnim__UpdateFunc();
	void IntroAnim__FinishedFunc();
	void UserConstructionScript();
	bool OnActive(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	bool OnRemove(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GCN_Athena_DanceStun_C">();
	}
	static class AGCN_Athena_DanceStun_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGCN_Athena_DanceStun_C>();
	}
};

}

