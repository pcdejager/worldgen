#include "pch.h"
#include "..\Pregnancy.h"
#include "TestUtils.h"

TEST(PregnancyTest, Constructor)
{
    IndividualPtr father = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr mother = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    WorldTime conceive(1ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    TimeSpan duration(1LL, 0LL, 0LL, 0LL, 0LL);

    Pregnancy test(father, mother, conceive, duration);

    EXPECT_EQ(test.Father(), father);
    EXPECT_EQ(test.Mother(), mother);
    EXPECT_EQ(test.Conceived(), conceive);
    EXPECT_EQ(test.Duration(), duration);
}

TEST(PregnancyTest, DueDate)
{
    IndividualPtr father = TestUtils::CreateIndividual(L"Human", true, 0.0, 1.0, 0.0);
    IndividualPtr mother = TestUtils::CreateIndividual(L"Human", false, 0.0, 1.0, 0.0);
    WorldTime conceive(1ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    TimeSpan duration(1LL, 0LL, 0LL, 0LL, 0LL);

    Pregnancy test(father, mother, conceive, duration);

    EXPECT_EQ(test.DueDate(), conceive + duration);
}