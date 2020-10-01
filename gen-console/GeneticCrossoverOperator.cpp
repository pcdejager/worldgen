#include "pch.h"
#include "GeneticCrossoverOperator.h"

void GeneticCrossoverOperator::Apply(const Genes& father, const Genes& mother, const GenePosition& position, Genes& result)
{
    __int64 value1 = father.ReadInt(position);
    __int64 value2 = mother.ReadInt(position);

    std::size_t middle = position.Size() / 2;
    __int64 mask = 1LL;
    for (std::size_t count = 1; count < middle; ++count)
    {
        mask <<= 1LL;
        mask += 1LL;
    }

    __int64 resultValue = (value1 & mask) + (value2 & (!mask));
    result.SetGenes(position, resultValue);
}