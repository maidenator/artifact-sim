#pragma once
#include "distributions.hpp"

// Prints enum names without needing to wrap them into a function

// Artifact Slot
inline std::ostream& operator<<(std::ostream& out, ArtifactSlot value) {
    return out << [value]() -> const char* {
        #define PROCESS_VAL(enumVal, str) case ArtifactSlot::enumVal: return str;
        switch(value) {
            PROCESS_VAL(flower,   "Flower of Life")
            PROCESS_VAL(feather,  "Plume of Death")
            PROCESS_VAL(sands,    "Sands of Eon")
            PROCESS_VAL(goblet,   "Goblet of Eonothem")
            PROCESS_VAL(circlet,  "Circlet of Logos")
            default:              return "Unknown";
        }
        #undef PROCESS_VAL
    }();
}

// Artifact Substat
inline std::ostream& operator<<(std::ostream& out, ArtifactSubstat value) {
    return out << [value]() -> const char* {
        #define PROCESS_VAL(enumVal, str) case ArtifactSubstat::enumVal: return str;
        switch(value) {
            PROCESS_VAL(critDmg,          "Crit DMG")
            PROCESS_VAL(critRate,         "Crit Rate")
            PROCESS_VAL(elementalMastery, "Elemental Mastery")
            PROCESS_VAL(energyRecharge,   "Energy Recharge")
            PROCESS_VAL(atkPercent,       "ATK%")
            PROCESS_VAL(atkFlat,          "ATK")
            PROCESS_VAL(hpPercent,        "HP%")
            PROCESS_VAL(hpFlat,           "HP")
            PROCESS_VAL(defPercent,       "DEF%")
            PROCESS_VAL(defFlat,          "DEF")
            default:                      return "Unknown";
        }
        #undef PROCESS_VAL
    }();
}

// Artifact Main Stat
inline std::ostream& operator<<(std::ostream& out, ArtifactMainStat value) {
    return out << [value]() -> const char* {
        #define PROCESS_VAL(enumVal, str) case ArtifactMainStat::enumVal: return str;
        switch(value) {
            // Substats valid as Main Stats
            PROCESS_VAL(critDmg,          "Crit DMG")
            PROCESS_VAL(critRate,         "Crit Rate")
            PROCESS_VAL(elementalMastery, "Elemental Mastery")
            PROCESS_VAL(energyRecharge,   "Energy Recharge")
            PROCESS_VAL(atkPercent,       "ATK%")
            PROCESS_VAL(atkFlat,          "ATK")
            PROCESS_VAL(hpPercent,        "HP%")
            PROCESS_VAL(hpFlat,           "HP")
            PROCESS_VAL(defPercent,       "DEF%")
            PROCESS_VAL(defFlat,          "DEF")

            // Exclusive Main Stats
            PROCESS_VAL(healingBonus,     "Healing Bonus")
            PROCESS_VAL(pyroDmg,          "Pyro DMG Bonus")
            PROCESS_VAL(hydroDmg,         "Hydro DMG Bonus")
            PROCESS_VAL(electroDmg,       "Electro DMG Bonus")
            PROCESS_VAL(cryoDmg,          "Cryo DMG Bonus")
            PROCESS_VAL(anemoDmg,         "Anemo DMG Bonus")
            PROCESS_VAL(geoDmg,           "Geo DMG Bonus")
            PROCESS_VAL(dendroDmg,        "Dendro DMG Bonus")
            PROCESS_VAL(physicalDmg,      "Physical DMG Bonus")
            default:                      return "Unknown";
        }
        #undef PROCESS_VAL
    }();
}