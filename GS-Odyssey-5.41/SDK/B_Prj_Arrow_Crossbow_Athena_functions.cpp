#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Prj_Arrow_Crossbow_Athena

#include "Basic.hpp"

#include "B_Prj_Arrow_Crossbow_Athena_classes.hpp"
#include "B_Prj_Arrow_Crossbow_Athena_parameters.hpp"


namespace SDK
{

// Function B_Prj_Arrow_Crossbow_Athena.B_Prj_Arrow_Crossbow_Athena_C.ExecuteUbergraph_B_Prj_Arrow_Crossbow_Athena
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AB_Prj_Arrow_Crossbow_Athena_C::ExecuteUbergraph_B_Prj_Arrow_Crossbow_Athena(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Arrow_Crossbow_Athena_C", "ExecuteUbergraph_B_Prj_Arrow_Crossbow_Athena");

	Params::B_Prj_Arrow_Crossbow_Athena_C_ExecuteUbergraph_B_Prj_Arrow_Crossbow_Athena Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Prj_Arrow_Crossbow_Athena.B_Prj_Arrow_Crossbow_Athena_C.OnTouched
// (Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FHitResult                       HitResult                                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)
// bool                                    bIsOverlap                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AB_Prj_Arrow_Crossbow_Athena_C::OnTouched(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const struct FHitResult& HitResult, bool bIsOverlap)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Arrow_Crossbow_Athena_C", "OnTouched");

	Params::B_Prj_Arrow_Crossbow_Athena_C_OnTouched Parms{};

	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.HitResult = std::move(HitResult);
	Parms.bIsOverlap = bIsOverlap;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Prj_Arrow_Crossbow_Athena.B_Prj_Arrow_Crossbow_Athena_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AB_Prj_Arrow_Crossbow_Athena_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Prj_Arrow_Crossbow_Athena_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}
