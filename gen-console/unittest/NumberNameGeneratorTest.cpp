#include "pch.h"
#include "..\NumberNameGenerator.h"

TEST(NumberNameGeneratorTest, Constuctor)
{
    auto generator = new NumberNameGenerator();
    ASSERT_NE(generator, nullptr);
}

TEST(NumberNameGeneratorTest, GenerateName)
{
    auto generator = new NumberNameGenerator();
    auto name1 = generator->GenerateName();
    EXPECT_EQ(name1.FirstName(), L"First_1");
    EXPECT_EQ(name1.LastName(), L"Last_1");
    auto name2 = generator->GenerateName();
    EXPECT_EQ(name2.FirstName(), L"First_2");
    EXPECT_EQ(name2.LastName(), L"Last_2");
}