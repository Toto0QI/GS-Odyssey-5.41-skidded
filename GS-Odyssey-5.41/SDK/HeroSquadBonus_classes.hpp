#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HeroSquadBonus

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "SlateCore_structs.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass HeroSquadBonus.HeroSquadBonus_C
// 0x0128 (0x0400 - 0x02D8)
class UHeroSquadBonus_C final : public UFortPerkWidget_NUI
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02D8(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       BonusPerkDescription;                              // 0x02E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 BonusPerkIcon;                                     // 0x02E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       BonusPerkTitle;                                    // 0x02F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          CommonBorderBackground;                            // 0x02F8(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ImageLock;                                         // 0x0300(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ImageSquadBonusType;                               // 0x0308(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               PerkIconSlotSizeBox;                               // 0x0310(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          StatFocus;                                         // 0x0318(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FSlateBrush                            EmptyBrush;                                        // 0x0320(0x0088)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   EmptyText;                                         // 0x03A8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   BonusPerkTItleText;                                // 0x03C0(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FVector2D                              Skill_Icon_Size;                                   // 0x03D8(0x0008)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortSupportBonusType                         SquadBonusType;                                    // 0x03E0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_5803[0x7];                                     // 0x03E1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CachedTooltipDescription;                          // 0x03E8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_HeroSquadBonus(int32 EntryPoint);
	void OnCombinedTooltipDescriptionReady(const class FText& Description);
	void Construct();
	void OnPerkUpdated();
	void PreConstruct(bool IsDesignTime);
	void UpdateBonusPerk();
	void UpdateSquadBonusIconState();
	void SetBackgroundGlow(bool GlowBackground);
	class UWidget* Get_ToolTipWidget();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HeroSquadBonus_C">();
	}
	static class UHeroSquadBonus_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHeroSquadBonus_C>();
	}
};

}
