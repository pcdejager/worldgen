#include "pch.h"
#include "PopulationStatistics.h"
#include "Individual.h"
#include "Race.h"
#include "Races.h"

PopulationStatistics::PopulationStatistics()
    : total(0ULL)
    , males(0ULL)
    , females(0ULL)
    , maleRace()
    , femaleRace()
{
    SetupContainers();
}

void PopulationStatistics::Reset()
{
    total = 0ULL;
    males = 0ULL;
    females = 0ULL;
    maleRace.clear();
    femaleRace.clear();
    SetupContainers();
}

unsigned __int64 PopulationStatistics::MalesOfRace(__int64 raceID) const
{
    auto find = maleRace.find(raceID);
    if (find != maleRace.end())
    {
        return find->second;
    }
    return 0ULL;
}

unsigned __int64 PopulationStatistics::FemalesOfRace(__int64 raceID) const
{
    auto find = femaleRace.find(raceID);
    if (find != femaleRace.end())
    {
        return find->second;
    }
    return 0ULL;
}

void PopulationStatistics::VisitIndividual(const IndividualPtr& individual)
{
    ++total;
    auto race = individual->Race();
    if (individual->Sex().IsFemale())
    {
        ++females;
        femaleRace[race->ID()] += 1ULL;
    }
    if (individual->Sex().IsMale())
    {
        ++males;
        maleRace[race->ID()] += 1ULL;
    }
}

void PopulationStatistics::SetupContainers()
{
    auto races = Races::GetRaces();
    auto ids = races->AllRaceIDs();
    for (__int64 id : ids)
    {
        maleRace.insert(std::make_pair(id, 0ULL));
        femaleRace.insert(std::make_pair(id, 0ULL));
    }
}