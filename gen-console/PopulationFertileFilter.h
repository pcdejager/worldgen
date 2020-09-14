#pragma once

#include "IPopulationFilter.h"

class PopulationFertileFilter : public IPopulationFilter
{
public:
    PopulationFertileFilter(bool allowFertile);
    virtual ~PopulationFertileFilter();

// IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

#ifdef UNITTEST
public:
    bool Fertile() const { return fertile; }
#endif

private:
    bool fertile;
};

