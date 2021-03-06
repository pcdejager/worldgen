#include "pch.h"
#include "../MathUtils.h"

TEST(MathUtilsTest, ScaleInt)
{
    __int64 min = 100LL;
    __int64 max = 200LL;

    EXPECT_EQ(MathUtils::ScaleInt(min, max, 0.5), 150LL);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, 0.25), 125LL);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, 0.75), 175LL);
}

TEST(MathUtilsTest, ScaleInt_min)
{
    __int64 min = 100LL;
    __int64 max = 200LL;

    EXPECT_EQ(MathUtils::ScaleInt(min, max, -123.1), min);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, -0.01), min);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, 0.0), min);
}

TEST(MathUtilsTest, ScaleInt_max)
{
    __int64 min = 100LL;
    __int64 max = 200LL;

    EXPECT_EQ(MathUtils::ScaleInt(min, max, 1.0), max);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, 1.01), max);
    EXPECT_EQ(MathUtils::ScaleInt(min, max, 123.1), max);
}