#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmallStatRowWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass SmallStatRowWidget.SmallStatRowWidget_C
// 0x0018 (0x0238 - 0x0220)
class USmallStatRowWidget_C final : public UAthenaProfileStatWidgetBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       StatName;                                          // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonNumericTextBlock*                StatValue;                                         // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_SmallStatRowWidget(int32 EntryPoint);
	void OnStatChanged();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SmallStatRowWidget_C">();
	}
	static class USmallStatRowWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USmallStatRowWidget_C>();
	}
};

}
