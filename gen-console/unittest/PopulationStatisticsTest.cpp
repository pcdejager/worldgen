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

    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", true, 0.0, 1.0, 0.0);

    stats.Reset();
    EXPECT_EQ(stats.Total(), 0ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 0ULL);
    EXPECT_EQ(stats.MalesOfRace(human->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->GetID()), 0ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->GetID()), 0ULL);
    stats.VisitIndividual(test1.get());
    EXPECT_EQ(stats.Total(), 1ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 1ULL);
    EXPECT_EQ(stats.MalesOfRace(human->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->GetID()), 1ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->GetID()), 0ULL);
    stats.VisitIndividual(test1.get());
    EXPECT_EQ(stats.Total(), 2ULL);
    EXPECT_EQ(stats.Males(), 0ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(human->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->GetID()), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->GetID()), 0ULL);
    stats.VisitIndividual(test2.get());
    EXPECT_EQ(stats.Total(), 3ULL);
    EXPECT_EQ(stats.Males(), 1ULL);
    EXPECT_EQ(stats.Females(), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(human->GetID()), 0ULL);
    EXPECT_EQ(stats.FemalesOfRace(human->GetID()), 2ULL);
    EXPECT_EQ(stats.MalesOfRace(elf->GetID()), 1ULL);
    EXPECT_EQ(stats.FemalesOfRace(elf->GetID()), 0ULL);
}