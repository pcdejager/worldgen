#include "pch.h"
#include "..\ValueRange.h"

TEST(ValueRangeTest, Constructor_default)
{
    ValueRange range;
    EXPECT_EQ(range.Minimum(), 0L);
    EXPECT_EQ(range.Average(), 0L);
    EXPECT_EQ(range.Maximum(), 0L);
}

TEST(ValueRangeTest, Constructor_values)
{
    ValueRange range(20L, 30L, 40L);
    EXPECT_EQ(range.Minimum(), 20L);
    EXPECT_EQ(range.Average(), 30L);
    EXPECT_EQ(range.Maximum(), 40L);
}

TEST(ValueRangeTest, ToString)
{
    ValueRange range(20L, 30L, 40L);
    EXPECT_EQ(range.ToString(), L"[20-30-40]");
}

TEST(ValueRangeTest, Value)
{
    __int64 min = 100L;
    __int64 avg = 200L;
    __int64 max = 300L;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-0.75), 125L);
    EXPECT_EQ(range.Value(-0.5), 150L);
    EXPECT_EQ(range.Value(-0.25), 175L);
    EXPECT_EQ(range.Value(0.0), avg);
    EXPECT_EQ(range.Value(0.25), 225L);
    EXPECT_EQ(range.Value(0.5), 250L);
    EXPECT_EQ(range.Value(0.75), 275L);
    EXPECT_EQ(range.Value(1.0), max);
}

TEST(ValueRangeTest, Value_offcenter)
{
    __int64 min = 160L;
    __int64 avg = 200L;
    __int64 max = 400L;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-0.75), 170L);
    EXPECT_EQ(range.Value(-0.5), 180L);
    EXPECT_EQ(range.Value(-0.25), 190L);
    EXPECT_EQ(range.Value(0.0), avg);
    EXPECT_EQ(range.Value(0.25), 250L);
    EXPECT_EQ(range.Value(0.5), 300L);
    EXPECT_EQ(range.Value(0.75), 350L);
    EXPECT_EQ(range.Value(1.0), max);
}

TEST(ValueRangeTest, Value_min)
{
    __int64 min = 100L;
    __int64 avg = 200L;
    __int64 max = 300L;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-1.01), min);
    EXPECT_EQ(range.Value(-123.1), min);
}

TEST(ValueRangeTest, Value_max)
{
    __int64 min = 100L;
    __int64 avg = 200L;
    __int64 max = 300L;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(1.0), max);
    EXPECT_EQ(range.Value(1.01), max);
    EXPECT_EQ(range.Value(123.1), max);
}

TEST(ValueRangeTest, OperatorEQ)
{
    ValueRange range0(20L, 30L, 40L);
    ValueRange range1(21L, 30L, 40L);
    ValueRange range2(20L, 31L, 40L);
    ValueRange range3(20L, 30L, 41L);
    ValueRange test(20L, 30L, 40L);
    EXPECT_TRUE(range0 == test);
    EXPECT_FALSE(range1 == test);
    EXPECT_FALSE(range2 == test);
    EXPECT_FALSE(range3 == test);
}

TEST(ValueRangeTest, OperatorNE)
{
    ValueRange range0(20L, 30L, 40L);
    ValueRange range1(21L, 30L, 40L);
    ValueRange range2(20L, 31L, 40L);
    ValueRange range3(20L, 30L, 41L);
    ValueRange test(20L, 30L, 40L);
    EXPECT_FALSE(range0 != test);
    EXPECT_TRUE(range1 != test);
    EXPECT_TRUE(range2 != test);
    EXPECT_TRUE(range3 != test);
}

TEST(ValueRangeTest, OperatorLT)
{
    ValueRange range0(20L, 30L, 40L);
    ValueRange range1(21L, 30L, 40L);
    ValueRange range2(20L, 31L, 40L);
    ValueRange range3(20L, 30L, 41L);

    ValueRange test(20L, 30L, 40L);
    EXPECT_FALSE(test < range0);
    EXPECT_FALSE(test < range1);
    EXPECT_TRUE(test < range2);
    EXPECT_FALSE(test < range3);
}

TEST(ValueRangeTest, OperatorLE)
{
    ValueRange range0(20L, 29L, 40L);
    ValueRange range1(21L, 29L, 40L);
    ValueRange range2(20L, 30L, 40L);
    ValueRange range3(20L, 29L, 41L);

    ValueRange test(20L, 30L, 40L);
    EXPECT_FALSE(test <= range0);
    EXPECT_FALSE(test <= range1);
    EXPECT_TRUE(test <= range2);
    EXPECT_FALSE(test <= range3);
}

TEST(ValueRangeTest, OperatorGT)
{
    ValueRange range0(20L, 30L, 40L);
    ValueRange range1(19L, 30L, 40L);
    ValueRange range2(20L, 29L, 40L);
    ValueRange range3(20L, 30L, 39L);

    ValueRange test(20L, 30L, 40L);
    EXPECT_FALSE(test > range0);
    EXPECT_FALSE(test > range1);
    EXPECT_TRUE(test > range2);
    EXPECT_FALSE(test > range3);
}

TEST(ValueRangeTest, OperatorGE)
{
    ValueRange range0(20L, 31L, 40L);
    ValueRange range1(19L, 31L, 40L);
    ValueRange range2(20L, 30L, 40L);
    ValueRange range3(20L, 31L, 39L);

    ValueRange test(20L, 30L, 40L);
    EXPECT_FALSE(test >= range0);
    EXPECT_FALSE(test >= range1);
    EXPECT_TRUE(test >= range2);
    EXPECT_FALSE(test >= range3);
}