#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Task_SetBlackboardBoolValues

#include "Basic.hpp"

#include "AIModule_structs.hpp"
#include "AIModule_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Task_SetBlackboardBoolValues.Task_SetBlackboardBoolValues_C
// 0x0100 (0x01A0 - 0x00A0)
class UTask_SetBlackboardBoolValues_C final : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00A0(0x0008)(Transient, DuplicateTransient)
	bool                                          Update_1_;                                         // 0x00A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35E2[0x7];                                     // 0x00A9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 BoolKey1;                                          // 0x00B0(0x0028)(Edit, BlueprintVisible)
	bool                                          BoolKey1Value;                                     // 0x00D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Update_2_;                                         // 0x00D9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35E3[0x6];                                     // 0x00DA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 BoolKey2;                                          // 0x00E0(0x0028)(Edit, BlueprintVisible)
	bool                                          BoolKey2Value;                                     // 0x0108(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Update_3_;                                         // 0x0109(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35E4[0x6];                                     // 0x010A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 BoolKey3;                                          // 0x0110(0x0028)(Edit, BlueprintVisible)
	bool                                          BoolKey3Value;                                     // 0x0138(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Update_4_;                                         // 0x0139(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35E5[0x6];                                     // 0x013A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 BoolKey4;                                          // 0x0140(0x0028)(Edit, BlueprintVisible)
	bool                                          BoolKey4Value;                                     // 0x0168(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Update_5_;                                         // 0x0169(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35E6[0x6];                                     // 0x016A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 BoolKey5;                                          // 0x0170(0x0028)(Edit, BlueprintVisible)
	bool                                          BoolKey5Value;                                     // 0x0198(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_Task_SetBlackboardBoolValues(int32 EntryPoint);
	void ReceiveExecute(class AActor* OwnerActor);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Task_SetBlackboardBoolValues_C">();
	}
	static class UTask_SetBlackboardBoolValues_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTask_SetBlackboardBoolValues_C>();
	}
};

}
