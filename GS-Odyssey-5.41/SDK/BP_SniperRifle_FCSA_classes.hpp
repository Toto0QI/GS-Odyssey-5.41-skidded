#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SniperRifle_FCSA

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass BP_SniperRifle_FCSA.BP_SniperRifle_FCSA_C
// 0x00F0 (0x0448 - 0x0358)
class UBP_SniperRifle_FCSA_C final : public UAnimInstance
{
public:
	uint8                                         Pad_610E[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_146699F448DB1AAB26EC9F814C49D1D1; // 0x0368(0x0040)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_F7DD3CBC4CA03D5C78826D9E409ECCA2; // 0x03A8(0x0068)()
	struct FAnimNode_RefPose                      AnimGraphNode_LocalRefPose_7C8D051E4A0B249DA61DCAA86177450B; // 0x0410(0x0038)()

public:
	void ExecuteUbergraph_BP_SniperRifle_FCSA(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_SniperRifle_FCSA_C">();
	}
	static class UBP_SniperRifle_FCSA_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_SniperRifle_FCSA_C>();
	}
};

}
