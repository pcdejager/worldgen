#include "pch.h"
#include "Race.h"

Race::Race(const std::wstring& raceName, __int64 raceID, const RacialTraits& raceTraits)
    : name(raceName)
    , id(raceID)
    , traits(raceTraits)
{
    ;
}
