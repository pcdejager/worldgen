#include "pch.h"
#include "GeneGenerator.h"
#include "GenePositions.h"

/*static*/ Genes GeneGenerator::Random()
{
    Genes result;

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    // Race
    {
        std::size_t raceMax = (1 << GenePositions::Race().Size()) - 1;
        std::uniform_int_distribution<> raceDistribution(0, raceMax);
        __int64 race = raceDistribution(generator);
        result.SetGenes(GenePositions::Race(), race);
    }

    std::uniform_real<> realDistribution(0.0, 1.0);
    // Sex
    {
        double sex = realDistribution(generator);
        result.SetGenes(GenePositions::Sex(), sex);
    }

    // Height
    {
        double height = realDistribution(generator);
        result.SetGenes(GenePositions::Height(), height);
    }

    // Weight
    {
        double weight = realDistribution(generator);
        result.SetGenes(GenePositions::Weight(), weight);
    }

    return result;
}