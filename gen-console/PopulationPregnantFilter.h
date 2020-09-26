#pragma once

#include "IPopulationFilter.h"

class PopulationPregnantFilter : public IPopulationFilter
{
public:
    PopulationPregnantFilter(bool allowPregnant);
    virtual ~PopulationPregnantFilter();

    // IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

#ifdef UNITTEST
public:
    bool Pregnant() const { return pregnant; }
#endif

private:
    bool pregnant;
};

