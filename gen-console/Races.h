#pragma once

#include "MultiPointValue.h"

class Races
{
    struct RacialTraits
    {
        MultiPointValue pregnancy;
    };

    class Race
    {
    public:
        Race(const std::wstring& raceName, const RacialTraits& raceTraits) 
            : name(raceName) 
            , traits(raceTraits)
        { ; }
        ~Race() = default;

    public:
        std::wstring Name() { return name; }
    private:
        std::wstring name;
        RacialTraits traits;        
    };

    typedef std::shared_ptr<Race> RacePtr;

public:
    Races() { ; }
    ~Races() = default;

    void Initialize();

private:
    std::vector<RacePtr> races;
};

