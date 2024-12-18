#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaBroadcastScoreboardListView

#include "Basic.hpp"

#include "CommonInput_structs.hpp"


namespace SDK::Params
{

// Function AthenaBroadcastScoreboardListView.AthenaBroadcastScoreboardListView_C.ExecuteUbergraph_AthenaBroadcastScoreboardListView
// 0x0010 (0x0010 - 0x0000)
struct AthenaBroadcastScoreboardListView_C_ExecuteUbergraph_AthenaBroadcastScoreboardListView final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3F90[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                K2Node_ComponentBoundEvent_Item;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function AthenaBroadcastScoreboardListView.AthenaBroadcastScoreboardListView_C.BndEvt__List_K2Node_ComponentBoundEvent_1_SimpleListItemEventDynamic__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct AthenaBroadcastScoreboardListView_C_BndEvt__List_K2Node_ComponentBoundEvent_1_SimpleListItemEventDynamic__DelegateSignature final
{
public:
	class UObject*                                Item;                                              // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function AthenaBroadcastScoreboardListView.AthenaBroadcastScoreboardListView_C.ResetFocus
// 0x0020 (0x0020 - 0x0000)
struct AthenaBroadcastScoreboardListView_C_ResetFocus final
{
public:
	class UAthenaSpectatorScoreboardRowData*      RowToSelect;                                       // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonInputContext*                    CallFunc_GetContext_ReturnValue;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetIndexForItem_ReturnValue;              // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECommonInputType                              CallFunc_GetCurrentInputType_ReturnValue;          // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0015(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0016(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3F91[0x1];                                     // 0x0017(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_SelectInt_ReturnValue;                    // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

