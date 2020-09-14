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

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, false);
    EXPECT_FALSE(test.Allow(individual1.get()));
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_TRUE(test.Allow(individual2.get()));
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", false, false);
    EXPECT_FALSE(test.Allow(individual3.get()));
    IndividualPtr individual4 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_TRUE(test.Allow(individual4.get()));
}

TEST(PopulationFertileFilterTest, Allow_Infertile)
{
    PopulationFertileFilter test(false);

    IndividualPtr individual1 = TestUtils::CreateIndividual(L"Human", true, false);
    EXPECT_TRUE(test.Allow(individual1.get()));
    IndividualPtr individual2 = TestUtils::CreateIndividual(L"Human", true, true);
    EXPECT_FALSE(test.Allow(individual2.get()));
    IndividualPtr individual3 = TestUtils::CreateIndividual(L"Human", false, false);
    EXPECT_TRUE(test.Allow(individual3.get()));
    IndividualPtr individual4 = TestUtils::CreateIndividual(L"Human", false, true);
    EXPECT_FALSE(test.Allow(individual4.get()));
}