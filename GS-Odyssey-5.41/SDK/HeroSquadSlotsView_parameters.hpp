#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HeroSquadSlotsView

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function HeroSquadSlotsView.HeroSquadSlotsView_C.ExecuteUbergraph_HeroSquadSlotsView
// 0x0040 (0x0040 - 0x0000)
struct HeroSquadSlotsView_C_ExecuteUbergraph_HeroSquadSlotsView final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_53D0[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class FName SquadId, int32 SquadSlotIndex)> K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void(class FName SquadId, int32 SquadSlotIndex)> K2Node_CreateDelegate_OutputDelegate1;             // 0x0018(0x0010)(ZeroConstructor, NoDestructor)
	class UFortUINavigationManager*               CallFunc_GetUINavigationManager_ReturnValue;       // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortPrototypingContext*                CallFunc_GetContext_ReturnValue;                   // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortPrototypingStatus                        CallFunc_GetPrototypingStatus_ReturnValue;         // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0039(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function HeroSquadSlotsView.HeroSquadSlotsView_C.CreateAndAddSquadSlotButton
// 0x0468 (0x0468 - 0x0000)
struct HeroSquadSlotsView_C_CreateAndAddSquadSlotButton final
{
public:
	int32                                         SquadSlotIndex;                                    // 0x0000(0x0004)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_53D1[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FHomebaseSquadSlot                     SquadSlotDefinition;                               // 0x0008(0x0068)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	class UWidget*                                OutSquadSlotButtonHost;                            // 0x0070(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortSquadSlotSelectorButton*           ReturnValue;                                       // 0x0078(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Temp_text_Variable;                                // 0x0080(0x0018)()
	bool                                          CallFunc_EqualEqual_IntInt_ReturnValue;            // 0x0098(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchInteger_CmpSuccess;                   // 0x0099(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_53D2[0x6];                                     // 0x009A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateBrush                            K2Node_MakeStruct_SlateBrush;                      // 0x00A0(0x0088)()
	struct FSlateBrush                            K2Node_MakeStruct_SlateBrush1;                     // 0x0128(0x0088)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x01B0(0x0018)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue1;             // 0x01C8(0x0018)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue2;             // 0x01E0(0x0018)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue3;             // 0x01F8(0x0018)()
	class FText                                   Temp_text_Variable1;                               // 0x0210(0x0018)()
	bool                                          Temp_bool_Variable;                                // 0x0228(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_53D3[0x7];                                     // 0x0229(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Temp_text_Variable2;                               // 0x0230(0x0018)()
	class FText                                   K2Node_Select_Default;                             // 0x0248(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0260(0x0040)(HasGetValueTypeHash)
	class FText                                   Temp_text_Variable3;                               // 0x02A0(0x0018)()
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x02B8(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x02C8(0x0018)()
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue;              // 0x02E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USimpleSquadSlotButton_C*               CallFunc_Create_ReturnValue;                       // 0x02E8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable1;                               // 0x02F0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_53D4[0x7];                                     // 0x02F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Select1_Default;                            // 0x02F8(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData1;             // 0x0310(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array1;                           // 0x0350(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue1;                      // 0x0360(0x0018)()
	TArray<class UWidget*>                        K2Node_MakeArray_Array2;                           // 0x0378(0x0010)(ZeroConstructor, ReferenceParm)
	bool                                          Temp_bool_Variable2;                               // 0x0388(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_53D5[0x7];                                     // 0x0389(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue1;             // 0x0390(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateBrush                            K2Node_Select2_Default;                            // 0x0398(0x0088)()
	class USimpleSquadSlotButton_C*               CallFunc_Create_ReturnValue1;                      // 0x0420(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         CallFunc_MakeLiteralByte_ReturnValue;              // 0x0428(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_53D6[0x7];                                     // 0x0429(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UWidget*>                        K2Node_MakeArray_Array3;                           // 0x0430(0x0010)(ZeroConstructor, ReferenceParm)
	uint8                                         CallFunc_MakeLiteralByte_ReturnValue1;             // 0x0440(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_53D7[0x7];                                     // 0x0441(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetOwningPlayer_ReturnValue2;             // 0x0448(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USimpleSquadSlotButton_C*               CallFunc_Create_ReturnValue2;                      // 0x0450(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UWidget*>                        K2Node_MakeArray_Array4;                           // 0x0458(0x0010)(ZeroConstructor, ReferenceParm)
};

// Function HeroSquadSlotsView.HeroSquadSlotsView_C.HandleSquadNavigation
// 0x0018 (0x0018 - 0x0000)
struct alignas(0x08) HeroSquadSlotsView_C_HandleSquadNavigation final
{
public:
	class FName                                   SquadId;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         SlotIndex;                                         // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         SquadSlotId;                                       // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchInteger_CmpSuccess;                   // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_NameName_ReturnValue;          // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function HeroSquadSlotsView.HeroSquadSlotsView_C.HighlightSlotByIndex
// 0x0008 (0x0008 - 0x0000)
struct HeroSquadSlotsView_C_HighlightSlotByIndex final
{
public:
	int32                                         Param_Index;                                       // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchInteger_CmpSuccess;                   // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
