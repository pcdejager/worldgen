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
    if (geneValue < 0.5)
    {
        return Sex(true, false);
    }
    return Sex(false, true);
}

#ifdef UNITTEST
void Genome::ReplaceGenes(const Genes& newGenes)
{
    genes = newGenes;
}
#endif
