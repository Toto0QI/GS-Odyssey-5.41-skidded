#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TabAudioOptions

#include "Basic.hpp"


namespace SDK::Params
{

// Function TabAudioOptions.TabAudioOptions_C.ExecuteUbergraph_TabAudioOptions
// 0x0058 (0x0058 - 0x0000)
struct TabAudioOptions_C_ExecuteUbergraph_TabAudioOptions final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3852[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	class UFortSettingsContext*                   CallFunc_GetContext_ReturnValue;                   // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUserWidget*                            K2Node_ComponentBoundEvent_Widget1;                // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortOptionsMenuSetting*                K2Node_DynamicCast_AsFort_Options_Menu_Setting;    // 0x0028(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3853[0x7];                                     // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                K2Node_ComponentBoundEvent_Item;                   // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUserWidget*                            K2Node_ComponentBoundEvent_Widget;                 // 0x0040(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortOptionsMenuSetting*                K2Node_DynamicCast_AsFort_Options_Menu_Setting1;   // 0x0048(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess1;                      // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function TabAudioOptions.TabAudioOptions_C.BndEvt__OptionsListView_K2Node_ComponentBoundEvent_4_OnListViewItemWidgetCreated__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct TabAudioOptions_C_BndEvt__OptionsListView_K2Node_ComponentBoundEvent_4_OnListViewItemWidgetCreated__DelegateSignature final
{
public:
	class UUserWidget*                            Widget;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function TabAudioOptions.TabAudioOptions_C.BndEvt__OptionsListView_K2Node_ComponentBoundEvent_5_OnListViewItemScrolledIntoView__DelegateSignature
// 0x0010 (0x0010 - 0x0000)
struct TabAudioOptions_C_BndEvt__OptionsListView_K2Node_ComponentBoundEvent_5_OnListViewItemScrolledIntoView__DelegateSignature final
{
public:
	class UObject*                                Item;                                              // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUserWidget*                            Widget;                                            // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}

