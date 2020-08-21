#include "pch.h"
#include "..\Genome.h"
#include "..\Genes.h"
#include "..\GenePositions.h"

// Sex uses 8 bits
constexpr __int64 GeneTest_Male = 0L;     // all bits disabled
constexpr __int64 GeneTest_Female = 255; // all bits enabled

TEST(GenomeTest, GetSex)
{
    Genome test;
    Genes genes;
    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Male);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());

    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Female);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
}