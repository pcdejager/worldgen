#include "pch.h"
#include "Population.h"
#include "Individual.h"
#include "Sex.h"
#include "IPopulationVisitor.h"
#include "IPopulationFilter.h"
#include "WorldProperties.h"
#include "Logger.h"

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

void Population::Died(const IndividualPtr& individual, const WorldTime& time)
{
    auto findIter = population.find(individual);
    if (findIter != population.end())
    {
        population.erase(findIter);
        individual->IndividualDied(time);
        dead.insert(individual);
    }
}

void Population::CheckDeaths()
{
    LoggerPtr logger = Logger::GetLogger();
    WorldTime now = WorldProperties::Properties()->Now();
    std::vector<std::pair<IndividualPtr, WorldTime>> newlyDead;
    for (auto individual : population)
    {
        TimeSpan span = individual->GetMaximumAge();
        WorldTime born = individual->GetBorn();
        WorldTime deathTime = born + span;
        if (now > deathTime)
        {
            newlyDead.push_back(std::make_pair(individual, deathTime));
        }
    }
    for (auto individual : newlyDead)
    {
        std::wstringstream message;
        message << individual.first->GetName().ToString() << L" died atr " << individual.second.ToString();
        logger->Log(message.str());
        Died(individual.first, individual.second);
    }
}

void Population::Visit(IPopulationVisitor* pVisitor)
{
    for (auto individual : population)
    {
        pVisitor->VisitIndividual(individual.get());
    }
}

void Population::Visit(IPopulationVisitor* pVisitor, IPopulationFilter* pFilter)
{
    for (auto individual : population)
    {
        if (pFilter->Allow(individual.get()))
        {
            pVisitor->VisitIndividual(individual.get());
        }
    }
}

std::vector<IndividualPtr> Population::Filter(IPopulationFilter* pFilter)
{
    std::vector<IndividualPtr> result;
    for (auto individual : population)
    {
        if (pFilter->Allow(individual.get()))
        {
            result.push_back(individual);
        }
    }
    return result;
}

std::size_t Population::FilterCount(IPopulationFilter* pFilter)
{
    std::size_t result = 0;
    for (auto individual : population)
    {
        if (pFilter->Allow(individual.get()))
        {
            ++result;
        }
    }
    return result;
}