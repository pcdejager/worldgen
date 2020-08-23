#include "pch.h"
#include "Race.h"

Race::Race(const std::wstring& raceName, const RacialTraits& raceTraits)
    : name(raceName)
    , traits(raceTraits)
{
    ;
}
