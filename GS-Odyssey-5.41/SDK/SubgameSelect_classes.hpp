#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SubgameSelect

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass SubgameSelect.SubgameSelect_C
// 0x0028 (0x0338 - 0x0310)
class USubgameSelect_C final : public UFortUIStateWidget_NUI
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0310(0x0008)(Transient, DuplicateTransient)
	class UBottomBarWidget_C*                     BottomBar;                                         // 0x0318(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBuildWatermark_C*                      BuildWatermark;                                    // 0x0320(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonWidgetStack*                     MainContentStack;                                  // 0x0328(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              TopBar;                                            // 0x0330(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_SubgameSelect(int32 EntryPoint);
	void PushContentWidgetInternal(class UWidget* Widget, const struct FContentPushState& State);
	void OnEnterState(EFortUIState PreviousUIState);
	void Construct();
	void Initialize();
	class UWidget* PopContentWidgetInternal(const struct FContentPushState& State);
	void UpdateHeaderAndFooter(bool HideHeader, bool HideFooter);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SubgameSelect_C">();
	}
	static class USubgameSelect_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USubgameSelect_C>();
	}
};

}
