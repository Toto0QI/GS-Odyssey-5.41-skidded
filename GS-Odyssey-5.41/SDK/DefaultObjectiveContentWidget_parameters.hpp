#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DefaultObjectiveContentWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK::Params
{

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.ExecuteUbergraph_DefaultObjectiveContentWidget
// 0x0088 (0x0088 - 0x0000)
struct DefaultObjectiveContentWidget_C_ExecuteUbergraph_DefaultObjectiveContentWidget final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4462[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class AFortMissionState* MissionState)> K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	class AFortObjectiveBase*                     K2Node_Event_Objective;                            // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_bInConfigureAsHUD;                    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4463[0x7];                                     // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class AFortObjectiveBase* Objective, bool bNewVisibility)> K2Node_CreateDelegate_OutputDelegate1;             // 0x0028(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void(class AFortObjectiveBase* Objective, EFortObjectiveStatus NewStatus)> K2Node_CreateDelegate_OutputDelegate2;             // 0x0038(0x0010)(ZeroConstructor, NoDestructor)
	const class AFortObjectiveBase*               K2Node_CustomEvent_Objective1;                     // 0x0048(0x0008)(ConstParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortObjectiveStatus                          K2Node_CustomEvent_NewStatus;                      // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4464[0x7];                                     // 0x0051(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	const class AFortObjectiveBase*               K2Node_CustomEvent_Objective;                      // 0x0058(0x0008)(ConstParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_CustomEvent_bNewVisibility;                 // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4465[0x7];                                     // 0x0061(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortMissionState*                      K2Node_CustomEvent_MissionState;                   // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortMissionTimerComponent*             CallFunc_GetTimerComponent_ReturnValue;            // 0x0070(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class UFortMissionTimerComponent* TimerComponent)> K2Node_CreateDelegate_OutputDelegate3;             // 0x0078(0x0010)(ZeroConstructor, NoDestructor)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.HandleUpdate
// 0x0008 (0x0008 - 0x0000)
struct DefaultObjectiveContentWidget_C_HandleUpdate final
{
public:
	class AFortMissionState*                      MissionState;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.HandleObjectiveVisibilityChanged
// 0x0010 (0x0010 - 0x0000)
struct DefaultObjectiveContentWidget_C_HandleObjectiveVisibilityChanged final
{
public:
	const class AFortObjectiveBase*               Objective;                                         // 0x0000(0x0008)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bNewVisibility;                                    // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.HandleObjectiveStatusChanged
// 0x0010 (0x0010 - 0x0000)
struct DefaultObjectiveContentWidget_C_HandleObjectiveStatusChanged final
{
public:
	const class AFortObjectiveBase*               Objective;                                         // 0x0000(0x0008)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortObjectiveStatus                          NewStatus;                                         // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.Setup
// 0x0010 (0x0010 - 0x0000)
struct DefaultObjectiveContentWidget_C_Setup final
{
public:
	class AFortObjectiveBase*                     Objective;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bInConfigureAsHUD;                                 // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.Update
// 0x01B8 (0x01B8 - 0x0000)
struct DefaultObjectiveContentWidget_C_Update final
{
public:
	class FText                                   TimerText;                                         // 0x0000(0x0018)(Edit, BlueprintVisible)
	bool                                          CallFunc_TextIsEmpty_ReturnValue;                  // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4466[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0020(0x0040)(HasGetValueTypeHash)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4467[0x7];                                     // 0x0061(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetEmptyText_ReturnValue;                 // 0x0068(0x0018)()
	class UMissionRichText_C*                     CallFunc_GetRichTextBlock_MissionRichTextBlock;    // 0x0080(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortMissionTimerComponent*             CallFunc_GetTimerComponent_ReturnValue;            // 0x0088(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0090(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue1;                     // 0x0091(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4468[0x6];                                     // 0x0092(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetTimeText_ReturnValue;                  // 0x0098(0x0018)()
	bool                                          CallFunc_IsTimerVisible_ReturnValue;               // 0x00B0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4469[0x7];                                     // 0x00B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData1;             // 0x00B8(0x0040)(HasGetValueTypeHash)
	float                                         CallFunc_GetMissionTimerTimeRemaining_ReturnValue; // 0x00F8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_446A[0x4];                                     // 0x00FC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0100(0x0010)(ZeroConstructor, ReferenceParm)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0110(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_446B[0x7];                                     // 0x0111(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0118(0x0018)()
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0130(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_446C[0x7];                                     // 0x0131(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetObjectiveDisplayString_ReturnValue;    // 0x0138(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData2;             // 0x0150(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array1;                           // 0x0190(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue1;                      // 0x01A0(0x0018)()
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.GetRichTextBlock
// 0x0030 (0x0030 - 0x0000)
struct DefaultObjectiveContentWidget_C_GetRichTextBlock final
{
public:
	class UMissionRichText_C*                     MissionRichTextBlock;                              // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMissionRichText_C*                     FoundTextBlock;                                    // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWidget*                                CallFunc_GetChildAt_ReturnValue;                   // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_HasAnyChildren_ReturnValue;               // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_446D[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMissionRichText_C*                     K2Node_DynamicCast_AsMission_Rich_Text;            // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.CreateRichTextBlock
// 0x0030 (0x0030 - 0x0000)
struct DefaultObjectiveContentWidget_C_CreateRichTextBlock final
{
public:
	class FText                                   Text;                                              // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue;              // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMissionRichText_C*                     CallFunc_Create_ReturnValue;                       // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPanelSlot*                             CallFunc_AddChild_ReturnValue;                     // 0x0028(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.HandleTimerComponentUpdated
// 0x0008 (0x0008 - 0x0000)
struct DefaultObjectiveContentWidget_C_HandleTimerComponentUpdated final
{
public:
	class UFortMissionTimerComponent*             InTimerComponent;                                  // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.UpdateAutoRefreshTimer
// 0x0028 (0x0028 - 0x0000)
struct DefaultObjectiveContentWidget_C_UpdateAutoRefreshTimer final
{
public:
	bool                                          ShouldAutoRefresh;                                 // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_446E[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          CallFunc_K2_IsTimerActiveHandle_ReturnValue;       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_446F[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0020(0x0008)(NoDestructor, HasGetValueTypeHash)
};

// Function DefaultObjectiveContentWidget.DefaultObjectiveContentWidget_C.GetHeightEstimate
// 0x0030 (0x0030 - 0x0000)
struct DefaultObjectiveContentWidget_C_GetHeightEstimate final
{
public:
	float                                         Height;                                            // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HeightEstimate;                                    // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4470[0x3];                                     // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetHeightEstimate_Height;                 // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4471[0x4];                                     // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMissionRichText_C*                     CallFunc_GetRichTextBlock_MissionRichTextBlock;    // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue1;                     // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4472[0x3];                                     // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetMissionHUDTextLineHeightEstimate_ReturnValue; // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue1;              // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

