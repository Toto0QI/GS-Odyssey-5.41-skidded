#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ProjectileTrajectory_Athena_SnapToGridArrow

#include "Basic.hpp"

#include "BP_ProjectileTrajectory_Athena_SnapToGridArrow_classes.hpp"
#include "BP_ProjectileTrajectory_Athena_SnapToGridArrow_parameters.hpp"


namespace SDK
{

// Function BP_ProjectileTrajectory_Athena_SnapToGridArrow.BP_ProjectileTrajectory_Athena_SnapToGridArrow_C.ExecuteUbergraph_BP_ProjectileTrajectory_Athena_SnapToGridArrow
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_ProjectileTrajectory_Athena_SnapToGridArrow_C::ExecuteUbergraph_BP_ProjectileTrajectory_Athena_SnapToGridArrow(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ProjectileTrajectory_Athena_SnapToGridArrow_C", "ExecuteUbergraph_BP_ProjectileTrajectory_Athena_SnapToGridArrow");

	Params::BP_ProjectileTrajectory_Athena_SnapToGridArrow_C_ExecuteUbergraph_BP_ProjectileTrajectory_Athena_SnapToGridArrow Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ProjectileTrajectory_Athena_SnapToGridArrow.BP_ProjectileTrajectory_Athena_SnapToGridArrow_C.SetTrajectorySpline
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<struct FVector>                  SplinePoints                                           (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// TArray<struct FVector>                  SplineTangents                                         (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)

void ABP_ProjectileTrajectory_Athena_SnapToGridArrow_C::SetTrajectorySpline(TArray<struct FVector>& SplinePoints, TArray<struct FVector>& SplineTangents)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ProjectileTrajectory_Athena_SnapToGridArrow_C", "SetTrajectorySpline");

	Params::BP_ProjectileTrajectory_Athena_SnapToGridArrow_C_SetTrajectorySpline Parms{};

	Parms.SplinePoints = std::move(SplinePoints);
	Parms.SplineTangents = std::move(SplineTangents);

	UObject::ProcessEvent(Func, &Parms);

	SplinePoints = std::move(Parms.SplinePoints);
	SplineTangents = std::move(Parms.SplineTangents);
}


// Function BP_ProjectileTrajectory_Athena_SnapToGridArrow.BP_ProjectileTrajectory_Athena_SnapToGridArrow_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_ProjectileTrajectory_Athena_SnapToGridArrow_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ProjectileTrajectory_Athena_SnapToGridArrow_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ProjectileTrajectory_Athena_SnapToGridArrow.BP_ProjectileTrajectory_Athena_SnapToGridArrow_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void ABP_ProjectileTrajectory_Athena_SnapToGridArrow_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ProjectileTrajectory_Athena_SnapToGridArrow_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ProjectileTrajectory_Athena_SnapToGridArrow.BP_ProjectileTrajectory_Athena_SnapToGridArrow_C.HandleGridSnapUpdates
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          NewLocation                                            (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_ProjectileTrajectory_Athena_SnapToGridArrow_C::HandleGridSnapUpdates(const struct FVector& NewLocation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ProjectileTrajectory_Athena_SnapToGridArrow_C", "HandleGridSnapUpdates");

	Params::BP_ProjectileTrajectory_Athena_SnapToGridArrow_C_HandleGridSnapUpdates Parms{};

	Parms.NewLocation = std::move(NewLocation);

	UObject::ProcessEvent(Func, &Parms);
}

}
