#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Prj_Athena_FragGrenade

#include "Basic.hpp"

#include "B_Prj_Athena_Grenade_Base_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Prj_Athena_FragGrenade.B_Prj_Athena_FragGrenade_C
// 0x0008 (0x0768 - 0x0760)
class AB_Prj_Athena_FragGrenade_C final : public AB_Prj_Athena_Grenade_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_B_Prj_Athena_FragGrenade_C;         // 0x0760(0x0008)(Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_B_Prj_Athena_FragGrenade(int32 EntryPoint);
	void FuseEnded();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Prj_Athena_FragGrenade_C">();
	}
	static class AB_Prj_Athena_FragGrenade_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Prj_Athena_FragGrenade_C>();
	}
};

}
