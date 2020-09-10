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
