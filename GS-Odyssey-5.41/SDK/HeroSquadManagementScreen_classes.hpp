#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HeroSquadManagementScreen

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass HeroSquadManagementScreen.HeroSquadManagementScreen_C
// 0x0058 (0x04B0 - 0x0458)
class UHeroSquadManagementScreen_C final : public UFortHeroSquadManagementScreen
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0458(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Entrance;                                          // 0x0460(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       AniShowSlotInfo;                                   // 0x0468(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       HidePicker;                                        // 0x0470(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       AniHideSlotInfo;                                   // 0x0478(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       ShowPicker;                                        // 0x0480(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          BorderSlotInfo;                                    // 0x0488(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextSlotBody;                                      // 0x0490(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextSlotHeader;                                    // 0x0498(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FDataTableRowHandle                    InputBackAction;                                   // 0x04A0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void ExecuteUbergraph_HeroSquadManagementScreen(int32 EntryPoint);
	void OnBeginIntro();
	void BndEvt__SquadSlotsView_K2Node_ComponentBoundEvent_2_OnDifferentSquadSlotSelected__DelegateSignature(int32 SquadSlotIndex);
	void HandleSquadSlotPickerHidden();
	void HandleSquadSlotPickerShown();
	void OnDeactivated();
	void SetDefaultScroll();
	void Construct();
	void OnActivated();
	ESlateVisibility GetInZoneVisibility();
	void HandleClosePicker(bool* bPassThrough);
	void ShowSlotInfo(const class FText& HeaderText, const class FText& BodyText);
	void HideSlotInfo();
	void Update_Hero_Squad_Bonus_Tiles_SubIcon_Glow_State();
	void Update_Hero_Squad_Bonus_Highlight_State();
	void HandleHideSlotInfoAni();
	void HandlePickerHideAni();
	void HandlePickerShowAni();
	void HandleShowSlotInfoAni();
	void Intro();
	void Intro_Initial_Reset();
	void UpdateSquadSlotInfoPanel(int32 SquadSlotIndex);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HeroSquadManagementScreen_C">();
	}
	static class UHeroSquadManagementScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHeroSquadManagementScreen_C>();
	}
};

}
