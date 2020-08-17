#include "pch.h"
#include "..\MultiPointValue.h"

TEST(MultiPointValueTest, Constructor)
{
    MultiPointValue test;
    EXPECT_EQ(test.Count(), 0);
}

TEST(MultiPointValueTest, Constructor_values)
{
    std::vector<__int64> values = { 3L, 2L, 1L };
    MultiPointValue test(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), 1L);
    EXPECT_EQ(test.Value(1), 2L);
    EXPECT_EQ(test.Value(2), 3L);
}

TEST(MultiPointValueTest, Set)
{
    std::vector<__int64> values = { 3L, 2L, 1L };
    MultiPointValue test;
    test.Set(values);
    EXPECT_EQ(test.Count(), 3);
    EXPECT_EQ(test.Value(0), 1L);
    EXPECT_EQ(test.Value(1), 2L);
    EXPECT_EQ(test.Value(2), 3L);
}

TEST(MultiPointValueTest, Count)
{
    MultiPointValue test1;
    EXPECT_EQ(test1.Count(), 0);

    std::vector<__int64> values = { 1L, 2L, 3L };
    MultiPointValue test2;
    test2.Set(values);
    EXPECT_EQ(test2.Count(), 3);
}

TEST(MultiPointValueTest, Minimum)
{
    MultiPointValue test1;
    EXPECT_EQ(test1.Minimum(), 0);

    std::vector<__int64> values = { 1L, 2L, 3L };
    MultiPointValue test2;
    test2.Set(values);
    EXPECT_EQ(test2.Minimum(), 1);
}

TEST(MultiPointValueTest, Maximum)
{
    MultiPointValue test1;
    EXPECT_EQ(test1.Maximum(), 0);

    std::vector<__int64> values = { 1L, 2L, 3L };
    MultiPointValue test2;
    test2.Set(values);
    EXPECT_EQ(test2.Maximum(), 3);
}

TEST(MultiPointValueTest, Value)
{
    std::vector<__int64> values = { 1L, 2L, 3L };
    MultiPointValue test;
    test.Set(values);
    EXPECT_EQ(test.Value(0), 1L);
    EXPECT_EQ(test.Value(1), 2L);
    EXPECT_EQ(test.Value(2), 3L);
}
