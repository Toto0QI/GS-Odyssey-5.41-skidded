#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Balloons_Rope_AnimBP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass Balloons_Rope_AnimBP.Balloons_Rope_AnimBP_C
// 0x0158 (0x04B0 - 0x0358)
class UBalloons_Rope_AnimBP_C final : public UAnimInstance
{
public:
	uint8                                         Pad_60AF[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_AE1B6F214BD7D654DA01BCBD0E7A0859; // 0x0368(0x0040)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_FF3F5BEB44F536DA6931F79BCDC105EF; // 0x03A8(0x0068)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_8B9A49D14E95A0CE4382AE90073E47B1; // 0x0410(0x00A0)()

public:
	void ExecuteUbergraph_Balloons_Rope_AnimBP(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Balloons_Rope_AnimBP_C">();
	}
	static class UBalloons_Rope_AnimBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBalloons_Rope_AnimBP_C>();
	}
};

}

