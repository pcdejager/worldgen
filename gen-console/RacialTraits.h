#pragma once

#include "MultiPointValue.h"
#include "Types.h"

struct RacialTraits
{
    MultiPointValueInt gene;
    AgeTraitsPtr ageRanges;
    MultiPointValueInt pregnancy;
    AgeSexRangeValuePtr height;
    AgeSexRangeValuePtr weight;
};
