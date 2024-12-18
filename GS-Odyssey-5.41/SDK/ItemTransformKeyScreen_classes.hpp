#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemTransformKeyScreen

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CommonUI_classes.hpp"
#include "FortniteUI_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemTransformKeyScreen.ItemTransformKeyScreen_C
// 0x0078 (0x0288 - 0x0210)
class UItemTransformKeyScreen_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0210(0x0008)(Transient, DuplicateTransient)
	class UHorizontalTabList_C*                   HorizontalTabList;                                 // 0x0218(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UItemTransformKeyInfo_C*                ItemTransformKeyInfo;                              // 0x0220(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UItemTransformKeyPicker_C*              ItemTransformKeyPicker;                            // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TabLabelText;                                      // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortItem*                              CurrentKey;                                        // 0x0238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UFortAccountItem*>               KeyItems;                                          // 0x0240(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	UMulticastDelegateProperty_                   OnKeySelected;                                     // 0x0250(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	UMulticastDelegateProperty_                   OnKeyConfirmed;                                    // 0x0260(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class FName                                   CurrentTab;                                        // 0x0270(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UBP_ItemTransform_TabButton_C*>  TabButtons;                                        // 0x0278(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)

public:
	void OnKeySelected__DelegateSignature(class UFortItem* Key);
	void OnKeyConfirmed__DelegateSignature();
	void ExecuteUbergraph_ItemTransformKeyScreen(int32 EntryPoint);
	void Hack();
	void BndEvt__ItemTransformKeyPicker_K2Node_ComponentBoundEvent_116_OnItemSelectionEvent__DelegateSignature(class UFortItem* SelectedItem);
	void BndEvt__ItemTransformKeyPicker_K2Node_ComponentBoundEvent_77_OnItemSelectionEvent__DelegateSignature(class UFortItem* SelectedItem);
	void BndEvt__HorizontalTabList_K2Node_ComponentBoundEvent_40_OnTabButtonCreated__DelegateSignature(class FName TabId, class UCommonButton* TabButton);
	void HandleHomebaseInventoryChanged();
	void BndEvt__HorizontalTabList_K2Node_ComponentBoundEvent_17_OnTabSelected__DelegateSignature(class FName TabId);
	void BndEvt__ItemTransformKeyPicker_K2Node_ComponentBoundEvent_189_OnItemSelectionEvent__DelegateSignature(class UFortItem* SelectedItem);
	void Construct();
	void RebuildKeyList(EConversionControlKeyRequest RequestType);
	void SetupKeyList();
	void HandleItemSelected(class UFortItem* Item);
	void ResetScreen();
	void Get_Selected_Item(class UFortItem** SelectedKey);
	void NavigateToSelectedItem(class UFortItem* InItem);
	void NavigateToFirstItem();
	void Determine_Key_Types_to_See(class FName TabNameID, EConversionControlKeyRequest* RequestType);
	void Determine_Tab_List_Title(class FName TabNameID, class FText* Text);
	void Refresh_Tab_Button_Bangs();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemTransformKeyScreen_C">();
	}
	static class UItemTransformKeyScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemTransformKeyScreen_C>();
	}
};

}

