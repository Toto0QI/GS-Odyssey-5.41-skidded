#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCL_Carmine_Jump_Trails

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function GCL_Carmine_Jump_Trails.GCL_Carmine_Jump_Trails_C.ExecuteUbergraph_GCL_Carmine_Jump_Trails
// 0x0008 (0x0008 - 0x0000)
struct GCL_Carmine_Jump_Trails_C_ExecuteUbergraph_GCL_Carmine_Jump_Trails final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EEndPlayReason                                K2Node_Event_EndPlayReason;                        // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GCL_Carmine_Jump_Trails.GCL_Carmine_Jump_Trails_C.ReceiveEndPlay
// 0x0001 (0x0001 - 0x0000)
struct GCL_Carmine_Jump_Trails_C_ReceiveEndPlay final
{
public:
	EEndPlayReason                                EndPlayReason;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}
