#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AutorunLockZone

#include "Basic.hpp"


namespace SDK::Params
{

// Function AutorunLockZone.AutorunLockZone_C.ExecuteUbergraph_AutorunLockZone
// 0x0008 (0x0008 - 0x0000)
struct AutorunLockZone_C_ExecuteUbergraph_AutorunLockZone final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_bNewIsInZone;                         // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function AutorunLockZone.AutorunLockZone_C.OnInZoneChanged
// 0x0001 (0x0001 - 0x0000)
struct AutorunLockZone_C_OnInZoneChanged final
{
public:
	bool                                          bNewIsInZone;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
