#pragma once

#include "IPopulationFilter.h"

class PopulationCompositeFilter : public IPopulationFilter
{
public:
    PopulationCompositeFilter();
    virtual ~PopulationCompositeFilter();

// IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

public:
    void AddFilter(const IPopulationFilterPtr& newFilter);

#ifdef UNITTEST
public:
    std::vector<IPopulationFilterPtr>& Filters() { return filters; }
#endif

private:
    std::vector<IPopulationFilterPtr> filters;

};

