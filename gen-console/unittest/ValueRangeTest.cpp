#include "pch.h"
#include "..\ValueRange.h"

TEST(ValueRangeTest, Constructor_default)
{
    ValueRange range;
    EXPECT_EQ(range.Minimum(), 0LL);
    EXPECT_EQ(range.Average(), 0LL);
    EXPECT_EQ(range.Maximum(), 0LL);
}

TEST(ValueRangeTest, Constructor_values)
{
    ValueRange range(20LL, 30LL, 40LL);
    EXPECT_EQ(range.Minimum(), 20LL);
    EXPECT_EQ(range.Average(), 30LL);
    EXPECT_EQ(range.Maximum(), 40LL);
}

TEST(ValueRangeTest, ToString)
{
    ValueRange range(20LL, 30LL, 40LL);
    EXPECT_EQ(range.ToString(), L"[20-30-40]");
}

TEST(ValueRangeTest, Value)
{
    __int64 min = 100LL;
    __int64 avg = 200LL;
    __int64 max = 300LL;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-0.75), 125LL);
    EXPECT_EQ(range.Value(-0.5), 150LL);
    EXPECT_EQ(range.Value(-0.25), 175LL);
    EXPECT_EQ(range.Value(0.0), avg);
    EXPECT_EQ(range.Value(0.25), 225LL);
    EXPECT_EQ(range.Value(0.5), 250LL);
    EXPECT_EQ(range.Value(0.75), 275LL);
    EXPECT_EQ(range.Value(1.0), max);
}

TEST(ValueRangeTest, Value_offcenter)
{
    __int64 min = 160LL;
    __int64 avg = 200LL;
    __int64 max = 400LL;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-0.75), 170LL);
    EXPECT_EQ(range.Value(-0.5), 180LL);
    EXPECT_EQ(range.Value(-0.25), 190LL);
    EXPECT_EQ(range.Value(0.0), avg);
    EXPECT_EQ(range.Value(0.25), 250LL);
    EXPECT_EQ(range.Value(0.5), 300LL);
    EXPECT_EQ(range.Value(0.75), 350LL);
    EXPECT_EQ(range.Value(1.0), max);
}

TEST(ValueRangeTest, Value_min)
{
    __int64 min = 100LL;
    __int64 avg = 200LL;
    __int64 max = 300LL;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(-1.0), min);
    EXPECT_EQ(range.Value(-1.01), min);
    EXPECT_EQ(range.Value(-123.1), min);
}

TEST(ValueRangeTest, Value_max)
{
    __int64 min = 100LL;
    __int64 avg = 200LL;
    __int64 max = 300LL;
    ValueRange range(min, avg, max);

    EXPECT_EQ(range.Value(1.0), max);
    EXPECT_EQ(range.Value(1.01), max);
    EXPECT_EQ(range.Value(123.1), max);
}

TEST(ValueRangeTest, OperatorEQ)
{
    ValueRange range0(20LL, 30LL, 40LL);
    ValueRange range1(21LL, 30LL, 40LL);
    ValueRange range2(20LL, 31LL, 40LL);
    ValueRange range3(20LL, 30LL, 41LL);
    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_TRUE(range0 == test);
    EXPECT_FALSE(range1 == test);
    EXPECT_FALSE(range2 == test);
    EXPECT_FALSE(range3 == test);
}

TEST(ValueRangeTest, OperatorNE)
{
    ValueRange range0(20LL, 30LL, 40LL);
    ValueRange range1(21LL, 30LL, 40LL);
    ValueRange range2(20LL, 31LL, 40LL);
    ValueRange range3(20LL, 30LL, 41LL);
    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_FALSE(range0 != test);
    EXPECT_TRUE(range1 != test);
    EXPECT_TRUE(range2 != test);
    EXPECT_TRUE(range3 != test);
}

TEST(ValueRangeTest, OperatorLT)
{
    ValueRange range0(20LL, 30LL, 40LL);
    ValueRange range1(21LL, 30LL, 40LL);
    ValueRange range2(20LL, 31LL, 40LL);
    ValueRange range3(20LL, 30LL, 41LL);

    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_FALSE(test < range0);
    EXPECT_FALSE(test < range1);
    EXPECT_TRUE(test < range2);
    EXPECT_FALSE(test < range3);
}

TEST(ValueRangeTest, OperatorLE)
{
    ValueRange range0(20LL, 29LL, 40LL);
    ValueRange range1(21LL, 29LL, 40LL);
    ValueRange range2(20LL, 30LL, 40LL);
    ValueRange range3(20LL, 29LL, 41LL);

    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_FALSE(test <= range0);
    EXPECT_FALSE(test <= range1);
    EXPECT_TRUE(test <= range2);
    EXPECT_FALSE(test <= range3);
}

TEST(ValueRangeTest, OperatorGT)
{
    ValueRange range0(20LL, 30LL, 40LL);
    ValueRange range1(19LL, 30LL, 40LL);
    ValueRange range2(20LL, 29LL, 40LL);
    ValueRange range3(20LL, 30LL, 39LL);

    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_FALSE(test > range0);
    EXPECT_FALSE(test > range1);
    EXPECT_TRUE(test > range2);
    EXPECT_FALSE(test > range3);
}

TEST(ValueRangeTest, OperatorGE)
{
    ValueRange range0(20LL, 31LL, 40LL);
    ValueRange range1(19LL, 31LL, 40LL);
    ValueRange range2(20LL, 30LL, 40LL);
    ValueRange range3(20LL, 31LL, 39LL);

    ValueRange test(20LL, 30LL, 40LL);
    EXPECT_FALSE(test >= range0);
    EXPECT_FALSE(test >= range1);
    EXPECT_TRUE(test >= range2);
    EXPECT_FALSE(test >= range3);
}