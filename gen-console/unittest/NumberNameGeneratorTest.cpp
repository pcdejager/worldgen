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
    EXPECT_EQ(name1, L"Name_1");
    auto name2 = generator->GenerateName();
    EXPECT_EQ(name2, L"Name_2");
}