#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PlayerEmblemAndXp

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "UMG_structs.hpp"


namespace SDK::Params
{

// Function PlayerEmblemAndXp.PlayerEmblemAndXp_C.ExecuteUbergraph_PlayerEmblemAndXp
// 0x0038 (0x0038 - 0x0000)
struct PlayerEmblemAndXp_C_ExecuteUbergraph_PlayerEmblemAndXp final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFortPublicAccountInfo                 K2Node_Event_Result;                               // 0x0004(0x0034)(ConstParm, NoDestructor)
};

// Function PlayerEmblemAndXp.PlayerEmblemAndXp_C.OnAccountInfoChanged
// 0x0034 (0x0034 - 0x0000)
struct PlayerEmblemAndXp_C_OnAccountInfoChanged final
{
public:
	struct FFortPublicAccountInfo                 Result;                                            // 0x0000(0x0034)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)
};

// Function PlayerEmblemAndXp.PlayerEmblemAndXp_C.Refresh
// 0x0128 (0x0128 - 0x0000)
struct PlayerEmblemAndXp_C_Refresh final
{
public:
	struct FFortPublicAccountInfo                 FortPublicAccountInfo;                             // 0x0000(0x0034)(BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0034(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0035(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5537[0x2];                                     // 0x0036(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UAthenaAccountContext*                  CallFunc_GetContext_ReturnValue;                   // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAthenaAccountContext*                  CallFunc_GetContext_ReturnValue1;                  // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetCurrentSeasonNumber_ReturnValue;       // 0x0048(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5538[0x4];                                     // 0x004C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetCurrentSeasonName_ReturnValue;         // 0x0050(0x0018)()
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5539[0x7];                                     // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_TextToUpper_ReturnValue;                  // 0x0070(0x0018)()
	bool                                          Temp_bool_Variable;                                // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_553A[0x7];                                     // 0x0089(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFortItemQuantityPair                  CallFunc_GetNextSeasonReward_Reward;               // 0x0090(0x0040)()
	int32                                         CallFunc_GetNextSeasonReward_RewardLevel;          // 0x00D0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GetNextSeasonReward_ReturnValue;          // 0x00D4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x00D5(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_553B[0x2];                                     // 0x00D6(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x00D8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_553C[0x4];                                     // 0x00DC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFortItemQuantityPair                  CallFunc_GetNextSeasonChaseReward_Reward;          // 0x00E0(0x0040)()
	int32                                         CallFunc_GetNextSeasonChaseReward_RewardLevel;     // 0x0120(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GetNextSeasonChaseReward_ReturnValue;     // 0x0124(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function PlayerEmblemAndXp.PlayerEmblemAndXp_C.SetupReward
// 0x0088 (0x0088 - 0x0000)
struct PlayerEmblemAndXp_C_SetupReward final
{
public:
	class UWidget*                                Container;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTextBlock*                             RewardText;                                        // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDailyQuestRewardInfo_C*                RewardInfoWidget;                                  // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasReward;                                         // 0x0018(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_553D[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFortItemQuantityPair                  RewardItem;                                        // 0x0020(0x0040)(BlueprintVisible, BlueprintReadOnly, Parm)
	int32                                         LevelRewarded;                                     // 0x0060(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0064(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_553E[0x3];                                     // 0x0065(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_IntToText_ReturnValue;               // 0x0068(0x0018)()
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0081(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0082(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x0083(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}
