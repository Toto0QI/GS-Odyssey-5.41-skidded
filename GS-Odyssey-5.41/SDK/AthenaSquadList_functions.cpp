#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaSquadList

#include "Basic.hpp"

#include "AthenaSquadList_classes.hpp"
#include "AthenaSquadList_parameters.hpp"


namespace SDK
{

// Function AthenaSquadList.AthenaSquadList_C.ExecuteUbergraph_AthenaSquadList
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSquadList_C::ExecuteUbergraph_AthenaSquadList(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "ExecuteUbergraph_AthenaSquadList");

	Params::AthenaSquadList_C_ExecuteUbergraph_AthenaSquadList Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSquadList.AthenaSquadList_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaSquadList_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaSquadList.AthenaSquadList_C.AppendSquadMember
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortPlayerStateAthena*           PlayerState                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSquadList_C::AppendSquadMember(class AFortPlayerStateAthena* PlayerState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "AppendSquadMember");

	Params::AthenaSquadList_C_AppendSquadMember Parms{};

	Parms.PlayerState = PlayerState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaSquadList.AthenaSquadList_C.RebuildSquadMembersList
// (Public, BlueprintCallable, BlueprintEvent)

void UAthenaSquadList_C::RebuildSquadMembersList()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "RebuildSquadMembersList");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaSquadList.AthenaSquadList_C.ClearSquadMembers
// (Public, BlueprintCallable, BlueprintEvent)

void UAthenaSquadList_C::ClearSquadMembers()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "ClearSquadMembers");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaSquadList.AthenaSquadList_C.HandleSquadMemberDisconnected
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortPlayerStateAthena*           Player                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaSquadList_C::HandleSquadMemberDisconnected(class AFortPlayerStateAthena* Player)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaSquadList_C", "HandleSquadMemberDisconnected");

	Params::AthenaSquadList_C_HandleSquadMemberDisconnected Parms{};

	Parms.Player = Player;

	UObject::ProcessEvent(Func, &Parms);
}

}
