#include "pch.h"
#include "GeneGenerator.h"
#include "GenePositions.h"
#include "MathUtils.h"

/*static*/ Genes GeneGenerator::Random()
{
    Genes result;

    // Race
    {
        std::size_t raceMax = (1 << GenePositions::Race().Size()) - 1;
        __int64 race = MathUtils::RandomInt(0, raceMax);
        result.SetGenes(GenePositions::Race(), race);
    }

    // Sex
    {
        double sex = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::Sex(), sex);
    }

    // Period
    {
        double period = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::Period(), period);
    }

    // Fertility
    {
        double fertility = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::Fertility(), fertility);
    }

    // Height
    {
        double height = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::Height(), height);
    }

    // Weight
    {
        double weight = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::Weight(), weight);
    }

    // Maximum life
    {
        double max = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::MaximumLife(), max);
    }

    return result;
}