#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BasicInteractionWidget

#include "Basic.hpp"

#include "BasicInteractionWidget_classes.hpp"
#include "BasicInteractionWidget_parameters.hpp"


namespace SDK
{

// Function BasicInteractionWidget.BasicInteractionWidget_C.ExecuteUbergraph_BasicInteractionWidget
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBasicInteractionWidget_C::ExecuteUbergraph_BasicInteractionWidget(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BasicInteractionWidget_C", "ExecuteUbergraph_BasicInteractionWidget");

	Params::BasicInteractionWidget_C_ExecuteUbergraph_BasicInteractionWidget Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BasicInteractionWidget.BasicInteractionWidget_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UBasicInteractionWidget_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BasicInteractionWidget_C", "PreConstruct");

	Params::BasicInteractionWidget_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BasicInteractionWidget.BasicInteractionWidget_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UBasicInteractionWidget_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BasicInteractionWidget_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BasicInteractionWidget.BasicInteractionWidget_C.InitBasicInteraction
// (Public, BlueprintCallable, BlueprintEvent)

void UBasicInteractionWidget_C::InitBasicInteraction()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BasicInteractionWidget_C", "InitBasicInteraction");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BasicInteractionWidget.BasicInteractionWidget_C.UpdateDescription
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Param_Description                                      (BlueprintVisible, BlueprintReadOnly, Parm)

void UBasicInteractionWidget_C::UpdateDescription(const class FText& Param_Description)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BasicInteractionWidget_C", "UpdateDescription");

	Params::BasicInteractionWidget_C_UpdateDescription Parms{};

	Parms.Param_Description = std::move(Param_Description);

	UObject::ProcessEvent(Func, &Parms);
}

}
