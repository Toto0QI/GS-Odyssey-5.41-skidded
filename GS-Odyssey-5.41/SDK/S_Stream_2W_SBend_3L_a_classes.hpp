#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S_Stream_2W_SBend_3L_a

#include "Basic.hpp"

#include "_WaterMeshBlueprintMaster_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass S_Stream_2W_SBend_3L_a.S_Stream_2W_SBend_3L_a_C
// 0x0000 (0x03F0 - 0x03F0)
class AS_Stream_2W_SBend_3L_a_C final : public A_WaterMeshBlueprintMaster_C
{
public:
	bool                                          ShowTestMesh_0;                                    // 0x03EB(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"S_Stream_2W_SBend_3L_a_C">();
	}
	static class AS_Stream_2W_SBend_3L_a_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AS_Stream_2W_SBend_3L_a_C>();
	}
};

}
