#include "pch.h"
#include "PopulationSexFilter.h"
#include "Individual.h"

PopulationSexFilter::PopulationSexFilter(bool allowMales, bool allowFemales)
    : males(allowMales)
    , females(allowFemales)
{
    ;
}

PopulationSexFilter::~PopulationSexFilter()
{
    ;
}

bool PopulationSexFilter::Allow(Individual* individual)
{
    Sex sex = individual->GetSex();
    if (sex.IsFemale() && (!females))
    {
        return false;
    }
    if (sex.IsMale() && (!males))
    {
        return false;
    }
    return true;
}
