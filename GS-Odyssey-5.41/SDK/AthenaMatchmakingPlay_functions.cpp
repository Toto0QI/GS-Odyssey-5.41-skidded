#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaMatchmakingPlay

#include "Basic.hpp"

#include "AthenaMatchmakingPlay_classes.hpp"
#include "AthenaMatchmakingPlay_parameters.hpp"


namespace SDK
{

// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.PlaylistsUpdated__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UAthenaMatchmakingPlay_C::PlaylistsUpdated__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "PlaylistsUpdated__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.ExecuteUbergraph_AthenaMatchmakingPlay
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaMatchmakingPlay_C::ExecuteUbergraph_AthenaMatchmakingPlay(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "ExecuteUbergraph_AthenaMatchmakingPlay");

	Params::AthenaMatchmakingPlay_C_ExecuteUbergraph_AthenaMatchmakingPlay Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OnNewModeViolatorUpdated
// (Event, Protected, BlueprintEvent)

void UAthenaMatchmakingPlay_C::OnNewModeViolatorUpdated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OnNewModeViolatorUpdated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.SetSquadFillText
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    InCurrentSquadFill                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaMatchmakingPlay_C::SetSquadFillText(bool InCurrentSquadFill)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "SetSquadFillText");

	Params::AthenaMatchmakingPlay_C_SetSquadFillText Parms{};

	Parms.InCurrentSquadFill = InCurrentSquadFill;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.BndEvt__AthenaMatchmakingModeButton_K2Node_ComponentBoundEvent_42_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaMatchmakingPlay_C::BndEvt__AthenaMatchmakingModeButton_K2Node_ComponentBoundEvent_42_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "BndEvt__AthenaMatchmakingModeButton_K2Node_ComponentBoundEvent_42_CommonButtonClicked__DelegateSignature");

	Params::AthenaMatchmakingPlay_C_BndEvt__AthenaMatchmakingModeButton_K2Node_ComponentBoundEvent_42_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.PlaylistChanged
// (Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// struct FPlaylistFrontEndData            NewPlaylist                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)

void UAthenaMatchmakingPlay_C::PlaylistChanged(const struct FPlaylistFrontEndData& NewPlaylist)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "PlaylistChanged");

	Params::AthenaMatchmakingPlay_C_PlaylistChanged Parms{};

	Parms.NewPlaylist = std::move(NewPlaylist);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OnSetCancelButtonText
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// class FText                             CancelButtonText                                       (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UAthenaMatchmakingPlay_C::OnSetCancelButtonText(const class FText& CancelButtonText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OnSetCancelButtonText");

	Params::AthenaMatchmakingPlay_C_OnSetCancelButtonText Parms{};

	Parms.CancelButtonText = std::move(CancelButtonText);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OnSetPlayButtonText
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// class FText                             PlayButtonText                                         (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UAthenaMatchmakingPlay_C::OnSetPlayButtonText(const class FText& PlayButtonText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OnSetPlayButtonText");

	Params::AthenaMatchmakingPlay_C_OnSetPlayButtonText Parms{};

	Parms.PlayButtonText = std::move(PlayButtonText);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OnPlayButtonUpdated
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    bShowPlayButton                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaMatchmakingPlay_C::OnPlayButtonUpdated(bool bShowPlayButton)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OnPlayButtonUpdated");

	Params::AthenaMatchmakingPlay_C_OnPlayButtonUpdated Parms{};

	Parms.bShowPlayButton = bShowPlayButton;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.BndEvt__BP_CancelButton_K2Node_ComponentBoundEvent_19_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaMatchmakingPlay_C::BndEvt__BP_CancelButton_K2Node_ComponentBoundEvent_19_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "BndEvt__BP_CancelButton_K2Node_ComponentBoundEvent_19_CommonButtonClicked__DelegateSignature");

	Params::AthenaMatchmakingPlay_C_BndEvt__BP_CancelButton_K2Node_ComponentBoundEvent_19_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.BndEvt__BP_PlayButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaMatchmakingPlay_C::BndEvt__BP_PlayButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "BndEvt__BP_PlayButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature");

	Params::AthenaMatchmakingPlay_C_BndEvt__BP_PlayButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaMatchmakingPlay_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OnAvailablePlaylistsUpdated
// (Event, Public, BlueprintEvent)

void UAthenaMatchmakingPlay_C::OnAvailablePlaylistsUpdated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OnAvailablePlaylistsUpdated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaMatchmakingPlay.AthenaMatchmakingPlay_C.OpenPlayOptions
// (Public, BlueprintCallable, BlueprintEvent)

void UAthenaMatchmakingPlay_C::OpenPlayOptions()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaMatchmakingPlay_C", "OpenPlayOptions");

	UObject::ProcessEvent(Func, nullptr);
}

}
