#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Results_Widget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Results_Widget.Results_Widget_C
// 0x0148 (0x0500 - 0x03B8)
class UResults_Widget_C final : public UFortResultsWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03B8(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Anim_TeleportPadIntro;                             // 0x03C0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_CommanderXPOutro;                             // 0x03C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_CommanderXPIntro;                             // 0x03D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_GradientOutro;                                // 0x03D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_GradientIntro;                                // 0x03E0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_VideoOutro;                                   // 0x03E8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_VideoIntro;                                   // 0x03F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_BadgeLoot_C*                   BadgeLoot;                                         // 0x03F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                BorderVideo;                                       // 0x0400(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMovieWidget_C*                         MovieWidgetVideo;                                  // 0x0408(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOverlay*                               Overlay_CommanderXP;                               // 0x0410(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_0;                                        // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_3;                                        // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_Summary_C*                     Summary;                                           // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTeamMicStack_C*                        TeamMicStack;                                      // 0x0430(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_TeamScore_C*                   TeamScore;                                         // 0x0438(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_TeamTotalScore_C*              TeamTotalScore;                                    // 0x0440(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_TeleportPad_C*                 TeleportPad;                                       // 0x0448(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TextZoneCompletion;                                // 0x0450(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_TopPanel_C*                    TopPanel;                                          // 0x0458(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetSwitcher*                        WidgetSwitcherMain;                                // 0x0460(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	float                                         AnalyticsTimeStart;                                // 0x0468(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5B37[0x4];                                     // 0x046C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMediaPlayer*                           MediaPlayer;                                       // 0x0470(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             ResultsStartVictory;                               // 0x0478(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             ResultsStartDefeat;                                // 0x0480(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             ResultsFinished;                                   // 0x0488(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        ACResultsFinished;                                 // 0x0490(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             VictoryIntro;                                      // 0x0498(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             DefeatIntro;                                       // 0x04A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMediaSource*                           DefeatVideo;                                       // 0x04A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortCompletionResult                         ZoneCompletionResult;                              // 0x04B0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5B38[0x3];                                     // 0x04B1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         DelayBetweenVideoAndIntro;                         // 0x04B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bCanSkipVideo;                                     // 0x04B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5B39[0x7];                                     // 0x04B9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             VictoryStart;                                      // 0x04C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             TeamScoreWhoosh;                                   // 0x04C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             CommanderXPWhoosh;                                 // 0x04D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    InputSkip;                                         // 0x04D8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	bool                                          bVideoSkipped;                                     // 0x04E8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5B3A[0x3];                                     // 0x04E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TPAnalyticsTimeStart;                              // 0x04EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UResults_CommanderXP_New_C*             CommanderXPNew_Widget;                             // 0x04F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UResults_CommanderXP_C*                 CommanderXPOld_Widget;                             // 0x04F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Results_Widget(int32 EntryPoint);
	void OnActivated();
	void Destruct();
	void Wait_for_Replication();
	void HandleClientEvent_PlayerLeftEvent(class UObject* EventSource, class UObject* EventFocus, const struct FFortClientEvent& ClientEvent);
	void Construct();
	void OnMediaOpened();
	void SkipVideo();
	void BndEvt__Anim_VideoOutro_K2Node_ComponentBoundEvent_0_OnWidgetAnimationPlaybackStatusChanged__DelegateSignature();
	void OnVideoEndReached();
	void VideoSequenceStart();
	void BndEvt__Anim_ZoneCompletionIntro_K2Node_ComponentBoundEvent_0_OnWidgetAnimationPlaybackStatusChanged__DelegateSignature();
	void PreResults_Sequence();
	void BndEvt__TopPanel_K2Node_ComponentBoundEvent_1_IntroComplete__DelegateSignature();
	void Team_Score_Sequence();
	void BndEvt__Results_ScoreAndXP_K2Node_ComponentBoundEvent_3_Finished__DelegateSignature();
	void Xp_Finished();
	void BndEvt__Anim_CommanderXPOutro_K2Node_ComponentBoundEvent_0_OnWidgetAnimationPlaybackStatusChanged__DelegateSignature();
	void BndEvt__Anim_CommanderXPIntro_K2Node_ComponentBoundEvent_0_OnWidgetAnimationPlaybackStatusChanged__DelegateSignature();
	void Commander_XP_Sequence();
	void BndEvt__ResultsBadgeLoot_K2Node_ComponentBoundEvent_0_Finished__DelegateSignature();
	void Badge_Loot_Sequence();
	void BndEvt__ResultsTeleportPad_K2Node_ComponentBoundEvent_1_OnExitClicked__DelegateSignature();
	void BndEvt__ResultsTeleportPad_K2Node_ComponentBoundEvent_5_OnMissionStatsClicked__DelegateSignature();
	void BndEvt__ResultsTeleportPad_K2Node_ComponentBoundEvent_8_OnUpVoteClicked__DelegateSignature(const struct FUniqueNetIdRepl& TargetId, const class FString& TargetName);
	void BndEvt__ResultsTeleportPad_K2Node_ComponentBoundEvent_7_OnAddFriendClicked__DelegateSignature(const struct FUniqueNetIdRepl& TargetId, const class FString& TargetName);
	void Teleport_Scene_Sequence();
	void BndEvt__ResultsSummary_K2Node_ComponentBoundEvent_1_OnReturnClicked__DelegateSignature();
	void Initialize();
	void Initialize_Video();
	void Toggle_Chat(bool Show);
	void SpawnResultsMusic();
	void Toggle_Top_Level_Tab_Controls(bool Show);
	void PlayMissionResultSound();
	void LogAnalytics(const class FString& ScreenName, bool bSkipped);
	void OnInputSkip(bool* bCommited);
	void InitializeInput();
	void Focus();
	void UseVideos(bool* bVideos);
	bool ShouldDisplayEndOfZoneCinematic();
	void AddCommanderXPWidget();
	void GetCommanderXPWidget(bool* UseNewWidget, class UResults_CommanderXP_New_C** Param_CommanderXPNew_Widget, class UResults_CommanderXP_C** Param_CommanderXPOld_Widget);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Results_Widget_C">();
	}
	static class UResults_Widget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UResults_Widget_C>();
	}
};

}
