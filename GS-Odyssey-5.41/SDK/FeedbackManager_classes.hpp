#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FeedbackManager

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass FeedbackManager.FeedbackManager_C
// 0x0008 (0x0450 - 0x0448)
class AFeedbackManager_C final : public AFortFeedbackManager
{
public:
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0448(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"FeedbackManager_C">();
	}
	static class AFeedbackManager_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AFeedbackManager_C>();
	}
};

}
