#include "pch.h"
#include "..\IndividualName.h"

TEST(IndividualNameTest, Constructor)
{
    IndividualName test;
    EXPECT_FALSE(test.IsValid());
    EXPECT_TRUE(test.FirstName().length() == 0);
    EXPECT_TRUE(test.LastName().length() == 0);
}

TEST(IndividualNameTest, Constructor_fl)
{
    std::wstring first = L"FirstName";
    std::wstring last = L"LastName";

    IndividualName test(first, last);
    EXPECT_TRUE(test.IsValid());
    EXPECT_EQ(test.FirstName(), first);
    EXPECT_EQ(test.LastName(), last);
}

TEST(IndividualNameTest, IsValid)
{
    IndividualName test1;
    EXPECT_FALSE(test1.IsValid());

    IndividualName test2(L"", L"TEST");
    EXPECT_FALSE(test2.IsValid());

    IndividualName test3(L"TEST", L"");
    EXPECT_FALSE(test3.IsValid());

    IndividualName test(L"TEST", L"TEST");
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualNameTest, FirstName)
{
    std::wstring first = L"FirstName";
    std::wstring last = L"LastName";

    IndividualName test(first, last);
    EXPECT_EQ(test.FirstName(), first);
}


TEST(IndividualNameTest, LastName)
{
    std::wstring first = L"FirstName";
    std::wstring last = L"LastName";

    IndividualName test(first, last);
    EXPECT_EQ(test.LastName(), last);
}

TEST(IndividualNameTest, ToString)
{
    std::wstring first = L"FirstName";
    std::wstring last = L"LastName";

    IndividualName test(first, last);
    EXPECT_EQ(test.ToString(), L"FirstName LastName");
}
