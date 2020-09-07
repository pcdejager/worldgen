#include "pch.h"
#include "..\Procreate.h"

TEST(ProcreateTest, Constructor)
{
    Procreate test;
    EXPECT_EQ(test.Test_Matrix().size(), 0);
}

TEST(ProcreateTest, Add)
{
    Procreate test;
    std::vector<__int64> raceIDs = { 3LL, 4LL };
    std::vector<double> chance = { 0.5, 1.0 };
    test.Add(1LL, 2LL, raceIDs, chance);
    ASSERT_EQ(test.Test_Matrix().size(), 1);
    EXPECT_EQ(test.Test_Matrix().begin()->first.first, 1LL);
    EXPECT_EQ(test.Test_Matrix().begin()->first.second, 2LL);
    auto& testID = test.Test_Matrix().begin()->second.first;
    ASSERT_EQ(testID.size(), 2u);
    EXPECT_EQ(testID[0], 3LL);
    EXPECT_EQ(testID[1], 4LL);
    auto& testChance = test.Test_Matrix().begin()->second.second;
    ASSERT_EQ(testChance.size(), 2u);
    EXPECT_EQ(testChance[0], 0.5);
    EXPECT_EQ(testChance[1], 1.0);
}