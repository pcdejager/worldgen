#include "pch.h"
#include "..\Height.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\Sex.h"

TEST(HeightTest, Constructor)
{
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sex(true, false, false);
    EXPECT_EQ(test.Value(0.5, TimeSpan(1, 0, 0, 0, 0, true), sex), -1L);
}

TEST(HeightTest, Value_NewBorn)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(-1.0, year * 0L, sexMale), 10L);
    EXPECT_EQ(test.Value(0.0, year * 0L, sexMale), 15L);
    EXPECT_EQ(test.Value(1.0, year * 0L, sexMale), 20L);

    EXPECT_EQ(test.Value(-1.0, year * 5L, sexMale), 15L);
    EXPECT_EQ(test.Value(0.0, year * 5L, sexMale), 20L);
    EXPECT_EQ(test.Value(1.0, year * 5L, sexMale), 25L);

    EXPECT_EQ(test.Value(-1.0, year * 10L, sexMale), 20L);
    EXPECT_EQ(test.Value(0.0, year * 10L, sexMale), 25L);
    EXPECT_EQ(test.Value(1.0, year * 10L, sexMale), 30L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(-1.0, year * 0L, sexFemale), 0L);
    EXPECT_EQ(test.Value(0.0, year * 0L, sexFemale), 5L);
    EXPECT_EQ(test.Value(1.0, year * 0L, sexFemale), 10L);

    EXPECT_EQ(test.Value(-1.0, year * 5L, sexFemale), 5L);
    EXPECT_EQ(test.Value(0.0, year * 5L, sexFemale), 10L);
    EXPECT_EQ(test.Value(1.0, year * 5L, sexFemale), 15L);

    EXPECT_EQ(test.Value(-1.0, year * 10L, sexFemale), 10L);
    EXPECT_EQ(test.Value(0.0, year * 10L, sexFemale), 15L);
    EXPECT_EQ(test.Value(1.0, year * 10L, sexFemale), 20L);
}

TEST(HeightTest, Value_Toddler)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(-1.0, year * 10L, sexMale), 20L);
    EXPECT_EQ(test.Value(0.0, year * 10L, sexMale), 25L);
    EXPECT_EQ(test.Value(1.0, year * 10L, sexMale), 30L);

    EXPECT_EQ(test.Value(-1.0, year * 15L, sexMale), 25L);
    EXPECT_EQ(test.Value(0.0, year * 15L, sexMale), 30L);
    EXPECT_EQ(test.Value(1.0, year * 15L, sexMale), 35L);

    EXPECT_EQ(test.Value(-1.0, year * 20L, sexMale), 30L);
    EXPECT_EQ(test.Value(0.0, year * 20L, sexMale), 35L);
    EXPECT_EQ(test.Value(1.0, year * 20L, sexMale), 40L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(-1.0, year * 10L, sexFemale), 10L);
    EXPECT_EQ(test.Value(0.0, year * 10L, sexFemale), 15L);
    EXPECT_EQ(test.Value(1.0, year * 10L, sexFemale), 20L);

    EXPECT_EQ(test.Value(-1.0, year * 15L, sexFemale), 15L);
    EXPECT_EQ(test.Value(0.0, year * 15L, sexFemale), 20L);
    EXPECT_EQ(test.Value(1.0, year * 15L, sexFemale), 25L);

    EXPECT_EQ(test.Value(-1.0, year * 20L, sexFemale), 20L);
    EXPECT_EQ(test.Value(0.0, year * 20L, sexFemale), 25L);
    EXPECT_EQ(test.Value(1.0, year * 20L, sexFemale), 30L);
}

TEST(HeightTest, Value_Child)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(-1.0, year * 20L, sexMale), 30L);
    EXPECT_EQ(test.Value(0.0, year * 20L, sexMale), 35L);
    EXPECT_EQ(test.Value(1.0, year * 20L, sexMale), 40L);

    EXPECT_EQ(test.Value(-1.0, year * 25L, sexMale), 35L);
    EXPECT_EQ(test.Value(0.0, year * 25L, sexMale), 40L);
    EXPECT_EQ(test.Value(1.0, year * 25L, sexMale), 45L);

    EXPECT_EQ(test.Value(-1.0, year * 30L, sexMale), 40L);
    EXPECT_EQ(test.Value(0.0, year * 30L, sexMale), 45L);
    EXPECT_EQ(test.Value(1.0, year * 30L, sexMale), 50L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(-1.0, year * 20L, sexFemale), 20L);
    EXPECT_EQ(test.Value(0.0, year * 20L, sexFemale), 25L);
    EXPECT_EQ(test.Value(1.0, year * 20L, sexFemale), 30L);

    EXPECT_EQ(test.Value(-1.0, year * 25L, sexFemale), 25L);
    EXPECT_EQ(test.Value(0.0, year * 25L, sexFemale), 30L);
    EXPECT_EQ(test.Value(1.0, year * 25L, sexFemale), 35L);

    EXPECT_EQ(test.Value(-1.0, year * 30L, sexFemale), 30L);
    EXPECT_EQ(test.Value(0.0, year * 30L, sexFemale), 35L);
    EXPECT_EQ(test.Value(1.0, year * 30L, sexFemale), 40L);
}

TEST(HeightTest, Value_Teenager)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(-1.0, year * 30L, sexMale), 40L);
    EXPECT_EQ(test.Value(0.0, year * 30L, sexMale), 45L);
    EXPECT_EQ(test.Value(1.0, year * 30L, sexMale), 50L);

    EXPECT_EQ(test.Value(-1.0, year * 35L, sexMale), 45L);
    EXPECT_EQ(test.Value(0.0, year * 35L, sexMale), 50L);
    EXPECT_EQ(test.Value(1.0, year * 35L, sexMale), 55L);

    EXPECT_EQ(test.Value(-1.0, year * 40L, sexMale), 50L);
    EXPECT_EQ(test.Value(0.0, year * 40L, sexMale), 55L);
    EXPECT_EQ(test.Value(1.0, year * 40L, sexMale), 60L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(-1.0, year * 30L, sexFemale), 30L);
    EXPECT_EQ(test.Value(0.0, year * 30L, sexFemale), 35L);
    EXPECT_EQ(test.Value(1.0, year * 30L, sexFemale), 40L);

    EXPECT_EQ(test.Value(-1.0, year * 35L, sexFemale), 35L);
    EXPECT_EQ(test.Value(0.0, year * 35L, sexFemale), 40L);
    EXPECT_EQ(test.Value(1.0, year * 35L, sexFemale), 45L);

    EXPECT_EQ(test.Value(-1.0, year * 40L, sexFemale), 40L);
    EXPECT_EQ(test.Value(0.0, year * 40L, sexFemale), 45L);
    EXPECT_EQ(test.Value(1.0, year * 40L, sexFemale), 50L);
}

TEST(HeightTest, Value_Outside_boundaries)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {0, 5, 10}, {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80} });
    Height test(male, female, ages);
    Sex sexMale(true, false, false);
    EXPECT_EQ(test.Value(0.5, year * -1L, sexMale), -1L);
    EXPECT_EQ(test.Value(0.5, year * 81L, sexMale), -1L);

    Sex sexFemale(false, true, false);
    EXPECT_EQ(test.Value(0.5, year * -1L, sexFemale), -1L);
    EXPECT_EQ(test.Value(0.5, year * 81L, sexFemale), -1L);
}