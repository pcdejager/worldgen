#pragma once

#include "Types.h"
#include "Procreate.h"

class Races
{
private:
    Races() { ; }
public:
    ~Races() = default;

public:
    static RacesPtr GetRaces();

private:
    static RacesPtr instance;

protected:
    void Initialize();

public:
    std::size_t NumberOfRaces() const { return races.size(); }
    std::vector<__int64> AllRaceIDs() const;
    std::vector<std::wstring> AllRaceNames() const;
    bool HasRace(const __int64 id) const;
    bool HasRace(const std::wstring& name) const;
    std::wstring FindRaceName(__int64 value) const;
    RacePtr FindRaceByGene(__int64 value) const;
    RacePtr FindRaceByID(__int64 id) const;
    RacePtr FindRaceByName(const std::wstring& name) const;

    RacePtr ChildRace(const RacePtr& father, const RacePtr& mother, double roll);

private:
    std::map<__int64, RacePtr> races;
    std::map<std::wstring, __int64> racesByName;
    std::map<__int64, __int64> racesByGene;
    Procreate proceateMatrix;
};

