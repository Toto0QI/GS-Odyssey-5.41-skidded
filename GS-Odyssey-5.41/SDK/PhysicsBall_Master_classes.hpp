#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PhysicsBall_Master

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PhysicsBall_Master.PhysicsBall_Master_C
// 0x00B0 (0x07E8 - 0x0738)
class APhysicsBall_Master_C : public AFortPhysicsBall
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0738(0x0008)(Transient, DuplicateTransient)
	class UStaticMeshComponent*                   Ball;                                              // 0x0740(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UFortVehicleAudioVoice*                 RollingAudio;                                      // 0x0748(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UFortCollisionAudioComponent*           FortCollisionAudio;                                // 0x0750(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UProjectileMovementComponent*           ProjectileMovement;                                // 0x0758(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         VelocityHitMagMultiplier;                          // 0x0760(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HitPitch;                                          // 0x0764(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SpeedToRotationRateRatio;                          // 0x0768(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LastVelocity;                                      // 0x076C(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DamageHitMagMultiplier;                            // 0x0778(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HitMagMax;                                         // 0x077C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             BallHitSound;                                      // 0x0780(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                OtherVelocity;                                     // 0x0788(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                OtherLocation;                                     // 0x0794(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MinAngularPower;                                   // 0x07A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HitOtherBall;                                      // 0x07A4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          HitOtherPawn;                                      // 0x07A5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          ServerAuthoritative;                               // 0x07A6(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          PlotTrajectory;                                    // 0x07A7(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor)
	struct FVector                                Debug_LastPosition;                                // 0x07A8(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                InitialSpawnPosition;                              // 0x07B4(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          EverCameToRest;                                    // 0x07C0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_32A1[0x3];                                     // 0x07C1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         BounceCount;                                       // 0x07C4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               GenericImpactFX;                                   // 0x07C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               WaterImpactFX;                                     // 0x07D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DustRadius;                                        // 0x07D8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                DustSize;                                          // 0x07DC(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_PhysicsBall_Master(int32 EntryPoint);
	void OnPawnTouchedMe(class APawn* TouchingPawn);
	void BndEvt__SphereCollision_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void DrawDebugTrajectory();
	void ReplicateKick(const struct FVector& HitLocation, const struct FVector& HitVelocity, class AActor* HitActor);
	void OnReplicatedVelocityStartOrStop(bool bStart);
	void ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, const struct FVector& HitLocation, const struct FVector& HitNormal, const struct FVector& NormalImpulse, const struct FHitResult& Hit);
	void ProjectileStop(const struct FHitResult& ImpactResult);
	void ReceiveBeginPlay();
	void ReceiveTick(float DeltaSeconds);
	void UserConstructionScript();
	void UpdateDirectionAndRotationRate(float DeltaSeconds);
	void ApplyImpulseToBall(const struct FVector& HitLocation, const struct FVector& HitVelocity, float HitMagnitude);
	void SetTickingEnabled(bool ShouldTick);
	float GetHitScale(const struct FVector& HitLocation, const struct FVector& HitVelocity);
	void OnRep_PlotTrajectory();
	void SetBallVelocityAndStartTicking(const struct FVector& NewVelocity);
	void MakeBallDormant();
	void ImpactFX(class AActor* HitActor, const struct FVector& SpawnLocation, bool Overlap_);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PhysicsBall_Master_C">();
	}
	static class APhysicsBall_Master_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APhysicsBall_Master_C>();
	}
};

}
