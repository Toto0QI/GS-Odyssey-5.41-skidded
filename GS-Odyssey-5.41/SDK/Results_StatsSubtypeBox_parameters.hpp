#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Results_StatsSubtypeBox

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function Results_StatsSubtypeBox.Results_StatsSubtypeBox_C.ExecuteUbergraph_Results_StatsSubtypeBox
// 0x0008 (0x0008 - 0x0000)
struct Results_StatsSubtypeBox_C_ExecuteUbergraph_Results_StatsSubtypeBox final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_StatsSubtypeBox.Results_StatsSubtypeBox_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct Results_StatsSubtypeBox_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function Results_StatsSubtypeBox.Results_StatsSubtypeBox_C.InitializeScoreType
// 0x03D0 (0x03D0 - 0x0000)
struct Results_StatsSubtypeBox_C_InitializeScoreType final
{
public:
	class UTexture2D*                             Texture;                                           // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Color;                                             // 0x0008(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0018(0x0018)(Edit, BlueprintVisible)
	struct FLinearColor                           CallFunc_Multiply_LinearColorFloat_ReturnValue;    // 0x0030(0x0010)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFortScoreStylingInfo                  CallFunc_GetScoreStylingData_ScoreStylingInfo;     // 0x0040(0x0358)()
	bool                                          CallFunc_GetScoreStylingData_ReturnValue;          // 0x0398(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5A34[0x7];                                     // 0x0399(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x03A0(0x0028)()
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x03C8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
