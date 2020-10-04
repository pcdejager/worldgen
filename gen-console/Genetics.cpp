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

/*static*/ std::map<GeneCategory, IGeneticOperatorPtr> Genetics::operators;

/*static*/ IndividualPtr Genetics::CreateChild(const IndividualPtr& father, const IndividualPtr& mother)
{
    Initialize();

    IndividualPtr child;

    GeneticRaceOperator raceOperator;
    GeneticDoubleOperator doubleOperator;

    // Race
    const auto& genePositions = GenePositions::AllGenes();
    for (const auto& position : genePositions)
    {
        operators[position.second.Type()]->Crossover(father->genome.genes, mother->genome.genes, position.second, child->genome.genes);
        operators[position.second.Type()]->Mutate(position.second, child->genome.genes);
    }

    return child;
}

/*static*/ void Genetics::Initialize()
{
    if (operators.empty())
    {
        IGeneticOperatorPtr raceOpertor = IGeneticOperatorPtr(new GeneticRaceOperator());
        operators.insert(std::make_pair(GeneCategory::RACE, raceOpertor));
        IGeneticOperatorPtr doubleOperator = IGeneticOperatorPtr(new GeneticDoubleOperator());
        operators.insert(std::make_pair(GeneCategory::DOUBLE, doubleOperator));
    }
}


