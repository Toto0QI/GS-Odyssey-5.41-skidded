#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemReceivedAccountWidget

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function ItemReceivedAccountWidget.ItemReceivedAccountWidget_C.ExecuteUbergraph_ItemReceivedAccountWidget
// 0x00A0 (0x00A0 - 0x0000)
struct ItemReceivedAccountWidget_C_ExecuteUbergraph_ItemReceivedAccountWidget final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFortPublicAccountInfo                 K2Node_Event_Result;                               // 0x0004(0x0034)(ConstParm, NoDestructor)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0038(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0078(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0088(0x0018)()
};

// Function ItemReceivedAccountWidget.ItemReceivedAccountWidget_C.OnAccountInfoChanged
// 0x0034 (0x0034 - 0x0000)
struct ItemReceivedAccountWidget_C_OnAccountInfoChanged final
{
public:
	struct FFortPublicAccountInfo                 Result;                                            // 0x0000(0x0034)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)
};

}
