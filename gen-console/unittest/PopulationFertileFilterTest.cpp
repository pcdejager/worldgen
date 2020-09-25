#include "pch.h"
#include "..\PopulationFertileFilter.h"
#include "TestUtils.h"

TEST(PopulationFertileFilterTest, Constructor)
{
    PopulationFertileFilter test1(false);
    PopulationFertileFilter test2(true);

    EXPECT_FALSE(test1.Fertile());
    EXPECT_TRUE(test2.Fertile());
}

TEST(PopulationFertileFilterTest, Allow_Fertile)
{
    PopulationFertileFilter test(true);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 0.0, 0.0);
    EXPECT_FALSE(test.Allow(individual1.get()));
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_TRUE(test.Allow(individual2.get()));
}

TEST(PopulationFertileFilterTest, Allow_Infertile)
{
    PopulationFertileFilter test(false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, 0.0, 0.0, 0.0);
    EXPECT_TRUE(test.Allow(individual1.get()));
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    EXPECT_FALSE(test.Allow(individual2.get()));
}