#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PieChartRowWidget

#include "Basic.hpp"

#include "PieChartRowWidget_classes.hpp"
#include "PieChartRowWidget_parameters.hpp"


namespace SDK
{

// Function PieChartRowWidget.PieChartRowWidget_C.Setup
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Param_Num                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FText                             Param_Name                                             (BlueprintVisible, BlueprintReadOnly, Parm)
// float                                   Param_Value                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ECommonNumericType                      NumericType                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FLinearColor                     LegendColor                                            (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPieChartRowWidget_C::Setup(int32 Param_Num, const class FText& Param_Name, float Param_Value, ECommonNumericType NumericType, const struct FLinearColor& LegendColor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PieChartRowWidget_C", "Setup");

	Params::PieChartRowWidget_C_Setup Parms{};

	Parms.Param_Num = Param_Num;
	Parms.Param_Name = std::move(Param_Name);
	Parms.Param_Value = Param_Value;
	Parms.NumericType = NumericType;
	Parms.LegendColor = std::move(LegendColor);

	UObject::ProcessEvent(Func, &Parms);
}

}
