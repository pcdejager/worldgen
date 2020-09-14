#include "pch.h"
#include "..\PopulationSexFilter.h"
#include "..\Genes.h"
#include "..\Individual.h"
#include "..\Parents.h"
#include "..\Races.h"
#include "TestUtils.h"

TEST(PopulationSexFilterTest, Constructor)
{
    PopulationSexFilter test1(false, false);
    PopulationSexFilter test2(false, true);
    PopulationSexFilter test3(true, false);
    PopulationSexFilter test4(true, true);

    EXPECT_FALSE(test1.Males());
    EXPECT_FALSE(test1.Females());
    EXPECT_FALSE(test2.Males());
    EXPECT_TRUE(test2.Females());
    EXPECT_TRUE(test3.Males());
    EXPECT_FALSE(test3.Females());
    EXPECT_TRUE(test4.Males());
    EXPECT_TRUE(test4.Females());
}

TEST(PopulationSexFilterTest, Allow_None)
{
    PopulationSexFilter test(false, false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_FALSE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_FALSE(test.Allow(individual2.get()));
}

TEST(PopulationSexFilterTest, Allow_Males)
{
    PopulationSexFilter test(true, false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_TRUE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_FALSE(test.Allow(individual2.get()));
}

TEST(PopulationSexFilterTest, Allow_Females)
{
    PopulationSexFilter test(false, true);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_FALSE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_TRUE(test.Allow(individual2.get()));
}

TEST(PopulationSexFilterTest, Allow_MalesAndFemales)
{
    PopulationSexFilter test(true, true);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_TRUE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_TRUE(test.Allow(individual2.get()));
}