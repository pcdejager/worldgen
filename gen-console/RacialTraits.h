#pragma once

#include "MultiPointValue.h"
#include "Types.h"

struct RacialTraits
{
    AgeTraitsPtr ageRanges;
    MultiPointValueInt pregnancy;
    MultiPointValueRange heightMale;
    MultiPointValueRange heightFemale;
};
