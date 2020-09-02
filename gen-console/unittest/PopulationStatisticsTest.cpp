#include "pch.h"
#include "..\PopulationStatistics.h"
#include "..\Genes.h"
#include "..\Parents.h"
#include "..\Individual.h"
#include "TestUtils.h"

TEST(PopulationstatisticsTest, Visit)
{
    PopulationStatistics stats;

    Genes genes1;
    TestUtils::SetGenes_FemaleFertile(genes1);
    IndividualPtr test1 = std::make_shared<Individual>(Parents::CreateNoParents(), genes1);

    Genes genes2;
    TestUtils::SetGenes_MaleFertile(genes2);
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes2);

    stats.Reset();
    EXPECT_EQ(stats.Total(), 0ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 0ULL);
    stats.VisitIndividual(test1);
    EXPECT_EQ(stats.Total(), 1ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 1ULL);
    stats.VisitIndividual(test1);
    EXPECT_EQ(stats.Total(), 2ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
    stats.VisitIndividual(test2);
    EXPECT_EQ(stats.Total(), 3ULL);
    EXPECT_EQ(stats.Males(), 1ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
}