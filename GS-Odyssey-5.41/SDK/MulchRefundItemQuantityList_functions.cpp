#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MulchRefundItemQuantityList

#include "Basic.hpp"

#include "MulchRefundItemQuantityList_classes.hpp"
#include "MulchRefundItemQuantityList_parameters.hpp"


namespace SDK
{

// Function MulchRefundItemQuantityList.MulchRefundItemQuantityList_C.AddListEntry
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UFortItemQuantityListEntryBase*   ListEntry                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UMulchRefundItemQuantityList_C::AddListEntry(class UFortItemQuantityListEntryBase* ListEntry)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MulchRefundItemQuantityList_C", "AddListEntry");

	Params::MulchRefundItemQuantityList_C_AddListEntry Parms{};

	Parms.ListEntry = ListEntry;

	UObject::ProcessEvent(Func, &Parms);
}


// Function MulchRefundItemQuantityList.MulchRefundItemQuantityList_C.ExecuteUbergraph_MulchRefundItemQuantityList
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UMulchRefundItemQuantityList_C::ExecuteUbergraph_MulchRefundItemQuantityList(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MulchRefundItemQuantityList_C", "ExecuteUbergraph_MulchRefundItemQuantityList");

	Params::MulchRefundItemQuantityList_C_ExecuteUbergraph_MulchRefundItemQuantityList Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}
