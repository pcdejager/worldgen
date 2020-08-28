#include "pch.h"
#include "..\AgeSexRangeValue.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\Sex.h"

TEST(HeightTest, Constructor)
{
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sex(true, false, false);
    EXPECT_EQ(test.Value(0.5, TimeSpan(1, 0, 0, 0, 0, true), sex), -1L);
}

TEST(HeightTest, Value_Male)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false, false);
    for (__int64 count = 0L; count <= 70L; count += 5L)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexMale), 10L + count);
        EXPECT_EQ(test.Value(0.0, year * count, sexMale), 15L + count);
        EXPECT_EQ(test.Value(1.0, year * count, sexMale), 20L + count);
    }
}

TEST(HeightTest, Value_Female)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexFemale(false, true, false);
    for (__int64 count = 0L; count <= 70L; count += 5L)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexFemale), 0L + count);
        EXPECT_EQ(test.Value(0.0, year * count, sexFemale), 5L + count);
        EXPECT_EQ(test.Value(1.0, year * count, sexFemale), 10L + count);
    }
}

TEST(HeightTest, Value_Male_Elder)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false, false);
    for (__int64 count = 70L; count < 80L; ++count)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexMale), 80L);
        EXPECT_EQ(test.Value(0.0, year * count, sexMale), 85L);
        EXPECT_EQ(test.Value(1.0, year * count, sexMale), 90L);
    }
}

TEST(HeightTest, Value_Female_Elder)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexFemale(false, true, false);
    for (__int64 count = 70L; count < 80L; ++count)
    {
        EXPECT_EQ(test.Value(-1.0, year * count, sexFemale), 70L);
        EXPECT_EQ(test.Value(0.0, year * count, sexFemale), 75L);
        EXPECT_EQ(test.Value(1.0, year * count, sexFemale), 80L);
    }
}
TEST(HeightTest, Value_Outside_boundaries)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    AgeSexRangeValue test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(0.5, year * -1L, sexMale), -1L);
    EXPECT_EQ(test.Value(0.5, year * 80L, sexMale), -1L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(0.5, year * -1L, sexFemale), -1L);
    EXPECT_EQ(test.Value(0.5, year * 80L, sexFemale), -1L);
}