#include "pch.h"
#include "..\AgeSexRangeValue.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\Sex.h"

TEST(HeightTest, Constructor)
{
    MultiPointValueInt ranges({ 10LL, 20LL, 30LL, 40LL, 50LL, 60LL, 70LL, 80LL });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sex(true, false);
    EXPECT_EQ(test.Value(0.5, TimeSpan(1, 0, 0, 0, 0, true), sex), -1LL);
}

TEST(HeightTest, Value_Male)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false);
    for (__int64 count = 0LL; count <= 70LL; count += 5LL)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexMale), 10LL + count);
        EXPECT_EQ(test.Value(0.0, year * count, sexMale), 15LL + count);
        EXPECT_EQ(test.Value(1.0, year * count, sexMale), 20LL + count);
    }
}

TEST(HeightTest, Value_Female)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexFemale(false, true);
    for (__int64 count = 0LL; count <= 70LL; count += 5LL)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexFemale), 0LL + count);
        EXPECT_EQ(test.Value(0.0, year * count, sexFemale), 5LL + count);
        EXPECT_EQ(test.Value(1.0, year * count, sexFemale), 10LL + count);
    }
}

TEST(HeightTest, Value_Male_Elder)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false);
    for (__int64 count = 70LL; count < 80LL; ++count)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexMale), 80LL);
        EXPECT_EQ(test.Value(0.0, year * count, sexMale), 85LL);
        EXPECT_EQ(test.Value(1.0, year * count, sexMale), 90LL);
    }
}

TEST(HeightTest, Value_Female_Elder)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexFemale(false, true);
    for (__int64 count = 70LL; count < 80LL; ++count)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexFemale), 70LL);
        EXPECT_EQ(test.Value(0.0, year * count, sexFemale), 75LL);
        EXPECT_EQ(test.Value(1.0, year * count, sexFemale), 80LL);
    }
}
TEST(HeightTest, Value_Outside_boundaries)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false);
    EXPECT_EQ(test.Value(0.5, year * -1LL, sexMale), -1LL);
    EXPECT_EQ(test.Value(0.5, year * 80LL, sexMale), -1LL);

    Sex sexFemale(false, true);
    EXPECT_EQ(test.Value(0.5, year * -1LL, sexFemale), -1LL);
    EXPECT_EQ(test.Value(0.5, year * 80LL, sexFemale), -1LL);
}