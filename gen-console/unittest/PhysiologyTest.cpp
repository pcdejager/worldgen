#include "pch.h"
#include "..\Physiology.h"
#include "..\Individual.h"
#include "..\Races.h"
#include "..\Race.h"
#include "TestUtils.h"

TEST(PhysiologyTest, Constructor)
{
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, 0.0, 0.0, 0.0);

    Physiology test1(individual1.get());
    EXPECT_EQ(test1.Race(), race);
    EXPECT_TRUE(test1.PeriodCycle().IsZero());
    EXPECT_EQ(test1.Fertility(), 1.0);

    Physiology test2(individual2.get());
    EXPECT_EQ(test2.Race(), race);
    EXPECT_EQ(test2.PeriodCycle(), TimeSpan(25LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test2.Fertility(), 0.0);
}