#pragma once
#include "distributions.hpp"

namespace format_utils {

constexpr std::string substatToString(ArtifactSubstat stat) {
    switch (stat) {
        case ArtifactSubstat::critRate:         return "Crit Rate";
        case ArtifactSubstat::critDmg:          return "Crit DMG";
        case ArtifactSubstat::atkPercent:       return "ATK%";
        case ArtifactSubstat::atkFlat:          return "ATK";
        case ArtifactSubstat::hpPercent:        return "HP%";
        case ArtifactSubstat::hpFlat:           return "HP";
        case ArtifactSubstat::defPercent:       return "DEF%";
        case ArtifactSubstat::defFlat:          return "DEF";
        case ArtifactSubstat::elementalMastery: return "Elemental Mastery";
        case ArtifactSubstat::energyRecharge:   return "Energy Recharge";
        default:                                return "Unknown";
    }
}

}