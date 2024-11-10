#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace BuildingProp
{
	/* --------------------------------------- ABuildingPropOG --------------------------------------- */
	void (*ABuildingContainer_PostUpdateOG)(ABuildingContainer* BuildingContainer, EFortBuildingPersistentState BuildingPersistentState, __int64 a3);



	/* ---------------------------------------- ABuildingProp ---------------------------------------- */

	void BlueprintCanInteract(ABuildingProp* BuildingProp, FFrame& Stack, void* Ret)
	{


		FN_LOG(LogGameMode, Log, "[ABuildingProp::BlueprintCanInteract]");
	}

	void InitBuildingProp()
	{
		ABuildingProp* BuildingPropDefault = ABuildingProp::GetDefaultObj();
		UClass* BuildingPropClass = ABuildingProp::StaticClass();

		// ABuildingProp* Prop_QuestInteractable_ParentDefault = Cast<ABuildingProp>(StaticLoadObject<UClass>(L"/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C")->CreateDefaultObject());
		// UClass* Prop_QuestInteractable_ParentClass = StaticLoadObject<UClass>(L"/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C");

		/* ---------------------------------------- ABuildingProp ---------------------------------------- */

		// UFunction* BlueprintCanInteractFunc = Prop_QuestInteractable_ParentClass->GetFunction("Prop_QuestInteractable_Parent_C", "BlueprintCanInteract");
		// MinHook::HookFunctionExec(BlueprintCanInteractFunc, BlueprintCanInteract, nullptr);

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, "InitBuildingActor Success!");
	}
}