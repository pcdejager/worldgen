#include "pch.h"
#include "..\PopulationMarryFilter.h"
#include "..\Genes.h"
#include "..\Individual.h"
#include "TestUtils.h"

TEST(PopulationMarryFilterTest, Constructor)
{
    PopulationMarryFilter test1(false);
    PopulationMarryFilter test2(true);

    EXPECT_FALSE(test1.Married());
    EXPECT_TRUE(test2.Married());
}

TEST(PopulationMarryFilterTest, Allow_NotMarried)
{
    PopulationMarryFilter test(false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_TRUE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    individual2->Marry(individual1);
    EXPECT_FALSE(test.Allow(individual2.get()));
}

TEST(PopulationMarryFilterTest, Allow_Married)
{
    PopulationMarryFilter test(true);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_FALSE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    individual2->Marry(individual1);
    EXPECT_TRUE(test.Allow(individual2.get()));
}

