#pragma once

#include "Types.h"

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
    std::vector<std::wstring> AllRaces() const;
    bool HasRace(const std::wstring& name) const;
    RacePtr FindRace(const std::wstring& name) const;
private:
    std::map<std::wstring, RacePtr> races;
};

