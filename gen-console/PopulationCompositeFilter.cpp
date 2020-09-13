#include "pch.h"
#include "PopulationCompositeFilter.h"

PopulationCompositeFilter::PopulationCompositeFilter()
    : filters()
{
    ;
}

PopulationCompositeFilter::~PopulationCompositeFilter()
{
    ;
}

bool PopulationCompositeFilter::Allow(const IndividualPtr& individual)
{
    for (auto filter : filters)
    {
        if (!filter->Allow(individual))
        {
            return false;
        }
    }
    return true;
}

void PopulationCompositeFilter::AddFilter(const IPopulationFilterPtr& newFilter)
{
    filters.push_back(newFilter);
}