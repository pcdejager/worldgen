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
    __int64 geneValue = genes.ReadInt(GenePositions::GetPosition(GeneType::Race));
    return Races::GetRaces()->FindRaceByGene(geneValue);
}

Sex Genome::GetSex() const
{
    double geneValue = genes.ReadDouble(GenePositions::GetPosition(GeneType::Sex));
    if (geneValue < 0.5)
    {
        return Sex(true, false);
    }
    return Sex(false, true);
}

double Genome::GetFertility() const
{
    return genes.ReadDouble(GenePositions::GetPosition(GeneType::Fertility));
}

TimeSpan Genome::GetPeriodCycle() const
{
    if (GetSex().IsMale())
    {
        return TimeSpan();
    }
    RacePtr race = GetRace();
    double period = (genes.ReadDouble(GenePositions::GetPosition(GeneType::Period)) * 2.0) - 1.0;
    __int64 ticks = race->GetTraits().period.Value(period);
    return TimeSpan(ticks);
}

__int64 Genome::GetHeight(const TimeSpan& age) const
{
    RacePtr race = GetRace();
    Sex sex = GetSex();
    double geneValue = (genes.ReadDouble(GenePositions::GetPosition(GeneType::Height)) * 2.0) - 1.0;
    return race->GetTraits().height->Value(geneValue, age, sex);
}

__int64 Genome::GetWeight(const TimeSpan& age) const
{
    RacePtr race = GetRace();
    Sex sex = GetSex();
    double geneValue = (genes.ReadDouble(GenePositions::GetPosition(GeneType::Weight)) * 2.0) - 1.0;
    return race->GetTraits().weight->Value(geneValue, age, sex);
}

TimeSpan Genome::MaximumAge() const
{
    RacePtr race = GetRace();
    double geneValue = genes.ReadDouble(GenePositions::GetPosition(GeneType::MaximumLife));
    __int64 max = race->GetTraits().ageRanges->NextAgeStart(AgeCategory::Elder);
    __int64 min = race->GetTraits().ageRanges->AgeStart(AgeCategory::Elder);
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


#ifdef UNITTEST
void Genome::ReplaceGenes(const Genes& newGenes)
{
    genes = newGenes;
}
#endif

