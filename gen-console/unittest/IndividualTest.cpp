#include "pch.h"
#include "..\Individual.h"

TEST(IndividualTest, Constructor)
{
    Individual test(WorldTime(123UL));
    EXPECT_EQ(WorldTime(123UL), test.Born());
}

TEST(IndividualTest, Age)
{
    Individual test(WorldTime(123UL));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(123UL)));
    EXPECT_EQ(TimeSpan(123L), test.Age(WorldTime(246UL)));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(0UL)));
}