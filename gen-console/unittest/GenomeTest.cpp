#include "pch.h"
#include "..\Genome.h"
#include "..\Genes.h"
#include "..\GenePositions.h"
#include "..\GrayCode.h"
#include "..\Races.h"
#include "..\Race.h"

// Races use 2 bits
constexpr __int64 GeneTest_Race_Max = (1L << static_cast<__int64>(GenePositions::Race().Size())) - 1L;

// Sex uses 8 bits
constexpr __int64 GeneTest_Male_Fertile = 0L;         // all bits disabled
constexpr __int64 GeneTest_Male_Infertile = ((1L << static_cast<__int64>(GenePositions::Sex().Size())) / 2L) - 1L;
constexpr __int64 GeneTest_Female_Fertile = (1L << static_cast<__int64>(GenePositions::Sex().Size())) - 1L;     // all bits enabled
constexpr __int64 GeneTest_Female_Infertile = ((1L << static_cast<__int64>(GenePositions::Sex().Size())) / 2L) + 1L;

TEST(GenomeTest, GetRace)
{
    Genome test;
    Genes genes;

    std::size_t numberOfRaces = Races::GetRaces()->NumberOfRaces();
    for (__int64 count = 0; count < GeneTest_Race_Max; ++count)
    {
        genes.SetGenes(GenePositions::Race(), count);
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
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(GenePositions::Sex(), GeneTest_Male_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());

    genes.SetGenes(GenePositions::Sex(), GeneTest_Female_Fertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_TRUE(test.GetSex().IsFertile());

    genes.SetGenes(GenePositions::Sex(), GeneTest_Female_Infertile);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
    EXPECT_FALSE(test.GetSex().IsFertile());
}

TEST(GenomeTest, GetHeight_Male_Min)
{
    Genome test;
    Genes genes;
    genes.SetGenes(GenePositions::Race(), 2L);
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male_Fertile);
    genes.SetGenes(GenePositions::Height(), 0L);

    test.ReplaceGenes(genes);
    std::wcout << "Race: " << test.GetRace()->Name() << std::endl;

    EXPECT_EQ(test.GetHeight(TimeSpan(0L, 0L, 0L, 0L, 0L, false)), 28L);
    EXPECT_EQ(test.GetHeight(TimeSpan(3L, 0L, 0L, 0L, 0L, false)), 55L);
    EXPECT_EQ(test.GetHeight(TimeSpan(6L, 0L, 0L, 0L, 0L, false)), 88L);
    EXPECT_EQ(test.GetHeight(TimeSpan(11L, 0L, 0L, 0L, 0L, false)), 105L);
    EXPECT_EQ(test.GetHeight(TimeSpan(18L, 0L, 0L, 0L, 0L, false)), 140L);
    EXPECT_EQ(test.GetHeight(TimeSpan(30L, 0L, 0L, 0L, 0L, false)), 140L);
    EXPECT_EQ(test.GetHeight(TimeSpan(45L, 0L, 0L, 0L, 0L, false)), 135L);
    EXPECT_EQ(test.GetHeight(TimeSpan(60L, 0L, 0L, 0L, 0L, false)), 130L);
}