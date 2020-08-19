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

TEST(AgeTraitsTest, AgeStart)
{
    MultiPointValue values({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraits test(values);
    EXPECT_EQ(0L, test.AgeStart(AgeCategory::NewBorn));
    EXPECT_EQ(10L, test.AgeStart(AgeCategory::Toddler));
    EXPECT_EQ(20L, test.AgeStart(AgeCategory::Child));
    EXPECT_EQ(30L, test.AgeStart(AgeCategory::Teenager));
    EXPECT_EQ(40L, test.AgeStart(AgeCategory::YoungAdult));
    EXPECT_EQ(50L, test.AgeStart(AgeCategory::Adult));
    EXPECT_EQ(60L, test.AgeStart(AgeCategory::OldAdult));
    EXPECT_EQ(70L, test.AgeStart(AgeCategory::Elder));
    EXPECT_EQ(80L, test.AgeStart(AgeCategory::Dead));
}

TEST(AgeTraitsTest, AgeEnd)
{
    MultiPointValue values({ 10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L });
    AgeTraits test(values);
    EXPECT_EQ(9L, test.AgeEnd(AgeCategory::NewBorn));
    EXPECT_EQ(19L, test.AgeEnd(AgeCategory::Toddler));
    EXPECT_EQ(29L, test.AgeEnd(AgeCategory::Child));
    EXPECT_EQ(39L, test.AgeEnd(AgeCategory::Teenager));
    EXPECT_EQ(49L, test.AgeEnd(AgeCategory::YoungAdult));
    EXPECT_EQ(59L, test.AgeEnd(AgeCategory::Adult));
    EXPECT_EQ(69L, test.AgeEnd(AgeCategory::OldAdult));
    EXPECT_EQ(79L, test.AgeEnd(AgeCategory::Elder));
    EXPECT_EQ(-1L, test.AgeEnd(AgeCategory::Dead));
}