#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_CameraLens_Cube_Area

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_CameraLens_Cube_Area.B_CameraLens_Cube_Area_C
// 0x0020 (0x0400 - 0x03E0)
class AB_CameraLens_Cube_Area_C final : public AEmitterCameraLensEffectBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03E0(0x0008)(Transient, DuplicateTransient)
	class AActor*                                 VelocityActor;                                     // 0x03E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                TargetRot;                                         // 0x03F0(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_CameraLens_Cube_Area(int32 EntryPoint);
	void ReceiveBeginPlay();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_CameraLens_Cube_Area_C">();
	}
	static class AB_CameraLens_Cube_Area_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_CameraLens_Cube_Area_C>();
	}
};

}
