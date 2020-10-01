#include "pch.h"
#include "Genetics.h"
#include "Race.h"
#include "Races.h"
#include "Individual.h"
#include "MathUtils.h"
#include "IGeneticOperator.h"
#include "GeneticRaceOperator.h"
#include "GeneticCrossoverOperator.h"
#include "GenePositions.h"

/*static*/ IndividualPtr Genetics::CreateChild(const IndividualPtr& father, const IndividualPtr& mother)
{
    IndividualPtr child;

    // Race
    GeneticRaceOperator raceOperator;
    raceOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Race(), child->genome.genes);

    GeneticCrossoverOperator crossOperator;

    // Sex
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Sex(), child->genome.genes);

    // Period
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Period(), child->genome.genes);

    // Fertility
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Fertility(), child->genome.genes);

    // Height
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Height(), child->genome.genes);

    // Weight
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::Weight(), child->genome.genes);

    // MaximumLife
    crossOperator.Apply(father->genome.genes, mother->genome.genes, GenePositions::MaximumLife(), child->genome.genes);

    return child;
}