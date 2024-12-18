#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AbilityDecoTool_Athena_MissileBattery_Homing

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AbilityDecoTool_Athena_MissileBattery_Homing.AbilityDecoTool_Athena_MissileBattery_Homing_C
// 0x0040 (0x0BF0 - 0x0BB0)
class AAbilityDecoTool_Athena_MissileBattery_Homing_C final : public AFortCustomizableAbilityDecoTool
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0BB0(0x0008)(Transient, DuplicateTransient)
	class UClass*                                 NewVar_0;                                          // 0x0BB8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortDecoHelper*                        Helper;                                            // 0x0BC0(0x0008)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           HideTimerHandle;                                   // 0x0BC8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class AFortPawn*                              FortPawn;                                          // 0x0BD0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AB_PlacementPreview_MissleBattery_Homing_C* PPMissileBatteryHoming;                            // 0x0BD8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                AimLocation;                                       // 0x0BE0(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AbilityDecoTool_Athena_MissileBattery_Homing(int32 EntryPoint);
	void ReceiveBeginPlay();
	void Show();
	void BPOnSetDecoObjectPreview(class AFortDecoHelper* FortDecoHelper);
	void HideFor(float InTime);
	void UserConstructionScript();
	void HideMeshAndPlacement(bool bInHide);
	void GetAimLocFromDeco(struct FVector* Param_AimLocation);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AbilityDecoTool_Athena_MissileBattery_Homing_C">();
	}
	static class AAbilityDecoTool_Athena_MissileBattery_Homing_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AAbilityDecoTool_Athena_MissileBattery_Homing_C>();
	}
};

}

