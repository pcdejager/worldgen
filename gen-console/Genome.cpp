#include "pch.h"
#include "Genome.h"
#include "GenePositions.h"
#include "Races.h"
#include "Race.h"
#include "AgeSexRangeValue.h"

/*static*/ std::map<__int64, std::wstring> Genome::genomeRaces;

Genome::Genome()
    : genes()
{
    InitializeRaces();
}

RacePtr Genome::GetRace() const
{
    __int64 geneValue = genes.ReadInt(GenePositions::Race()) % genomeRaces.size();
    return Races::GetRaces()->FindRace(genomeRaces[geneValue]);
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

void Genome::InitializeRaces() const
{
    if (genomeRaces.size() == 0)
    {
        auto names = Races::GetRaces()->AllRaces();
        for (std::size_t count = 0; count < names.size(); ++count)
        {
            genomeRaces.insert(std::make_pair(count, names[count]));
        }
    }
}

