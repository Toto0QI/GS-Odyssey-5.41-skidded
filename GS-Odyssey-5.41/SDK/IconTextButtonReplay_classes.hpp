#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: IconTextButtonReplay

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "CommonInput_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass IconTextButtonReplay.IconTextButtonReplay_C
// 0x0130 (0x09C0 - 0x0890)
class UIconTextButtonReplay_C final : public UCommonButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0890(0x0008)(Transient, DuplicateTransient)
	class UBorder*                                Background;                                        // 0x0898(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       CenterButtonTextWidget;                            // 0x08A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                ContentBorder;                                     // 0x08A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image;                                             // 0x08B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UNamedSlot*                             RightExtraContentSlot;                             // 0x08B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   ButtonText;                                        // 0x08C0(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FSlateBrush                            IconBrush;                                         // 0x08D8(0x0088)(Edit, BlueprintVisible, ExposeOnSpawn)
	class UClass*                                 ControllerInputStyle;                              // 0x0960(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	class UClass*                                 MouseKeyboardStyle;                                // 0x0968(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    ButtonClickAction;                                 // 0x0970(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	EHorizontalAlignment                          ContentAlignment;                                  // 0x0980(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_56BB[0x3];                                     // 0x0981(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           HoveredColor;                                      // 0x0984(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           DefaultColor;                                      // 0x0994(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FColor                                 PressedColor;                                      // 0x09A4(0x0004)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           SelectedColor;                                     // 0x09A8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShouldHideIcon;                                    // 0x09B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_IconTextButtonReplay(int32 EntryPoint);
	void BP_OnDeselected();
	void BP_OnSelected();
	void BP_OnUnhovered();
	void BP_OnHovered();
	void Construct();
	void OnActionComplete();
	void OnActionProgress(float HeldPercent);
	void OnTriggeredInputActionChanged(const struct FDataTableRowHandle& NewTriggeredAction);
	void BndEvt__CommonActionWidgetAction_K2Node_ComponentBoundEvent_0_OnInputMethodChanged__DelegateSignature(bool bUsingGamepad);
	void SetTabLabelInfo(const struct FFortTabButtonLabelInfo& TabLabelInfo);
	void PreConstruct(bool IsDesignTime);
	void OnCurrentTextStyleChanged();
	void Set_Text(const class FText& Param_ButtonText);
	void Set_Icon(const struct FSlateBrush& Param_IconBrush);
	void InitializeButton();
	void UpdateTextAndStyle(bool bUsingGamepad);
	void SetControllerStyle(class UClass* Param_ControllerInputStyle);
	void UpdateText();
	void UpdateStyle(bool UsingGamepad);
	void SetMouseKeyboardStyle(class UClass* Param_ControllerInputStyle);
	void UpdateContentAlignment();
	void SetContentAlignment(EHorizontalAlignment Param_ContentAlignment);
	void UpdateTextStyle();
	void ActivateButton();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"IconTextButtonReplay_C">();
	}
	static class UIconTextButtonReplay_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UIconTextButtonReplay_C>();
	}
};

}
