#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GCNL_GM_Fury

#include "Basic.hpp"

#include "GameplayAbilities_structs.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function GCNL_GM_Fury.GCNL_GM_Fury_C.ExecuteUbergraph_GCNL_GM_Fury
// 0x0050 (0x0050 - 0x0000)
struct GCNL_GM_Fury_C_ExecuteUbergraph_GCNL_GM_Fury final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44CF[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 K2Node_CustomEvent_DeadActor;                      // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_CustomEvent_Damage;                         // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44D0[0x4];                                     // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPawn*                              K2Node_CustomEvent_InstigatedBy;                   // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                K2Node_CustomEvent_HitLocation;                    // 0x0020(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44D1[0x4];                                     // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 K2Node_CustomEvent_DamageCauser;                   // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class AActor* DeadActor, float Damage, class AFortPawn* InstigatedBy, const struct FVector& HitLocation, class AActor* DamageCauser)> K2Node_CreateDelegate_OutputDelegate;              // 0x0038(0x0010)(ZeroConstructor, NoDestructor)
	class AEnemyPawn_Parent_C*                    K2Node_CustomEvent_EnemyPawnParentReference;       // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GCNL_GM_Fury.GCNL_GM_Fury_C.OnEnemyDeath
// 0x0030 (0x0030 - 0x0000)
struct GCNL_GM_Fury_C_OnEnemyDeath final
{
public:
	class AActor*                                 DeadActor;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Damage;                                            // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44D2[0x4];                                     // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPawn*                              InstigatedBy;                                      // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                HitLocation;                                       // 0x0018(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44D3[0x4];                                     // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 DamageCauser;                                      // 0x0028(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GCNL_GM_Fury.GCNL_GM_Fury_C.BindOnDied
// 0x0008 (0x0008 - 0x0000)
struct GCNL_GM_Fury_C_BindOnDied final
{
public:
	class AEnemyPawn_Parent_C*                    EnemyPawnParentReference;                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function GCNL_GM_Fury.GCNL_GM_Fury_C.OnActive
// 0x0170 (0x0170 - 0x0000)
struct GCNL_GM_Fury_C_OnActive final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x00B8)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, ContainsInstancedReference)
	bool                                          ReturnValue;                                       // 0x00C0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_44D4[0x7];                                     // 0x00C1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AEnemyPawn_Parent_C*                    K2Node_DynamicCast_AsEnemy_Pawn_Parent;            // 0x00C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x00D0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_44D5[0xF];                                     // 0x00D1(0x000F)(Fixing Size After Last Property [ Dumper-7 ])
	struct FParticleSysParam                      K2Node_MakeStruct_ParticleSysParam;                // 0x00E0(0x0080)(IsPlainOldData, NoDestructor)
	TArray<struct FParticleSysParam>              K2Node_MakeArray_Array;                            // 0x0160(0x0010)(ZeroConstructor, ReferenceParm)
};

// Function GCNL_GM_Fury.GCNL_GM_Fury_C.DisableFuryPS
// 0x0001 (0x0001 - 0x0000)
struct GCNL_GM_Fury_C_DisableFuryPS final
{
public:
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
