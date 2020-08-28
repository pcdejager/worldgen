#include "pch.h"
#include "AgeSexRangeValue.h"
#include "ValueRange.h"
#include "AgeCategory.h"
#include "AgeTraits.h"
#include "MathUtils.h"

AgeSexRangeValue::AgeSexRangeValue(const MultiPointValueRange& male, const MultiPointValueRange& female, const AgeTraitsPtr& traits)
    : ages(traits)
    , heightMale(male)
    , heightFemale(female)
{
    ;
}

__int64 AgeSexRangeValue::Value(double index, const TimeSpan& age, const Sex& sex) const
{
    __int64 ticks = age.Ticks();
    if (sex.IsMale())
    {
        return Value(index, heightMale, ticks);
    }
    else if (sex.IsFemale())
    {
        return Value(index, heightFemale, ticks);
    }
    return -1L;
}


__int64 AgeSexRangeValue::Value(double index, const MultiPointValueRange& range, const TimeSpan& age) const
{
    if (age < 0L)
    {
        return -1L;
    }
    AgeCategory category = ages->Categorize(age);
    switch (category)
    {
    case AgeCategory::NewBorn:
        return Value(range.Value(0).Value(index), range.Value(1).Value(index), category, age);
    case AgeCategory::Toddler:
        return Value(range.Value(1).Value(index), range.Value(2).Value(index), category, age);
    case AgeCategory::Child:
        return Value(range.Value(2).Value(index), range.Value(3).Value(index), category, age);
    case AgeCategory::Teenager:
        return Value(range.Value(3).Value(index), range.Value(4).Value(index), category, age);
    case AgeCategory::YoungAdult:
        return Value(range.Value(4).Value(index), range.Value(5).Value(index), category, age);
    case AgeCategory::Adult:
        return Value(range.Value(5).Value(index), range.Value(6).Value(index), category, age);
    case AgeCategory::OldAdult:
        return Value(range.Value(6).Value(index), range.Value(7).Value(index), category, age);
    case AgeCategory::Elder:
        return range.Value(7).Value(index);
    case AgeCategory::Dead:
        return -1L;
    default:
        return -1L;
    }
}

__int64 AgeSexRangeValue::Value(__int64 start, __int64 end, AgeCategory category, const TimeSpan& age) const
{
    __int64 ageStart = TimeSpan(ages->AgeStart(category), 0, 0, 0, 0, false).Ticks();
    __int64 ageEnd = TimeSpan(ages->NextAgeStart(category), 0, 0, 0, 0, false).Ticks();
    double index = static_cast<double>(age.Ticks() - ageStart) / static_cast<double>(ageEnd - ageStart);
    return MathUtils::ScaleInt(start, end, index);
}