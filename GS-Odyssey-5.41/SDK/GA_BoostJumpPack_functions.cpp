#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_BoostJumpPack

#include "Basic.hpp"

#include "GA_BoostJumpPack_classes.hpp"
#include "GA_BoostJumpPack_parameters.hpp"


namespace SDK
{

// Function GA_BoostJumpPack.GA_BoostJumpPack_C.ExecuteUbergraph_GA_BoostJumpPack
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::ExecuteUbergraph_GA_BoostJumpPack(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "ExecuteUbergraph_GA_BoostJumpPack");

	Params::GA_BoostJumpPack_C_ExecuteUbergraph_GA_BoostJumpPack Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Delay_ProcessAbilityStateMachine
// (BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Delay_ProcessAbilityStateMachine()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Delay_ProcessAbilityStateMachine");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.OnCurrentStateChanged
// (Event, Public, BlueprintEvent)
// Parameters:
// EJumpBoostPackState                     InPreviousState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EJumpBoostPackState                     InCurrentState                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::OnCurrentStateChanged(EJumpBoostPackState InPreviousState, EJumpBoostPackState InCurrentState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "OnCurrentStateChanged");

	Params::GA_BoostJumpPack_C_OnCurrentStateChanged Parms{};

	Parms.InPreviousState = InPreviousState;
	Parms.InCurrentState = InCurrentState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.K2_ActivateAbilityFromEvent
// (Event, Protected, HasOutParams, BlueprintEvent)
// Parameters:
// struct FGameplayEventData               EventData                                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UGA_BoostJumpPack_C::K2_ActivateAbilityFromEvent(const struct FGameplayEventData& EventData)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "K2_ActivateAbilityFromEvent");

	Params::GA_BoostJumpPack_C_K2_ActivateAbilityFromEvent Parms{};

	Parms.EventData = std::move(EventData);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.OnPawnLanded
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FHitResult                       Hit                                                    (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void UGA_BoostJumpPack_C::OnPawnLanded(const struct FHitResult& Hit)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "OnPawnLanded");

	Params::GA_BoostJumpPack_C_OnPawnLanded Parms{};

	Parms.Hit = std::move(Hit);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.On Reached Jump Apex
// (BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::On_Reached_Jump_Apex()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "On Reached Jump Apex");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.SetJumpHeight
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortPlayerPawn*                  Pawn                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AFortPlayerPawn*                  Pawn_Out                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Jump_Height                                            (Parm, OutParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::SetJumpHeight(class AFortPlayerPawn* Pawn, class AFortPlayerPawn** Pawn_Out, struct FVector* Jump_Height)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "SetJumpHeight");

	Params::GA_BoostJumpPack_C_SetJumpHeight Parms{};

	Parms.Pawn = Pawn;

	UObject::ProcessEvent(Func, &Parms);

	if (Pawn_Out != nullptr)
		*Pawn_Out = Parms.Pawn_Out;

