#pragma once

#include "MultiPointValue.h"
#include "Types.h"

struct RacialTraits
{
    MultiPointValueInt gene;
    AgeTraitsPtr ageRanges;
    ValueRange period;
    ValueRange pregnancy;
    AgeSexRangeValuePtr height;
    AgeSexRangeValuePtr weight;
    MarryPtr marry;
};
