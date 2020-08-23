#pragma once

#include "Types.h"

class Races
{
public:
    Races() { ; }
    ~Races() = default;

    void Initialize();

public:
    std::size_t NumberOfRaces() const { return races.size(); }
    bool HasRace(const std::wstring& name) const;
    RacePtr FindRace(const std::wstring& name) const;
private:
    std::vector<RacePtr> races;
};

