#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaSeasonReward

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "CommonInput_structs.hpp"
#include "CommonUI_classes.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaSeasonReward.AthenaSeasonReward_C
// 0x0078 (0x0908 - 0x0890)
class UAthenaSeasonReward_C final : public UCommonButton
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0890(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Intro;                                             // 0x0898(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ClaimedImage;                                      // 0x08A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortMultiSizeItemCard*                 ItemCard;                                          // 0x08A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 LockedImage;                                       // 0x08B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 RarityFlare;                                       // 0x08B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 RevealOverlay;                                     // 0x08C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortItem*                              StrongItemToRepresent;                             // 0x08C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             SoundOnReveal;                                     // 0x08D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ViewOnHover;                                       // 0x08D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_542F[0x7];                                     // 0x08D9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortItem*                              SecondaryItem;                                     // 0x08E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           ShowVariantTimer;                                  // 0x08E8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           ResetVariantTimer;                                 // 0x08F0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	int32                                         VariantIndex;                                      // 0x08F8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          WaitingForVaultToChange;                           // 0x08FC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5430[0x3];                                     // 0x08FD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TimeBetweenVariants;                               // 0x0900(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TimeBetweenVariantsRestart;                        // 0x0904(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AthenaSeasonReward(int32 EntryPoint);
	void BP_OnClicked();
	void ViewItem();
	void PlayIntro();
	void BP_OnHovered();
	void Setup(class UFortItem* ItemToRepresent, bool Claimed, bool Locked, bool LevelAchieved, EFortItemCardSize ItemCardSize);
	void SetState(bool Claimed, bool Locked, bool LevelAchieved);
	void SetViewOnHover(bool ShouldViewOnHover);
	void EnableRarityFlare();
	void SetSecondaryItem(class UFortItem* Param_SecondaryItem);
	void ViewInVault(const TArray<class UFortItem*>& Additional_Items);
	void ViewInVaultByUser();
	void BeginCyclingVariants();
	void StopCyclingVariants();
	void ShowNextVariant();
	void OnVaultItemsChanged(TArray<class UFortItem*>& Items);
	void GetAthenaItemCharacterItemDefinition(class UAthenaCharacterItemDefinition** AsAthena_Character_Item_Definition);
	void StartVariantTimer();
	void CancelVariantTimer();
	void ResetVariantToDefault();

	void GetTemporaryItems(TArray<struct FFortCosmeticVariantPreviewElement>& Cosmetics, TArray<class UFortItem*>* Temporary_Items) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaSeasonReward_C">();
	}
	static class UAthenaSeasonReward_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaSeasonReward_C>();
	}
};

}
