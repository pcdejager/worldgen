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
    EXPECT_EQ(test.Born(), WorldProperties::Properties()->Now());
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

TEST(IndividualTest, Parents)
{
    Genes genes;
    Individual test(Parents::CreateNoParents(), genes);
    auto parents = test.Parents();
    EXPECT_FALSE(parents->BiologicalFather()->IsValid());
    EXPECT_FALSE(parents->BiologicalMother()->IsValid());
}

TEST(IndividualTest, Name)
{
    auto test1 = Individual::GetNullIndividual();
    ASSERT_TRUE(test1 != nullptr);
    EXPECT_FALSE(test1->Name().IsValid());

    Genes genes;
    Individual test2(Parents::CreateNoParents(), genes);
    EXPECT_TRUE(test2.Name().IsValid());
}

TEST(IndividualTest, Born)
{
    Genes genes;
    Individual test1(Parents::CreateNoParents(), genes);
    WorldTime date1 = WorldProperties::Properties()->Now();
    EXPECT_EQ(test1.Born(), date1);
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1234567UL));
    Individual test2(Parents::CreateNoParents(), genes);
    WorldTime date2 = WorldProperties::Properties()->Now();
    EXPECT_EQ(test2.Born(), date2);
    EXPECT_TRUE(test1.Born() < test2.Born());
}

TEST(IndividualTest, Died)
{
    Genes genes;
    Individual test1(Parents::CreateNoParents(), genes);
    EXPECT_EQ(WorldTime::Undefined(), test1.Died());

    Population pop;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);

    WorldProperties::Properties()->AdvanceTime(TimeSpan(123456UL));
    pop.Died(test2, WorldProperties::Properties()->Now());

    EXPECT_EQ(test2->Died(), WorldProperties::Properties()->Now());
}

TEST(IndividualTest, Age_bornInTheFuture)
{
    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1234LL));
    Genes genes;
    Individual test(Parents::CreateNoParents(), genes);

    WorldProperties::Properties()->ResetTime();

    EXPECT_EQ(test.Age(), TimeSpan());
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, Age_alive)
{
    Genes genes;
    WorldProperties::Properties()->ResetTime();
    Individual test(Parents::CreateNoParents(), genes);

    WorldTime start = WorldProperties::Properties()->Now();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(12345LL));
    WorldTime end1 = WorldProperties::Properties()->Now();

    EXPECT_EQ(test.Age(), end1 - start);
    EXPECT_TRUE(test.IsValid());

    WorldProperties::Properties()->AdvanceTime(TimeSpan(12345LL));
    WorldTime end2 = WorldProperties::Properties()->Now();

    EXPECT_EQ(test.Age(), end2 - start);
    EXPECT_NE(test.Age(), end1 - start);
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, Age_dead)
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

    EXPECT_EQ(test->Age(), died - start);
    EXPECT_NE(test->Age(), end - start);
    EXPECT_TRUE(test->IsValid());
}

TEST(IndividualTest, MaximumAge)
{
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");
    TimeSpan min = race->Traits().ageRanges->AgeStart(AgeCategory::Elder);
    TimeSpan max = race->Traits().ageRanges->AgeStart(AgeCategory::Dead);

    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 1.0);

    EXPECT_EQ(test1->MaximumAge(), min);
    EXPECT_EQ(test2->MaximumAge(), max);
}

TEST(IndividualTest, AgeCategory)
{
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");

    IndividualPtr test = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->AgeCategory(), AgeCategory::NewBorn);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->Traits().ageRanges->AgeStart(AgeCategory::Toddler));
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->AgeCategory(), AgeCategory::Toddler);

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->Traits().ageRanges->AgeStart(AgeCategory::Child));
    WorldProperties::Properties()->AdvanceTime(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(test->AgeCategory(), AgeCategory::Child);
}

TEST(IndividualTest, Race)
{
    RacePtr race1 = Races::GetRaces()->FindRaceByName(L"Human");
    RacePtr race2 = Races::GetRaces()->FindRaceByName(L"Elf");

    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", true, 0.0, 1.0, 0.0);

    EXPECT_EQ(test1->Race(), race1);
    EXPECT_EQ(test2->Race(), race2);
}

TEST(IndividualTest, Sex)
{
    IndividualPtr test1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr test2 = TestUtils::CreateIndividual(L"Elf", false, 0.0, 1.0, 0.0);

    EXPECT_TRUE(test1->Sex().IsMale());
    EXPECT_TRUE(test2->Sex().IsFemale());
}