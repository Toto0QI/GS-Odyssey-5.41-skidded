#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ChoiceCardCount

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function ChoiceCardCount.ChoiceCardCount_C.UpdateText
// 0x0070 (0x0070 - 0x0000)
struct ChoiceCardCount_C_UpdateText final
{
public:
	int32                                         InventoryCount;                                    // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5E50[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0008(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0048(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0058(0x0018)()
};

}
