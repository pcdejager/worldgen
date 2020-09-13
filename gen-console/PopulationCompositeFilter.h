#pragma once

#include "Types.h"
#include "IPopulationFilter.h"

class PopulationCompositeFilter : public IPopulationFilter
{
public:
    PopulationCompositeFilter();
    virtual ~PopulationCompositeFilter();

// IPopulationFilter
public:
    virtual bool Allow(const IndividualPtr& individual);

public:
    void AddFilter(const IPopulationFilterPtr& newFilter);

private:
    std::vector<IPopulationFilterPtr> filters;

};

