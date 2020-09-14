#include "pch.h"
#include "..\PopulationStatistics.h"
#include "..\Genes.h"
#include "..\Parents.h"
#include "..\Individual.h"
#include "..\Races.h"
#include "..\Race.h"
#include "TestUtils.h"

TEST(PopulationstatisticsTest, Visit)
{
    PopulationStatistics stats;

    auto human = Races::GetRaces()->FindRaceByName(L"Human");
    auto elf = Races::GetRaces()->FindRaceByName(L"Elf");

    Genes genes1;
    TestUtils::SetGenes_Race(genes1, human);
    TestUtils::SetGenes_FemaleFertile(genes1);
    IndividualPtr test1 = std::make_shared<Individual>(Parents::CreateNoParents(), genes1);

    Genes genes2;
    TestUtils::SetGenes_Race(genes2, elf);
    TestUtils::SetGenes_MaleFertile(genes2);
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes2);

    stats.Reset();
    EXPECT_EQ(stats.Total(), 0ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 0ULL);
    EXPECT_EQ(stats.MalesOfRace(human->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->ID()), 0ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->ID()), 0ULL);
    stats.VisitIndividual(test1.get());
    EXPECT_EQ(stats.Total(), 1ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 1ULL);
    EXPECT_EQ(stats.MalesOfRace(human->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->ID()), 1ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->ID()), 0ULL);
    stats.VisitIndividual(test1.get());
    EXPECT_EQ(stats.Total(), 2ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(human->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->ID()), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->ID()), 0ULL);
    stats.VisitIndividual(test2.get());
    EXPECT_EQ(stats.Total(), 3ULL);
    EXPECT_EQ(stats.Males(), 1ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(human->ID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->ID()), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->ID()), 1ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->ID()), 0ULL);
}