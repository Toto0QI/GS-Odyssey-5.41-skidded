#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaEventMatchStatusScreen

#include "Basic.hpp"


namespace SDK::Params
{

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.ExecuteUbergraph_AthenaEventMatchStatusScreen
// 0x0300 (0x0300 - 0x0000)
struct AthenaEventMatchStatusScreen_C_ExecuteUbergraph_AthenaEventMatchStatusScreen final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3911[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x0008(0x0018)()
	class FText                                   K2Node_Event_DamageHealedText;                     // 0x0020(0x0018)(ConstParm)
	class FText                                   K2Node_Event_DamageInflictedText;                  // 0x0038(0x0018)(ConstParm)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0050(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3912[0x4];                                     // 0x005C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Event_ChestsLootedText;                     // 0x0060(0x0018)(ConstParm)
	int32                                         Temp_int_Array_Index_Variable1;                    // 0x0078(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable1;                   // 0x007C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue1;                  // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3913[0x4];                                     // 0x0084(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Event_DamageTakenText;                      // 0x0088(0x0018)(ConstParm)
	class FText                                   K2Node_Event_LongestEliminationText;               // 0x00A0(0x0018)(ConstParm)
	class FText                                   K2Node_Event_MatchTimeText;                        // 0x00B8(0x0018)(ConstParm)
	class FText                                   K2Node_Event_MostKillsScore;                       // 0x00D0(0x0018)(ConstParm)
	class FText                                   K2Node_Event_PiecesBuiltText;                      // 0x00E8(0x0018)(ConstParm)
	class FText                                   K2Node_Event_LongestEliminationScore;              // 0x0100(0x0018)(ConstParm)
	class FText                                   K2Node_Event_GamePhaseTimeText;                    // 0x0118(0x0018)(ConstParm)
	class FText                                   K2Node_Event_CircleRadiusText;                     // 0x0130(0x0018)(ConstParm)
	class FText                                   K2Node_Event_GamePhaseTimeTitleText;               // 0x0148(0x0018)(ConstParm)
	class FText                                   K2Node_Event_PiecesDestroyedText;                  // 0x0160(0x0018)(ConstParm)
	class FText                                   CallFunc_MakeLiteralText_ReturnValue1;             // 0x0178(0x0018)()
	class FText                                   K2Node_Event_MostKillsText;                        // 0x0190(0x0018)(ConstParm)
	class FText                                   K2Node_Event_PlayersRemainingText;                 // 0x01A8(0x0018)(ConstParm)
	class FText                                   K2Node_Event_TimeSinceLastKillText;                // 0x01C0(0x0018)(ConstParm)
	class FText                                   K2Node_Event_GamePhaseText;                        // 0x01D8(0x0018)(ConstParm)
	int32                                         Temp_int_Loop_Counter_Variable2;                   // 0x01F0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue2;                  // 0x01F4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UAthenaMatchStatusTextPlayer_C*> K2Node_MakeArray_Array;                            // 0x01F8(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   K2Node_Event_ShotsFiredText;                       // 0x0208(0x0018)(ConstParm)
	class UAthenaMatchStatusTextPlayer_C*         CallFunc_Array_Get_Item;                           // 0x0220(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0228(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable2;                    // 0x022C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0230(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3914[0x7];                                     // 0x0231(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAthenaRemotePlayerViewData*            K2Node_Event_InPlayerData;                         // 0x0238(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_bInIsDead;                            // 0x0240(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0241(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3915[0x6];                                     // 0x0242(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_GetPlayerName_ReturnValue;                // 0x0248(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0258(0x0018)()
	class FText                                   K2Node_Event_FastestKillText;                      // 0x0270(0x0018)(ConstParm)
	class FText                                   K2Node_Event_FastestKillTime;                      // 0x0288(0x0018)(ConstParm)
	TArray<class UAthenaMatchStatusTextPlayer_C*> K2Node_MakeArray_Array1;                           // 0x02A0(0x0010)(ZeroConstructor, ReferenceParm)
	class UAthenaMatchStatusTextPlayer_C*         CallFunc_Array_Get_Item1;                          // 0x02B0(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue1;                // 0x02B8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue1;                 // 0x02BC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_TextText_ReturnValue;          // 0x02BD(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3916[0x2];                                     // 0x02BE(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Event_SupplyDropsLootedText;                // 0x02C0(0x0018)(ConstParm)
	TArray<class UAthenaEventMatchStatusText_C*>  K2Node_MakeArray_Array2;                           // 0x02D8(0x0010)(ZeroConstructor, ReferenceParm)
	int32                                         CallFunc_Array_Length_ReturnValue2;                // 0x02E8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3917[0x4];                                     // 0x02EC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAthenaEventMatchStatusText_C*          CallFunc_Array_Get_Item2;                          // 0x02F0(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue2;                 // 0x02F8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.OnPlayerDeadStateChanged_BP
// 0x0010 (0x0010 - 0x0000)
struct AthenaEventMatchStatusScreen_C_OnPlayerDeadStateChanged_BP final
{
public:
	class UAthenaRemotePlayerViewData*            InPlayerData;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bInIsDead;                                         // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateGamePhaseText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateGamePhaseText final
{
public:
	class FText                                   GamePhaseText;                                     // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateTimeSinceLastKillText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateTimeSinceLastKillText final
{
public:
	class FText                                   TimeSinceLastKillText;                             // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdatePlayersRemainingText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdatePlayersRemainingText final
{
public:
	class FText                                   PlayersRemainingText;                              // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateGamePhaseTimeTitleText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateGamePhaseTimeTitleText final
{
public:
	class FText                                   GamePhaseTimeTitleText;                            // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateGamePhaseTimeText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateGamePhaseTimeText final
{
public:
	class FText                                   GamePhaseTimeText;                                 // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateLongestEliminationScore
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateLongestEliminationScore final
{
public:
	class FText                                   Param_LongestEliminationScore;                     // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateMostKillsScore
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateMostKillsScore final
{
public:
	class FText                                   MostKillsScore;                                    // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateChestsLootedText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateChestsLootedText final
{
public:
	class FText                                   ChestsLootedText;                                  // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateDamageInflictedText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateDamageInflictedText final
{
public:
	class FText                                   DamageInflictedText;                               // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateDamageHealedText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateDamageHealedText final
{
public:
	class FText                                   DamageHealedText;                                  // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateDamageTakenText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateDamageTakenText final
{
public:
	class FText                                   DamageTakenText;                                   // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateLongestEliminationText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateLongestEliminationText final
{
public:
	class FText                                   LongestEliminationText;                            // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateMatchTimeText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateMatchTimeText final
{
public:
	class FText                                   MatchTimeText;                                     // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdatePiecesBuiltText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdatePiecesBuiltText final
{
public:
	class FText                                   PiecesBuiltText;                                   // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateCircleRadiusText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateCircleRadiusText final
{
public:
	class FText                                   CircleRadiusText;                                  // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdatePiecesDestroyedText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdatePiecesDestroyedText final
{
public:
	class FText                                   PiecesDestroyedText;                               // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateMostKillsText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateMostKillsText final
{
public:
	class FText                                   MostKillsText;                                     // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateShotsFiredText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateShotsFiredText final
{
public:
	class FText                                   ShotsFiredText;                                    // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateFastestKillText
// 0x0030 (0x0030 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateFastestKillText final
{
public:
	class FText                                   FastestKillText;                                   // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	class FText                                   FastestKillTime;                                   // 0x0018(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.UpdateSupplyDropsLootedText
// 0x0018 (0x0018 - 0x0000)
struct AthenaEventMatchStatusScreen_C_UpdateSupplyDropsLootedText final
{
public:
	class FText                                   SupplyDropsLootedText;                             // 0x0000(0x0018)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.NewTopPlayer
// 0x0020 (0x0020 - 0x0000)
struct AthenaEventMatchStatusScreen_C_NewTopPlayer final
{
public:
	class UAthenaMatchStatusTextPlayer_C*         TargetWidget;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   InText;                                            // 0x0008(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.NewTopScore
// 0x0020 (0x0020 - 0x0000)
struct AthenaEventMatchStatusScreen_C_NewTopScore final
{
public:
	class UAthenaEventMatchStatusText_C*          TargetWidget;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   InText;                                            // 0x0008(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.NewStatUpdate3Pulse
// 0x0028 (0x0028 - 0x0000)
struct AthenaEventMatchStatusScreen_C_NewStatUpdate3Pulse final
{
public:
	class UAthenaEventMatchStatusText_C*          TargetWidget;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   InText;                                            // 0x0008(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	bool                                          SkipTextUpdate;                                    // 0x0020(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function AthenaEventMatchStatusScreen.AthenaEventMatchStatusScreen_C.NewStatUpdate1Pulse
// 0x0028 (0x0028 - 0x0000)
struct AthenaEventMatchStatusScreen_C_NewStatUpdate1Pulse final
{
public:
	class UAthenaEventMatchStatusText_C*          TargetWidget;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   InText;                                            // 0x0008(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	bool                                          SkipTextUpdate;                                    // 0x0020(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
