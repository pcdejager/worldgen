#include "pch.h"
#include "..\GenePositions.h"

TEST(GenePositionsTest, AllGenes)
{
    auto test = GenePositions::AllGenes();
    ASSERT_EQ(test.size(), 7);
    EXPECT_EQ(test.find(GeneType::Race)->second, GenePositions::GetPosition(GeneType::Race));
    EXPECT_EQ(test.find(GeneType::Sex)->second, GenePositions::GetPosition(GeneType::Sex));
    EXPECT_EQ(test.find(GeneType::Period)->second, GenePositions::GetPosition(GeneType::Period));
    EXPECT_EQ(test.find(GeneType::Fertility)->second, GenePositions::GetPosition(GeneType::Fertility));
    EXPECT_EQ(test.find(GeneType::Height)->second, GenePositions::GetPosition(GeneType::Height));
    EXPECT_EQ(test.find(GeneType::Weight)->second, GenePositions::GetPosition(GeneType::Weight));
    EXPECT_EQ(test.find(GeneType::MaximumLife)->second, GenePositions::GetPosition(GeneType::MaximumLife));
}