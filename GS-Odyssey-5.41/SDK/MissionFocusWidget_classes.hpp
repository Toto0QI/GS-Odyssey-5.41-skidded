#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MissionFocusWidget

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass MissionFocusWidget.MissionFocusWidget_C
// 0x0040 (0x0250 - 0x0210)
class UMissionFocusWidget_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0210(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       HeaderText;                                        // 0x0218(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UProgressBar*                           KillPointsBar;                                     // 0x0220(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TimerText;                                         // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortMissionTimerComponent*             SavedTimerComponent;                               // 0x0230(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortMission*                           CurrentFocusedMission;                             // 0x0238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         KillBarPercentage;                                 // 0x0240(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4F91[0x4];                                     // 0x0244(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           RefreshTimerHandle;                                // 0x0248(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_MissionFocusWidget(int32 EntryPoint);
	void Construct();
	void UpdateTimer();
	void HandleTimerComponentChanged(class UFortMissionTimerComponent* TimerComponent);
	void HandleFocusedMission(class AFortMission* FocusedMission);
	void UpdateVisibility();
	void UpdateAutoRefreshTimer();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MissionFocusWidget_C">();
	}
	static class UMissionFocusWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMissionFocusWidget_C>();
	}
};

}

