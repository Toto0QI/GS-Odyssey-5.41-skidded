#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GenericMessageReceived

#include "Basic.hpp"

#include "UMG_structs.hpp"


namespace SDK::Params
{

// Function GenericMessageReceived.GenericMessageReceived_C.ExecuteUbergraph_GenericMessageReceived
// 0x0090 (0x0090 - 0x0000)
struct GenericMessageReceived_C_ExecuteUbergraph_GenericMessageReceived final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2DFE[0x1];                                     // 0x0007(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x0008(0x0018)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue1;             // 0x0020(0x0018)()
	class UFortUINavigationManager*               CallFunc_GetUINavigationManager_ReturnValue;       // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   CallFunc_FormatTextUsingParams_ReturnValue;        // 0x0040(0x0018)()
	class FText                                   CallFunc_FormatTextUsingParams_ReturnValue1;       // 0x0058(0x0018)()
	class UFortUIManagerWidget_NUI*               CallFunc_GetUIManagerWidget_ReturnValue;           // 0x0070(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button;                 // 0x0078(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortFrontEndContext*                   CallFunc_GetContext_ReturnValue;                   // 0x0080(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_HasParam_ReturnValue;                     // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x0089(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GenericMessageReceived.GenericMessageReceived_C.BndEvt__ShowNextButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct GenericMessageReceived_C_BndEvt__ShowNextButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}
