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
    Physiology physiology = individual->GetPhysiology();
    if (physiology.IsFertile() == fertile)
    {
        return true;
    }
    return false;
}
