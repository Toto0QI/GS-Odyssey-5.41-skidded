#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaSpectatorHitPointBar

#include "Basic.hpp"

#include "AthenaSpectatorHitPointBar_classes.hpp"
#include "AthenaSpectatorHitPointBar_parameters.hpp"


namespace SDK
{

// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.ExecuteUbergraph_AthenaSpectatorHitPointBar
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSpectatorHitPointBar_C::ExecuteUbergraph_AthenaSpectatorHitPointBar(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "ExecuteUbergraph_AthenaSpectatorHitPointBar");

	Params::AthenaSpectatorHitPointBar_C_ExecuteUbergraph_AthenaSpectatorHitPointBar Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnDeltaValueChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   InDeltaValue                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSpectatorHitPointBar_C::OnDeltaValueChanged(float InDeltaValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "OnDeltaValueChanged");

	Params::AthenaSpectatorHitPointBar_C_OnDeltaValueChanged Parms{};

	Parms.InDeltaValue = InDeltaValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnCurrentValueChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   InCurrentValue                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSpectatorHitPointBar_C::OnCurrentValueChanged(float InCurrentValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "OnCurrentValueChanged");

	Params::AthenaSpectatorHitPointBar_C_OnCurrentValueChanged Parms{};

	Parms.InCurrentValue = InCurrentValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnDBNOChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInIsDBNO                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaSpectatorHitPointBar_C::OnDBNOChanged(bool bInIsDBNO)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "OnDBNOChanged");

	Params::AthenaSpectatorHitPointBar_C_OnDBNOChanged Parms{};

	Parms.bInIsDBNO = bInIsDBNO;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnDBNOChanged_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::OnDBNOChanged_BP()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "OnDBNOChanged_BP");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.UpdateBars_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::UpdateBars_BP()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "UpdateBars_BP");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaSpectatorHitPointBar_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "PreConstruct");

	Params::AthenaSpectatorHitPointBar_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.InitializeBar
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::InitializeBar()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSpectatorHitPointBar_C", "InitializeBar");

	UObject::ProcessEvent(Func, nullptr);
}

}
