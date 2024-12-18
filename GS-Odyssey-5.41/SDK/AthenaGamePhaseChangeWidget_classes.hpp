#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaGamePhaseChangeWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaGamePhaseChangeWidget.AthenaGamePhaseChangeWidget_C
// 0x0050 (0x0290 - 0x0240)
class UAthenaGamePhaseChangeWidget_C final : public UAthenaHUDGamePhaseChangingBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0240(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       IconSlide;                                         // 0x0248(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       IconPulse;                                         // 0x0250(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       ModeChanged;                                       // 0x0258(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           Content;                                           // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         Feedback;                                          // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Icon;                                              // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       MESSAGE;                                           // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TimeText;                                          // 0x0280(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          bSimplifiedHUD;                                    // 0x0288(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_AthenaGamePhaseChangeWidget(int32 EntryPoint);
	void Construct();
	void GamePhaseStepChanged(EAthenaGamePhaseStep Step);
	void OnAnimationFinished(const class UWidgetAnimation* Animation);
	void UpdateMessaging(EAthenaGamePhaseStep Step, const class FText& Param_MESSAGE, const class FText& Param_TimeText);
	void PlayGamePhaseAlertSound(EAthenaGamePhaseStep Step);
	void PlayIntroAnimation(EAthenaGamePhaseStep Step);
	void SimplifiedAnimationFinished();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaGamePhaseChangeWidget_C">();
	}
	static class UAthenaGamePhaseChangeWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaGamePhaseChangeWidget_C>();
	}
};

}

