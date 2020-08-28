#include "pch.h"
#include "AgeTraits.h"
#include "AgeCategory.h"

AgeTraits::AgeTraits(const MultiPointValueInt& ranges)
{
    ages.clear();
    ages.push_back(std::make_pair(AgeCategory::NewBorn, 0L));
    ages.push_back(std::make_pair(AgeCategory::Toddler, ranges.Value(0)));
    ages.push_back(std::make_pair(AgeCategory::Child, ranges.Value(1)));
    ages.push_back(std::make_pair(AgeCategory::Teenager, ranges.Value(2)));
    ages.push_back(std::make_pair(AgeCategory::YoungAdult, ranges.Value(3)));
    ages.push_back(std::make_pair(AgeCategory::Adult, ranges.Value(4)));
    ages.push_back(std::make_pair(AgeCategory::OldAdult, ranges.Value(5)));
    ages.push_back(std::make_pair(AgeCategory::Elder, ranges.Value(6)));
    ages.push_back(std::make_pair(AgeCategory::Dead, ranges.Value(7)));
}

AgeCategory AgeTraits::Categorize(const TimeSpan& age) const
{
    if (age.Negative())
    {
        return AgeCategory::Dead;
    }
    auto previous = ages.begin();
    auto current = ages.begin();
    ++current;
    do
    {
        if ((age >= previous->second) && (age < current->second))
        {
            return previous->first;
        }
        ++current;
        ++previous;
    } 
    while (current != ages.end());
    return AgeCategory::Dead;
}

__int64 AgeTraits::AgeStart(AgeCategory age) const
{
    for (auto iter = ages.begin(); iter < ages.end(); ++iter)
    {
        if (iter->first == age)
        {
            return iter->second;
        }
    }
    return -1L;
}

__int64 AgeTraits::AgeEnd(AgeCategory age) const
{
    if (age == AgeCategory::Dead)
    {
        return -1L;
    }
    AgeCategory test = AgeCategoryUtils::CategoryAfter(age);
    for (auto iter = ages.begin(); iter < ages.end(); ++iter)
    {
        if (iter->first == test)
        {
            return (iter->second - 1L);
        }
    }
    return -1L;
}

__int64 AgeTraits::NextAgeStart(AgeCategory age) const
{
    __int64 end = AgeEnd(age);
    if (end > 0L)
    {
        end += 1L;
    }
    return end;
}