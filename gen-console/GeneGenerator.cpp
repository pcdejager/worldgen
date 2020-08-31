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

    return result;
}