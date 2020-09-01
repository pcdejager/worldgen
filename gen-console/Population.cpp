#include "pch.h"
#include "Population.h"
#include "Individual.h"
#include "Sex.h"

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

void Population::Died(const IndividualPtr& individual)
{
    auto findIter = population.find(individual);
    if (findIter != population.end())
    {
        population.erase(findIter);
        individual->IndividualDied();
        dead.insert(individual);
    }
}

std::size_t Population::NumberOfMales() const
{
    std::size_t result = 0;
    for (auto individual : population)
    {
        if (individual->Sex().IsMale())
        {
            ++result;
        }
    }
    return result;
}

std::size_t Population::NumberOfFemales() const
{
    std::size_t result = 0;
    for (auto individual : population)
    {
        if (individual->Sex().IsFemale())
        {
            ++result;
        }
    }
    return result;
}
