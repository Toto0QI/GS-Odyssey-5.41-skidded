#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: InputReflectorButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_structs.hpp"
#include "SlateCore_structs.hpp"
#include "CommonInput_structs.hpp"


namespace SDK::Params
{

// Function InputReflectorButton.InputReflectorButton_C.ExecuteUbergraph_InputReflectorButton
// 0x0048 (0x0048 - 0x0000)
struct InputReflectorButton_C_ExecuteUbergraph_InputReflectorButton final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3061[0x2];                                     // 0x0006(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonInputContext*                    CallFunc_GetContext_ReturnValue;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECommonInputType                              CallFunc_GetCurrentInputType_ReturnValue;          // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_HasAnyChildren_ReturnValue;               // 0x0012(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3062[0x5];                                     // 0x0013(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonInputContext*                    CallFunc_GetContext_ReturnValue1;                  // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECommonInputType                              CallFunc_GetCurrentInputType_ReturnValue1;         // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue1;         // 0x0022(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0023(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_bUsingGamepad;          // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3063[0x3];                                     // 0x0025(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDataTableRowHandle                    K2Node_Event_NewTriggeredAction;                   // 0x0028(0x0010)(ConstParm, NoDestructor)
	float                                         K2Node_Event_HeldPercent;                          // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable1;                               // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable2;                               // 0x003D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_SlateBrush_ReturnValue;        // 0x003E(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable3;                               // 0x003F(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              K2Node_Select1_Default;                            // 0x0041(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function InputReflectorButton.InputReflectorButton_C.OnActionProgress
// 0x0004 (0x0004 - 0x0000)
struct InputReflectorButton_C_OnActionProgress final
{
public:
	float                                         HeldPercent;                                       // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function InputReflectorButton.InputReflectorButton_C.OnTriggeredInputActionChanged
// 0x0010 (0x0010 - 0x0000)
struct InputReflectorButton_C_OnTriggeredInputActionChanged final
{
public:
	struct FDataTableRowHandle                    NewTriggeredAction;                                // 0x0000(0x0010)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.BndEvt__CommonActionWidgetAction_K2Node_ComponentBoundEvent_0_OnInputMethodChanged__DelegateSignature
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_BndEvt__CommonActionWidgetAction_K2Node_ComponentBoundEvent_0_OnInputMethodChanged__DelegateSignature final
{
public:
	bool                                          bUsingGamepad;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.Set Text
// 0x0018 (0x0018 - 0x0000)
struct InputReflectorButton_C_Set_Text final
{
public:
	class FText                                   Param_ButtonText;                                  // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function InputReflectorButton.InputReflectorButton_C.Set Icon
// 0x0088 (0x0088 - 0x0000)
struct InputReflectorButton_C_Set_Icon final
{
public:
	struct FSlateBrush                            Param_IconBrush;                                   // 0x0000(0x0088)(BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function InputReflectorButton.InputReflectorButton_C.InitializeButton
// 0x0010 (0x0010 - 0x0000)
struct InputReflectorButton_C_InitializeButton final
{
public:
	class UObject*                                CallFunc_GetBrushResource_ReturnValue;             // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.UpdateTextAndStyle
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_UpdateTextAndStyle final
{
public:
	bool                                          bUsingGamepad;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.SetControllerStyle
// 0x0018 (0x0018 - 0x0000)
struct InputReflectorButton_C_SetControllerStyle final
{
public:
	class UClass*                                 Param_ControllerInputStyle;                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonInputContext*                    CallFunc_GetContext_ReturnValue;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECommonInputType                              CallFunc_GetCurrentInputType_ReturnValue;          // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.UpdateText
// 0x0058 (0x0058 - 0x0000)
struct InputReflectorButton_C_UpdateText final
{
public:
	bool                                          Temp_bool_Variable;                                // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Temp_bool_Variable1;                               // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TextIsEmpty_ReturnValue;                  // 0x0002(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3064[0x5];                                     // 0x0003(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetDisplayText_ReturnValue;               // 0x0008(0x0018)()
	class FText                                   K2Node_Select_Default;                             // 0x0020(0x0018)()
	bool                                          CallFunc_TextIsEmpty_ReturnValue1;                 // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0039(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3065[0x6];                                     // 0x003A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Select1_Default;                            // 0x0040(0x0018)()
};

// Function InputReflectorButton.InputReflectorButton_C.UpdateStyle
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_UpdateStyle final
{
public:
	bool                                          UsingGamepad;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.SetMouseKeyboardStyle
// 0x0018 (0x0018 - 0x0000)
struct InputReflectorButton_C_SetMouseKeyboardStyle final
{
public:
	class UClass*                                 Param_ControllerInputStyle;                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonInputContext*                    CallFunc_GetContext_ReturnValue;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECommonInputType                              CallFunc_GetCurrentInputType_ReturnValue;          // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.UpdateContentAlignment
// 0x0018 (0x0018 - 0x0000)
struct InputReflectorButton_C_UpdateContentAlignment final
{
public:
	class UPanelSlot*                             CallFunc_GetContentSlot_ReturnValue;               // 0x0000(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UBorderSlot*                            K2Node_DynamicCast_AsBorder_Slot;                  // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function InputReflectorButton.InputReflectorButton_C.SetContentAlignment
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_SetContentAlignment final
{
public:
	EHorizontalAlignment                          Param_ContentAlignment;                            // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function InputReflectorButton.InputReflectorButton_C.UpdateTextStyle
// 0x0008 (0x0008 - 0x0000)
struct InputReflectorButton_C_UpdateTextStyle final
{
public:
	class UClass*                                 CallFunc_GetCurrentTextStyleClass_ReturnValue;     // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function InputReflectorButton.InputReflectorButton_C.SetTextInternal
// 0x0020 (0x0020 - 0x0000)
struct InputReflectorButton_C_SetTextInternal final
{
public:
	class FText                                   InButtonText;                                      // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	bool                                          Temp_bool_Variable;                                // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x001A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_TextIsEmpty_ReturnValue;                  // 0x001B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x001C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function InputReflectorButton.InputReflectorButton_C.ShowIcon
// 0x0001 (0x0001 - 0x0000)
struct InputReflectorButton_C_ShowIcon final
{
public:
	bool                                          bShouldShow;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
