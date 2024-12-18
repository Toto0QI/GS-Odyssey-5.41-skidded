#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Athena_PlayerController

#include "Basic.hpp"

#include "Athena_PlayerController_classes.hpp"
#include "Athena_PlayerController_parameters.hpp"


namespace SDK
{

// Function Athena_PlayerController.Athena_PlayerController_C.ExecuteUbergraph_Athena_PlayerController
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAthena_PlayerController_C::ExecuteUbergraph_Athena_PlayerController(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "ExecuteUbergraph_Athena_PlayerController");

	Params::Athena_PlayerController_C_ExecuteUbergraph_Athena_PlayerController Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Athena_PlayerController.Athena_PlayerController_C.ReceiveEndPlay
// (Event, Public, BlueprintEvent)
// Parameters:
// EEndPlayReason                          EndPlayReason                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAthena_PlayerController_C::ReceiveEndPlay(EEndPlayReason EndPlayReason)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "ReceiveEndPlay");

	Params::Athena_PlayerController_C_ReceiveEndPlay Parms{};

	Parms.EndPlayReason = EndPlayReason;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Athena_PlayerController.Athena_PlayerController_C.PlayWinEffects
// (Event, Public, BlueprintEvent)
// Parameters:
// class APawn*                            FinisherPawn                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UFortWeaponItemDefinition*        FinishingWeapon                                        (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EDeathCause                             DeathCause                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAthena_PlayerController_C::PlayWinEffects(class APawn* FinisherPawn, const class UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "PlayWinEffects");

	Params::Athena_PlayerController_C_PlayWinEffects Parms{};

	Parms.FinisherPawn = FinisherPawn;
	Parms.FinishingWeapon = FinishingWeapon;
	Parms.DeathCause = DeathCause;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Athena_PlayerController.Athena_PlayerController_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AAthena_PlayerController_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Athena_PlayerController.Athena_PlayerController_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AAthena_PlayerController_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Athena_PlayerController.Athena_PlayerController_C.IsLocalPlayerFriendsWithSquadMember
// (Event, Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortPlayerState*                 SquadMember                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool AAthena_PlayerController_C::IsLocalPlayerFriendsWithSquadMember(class AFortPlayerState* SquadMember)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Athena_PlayerController_C", "IsLocalPlayerFriendsWithSquadMember");

	Params::Athena_PlayerController_C_IsLocalPlayerFriendsWithSquadMember Parms{};

	Parms.SquadMember = SquadMember;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

