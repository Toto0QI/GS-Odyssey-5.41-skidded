#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BoltActionSniperRifleNoScope

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass BP_BoltActionSniperRifleNoScope.BP_BoltActionSniperRifleNoScope_C
// 0x0158 (0x04B0 - 0x0358)
class UBP_BoltActionSniperRifleNoScope_C final : public UAnimInstance
{
public:
	uint8                                         Pad_4BEB[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_80F88762449D5790C18126A73190A30A; // 0x0368(0x0040)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_3F9AE2D64A1081980E00CE94E79DD708; // 0x03A8(0x0068)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_F813E2B842B7262277782F9EC5A3917A; // 0x0410(0x00A0)()

public:
	void ExecuteUbergraph_BP_BoltActionSniperRifleNoScope(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_BoltActionSniperRifleNoScope_C">();
	}
	static class UBP_BoltActionSniperRifleNoScope_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_BoltActionSniperRifleNoScope_C>();
	}
};

}
