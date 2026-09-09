#pragma once
#include "types.hpp"
#include "random_utils.hpp"

namespace generator {

/**
 * Calculates the artifact's Crit Value (CV) using the standard formula:
 * Crit DMG + (Crit Rate * 2)
 * 
 * @param art The artifact object containing the substats to evaluate
 * @return float The total calculated crit value
 */

inline float calculateCritValue(const Artifact &art) {
    float critValue = 0.0f;
    for(int i  = 0; i < art.substatCount; ++i) {
        const auto &sub = art.subStats[i];

        if(sub.type == ArtifactSubstat::critDmg)
            critValue += sub.value;
        if(sub.type == ArtifactSubstat::critRate)
            critValue += sub.value * 2.0f;
    }
    return critValue;
}

// ==========================================
// TODOs for Tomorrow: Artifact Simulation Pipeline
// ==========================================

/**
 * @brief TODO: Selects a random main stat for a given artifact piece based on official drop weights.
 * 
 * @param pieceType The piece category (Flower, Plume, Sands, Goblet, Circlet).
 * @param rng Reference to the Xoshiro256 random engine.
 * @return ArtifactSubstatType The selected main stat.
 */
// TODO: implement generateMainStat(...)

/**
 * @brief TODO: Rolls the initial substats for a new artifact drop (handles 3 vs 4 starting lines and prevents duplicate stats).
 * 
 * @param mainStat The main stat type to ensure it doesn't duplicate into the substat pool.
 * @param rng Reference to the Xoshiro256 random engine.
 * @return Artifact The generated artifact with its initial rolls.
 */
// TODO: implement generateInitialSubstats(...)

/**
 * @brief TODO: Simulates upgrading an artifact level, either adding a new substat or boosting an existing one.
 * 
 * @param art Reference to the artifact being upgraded.
 * @param rng Reference to the Xoshiro256 random engine.
 */
// TODO: implement upgradeArtifact(...)

} // namespace generator
