#include "pch.h"
#include "..\GenePosition.h"

TEST(GenePositionTest, Constructor)
{
    GenePosition test(GeneCategory::DOUBLE, 10, 12);
    EXPECT_EQ(test.Type(), GeneCategory::DOUBLE);
    EXPECT_EQ(test.Start(), 10);
    EXPECT_EQ(test.Size(), 12);
}

TEST(GenePositionTest, OperatorEQ)
{
    GenePosition test1(GeneCategory::DOUBLE, 10, 12);
    GenePosition test2(GeneCategory::RACE, 10, 12);
    GenePosition test3(GeneCategory::DOUBLE, 11, 12);
    GenePosition test4(GeneCategory::DOUBLE, 10, 13);
    GenePosition test5(GeneCategory::DOUBLE, 10, 12);

    EXPECT_FALSE(test1 == test2);
    EXPECT_FALSE(test1 == test3);
    EXPECT_FALSE(test1 == test4);
    EXPECT_TRUE(test1 == test5);
}

TEST(GenePositionTest, OperatorNE)
{
    GenePosition test1(GeneCategory::DOUBLE, 10, 12);
    GenePosition test2(GeneCategory::RACE, 10, 12);
    GenePosition test3(GeneCategory::DOUBLE, 11, 12);
    GenePosition test4(GeneCategory::DOUBLE, 10, 13);
    GenePosition test5(GeneCategory::DOUBLE, 10, 12);

    EXPECT_TRUE(test1 != test2);
    EXPECT_TRUE(test1 != test3);
    EXPECT_TRUE(test1 != test4);
    EXPECT_FALSE(test1 != test5);
}