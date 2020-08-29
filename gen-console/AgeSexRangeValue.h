#pragma once

#include "Types.h"
#include "MultiPointValue.h"
#include "TimeSpan.h"
#include "Sex.h"
#include "AgeCategory.h"

class AgeSexRangeValue
{
private:
    AgeSexRangeValue() = delete;
public:
    AgeSexRangeValue(const MultiPointValueRange& male, const MultiPointValueRange& female, const AgeTraitsPtr& traits);
    ~AgeSexRangeValue() = default;

public:
    __int64 Value(double index, const TimeSpan& age, const Sex& sex) const;

private:
    __int64 Value(double index, const MultiPointValueRange& range, const TimeSpan& age) const;
    __int64 Value(__int64 start, __int64 end, AgeCategory category, const TimeSpan& age) const;

#ifdef UNITTEST
public:
    MultiPointValueRange& MaleRange() { return heightMale; }
    MultiPointValueRange& FemaleRange() { return heightFemale; }
#endif

private:
    AgeTraitsPtr ages;
    MultiPointValueRange heightMale;
    MultiPointValueRange heightFemale;
};

