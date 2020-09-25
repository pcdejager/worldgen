#include "pch.h"
#include "../Sex.h"
#include "../TimeSpan.h"

TEST(SexTest, Constructor)
{
    TimeSpan period(20LL, 0LL, 0LL, 0LL);
    Sex test(true, false);
    EXPECT_TRUE(test.IsMale());
    EXPECT_FALSE(test.IsFemale());
}

TEST(SexTest, IsMale)
{
    Sex test1(true, false);
    EXPECT_TRUE(test1.IsMale());

    Sex test2(false, true);
    EXPECT_FALSE(test2.IsMale());
}

TEST(SexTest, IsFemale)
{
    Sex test1(false, true);
    EXPECT_TRUE(test1.IsFemale());

    Sex test2(true, false);
    EXPECT_FALSE(test2.IsFemale());
}

