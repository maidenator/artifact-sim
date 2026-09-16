#include <emscripten/bind.h>
#include <vector>
#include <string>
#include "distributions.hpp"
#include "generator.hpp"
#include "types.hpp"

using namespace emscripten;

// --- Helper Getters/Setters for Artifact Complex Fields ---
std::string getArtifactId(const Artifact& a) { return a.id.value_or(""); }
void setArtifactId(Artifact& a, const std::string& val) { a.id = val; }

std::string getPieceName(const Artifact& a) { return a.pieceName.value_or(""); }
void setPieceName(Artifact& a, const std::string& val) { a.pieceName = val; }

std::vector<SubstatRoll> getSubStats(const Artifact& a) {
    return std::vector<SubstatRoll>(a.subStats.begin(), a.subStats.end());
}
void setSubStats(Artifact& a, const std::vector<SubstatRoll>& vec) {
    for (size_t i = 0; i < 4 && i < vec.size(); ++i) {
        a.subStats[i] = vec[i];
    }
}

EMSCRIPTEN_BINDINGS(artifact_engine) {
    
    // Register vector type so JS can receive std::vector<SubstatRoll>
    register_vector<SubstatRoll>("VectorOfSubstatRolls");

    // Enums
    enum_<ArtifactSlot>("ArtifactSlot")
        .value("FLOWER", ArtifactSlot::flower)
        .value("FEATHER", ArtifactSlot::feather)
        .value("SANDS", ArtifactSlot::sands)
        .value("GOBLET", ArtifactSlot::goblet)
        .value("CIRCLET", ArtifactSlot::circlet);

    enum_<ArtifactSubstat>("ArtifactSubstat")
        .value("CRIT_RATE", ArtifactSubstat::critRate)
        .value("CRIT_DMG", ArtifactSubstat::critDmg)
        .value("ELEMENTAL_MASTERY", ArtifactSubstat::elementalMastery)
        .value("ENERGY_RECHARGE", ArtifactSubstat::energyRecharge)
        .value("ATK_PERCENT", ArtifactSubstat::atkPercent)
        .value("ATK_FLAT", ArtifactSubstat::atkFlat)
        .value("HP_PERCENT", ArtifactSubstat::hpPercent)
        .value("HP_FLAT", ArtifactSubstat::hpFlat)
        .value("DEF_PERCENT", ArtifactSubstat::defPercent)
        .value("DEF_FLAT", ArtifactSubstat::defFlat);

    enum_<ArtifactMainStat>("ArtifactMainStat")
        .value("CRIT_DMG", ArtifactMainStat::critDmg)
        .value("CRIT_RATE", ArtifactMainStat::critRate)
        .value("ELEMENTAL_MASTERY", ArtifactMainStat::elementalMastery)
        .value("ENERGY_RECHARGE", ArtifactMainStat::energyRecharge)
        .value("ATK_PERCENT", ArtifactMainStat::atkPercent)
        .value("ATK_FLAT", ArtifactMainStat::atkFlat)
        .value("HP_PERCENT", ArtifactMainStat::hpPercent)
        .value("HP_FLAT", ArtifactMainStat::hpFlat)
        .value("DEF_PERCENT", ArtifactMainStat::defPercent)
        .value("DEF_FLAT", ArtifactMainStat::defFlat)
        .value("HEALING_BONUS", ArtifactMainStat::healingBonus)
        .value("PYRO_DMG", ArtifactMainStat::pyroDmg)
        .value("HYDRO_DMG", ArtifactMainStat::hydroDmg)
        .value("ELECTRO_DMG", ArtifactMainStat::electroDmg)
        .value("CRYO_DMG", ArtifactMainStat::cryoDmg)
        .value("ANEMO_DMG", ArtifactMainStat::anemoDmg)
        .value("GEO_DMG", ArtifactMainStat::geoDmg)
        .value("DENDRO_DMG", ArtifactMainStat::dendroDmg)
        .value("PHYSICAL_DMG", ArtifactMainStat::physicalDmg);

    // Structs
    value_object<SubstatRoll>("SubstatRoll")
        .field("type", &SubstatRoll::type)
        .field("value", &SubstatRoll::value)
        .field("rolls", &SubstatRoll::rolls);

    value_object<MainStat>("MainStat")
        .field("type", &MainStat::type)
        .field("value", &MainStat::value);

    // Artifact Class Bindings using clean free-function pointers
    class_<Artifact>("Artifact")
        .constructor<>()
        .property("rarity", &Artifact::rarity)
        .property("setName", &Artifact::setName)
        .property("slot", &Artifact::slot)
        .property("level", &Artifact::level)
        .property("mainStat", &Artifact::mainStat)
        .property("substatCount", &Artifact::substatCount)
        .property("id", &getArtifactId, &setArtifactId)
        .property("pieceName", &getPieceName, &setPieceName)
        .property("subStats", &getSubStats, &setSubStats);

    // RNG and Generator Functions
    class_<rng::Xoshiro256>("Xoshiro256")
        .constructor<uint64_t>();

    function("fastUniform", &rng::fastUniform);
    function("fastUniformRange", &rng::fastUniformRange);
    function("generateArtifact", &generator::generateArtifact);
    function("upgradeArtifactOnce", &generator::upgradeArtifactOnce);
}