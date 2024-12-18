#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AbilityDecoTool_Athena_IntelPack

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AbilityDecoTool_Athena_IntelPack.AbilityDecoTool_Athena_IntelPack_C
// 0x0008 (0x0BB8 - 0x0BB0)
class AAbilityDecoTool_Athena_IntelPack_C final : public AFortCustomizableAbilityDecoTool
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0BB0(0x0008)(Transient, DuplicateTransient)

public:
	void BPPressTrigger(class AFortDecoHelper* FortDecoHelper);
	void ExecuteUbergraph_AbilityDecoTool_Athena_IntelPack(int32 EntryPoint);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AbilityDecoTool_Athena_IntelPack_C">();
	}
	static class AAbilityDecoTool_Athena_IntelPack_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AAbilityDecoTool_Athena_IntelPack_C>();
	}
};

}

