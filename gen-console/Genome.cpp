#include "pch.h"
#include "Genome.h"
#include "GenePositions.h"
#include "Races.h"

/*static*/ std::map<__int64, std::wstring> Genome::genomeRaces;

Genome::Genome()
    : genes()
{
    InitializeRaces();
}

RacePtr Genome::GetRace() const
{
    __int64 geneValue = genes.ReadInt(RaceGenesStart, RaceGenesSize) % genomeRaces.size();
    return Races::GetRaces()->FindRace(genomeRaces[geneValue]);
}

Sex Genome::GetSex() const
{
    double geneValue = genes.ReadDouble(SexGenesStart, SexGenesSize);
    bool fertile = (geneValue < 0.48) || (geneValue >= 0.52);
    if (geneValue < 0.5)
    {
        return Sex(true, false, fertile);
    }
    return Sex(false, true, fertile);
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

