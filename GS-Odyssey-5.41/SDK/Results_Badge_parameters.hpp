#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Results_Badge

#include "Basic.hpp"


namespace SDK::Params
{

// Function Results_Badge.Results_Badge_C.ExecuteUbergraph_Results_Badge
// 0x0008 (0x0008 - 0x0000)
struct Results_Badge_C_ExecuteUbergraph_Results_Badge final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanOR_ReturnValue;                    // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue1;                   // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue2;                   // 0x0007(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_Badge.Results_Badge_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct Results_Badge_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_Badge.Results_Badge_C.SetItem
// 0x0030 (0x0030 - 0x0000)
struct Results_Badge_C_SetItem final
{
public:
	class UFortItem*                              Item;                                              // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   CallFunc_GetDisplayName_ReturnValue;               // 0x0008(0x0018)()
	class UFortItemDefinition*                    CallFunc_GetItemDefinitionBP_ReturnValue;          // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_Badge.Results_Badge_C.HasValidItem
// 0x0002 (0x0002 - 0x0000)
struct Results_Badge_C_HasValidItem final
{
public:
	bool                                          Param_HasValidItem;                                // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_Badge.Results_Badge_C.Initialize
// 0x0004 (0x0004 - 0x0000)
struct Results_Badge_C_Initialize final
{
public:
	float                                         Param_PlayRate;                                    // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function Results_Badge.Results_Badge_C.SetSkippingToEnd
// 0x0030 (0x0030 - 0x0000)
struct Results_Badge_C_SetSkippingToEnd final
{
public:
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UWidgetAnimation*>               K2Node_MakeArray_Array;                            // 0x0008(0x0010)(ZeroConstructor, ReferenceParm)
	class UWidgetAnimation*                       CallFunc_Array_Get_Item;                           // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsAnimationPlaying_ReturnValue;           // 0x0025(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3843[0x2];                                     // 0x0026(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function Results_Badge.Results_Badge_C.DoDesignTimeRandomization
// 0x00A0 (0x00A0 - 0x0000)
struct Results_Badge_C_DoDesignTimeRandomization final
{
public:
	int32                                         Temp_int_Variable;                                 // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3844[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Temp_text_Variable;                                // 0x0008(0x0018)()
	class FText                                   Temp_text_Variable1;                               // 0x0020(0x0018)()
	class FText                                   Temp_text_Variable2;                               // 0x0038(0x0018)()
	class FText                                   Temp_text_Variable3;                               // 0x0050(0x0018)()
	int32                                         CallFunc_RandomInteger_ReturnValue;                // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3845[0x4];                                     // 0x006C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0070(0x0018)()
	class FText                                   K2Node_Select_Default;                             // 0x0088(0x0018)()
};

}
