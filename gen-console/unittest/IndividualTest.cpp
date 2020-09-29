#include "pch.h"
#include "..\Individual.h"
#include "..\Parents.h"
#include "..\Population.h"
#include "..\WorldTime.h"
#include "..\WorldProperties.h"
#include "..\Race.h"
#include "..\Races.h"
#include "..\AgeTraits.h"
#include "TestUtils.h"

TEST(IndividualTest, Constructor)
{
    Genes emptyGenes;
    Individual test(Parents::CreateNoParents(), emptyGenes);
    EXPECT_EQ(test.GetBorn(), WorldProperties::Properties()->Now());
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, GetNullIndividual)
{
    auto test = Individual::GetNullIndividual();
    ASSERT_TRUE(test != nullptr);
    EXPECT_FALSE(test->IsValid());

    auto test2 = Individual::GetNullIndividual();
    ASSERT_TRUE(test == test2);
}

TEST(IndividualTest, IsValid)
{
    auto test1 = Individual::GetNullIndividual();
    ASSERT_TRUE(test1 != nullptr);
    EXPECT_FALSE(test1->IsValid());

    Genes genes;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    EXPECT_TRUE(test2->IsValid());
}

TEST(IndividualTest, IsAlive)
{
    Genes genes;
    Population pop;
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);

    EXPECT_EQ(pop.Size(), 2);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_TRUE(test2->IsAlive());

    pop.Died(test1, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 1);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_TRUE(test2->IsAlive());

    pop.Died(test2, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 0);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_FALSE(test2->IsAlive());
}

TEST(IndividualTest, GetParents)
{
    Genes genes;
    Individual test(Parents::CreateNoParents(), genes);
    auto parents = test.GetParents();
    EXPECT_FALSE(parents->BiologicalFather()->IsValid());
    EXPECT_FALSE(parents->BiologicalMother()->IsValid());
}

TEST(IndividualTest, GetName)
{
    auto test1 = Individual::GetNullIndividual();
    ASSERT_TRUE(test1 != nullptr);
    EXPECT_FALSE(test1->GetName().IsValid());

    Genes genes;
    Individual test2(Parents::CreateNoParents(), genes);
    EXPECT_TRUE(test2.GetName().IsValid());
}

TEST(IndividualTest, GetBorn)
{
    Genes genes;
    Individual test1(Parents::CreateNoParents(), genes);
    WorldTime date1 = WorldProperties::Properties()->Now();
    EXPECT_EQ(test1.GetBorn(), date1);
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1234567UL));
    Individual test2(Parents::CreateNoParents(), genes);
    WorldTime date2 = WorldProperties::Properties()->Now();
    EXPECT_EQ(test2.GetBorn(), date2);
    EXPECT_TRUE(test1.GetBorn() < test2.GetBorn());
}

TEST(IndividualTest, GetDied)
{
    Genes genes;
    Individual test1(Parents::CreateNoParents(), genes);
    EXPECT_EQ(WorldTime::Undefined(), test1.GetDied());

    Population pop;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);

    WorldProperties::Properties()->AdvanceTime(TimeSpan(123456UL));
    pop.Died(test2, WorldProperties::Properties()->Now());

    EXPECT_EQ(test2->GetDied(), WorldProperties::Properties()->Now());
}

TEST(IndividualTest, GetAge_bornInTheFuture)
{
    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1234LL));
    Genes genes;
    Individual test(Parents::CreateNoParents(), genes);

    WorldProperties::Properties()->ResetTime();

    EXPECT_EQ(test.GetAge(), TimeSpan());
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, GetAge_alive)
{
    Genes genes;
    WorldProperties::Properties()->ResetTime();
    Individual test(Parents::CreateNoParents(), genes);

    WorldTime start = WorldProperties::Properties()->Now();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(12345LL));
    WorldTime end1 = WorldProperties::Properties()->Now();

    EXPECT_EQ(test.GetAge(), end1 - start);
    EXPECT_TRUE(test.IsValid());

    WorldProperties::Properties()->AdvanceTime(TimeSpan(12345LL));
    WorldTime end2 = WorldProperties::Properties()->Now();

    EXPECT_EQ(test.GetAge(), end2 - start);
    EXPECT_NE(test.GetAge(), end1 - start);
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, GetAge_dead)
{
    Genes genes;
    Population pop;
    IndividualPtr test = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test);

    WorldTime start = WorldProperties::Properties()->Now();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(12345LL));
    WorldTime died = WorldProperties::Properties()->Now();

    pop.Died(test, died);

    WorldProperties::Properties()->AdvanceTime(TimeSpan(67890LL));
    WorldTime end = WorldProperties::Properties()->Now();

    EXPECT_EQ(test->GetAge(), died - start);
    EXPECT_NE(test->GetAge(), end - start);
    EXPECT_TRUE(test->IsValid());
}

TEST(IndividualTest, GetMaximumAge)
{
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");
    TimeSpan min = race->GetTraits().ageRanges->AgeStart(AgeCategory::Elder);
    TimeSpan max = race->GetTraits().ageRanges->AgeStart(AgeCategory::Dead);

    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 1.0);

    EXPECT_EQ(test1->GetMaximumAge(), min);
    EXPECT_EQ(test2->GetMaximumAge(), max);
}

TEST(IndividualTest, GetAgeCategory)
{
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");

    IndividualPtr test = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->GetAgeCategory(), AgeCategory::NewBorn);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::Toddler));
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->GetAgeCategory(), AgeCategory::Toddler);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::Child));
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->GetAgeCategory(), AgeCategory::Child);
}

TEST(IndividualTest, GetRace)
{
    RacePtr race1 = Races::GetRaces()->FindRaceByName(L"Human");
    RacePtr race2 = Races::GetRaces()->FindRaceByName(L"Elf");

    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", true, 0.0, 1.0, 0.0);

    EXPECT_EQ(test1->GetRace(), race1);
    EXPECT_EQ(test2->GetRace(), race2);
}

TEST(IndividualTest, GetSex)
{
    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", false, 0.0, 1.0, 0.0);

    EXPECT_TRUE(test1->GetSex().IsMale());
    EXPECT_TRUE(test2->GetSex().IsFemale());
}

TEST(IndividualTest, GetPhysiology)
{
    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", false, 0.0, 0.0, 0.0);

    EXPECT_EQ(test1->GetPhysiology().Fertility(), 1.0);
    EXPECT_EQ(test2->GetPhysiology().Fertility(), 0.0);
}