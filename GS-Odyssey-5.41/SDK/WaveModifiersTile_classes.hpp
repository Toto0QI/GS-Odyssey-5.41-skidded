#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WaveModifiersTile

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WaveModifiersTile.WaveModifiersTile_C
// 0x0038 (0x0250 - 0x0218)
class UWaveModifiersTile_C final : public UFortUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0218(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Intro;                                             // 0x0220(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             ModifierDesc;                                      // 0x0228(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 ModifierImage;                                     // 0x0230(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             ModifierName;                                      // 0x0238(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	UMulticastDelegateProperty_                   OnReadyForNextModifierPresentation;                // 0x0240(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)

public:
	void OnReadyForNextModifierPresentation__DelegateSignature();
	void ExecuteUbergraph_WaveModifiersTile(int32 EntryPoint);
	void SetData(class UObject* InData);
	void OnAnimReadyForNextModifier();
	void SetModifierItem(class UFortItem* ModifierItem);
	void PlayIntro();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WaveModifiersTile_C">();
	}
	static class UWaveModifiersTile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWaveModifiersTile_C>();
	}
};

}
