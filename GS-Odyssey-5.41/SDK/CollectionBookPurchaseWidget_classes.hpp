#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CollectionBookPurchaseWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CollectionBookPurchaseWidget.CollectionBookPurchaseWidget_C
// 0x0030 (0x0358 - 0x0328)
class UCollectionBookPurchaseWidget_C final : public UFortActivatablePanel
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0328(0x0008)(Transient, DuplicateTransient)
	class UIconTextButton_C*                      ButtonClose;                                       // 0x0330(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCollectionBookPurchasePanel_C*         CollectionBookPurchasePanel;                       // 0x0338(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       DisplayName;                                       // 0x0340(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class ULightbox_C*                            Lightbox;                                          // 0x0348(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       SectionNameTextWidget;                             // 0x0350(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BndEvt__ButtonClose_K2Node_ComponentBoundEvent_26_CommonButtonClicked__DelegateSignature(class UCommonButton* Button);
	void Close();
	void ExecuteUbergraph_CollectionBookPurchaseWidget(int32 EntryPoint);
	void OnActivated();
	void SetItem(class UFortItem* Item, const struct FFortCollectionBookSlotData& SlotData);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CollectionBookPurchaseWidget_C">();
	}
	static class UCollectionBookPurchaseWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCollectionBookPurchaseWidget_C>();
	}
};

}

