#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaSpectatorNameplateLayer

#include "Basic.hpp"


namespace SDK::Params
{

// Function AthenaSpectatorNameplateLayer.AthenaSpectatorNameplateLayer_C.ExecuteUbergraph_AthenaSpectatorNameplateLayer
// 0x0028 (0x0028 - 0x0000)
struct AthenaSpectatorNameplateLayer_C_ExecuteUbergraph_AthenaSpectatorNameplateLayer final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B01[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAthenaSpectatorNameplateBase*          K2Node_Event_NameplateWidget1;                     // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAthenaSpectatorNameplateBase*          K2Node_Event_NameplateWidget;                      // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortActorCanvasSlot*                   CallFunc_AddActorIndicator_ReturnValue;            // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_RemoveChild_ReturnValue;                  // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function AthenaSpectatorNameplateLayer.AthenaSpectatorNameplateLayer_C.AddNameplate
// 0x0008 (0x0008 - 0x0000)
struct AthenaSpectatorNameplateLayer_C_AddNameplate final
{
public:
	class UAthenaSpectatorNameplateBase*          NameplateWidget;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function AthenaSpectatorNameplateLayer.AthenaSpectatorNameplateLayer_C.RemoveNameplate
// 0x0008 (0x0008 - 0x0000)
struct AthenaSpectatorNameplateLayer_C_RemoveNameplate final
{
public:
	class UAthenaSpectatorNameplateBase*          NameplateWidget;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}
