#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Soldier_Minigun

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass BP_Soldier_Minigun.BP_Soldier_Minigun_C
// 0x03A8 (0x0700 - 0x0358)
class UBP_Soldier_Minigun_C final : public UAnimInstance
{
public:
	uint8                                         Pad_489A[0x8];                                     // 0x0358(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0360(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_5BEDD1AF46E640F37CCC9FAA8DF7F6DC; // 0x0368(0x0040)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot_15839C374918416DF8289BAE7466DE11; // 0x03A8(0x0068)()
	struct FAnimNode_ModifyBone                   AnimGraphNode_ModifyBone_CDE861E049ED25F9468E1596307CE0F7; // 0x0410(0x0138)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace_2E6915294401BD03648F4689C8817592; // 0x0548(0x0040)()
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace_580B6AC241C93B1B43A2A4ACEF5528AD; // 0x0588(0x0040)()
	struct FAnimNode_SequenceEvaluator            AnimGraphNode_SequenceEvaluator_43BD42EB42C5FE9A4147628D6467C8A7; // 0x05C8(0x0070)()
	struct FAnimNode_RotateRootBone               AnimGraphNode_RotateRootBone_23F81C024704537420FC1492A49C0F7B; // 0x0638(0x00C0)()
	float                                         MinigunRotation;                                   // 0x06F8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxMinigunRotSpeed;                                // 0x06FC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_BP_Soldier_Minigun(int32 EntryPoint);
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void EvaluateGraphExposedInputs_ExecuteUbergraph_BP_Soldier_Minigun_AnimGraphNode_ModifyBone_CDE861E049ED25F9468E1596307CE0F7();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Soldier_Minigun_C">();
	}
	static class UBP_Soldier_Minigun_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBP_Soldier_Minigun_C>();
	}
};

}
