export type ArtifactSlot = 
| 'flower'
| 'feather'
| 'sands'
| 'goblet'
| 'circlet'

export type ArtifactSubStat = 
| 'critDmg'
| 'critRate'
| 'elementalMastery'
| 'energyRecharge'
| 'atkPercent'
| 'atkFlat'
| 'hpPercent'
| 'hpFlat'
| 'defPercent'
| 'defFlat'

export type ArtifactMainStat =
| ArtifactSubStat
| 'healingBonus'
| 'pyroDmg'
| 'hydroDmg'
| 'electroDmg'
| 'cryoDmg'
| 'anemoDmg'
| 'geoDmg'
| 'dendroDmg'
| 'physicalDmg'

export type SubstatRoll = {
    type: ArtifactSubStat;
    value: number;
    rolls?: number;
};

export type MainStat =  {
    type: ArtifactMainStat;
    value?: number;
};

export type Artifact = {
    id?: string;
    setName: string;
    pieceName?: string;
    slot: ArtifactSlot;
    level: number;
    rarity: number;
    mainStat: MainStat;
    subStats: SubstatRoll[];
};