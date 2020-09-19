#include "pch.h"
#include "..\PopulationFilterFactory.h"
#include "..\PopulationCompositeFilter.h"
#include "..\PopulationSexFilter.h"
#include "..\PopulationMarryFilter.h"
#include "..\PopulationAgeCategoryFilter.h"
#include "..\AgeCategory.h"

TEST(PopulationFilterFactoryTest, MaleMarry)
{
    IPopulationFilterPtr filter = PopulationFilterFactory::MaleMarry();
    ASSERT_NE(filter, nullptr);

    PopulationCompositeFilter* composite = dynamic_cast<PopulationCompositeFilter*>(filter.get());
    ASSERT_NE(composite, nullptr);

    std::vector<IPopulationFilterPtr>& internalFilters = composite->Filters();
    ASSERT_EQ(internalFilters.size(), 3);

    PopulationSexFilter* sex = dynamic_cast<PopulationSexFilter*>(internalFilters[0].get());
    ASSERT_NE(sex, nullptr);
    EXPECT_TRUE(sex->Males());
    EXPECT_FALSE(sex->Females());

    PopulationMarryFilter* marry = dynamic_cast<PopulationMarryFilter*>(internalFilters[1].get());
    ASSERT_NE(marry, nullptr);
    EXPECT_FALSE(marry->Married());

    PopulationAgeCategoryFilter* age = dynamic_cast<PopulationAgeCategoryFilter*>(internalFilters[2].get());
    ASSERT_NE(age, nullptr);
    std::set<AgeCategory>& categories = age->AgeCategories();

    std::vector<AgeCategory> categoryReference = AgeCategoryUtils::MarryCategories();
    ASSERT_EQ(categories.size(), categoryReference.size());
    for (AgeCategory entry : categoryReference)
    {
        EXPECT_TRUE(categories.find(entry) != categories.end());
    }
}

TEST(PopulationFilterFactoryTest, FemaleMarry)
{
    IPopulationFilterPtr filter = PopulationFilterFactory::FemaleMarry();
    ASSERT_NE(filter, nullptr);

    PopulationCompositeFilter* composite = dynamic_cast<PopulationCompositeFilter*>(filter.get());
    ASSERT_NE(composite, nullptr);

    std::vector<IPopulationFilterPtr>& internalFilters = composite->Filters();
    ASSERT_EQ(internalFilters.size(), 3);

    PopulationSexFilter* sex = dynamic_cast<PopulationSexFilter*>(internalFilters[0].get());
    ASSERT_NE(sex, nullptr);
    EXPECT_FALSE(sex->Males());
    EXPECT_TRUE(sex->Females());

    PopulationMarryFilter* marry = dynamic_cast<PopulationMarryFilter*>(internalFilters[1].get());
    ASSERT_NE(marry, nullptr);
    EXPECT_FALSE(marry->Married());

    PopulationAgeCategoryFilter* age = dynamic_cast<PopulationAgeCategoryFilter*>(internalFilters[2].get());
    ASSERT_NE(age, nullptr);
    std::set<AgeCategory>& categories = age->AgeCategories();

    std::vector<AgeCategory> categoryReference = AgeCategoryUtils::MarryCategories();
    ASSERT_EQ(categories.size(), categoryReference.size());
    for (AgeCategory entry : categoryReference)
    {
        EXPECT_TRUE(categories.find(entry) != categories.end());
    }
}