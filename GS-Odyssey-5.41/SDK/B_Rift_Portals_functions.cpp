#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Rift_Portals

#include "Basic.hpp"

#include "B_Rift_Portals_classes.hpp"
#include "B_Rift_Portals_parameters.hpp"


namespace SDK
{

// Function B_Rift_Portals.B_Rift_Portals_C.ExecuteUbergraph_B_Rift_Portals
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AB_Rift_Portals_C::ExecuteUbergraph_B_Rift_Portals(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ExecuteUbergraph_B_Rift_Portals");

	Params::B_Rift_Portals_C_ExecuteUbergraph_B_Rift_Portals Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ResetGate
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::ResetGate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ResetGate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.OnDeactivated
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void AB_Rift_Portals_C::OnDeactivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "OnDeactivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.PatrolEnemySuckIn
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Delay                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Param_RiftLightningDuration                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Param_SpawnImpactParticles                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AB_Rift_Portals_C::PatrolEnemySuckIn(float Delay, float Param_RiftLightningDuration, bool Param_SpawnImpactParticles)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "PatrolEnemySuckIn");

	Params::B_Rift_Portals_C_PatrolEnemySuckIn Parms{};

	Parms.Delay = Delay;
	Parms.Param_RiftLightningDuration = Param_RiftLightningDuration;
	Parms.Param_SpawnImpactParticles = Param_SpawnImpactParticles;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ManuallyDeactivateRift
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::ManuallyDeactivateRift()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ManuallyDeactivateRift");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ManuallyActivateRift
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::ManuallyActivateRift()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ManuallyActivateRift");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.FadeLightOut
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::FadeLightOut()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "FadeLightOut");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.FadeLightIn
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::FadeLightIn()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "FadeLightIn");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AB_Rift_Portals_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ReceiveEndPlay
// (Event, Public, BlueprintEvent)
// Parameters:
// EEndPlayReason                          EndPlayReason                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AB_Rift_Portals_C::ReceiveEndPlay(EEndPlayReason EndPlayReason)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ReceiveEndPlay");

	Params::B_Rift_Portals_C_ReceiveEndPlay Parms{};

	Parms.EndPlayReason = EndPlayReason;

	UObject::ProcessEvent(Func, &Parms);
}


// Function B_Rift_Portals.B_Rift_Portals_C.OnActivated
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void AB_Rift_Portals_C::OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.Lightning Impact Event
// (BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::Lightning_Impact_Event()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "Lightning Impact Event");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.OnSpawnAI
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void AB_Rift_Portals_C::OnSpawnAI()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "OnSpawnAI");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.OnRemoved
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void AB_Rift_Portals_C::OnRemoved()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "OnRemoved");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.OnPlaced
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void AB_Rift_Portals_C::OnPlaced()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "OnPlaced");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ScaleLightOnOff__UpdateFunc
// (BlueprintEvent)

void AB_Rift_Portals_C::ScaleLightOnOff__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ScaleLightOnOff__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.ScaleLightOnOff__FinishedFunc
// (BlueprintEvent)

void AB_Rift_Portals_C::ScaleLightOnOff__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "ScaleLightOnOff__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.BoostLight__UpdateFunc
// (BlueprintEvent)

void AB_Rift_Portals_C::BoostLight__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "BoostLight__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.BoostLight__FinishedFunc
// (BlueprintEvent)

void AB_Rift_Portals_C::BoostLight__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "BoostLight__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function B_Rift_Portals.B_Rift_Portals_C.UserConstructionScript
// (Event, Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AB_Rift_Portals_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("B_Rift_Portals_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}
