#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmallStatWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass SmallStatWidget.SmallStatWidget_C
// 0x0018 (0x0238 - 0x0220)
class USmallStatWidget_C final : public UAthenaProfileStatWidgetBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(Transient, DuplicateTransient)
	class UImage*                                 StatImage;                                         // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonNumericTextBlock*                StatValue;                                         // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_SmallStatWidget(int32 EntryPoint);
	void OnStatChanged();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SmallStatWidget_C">();
	}
	static class USmallStatWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USmallStatWidget_C>();
	}
};

}
