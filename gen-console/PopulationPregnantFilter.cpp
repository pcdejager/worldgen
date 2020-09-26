#include "pch.h"
#include "PopulationPregnantFilter.h"
#include "Individual.h"

PopulationPregnantFilter::PopulationPregnantFilter(bool allowPregnant)
    : pregnant(allowPregnant)
{
    ;
}

PopulationPregnantFilter::~PopulationPregnantFilter()
{
    ;
}

bool PopulationPregnantFilter::Allow(Individual* individual)
{
    if (individual->IsPregnant() && pregnant)
    {
        return true;
    }
    else if (!individual->IsPregnant() && !pregnant)
    {
        return true;
    }
    return false;
}
