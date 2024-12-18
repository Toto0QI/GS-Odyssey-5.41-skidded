#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_SmasherChargeDecelerate

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "GAB_AIBaseSimpleMontage_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GAB_SmasherChargeDecelerate.GAB_SmasherChargeDecelerate_C
// 0x0010 (0x0910 - 0x0900)
class UGAB_SmasherChargeDecelerate_C final : public UGAB_AIBaseSimpleMontage_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GAB_SmasherChargeDecelerate_C;      // 0x0900(0x0008)(Transient, DuplicateTransient)
	struct FGameplayTag                           GC_GameplayCueNPCSmasherCharge;                    // 0x0908(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GAB_SmasherChargeDecelerate(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GAB_SmasherChargeDecelerate_C">();
	}
	static class UGAB_SmasherChargeDecelerate_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGAB_SmasherChargeDecelerate_C>();
	}
};

}

