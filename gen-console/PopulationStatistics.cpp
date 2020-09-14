#include "pch.h"
#include "PopulationStatistics.h"
#include "Individual.h"
#include "Race.h"
#include "Races.h"

PopulationStatistics::PopulationStatistics()
    : total(0ULL)
    , males(0ULL)
    , females(0ULL)
    , raceStatistics()
{
    SetupContainers();
}

void PopulationStatistics::Reset()
{
    total = 0ULL;
    males = 0ULL;
    females = 0ULL;
    raceStatistics.clear();
    SetupContainers();
}

unsigned __int64 PopulationStatistics::MalesOfRace(__int64 raceID) const
{
    auto find = raceStatistics.find(raceID);
    if (find != raceStatistics.end())
    {
        return find->second.sex.males;
    }
    return 0ULL;
}

unsigned __int64 PopulationStatistics::FemalesOfRace(__int64 raceID) const
{
    auto find = raceStatistics.find(raceID);
    if (find != raceStatistics.end())
    {
        return find->second.sex.females;
    }
    return 0ULL;
}

void PopulationStatistics::VisitIndividual(Individual* individual)
{
    ++total;
    RacePtr race = individual->Race();
    AgeCategory ageCategory = individual->AgeCategory();
    __int64 raceID = race->ID();
    if (individual->Sex().IsFemale())
    {
        ++females;
        raceStatistics[raceID].sex.females += 1ULL;
        raceStatistics[raceID].perAge[ageCategory].females += 1ULL;
    }
    if (individual->Sex().IsMale())
    {
        ++males;
        raceStatistics[raceID].sex.males += 1ULL;
        raceStatistics[raceID].perAge[ageCategory].males += 1ULL;
    }
}

void PopulationStatistics::SetupContainers()
{
    auto races = Races::GetRaces();
    auto ids = races->AllRaceIDs();
    for (__int64 id : ids)
    {
        RaceStatistics raceStats;
        raceStats.sex.females = 0ULL;
        raceStats.sex.males = 0ULL;
        auto categories = AgeCategoryUtils::AliveCategories();
        for (AgeCategory category : categories)
        {
            SexStatistics sex;
            sex.females = 0ULL;
            sex.males = 0ULL;
            raceStats.perAge.insert(std::make_pair(category, sex));
        }
        raceStatistics.insert(std::make_pair(id, raceStats));
    }
}