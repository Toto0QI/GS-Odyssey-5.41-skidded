#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AnimNotify_ShielderBuildUp

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AnimNotify_ShielderBuildUp.AnimNotify_ShielderBuildUp_C
// 0x0000 (0x0038 - 0x0038)
class UAnimNotify_ShielderBuildUp_C final : public UAnimNotify
{
public:
	bool Received_Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AnimNotify_ShielderBuildUp_C">();
	}
	static class UAnimNotify_ShielderBuildUp_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAnimNotify_ShielderBuildUp_C>();
	}
};

}

