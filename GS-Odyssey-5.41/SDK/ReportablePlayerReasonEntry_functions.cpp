#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ReportablePlayerReasonEntry

#include "Basic.hpp"

#include "ReportablePlayerReasonEntry_classes.hpp"
#include "ReportablePlayerReasonEntry_parameters.hpp"


namespace SDK
{

// Function ReportablePlayerReasonEntry.ReportablePlayerReasonEntry_C.ExecuteUbergraph_ReportablePlayerReasonEntry
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UReportablePlayerReasonEntry_C::ExecuteUbergraph_ReportablePlayerReasonEntry(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ReportablePlayerReasonEntry_C", "ExecuteUbergraph_ReportablePlayerReasonEntry");

	Params::ReportablePlayerReasonEntry_C_ExecuteUbergraph_ReportablePlayerReasonEntry Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ReportablePlayerReasonEntry.ReportablePlayerReasonEntry_C.SetSelectionState
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    bIsSelected                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    bAnimateOnSelect                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UReportablePlayerReasonEntry_C::SetSelectionState(bool bIsSelected, bool bAnimateOnSelect)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ReportablePlayerReasonEntry_C", "SetSelectionState");

	Params::ReportablePlayerReasonEntry_C_SetSelectionState Parms{};

	Parms.bIsSelected = bIsSelected;
	Parms.bAnimateOnSelect = bAnimateOnSelect;

	UObject::ProcessEvent(Func, &Parms);
}

}
