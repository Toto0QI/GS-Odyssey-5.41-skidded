#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaMatchStatsScreen

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function AthenaMatchStatsScreen.AthenaMatchStatsScreen_C.ExecuteUbergraph_AthenaMatchStatsScreen
// 0x0028 (0x0028 - 0x0000)
struct AthenaMatchStatsScreen_C_ExecuteUbergraph_AthenaMatchStatsScreen final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_511E[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue;              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AAthena_PlayerController_C*             K2Node_DynamicCast_AsAthena_Player_Controller;     // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_511F[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAthenaPlayerMatchReport*               CallFunc_GetMatchReport_ReturnValue;               // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function AthenaMatchStatsScreen.AthenaMatchStatsScreen_C.RegisterBack
// 0x0020 (0x0020 - 0x0000)
struct AthenaMatchStatsScreen_C_RegisterBack final
{
public:
	TDelegate<void(bool* bPassThrough)>           K2Node_CreateDelegate_OutputDelegate;              // 0x0000(0x0010)(ZeroConstructor, NoDestructor)
	struct FDataTableRowHandle                    K2Node_MakeStruct_DataTableRowHandle;              // 0x0010(0x0010)(NoDestructor)
};

// Function AthenaMatchStatsScreen.AthenaMatchStatsScreen_C.HandleBack
// 0x0010 (0x0010 - 0x0000)
struct AthenaMatchStatsScreen_C_HandleBack final
{
public:
	bool                                          Passthrough;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5120[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortUIManagerWidget_NUI*               CallFunc_GetUIManagerWidget_ReturnValue;           // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function AthenaMatchStatsScreen.AthenaMatchStatsScreen_C.InputRefresh
// 0x0010 (0x0010 - 0x0000)
struct AthenaMatchStatsScreen_C_InputRefresh final
{
public:
	struct FDataTableRowHandle                    K2Node_MakeStruct_DataTableRowHandle;              // 0x0000(0x0010)(NoDestructor)
};

// Function AthenaMatchStatsScreen.AthenaMatchStatsScreen_C.On_BorderTouchZone_MouseButtonDown
// 0x0220 (0x0220 - 0x0000)
struct AthenaMatchStatsScreen_C_On_BorderTouchZone_MouseButtonDown final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          MouseEvent;                                        // 0x0038(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FEventReply                            ReturnValue;                                       // 0x00A8(0x00B8)(Parm, OutParm, ReturnParm)
	bool                                          CallFunc_HandleBack_Passthrough;                   // 0x0160(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5121[0x7];                                     // 0x0161(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FEventReply                            CallFunc_Handled_ReturnValue;                      // 0x0168(0x00B8)()
};

}
