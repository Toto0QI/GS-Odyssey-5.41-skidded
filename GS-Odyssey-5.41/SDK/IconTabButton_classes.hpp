#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: IconTabButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "CommonInput_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass IconTabButton.IconTabButton_C
// 0x0158 (0x09E8 - 0x0890)
class UIconTabButton_C final : public UCommonButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0890(0x0008)(Transient, DuplicateTransient)
	class UNormalBangWrapper_C*                   BangWrapper;                                       // 0x0898(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       CenterButtonTextWidget;                            // 0x08A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         ContentHB;                                         // 0x08A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 LeftSideImage;                                     // 0x08B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               SizeBoxShell;                                      // 0x08B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   ButtonText;                                        // 0x08C0(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FSlateBrush                            IconBrush;                                         // 0x08D8(0x0088)(Edit, BlueprintVisible, ExposeOnSpawn)
	bool                                          UseText;                                           // 0x0960(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_440B[0x3];                                     // 0x0961(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           SelectedIconTint;                                  // 0x0964(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           DeselectedIconTint;                                // 0x0974(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           HoveredIconTint;                                   // 0x0984(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bBangEnabled;                                      // 0x0994(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          ChangeIconColorWhenSelected;                       // 0x0995(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_440C[0x2];                                     // 0x0996(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            SelectedIconColor;                                 // 0x0998(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FSlateColor                            UnSelectedIconColor;                               // 0x09C0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_IconTabButton(int32 EntryPoint);
	void OnCurrentTextStyleChanged();
	void BP_OnDisabled();
	void BP_OnEnabled();
	void BP_OnUnhovered();
	void BP_OnHovered();
	void Construct();
	void BP_OnDeselected();
	void BP_OnSelected();
	void SetTabLabelInfo(const struct FFortTabButtonLabelInfo& TabLabelInfo);
	void PreConstruct(bool IsDesignTime);
	void Set_Text(const class FText& Param_ButtonText);
	void Set_Icon(const struct FSlateBrush& Param_IconBrush);
	void ShowText();
	void SetTutorialBorderStyle(class UClass* BorderStyle);
	void Update_Bang_State(bool Param_bBangEnabled);
	void SetChangeIconColorWhenSelected(bool ChangeColorWhenSelected, const struct FSlateColor& SelectedColor, const struct FSlateColor& UnselectedColor);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"IconTabButton_C">();
	}
	static class UIconTabButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UIconTabButton_C>();
	}
};

}
