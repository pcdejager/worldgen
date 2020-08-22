#include "pch.h"
#include "../Sex.h"

TEST(SexTest, Constructor)
{
    Sex test(true, false, false);
    EXPECT_TRUE(test.IsMale());
    EXPECT_FALSE(test.IsFemale());
    EXPECT_FALSE(test.IsFertile());
}

TEST(SexTest, IsMale)
{
    Sex test1(true, false, false);
    EXPECT_TRUE(test1.IsMale());

    Sex test2(false, true, true);
    EXPECT_FALSE(test2.IsMale());
}

TEST(SexTest, IsFemale)
{
    Sex test1(false, true, false);
    EXPECT_TRUE(test1.IsFemale());

    Sex test2(true, false, true);
    EXPECT_FALSE(test2.IsFemale());
}

TEST(SexTest, IsFertile)
{
    Sex test1(false, false, true);
    EXPECT_TRUE(test1.IsFertile());

    Sex test2(true, true, false);
    EXPECT_FALSE(test2.IsFertile());
}