#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemReceivedChallengeCompleteHeader

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ItemReceivedHeaderSubWidgetBase_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemReceivedChallengeCompleteHeader.ItemReceivedChallengeCompleteHeader_C
// 0x0050 (0x0290 - 0x0240)
class UItemReceivedChallengeCompleteHeader_C final : public UItemReceivedHeaderSubWidgetBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_ItemReceivedChallengeCompleteHeader_C; // 0x0240(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       BattlepassTier;                                    // 0x0248(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       BattlepassUpgraded;                                // 0x0250(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       CommonTextBlock_2;                                 // 0x0258(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonWidgetSwitcher*                  CommonWidgetSwitcher_Icon;                         // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonWidgetSwitcher*                  CommonWidgetSwitcher_Title;                        // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ImageBattlePassIconGold;                           // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ImageBattlePassIconSilver;                         // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UItemReceivedAccountWidget_C*           ItemReceivedAccountWidget;                         // 0x0280(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          Is_BattlePass;                                     // 0x0288(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_ItemReceivedChallengeCompleteHeader(int32 EntryPoint);
	void InitFromGiftBoxItem_BP();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemReceivedChallengeCompleteHeader_C">();
	}
	static class UItemReceivedChallengeCompleteHeader_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemReceivedChallengeCompleteHeader_C>();
	}
};

}
