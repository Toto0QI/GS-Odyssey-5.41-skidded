#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HordeTierResultsWidget

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass HordeTierResultsWidget.HordeTierResultsWidget_C
// 0x0068 (0x0360 - 0x02F8)
class UHordeTierResultsWidget_C final : public UCommonActivatablePanel
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02F8(0x0008)(Transient, DuplicateTransient)
	class UMovieWidget_C*                         Movie;                                             // 0x0300(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UResults_NameplateWidget_C*             ResultsNameplate;                                  // 0x0308(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	UMulticastDelegateProperty_                   OnTierResultsWidgetComplete;                       // 0x0310(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	EFortCompletionResult                         CompletionResult;                                  // 0x0320(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_58CA[0x7];                                     // 0x0321(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMediaSource*                           DefaultDefeatMedia;                                // 0x0328(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMediaSource*                           DefaultVictoryMedia;                               // 0x0330(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             VictorySound;                                      // 0x0338(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             DefeatSound;                                       // 0x0340(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MovieTextDelay;                                    // 0x0348(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_58CB[0x4];                                     // 0x034C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 NameplateIntroFunctionName;                        // 0x0350(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)

public:
	void OnTierResultsWidgetComplete__DelegateSignature();
	void ExecuteUbergraph_HordeTierResultsWidget(int32 EntryPoint);
	void Destruct();
	void Construct();
	void InitializeMovie();
	void Initialize(EFortCompletionResult Result);
	void ChooseMediaToUse(class UMediaSource** MediaToUse);
	void OnEndOfMovieReached();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HordeTierResultsWidget_C">();
	}
	static class UHordeTierResultsWidget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHordeTierResultsWidget_C>();
	}
};

}
