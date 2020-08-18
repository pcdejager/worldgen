#include "pch.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"

TEST(AgeTraitsTest, Constructor)
{
    MultiPointValue values1;
    AgeTraits test1(values1);
    EXPECT_EQ(test1.AgeStart(AgeCategory::Dead), 0L);
    
    //std::vector<__int64> ranges = { 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L }
    MultiPointValue values2({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraits test2(values2);
    EXPECT_EQ(test2.AgeStart(AgeCategory::Dead), 80L);
}

TEST(AgeTraitsTest, Categorize)
{
    MultiPointValue values({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraits test(values);
    EXPECT_EQ(test.Categorize(TimeSpan(1L, 0L, 0L, 0L, 0L, true)), AgeCategory::Dead);
    EXPECT_EQ(test.Categorize(TimeSpan(0L, 0L, 0L, 0L, 0L, false)), AgeCategory::NewBorn);
    EXPECT_EQ(test.Categorize(TimeSpan(9L, 0L, 0l, 0L, 0L, false)), AgeCategory::NewBorn);
    EXPECT_EQ(test.Categorize(TimeSpan(10L, 0L, 0L, 0L, 0L, false)), AgeCategory::Toddler);
    EXPECT_EQ(test.Categorize(TimeSpan(19L, 0L, 0L, 0L, 0L, false)), AgeCategory::Toddler);
    EXPECT_EQ(test.Categorize(TimeSpan(20L, 0L, 0L, 0L, 0L, false)), AgeCategory::Child);
    EXPECT_EQ(test.Categorize(TimeSpan(29L, 0L, 0L, 0L, 0L, false)), AgeCategory::Child);
    EXPECT_EQ(test.Categorize(TimeSpan(30L, 0L, 0L, 0L, 0L, false)), AgeCategory::Teenager);
    EXPECT_EQ(test.Categorize(TimeSpan(39L, 0L, 0L, 0L, 0L, false)), AgeCategory::Teenager);
    EXPECT_EQ(test.Categorize(TimeSpan(40L, 0L, 0L, 0L, 0L, false)), AgeCategory::YoungAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(49L, 0L, 0L, 0L, 0L, false)), AgeCategory::YoungAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(50L, 0L, 0L, 0L, 0L, false)), AgeCategory::Adult);
    EXPECT_EQ(test.Categorize(TimeSpan(59L, 0L, 0L, 0L, 0L, false)), AgeCategory::Adult);
    EXPECT_EQ(test.Categorize(TimeSpan(60L, 0L, 0L, 0L, 0L, false)), AgeCategory::OldAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(69L, 0L, 0L, 0L, 0L, false)), AgeCategory::OldAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(70L, 0L, 0L, 0L, 0L, false)), AgeCategory::Elder);
    EXPECT_EQ(test.Categorize(TimeSpan(79L, 0L, 0L, 0L, 0L, false)), AgeCategory::Elder);
    EXPECT_EQ(test.Categorize(TimeSpan(80L, 0L, 0L, 0L, 0L, false)), AgeCategory::Dead);
    EXPECT_EQ(test.Categorize(TimeSpan(90L, 0L, 0L, 0L, 0L, false)), AgeCategory::Dead);
}