#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SpecialEventsCamera_Blueprint

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SpecialEventsCamera_Blueprint.SpecialEventsCamera_Blueprint_C
// 0x0010 (0x0890 - 0x0880)
class ASpecialEventsCamera_Blueprint_C final : public AFortCameraBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0880(0x0008)(Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_SpecialEventsCamera_Blueprint(int32 EntryPoint);
	void OnActivated();
	void OnDeactivated();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SpecialEventsCamera_Blueprint_C">();
	}
	static class ASpecialEventsCamera_Blueprint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASpecialEventsCamera_Blueprint_C>();
	}
};

}
