#include <Windows.h>
#include <iostream>
#include <thread>
#include <detours.h>
#include <regex>
#include <unordered_map>
#include <fstream>
#include <intrin.h>

#include "Minhook/Minhook.h"
#pragma comment(lib,"Minhook/Minhook.lib")

#include "SDK.hpp"

#include "Globals.h"
#include "MinHook.h"
#include "Patterns.h"
#include "Util.h"

#include "Functions/Abilities.h"
#include "Functions/Inventory.h"
#include "Functions/Loots.h"
#include "Functions/Functions.h"
#include "Functions/Threads.h"

#include "Globals/GameMode.h"
#include "Globals/BuildingActor.h"
#include "Globals/PlayerController.h"
#include "Globals/Pawn.h"
#include "Globals/FortKismetLibrary.h"
#include "Globals/FortAthenaSupplyDrop.h"

#include "Functions/Cheats.h"
#include "Functions/Beacon.h"

#include <fstream>
#include "Hooks.h"
#include "InitFunc.h"

DWORD WINAPI MainThread(LPVOID)
{
    FILE* fDummy;
    AllocConsole();
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);

    MH_Initialize();

    SetConsoleTitleA("5.41 Odyssey");
    srand(time(0));

    if (true)
    {
        APlayerController* PlayerController = Globals::GetServerPlayerController();

        /*UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogNavigation VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogNavOctree Warning", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortNavigation VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortCheat VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortClientBot VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortLoot VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortLootQuota VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortAbility VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortInventoryUI VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortInventory VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortThreatVisuals VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortWind VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortEQS VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortGameDifficulty VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortGameUI VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortLoadingScreen VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortMission VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortAIGoalSelection VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortWorld VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortPlayerRegistration VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogBuilding VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortTeams VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortAI VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortAIDirector VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortQuest VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortUIDirector NoLogging", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogAbilitySystem VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogDataTable VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogMeshNetwork VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogEQS VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFort VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogGameMode VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogSpecialEvent VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogPlayerController VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogSpecialEventPhase VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogFortCustomization VeryVerbose", nullptr);
        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"log LogSpecialEventScriptMeshActor VeryVerbose", nullptr);*/

        if (PlayerController)
        {
            InitFunc::InitializeAll();

            UFortConsole* NewConsole = (UFortConsole*)UGameplayStatics::SpawnObject(UFortConsole::StaticClass(), UEngine::GetEngine()->GameViewport);

            if (NewConsole)
                UEngine::GetEngine()->GameViewport->ViewportConsole = NewConsole;

            PlayerController->SwitchLevel(L"Athena_Terrain");

            Hooks::InitHook();
        }

        *(bool*)Hooks::GIsClient() = false;
        *(bool*)Hooks::GIsServer() = true;

        FN_LOG(LogInitialize, Log, "Init Success!");
    }
    else
    {
        FN_LOG(LogInitialize, Log, "Init Failed!");
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID res)
{
    if (reason == 1)
        CreateThread(0, 0, MainThread, mod, 0, 0);

    return TRUE;
}