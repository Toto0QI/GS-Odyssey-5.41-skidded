#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerPawn_Athena

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "PlayerPawn_Athena_Generic_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayerPawn_Athena.PlayerPawn_Athena_C
// 0x0350 (0x2990 - 0x2640)
class APlayerPawn_Athena_C final : public APlayerPawn_Athena_Generic_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_PlayerPawn_Athena_C;                // 0x2640(0x0008)(Transient, DuplicateTransient)
	float                                         TFX_ResOutCharacterMesh_LightIntensity_742226E94F2087597CFE2FAE7DCC91EA; // 0x2648(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_ResOutCharacterMesh_ZHeightParam_742226E94F2087597CFE2FAE7DCC91EA; // 0x264C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_ResOutCharacterMesh_TransitionParam_742226E94F2087597CFE2FAE7DCC91EA; // 0x2650(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            TFX_ResOutCharacterMesh__Direction_742226E94F2087597CFE2FAE7DCC91EA; // 0x2654(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E8F[0x3];                                     // 0x2655(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     TFX_ResOutCharacterMesh;                           // 0x2658(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TFX_GlowCharacterMesh_EmissiveWarp_72A948944C388F740514419F46EFBC56; // 0x2660(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            TFX_GlowCharacterMesh__Direction_72A948944C388F740514419F46EFBC56; // 0x2664(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E90[0x3];                                     // 0x2665(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     TFX_GlowCharacterMesh;                             // 0x2668(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_0_BlendWeight_A4943458400C3662DB243099F9EAC7E8; // 0x2670(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline_0__Direction_A4943458400C3662DB243099F9EAC7E8; // 0x2674(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E91[0x3];                                     // 0x2675(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline_0;                                        // 0x2678(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Storm_Audio_Fader_Volume_8F54E8DB44CB132992E4EBA6F5FAF86B; // 0x2680(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Storm_Audio_Fader__Direction_8F54E8DB44CB132992E4EBA6F5FAF86B; // 0x2684(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E92[0x3];                                     // 0x2685(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Storm_Audio_Fader;                                 // 0x2688(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashTL_LERP_C86EEA494C7B742DC045759B630397B7; // 0x2690(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            LightningFlashTL__Direction_C86EEA494C7B742DC045759B630397B7; // 0x2694(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E93[0x3];                                     // 0x2695(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     LightningFlashTL;                                  // 0x2698(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 TargetHead;                                        // 0x26A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 TargetBody;                                        // 0x26A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UMaterialInterface*>             PawnHeadMaterials_0;                               // 0x26B0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<class UMaterialInterface*>             PawnBodyMaterials_0;                               // 0x26C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	struct FGameplayTagContainer                  TC_FlakVest;                                       // 0x26D0(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayEventData                     Event_Data;                                        // 0x26F0(0x00A8)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                           EventSpawnEffect;                                  // 0x2798(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	bool                                          IsMale;                                            // 0x27A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E94[0x7];                                     // 0x27A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortWeapon*                            MenuGoingCommandowWeapon;                          // 0x27A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             SafeZonePassThroughSound;                          // 0x27B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHasBeenOutsideSafeZone;                           // 0x27B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E95[0x3];                                     // 0x27B9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           ThreatColor;                                       // 0x27BC(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E96[0x4];                                     // 0x27CC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             PlayerKilledSound;                                 // 0x27D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Contrail_A;                                        // 0x27D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bContrailReady;                                    // 0x27E0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E97[0x7];                                     // 0x27E1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystem*                        ActiveContrail;                                    // 0x27E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bLiveContrail;                                     // 0x27F0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E98[0x7];                                     // 0x27F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystemComponent*               Vapor_Effect;                                      // 0x27F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               WindDebrisParticles;                               // 0x2800(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               FallingRainParticles;                              // 0x2808(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LightningSpawnLocation;                            // 0x2810(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningIntensityMin;                             // 0x281C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningIntensityMax;                             // 0x2820(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E99[0x4];                                     // 0x2824(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 SafeZoneActor;                                     // 0x2828(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningIntensity;                                // 0x2830(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E9A[0x4];                                     // 0x2834(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPointLightComponent*                   RandomLightningLight;                              // 0x2838(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningTimelinePlaySpeedMin;                     // 0x2840(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningTimelinePlaySpeedMax;                     // 0x2844(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashDiameter;                            // 0x2848(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashHeight;                              // 0x284C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashRepeatDelayMin;                      // 0x2850(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LightningFlashRepeatDelayMax;                      // 0x2854(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AEmitterCameraLensEffectBase*           RainCameraLensParticles;                           // 0x2858(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         _ChanceOfLightningMesh;                            // 0x2860(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShowInvulnerableVisuals;                           // 0x2864(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E9B[0x3];                                     // 0x2865(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UAudioComponent*                        StormAudioLoop_Inst;                               // 0x2868(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         StormAudioVolume;                                  // 0x2870(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkydiveAudioGroundVolumeScale;                     // 0x2874(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SkydiveMovementVolumeScale;                        // 0x2878(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E9C[0x4];                                     // 0x287C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAudioComponent*                        FallingAudioLoop_Inst;                             // 0x2880(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsPlayingFallingSound;                            // 0x2888(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E9D[0x3];                                     // 0x2889(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PlayerAttributes_Speed_Walk;                       // 0x288C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PlayerAttributes_Speed_Run;                        // 0x2890(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PlayerAttributes_Speed_Sprint;                     // 0x2894(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         MaxTrailsLOD;                                      // 0x2898(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E9E[0x4];                                     // 0x289C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPostProcessComponent*                  MobilePostProcess;                                 // 0x28A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bIsOutsideSafeZoneCached;                          // 0x28A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4E9F[0x7];                                     // 0x28A9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UMaterialInstanceDynamic*>       ResOutMaterials;                                   // 0x28B0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	class ADuplicateResOutMesh_C*                 RezInFXActor;                                      // 0x28C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bQueueRezIn;                                       // 0x28C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4EA0[0x7];                                     // 0x28C9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ADuplicateResOutMesh_C*                 RezOutFXActor;                                     // 0x28D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bQueueRezOut;                                      // 0x28D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          bWasEverInWarmUp;                                  // 0x28D9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bStormAudioCleanedUp;                              // 0x28DA(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4EA1[0x5];                                     // 0x28DB(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             Box_Local_Transform;                               // 0x28E0(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	float                                         BoundsRadius;                                      // 0x2910(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4EA2[0x4];                                     // 0x2914(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPointLightComponent*                   TeleportationPointLight;                           // 0x2918(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxLightIntensity;                                 // 0x2920(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4EA3[0x4];                                     // 0x2924(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   Socket_MeshTop;                                    // 0x2928(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   Socket_MeshBot;                                    // 0x2930(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_Transition;                               // 0x2938(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_DissolvePercent;                          // 0x2940(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_DissolveDirection;                        // 0x2948(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_DissolveBaseLoc;                          // 0x2950(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_DissolveDistance;                         // 0x2958(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   MIDParam_DissolveFirstSpawn;                       // 0x2960(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     Mat_CharacterDissolve;                             // 0x2968(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UMaterialInstanceDynamic*>       DissolveMIDs;                                      // 0x2970(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                          bUseNewTeleportFX;                                 // 0x2980(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_PlayerPawn_Athena(int32 EntryPoint);
	void PlayResOutFX();
	void PlayResInFX();
	void OnResInDuringWarmup();
	void PlayResOut();
	void OnCharacterCustomizationCompleted(class AFortPlayerPawn* Pawn);
	void OnEnteredReplayRelevancy();
	void OnLeftReplayRelevancy();
	void OnSignificantTick(float Significance);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void NotifyTeammateSkydivedFromBus();
	void OnExitedWaterVolume();
	void OnEnteredWaterVolume();
	void Update_Parachute_and_Falling_Audio();
	void Start_Storm_Audio_Fader();
	void Play_Lightning_Flash_Audio(const struct FVector& Location);
	void Remove_Storm_Audio();
	void Add_Storm_Audio();
	void UpdateInvulnerableVisuals();
	void GameplayCue_Abilities_Activation_DBNOResurrect(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void ZapFX(int32 ZapCount);
	void RandomLightningFlashesRepeat();
	void StartRandomLightningFlashes();
	void RemoveStormFX();
	void AddStormFX();
	void GameplayCue_Athena_Player_BeingRevivedFromDBNO(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void ContrailCheck();
	void OnDeathPlayEffects(float Damage, const struct FGameplayTagContainer& DamageTags, const struct FVector& Momentum, const struct FHitResult& HitInfo, class AFortPawn* InstigatedBy, class AActor* DamageCauser, const struct FGameplayEffectContextHandle& EffectContext);
	void GameplayCue_Athena_Equipping(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void SafeZoneStatusChanged();
	void GameplayCue_Athena_OutsideSafeZone(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void ReceiveDestroyed();
	void ReceiveBeginPlay();
	void ReceivePossessed(class AController* NewController);
	void GameplayCue_Abilities_Activation_Generic_HarvestBuff_Tier2(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Abilities_Activation_Generic_HarvestBuff_Tier1(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void TFX_ResOutCharacterMesh__UpdateFunc();
	void TFX_ResOutCharacterMesh__FinishedFunc();
	void TFX_GlowCharacterMesh__UpdateFunc();
	void TFX_GlowCharacterMesh__FinishedFunc();
	void Timeline_0__UpdateFunc();
	void Timeline_0__FinishedFunc();
	void Storm_Audio_Fader__UpdateFunc();
	void Storm_Audio_Fader__FinishedFunc();
	void LightningFlashTL__UpdateFunc();
	void LightningFlashTL__FinishedFunc();
	void UserConstructionScript();
	void InitAthenaFoleyAudio();
	void GetLocationInCircle_XY(struct FVector* LocationLocalSpace);
	void GetParachuteMovementVolumeScale(float* Scale);
	void ApplyParachuteMovementVolumeScale();
	void HandleWaterFX();
	void EnableWaterAudio(bool Is_Entering_Water);
	void StopLoopingAudio();
	void InWarmUp(bool* Param_InWarmUp);
	void OnStartLongInteract(class AActor* ReceivingActor, bool* Out_bConsumeEvent, bool* Out_bSkipSetInteractDuration, bool* Out_bSkipStartAnimation);
	void OnOpenParachute(bool* bConsumeEvent);
	void QueueTeleportIn();
	void QueueTeleportOut();
	void FindBounds();
	void SpawnTeleportationLight();
	void UpdateDissolveFX(float Scalar_Transition, float Scalar_ZHeight, float Scalar_LightIntensity);
	void GetDissolveValues(float ZheightNormScalar, float* DissolveGradientDistance, struct FVector* WorldDissolveLocation, struct FLinearColor* DissolveGradientDirectionColor, struct FLinearColor* DissolveGradientBaseLocColor);
	void UpdateTeleportationPointLight(const struct FVector& NewWorldLoc, float IntensityScalar);
	void SetupDissolveFX();
	void RestoreCharacterMats();
	void UpdatePreDissolve(float GlowScalar);
	void CleanUpTeleportationFXLight();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayerPawn_Athena_C">();
	}
	static class APlayerPawn_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APlayerPawn_Athena_C>();
	}
};

}

