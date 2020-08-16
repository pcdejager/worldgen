#pragma once

#include "Types.h"
#include "WorldTime.h"

class Population
{
public:
    Population() = default;
    ~Population() = default;

public:
    std::size_t Size() const;
    void Add(const IndividualPtr& newIndividual);

    std::size_t DeadSize() const;
    void Died(const IndividualPtr& individual);

private:
    std::set<IndividualPtr> population;
    std::set<IndividualPtr> dead;
};

