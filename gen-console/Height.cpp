#include "pch.h"
#include "Height.h"
#include "ValueRange.h"
#include "AgeCategory.h"
#include "AgeTraits.h"

Height::Height(const MultiPointValueRange& male, const MultiPointValueRange& female, const AgeTraitsPtr& traits)
    : ages(traits)
    , heightMale(male)
    , heightFemale(female)
{
    ;
}

__int64 Height::Value(const TimeSpan& age, const Sex& sex) const
{
    __int64 ticks = age.Ticks();
    if (sex.IsMale())
    {
        return Value(heightMale, ticks);
    }
    else if (sex.IsFemale())
    {
        return Value(heightFemale, ticks);
    }
    return -1L;
}


__int64 Height::Value(const MultiPointValueRange& range, const TimeSpan& age) const
{
    if (age < 0L)
    {
        return -1L;
    }
    AgeCategory category = ages->Categorize(age);
    switch (category)
    {
    case AgeCategory::NewBorn:
        return Value(range.Value(0), category, age);
    case AgeCategory::Toddler:
        return Value(range.Value(1), category, age);
    case AgeCategory::Child:
        return Value(range.Value(2), category, age);
    case AgeCategory::Teenager:
        return Value(range.Value(3), category, age);
    case AgeCategory::YoungAdult:
        return Value(range.Value(4), category, age);
    case AgeCategory::Adult:
        return Value(range.Value(5), category, age);
    case AgeCategory::OldAdult:
        return Value(range.Value(6), category, age);
    case AgeCategory::Elder:
        return Value(range.Value(7), category, age);
    case AgeCategory::Dead:
        return -1L;
    default:
        return -1L;
    }
}

__int64 Height::Value(const ValueRange& range, AgeCategory category, const TimeSpan& age) const
{
    __int64 start = ages->AgeStart(category);
    __int64 end = ages->AgeEnd(category);
    double index = static_cast<double>(age.Ticks() - start) / static_cast<double>(end - start);
    return range.Value(index);
}