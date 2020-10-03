#include "pch.h"
#include "..\GenePositions.h"

TEST(GenePositionsTest, AllGenes)
{
    auto test = GenePositions::AllGenes();
    ASSERT_EQ(test.size(), 7);
    EXPECT_EQ(test[0], GenePositions::Race());
    EXPECT_EQ(test[1], GenePositions::Sex());
    EXPECT_EQ(test[2], GenePositions::Period());
    EXPECT_EQ(test[3], GenePositions::Fertility());
    EXPECT_EQ(test[4], GenePositions::Height());
    EXPECT_EQ(test[5], GenePositions::Weight());
    EXPECT_EQ(test[6], GenePositions::MaximumLife());
}