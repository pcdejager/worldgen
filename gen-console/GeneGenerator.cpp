#include "pch.h"
#include "GeneGenerator.h"
#include "GenePositions.h"
#include "MathUtils.h"

/*static*/ Genes GeneGenerator::Random()
{
    Genes result;

    // Race
    {
        std::size_t raceMax = (1 << GenePositions::GetPosition(GeneType::Race).Size()) - 1;
        __int64 race = MathUtils::RandomInt(0, raceMax);
        result.SetGenes(GenePositions::GetPosition(GeneType::Race), race);
    }

    // Sex
    {
        double sex = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::Sex), sex);
    }

    // Period
    {
        double period = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::Period), period);
    }

    // Fertility
    {
        double fertility = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::Fertility), fertility);
    }

    // Height
    {
        double height = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::Height), height);
    }

    // Weight
    {
        double weight = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::Weight), weight);
    }

    // Maximum life
    {
        double max = MathUtils::RandomDouble();
        result.SetGenes(GenePositions::GetPosition(GeneType::MaximumLife), max);
    }

    return result;
}