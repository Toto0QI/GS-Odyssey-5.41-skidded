#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCN_Hoverboard_Strait

#include "Basic.hpp"

#include "GCN_Hoverboard_Strait_classes.hpp"
#include "GCN_Hoverboard_Strait_parameters.hpp"


namespace SDK
{

// Function GCN_Hoverboard_Strait.GCN_Hoverboard_Strait_C.ExecuteUbergraph_GCN_Hoverboard_Strait
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGCN_Hoverboard_Strait_C::ExecuteUbergraph_GCN_Hoverboard_Strait(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GCN_Hoverboard_Strait_C", "ExecuteUbergraph_GCN_Hoverboard_Strait");

	Params::GCN_Hoverboard_Strait_C_ExecuteUbergraph_GCN_Hoverboard_Strait Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GCN_Hoverboard_Strait.GCN_Hoverboard_Strait_C.OnActivate
// (BlueprintCallable, BlueprintEvent)

void AGCN_Hoverboard_Strait_C::OnActivate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GCN_Hoverboard_Strait_C", "OnActivate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GCN_Hoverboard_Strait.GCN_Hoverboard_Strait_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AGCN_Hoverboard_Strait_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GCN_Hoverboard_Strait_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GCN_Hoverboard_Strait.GCN_Hoverboard_Strait_C.OnActive
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           MyTarget                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FGameplayCueParameters           Parameters                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, ContainsInstancedReference)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool AGCN_Hoverboard_Strait_C::OnActive(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GCN_Hoverboard_Strait_C", "OnActive");

	Params::GCN_Hoverboard_Strait_C_OnActive Parms{};

	Parms.MyTarget = MyTarget;
	Parms.Parameters = std::move(Parameters);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}
