#pragma once

class Races
{
    struct RacialTraits
    {
        __int64 minPregnancyDays;
        __int64 avgPregnancyDays;
        __int64 maxPregnancyDays;
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

