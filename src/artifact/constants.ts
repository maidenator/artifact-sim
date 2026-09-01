import type { ArtifactSlot, ArtifactSubStat, ArtifactMainStat } from "./types";


// Main Stat Distribution
export const MAIN_STAT_DISTRIBUTION = {
    flower: {
        hpFlat: 100,    // All flowers can only have Flat HP as its main stat
    },
    feather: {
        atkFlat: 100,   // All feathers can only have Flat HP as its main stat
    },
    sands: {
        hpPercent: 26.68,
        atkPercent: 26.66,
        defPercent: 26.66,
        energyRecharge: 10.0,
        elementalMastery: 10.0,
    },
    goblet: {
        hpPercent: 19.25,
        atkPercent: 19.25,
        defPercent: 19.0,
        pyroDmg: 5.0,
        hydroDmg: 5.0,
        electroDmg: 5.0,
        cryoDmg: 5.0,
        anemoDmg: 5.0,
        geoDmg: 5.0,
        dendroDmg: 5.0,
        physicalDmg: 5.0,
        elementalMastery: 2.5,
    },
    circlet: {
        hpPercent: 22.0,
        atkPercent: 22.0,
        defPercent: 22.0,
        critRate: 10.0,
        critDmg: 10.0,
        healingBonus: 10.0,
        elementalMastery: 4.0,
    },
} as const satisfies Record<ArtifactSlot, Partial<Record<ArtifactMainStat, number>>>;

// Maximum Main Stat Values for level 20 five star artifacts
export const MAX_MAIN_STAT_VALUES: Partial<Record<ArtifactMainStat, number>> = {
    hpFlat: 4780,
    atkFlat: 311,
    hpPercent: 46.6,
    atkPercent: 46.6,
    defPercent: 58.3,
    energyRecharge: 51.8,
    elementalMastery: 187,
    critRate: 31.1,
    critDmg: 62.2,
    healingBonus: 35.9,
    pyroDmg: 46.6,
    hydroDmg: 46.6,
    electroDmg: 46.6,
    cryoDmg: 46.6,
    anemoDmg: 46.6,
    geoDmg: 46.6,
    dendroDmg: 46.6,
    physicalDmg: 58.3,
};

// Sub Stat Spawn Rates
export const SUBSTAT_SPAWN_WEIGHTS = {
    hpFlat: 6,
    atkFlat: 6,
    defFlat: 6,
    hpPercent: 4,
    atkPercent: 4,
    defPercent: 4,
    energyRecharge: 3,
    elementalMastery: 3,
    critRate: 3,
    critDmg: 3,
} as const satisfies Record<ArtifactSubStat, number>;

// Substat Values
export const SUBSTAT_TIERS = {
    hpFlat: [209.13, 239.00, 268.88, 298.75],
    atkFlat: [13.62, 15.56, 17.51, 19.45],
    defFlat: [16.20, 18.52, 20.83, 23.15],
    hpPercent: [4.08, 4.66, 5.25, 5.83],
    atkPercent: [4.08, 4.66, 5.25, 5.83],
    defPercent: [5.10, 5.83, 6.56, 7.29],
    elementalMastery: [16.32, 18.65, 20.98, 23.31],
    energyRecharge: [4.53, 5.18, 5.83, 6.48],
    critRate: [2.72, 3.11, 3.50, 3.89],
    critDmg: [5.44, 6.22, 6.99, 7.77],
} as const satisfies Record<ArtifactSubStat, readonly [number, number, number, number]>;

// Domain Constants
export const DOMAIN_CONSTANTS = {
    RESIN_PER_RUN: 20,              // One run costs 20 resin
    BASE_5_STAR_COUNT: 1,           // Guaranteed to get one 5* drop every 20 resin spent
    DOUBLE_5_STAR_CHANCE: 0.065,    // 6.5% chance for a 2nd 5* drop every 20 resin spent
    SET_SPLIT_RATE: 0.5,            // 50% target set
    SLOT_SPLIT_RATE: 0.2,           // 20% per slot
    FOUR_LINER_CHANCE: 0.20,        // 20% drops with 4 lines, 80% with 3
} as const;