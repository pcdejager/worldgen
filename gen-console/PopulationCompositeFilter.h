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

private:
    std::vector<IPopulationFilterPtr> filters;

};

