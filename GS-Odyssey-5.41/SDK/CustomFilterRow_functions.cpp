#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CustomFilterRow

#include "Basic.hpp"

#include "CustomFilterRow_classes.hpp"
#include "CustomFilterRow_parameters.hpp"


namespace SDK
{

// Function CustomFilterRow.CustomFilterRow_C.OnCustomFilterToggled__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// EFortInventoryCustomFilter              Param_Filter                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsChecked                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCustomFilterRow_C::OnCustomFilterToggled__DelegateSignature(EFortInventoryCustomFilter Param_Filter, bool IsChecked)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "OnCustomFilterToggled__DelegateSignature");

	Params::CustomFilterRow_C_OnCustomFilterToggled__DelegateSignature Parms{};

	Parms.Param_Filter = Param_Filter;
	Parms.IsChecked = IsChecked;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CustomFilterRow.CustomFilterRow_C.ExecuteUbergraph_CustomFilterRow
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCustomFilterRow_C::ExecuteUbergraph_CustomFilterRow(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "ExecuteUbergraph_CustomFilterRow");

	Params::CustomFilterRow_C_ExecuteUbergraph_CustomFilterRow Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CustomFilterRow.CustomFilterRow_C.BP_OnClicked
// (Event, Protected, BlueprintEvent)

void UCustomFilterRow_C::BP_OnClicked()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "BP_OnClicked");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CustomFilterRow.CustomFilterRow_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCustomFilterRow_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "PreConstruct");

	Params::CustomFilterRow_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CustomFilterRow.CustomFilterRow_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UCustomFilterRow_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CustomFilterRow.CustomFilterRow_C.SetCheckedState
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsChecked                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCustomFilterRow_C::SetCheckedState(bool IsChecked)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CustomFilterRow_C", "SetCheckedState");

	Params::CustomFilterRow_C_SetCheckedState Parms{};

	Parms.IsChecked = IsChecked;

	UObject::ProcessEvent(Func, &Parms);
}

}
