#pragma once

class Individual;

class IPopulationFilter
{
protected:
    IPopulationFilter() = default;

public:
    virtual ~IPopulationFilter() = default;

public:
    virtual bool Allow(Individual* individual) = 0;
};

typedef std::shared_ptr<IPopulationFilter> IPopulationFilterPtr;
