#pragma once
#include <map>

#ifdef ANTICHEAT
enum ACLogLevel 
{
	ACLog,
	ACWarning,
	ACError
};

void WriteLogAntiCheat(ACLogLevel level, const char* format, ...)
{
	const char* levelStr;

	switch (level) {
		case ACLogLevel::ACLog: levelStr = "Info"; break;
		case ACLogLevel::ACWarning: levelStr = "Warning"; break;
		case ACLogLevel::ACError: levelStr = "Error"; break;
		default: levelStr = "Unknown"; break;
	}

	printf("LogOdysseyAC: %s: ", levelStr);

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);

	printf("\n");
}

#define AC_LOG(Level, ...) WriteLogAntiCheat(Level, __VA_ARGS__)

enum class EAntiCheatDetection : uint8
{
	None = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	Critical = 4,
	EAntiCheatDetection_MAX
};

extern inline float MaxPickaxeDistance = 300.0f;
extern inline float MaxPickupDistance = 550.0f;
extern inline float MaxInteractDistance = 750.0f;
extern inline float MaxBuildingActorDistance = 2250.0f;

class UAntiCheatOdyssey final
{
public:
	static inline std::map<APlayerController*, UAntiCheatOdyssey*> AntiCheatOdysseyMap;

	APlayerController* PlayerController;
	FString PlayerName;
	EAntiCheatDetection AntiCheatDetection = EAntiCheatDetection::None;
	bool bServerReadyToStartMatch = false;
	AFortPlayerPawn* PlayerPawnAntiAimbot = nullptr;

	APlayerController* GetPlayerController() const
	{
		return PlayerController;
	}

	AFortPlayerController* GetFortPlayerController() const
	{
		return Cast<AFortPlayerController>(PlayerController);
	}

	FString GetPlayerName() const
	{
		return PlayerName;
	}

	float GetMaxPickaxeDistance() const
	{
		return MaxPickaxeDistance;
	}

	float GetMaxPickupDistance() const
	{
		return MaxPickupDistance;
	}

	float GetMaxInteractDistance() const
	{
		return MaxInteractDistance;
	}

	float GetMaxBuildingActorDistance() const
	{
		return MaxBuildingActorDistance;
	}

	void KickByAntiCheat(const FString& Reason)
	{
		if (PlayerController)
		{
			AC_LOG(ACWarning, "The Anti Cheat has just been kicked PlayerController: [%s]", PlayerController->GetName().c_str());

			AFortPlayerController* FortPlayerController = GetFortPlayerController();

			if (FortPlayerController && FortPlayerController->Pawn)
				FortPlayerController->ServerSuicide();

			PlayerController->ClientReturnToMainMenu(Reason);

			if (PlayerController->NetConnection)
			{
				// 7FF670C83060
				void (*Close)(UNetConnection* NetConnection) = decltype(Close)(0x2633060 + uintptr_t(GetModuleHandle(0)));
				Close(PlayerController->NetConnection);
			}

			AntiCheatOdysseyMap.erase(PlayerController);
		}
	}

	void BanByAntiCheat(const FString& Reason)
	{
		// Code pour ban depuis le backend

		KickByAntiCheat(Reason);
	}

	void InitAntiCheatOdyssey(APlayerController* InPC)
	{
		if (!InPC || !InPC->PlayerState)
		{
			if (InPC)
			{
				PlayerController = InPC;
				KickByAntiCheat(L"Unable to Init AC!\nPlease contact a developer to fix this problem.");
			}

			AC_LOG(ACLogLevel::ACError, "Failed to InitAntiCheatOdyssey!");
			return;
		}

		PlayerController = InPC;
		PlayerName = PlayerController->PlayerState->GetPlayerName();
	}

	void DeleteAntiCheatOdyssey(APlayerController* InPC)
	{
		if (!InPC || !InPC->PlayerState)
		{
			AC_LOG(ACLogLevel::ACError, "Failed to InitAntiCheatOdyssey!");
			return;
		}

		if (AntiCheatOdysseyMap.contains(InPC));
			AntiCheatOdysseyMap.erase(InPC);
	}

	AFortPlayerPawn* GetOrCreatePlayerPawnAntiAimbot()
	{
		if (!PlayerPawnAntiAimbot || PlayerPawnAntiAimbot->bActorIsBeingDestroyed)
		{
			PlayerPawnAntiAimbot = Util::SpawnActor<AFortPlayerPawn>(APlayerPawn_Athena_C::StaticClass());

			if (PlayerPawnAntiAimbot)
			{
				PlayerPawnAntiAimbot->bIsScriptedBot = true;
				PlayerPawnAntiAimbot->bCanBeDamaged = false;
				
				PlayerPawnAntiAimbot->SetActorEnableCollision(false);
			}
		}

		return PlayerPawnAntiAimbot;
	}
};

static UAntiCheatOdyssey* CreateAntiCheatOdyssey(APlayerController* PlayerController)
{
	UAntiCheatOdyssey* NewClass = new UAntiCheatOdyssey;
	NewClass->InitAntiCheatOdyssey(PlayerController);
	UAntiCheatOdyssey::AntiCheatOdysseyMap.insert_or_assign(PlayerController, NewClass);
	return NewClass;
}

static UAntiCheatOdyssey* FindOrCreateAntiCheatOdyssey(APlayerController* PlayerController)
{
	UAntiCheatOdyssey* AntiCheatOdyssey = nullptr;

	if (!PlayerController)
		return AntiCheatOdyssey;

	for (auto& Find : UAntiCheatOdyssey::AntiCheatOdysseyMap)
	{
		if (Find.first == PlayerController)
		{
			AntiCheatOdyssey = Find.second;
			break;
		}
	}

	if (!AntiCheatOdyssey)
		AntiCheatOdyssey = CreateAntiCheatOdyssey(PlayerController);

	return AntiCheatOdyssey;
}

namespace AntiCheatOdyssey
{
	void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
	{
		if (!Object || !Function)
			return;

		/*const std::string& FunctionName = Function->GetName();

		if (FunctionName.contains("Tick"))
		{
			for (auto& Find : UAntiCheatOdyssey::AntiCheatOdysseyMap)
			{
				UAntiCheatOdyssey* AntiCheatOdyssey = Find.second;

				if (!AntiCheatOdyssey) 
					continue;

				AFortPlayerController* PlayerController = AntiCheatOdyssey->GetFortPlayerController();
				AFortPlayerPawn* PlayerPawn = PlayerController->MyFortPawn;

				if (!PlayerController || !PlayerPawn)
					continue;

				AFortPlayerPawn* PlayerPawnAntiAimbot = AntiCheatOdyssey->GetOrCreatePlayerPawnAntiAimbot();

				if (PlayerPawnAntiAimbot)
				{
					FVector PawnLocation = PlayerPawn->K2_GetActorLocation();

					PawnLocation += PlayerPawn->GetActorForwardVector() * (PlayerPawn->IsInVehicle() ? 400.0f : 250.0f);
					PawnLocation.Z += 150.0f; 
					PawnLocation.Y += 30.0f;

					FRotator PlayerRotation = PlayerPawn->K2_GetActorRotation();

					FRotator InvertedRotation = PlayerRotation;
					InvertedRotation.Pitch += 180.0f;
					InvertedRotation.Roll = 0.0f;

					FHitResult HitResult;
					PlayerPawnAntiAimbot->K2_SetActorLocationAndRotation(PawnLocation, InvertedRotation, false, &HitResult, false);

				}
			}
		}*/
	}
}

#endif // ANTICHEAT