#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RecentMatchesStatScreen

#include "Basic.hpp"

#include "RecentMatchesStatScreen_classes.hpp"
#include "RecentMatchesStatScreen_parameters.hpp"


namespace SDK
{

// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.ExecuteUbergraph_RecentMatchesStatScreen
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void URecentMatchesStatScreen_C::ExecuteUbergraph_RecentMatchesStatScreen(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "ExecuteUbergraph_RecentMatchesStatScreen");

	Params::RecentMatchesStatScreen_C_ExecuteUbergraph_RecentMatchesStatScreen Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnRecentMatcheChanged
// (Event, Public, BlueprintEvent)

void URecentMatchesStatScreen_C::OnRecentMatcheChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnRecentMatcheChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnDataRecieved
// (Event, Public, BlueprintEvent)

void URecentMatchesStatScreen_C::OnDataRecieved()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnDataRecieved");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnNoData
// (Event, Public, BlueprintEvent)

void URecentMatchesStatScreen_C::OnNoData()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnNoData");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnStartFetchingData
// (Event, Public, BlueprintEvent)

void URecentMatchesStatScreen_C::OnStartFetchingData()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnStartFetchingData");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnActivated
// (Event, Protected, BlueprintEvent)

void URecentMatchesStatScreen_C::OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.OnDeactivated
// (Event, Protected, BlueprintEvent)

void URecentMatchesStatScreen_C::OnDeactivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "OnDeactivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void URecentMatchesStatScreen_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RecentMatchesStatScreen.RecentMatchesStatScreen_C.HandleBack
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Passthrough                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void URecentMatchesStatScreen_C::HandleBack(bool* Passthrough)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RecentMatchesStatScreen_C", "HandleBack");

	Params::RecentMatchesStatScreen_C_HandleBack Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Passthrough != nullptr)
		*Passthrough = Parms.Passthrough;
}

}
