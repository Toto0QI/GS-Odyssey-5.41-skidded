#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CollectionMultiProgressBar

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"
#include "CollectionMissionBadgeDisplayInfo_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CollectionMultiProgressBar.CollectionMultiProgressBar_C
// 0x02B8 (0x04C8 - 0x0210)
class UCollectionMultiProgressBar_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0210(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Flash;                                             // 0x0218(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 CategoryIcon;                                      // 0x0220(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 FlashImage;                                        // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         ProgressBarsBox;                                   // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 SpacerImage;                                       // 0x0238(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         TopBox;                                            // 0x0240(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         TopIconsBox;                                       // 0x0248(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	TArray<struct FCollectionMissionBadgeDisplayInfo> BarInfos;                                          // 0x0250(0x0010)(Edit, BlueprintVisible, ZeroConstructor, ExposeOnSpawn)
	struct FProgressBarStyle                      ProgressBarsStyle;                                 // 0x0260(0x01A0)(Edit, BlueprintVisible)
	bool                                          bOnlyShowBarWithCountInRange;                      // 0x0400(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39B3[0x7];                                     // 0x0401(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateBrush                            IconBrush;                                         // 0x0408(0x0088)(Edit, BlueprintVisible, ExposeOnSpawn)
	EFortBrushSize                                IconSize;                                          // 0x0490(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          bShowBarTopIcons;                                  // 0x0491(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	bool                                          bShowBarSideIcons;                                 // 0x0492(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	uint8                                         Pad_39B4[0x1];                                     // 0x0493(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMargin                                BarsMargin;                                        // 0x0494(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	struct FMargin                                BarsIconMargin;                                    // 0x04A4(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	float                                         BarHeightFactor;                                   // 0x04B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCollectionBar_C*                       PreviousBarWithCountInRange;                       // 0x04B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BarHeightOverride;                                 // 0x04C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_CollectionMultiProgressBar(int32 EntryPoint);
	void Construct();
	void Setup(TArray<struct FCollectionMissionBadgeDisplayInfo>& InBarInfos, int32 AchievedCount);
	void Update(int32 AchievedCount);
	void UpdateVisibleBar();
	void PlayFlashAnimation();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CollectionMultiProgressBar_C">();
	}
	static class UCollectionMultiProgressBar_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCollectionMultiProgressBar_C>();
	}
};

}

