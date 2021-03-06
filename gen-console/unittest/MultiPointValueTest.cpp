#include "pch.h"
#include "..\MultiPointValue.h"

TEST(MultiPointValueIntTest, Constructor)
{
    MultiPointValueInt test;
    EXPECT_EQ(test.Count(), 0);
}

TEST(MultiPointValueIntTest, Constructor_values)
{
    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), 1LL);
    EXPECT_EQ(test.Value(1), 2LL);
    EXPECT_EQ(test.Value(2), 3LL);
}

TEST(MultiPointValueIntTest, Set)
{
    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test;
    test.Set(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), 1LL);
    EXPECT_EQ(test.Value(1), 2LL);
    EXPECT_EQ(test.Value(2), 3LL);
}

TEST(MultiPointValueIntTest, Count)
{
    MultiPointValueInt test1;
    EXPECT_EQ(test1.Count(), 0);

    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test2;
    test2.Set(values);
    EXPECT_EQ(test2.Count(), 3);
}

TEST(MultiPointValueIntTest, Minimum)
{
    MultiPointValueInt test1;
    EXPECT_EQ(test1.Minimum(), 0);

    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test2;
    test2.Set(values);
    EXPECT_EQ(test2.Minimum(), 1);
}

TEST(MultiPointValueIntTest, Maximum)
{
    MultiPointValueInt test1;
    EXPECT_EQ(test1.Maximum(), 0);

    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test2;
    test2.Set(values);
    EXPECT_EQ(test2.Maximum(), 3);
}

TEST(MultiPointValueIntTest, Value)
{
    std::vector<__int64> values = { 1LL, 2LL, 3LL };
    MultiPointValueInt test;
    test.Set(values);
    EXPECT_EQ(test.Value(0), 1LL);
    EXPECT_EQ(test.Value(1), 2LL);
    EXPECT_EQ(test.Value(2), 3LL);
}

TEST(MultiPointValueRangeTest, Constructor)
{
    MultiPointValueRange test;
    EXPECT_EQ(test.Count(), 0);
}

TEST(MultiPointValueRangeTest, Constructor_values)
{
    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range1, range2, range3 };
    MultiPointValueRange test(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), range1);
    EXPECT_EQ(test.Value(1), range2);
    EXPECT_EQ(test.Value(2), range3);
}

TEST(MultiPointValueRangeTest, Set)
{
    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range1, range2, range3 };
    MultiPointValueRange test;
    test.Set(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), range1);
    EXPECT_EQ(test.Value(1), range2);
    EXPECT_EQ(test.Value(2), range3);
}

TEST(MultiPointValueRangeTest, Count)
{
    MultiPointValueRange test1;
    EXPECT_EQ(test1.Count(), 0);

    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range3, range2, range1 };
    MultiPointValueRange test2;
    test2.Set(values);
    EXPECT_EQ(test2.Count(), 3);
}

TEST(MultiPointValueRangeTest, Minimum)
{
    MultiPointValueRange test1;
    EXPECT_EQ(test1.Minimum(), ValueRange());

    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range1, range2, range3 };
    MultiPointValueRange test2;
    test2.Set(values);
    EXPECT_EQ(test2.Minimum(), range1);
}

TEST(MultiPointValueRangeTest, Maximum)
{
    MultiPointValueRange test1;
    EXPECT_EQ(test1.Maximum(), ValueRange());

    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range1, range2, range3 };
    MultiPointValueRange test2;
    test2.Set(values);
    EXPECT_EQ(test2.Maximum(), range3);
}

TEST(MultiPointValueRangeTest, Value)
{
    ValueRange range1 = { 1LL,2LL,3LL };
    ValueRange range2 = { 2LL,3LL,4LL };
    ValueRange range3 = { 3LL,4LL,5LL };
    std::vector<ValueRange> values = { range1, range2, range3 };
    MultiPointValueRange test;
    test.Set(values);
    EXPECT_EQ(test.Value(0), range1);
    EXPECT_EQ(test.Value(1), range2);
    EXPECT_EQ(test.Value(2), range3);
}
