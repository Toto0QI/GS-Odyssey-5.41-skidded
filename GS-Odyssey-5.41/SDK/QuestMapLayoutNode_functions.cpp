#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: QuestMapLayoutNode

#include "Basic.hpp"

#include "QuestMapLayoutNode_classes.hpp"
#include "QuestMapLayoutNode_parameters.hpp"


namespace SDK
{

// Function QuestMapLayoutNode.QuestMapLayoutNode_C.ExecuteUbergraph_QuestMapLayoutNode
// ()
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UQuestMapLayoutNode_C::ExecuteUbergraph_QuestMapLayoutNode(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestMapLayoutNode_C", "ExecuteUbergraph_QuestMapLayoutNode");

	Params::QuestMapLayoutNode_C_ExecuteUbergraph_QuestMapLayoutNode Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuestMapLayoutNode.QuestMapLayoutNode_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UQuestMapLayoutNode_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestMapLayoutNode_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function QuestMapLayoutNode.QuestMapLayoutNode_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UQuestMapLayoutNode_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestMapLayoutNode_C", "PreConstruct");

	Params::QuestMapLayoutNode_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function QuestMapLayoutNode.QuestMapLayoutNode_C.SetQuestTileProps
// (Public, BlueprintCallable, BlueprintEvent)

void UQuestMapLayoutNode_C::SetQuestTileProps()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("QuestMapLayoutNode_C", "SetQuestTileProps");

	UObject::ProcessEvent(Func, nullptr);
}

}
