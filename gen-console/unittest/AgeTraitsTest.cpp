#include "pch.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"

TEST(AgeTraitsTest, Constructor)
{
    MultiPointValueInt values1;
    AgeTraits test1(values1);
    EXPECT_EQ(test1.AgeStart(AgeCategory::Dead), 0LL);
    
    //std::vector<__int64> ranges = { 10LL, 20LL, 30LL, 40LL, 50LL, 60LL, 70LL, 80LL }
    MultiPointValueInt values2({ 10LL, 20LL, 30LL, 40LL, 50LL, 60LL, 70LL, 80LL });
    AgeTraits test2(values2);
    EXPECT_EQ(test2.AgeStart(AgeCategory::Dead), 80LL);
}

TEST(AgeTraitsTest, Categorize)
{
    __int64 year = TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL, false).Ticks();
    MultiPointValueInt values({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraits test(values);
    EXPECT_EQ(test.Categorize(TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL, true)), AgeCategory::Dead);
    EXPECT_EQ(test.Categorize(TimeSpan(0LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::NewBorn);
    EXPECT_EQ(test.Categorize(TimeSpan(9LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::NewBorn);
    EXPECT_EQ(test.Categorize(TimeSpan(10LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Toddler);
    EXPECT_EQ(test.Categorize(TimeSpan(19LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Toddler);
    EXPECT_EQ(test.Categorize(TimeSpan(20LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Child);
    EXPECT_EQ(test.Categorize(TimeSpan(29LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Child);
    EXPECT_EQ(test.Categorize(TimeSpan(30LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Teenager);
    EXPECT_EQ(test.Categorize(TimeSpan(39LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Teenager);
    EXPECT_EQ(test.Categorize(TimeSpan(40LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::YoungAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(49LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::YoungAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(50LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Adult);
    EXPECT_EQ(test.Categorize(TimeSpan(59LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Adult);
    EXPECT_EQ(test.Categorize(TimeSpan(60LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::OldAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(69LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::OldAdult);
    EXPECT_EQ(test.Categorize(TimeSpan(70LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Elder);
    EXPECT_EQ(test.Categorize(TimeSpan(79LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Elder);
    EXPECT_EQ(test.Categorize(TimeSpan(80LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Dead);
    EXPECT_EQ(test.Categorize(TimeSpan(90LL, 0LL, 0LL, 0LL, 0LL, false)), AgeCategory::Dead);
}

TEST(AgeTraitsTest, AgeStart)
{
    __int64 year = TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL, false).Ticks();
    MultiPointValueInt values({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraits test(values);
    EXPECT_EQ(0LL * year, test.AgeStart(AgeCategory::NewBorn));
    EXPECT_EQ(10LL * year, test.AgeStart(AgeCategory::Toddler));
    EXPECT_EQ(20LL * year, test.AgeStart(AgeCategory::Child));
    EXPECT_EQ(30LL * year, test.AgeStart(AgeCategory::Teenager));
    EXPECT_EQ(40LL * year, test.AgeStart(AgeCategory::YoungAdult));
    EXPECT_EQ(50LL * year, test.AgeStart(AgeCategory::Adult));
    EXPECT_EQ(60LL * year, test.AgeStart(AgeCategory::OldAdult));
    EXPECT_EQ(70LL * year, test.AgeStart(AgeCategory::Elder));
    EXPECT_EQ(80LL * year, test.AgeStart(AgeCategory::Dead));
}

TEST(AgeTraitsTest, AgeEnd)
{
    __int64 year = TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL, false).Ticks();
    MultiPointValueInt values({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraits test(values);
    EXPECT_EQ(10LL * year - 1LL, test.AgeEnd(AgeCategory::NewBorn));
    EXPECT_EQ(20LL * year - 1LL, test.AgeEnd(AgeCategory::Toddler));
    EXPECT_EQ(30LL * year - 1LL, test.AgeEnd(AgeCategory::Child));
    EXPECT_EQ(40LL * year - 1LL, test.AgeEnd(AgeCategory::Teenager));
    EXPECT_EQ(50LL * year - 1LL, test.AgeEnd(AgeCategory::YoungAdult));
    EXPECT_EQ(60LL * year - 1LL, test.AgeEnd(AgeCategory::Adult));
    EXPECT_EQ(70LL * year - 1LL, test.AgeEnd(AgeCategory::OldAdult));
    EXPECT_EQ(80LL * year - 1LL, test.AgeEnd(AgeCategory::Elder));
    EXPECT_EQ(-1LL, test.AgeEnd(AgeCategory::Dead));
}

TEST(AgeTraitsTest, NextAgeStart)
{
    __int64 year = TimeSpan(1LL, 0LL, 0LL, 0LL, 0LL, false).Ticks();
    MultiPointValueInt values({ 10LL * year, 20LL * year, 30LL * year, 40LL * year, 50LL * year, 60LL * year, 70LL * year, 80LL * year });
    AgeTraits test(values);
    EXPECT_EQ(10LL * year, test.NextAgeStart(AgeCategory::NewBorn));
    EXPECT_EQ(20LL * year, test.NextAgeStart(AgeCategory::Toddler));
    EXPECT_EQ(30LL * year, test.NextAgeStart(AgeCategory::Child));
    EXPECT_EQ(40LL * year, test.NextAgeStart(AgeCategory::Teenager));
    EXPECT_EQ(50LL * year, test.NextAgeStart(AgeCategory::YoungAdult));
    EXPECT_EQ(60LL * year, test.NextAgeStart(AgeCategory::Adult));
    EXPECT_EQ(70LL * year, test.NextAgeStart(AgeCategory::OldAdult));
    EXPECT_EQ(80LL * year, test.NextAgeStart(AgeCategory::Elder));
    EXPECT_EQ(-1LL, test.NextAgeStart(AgeCategory::Dead));
}