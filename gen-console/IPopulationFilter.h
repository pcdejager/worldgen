#pragma once

class IPopulationFilter
{
protected:
    IPopulationFilter() = default;

public:
    virtual ~IPopulationFilter() = default;

public:
    virtual bool Allow(const IndividualPtr & individual) = 0;
};

typedef std::shared_ptr<IPopulationFilter> IPopulationFilterPtr;
