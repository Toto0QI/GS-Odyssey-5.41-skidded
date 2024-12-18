#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Prj_Arrow_Crossbow_Athena

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Prj_Arrow_Crossbow_Athena.B_Prj_Arrow_Crossbow_Athena_C
// 0x0018 (0x07D0 - 0x07B8)
class AB_Prj_Arrow_Crossbow_Athena_C final : public AFortProjectileAthena
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x07B8(0x0008)(Transient, DuplicateTransient)
	class UParticleSystemComponent*               P_Crossbow_Projectile;                             // 0x07C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        HitPlayerEffect;                                   // 0x07C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_Prj_Arrow_Crossbow_Athena(int32 EntryPoint);
	void OnTouched(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const struct FHitResult& HitResult, bool bIsOverlap);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Prj_Arrow_Crossbow_Athena_C">();
	}
	static class AB_Prj_Arrow_Crossbow_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Prj_Arrow_Crossbow_Athena_C>();
	}
};

}

