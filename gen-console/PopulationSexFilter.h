#pragma once

#include "IPopulationFilter.h"

class PopulationSexFilter : public IPopulationFilter
{
public:
    PopulationSexFilter(bool allowMales, bool allowFemales);
    virtual ~PopulationSexFilter();

// IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

#ifdef UNITTEST
public:
    bool Males() const { return males; }
    bool Females() const { return females; }
#endif

private:
    bool males;
    bool females;
};

