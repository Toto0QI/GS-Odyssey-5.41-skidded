#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemInspectUpgradeCallout

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"


namespace SDK::Params
{

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.ExecuteUbergraph_ItemInspectUpgradeCallout
// 0x0018 (0x0018 - 0x0000)
struct ItemInspectUpgradeCallout_C_ExecuteUbergraph_ItemInspectUpgradeCallout final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_42B4[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button1;                // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button;                 // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.BndEvt__EvolveButton_K2Node_ComponentBoundEvent_51_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct ItemInspectUpgradeCallout_C_BndEvt__EvolveButton_K2Node_ComponentBoundEvent_51_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.BndEvt__IconTextButton_K2Node_ComponentBoundEvent_257_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct ItemInspectUpgradeCallout_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_257_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.Refresh
// 0x0010 (0x0010 - 0x0000)
struct ItemInspectUpgradeCallout_C_Refresh final
{
public:
	bool                                          CallFunc_HasEvolutions_ReturnValue;                // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42B5[0x2];                                     // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetLevel_ReturnValue;                     // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetMaxLevel_ReturnValue;                  // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_IntInt_ReturnValue;          // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.SetItemToRepresent
// 0x0008 (0x0008 - 0x0000)
struct ItemInspectUpgradeCallout_C_SetItemToRepresent final
{
public:
	class UFortItem*                              Param_Item;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.OnShow
// 0x0010 (0x0010 - 0x0000)
struct ItemInspectUpgradeCallout_C_OnShow final
{
public:
	bool                                          CallFunc_IsVisible_ReturnValue;                    // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42B6[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortUINavigationManager*               CallFunc_GetUINavigationManager_ReturnValue;       // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.IsUpgradeReady
// 0x0038 (0x0038 - 0x0000)
struct ItemInspectUpgradeCallout_C_IsUpgradeReady final
{
public:
	bool                                          UpgradeReady;                                      // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42B7[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<EItemUpgradeRestrictionReason>         CallFunc_CanBeUpgraded_OutRestrictionReasons;      // 0x0008(0x0010)(ZeroConstructor, ReferenceParm)
	bool                                          CallFunc_CanBeUpgraded_ReturnValue;                // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42B8[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortPersistentResourceItemDefinition*  CallFunc_GetUpgradeResourceItemDefinition_ReturnValue; // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortInventoryContext*                  CallFunc_GetContext_ReturnValue;                   // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetNumInInventory_ReturnValue;            // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_IntInt_ReturnValue;          // 0x0034(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0035(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.ShowUpgradeInfo
// 0x0018 (0x0018 - 0x0000)
struct ItemInspectUpgradeCallout_C_ShowUpgradeInfo final
{
public:
	bool                                          CallFunc_IsUpgradeReady_UpgradeReady;              // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42B9[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortPersistentResourceItemDefinition*  CallFunc_GetUpgradeResourceItemDefinition_ReturnValue; // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetUpgradeCost_ReturnValue;               // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.ShowEvolutionInfo
// 0x00D0 (0x00D0 - 0x0000)
struct ItemInspectUpgradeCallout_C_ShowEvolutionInfo final
{
public:
	bool                                          CallFunc_IsEvolutionReady_EvolutionReady;          // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42BA[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortItemDefinition*                    CallFunc_GetItemDefinitionBP_ReturnValue;          // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortInventoryContext*                  CallFunc_GetContext_ReturnValue;                   // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<struct FRecipe>                        CallFunc_GetConversionRecipesFromItemDefintion_ReturnValue; // 0x0018(0x0010)(ZeroConstructor, ReferenceParm)
	struct FRecipe                                CallFunc_Array_Get_Item;                           // 0x0028(0x0058)()
	struct FFortItemQuantityPair                  CallFunc_Array_Get_Item1;                          // 0x0080(0x0040)()
	class UFortFrontEndContext*                   CallFunc_GetContext_ReturnValue1;                  // 0x00C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortItemDefinition*                    CallFunc_GetItemFromItemQuantityPair_ReturnValue;  // 0x00C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ItemInspectUpgradeCallout.ItemInspectUpgradeCallout_C.IsEvolutionReady
// 0x0020 (0x0020 - 0x0000)
struct ItemInspectUpgradeCallout_C_IsEvolutionReady final
{
public:
	bool                                          EvolutionReady;                                    // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42BB[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<EItemEvolutionRestrictionReason>       CallFunc_CanEvolve_OutRestrictionReasons;          // 0x0008(0x0010)(ZeroConstructor, ReferenceParm)
	bool                                          CallFunc_CanEvolve_ReturnValue;                    // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

}
