#include "pch.h"
#include "..\Genome.h"
#include "..\Genes.h"
#include "..\GenePositions.h"
#include "..\GrayCode.h"
#include "..\Races.h"
#include "..\Race.h"

// Races use 2 bits
constexpr __int64 GeneTest_Race_Max = (1L << RaceGenesSize) - 1L;

// Sex uses 8 bits
constexpr __int64 GeneTest_Male_Fertile = 0L;         // all bits disabled
constexpr __int64 GeneTest_Male_Infertile = ((1L << SexGenesSize) / 2L) - 1L;
constexpr __int64 GeneTest_Female_Fertile = (1L << SexGenesSize) - 1L;     // all bits enabled
constexpr __int64 GeneTest_Female_Infertile = ((1L << SexGenesSize) / 2L) + 1L;

TEST(GenomeTest, GetRace)
{
    Genome test;
    Genes genes;

    std::size_t numberOfRaces = Races::GetRaces()->NumberOfRaces();
    for (__int64 count = 0; count < GeneTest_Race_Max; ++count)
    {
        genes.SetGenes(RaceGenesStart, RaceGenesSize, count);
        test.ReplaceGenes(genes);

        auto race = test.GetRace();
        ASSERT_TRUE(race != nullptr);

        std::size_t index = count % Genome::genomeRaces.size();
        EXPECT_EQ(race->Name(), Genome::genomeRaces[index]);
    }
}

TEST(GenomeTest, GetSex)
{
    Genome test;
    Genes genes;
    genes.SetGenes(SexGenesStart, SexGenesSize, GeneTest_Male_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesSize, GeneTest_Male_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesSize, GeneTest_Female_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(SexGenesStart, SexGenesSize, GeneTest_Female_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());
}