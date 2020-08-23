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