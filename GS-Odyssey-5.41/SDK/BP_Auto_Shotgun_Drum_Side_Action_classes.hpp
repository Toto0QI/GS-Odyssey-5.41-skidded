#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Auto_Shotgun_Drum_Side_Action

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass BP_Auto_Shotgun_Drum_Side_Action.BP_Auto_Shotgun_Drum_Side_Action_C
// 0x00F0 (0x0448 - 0x0358)
class UBP_Auto_Shotgun_Drum_Side_Action_C final : public UAnimInstance
{
public:
	uint8                                         Pad_3343[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_7EA7D37645F443897F10498323E528F7; // 0x0368(0x0040)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_64A40914450FCFA8B6BB00AA8DAB6F04; // 0x03A8(0x0068)()
	struct FAnimNode_RefPose                      AnimGraphNode_LocalRefPose_9AFCD47E4FA0ED23378DEABB5751407C; // 0x0410(0x0038)()

public:
	void ExecuteUbergraph_BP_Auto_Shotgun_Drum_Side_Action(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Auto_Shotgun_Drum_Side_Action_C">();
	}
	static class UBP_Auto_Shotgun_Drum_Side_Action_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_Auto_Shotgun_Drum_Side_Action_C>();
	}
};

}

