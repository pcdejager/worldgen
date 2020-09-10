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
        TimeSpan span = individual->MaximumAge();
        WorldTime born = individual->Born();
        WorldTime deathTime = born + span;
        if (now > deathTime)
        {
            newlyDead.push_back(std::make_pair(individual, deathTime));
        }
    }
    for (auto individual : newlyDead)
    {
        std::wstringstream message;
        message << individual.first->Name().ToString() << L" died atr " << individual.second.ToString();
        logger->Log(message.str());
        Died(individual.first, individual.second);
    }
}

void Population::Visit(IPopulationVisitor* pVisitor)
{
    for (auto individual : population)
    {
        pVisitor->VisitIndividual(individual);
    }
}

void Population::Visit(IPopulationVisitor* pVisitor, IPopulationFilter* pFilter)
{
    for (auto individual : population)
    {
        if (pFilter->Allow(individual))
        {
            pVisitor->VisitIndividual(individual);
        }
    }
}