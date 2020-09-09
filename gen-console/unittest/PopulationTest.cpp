#include "pch.h"
#include "..\Population.h"
#include "..\Individual.h"
#include "..\Parents.h"

TEST(PopulationTest, Constructor)
{
    Population pop;
    ASSERT_EQ(pop.Size(), 0);
}

TEST(PopulationTest, Size)
{
    Population pop;
    EXPECT_EQ(pop.Size(), 0);
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    EXPECT_EQ(pop.Size(), 1);
    Genes genes;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);
    EXPECT_EQ(pop.Size(), 2);

    pop.Died(test1, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 1);

    pop.Died(test2, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 0);
}

TEST(PopulationTest, Add)
{
    Population pop;
    EXPECT_EQ(pop.Size(), 0);
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    EXPECT_EQ(pop.Size(), 1);
    Genes genes;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);
    EXPECT_EQ(pop.Size(), 2);
}

TEST(PopulationTest, DeadSize)
{
    Population pop;
    EXPECT_EQ(pop.DeadSize(), 0);
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    EXPECT_EQ(pop.DeadSize(), 0);
    Genes genes;
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);
    EXPECT_EQ(pop.DeadSize(), 0);

    pop.Died(test1, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.DeadSize(), 1);

    pop.Died(test2, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.DeadSize(), 2);
}

TEST(PopulationTest, Died)
{
    Genes genes;
    Population pop;
    EXPECT_EQ(pop.Size(), 0);
    EXPECT_EQ(pop.DeadSize(), 0);
    IndividualPtr test1 = Individual::GetNullIndividual();
    pop.Add(test1);
    IndividualPtr test2 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);
    pop.Add(test2);
    IndividualPtr test3 = std::make_shared<Individual>(Parents::CreateNoParents(), genes);

    EXPECT_EQ(pop.Size(), 2);
    EXPECT_EQ(pop.DeadSize(), 0);

    pop.Died(test1, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 1);
    EXPECT_EQ(pop.DeadSize(), 1);

    pop.Died(test3, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 1);
    EXPECT_EQ(pop.DeadSize(), 1);

    pop.Died(test2, WorldTime(1LL, 0LL, 0LL, 0LL, 0LL));
    EXPECT_EQ(pop.Size(), 0);
    EXPECT_EQ(pop.DeadSize(), 2);
}
