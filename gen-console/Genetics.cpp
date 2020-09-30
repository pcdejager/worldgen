#include "pch.h"
#include "Genetics.h"
#include "Race.h"
#include "Races.h"
#include "Individual.h"
#include "MathUtils.h"
#include "IGeneticOperator.h"
#include "GeneticRaceOperator.h"
#include "GenePositions.h"

/*static*/ IndividualPtr Genetics::CreateChild(const IndividualPtr& father, const IndividualPtr& mother)
{
    IndividualPtr child;

    // Race
    GeneticRaceOperator raceOperator;
    raceOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Race(), child->genome.genes);

    // TODO : Apply GeneticOperators to all GenePositions

    return child;
}