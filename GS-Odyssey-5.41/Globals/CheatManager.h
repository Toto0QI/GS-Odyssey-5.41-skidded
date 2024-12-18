#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace CheatManager
{
	/* ------------------------------------- UFortCheatManagerOG ------------------------------------- */
	bool (*ReadyToStartMatchOG)(AFortGameModeAthena* GameModeAthena);
	void (*HandlePostSafeZonePhaseChangedOG)(AFortGameModeAthena* GameModeAthena);
	bool (*StartAircraftPhaseOG)(AFortGameModeAthena* GameModeAthena);


	/* -------------------------------------- UFortCheatManager -------------------------------------- */


	void InitCheatManager()
	{
		UFortCheatManager* FortCheatManagerDefault = UFortCheatManager::GetDefaultObj();
		UClass* FortCheatManagerClass = UFortCheatManager::StaticClass();

		/* -------------------------------------- UFortCheatManager -------------------------------------- */

		

		/* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, L"InitCheatManager Success!");
	}
}