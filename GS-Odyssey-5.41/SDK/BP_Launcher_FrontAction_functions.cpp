#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Launcher_FrontAction

#include "Basic.hpp"

#include "BP_Launcher_FrontAction_classes.hpp"
#include "BP_Launcher_FrontAction_parameters.hpp"


namespace SDK
{

// Function BP_Launcher_FrontAction.BP_Launcher_FrontAction_C.ExecuteUbergraph_BP_Launcher_FrontAction
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_Launcher_FrontAction_C::ExecuteUbergraph_BP_Launcher_FrontAction(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Launcher_FrontAction_C", "ExecuteUbergraph_BP_Launcher_FrontAction");

	Params::BP_Launcher_FrontAction_C_ExecuteUbergraph_BP_Launcher_FrontAction Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}
