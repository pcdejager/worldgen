#pragma once

#include "MultiPointValue.h"
#include "TimeSpan.h"
#include "AgeCategory.h"

class AgeTraits
{
public:
    AgeTraits() = delete;
    AgeTraits(const MultiPointValueInt& ranges);
    ~AgeTraits() = default;
    AgeTraits(const AgeTraits&) = delete;

    AgeTraits& operator=(const AgeTraits&) = delete;

public:
    AgeCategory Categorize(const TimeSpan& age) const;
    __int64 AgeStart(AgeCategory age) const;
    __int64 AgeEnd(AgeCategory age) const;
    __int64 NextAgeStart(AgeCategory age) const;

private:
    std::vector<std::pair<AgeCategory, __int64>> ages;
};