#include "pch.h"
#include "Genome.h"
#include "GenePositions.h"
#include "Races.h"
#include "Race.h"
#include "AgeSexRangeValue.h"

Genome::Genome()
    : genes()
{
    ;
}

Genome::Genome(const Genes& inputGenes)
    : genes(inputGenes)
{
    ;
}

RacePtr Genome::GetRace() const
{
    __int64 geneValue = genes.ReadInt(GenePositions::Race());
    return Races::GetRaces()->FindRace(geneValue);
}

Sex Genome::GetSex() const
{
    double geneValue = genes.ReadDouble(GenePositions::Sex());
    bool fertile = (geneValue < 0.48) || (geneValue >= 0.52);
    if (geneValue < 0.5)
    {
        return Sex(true, false, fertile);
    }
    return Sex(false, true, fertile);
}

__int64 Genome::GetHeight(const TimeSpan& age) const
{
    RacePtr race = GetRace();
    Sex sex = GetSex();
    double geneValue = (genes.ReadDouble(GenePositions::Height()) * 2.0) - 1.0;
    return race->Traits().height->Value(geneValue, age, sex);
}

__int64 Genome::GetWeight(const TimeSpan& age) const
{
    RacePtr race = GetRace();
    Sex sex = GetSex();
    double geneValue = (genes.ReadDouble(GenePositions::Weight()) * 2.0) - 1.0;
    return race->Traits().weight->Value(geneValue, age, sex);
}

#ifdef UNITTEST
void Genome::ReplaceGenes(const Genes& newGenes)
{
    genes = newGenes;
}
#endif

