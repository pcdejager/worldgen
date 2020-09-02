#include "pch.h"
#include "Population.h"
#include "Individual.h"
#include "Sex.h"
#include "IPopulationVisitor.h"

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

void Population::Visit(IPopulationVisitor* pVisitor)
{
    for (auto individual : population)
    {
        pVisitor->VisitIndividual(individual);
    }
}
