#pragma once

#include "Types.h"
#include "IPopulationFilter.h"

class PopulationSexFilter : public IPopulationFilter
{
public:
    PopulationSexFilter(bool allowMales, bool allowFemales);
    virtual ~PopulationSexFilter();

// IPopulationFilter
public:
    virtual bool Allow(const IndividualPtr& individual);

private:
    bool males;
    bool females;
};

