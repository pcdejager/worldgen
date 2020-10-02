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

    // Race
    GeneticRaceOperator raceOperator;
    raceOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Race(), child->genome.genes);
    raceOperator.Mutate(GenePositions::Race(), child->genome.genes);

    GeneticDoubleOperator doubleOperator;

    // Sex
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Sex(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::Sex(), child->genome.genes);

    // Period
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Period(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::Period(), child->genome.genes);

    // Fertility
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Fertility(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::Fertility(), child->genome.genes);

    // Height
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Height(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::Height(), child->genome.genes);

    // Weight
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::Weight(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::Weight(), child->genome.genes);

    // MaximumLife
    doubleOperator.Crossover(father->genome.genes, mother->genome.genes, GenePositions::MaximumLife(), child->genome.genes);
    doubleOperator.Mutate(GenePositions::MaximumLife(), child->genome.genes);

    return child;
}