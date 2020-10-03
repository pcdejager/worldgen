#include "pch.h"
#include "Genetics.h"
#include "Race.h"
#include "Races.h"
#include "Individual.h"
#include "MathUtils.h"
#include "IGeneticOperator.h"
#include "GeneticRaceOperator.h"
#include "GeneticDoubleOperator.h"
#include "GenePositions.h"

/*static*/ IndividualPtr Genetics::CreateChild(const IndividualPtr& father, const IndividualPtr& mother)
{
    IndividualPtr child;

    GeneticRaceOperator raceOperator;
    GeneticDoubleOperator doubleOperator;

    // Race
    const auto& genePositions = GenePositions::AllGenes();
    for (const auto& position : genePositions)
    {
        if (position.Type() == GeneType::RACE)
        {
            raceOperator.Crossover(father->genome.genes, mother->genome.genes, position, child->genome.genes);
            raceOperator.Mutate(position, child->genome.genes);
        }
        else if (position.Type() == GeneType::DOUBLE)
        {
            doubleOperator.Crossover(father->genome.genes, mother->genome.genes, position, child->genome.genes);
            doubleOperator.Mutate(position, child->genome.genes);
        }
    }

    return child;
}