#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaSpectatorHitPointBar

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C
// 0x00B8 (0x02F0 - 0x0238)
class UAthenaSpectatorHitPointBar_C final : public UAthenaSpectatorHitPointBarBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0238(0x0008)(Transient, DuplicateTransient)
	class USimpleMaterialProgressBar_C*           ProgressBarDelta;                                  // 0x0240(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USimpleMaterialProgressBar_C*           ProgressBarFill;                                   // 0x0248(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FLinearColor                           HealthFillColorA;                                  // 0x0250(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HealthFillColorB;                                  // 0x0260(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HealthDeltaColorA;                                 // 0x0270(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HealthDeltaColorB;                                 // 0x0280(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HealthBackgroundColor;                             // 0x0290(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           ShieldFillColorA;                                  // 0x02A0(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           ShieldFillColorB;                                  // 0x02B0(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           ShieldDeltaColorA;                                 // 0x02C0(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           ShieldDeltaColorB;                                 // 0x02D0(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           ShieldBackgroundColor;                             // 0x02E0(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AthenaSpectatorHitPointBar(int32 EntryPoint);
	void OnDeltaValueChanged(float InDeltaValue);
	void OnCurrentValueChanged(float InCurrentValue);
	void OnDBNOChanged(bool bInIsDBNO);
	void OnDBNOChanged_BP();
	void UpdateBars_BP();
	void PreConstruct(bool IsDesignTime);
	void InitializeBar();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaSpectatorHitPointBar_C">();
	}
	static class UAthenaSpectatorHitPointBar_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaSpectatorHitPointBar_C>();
	}
};

}
