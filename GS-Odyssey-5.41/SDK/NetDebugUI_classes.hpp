#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NetDebugUI

#include "Basic.hpp"

#include "NetUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass NetDebugUI.NetDebugUI_C
// 0x0018 (0x0328 - 0x0310)
class UNetDebugUI_C final : public UNetDebugWidget
{
public:
	class UImage*                                 Image_1;                                           // 0x0310(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_2;                                           // 0x0318(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 TimeoutIcon;                                       // 0x0320(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"NetDebugUI_C">();
	}
	static class UNetDebugUI_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UNetDebugUI_C>();
	}
};

}
