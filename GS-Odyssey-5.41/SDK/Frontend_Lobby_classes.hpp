#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Frontend_Lobby

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Frontend_Lobby.Frontend_Lobby_C
// 0x0018 (0x0358 - 0x0340)
class AFrontend_Lobby_C final : public AFortLevelScriptActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0340(0x0008)(Transient, DuplicateTransient)
	class FName                                   CurrentBackgroundLevelName;                        // 0x0348(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   NewBackgroundLevelName;                            // 0x0350(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Frontend_Lobby(int32 EntryPoint);
	void OnBackgroundChanged();
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Frontend_Lobby_C">();
	}
	static class AFrontend_Lobby_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AFrontend_Lobby_C>();
	}
};

}