	if (Jump_Height != nullptr)
		*Jump_Height = std::move(Parms.Jump_Height);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.HandleBoostJump
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::HandleBoostJump()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "HandleBoostJump");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.SetupTransitionVariables
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayTag                     Tag                                                    (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::SetupTransitionVariables(const struct FGameplayTag& Tag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "SetupTransitionVariables");

	Params::GA_BoostJumpPack_C_SetupTransitionVariables Parms{};

	Parms.Tag = std::move(Tag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.DetermineStateToTransitionTo
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// Enum_BoostJumpStates                    BoostState                                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::DetermineStateToTransitionTo(Enum_BoostJumpStates* BoostState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "DetermineStateToTransitionTo");

	Params::GA_BoostJumpPack_C_DetermineStateToTransitionTo Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (BoostState != nullptr)
		*BoostState = Parms.BoostState;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.ProcessAbilityStateMachine
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::ProcessAbilityStateMachine()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "ProcessAbilityStateMachine");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.TransitionFromBoost
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// Enum_BoostJumpStates                    TargetBoostState                                       (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::TransitionFromBoost(Enum_BoostJumpStates* TargetBoostState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "TransitionFromBoost");

	Params::GA_BoostJumpPack_C_TransitionFromBoost Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetBoostState != nullptr)
		*TargetBoostState = Parms.TargetBoostState;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.TransitionFromHovering
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// Enum_BoostJumpStates                    TargetBoostState                                       (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::TransitionFromHovering(Enum_BoostJumpStates* TargetBoostState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "TransitionFromHovering");

	Params::GA_BoostJumpPack_C_TransitionFromHovering Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetBoostState != nullptr)
		*TargetBoostState = Parms.TargetBoostState;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.TransitionFromFalling
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// Enum_BoostJumpStates                    TargetBoostState                                       (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::TransitionFromFalling(Enum_BoostJumpStates* TargetBoostState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "TransitionFromFalling");

	Params::GA_BoostJumpPack_C_TransitionFromFalling Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetBoostState != nullptr)
		*TargetBoostState = Parms.TargetBoostState;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.ResetTransitionVariables
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::ResetTransitionVariables()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "ResetTransitionVariables");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.HandleHovering
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::HandleHovering()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "HandleHovering");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.HandleFalling
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::HandleFalling()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "HandleFalling");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.HandleIdle
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::HandleIdle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "HandleIdle");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Setup Notify at Apex
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bNotifyApex                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_BoostJumpPack_C::Setup_Notify_at_Apex(bool bNotifyApex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Setup Notify at Apex");

	Params::GA_BoostJumpPack_C_Setup_Notify_at_Apex Parms{};

	Parms.bNotifyApex = bNotifyApex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.PotentiallyEndHovering
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bForceEndHovering                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_BoostJumpPack_C::PotentiallyEndHovering(bool bForceEndHovering)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "PotentiallyEndHovering");

	Params::GA_BoostJumpPack_C_PotentiallyEndHovering Parms{};

	Parms.bForceEndHovering = bForceEndHovering;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.SetCurrentBoostState
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// EJumpBoostPackState                     NewState                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::SetCurrentBoostState(EJumpBoostPackState NewState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "SetCurrentBoostState");

	Params::GA_BoostJumpPack_C_SetCurrentBoostState Parms{};

	Parms.NewState = NewState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.HandleCurrentBoostStateChanged
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// EJumpBoostPackState                     PreviousState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EJumpBoostPackState                     Param_CurrentState                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::HandleCurrentBoostStateChanged(EJumpBoostPackState PreviousState, EJumpBoostPackState Param_CurrentState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "HandleCurrentBoostStateChanged");

	Params::GA_BoostJumpPack_C_HandleCurrentBoostStateChanged Parms{};

	Parms.PreviousState = PreviousState;
	Parms.Param_CurrentState = Param_CurrentState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.IsUsingJetpackEffectActive
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UGA_BoostJumpPack_C::IsUsingJetpackEffectActive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "IsUsingJetpackEffectActive");

	Params::GA_BoostJumpPack_C_IsUsingJetpackEffectActive Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Setup PlayerPawn
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Setup_PlayerPawn()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Setup PlayerPawn");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.K2_OnEndAbility
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_BoostJumpPack_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "K2_OnEndAbility");

	Params::GA_BoostJumpPack_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Consider Starting Regen Effect
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Consider_Starting_Regen_Effect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Consider Starting Regen Effect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Consider Stopping Regen Effect
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Consider_Stopping_Regen_Effect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Consider Stopping Regen Effect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Start Regen Effect
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Start_Regen_Effect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Start Regen Effect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Stop Regen Effect
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Stop_Regen_Effect()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Stop Regen Effect");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.ProcessTriggerData
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayTag                     TagOne                                                 (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::ProcessTriggerData(const struct FGameplayTag& TagOne)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "ProcessTriggerData");

	Params::GA_BoostJumpPack_C_ProcessTriggerData Parms{};

	Parms.TagOne = std::move(TagOne);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Reset Toggle Input State
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Reset_Toggle_Input_State()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Reset Toggle Input State");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.OnFuelIsFull
// (Event, Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::OnFuelIsFull()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "OnFuelIsFull");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.OnFuelIsEmpty
// (Event, Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::OnFuelIsEmpty()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "OnFuelIsEmpty");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.OnAbilityCanceled
// (Event, Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::OnAbilityCanceled()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "OnAbilityCanceled");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.SavePlayerPawn
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::SavePlayerPawn()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "SavePlayerPawn");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Reengage Hovering Movement
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Reengage_Hovering_Movement()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Reengage Hovering Movement");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Reengage Falling Movement
// (Public, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Reengage_Falling_Movement()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Reengage Falling Movement");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Handle Jetpack Equipped
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UGA_BoostJumpPack_C::Handle_Jetpack_Equipped()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Handle Jetpack Equipped");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.TransitionFromIdle
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// Enum_BoostJumpStates                    TargetBoostState                                       (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::TransitionFromIdle(Enum_BoostJumpStates* TargetBoostState) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "TransitionFromIdle");

	Params::GA_BoostJumpPack_C_TransitionFromIdle Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetBoostState != nullptr)
		*TargetBoostState = Parms.TargetBoostState;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.GetFuel
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// float                                   Fuel                                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::GetFuel(float* Fuel) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "GetFuel");

	Params::GA_BoostJumpPack_C_GetFuel Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Fuel != nullptr)
		*Fuel = Parms.Fuel;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.GetMaxFuel
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// float                                   MaxFuel                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_BoostJumpPack_C::GetMaxFuel(float* MaxFuel) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "GetMaxFuel");

	Params::GA_BoostJumpPack_C_GetMaxFuel Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (MaxFuel != nullptr)
		*MaxFuel = Parms.MaxFuel;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.K2_ShouldAbilityRespondToEvent
