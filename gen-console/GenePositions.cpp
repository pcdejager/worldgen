#include "pch.h"
#include "GenePositions.h"

/*static*/ std::vector<GenePosition> GenePositions::genes =
{
    Race(),
    Sex(),
    Period(),
    Fertility(),
    Height(),
    Weight(),
    MaximumLife()
};

/*static*/ const std::vector<GenePosition>& GenePositions::AllGenes()
{
    return genes;
}