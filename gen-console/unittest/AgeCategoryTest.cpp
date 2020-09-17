#include "pch.h"
#include "..\AgeCategory.h"

TEST(AgeCategoryTest, CategoryBefore)
{
    EXPECT_EQ(AgeCategory::Dead, AgeCategoryUtils::CategoryBefore(AgeCategory::NewBorn));
    EXPECT_EQ(AgeCategory::NewBorn, AgeCategoryUtils::CategoryBefore(AgeCategory::Toddler));
    EXPECT_EQ(AgeCategory::Toddler, AgeCategoryUtils::CategoryBefore(AgeCategory::Child));
    EXPECT_EQ(AgeCategory::Child, AgeCategoryUtils::CategoryBefore(AgeCategory::Teenager));
    EXPECT_EQ(AgeCategory::Teenager, AgeCategoryUtils::CategoryBefore(AgeCategory::YoungAdult));
    EXPECT_EQ(AgeCategory::YoungAdult, AgeCategoryUtils::CategoryBefore(AgeCategory::Adult));
    EXPECT_EQ(AgeCategory::Adult, AgeCategoryUtils::CategoryBefore(AgeCategory::OldAdult));
    EXPECT_EQ(AgeCategory::OldAdult, AgeCategoryUtils::CategoryBefore(AgeCategory::Elder));
    EXPECT_EQ(AgeCategory::Dead, AgeCategoryUtils::CategoryBefore(AgeCategory::Dead));
}

TEST(AgeCategoryTest, CategoryAfter)
{
    EXPECT_EQ(AgeCategory::Toddler, AgeCategoryUtils::CategoryAfter(AgeCategory::NewBorn));
    EXPECT_EQ(AgeCategory::Child, AgeCategoryUtils::CategoryAfter(AgeCategory::Toddler));
    EXPECT_EQ(AgeCategory::Teenager, AgeCategoryUtils::CategoryAfter(AgeCategory::Child));
    EXPECT_EQ(AgeCategory::YoungAdult, AgeCategoryUtils::CategoryAfter(AgeCategory::Teenager));
    EXPECT_EQ(AgeCategory::Adult, AgeCategoryUtils::CategoryAfter(AgeCategory::YoungAdult));
    EXPECT_EQ(AgeCategory::OldAdult, AgeCategoryUtils::CategoryAfter(AgeCategory::Adult));
    EXPECT_EQ(AgeCategory::Elder, AgeCategoryUtils::CategoryAfter(AgeCategory::OldAdult));
    EXPECT_EQ(AgeCategory::Dead, AgeCategoryUtils::CategoryAfter(AgeCategory::Elder));
    EXPECT_EQ(AgeCategory::Dead, AgeCategoryUtils::CategoryAfter(AgeCategory::Dead));
}

TEST(AgeCategoryTest, AliveCategories)
{
    auto alive = AgeCategoryUtils::AliveCategories();
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::NewBorn) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::Toddler) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::Child) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::Teenager) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::YoungAdult) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::Adult) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::OldAdult) != alive.end());
    EXPECT_TRUE(std::find(alive.begin(), alive.end(), AgeCategory::Elder) != alive.end());
    EXPECT_FALSE(std::find(alive.begin(), alive.end(), AgeCategory::Dead) != alive.end());
}

TEST(AgeCategoryTest, MarryCategories)
{
    auto marry = AgeCategoryUtils::MarryCategories();
    EXPECT_FALSE(std::find(marry.begin(), marry.end(), AgeCategory::NewBorn) != marry.end());
    EXPECT_FALSE(std::find(marry.begin(), marry.end(), AgeCategory::Toddler) != marry.end());
    EXPECT_FALSE(std::find(marry.begin(), marry.end(), AgeCategory::Child) != marry.end());
    EXPECT_FALSE(std::find(marry.begin(), marry.end(), AgeCategory::Teenager) != marry.end());
    EXPECT_TRUE(std::find(marry.begin(), marry.end(), AgeCategory::YoungAdult) != marry.end());
    EXPECT_TRUE(std::find(marry.begin(), marry.end(), AgeCategory::Adult) != marry.end());
    EXPECT_TRUE(std::find(marry.begin(), marry.end(), AgeCategory::OldAdult) != marry.end());
    EXPECT_TRUE(std::find(marry.begin(), marry.end(), AgeCategory::Elder) != marry.end());
    EXPECT_FALSE(std::find(marry.begin(), marry.end(), AgeCategory::Dead) != marry.end());
}