#include "pch.h"
#include "..\Individual.h"
#include "..\Parents.h"
#include "..\Population.h"

TEST(IndividualTest, Constructor)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    EXPECT_EQ(WorldTime(123UL), test.Born());
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

    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), WorldTime(123UL));
    EXPECT_TRUE(test2->IsValid());
}

TEST(IndividualTest, IsAlive)
{
    Population pop;
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), WorldTime(123UL));
    pop.Add(test2);

    EXPECT_EQ(pop.Size(), 2);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_TRUE(test2->IsAlive());

    pop.Died(test1, WorldTime(234UL));
    EXPECT_EQ(pop.Size(), 1);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_TRUE(test2->IsAlive());

    pop.Died(test2, WorldTime(234UL));
    EXPECT_EQ(pop.Size(), 0);
    EXPECT_FALSE(test1->IsAlive());
    EXPECT_FALSE(test2->IsAlive());
}

TEST(IndividualTest, Parents)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    auto parents = test.Parents();
    EXPECT_FALSE(parents->BiologicalFather()->IsValid());
    EXPECT_FALSE(parents->BiologicalMother()->IsValid());
}
TEST(IndividualTest, Age)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(123UL)));
    EXPECT_EQ(TimeSpan(123L), test.Age(WorldTime(246UL)));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(0UL)));
    EXPECT_TRUE(test.IsValid());
}

