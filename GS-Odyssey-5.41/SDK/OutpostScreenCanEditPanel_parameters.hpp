#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OutpostScreenCanEditPanel

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK::Params
{

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.ExecuteUbergraph_OutpostScreenCanEditPanel
// 0x0460 (0x0460 - 0x0000)
struct OutpostScreenCanEditPanel_C_ExecuteUbergraph_OutpostScreenCanEditPanel final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45D8[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFortTeamMemberInfo                    K2Node_CustomEvent_PlayerInfo;                     // 0x0008(0x01F8)(ConstParm, HasGetValueTypeHash)
	TDelegate<void(struct FFortTeamMemberInfo& PlayerInfo)> K2Node_CreateDelegate_OutputDelegate;              // 0x0200(0x0010)(ZeroConstructor, NoDestructor)
	class UFortBaseButton*                        K2Node_ComponentBoundEvent_Button1;                // 0x0210(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_Selected1;              // 0x0218(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45D9[0x7];                                     // 0x0219(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(int32 PlayerIndex)>            K2Node_CreateDelegate_OutputDelegate1;             // 0x0220(0x0010)(ZeroConstructor, NoDestructor)
	struct FFortTeamMemberInfo                    K2Node_CustomEvent_NewTeamMemberInfo;              // 0x0230(0x01F8)(HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_PlayerIndex;                    // 0x0428(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45DA[0x4];                                     // 0x042C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(const struct FFortTeamMemberInfo& NewTeamMemberInfo)> K2Node_CreateDelegate_OutputDelegate2;             // 0x0430(0x0010)(ZeroConstructor, NoDestructor)
	class UFortPartyContext*                      CallFunc_GetContext_ReturnValue;                   // 0x0440(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button;                 // 0x0448(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_Selected;               // 0x0450(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45DB[0x7];                                     // 0x0451(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortUITeamInfo*                        CallFunc_GetLocalPlayerTeam_ReturnValue;           // 0x0458(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.PartyUpdated
// 0x01F8 (0x01F8 - 0x0000)
struct OutpostScreenCanEditPanel_C_PartyUpdated final
{
public:
	struct FFortTeamMemberInfo                    PlayerInfo;                                        // 0x0000(0x01F8)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, HasGetValueTypeHash)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.BndEvt__IconTextButton_K2Node_ComponentBoundEvent_71_CommonSelectedStateChanged__DelegateSignature
// 0x0010 (0x0010 - 0x0000)
struct OutpostScreenCanEditPanel_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_71_CommonSelectedStateChanged__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Selected;                                          // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.HandleRemoved
// 0x0004 (0x0004 - 0x0000)
struct OutpostScreenCanEditPanel_C_HandleRemoved final
{
public:
	int32                                         PlayerIndex;                                       // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.HandleJoined
// 0x01F8 (0x01F8 - 0x0000)
struct OutpostScreenCanEditPanel_C_HandleJoined final
{
public:
	struct FFortTeamMemberInfo                    NewTeamMemberInfo;                                 // 0x0000(0x01F8)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.BndEvt__MasterSwitchButton_K2Node_ComponentBoundEvent_407_FortSelectedStateChanged__DelegateSignature
// 0x0010 (0x0010 - 0x0000)
struct OutpostScreenCanEditPanel_C_BndEvt__MasterSwitchButton_K2Node_ComponentBoundEvent_407_FortSelectedStateChanged__DelegateSignature final
{
public:
	class UFortBaseButton*                        Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Selected;                                          // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.Init
// 0x0098 (0x0098 - 0x0000)
struct OutpostScreenCanEditPanel_C_Init final
{
public:
	class AFortPlayerControllerOutpost*           InOutpostOwner;                                    // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsOutpostOwner_ReturnValue;               // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45DC[0x7];                                     // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerStateOutpost*                K2Node_DynamicCast_AsFort_Player_State_Outpost;    // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x001A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45DD[0x1];                                     // 0x001B(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Array_Index_Variable;                     // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45DE[0x3];                                     // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetChildrenCount_ReturnValue;             // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_IntInt_ReturnValue;             // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45DF[0x3];                                     // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45E0[0x4];                                     // 0x0034(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue;              // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45E1[0x7];                                     // 0x0041(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UOutpostScreenCanEditRow_C*             CallFunc_Create_ReturnValue;                       // 0x0048(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UVerticalBoxSlot*                       CallFunc_AddChildToVerticalBox_ReturnValue;        // 0x0050(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class AFortPlayerPawn*>                CallFunc_GetAllFortPlayerPawns_OutFortPlayerPawns; // 0x0058(0x0010)(ZeroConstructor, ReferenceParm)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45E2[0x7];                                     // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerPawn*                        CallFunc_Array_Get_Item;                           // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x0078(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45E3[0x7];                                     // 0x0079(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerStateOutpost*                K2Node_DynamicCast_AsFort_Player_State_Outpost1;   // 0x0080(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess1;                      // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_ObjectObject_ReturnValue;        // 0x0089(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E4[0x2];                                     // 0x008A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x008C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanAND_ReturnValue1;                  // 0x0090(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0091(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.SetMasterSwitch
// 0x0058 (0x0058 - 0x0000)
struct OutpostScreenCanEditPanel_C_SetMasterSwitch final
{
public:
	bool                                          bCanEdit;                                          // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E5[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerStateOutpost*                LocalPlayerState;                                  // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          LocalCanEdit;                                      // 0x0010(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E6[0x3];                                     // 0x0011(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_ObjectObject_ReturnValue;        // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E7[0x7];                                     // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AFortPlayerPawn*>                CallFunc_GetAllFortPlayerPawns_OutFortPlayerPawns; // 0x0028(0x0010)(ZeroConstructor, ReferenceParm)
	class AFortPlayerPawn*                        CallFunc_Array_Get_Item;                           // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0040(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0044(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E8[0x3];                                     // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPlayerStateOutpost*                K2Node_DynamicCast_AsFort_Player_State_Outpost;    // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0051(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function OutpostScreenCanEditPanel.OutpostScreenCanEditPanel_C.CenterWidget
// 0x0028 (0x0028 - 0x0000)
struct OutpostScreenCanEditPanel_C_CenterWidget final
{
public:
	class UFortUINavigationManager*               CallFunc_GetUINavigationManager_ReturnValue;       // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsVisible_ReturnValue;                    // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45E9[0x7];                                     // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UWidget*                                CallFunc_GetChildAt_ReturnValue;                   // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOutpostScreenCanEditRow_C*             K2Node_DynamicCast_AsOutpost_Screen_Can_Edit_Row;  // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
