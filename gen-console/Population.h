#pragma once

#include "Types.h"
#include "WorldTime.h"

class IPopulationVisitor;

class Population
{
public:
    Population() = default;
    ~Population() = default;

public:
    std::size_t Size() const;
    void Add(const IndividualPtr& newIndividual);

    std::size_t DeadSize() const;
    void Died(const IndividualPtr& individual, const WorldTime& time);

public:
    void CheckDeaths();

public:
    void Visit(IPopulationVisitor* pVisitor);
    void Visit(IPopulationVisitor* pVisitor, IPopulationFilter* pFilter);

private:
    std::set<IndividualPtr> population;
    std::set<IndividualPtr> dead;
};

