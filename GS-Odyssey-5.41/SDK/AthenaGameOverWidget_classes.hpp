#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaGameOverWidget

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "FortniteGame_structs.hpp"
#include "CommonUI_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaGameOverWidget.AthenaGameOverWidget_C
// 0x00E8 (0x0410 - 0x0328)
class UAthenaGameOverWidget_C final : public UAthenaGameOverDisplay
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0328(0x0008)(Transient, DuplicateTransient)
	class UEliminatedOverlay_C*                   EliminatedOverlay;                                 // 0x0330(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetSwitcher*                        GameOverSwitcher;                                  // 0x0338(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UIconTextButton_C*                      OpenShadowPlayHighlights;                          // 0x0340(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_0;                                        // 0x0348(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USpectatedPlayerSwitcher_C*             SpectatedPlayerSwitcher;                           // 0x0350(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWinnerOverlay_C*                       WinnerOverlay;                                     // 0x0358(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FDataTableRowHandle                    Input_ReturnToLobby;                               // 0x0360(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    Input_NextTeammate;                                // 0x0370(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    Input_PreviousTeammate;                            // 0x0380(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    Input_ReportPlayer;                                // 0x0390(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    Input_ViewMatchStats;                              // 0x03A0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	bool                                          ForceSpectatorSetupForReportingPlayer;             // 0x03B0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_560E[0x7];                                     // 0x03B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   KillersName;                                       // 0x03B8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          DeadAndSpectating;                                 // 0x03D0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_560F[0x7];                                     // 0x03D1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDataTableRowHandle                    Input_Matchmake;                                   // 0x03D8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    Input_CancelMatchmaking;                           // 0x03E8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	bool                                          MatchmakingComplete;                               // 0x03F8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5610[0x7];                                     // 0x03F9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDataTableRowHandle                    Input_FollowSpecialActor;                          // 0x0400(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void ExecuteUbergraph_AthenaGameOverWidget(int32 EntryPoint);
	void SpectatorStreamingChanged(bool bSpectatorStreaming);
	void OnToggleFullscreenMap_Bind(bool bFullscreenMapVisible);
	void OnActivated();
	void Destruct();
	void OnDeactivated();
	void BndEvt__OpenShadowPlayHighlights_K2Node_ComponentBoundEvent_188_CommonButtonClicked__DelegateSignature(class UCommonButton* Button);
	void On_Kill_Feed_Updated();
	void Construct();
	void OnPawnDied(struct FFortPlayerDeathReport& DeathReport);
	void OnPlaceChanged();
	void OnViewTargetChanged();
	void HideExtraStuffForSpectating();
	void OnWinnerAnnounced(const class FString& Winner);
	void HighlightCountChanged(int32 HighlightCount);
	void Handle_ReturnToLobby(bool* Passthrough);
	void InputRefresh();
	void Handle_FollowNextTeammate(bool* Passthrough);
	void Handle_FollowPreviousTeammate(bool* Passthrough);
	void InputSetup();
	void Handle_ReportPlayer(bool* Passthrough);
	void Handle_ViewMatchStats(bool* Passthrough);
	void OnPlayerOrTeamWon();
	void SetKillersName(struct FFortPlayerDeathReport& FortPlayerDeathReport);
	bool CanFollowNextOrPreviousTeammate();
	void SetViewModel(class UAthenaPlayerViewModel* ViewModel);
	void InGameMatchmakingComplete(bool Success);
	void Handle_Matchmake(bool* Passthrough);
	void Handle_CancelMatchmaking(bool* Passthrough);
	void OnWinningScoreDetermined(int32 Score);
	void OnPlayerLost(EEndOfMatchReason LostReason);
	void FocusPlayerSwitcher();
	bool CanFollowSpecialActor();
	void Handle_SpectateSpecialActor(bool* Passthrough);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaGameOverWidget_C">();
	}
	static class UAthenaGameOverWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaGameOverWidget_C>();
	}
};

}

