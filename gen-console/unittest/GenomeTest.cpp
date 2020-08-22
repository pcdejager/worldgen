#include "pch.h"
#include "..\Genome.h"
#include "..\Genes.h"
#include "..\GenePositions.h"
#include "..\GrayCode.h"

// Sex uses 8 bits
constexpr __int64 GeneTest_Male_Fertile = 0L;         // all bits disabled
constexpr __int64 GeneTest_Male_Infertile = 126L;     
constexpr __int64 GeneTest_Female_Fertile = 255l;     // all bits enabled
constexpr __int64 GeneTest_Female_Infertile =128L;    

TEST(GenomeTest, GetSex)
{
    Genome test;
    Genes genes;
    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Male_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Male_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Female_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesEnd, GeneTest_Female_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());
}