#pragma once
#include <string>
#include <array>
#include <vector>
#include <optional>

enum class ArtifactSlot {
    flower,
    feather,
    sands,
    goblet,
    circlet,
};

enum class ArtifactSubstat {
    critDmg,
    critRate,
    elementalMastery,
    energyRecharge,
    atkPercent,
    atkFlat,
    hpPercent,
    hpFlat,
    defPercent,
    defFlat,
};

enum class ArtifactMainStat {
    // Artifact Substats are valid Main Stats
    critDmg,
    critRate,
    elementalMastery,
    energyRecharge,
    atkPercent,
    atkFlat,
    hpPercent,
    hpFlat,
    defPercent,
    defFlat,

    // Exlusive
    healingBonus,
    pyroDmg,
    hydroDmg,
    electroDmg,
    cryoDmg,
    anemoDmg,
    geoDmg,
    dendroDmg,
    physicalDmg,
};

struct SubstatRoll {
    ArtifactSubstat type;
    double value = 0.0;
    int rolls = 1;
};

struct MainStat {
    ArtifactMainStat type;
    double value = 0.0;
};

struct Artifact {
    std::optional<std::string> id;
    int rarity;

    std::string setName;
    std::optional<std::string> pieceName;
    ArtifactSlot slot;
    
    MainStat mainStat;
    int level = 0;

    std::array<SubstatRoll, 4> subStats;
    int substatCount = 0;
};