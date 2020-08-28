#include "pch.h"
#include "..\Race.h"
#include "..\RacialTraits.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\AgeSexRangeValue.h"

TEST(RaceTest, Constructor)
{
    RacialTraits traits;
    Race test(L"Test", traits);
    EXPECT_EQ(test.Name(), L"Test");
}

TEST(RaceTest, Name)
{
    RacialTraits traits;
    Race test(L"Test", traits);
    EXPECT_EQ(test.Name(), L"Test");
}

TEST(RaceTest, Traits)
{
    RacialTraits traits;
    MultiPointValueInt ranges({ 1,2,3 });
    traits.ageRanges = AgeTraitsPtr(new AgeTraits(ranges));
    traits.pregnancy = MultiPointValueInt({ 4,5,6 });
    MultiPointValueRange maleHeightRange({ {11,22,33},{44,55,66},{77,88,99} });
    MultiPointValueRange femaleHeightRange({ {12,23,34},{45,56,67},{78,89,90} });
    traits.height = AgeSexRangeValuePtr(new AgeSexRangeValue(maleHeightRange, femaleHeightRange, traits.ageRanges));
    MultiPointValueRange maleWeightRange({ {11,12,13},{14,15,16},{17,18,19} });
    MultiPointValueRange femaleWeightRange({ {21,22,23},{24,25,6},{27,8,9} });
    traits.weight = AgeSexRangeValuePtr(new AgeSexRangeValue(maleWeightRange, femaleWeightRange, traits.ageRanges));
    Race race(L"Test", traits);
    auto& test = race.Traits();

    EXPECT_EQ(test.ageRanges, traits.ageRanges);
    EXPECT_EQ(test.pregnancy.Value(0), 4);
    EXPECT_EQ(test.height, traits.height);
    EXPECT_EQ(test.weight, traits.weight);
}