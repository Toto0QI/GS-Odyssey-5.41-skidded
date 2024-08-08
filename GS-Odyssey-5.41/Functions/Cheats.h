#pragma once

#include <algorithm>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <sstream>

namespace Cheats
{
    std::vector<std::string> split(const std::string& s, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void ProcessEventHook(UObject* Object, UFunction* Function, void* Parms)
    {
        if (!Object || !Function)
            return;

        const std::string& FunctionName = Function->GetName();

        if (FunctionName.contains("ServerCheat"))
        {
            AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
            auto Params = (Params::FortPlayerController_ServerCheat*)Parms;

            if (PlayerController && Params->Msg.IsValid())
            {
                std::string Command = Params->Msg.ToString();
                std::vector<std::string> ParsedCommand = split(Command, ' ');

                if (!ParsedCommand.empty())
                {
                    std::string Action = ParsedCommand[0];
                    std::transform(Action.begin(), Action.end(), Action.begin(),
                        [](unsigned char c) { return std::tolower(c); });

                    FString Message = L"Unknown Command";

                    UCheatManager* CheatManager = PlayerController->CheatManager;
                    AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;
                    AFortPlayerPawn* Pawn = PlayerController->MyFortPawn;

                    if (Action == "listplayers")
                    {
                        AFortGameModeAthena* GameMode = Globals::GetGameMode();

                        if (GameMode)
                        {
                            TArray<AFortPlayerController*> AllFortPlayerController = UFortKismetLibrary::GetAllFortPlayerControllers(GameMode, true, false);

                            int32 NumPlayers = 0;

                            for (int32 i = 0; i < AllFortPlayerController.Num(); i++)
                            {
                                AFortPlayerControllerAthena* FortPlayerController = (AFortPlayerControllerAthena*)AllFortPlayerController[i];
                                if (!FortPlayerController) continue;

                                if (!FortPlayerController->PlayerState)
                                    continue;

                                NumPlayers++;

                                std::string LootMessage = "[" + std::to_string(NumPlayers) + "] - PlayerName: " + FortPlayerController->PlayerState->GetPlayerName().ToString();
                                FString FLootMessage = std::wstring(LootMessage.begin(), LootMessage.end()).c_str();
                                PlayerController->ClientMessage(FLootMessage, FName(), 1);

                                Message = L"null";
                            }
                        }
                        else
                        {
                            Message = L"GameMode not found!";
                        }
                    }
#ifdef CHEATS
                    if (Action == "buildfree")
                    {
                        PlayerController->bBuildFree = PlayerController->bBuildFree ? false : true;
                        Message = PlayerController->bBuildFree ? L"BuildFree on" : L"BuildFree off";
                    }
                    else if (Action == "infiniteammo")
                    {
                        PlayerController->bInfiniteAmmo = PlayerController->bInfiniteAmmo ? false : true;
                        Message = PlayerController->bInfiniteAmmo ? L"InfiniteAmmo on" : L"InfiniteAmmo off";
                    }
                    else if (Action == "pausesafezone")
                    {
                        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"pausesafezone", nullptr);
                        Message = L"PauseSafeZone command executed successfully!";
                    }
                    else if (Action == "skipsafezone")
                    {
                        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"skipsafezone", nullptr);
                        Message = L"SkipSafeZone command executed successfully!";
                    }
                    else if (Action == "skipshrinksafezone")
                    {
                        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"skipshrinksafezone", nullptr);
                        Message = L"SkipShrinkSafeZone command executed successfully!";
                    }
                    else if (Action == "startshrinksafezone")
                    {
                        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"startshrinksafezone", nullptr);
                        Message = L"StartShrinkSafeZone command executed successfully!";
                    }
                    else if (Action == "startaircraft")
                    {
                        UKismetSystemLibrary::ExecuteConsoleCommand(Globals::GetWorld(), L"startaircraft", nullptr);
                        Message = L"StartAirCraft command executed successfully!";
                    }
                    else if (Action == "sethealth" && ParsedCommand.size() >= 2)
                    {
                        if (Pawn)
                        {
                            try
                            {
                                float NewHealthVal = std::stof(ParsedCommand[1]);

                                Pawn->SetHealth(NewHealthVal);
                                Message = L"SetHealth command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid NewHealthVal provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"NewHealthVal out of range!";
                            }
                        }
                        else
                        {
                            Message = L"Pawn not found!";
                        }
                    }
                    else if (Action == "setshield" && ParsedCommand.size() >= 2)
                    {
                        if (Pawn)
                        {
                            try
                            {
                                float NewShieldVal = std::stof(ParsedCommand[1]);

                                // 7FF66F7BC760 (Je suis sévèrement autiste)
                                void (*SetShield)(AFortPawn* Pawn, float NewShieldValue) = decltype(SetShield)(0x116C760 + uintptr_t(GetModuleHandle(0)));
                                SetShield(Pawn, NewShieldVal);
                                Message = L"SetShield command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid NewShieldVal provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"NewShieldVal out of range!";
                            }
                        }
                        else
                        {
                            Message = L"Pawn not found!";
                        }
                    }
                    else if (Action == "setmaxhealth" && ParsedCommand.size() >= 2)
                    {
                        if (Pawn)
                        {
                            try
                            {
                                float NewHealthVal = std::stof(ParsedCommand[1]);

                                Pawn->SetMaxHealth(NewHealthVal);
                                Message = L"SetMaxHealth command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid NewHealthVal provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"NewHealthVal out of range!";
                            }
                        }
                        else
                        {
                            Message = L"Pawn not found!";
                        }
                    }
                    else if (Action == "setmaxshield" && ParsedCommand.size() >= 2)
                    {
                        if (Pawn)
                        {
                            try
                            {
                                float NewShieldVal = std::stof(ParsedCommand[1]);

                                Pawn->SetMaxShield(NewShieldVal);
                                Message = L"SetMaxShield command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid NewShieldVal provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"NewShieldVal out of range!";
                            }
                        }
                        else
                        {
                            Message = L"Pawn not found!";
                        }
                    }
                    else if (Action == "god")
                    {
                        if (CheatManager)
                        {
                            CheatManager->God();
                            Message = L"null";
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
                    else if (Action == "destroytarget")
                    {
                        if (CheatManager)
                        {
                            CheatManager->DestroyTarget();
                            Message = L"Target successfully destroyed!";
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
                    else if (Action == "tp")
                    {
                        if (CheatManager)
                        {
                            CheatManager->Teleport();
                            Message = L"Teleportation successful!";
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
                    else if (Action == "tpw")
                    {
                        AFortPlayerStateAthena* PlayerState = (AFortPlayerStateAthena*)PlayerController->PlayerState;

                        if (PlayerState)
                        {
                            FVector MarkerPosition = PlayerState->LocalWorldMapMarker->MarkerPosition2D;

                            MarkerPosition.Z = 10000;

                            CheatManager->BugItGo(MarkerPosition.X, MarkerPosition.Y, MarkerPosition.Z, 0.f, 0.f, 0.f);
                        }
                    }
                    else if (Action == "changesize" && ParsedCommand.size() >= 2)
                    {
                        if (CheatManager)
                        {
                            try
                            {
                                float NewSize = std::stof(ParsedCommand[1]);

                                CheatManager->ChangeSize(NewSize);
                                Message = L"ChangeSize command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid NewSize provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"NewSize out of range!";
                            }
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
                    else if (Action == "bugitgo" && ParsedCommand.size() >= 4)
                    {
                        if (CheatManager)
                        {
                            try
                            {
                                float X = std::stof(ParsedCommand[1]);
                                float Y = std::stof(ParsedCommand[2]);
                                float Z = std::stof(ParsedCommand[3]);

                                CheatManager->BugItGo(X, Y, Z, 0.f, 0.f, 0.f);
                                Message = L"BugItGo command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid coordinates provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"Coordinates out of range!";
                            }
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
                    else if (Action == "launchpawn" && ParsedCommand.size() >= 4)
                    {
                        if (Pawn)
                        {
                            try
                            {
                                float X = std::stof(ParsedCommand[1]);
                                float Y = std::stof(ParsedCommand[2]);
                                float Z = std::stof(ParsedCommand[3]);

                                Pawn->LaunchPawn(FVector(X, Y, Z), false, false);
                                Message = L"LaunchPawn command executed successfully!";
                            }
                            catch (const std::invalid_argument& e)
                            {
                                Message = L"Invalid coordinates provided!";
                            }
                            catch (const std::out_of_range& e)
                            {
                                Message = L"Coordinates out of range!";
                            }
                        }
                        else
                        {
                            Message = L"Pawn not found!";
                        }
                    }
                    else if (Action == "summon" && ParsedCommand.size() >= 2)
                    {
                        if (CheatManager)
                        {
                            std::string& ClassName = ParsedCommand[1];

                            CheatManager->Summon(std::wstring(ClassName.begin(), ClassName.end()).c_str());

                            Message = L"Summon successful!";
                        }
                        else
                        {
                            Message = L"CheatManager not found!";
                        }
                    }
#ifdef DEBUGS
                    else if (Action == "simulateloot" && ParsedCommand.size() >= 3)
                    {
                        std::string& LootTierGroup = ParsedCommand[1];
                        int32 LootTier = 0;

                        bool bIsLootTierInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

                        if (CheatManager && bIsLootTierInt)
                        {
                            FName TierGroup = UKismetStringLibrary::Conv_StringToName(std::wstring(LootTierGroup.begin(), LootTierGroup.end()).c_str());

                            LootTier = std::stoi(ParsedCommand[2]);

                            bool bSuccess;
                            std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(TierGroup, LootTier, &bSuccess);

                            if (bSuccess)
                            {
                                for (auto& LootToDrop : LootToDrops)
                                {
                                    if (!LootToDrop.ItemDefinition)
                                        continue;

                                    std::string LootMessage = "SimulateLoot | ItemDefinition: [" + LootToDrop.ItemDefinition->GetName() + "] - Count: [" + std::to_string(LootToDrop.Count) + "]";
                                    FString FLootMessage = std::wstring(LootMessage.begin(), LootMessage.end()).c_str();
                                    PlayerController->ClientMessage(FLootMessage, FName(), 1);
                                }

                                Message = L"SimulateLoot success!";
                            }
                            else
                            {
                                Message = L"Failed SimulateLoot!";
                            }
                        }
                        else
                        {
                            if (!CheatManager)
                            {
                                Message = L"CheatManager not found!";
                            }
                            else if (!bIsLootTierInt)
                            {
                                Message = L"Invalid LootTier provided!";
                            }
                        }
                    }
#endif // DEBUGS
                    else if (Action == "spawnloot" && ParsedCommand.size() >= 2)
                    {
                        std::string& LootTierGroup = ParsedCommand[1];

                        FName SearchLootTierGroup = UKismetStringLibrary::Conv_StringToName(std::wstring(LootTierGroup.begin(), LootTierGroup.end()).c_str());

                        bool bSuccess;
                        std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(SearchLootTierGroup, 0, &bSuccess);

                        if (bSuccess && Pawn)
                        {
                            for (auto& LootToDrop : LootToDrops)
                            {
                                Inventory::SpawnPickup(nullptr, &LootToDrop, Pawn->K2_GetActorLocation(), true);
                            }

                            Message = L"LootTierGroup success spawn!";
                        }
                        else
                        {
                            if (!Pawn)
                            {
                                Message = L"Pawn not found!";
                            }
                            else
                            {
                                Message = L"Failed to find this LootTierGroup!";
                            }
                        }
                    }
                    else if (Action == "spawnpickup" && ParsedCommand.size() >= 3)
                    {
                        std::string ItemDefinitionName = ParsedCommand[1];

                        std::transform(ItemDefinitionName.begin(), ItemDefinitionName.end(), ItemDefinitionName.begin(),
                            [](unsigned char c) { return std::tolower(c); });

                        int32 NumberToSpawn = 0;

                        bool bIsNumberToSpawnInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

                        TArray<UFortWorldItemDefinition*> AllItems = Functions::GetAllItems();

                        bool bItemFound = false;

                        if (Pawn && bIsNumberToSpawnInt)
                        {
                            NumberToSpawn = std::stoi(ParsedCommand[2]);

                            if (NumberToSpawn <= 10000 && NumberToSpawn > 0)
                            {
                                for (int32 i = 0; i < AllItems.Num(); i++)
                                {
                                    UFortWorldItemDefinition* ItemDefinition = AllItems[i];

                                    if (!ItemDefinition)
                                        continue;

                                    std::string ItemDefinitionName2 = ItemDefinition->GetName();

                                    std::transform(ItemDefinitionName2.begin(), ItemDefinitionName2.end(), ItemDefinitionName2.begin(),
                                        [](unsigned char c) { return std::tolower(c); });

                                    if (ItemDefinitionName2 != ItemDefinitionName)
                                        continue;

                                    UFortKismetLibrary::K2_SpawnPickupInWorld(PlayerController, ItemDefinition, NumberToSpawn, Pawn->K2_GetActorLocation(), FVector(), 0, true, true, false);
                                    bItemFound = true;
                                    break;
                                }

                                if (bItemFound)
                                {
                                    Message = L"Pickup successfully spawned!";
                                }
                                else
                                {
                                    Message = L"Item definition not found!";
                                }
                            }
                            else
                            {
                                Message = L"Invalid number to spawn (NumberToSpawn <= 10000 && NumberToSpawn > 0)";
                            }
                        }
                        else
                        {
                            if (!Pawn)
                            {
                                Message = L"Pawn not found!";
                            }
                            else if (!bIsNumberToSpawnInt)
                            {
                                Message = L"Invalid number to spawn!";
                            }
                        }
                    }
                    else if (Action == "rtx" && ParsedCommand.size() >= 1)
                    {
                        TArray<UFortWorldItemDefinition*> AllItems = Functions::GetAllItems(true);

                        if (AllItems.Num() > 0 && Pawn)
                        {
                            for (int i = 0; i < AllItems.Num(); i++)
                            {
                                UFortWorldItemDefinition* ItemDefinition = AllItems[i];

                                if (!ItemDefinition)
                                    continue;

                                if (ItemDefinition->Rarity != EFortRarity::Fine)
                                    continue;

                                UFortKismetLibrary::K2_SpawnPickupInWorld(PlayerController, ItemDefinition, 1, Pawn->K2_GetActorLocation(), FVector(), 0, true, true, false);
                            }

                            Message = L"TEUPAIIII!";
                        }
                        else
                        {
                            if (!Pawn)
                            {
                                Message = L"Pawn not found!";
                            }
                            else
                            {
                                Message = L"No items found to spawn!";
                            }
                        }
                    }
#endif // CHEATS
                    if (Message != L"null")
                        PlayerController->ClientMessage(Message, FName(), 1);
                }
            }
        }
    }

    void InitCheats()
    {
        FN_LOG(LogInit, Log, "InitCheats Success!");
    }
}