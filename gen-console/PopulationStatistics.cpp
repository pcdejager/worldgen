#include "pch.h"
#include "PopulationStatistics.h"
#include "Individual.h"

PopulationStatistics::PopulationStatistics()
    : total(0ULL)
    , males(0ULL)
    , females(0ULL)
{
    ;
}

void PopulationStatistics::Reset()
{
    total = 0ULL;
    males = 0ULL;
    females = 0ULL;
}

void PopulationStatistics::VisitIndividual(const IndividualPtr& individual)
{
    ++total;
    if (individual->Sex().IsFemale())
    {
        ++females;
    }
    if (individual->Sex().IsMale())
    {
        ++males;
    }

}