// (Event, Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// struct FGameplayAbilityActorInfo        ActorInfo                                              (BlueprintVisible, BlueprintReadOnly, Parm, ContainsInstancedReference)
// struct FGameplayEventData               Payload                                                (BlueprintVisible, BlueprintReadOnly, Parm)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UGA_BoostJumpPack_C::K2_ShouldAbilityRespondToEvent(const struct FGameplayAbilityActorInfo& ActorInfo, const struct FGameplayEventData& Payload) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "K2_ShouldAbilityRespondToEvent");

	Params::GA_BoostJumpPack_C_K2_ShouldAbilityRespondToEvent Parms{};

	Parms.ActorInfo = std::move(ActorInfo);
	Parms.Payload = std::move(Payload);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.IsBoostAllowed
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UGA_BoostJumpPack_C::IsBoostAllowed() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "IsBoostAllowed");

	Params::GA_BoostJumpPack_C_IsBoostAllowed Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.IsCurrentlyDead
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// struct FGameplayTag                     TagOne                                                 (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UGA_BoostJumpPack_C::IsCurrentlyDead(const struct FGameplayTag& TagOne) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "IsCurrentlyDead");

	Params::GA_BoostJumpPack_C_IsCurrentlyDead Parms{};

	Parms.TagOne = std::move(TagOne);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Get Player Pawn
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UObject*                          Object                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AFortPlayerPawn*                  ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class AFortPlayerPawn* UGA_BoostJumpPack_C::Get_Player_Pawn(class UObject* Object) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Get Player Pawn");

	Params::GA_BoostJumpPack_C_Get_Player_Pawn Parms{};

	Parms.Object = Object;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function GA_BoostJumpPack.GA_BoostJumpPack_C.Reasons To Reset on Transition
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure, Const)
// Parameters:
// struct FGameplayTag                     Tag                                                    (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UGA_BoostJumpPack_C::Reasons_To_Reset_on_Transition(const struct FGameplayTag& Tag) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_BoostJumpPack_C", "Reasons To Reset on Transition");

	Params::GA_BoostJumpPack_C_Reasons_To_Reset_on_Transition Parms{};

	Parms.Tag = std::move(Tag);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}
