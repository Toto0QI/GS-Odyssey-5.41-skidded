#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HUDLayoutToolPropertyWidget

#include "Basic.hpp"

#include "HUDLayoutToolPropertyWidget_classes.hpp"
#include "HUDLayoutToolPropertyWidget_parameters.hpp"


namespace SDK
{

// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.ExecuteUbergraph_HUDLayoutToolPropertyWidget
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHUDLayoutToolPropertyWidget_C::ExecuteUbergraph_HUDLayoutToolPropertyWidget(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "ExecuteUbergraph_HUDLayoutToolPropertyWidget");

	Params::HUDLayoutToolPropertyWidget_C_ExecuteUbergraph_HUDLayoutToolPropertyWidget Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.OnRotatorChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Selected_Index                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHUDLayoutToolPropertyWidget_C::OnRotatorChanged(int32 Selected_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "OnRotatorChanged");

	Params::HUDLayoutToolPropertyWidget_C_OnRotatorChanged Parms{};

	Parms.Selected_Index = Selected_Index;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.RefreshProperties
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UHUDLayoutToolPropertyWidget_C::RefreshProperties()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "RefreshProperties");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.BndEvt__Button_BoolToggle_K2Node_ComponentBoundEvent_139_OnButtonPressedEvent__DelegateSignature
// (BlueprintEvent)

void UHUDLayoutToolPropertyWidget_C::BndEvt__Button_BoolToggle_K2Node_ComponentBoundEvent_139_OnButtonPressedEvent__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "BndEvt__Button_BoolToggle_K2Node_ComponentBoundEvent_139_OnButtonPressedEvent__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.SetBoolValue
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bNewValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UHUDLayoutToolPropertyWidget_C::SetBoolValue(bool bNewValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "SetBoolValue");

	Params::HUDLayoutToolPropertyWidget_C_SetBoolValue Parms{};

	Parms.bNewValue = bNewValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HUDLayoutToolPropertyWidget.HUDLayoutToolPropertyWidget_C.SetPropertyType
// (Event, Protected, BlueprintEvent)
// Parameters:
// ELayoutPropertyType                     NewPropertyType                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHUDLayoutToolPropertyWidget_C::SetPropertyType(ELayoutPropertyType NewPropertyType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HUDLayoutToolPropertyWidget_C", "SetPropertyType");

	Params::HUDLayoutToolPropertyWidget_C_SetPropertyType Parms{};

	Parms.NewPropertyType = NewPropertyType;

	UObject::ProcessEvent(Func, &Parms);
}

}
