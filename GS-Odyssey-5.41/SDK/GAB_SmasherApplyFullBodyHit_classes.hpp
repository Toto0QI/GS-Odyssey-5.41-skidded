#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_SmasherApplyFullBodyHit

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GAB_GenericApplyFullBodyHit_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_SmasherApplyFullBodyHit.GAB_SmasherApplyFullBodyHit_C
// 0x0018 (0x0968 - 0x0950)
class UGAB_SmasherApplyFullBodyHit_C final : public UGAB_GenericApplyFullBodyHit_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GAB_SmasherApplyFullBodyHit_C;      // 0x0950(0x0008)(Transient, DuplicateTransient)
	class FName                                   Front;                                             // 0x0958(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CurrentNum;                                        // 0x0960(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         PreviousNum;                                       // 0x0964(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GAB_SmasherApplyFullBodyHit(int32 EntryPoint);
	void PickFullBodyHitMontageSection();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_SmasherApplyFullBodyHit_C">();
	}
	static class UGAB_SmasherApplyFullBodyHit_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_SmasherApplyFullBodyHit_C>();
	}
};

}
