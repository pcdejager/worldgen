#include "pch.h"
#include "..\PopulationPregnantFilter.h"

#include "..\Genes.h"
#include "..\Individual.h"
#include "TestUtils.h"

TEST(PopulationPregnantFilterTest, Constructor)
{
    PopulationPregnantFilter test1(false);
    PopulationPregnantFilter test2(true);

    EXPECT_FALSE(test1.Pregnant());
    EXPECT_TRUE(test2.Pregnant());
}

TEST(PopulationPregnantFilterTest, Allow_NotPregnant)
{
    PopulationPregnantFilter test(false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_TRUE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    individual1->Inpregnate(individual2);
    EXPECT_FALSE(test.Allow(individual1.get()));
}

TEST(PopulationPregnantFilterTest, Allow_Pregnant)
{
    PopulationPregnantFilter test(true);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_FALSE(test.Allow(individual1.get()));

    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    individual1->Inpregnate(individual2);
    EXPECT_TRUE(test.Allow(individual1.get()));
}

