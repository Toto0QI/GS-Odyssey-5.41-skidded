#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemStackCounter

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemStackCounter.ItemStackCounter_C
// 0x05D0 (0x07E0 - 0x0210)
class UItemStackCounter_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0210(0x0008)(Transient, DuplicateTransient)
	class USizeBox*                               _SizeBox_;                                         // 0x0218(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          BorderBase;                                        // 0x0220(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextCounter;                                       // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	struct FFortMultiSizeBrush                    MultiSizeBase;                                     // 0x0230(0x0330)(Edit, BlueprintVisible)
	struct FFortMultiSizeFont                     MultiSizeFont;                                     // 0x0560(0x0210)(Edit, BlueprintVisible)
	struct FFortMultiSizeMargin                   MultiSizeMargin;                                   // 0x0770(0x0060)(Edit, BlueprintVisible, NoDestructor)
	EFortBrushSize                                Brush_Size;                                        // 0x07D0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_528F[0x3];                                     // 0x07D1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Count;                                             // 0x07D4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          AlwaysVisible;                                     // 0x07D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          TruncateValue;                                     // 0x07D9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	ESlateVisibility                              VisibilityWithNoStack;                             // 0x07DA(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_ItemStackCounter(int32 EntryPoint);
	void PreConstruct(bool IsDesignTime);
	void Update(EFortBrushSize Param_Brush_Size, int32 Param_Count);
	void Set_Stack_Count(int32 Param_Count);
	void Refresh_Visibility();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemStackCounter_C">();
	}
	static class UItemStackCounter_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemStackCounter_C>();
	}
};

}

