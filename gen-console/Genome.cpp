#include "pch.h"
#include "Genome.h"
#include "GenePositions.h"
#include "Races.h"
#include "Race.h"
#include "RacialTraits.h"
#include "AgeSexRangeValue.h"
#include "AgeTraits.h"

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
    return Races::GetRaces()->FindRaceByGene(geneValue);
}

Sex Genome::GetSex() const
{
    double geneValue = genes.ReadDouble(GenePositions::Sex());
    double fertility = genes.ReadDouble(GenePositions::Fertility());
    if (geneValue < 0.5)
    {
        return Sex(true, false, GetPeriodCycle(), fertility);
    }
    return Sex(false, true, GetPeriodCycle(), fertility);
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

TimeSpan Genome::MaximumAge() const
{
    RacePtr race = GetRace();
    double geneValue = genes.ReadDouble(GenePositions::MaximumLife());
    __int64 max = race->Traits().ageRanges->NextAgeStart(AgeCategory::Elder);
    __int64 min = race->Traits().ageRanges->AgeStart(AgeCategory::Elder);
    __int64 result = min + static_cast<__int64>((geneValue * static_cast<double>(max - min)));
    if (result < min)
    {
        result = min;
    }
    else if (result > max)
    {
        result = max;
    }
    return TimeSpan(result);
}

TimeSpan Genome::GetPeriodCycle() const
{
    RacePtr race = GetRace();
    double period = (genes.ReadDouble(GenePositions::Period()) * 2.0) - 1.0;
    __int64 ticks = race->Traits().period.Value(period);
    return TimeSpan(ticks);
}

#ifdef UNITTEST
void Genome::ReplaceGenes(const Genes& newGenes)
{
    genes = newGenes;
}
#endif

