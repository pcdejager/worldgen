#pragma once

#include "IPopulationFilter.h"

class PopulationMarryFilter : public IPopulationFilter
{
public:
    PopulationMarryFilter(bool allowMarried);
    virtual ~PopulationMarryFilter();

    // IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

#ifdef UNITTEST
public:
    bool Married() const { return married; }
#endif

private:
    bool married;
};

