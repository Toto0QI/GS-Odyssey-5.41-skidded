#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaEventMatchPlayerGridScreen

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaEventMatchPlayerGridScreen.AthenaEventMatchPlayerGridScreen_C
// 0x0038 (0x03D8 - 0x03A0)
class UAthenaEventMatchPlayerGridScreen_C final : public UAthenaEventMatchPlayerGridScreenBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03A0(0x0008)(Transient, DuplicateTransient)
	class UButton*                                ActivePlayersButton;                               // 0x03A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUniformGridPanel*                      ActivePlayersGrid;                                 // 0x03B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UButton*                                DeadPlayersButton;                                 // 0x03B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUniformGridPanel*                      DeadPlayersGrid;                                   // 0x03C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           SpectateInReplayVB;                                // 0x03C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TitleText;                                         // 0x03D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AthenaEventMatchPlayerGridScreen(int32 EntryPoint);
	void ShowEliminatedPlayers();
	void ShowActivePlayers();
	void OnTeamAdded_BP(class UAthenaEventMatchTeamWidgetBase* NewlyAddedTeamWidget);
	void OnTeamDied_BP(class UAthenaEventMatchTeamWidgetBase* NewlyDeadTeamWidget);
	void BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature();
	void BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature();
	void Construct();
	void ShouldResizeActiveGrid(bool* bShouldResize, int32* NumColumns);
	void ResetTeamGrid(class UUniformGridPanel* InGrid, TArray<class UAthenaEventMatchTeamWidgetBase*>& InChildren, int32 InNumColumns);
	void CalculateRectangleGridHeight(int32 NumElements, int32* GridHeight);
	void AddTeamToGrid(class UAthenaEventMatchTeamWidgetBase* TeamWidget, int32 NumColumns);
	void IsActiveGridVisible(bool* bIsVisible);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaEventMatchPlayerGridScreen_C">();
	}
	static class UAthenaEventMatchPlayerGridScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaEventMatchPlayerGridScreen_C>();
	}
};

}
