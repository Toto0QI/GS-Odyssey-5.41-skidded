#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SubtitlesWidgets

#include "Basic.hpp"

#include "SubtitlesWidgets_classes.hpp"
#include "SubtitlesWidgets_parameters.hpp"


namespace SDK
{

// Function SubtitlesWidgets.FortMediaSubtitlesPlayer.BindToMediaPlayer
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UMediaPlayer*                     InMediaPlayer                                          (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UFortMediaSubtitlesPlayer::BindToMediaPlayer(class UMediaPlayer* InMediaPlayer)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FortMediaSubtitlesPlayer", "BindToMediaPlayer");

	Params::FortMediaSubtitlesPlayer_BindToMediaPlayer Parms{};

	Parms.InMediaPlayer = InMediaPlayer;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function SubtitlesWidgets.FortMediaSubtitlesPlayer.Play
// (Final, Native, Public, BlueprintCallable)

void UFortMediaSubtitlesPlayer::Play()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FortMediaSubtitlesPlayer", "Play");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function SubtitlesWidgets.FortMediaSubtitlesPlayer.SetSubtitles
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UOverlays*                        Subtitles                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UFortMediaSubtitlesPlayer::SetSubtitles(class UOverlays* Subtitles)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FortMediaSubtitlesPlayer", "SetSubtitles");

	Params::FortMediaSubtitlesPlayer_SetSubtitles Parms{};

	Parms.Subtitles = Subtitles;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function SubtitlesWidgets.FortMediaSubtitlesPlayer.Stop
// (Final, Native, Public, BlueprintCallable)

void UFortMediaSubtitlesPlayer::Stop()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FortMediaSubtitlesPlayer", "Stop");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function SubtitlesWidgets.SubtitleDisplay.HasSubtitles
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USubtitleDisplay::HasSubtitles() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SubtitleDisplay", "HasSubtitles");

	Params::SubtitleDisplay_HasSubtitles Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}

}
