#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_AssaultRifle_FrontClip_BackAction

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass BP_AssaultRifle_FrontClip_BackAction.BP_AssaultRifle_FrontClip_BackAction_C
// 0x00F0 (0x0448 - 0x0358)
class UBP_AssaultRifle_FrontClip_BackAction_C final : public UAnimInstance
{
public:
	uint8                                         Pad_60D6[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_093BD79B4AD87188F29729836AA06276; // 0x0368(0x0040)()
	struct FAnimNode_RefPose                      AnimGraphNode_LocalRefPose_A31555D842D75C0905B639846DA94151; // 0x03A8(0x0038)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_6E68D2AF43B0D536C012ED82940BED48; // 0x03E0(0x0068)()

public:
	void ExecuteUbergraph_BP_AssaultRifle_FrontClip_BackAction(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_AssaultRifle_FrontClip_BackAction_C">();
	}
	static class UBP_AssaultRifle_FrontClip_BackAction_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_AssaultRifle_FrontClip_BackAction_C>();
	}
};

}

