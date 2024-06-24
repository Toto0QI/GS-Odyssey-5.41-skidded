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
#ifdef CHEATS
            AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
            auto Params = (Params::FortPlayerController_ServerCheat*)Parms;

            if (PlayerController && Params->Msg.IsValid())
            {
                std::string Command = Params->Msg.ToString();
                std::vector<std::string> ParsedCommand = split(Command, ' ');
                AFortPawn* Pawn = (AFortPawn*)PlayerController->Pawn;

                if (!ParsedCommand.empty())
                {
                    std::string Action = ParsedCommand[0];
                    std::transform(Action.begin(), Action.end(), Action.begin(),
                        [](unsigned char c) { return std::tolower(c); });

                    FString Message = L"Unknown Command";

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
                    else if (Action == "godmode" && Pawn)
                    {
                        Pawn->bIsInvulnerable = Pawn->bIsInvulnerable ? false : true;
                        Message = Pawn->bIsInvulnerable ? L"GodMode on" : L"GodMode off";
                    }
                    else if (Action == "tpto" && ParsedCommand.size() >= 4 && Pawn)
                    {
                        bool bIsNumberToPosX = std::all_of(ParsedCommand[1].begin(), ParsedCommand[1].end(), ::isdigit);
                        bool bIsNumberToPosY = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);
                        bool bIsNumberToPosZ = std::all_of(ParsedCommand[3].begin(), ParsedCommand[3].end(), ::isdigit);

                        if (bIsNumberToPosX && bIsNumberToPosY && bIsNumberToPosZ)
                        {
                            FVector Vector;
                            Vector.X = std::stoi(ParsedCommand[1]);
                            Vector.Y = std::stoi(ParsedCommand[2]);
                            Vector.Z = std::stoi(ParsedCommand[3]);

                            Pawn->K2_TeleportTo(Vector, FRotator());

                            Message = L"Pawn successful teleport!";
                        }
                        else
                        {
                            Message = L"Invalid location!";
                        }
                    }
                    else if (Action == "spawnloot" && ParsedCommand.size() >= 2)
                    {
                        std::string& LootTierGroup = ParsedCommand[1];

                        FName SearchLootTierGroup = Globals::GetStringLibrary()->Conv_StringToName(std::wstring(LootTierGroup.begin(), LootTierGroup.end()).c_str());

                        bool bSuccess;
                        std::vector<FFortItemEntry> LootToDrops = Loots::ChooseLootToDrops(SearchLootTierGroup, 0 , &bSuccess);

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
                            Message = L"Failed to find this LootTierGroup!";
                        }
                    }
                    else if (Action == "spawnpickup" && ParsedCommand.size() >= 3 && Pawn)
                    {
                        std::string ItemDefinitionName = ParsedCommand[1];

                        std::transform(ItemDefinitionName.begin(), ItemDefinitionName.end(), ItemDefinitionName.begin(),
                            [](unsigned char c) { return std::tolower(c); });

                        int32 NumberToSpawn = 0;

                        bool bIsNumberToSpawnInt = std::all_of(ParsedCommand[2].begin(), ParsedCommand[2].end(), ::isdigit);

                        if (bIsNumberToSpawnInt)
                            NumberToSpawn = std::stoi(ParsedCommand[2]);

                        TArray<UFortWorldItemDefinition*> AllItems = Functions::GetAllItems();

                        for (int i = 0; i < AllItems.Num(); i++)
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
                            break;
                        }

                        Message = L"Pickup success spawn!";
                    }
                    else if (Action == "rtx" && ParsedCommand.size() >= 1 && Pawn)
                    {
                        TArray<UFortWorldItemDefinition*> AllItems = Functions::GetAllItems(true);

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

                    PlayerController->ClientMessage(Message, FName(), 1);
                }
            }
#endif // CHEATS
        }
    }

    void InitCheats()
    {
        FN_LOG(LogInit, Log, "InitCheats Success!");
    }
}