#include "pch.h"
#include "Population.h"
#include "Individual.h"

std::size_t Population::Size() const
{
    return population.size();
}

void Population::Add(const IndividualPtr& newIndividual)
{
    population.insert(newIndividual);
}

std::size_t Population::DeadSize() const
{
    return dead.size();
}

void Population::Died(const IndividualPtr& individual, const WorldTime& date)
{
    auto findIter = population.find(individual);
    if (findIter != population.end())
    {
        population.erase(findIter);
        individual->IndividualDied(date);
        dead.insert(individual);
    }
}