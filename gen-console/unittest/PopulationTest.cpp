#include "pch.h"
#include "..\Population.h"
#include "..\Individual.h"
#include "..\Parents.h"
#include "..\PopulationSexFilter.h"
#include "..\IPopulationVisitor.h"
#include "TestUtils.h"

class PopulationTestVisitor : public IPopulationVisitor
{
public:
    PopulationTestVisitor()
    {
        ;
    }
    virtual ~PopulationTestVisitor()
    {
        ;
    }

    // IPopulationVisitor
public:
    virtual void VisitIndividual(Individual* individual)
    {
        visited.push_back(individual);
    }

public:
    std::vector<Individual*> visited;
};

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

TEST(PopulationTest, Visit)
{
    Population pop;
    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", true, true);
    pop.Add(individual1);
    pop.Add(individual2);
    pop.Add(individual3);

    PopulationTestVisitor test;
    test.visited.clear();
    pop.Visit(&test);

    ASSERT_EQ(test.visited.size(), 3);
    EXPECT_EQ(test.visited[0], individual1.get());
    EXPECT_EQ(test.visited[1], individual2.get());
    EXPECT_EQ(test.visited[2], individual3.get());
}

TEST(PopulationTest, Visit_Filtered)
{
    Population pop;
    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", true, true);
    pop.Add(individual1);
    pop.Add(individual2);
    pop.Add(individual3);

    IPopulationFilterPtr filterNone = IPopulationFilterPtr(new PopulationSexFilter(false, false));
    IPopulationFilterPtr filterMale = IPopulationFilterPtr(new PopulationSexFilter(true, false));
    IPopulationFilterPtr filterFemale = IPopulationFilterPtr(new PopulationSexFilter(false, true));
    IPopulationFilterPtr filterAll = IPopulationFilterPtr(new PopulationSexFilter(true, true));

    PopulationTestVisitor test1;
    test1.visited.clear();
    pop.Visit(&test1, filterNone.get());
    ASSERT_EQ(test1.visited.size(), 0);

    PopulationTestVisitor test2;
    test2.visited.clear();
    pop.Visit(&test2, filterMale.get());
    ASSERT_EQ(test2.visited.size(), 2);
    EXPECT_TRUE(std::find(test2.visited.begin(), test2.visited.end(), individual1.get()) != test2.visited.end());
    EXPECT_TRUE(std::find(test2.visited.begin(), test2.visited.end(), individual3.get()) != test2.visited.end());

    PopulationTestVisitor test3;
    test3.visited.clear();
    pop.Visit(&test3, filterFemale.get());
    ASSERT_EQ(test3.visited.size(), 1);
    EXPECT_TRUE(std::find(test3.visited.begin(), test3.visited.end(), individual2.get()) != test3.visited.end());

    PopulationTestVisitor test4;
    test4.visited.clear();
    pop.Visit(&test4, filterAll.get());
    ASSERT_EQ(test4.visited.size(), 3);
    EXPECT_TRUE(std::find(test4.visited.begin(), test4.visited.end(), individual1.get()) != test4.visited.end());
    EXPECT_TRUE(std::find(test4.visited.begin(), test4.visited.end(), individual2.get()) != test4.visited.end());
    EXPECT_TRUE(std::find(test4.visited.begin(), test4.visited.end(), individual3.get()) != test4.visited.end());
}

TEST(PopulationTest, Filter)
{
    Population pop;
    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", true, true);
    pop.Add(individual1);
    pop.Add(individual2);
    pop.Add(individual3);

    IPopulationFilterPtr filterNone = IPopulationFilterPtr(new PopulationSexFilter(false, false));
    IPopulationFilterPtr filterMale = IPopulationFilterPtr(new PopulationSexFilter(true, false));
    IPopulationFilterPtr filterFemale = IPopulationFilterPtr(new PopulationSexFilter(false, true));
    IPopulationFilterPtr filterAll = IPopulationFilterPtr(new PopulationSexFilter(true, true));

    auto test1 = pop.Filter(filterNone.get());
    ASSERT_EQ(test1.size(), 0);

    auto test2 = pop.Filter(filterMale.get());
    ASSERT_EQ(test2.size(), 2);
    EXPECT_TRUE(std::find(test2.begin(), test2.end(), individual1) != test2.end());
    EXPECT_TRUE(std::find(test2.begin(), test2.end(), individual3) != test2.end());

    auto test3 = pop.Filter(filterFemale.get());
    ASSERT_EQ(test3.size(), 1);
    EXPECT_TRUE(std::find(test3.begin(), test3.end(), individual2) != test3.end());

    auto test4 = pop.Filter(filterAll.get());
    ASSERT_EQ(test4.size(), 3);
    EXPECT_TRUE(std::find(test4.begin(), test4.end(), individual1) != test4.end());
    EXPECT_TRUE(std::find(test4.begin(), test4.end(), individual2) != test4.end());
    EXPECT_TRUE(std::find(test4.begin(), test4.end(), individual3) != test4.end());
}

TEST(PopulationTest, FilterCount)
{
    Population pop;
    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", true, true);
    pop.Add(individual1);
    pop.Add(individual2);
    pop.Add(individual3);

    IPopulationFilterPtr filterNone = IPopulationFilterPtr(new PopulationSexFilter(false, false));
    IPopulationFilterPtr filterMale = IPopulationFilterPtr(new PopulationSexFilter(true, false));
    IPopulationFilterPtr filterFemale = IPopulationFilterPtr(new PopulationSexFilter(false, true));
    IPopulationFilterPtr filterAll = IPopulationFilterPtr(new PopulationSexFilter(true, true));

    auto test1 = pop.FilterCount(filterNone.get());
    ASSERT_EQ(test1, 0);
    auto test2 = pop.FilterCount(filterMale.get());
    ASSERT_EQ(test2, 2);
    auto test3 = pop.FilterCount(filterFemale.get());
    ASSERT_EQ(test3, 1);
    auto test4 = pop.FilterCount(filterAll.get());
    ASSERT_EQ(test4, 3);
}