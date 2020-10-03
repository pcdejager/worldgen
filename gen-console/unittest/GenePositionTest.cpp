#include "pch.h"
#include "..\GenePosition.h"

TEST(GenePositionTest, Constructor)
{
    GenePosition test(GeneType::DOUBLE, 10, 12);
    EXPECT_EQ(test.Type(), GeneType::DOUBLE);
    EXPECT_EQ(test.Start(), 10);
    EXPECT_EQ(test.Size(), 12);
}

TEST(GenePositionTest, OperatorEQ)
{
    GenePosition test1(GeneType::DOUBLE, 10, 12);
    GenePosition test2(GeneType::RACE, 10, 12);
    GenePosition test3(GeneType::DOUBLE, 11, 12);
    GenePosition test4(GeneType::DOUBLE, 10, 13);
    GenePosition test5(GeneType::DOUBLE, 10, 12);

    EXPECT_FALSE(test1 == test2);
    EXPECT_FALSE(test1 == test3);
    EXPECT_FALSE(test1 == test4);
    EXPECT_TRUE(test1 == test5);
}

TEST(GenePositionTest, OperatorNE)
{
    GenePosition test1(GeneType::DOUBLE, 10, 12);
    GenePosition test2(GeneType::RACE, 10, 12);
    GenePosition test3(GeneType::DOUBLE, 11, 12);
    GenePosition test4(GeneType::DOUBLE, 10, 13);
    GenePosition test5(GeneType::DOUBLE, 10, 12);

    EXPECT_TRUE(test1 != test2);
    EXPECT_TRUE(test1 != test3);
    EXPECT_TRUE(test1 != test4);
    EXPECT_FALSE(test1 != test5);
}