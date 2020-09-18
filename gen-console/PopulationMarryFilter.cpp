#include "pch.h"
#include "PopulationMarryFilter.h"
#include "Individual.h"

PopulationMarryFilter::PopulationMarryFilter(bool allowMarried)
    : married(allowMarried)
{
    ;
}

PopulationMarryFilter::~PopulationMarryFilter()
{
    ;
}

bool PopulationMarryFilter::Allow(Individual* individual)
{
    if (individual->IsMarried() && married)
    {
        return true;
    }
    else if (!individual->IsMarried() && !married)
    {
        return true;
    }
    return false;
}
