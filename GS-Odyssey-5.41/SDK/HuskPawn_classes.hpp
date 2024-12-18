#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HuskPawn

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "EnemyPawn_Parent_classes.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass HuskPawn.HuskPawn_C
// 0x01A0 (0x21F0 - 0x2050)
#pragma pack(push, 0x1)
class alignas(0x10) AHuskPawn_C : public AEnemyPawn_Parent_C
{
public:
	uint8                                         Pad_45A7[0x7];                                     // 0x2041(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame_HuskPawn_C;                         // 0x2048(0x0008)(Transient, DuplicateTransient)
	int32                                         HitCount;                                          // 0x2050(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LastTakeHitTime;                                   // 0x2054(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          PushFromFlingerSpawn;                              // 0x2058(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45A8[0x7];                                     // 0x2059(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPawn*                              PawnThatSpawnedMe;                                 // 0x2060(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                PawnThatSpawnedMeLocation;                         // 0x2068(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45A9[0x4];                                     // 0x2074(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  TC_HitReactionAdditiveSingleOneShot;               // 0x2078(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_HitReactionAdditiveLoop;                        // 0x2098(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_HitReactionFullBody;                            // 0x20B8(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_HitReactionBlockAll;                            // 0x20D8(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_HitReactionBlockMelee;                          // 0x20F8(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_HitReactionBlockRanged;                         // 0x2118(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          HitReactForMelee;                                  // 0x2138(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          HuskIsInFlingersHand;                              // 0x2139(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          HuskIsAirborne;                                    // 0x213A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45AA[0x1];                                     // 0x213B(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                HuskFlingerHandOffset;                             // 0x213C(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               HuskFlingerHandRotation;                           // 0x2148(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	struct FVector                                HuskFlingerProjectileOffset;                       // 0x2154(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               HuskFlingerProjectileRotation;                     // 0x2160(0x000C)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45AB[0x4];                                     // 0x216C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystem*                        ImpactParticles_Default;                           // 0x2170(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_HumanFlesh;                        // 0x2178(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Wood;                              // 0x2180(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Stone;                             // 0x2188(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Metal;                             // 0x2190(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MeleeImpact_UseSocketTransforms;                   // 0x2198(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45AC[0x7];                                     // 0x2199(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   Impact_MeleeSocket;                                // 0x21A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsHeadshot_HideHead;                               // 0x21A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45AD[0x3];                                     // 0x21A9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PreviousLargestDeathRadius;                        // 0x21AC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Death_Normal_Sound_HuskPawn_C;                     // 0x21B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Death_RedLaser_Sound;                              // 0x21B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        Spawn_Dust_Particles;                              // 0x21C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SafetyTimerDuration;                               // 0x21C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DeathFX_HQ;                                        // 0x21CC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45AE[0x3];                                     // 0x21CD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class USkeletalMeshComponent*                 ShieldSkeletalMesh;                                // 0x21D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AShielderSpringArm_C*                   ShieldArm;                                         // 0x21D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture*                               Diffuse_Texture;                                   // 0x21E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_HuskPawn(int32 EntryPoint);
	void GameplayCue_Damage_Shielded(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Shield_Destroyed(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Shield_Reapplied(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Impact_Physical_Creature(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void PortalCollision(bool Collide_);
	void PortalFX();
	void PortalGet(class ABuildingActor* BuildingActor, const TArray<class ABuildingActor*>& BuildingActorList, class AActor* BT);
	void TakerSoulSuckInterrupted();
	void PortalClear();
	void PortalAdd(class ABuildingActor* BuildingActor, const TArray<class ABuildingActor*>& BuildingActorList);
	void TakerSoulSuckSoundEnd();
	void TakerSoulSuckSoundBegin(bool Success);
	void TakerAttackFSM(bool SuccessfulHit);
	void IsTakerWallPortalAvailable(bool Portal_Available_);
	void TakerWallPortalBehavior(class AActor* BuildingPart, class UBTTask_BlueprintBase* Task, const struct FVector& DesiredMoveLocation, bool Debug);
	void EndTakerSwoopAttack();
	void BeginTakerSwoopAttack();
	void ResetTakerSpecialAttackTimer(bool Swoop, bool SoulSuckMelee, bool Portal);
	void VerifyTakerAttack(bool SpecialAttack, bool Swoop, bool Soul_Suck, bool Portal);
	void HuskEvadeStart();
	void MantleEnd();
	void MantleStart(const struct FVector& StartPos, const struct FVector& MidPos, const struct FVector& EndPos, bool LowWall, bool MidWall, bool FullWall, bool WindowWall);
	void FlingerEnemyDied(class APawn* PawnThatDied);
	void AlertEnemySpawnedByFlinger(const struct FVector& Param_PushMomentum, float PushDuration, class APawn* OwningFlinger);
	void CanFlingerSpawnAnEnemy(class AActor* ActorWhoAsked);
	void FlingerCan_tSpawnAnEnemy();
	void FlingerCanSpawnAnEnemy();
	void FlingerEnemyFailedToSpawn(class AFortProjectileBase* FailedProjectile);
	void FlingerSpawnedAnEnemy(class AFortAIPawn* EnemySpawned, class AFortProjectileBase* ProjectileThatSpawnedThisEnemy);
	void FlingerThrewAProjectileContainingAnEnemy(class AFortProjectileBase* Projectile);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HuskPawn_C">();
	}
	static class AHuskPawn_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AHuskPawn_C>();
	}
};
#pragma pack(pop)

}

