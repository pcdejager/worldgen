#include "pch.h"
#include "..\Race.h"
#include "..\RacialTraits.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\AgeSexRangeValue.h"

TEST(RaceTest, Constructor)
{
    RacialTraits traits;
    Race test(L"Test", 123LL, traits);
    EXPECT_EQ(test.GetName(), L"Test");
}

TEST(RaceTest, GetName)
{
    RacialTraits traits;
    Race test(L"Test", 123LL, traits);
    EXPECT_EQ(test.GetName(), L"Test");
}

TEST(RaceTest, GetID)
{
    RacialTraits traits;
    Race test(L"Test", 123LL, traits);
    EXPECT_EQ(test.GetID(), 123LL);
}

TEST(RaceTest, GetTraits)
{
    RacialTraits traits;
    MultiPointValueInt ranges({ 1,2,3 });
    traits.ageRanges = AgeTraitsPtr(new AgeTraits(ranges));
    traits.period = ValueRange(7, 8, 9);
    traits.pregnancy = ValueRange(4, 5, 6);
    MultiPointValueRange maleHeightRange({ {11,22,33},{44,55,66},{77,88,99} });
    MultiPointValueRange femaleHeightRange({ {12,23,34},{45,56,67},{78,89,90} });
    traits.height = AgeSexRangeValuePtr(new AgeSexRangeValue(maleHeightRange, femaleHeightRange, traits.ageRanges));
    MultiPointValueRange maleWeightRange({ {11,12,13},{14,15,16},{17,18,19} });
    MultiPointValueRange femaleWeightRange({ {21,22,23},{24,25,6},{27,8,9} });
    traits.weight = AgeSexRangeValuePtr(new AgeSexRangeValue(maleWeightRange, femaleWeightRange, traits.ageRanges));
    Race race(L"Test", 123LL, traits);
    auto& test = race.GetTraits();

    EXPECT_EQ(test.ageRanges, traits.ageRanges);
    EXPECT_EQ(test.period, ValueRange(7, 8, 9));
    EXPECT_EQ(test.pregnancy, ValueRange(4, 5, 6));
    EXPECT_EQ(test.height, traits.height);
    EXPECT_EQ(test.weight, traits.weight);
}