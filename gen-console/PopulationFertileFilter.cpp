#include "pch.h"
#include "PopulationFertileFilter.h"
#include "Individual.h"

PopulationFertileFilter::PopulationFertileFilter(bool allowFertile)
    : fertile(allowFertile)
{
    ;
}

PopulationFertileFilter::~PopulationFertileFilter()
{
    ;
}

bool PopulationFertileFilter::Allow(Individual* individual)
{
    Sex sex = individual->Sex();
    if (sex.IsFertile() == fertile)
    {
        return true;
    }
    return false;
}
