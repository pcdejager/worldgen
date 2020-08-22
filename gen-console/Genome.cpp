#include "pch.h"
#include "Genome.h"
#include "GenePositions.h"

Genome::Genome()
    : genes()
{
    ;
}

Sex Genome::GetSex() const
{
    double geneValue = genes.ReadDouble(SexGenesStart, SexGenesEnd);
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
