#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HeroSquadSlotsView

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass HeroSquadSlotsView.HeroSquadSlotsView_C
// 0x0038 (0x0330 - 0x02F8)
class UHeroSquadSlotsView_C final : public UFortSquadSlotsView
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02F8(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Defenders_Squad_Intro;                             // 0x0300(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Bonus_Squad_Intro;                                 // 0x0308(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Primary_Intro;                                     // 0x0310(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USquadSlotGroup_C*                      BonusSquadSlotGroup;                               // 0x0318(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USquadSlotGroup_C*                      DefendersSquadSlotGroup;                           // 0x0320(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USquadSlotGroup_C*                      PrimarySquadSlotGroup;                             // 0x0328(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_HeroSquadSlotsView(int32 EntryPoint);
	void Construct();
	class UFortSquadSlotSelectorButton* CreateAndAddSquadSlotButton(const int32 SquadSlotIndex, const struct FHomebaseSquadSlot& SquadSlotDefinition, class UWidget** OutSquadSlotButtonHost);
	void HandleSquadNavigation(class FName SquadId, int32 SlotIndex);
	void HighlightSlotByIndex(int32 Param_Index);
	void Bonus();
	void Defenders();
	void Primary();
	void UndarkenAllSlots();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HeroSquadSlotsView_C">();
	}
	static class UHeroSquadSlotsView_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHeroSquadSlotsView_C>();
	}
};

}
