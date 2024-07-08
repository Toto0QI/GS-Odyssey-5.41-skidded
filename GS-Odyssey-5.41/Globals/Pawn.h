#pragma once

namespace Pawn
{
	void (*SetPickupTarget)(AFortPickup* Pickup, AFortPlayerPawn* Pawn, float InFlyTime, const FVector& InStartDirection);

	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("ServerHandlePickupWithSwap")) // Finir la fonction
		{
			AFortPlayerPawn* Pawn = (AFortPlayerPawn*)Object;
			auto Params = (Params::FortPlayerPawn_ServerHandlePickupWithSwap*)Parms;

			FN_LOG(LogPawn, Log, "[AFortPlayerPawn::ServerHandlePickupWithSwap] func called!");
		}
		else if (FunctionName.contains("ServerHandlePickup"))
		{
			AFortPlayerPawn* Pawn = (AFortPlayerPawn*)Object;
			auto Params = (Params::FortPlayerPawn_ServerHandlePickup*)Parms;

			if (!Pawn || !Pawn->Controller || !Params->Pickup)
			{
				FN_LOG(LogPawn, Error, "[AFortPlayerPawn::ServerHandlePickup] Failed to get Pawn/Controller/Pickup!");
				return;
			}

			if (Params->Pickup->bPickedUp)
				return;

			SetPickupTarget(Params->Pickup, Pawn, Globals::GetMathLibrary()->RandomFloatInRange(0.40f, 0.54f), FVector());

			FFortPickupLocationData* PickupLocationData = &Params->Pickup->PickupLocationData;
			PickupLocationData->PickupGuid = Pawn->CurrentWeapon ? Pawn->CurrentWeapon->ItemEntryGuid : FGuid();
			Params->Pickup->OnRep_PickupLocationData();
		}
		else if (FunctionName.contains("OnCapsuleBeginOverlap"))
		{
			AFortPlayerPawn* Pawn = (AFortPlayerPawn*)Object;
			auto Params = (Params::FortPlayerPawn_OnCapsuleBeginOverlap*)Parms;

			if (!Pawn || !Params->OtherActor)
				return;

			AFortPlayerController* PlayerController = (AFortPlayerController*)Pawn->Controller;

			if (!PlayerController)
				return;

			if (Params->OtherActor->IsA(AFortPickup::StaticClass()))
			{
				AFortPickup* Pickup = (AFortPickup*)Params->OtherActor;

				if (!Pickup || Pickup->bPickedUp)
					return;

				if (!Pickup->bServerStoppedSimulation && Pickup->PawnWhoDroppedPickup)
					return;

				UFortItemDefinition* ItemDefinition = Pickup->PrimaryPickupItemEntry.ItemDefinition;

				if (ItemDefinition)
				{
					if (ItemDefinition->IsA(UFortAmmoItemDefinition::StaticClass()) ||
						ItemDefinition->IsA(UFortTrapItemDefinition::StaticClass()) ||
						ItemDefinition->IsA(UFortResourceItemDefinition::StaticClass()))
					{
						const FVector& InStartDirection = Params->OtherActor->K2_GetActorLocation();
						Pawn->ServerHandlePickup(Pickup, 0.f, InStartDirection, true);
					}
				}
			}
		}
		else if (FunctionName.contains("OnDeathServer"))
		{
			AFortPawn* Pawn = (AFortPawn*)Object;

			if (Pawn->IsA(AFortPawn::StaticClass()))
			{
				AFortPlayerController* PlayerController = (AFortPlayerController*)Pawn->Controller;

				if (!PlayerController)
					return;

				Inventory::DropAllItemsFromInventory(PlayerController);
				Inventory::UpdateInventory(PlayerController->WorldInventory);
			}
		}
	}


	void InitPawn()
	{
		static auto FortPlayerPawnAthenaDefault = AFortPlayerPawnAthena::GetDefaultObj();

		uintptr_t PatternSetPickupTarget = MinHook::FindPattern(Patterns::SetPickupTarget);

		SetPickupTarget = decltype(SetPickupTarget)(PatternSetPickupTarget);

		FN_LOG(LogInit, Log, "InitPawn Success!");
	}
}