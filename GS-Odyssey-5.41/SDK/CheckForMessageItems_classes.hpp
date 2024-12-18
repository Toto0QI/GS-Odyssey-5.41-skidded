#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CheckForMessageItems

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CheckForMessageItems.CheckForMessageItems_C
// 0x0018 (0x03A0 - 0x0388)
class ACheckForMessageItems_C final : public AFortScriptedAction
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0388(0x0008)(Transient, DuplicateTransient)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0390(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UFortGiftBoxItem*                       GiftBox;                                           // 0x0398(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_CheckForMessageItems(int32 EntryPoint);
	void Execute(const struct FFortScriptedActionParams& Params_0);
	void UserConstructionScript();
	void ShowMessage();
	void Closed(class UCommonActivatablePanel* Param_Closed);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CheckForMessageItems_C">();
	}
	static class ACheckForMessageItems_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ACheckForMessageItems_C>();
	}
};

}

