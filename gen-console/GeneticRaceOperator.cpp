#include "pch.h"
#include "GeneticRaceOperator.h"
#include "Race.h"
#include "Races.h"
#include "MathUtils.h"

void GeneticRaceOperator::Apply(const Genes& father, const Genes& mother, const GenePosition& position, Genes& result)
{
    __int64 fatherGene = father.ReadInt(position);
    __int64 motherGene = mother.ReadInt(position);

    RacePtr fatherRace = Races::GetRaces()->FindRaceByGene(fatherGene);
    RacePtr motherRace = Races::GetRaces()->FindRaceByGene(motherGene);

    double roll = MathUtils::RandomDouble();

    RacePtr childRace = Races::GetRaces()->ChildRace(fatherRace, motherRace, roll);

    // Pick a random gene from possible genes
    std::size_t possibleGenes = childRace->GetTraits().gene.Count();
    __int64 geneValue = MathUtils::RandomInt(0, possibleGenes);

    result.SetGenes(position, geneValue);

}