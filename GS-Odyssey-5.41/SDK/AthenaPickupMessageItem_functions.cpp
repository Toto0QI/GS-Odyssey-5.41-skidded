#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaPickupMessageItem

#include "Basic.hpp"

#include "AthenaPickupMessageItem_classes.hpp"
#include "AthenaPickupMessageItem_parameters.hpp"


namespace SDK
{

// Function AthenaPickupMessageItem.AthenaPickupMessageItem_C.ExecuteUbergraph_AthenaPickupMessageItem
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaPickupMessageItem_C::ExecuteUbergraph_AthenaPickupMessageItem(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaPickupMessageItem_C", "ExecuteUbergraph_AthenaPickupMessageItem");

	Params::AthenaPickupMessageItem_C_ExecuteUbergraph_AthenaPickupMessageItem Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaPickupMessageItem.AthenaPickupMessageItem_C.OnBeginRemove
// (Event, Protected, BlueprintEvent)

void UAthenaPickupMessageItem_C::OnBeginRemove()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaPickupMessageItem_C", "OnBeginRemove");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaPickupMessageItem.AthenaPickupMessageItem_C.OnStackSizeChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   OldStackSize                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaPickupMessageItem_C::OnStackSizeChanged(int32 OldStackSize)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaPickupMessageItem_C", "OnStackSizeChanged");

	Params::AthenaPickupMessageItem_C_OnStackSizeChanged Parms{};

	Parms.OldStackSize = OldStackSize;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AthenaPickupMessageItem.AthenaPickupMessageItem_C.Refresh Count
// (Public, BlueprintCallable, BlueprintEvent)

void UAthenaPickupMessageItem_C::Refresh_Count()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaPickupMessageItem_C", "Refresh Count");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AthenaPickupMessageItem.AthenaPickupMessageItem_C.Setup
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UFortItem*                        Param_Picked_Up_Item                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaPickupMessageItem_C::Setup(class UFortItem* Param_Picked_Up_Item)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AthenaPickupMessageItem_C", "Setup");

	Params::AthenaPickupMessageItem_C_Setup Parms{};

	Parms.Param_Picked_Up_Item = Param_Picked_Up_Item;

	UObject::ProcessEvent(Func, &Parms);
}

}

