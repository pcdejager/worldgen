#include "pch.h"
#include "GeneticDoubleOperator.h"
#include "MathUtils.h"

GeneticDoubleOperator::GeneticDoubleOperator(double mutate)
    : mutation(mutate)
{
    ;
}

void GeneticDoubleOperator::Crossover(const Genes& father, const Genes& mother, const GenePosition& position, Genes& result)
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

void GeneticDoubleOperator::Mutate(const GenePosition& position, Genes& child)
{
    for (std::size_t index = position.Start(); index < position.End(); ++index)
    {
        double roll = MathUtils::RandomDouble();
        if (roll < mutation)
        {
            child.SetBool(index, !child.ReadBool(index));
        }
    }
}