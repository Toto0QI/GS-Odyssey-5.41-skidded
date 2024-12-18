#pragma once

/*
 * - The explanations were made with chatgpt (I was too lazy to do it)
*/

namespace GameState
{
	/* ----------------------------------- AFortGameStateAthenaOG ------------------------------------ */
	bool (*ReadyToStartMatchOG)(AFortGameModeAthena* GameModeAthena);
	void (*HandlePostSafeZonePhaseChangedOG)(AFortGameModeAthena* GameModeAthena);
	bool (*StartAircraftPhaseOG)(AFortGameModeAthena* GameModeAthena);



	/* ------------------------------------ AFortGameStateAthena ------------------------------------- */

    /*
     * IsOutOfSafeZone checks if a specified location is outside the current safe zone.
     *
     * - Retrieves the location of the safe zone mesh component from `SafeZoneIndicator`.
     * - Calculates the Euclidean distance between the given location and the center of the safe zone.
     * - Compares the distance to the safe zone radius:
     *      - If the distance is greater than the radius, the location is outside the safe zone.
     *      - Returns true if outside the safe zone, otherwise false.
     */
    bool IsOutOfSafeZone(AFortSafeZoneIndicator* SafeZoneIndicator, FVector Location)
    {
        UStaticMeshComponent* SafeZoneMesh = SafeZoneIndicator->SafeZoneMesh;
        const FVector& ComponentLocation = SafeZoneMesh->K2_GetComponentLocation();

        float v3 = ComponentLocation.Y;
        float v4 = ComponentLocation.X - Location.X;
        return std::sqrt((v3 - Location.Y) * (v3 - Location.Y) + v4 * v4) <= SafeZoneIndicator->Radius;
    }

    /*
     * IsRespawningAllowed checks if respawning is allowed for a player based on game state conditions and the current playlist.
     *
     * - Retrieves the current playlist data from `GameStateAthena`; if unavailable, returns false.
     * - Determines respawn permission based on `RespawnType`:
     *      - If `RespawnType` is `InfiniteRespawn`, always allows respawning.
     *      - If `RespawnType` is `InfiniteRespawnExceptStorm`, additional checks are made:
     *          - If no safe zone is defined, respawning is allowed.
     *          - Checks the player's `DeathInfo` to see if they died outside the safe zone.
     *              - If the death location is outside the safe zone, allows respawning.
     * - Returns true if respawning is allowed based on the conditions, otherwise false.
     */
	bool IsRespawningAllowed(AFortGameStateAthena* GameStateAthena, AFortPlayerState* PlayerState)
	{
        AFortPlayerStateAthena* PlayerStateAthena = Cast<AFortPlayerStateAthena>(PlayerState);
        if (!PlayerStateAthena) return false;

        UFortPlaylistAthena* CurrentPlaylistData = GameStateAthena->CurrentPlaylistData;
        if (!CurrentPlaylistData) return false;

        EAthenaRespawnType RespawnType = CurrentPlaylistData->RespawnType;

        if (RespawnType == EAthenaRespawnType::InfiniteRespawn)
            return true;

        if (RespawnType == EAthenaRespawnType::InfiniteRespawnExceptStorm)
        {
            if (!GameStateAthena->SafeZoneIndicator)
                return true;

            FDeathInfo DeathInfo = PlayerStateAthena->DeathInfo;

            if (!DeathInfo.bInitialized)
                return true;

            AFortSafeZoneIndicator* SafeZoneIndicator = GameStateAthena->SafeZoneIndicator;

            if (IsOutOfSafeZone(SafeZoneIndicator, DeathInfo.DeathLocation))
                return true;
        }

        return false;
    }

	void InitGameState()
	{
		AFortGameStateAthena* FortGameStateAthenaDefault = AFortGameStateAthena::GetDefaultObj();
        UClass* FortGameStateAthenaClass = AFortGameStateAthena::StaticClass();

		/* ------------------------------------ AFortGameStateAthena ------------------------------------- */
        /* ----------------------------------------------------------------------------------------------- */

		FN_LOG(LogInit, Log, L"InitGameState Success!");
	}
}