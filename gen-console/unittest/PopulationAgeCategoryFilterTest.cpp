#include "pch.h"
#include "..\PopulationAgeCategoryFilter.h"
#include "..\AgeCategory.h"
#include "..\Individual.h"
#include "..\Races.h"
#include "..\Race.h"
#include "..\AgeTraits.h"
#include "..\WorldProperties.h"
#include "TestUtils.h"

TEST(PopulationAgeCategoryFilterTest, Constructor)
{
    PopulationAgeCategoryFilter test;
    ASSERT_EQ(test.AgeCategories().size(), 0);
}

TEST(PopulationAgeCategoryFilterTest, Allow)
{
    WorldProperties::Properties()->ResetTime();

    IndividualPtr individual = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    RacePtr race = Races::GetRaces()->FindRaceByName(L"Human");
    __int64 year = TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL).Ticks();

    PopulationAgeCategoryFilter test;
    test.AddCategory(AgeCategory::Child);
    test.AddCategory(AgeCategory::Adult);

    EXPECT_FALSE(test.Allow(individual.get()));

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::Toddler) + year);

    EXPECT_FALSE(test.Allow(individual.get()));

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::Child) + year);

    EXPECT_TRUE(test.Allow(individual.get()));

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::YoungAdult) + year);

    EXPECT_FALSE(test.Allow(individual.get()));

    WorldProperties::Properties()->ResetTime();
    WorldProperties::Properties()->AdvanceTime(race->GetTraits().ageRanges->AgeStart(AgeCategory::Adult) + year);

    EXPECT_TRUE(test.Allow(individual.get()));
}

TEST(PopulationAgeCategoryFilterTest, AddCategory)
{
    PopulationAgeCategoryFilter test;

    ASSERT_EQ(test.AgeCategories().size(), 0);

    test.AddCategory(AgeCategory::Teenager);
    EXPECT_EQ(test.AgeCategories().size(), 1);
    EXPECT_TRUE(test.AgeCategories().find(AgeCategory::Teenager) != test.AgeCategories().end());
}