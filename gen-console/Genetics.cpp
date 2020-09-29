#include "pch.h"
#include "Genetics.h"
#include "Race.h"
#include "Races.h"
#include "Individual.h"
#include "MathUtils.h"

/*static*/ IndividualPtr Genetics::CreateChild(const IndividualPtr& father, const IndividualPtr& mother)
{
    IndividualPtr child;

    // TODO : Calculate new race
    RacePtr fatherRace = father->GetRace();
    RacePtr motherRace = mother->GetRace();

    double roll = MathUtils::RandomDouble();

    RacePtr childRace = Races::GetRaces()->ChildRace(fatherRace, motherRace, roll);

    // TODO : Apply GeneticOperators to all GenePositions

    return child;
}