#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_PlayerShieldDamage_CameraLensEffect

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "B_PlayerHealthDamage_CameraLensEffect_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_PlayerShieldDamage_CameraLensEffect.B_PlayerShieldDamage_CameraLensEffect_C
// 0x0000 (0x03F0 - 0x03F0)
class AB_PlayerShieldDamage_CameraLensEffect_C final : public AB_PlayerHealthDamage_CameraLensEffect_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_B_PlayerShieldDamage_CameraLensEffect_C; // 0x03E8(0x0008)(Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_B_PlayerShieldDamage_CameraLensEffect(int32 EntryPoint);
	void PassParticle_Parameter_Shield(float NewParam);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_PlayerShieldDamage_CameraLensEffect_C">();
	}
	static class AB_PlayerShieldDamage_CameraLensEffect_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_PlayerShieldDamage_CameraLensEffect_C>();
	}
};

}
