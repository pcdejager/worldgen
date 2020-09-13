#pragma once

#include "Types.h"
#include "IPopulationFilter.h"

class PopulationFertileFilter : public IPopulationFilter
{
public:
    PopulationFertileFilter(bool allowFertile);
    virtual ~PopulationFertileFilter();

// IPopulationFilter
public:
    virtual bool Allow(const IndividualPtr& individual);

private:
    bool fertile;
};

