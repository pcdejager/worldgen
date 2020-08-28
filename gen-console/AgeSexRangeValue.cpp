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
    if (sex.IsMale())
    {
        return Value(index, heightMale, age);
    }
    else if (sex.IsFemale())
    {
        return Value(index, heightFemale, age);
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
    __int64 ageStart = ages->AgeStart(category);
    __int64 ageEnd = ages->NextAgeStart(category);

    double index = static_cast<double>(age.Ticks() - ageStart) / static_cast<double>(ageEnd - ageStart);

#ifdef UNITTEST
    std::wcout << L"-----------------------------------------" << std::endl;
    std::wcout << L"Age     : " << age.ToString() << std::endl;
    std::wcout << L"AgeStart: " << TimeSpan(ages->AgeStart(category)).ToString() << std::endl;
    std::wcout << L"AgeEnd  : " << TimeSpan(ages->NextAgeStart(category)).ToString() << std::endl;
    std::wcout << L"Index   : " << index << std::endl;
    std::wcout << L"Start   : " << start << std::endl;
    std::wcout << L"End     : " << end << std::endl;
#endif

    return MathUtils::ScaleInt(start, end, index);
}