#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PhoneInfo

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass PhoneInfo.PhoneInfo_C
// 0x0040 (0x0390 - 0x0350)
class UPhoneInfo_C final : public UBacchusHUDElement
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0350(0x0008)(Transient, DuplicateTransient)
	class UImage*                                 BatteryIcon;                                       // 0x0358(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       LocalTime;                                         // 0x0360(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UPaperSprite*                           Battery_0;                                         // 0x0368(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPaperSprite*                           Battery_25;                                        // 0x0370(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPaperSprite*                           Battery_50;                                        // 0x0378(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPaperSprite*                           Battery_75;                                        // 0x0380(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPaperSprite*                           Battery_100;                                       // 0x0388(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_PhoneInfo(int32 EntryPoint);
	void On_Low_Perf_Mode(bool bInLowPerformanceMode);
	void Construct();
	void BatteryTimerUpdate();
	void ClockTimerUpdate();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PhoneInfo_C">();
	}
	static class UPhoneInfo_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPhoneInfo_C>();
	}
};

}
