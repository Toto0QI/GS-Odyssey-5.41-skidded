#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NetDebugContainer

#include "Basic.hpp"

#include "NetDebugContainer_classes.hpp"
#include "NetDebugContainer_parameters.hpp"


namespace SDK
{

// Function NetDebugContainer.NetDebugContainer_C.ExecuteUbergraph_NetDebugContainer
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNetDebugContainer_C::ExecuteUbergraph_NetDebugContainer(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NetDebugContainer_C", "ExecuteUbergraph_NetDebugContainer");

	Params::NetDebugContainer_C_ExecuteUbergraph_NetDebugContainer Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NetDebugContainer.NetDebugContainer_C.OnVisibilitySetEvent
// (Event, Protected, BlueprintEvent)
// Parameters:
// ESlateVisibility                        InVisibility                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNetDebugContainer_C::OnVisibilitySetEvent(ESlateVisibility InVisibility)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NetDebugContainer_C", "OnVisibilitySetEvent");

	Params::NetDebugContainer_C_OnVisibilitySetEvent Parms{};

	Parms.InVisibility = InVisibility;

	UObject::ProcessEvent(Func, &Parms);
}

}
