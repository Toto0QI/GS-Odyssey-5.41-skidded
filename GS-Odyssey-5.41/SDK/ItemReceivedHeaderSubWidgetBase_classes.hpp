#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemReceivedHeaderSubWidgetBase

#include "Basic.hpp"

#include "FortniteUI_structs.hpp"
#include "UMG_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemReceivedHeaderSubWidgetBase.ItemReceivedHeaderSubWidgetBase_C
// 0x0038 (0x0240 - 0x0208)
class UItemReceivedHeaderSubWidgetBase_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0208(0x0008)(Transient, DuplicateTransient)
	class UFortGiftBoxItem*                       GiftBoxItem_BP;                                    // 0x0210(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	class FString                                 FromUserName_BP;                                   // 0x0218(0x0010)(Edit, BlueprintVisible, ZeroConstructor, ExposeOnSpawn, HasGetValueTypeHash)
	TArray<struct FFortReceivedItemLootInfo>      ItemDefs;                                          // 0x0228(0x0010)(Edit, BlueprintVisible, ZeroConstructor)
	bool                                          bIsBattlePassUpgrade;                              // 0x0238(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bSelfGift;                                         // 0x0239(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)

public:
	void Construct();
	void ExecuteUbergraph_ItemReceivedHeaderSubWidgetBase(int32 EntryPoint);
	void InitFromGiftBoxItem_BP();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemReceivedHeaderSubWidgetBase_C">();
	}
	static class UItemReceivedHeaderSubWidgetBase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemReceivedHeaderSubWidgetBase_C>();
	}
};

}

