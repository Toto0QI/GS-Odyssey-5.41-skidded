#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaInventoryEquipSlot

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "FortniteGame_structs.hpp"
#include "CommonInput_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaInventoryEquipSlot.AthenaInventoryEquipSlot_C
// 0x0028 (0x08D0 - 0x08A8)
class UAthenaInventoryEquipSlot_C final : public UAthenaInventoryEquipButtonBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x08A8(0x0008)(Transient, DuplicateTransient)
	class UImage*                                 DropTarget;                                        // 0x08B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ItemLocked;                                        // 0x08B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UAthenaGadgetFuelGauge_C*               JetpackFuelGauge;                                  // 0x08C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          IsDragHovered;                                     // 0x08C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_AthenaInventoryEquipSlot(int32 EntryPoint);
	void OnDragLeave(const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	void OnInventoryItemSelected_Event_0(class UFortItem* Item);
	void BP_OnDoubleClicked();
	void BP_OnDeselected();
	void BP_OnSelected();
	void OnAddedToFocusPath(const struct FFocusEvent& InFocusEvent);
	void BP_OnClicked();
	void OnQuickbarContentsChanged_Event_0(EFortQuickBars QuickbarIndex, const TArray<int32>& ChangedSlots);
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void Construct();
	void RefreshItem();
	bool OnDrop(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	void OnDragDetected(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation** Operation);
	void TryAndShowDropTarget();
	bool IsDraggingEquipableItem();
	struct FEventReply OnPreviewMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	bool OnDragOver(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation);
	bool CanEquipFortItem(class UObject* Object);
	void IsFocusOfDrop(bool* Param_IsDragHovered);
	void Update_Athena_Gadget_Fuel_Widget(class UFortItem* ItemInSlot);
	void Hide_Athena_Gadget_Fuel_Widget();
	void Show_Athena_Gadget_Fuel_Widget(class UFortItem* Item);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaInventoryEquipSlot_C">();
	}
	static class UAthenaInventoryEquipSlot_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaInventoryEquipSlot_C>();
	}
};

}

