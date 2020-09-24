#include "pch.h"
#include "../Sex.h"
#include "../TimeSpan.h"
TEST(SexTest, Constructor)
{
    TimeSpan period(20LL, 0LL, 0LL, 0LL);
    Sex test(true, false, period, 0.0);
    EXPECT_TRUE(test.IsMale());
    EXPECT_FALSE(test.IsFemale());
    EXPECT_FALSE(test.IsFertile());
    EXPECT_EQ(test.PeriodCycle(), period);
}

TEST(SexTest, IsMale)
{
    TimeSpan period(20LL, 0LL, 0LL, 0LL);

    Sex test1(true, false, period, 0.0);
    EXPECT_TRUE(test1.IsMale());

    Sex test2(false, true, period, 1.0);
    EXPECT_FALSE(test2.IsMale());
}

TEST(SexTest, IsFemale)
{
    TimeSpan period(20LL, 0LL, 0LL, 0LL);

    Sex test1(false, true, period, 0.0);
    EXPECT_TRUE(test1.IsFemale());

    Sex test2(true, false, period, 1.0);
    EXPECT_FALSE(test2.IsFemale());
}

TEST(SexTest, IsFertile)
{
    TimeSpan period(20LL, 0LL, 0LL, 0LL);

    Sex test1(false, false, period, 1.0);
    EXPECT_TRUE(test1.IsFertile());

    Sex test2(true, true, period, 0.0);
    EXPECT_FALSE(test2.IsFertile());
}

TEST(SexTest, PeriodCycle)
{
    TimeSpan period1(20LL, 0LL, 0LL, 0LL);
    TimeSpan period2(21LL, 0LL, 0LL, 0LL);

    Sex test1(false, false, period1, 1.0);
    EXPECT_EQ(test1.PeriodCycle(), period1);

    Sex test2(true, true, period2, 0.0);
    EXPECT_EQ(test2.PeriodCycle(), period2);
}