#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TopWeaponStatRow

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass TopWeaponStatRow.TopWeaponStatRow_C
// 0x0038 (0x0258 - 0x0220)
class UTopWeaponStatRow_C final : public UAthenaProfileStatWidgetBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       StatName;                                          // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopWeaponStatRowEntry_C*               Weapon1;                                           // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopWeaponStatRowEntry_C*               Weapon2;                                           // 0x0238(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopWeaponStatRowEntry_C*               Weapon3;                                           // 0x0240(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopWeaponStatRowEntry_C*               Weapon4;                                           // 0x0248(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopWeaponStatRowEntry_C*               Weapon5;                                           // 0x0250(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TopWeaponStatRow(int32 EntryPoint);
	void OnStatChanged();
	void Update();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TopWeaponStatRow_C">();
	}
	static class UTopWeaponStatRow_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTopWeaponStatRow_C>();
	}
};

}
