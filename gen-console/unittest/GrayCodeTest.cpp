#include "pch.h"
#include "../GrayCode.h"

TEST(GrayCodeTest, BinaryToGray_2)
{
    EXPECT_EQ(0LL, GrayCode::BinaryToGray(0LL));
    EXPECT_EQ(1LL, GrayCode::BinaryToGray(1LL));
    EXPECT_EQ(3LL, GrayCode::BinaryToGray(2LL));
    EXPECT_EQ(2LL, GrayCode::BinaryToGray(3LL));
}

TEST(GrayCodeTest, BinaryToGray_3)
{
    EXPECT_EQ(0LL, GrayCode::BinaryToGray(0LL));
    EXPECT_EQ(1LL, GrayCode::BinaryToGray(1LL));
    EXPECT_EQ(3LL, GrayCode::BinaryToGray(2LL));
    EXPECT_EQ(2LL, GrayCode::BinaryToGray(3LL));
    EXPECT_EQ(6LL, GrayCode::BinaryToGray(4LL));
    EXPECT_EQ(7LL, GrayCode::BinaryToGray(5LL));
    EXPECT_EQ(5LL, GrayCode::BinaryToGray(6LL));
    EXPECT_EQ(4LL, GrayCode::BinaryToGray(7LL));
}

TEST(GrayCodeTest, BinaryToGray_4)
{
    EXPECT_EQ(0LL, GrayCode::BinaryToGray(0LL));
    EXPECT_EQ(1LL, GrayCode::BinaryToGray(1LL));
    EXPECT_EQ(3LL, GrayCode::BinaryToGray(2LL));
    EXPECT_EQ(2LL, GrayCode::BinaryToGray(3LL));
    EXPECT_EQ(6LL, GrayCode::BinaryToGray(4LL));
    EXPECT_EQ(7LL, GrayCode::BinaryToGray(5LL));
    EXPECT_EQ(5LL, GrayCode::BinaryToGray(6LL));
    EXPECT_EQ(4LL, GrayCode::BinaryToGray(7LL));
    EXPECT_EQ(12LL, GrayCode::BinaryToGray(8LL));
    EXPECT_EQ(13LL, GrayCode::BinaryToGray(9LL));
    EXPECT_EQ(15LL, GrayCode::BinaryToGray(10LL));
    EXPECT_EQ(14LL, GrayCode::BinaryToGray(11LL));
    EXPECT_EQ(10LL, GrayCode::BinaryToGray(12LL));
    EXPECT_EQ(11LL, GrayCode::BinaryToGray(13LL));
    EXPECT_EQ(9LL, GrayCode::BinaryToGray(14LL));
    EXPECT_EQ(8LL, GrayCode::BinaryToGray(15LL));
}

TEST(GrayCodeTest, GrayToBinary_2)
{
    EXPECT_EQ(0LL, GrayCode::GrayToBinary(0LL));
    EXPECT_EQ(1LL, GrayCode::GrayToBinary(1LL));
    EXPECT_EQ(2LL, GrayCode::GrayToBinary(3LL));
    EXPECT_EQ(3LL, GrayCode::GrayToBinary(2LL));
}

TEST(GrayCodeTest, GrayToBinary_3)
{
    EXPECT_EQ(0LL, GrayCode::GrayToBinary(0LL));
    EXPECT_EQ(1LL, GrayCode::GrayToBinary(1LL));
    EXPECT_EQ(2LL, GrayCode::GrayToBinary(3LL));
    EXPECT_EQ(3LL, GrayCode::GrayToBinary(2LL));
    EXPECT_EQ(4LL, GrayCode::GrayToBinary(6LL));
    EXPECT_EQ(5LL, GrayCode::GrayToBinary(7LL));
    EXPECT_EQ(6LL, GrayCode::GrayToBinary(5LL));
    EXPECT_EQ(7LL, GrayCode::GrayToBinary(4LL));
}
TEST(GrayCodeTest, GrayToBinary_4)
{
    EXPECT_EQ(0LL, GrayCode::GrayToBinary(0LL));
    EXPECT_EQ(1LL, GrayCode::GrayToBinary(1LL));
    EXPECT_EQ(2LL, GrayCode::GrayToBinary(3LL));
    EXPECT_EQ(3LL, GrayCode::GrayToBinary(2LL));
    EXPECT_EQ(4LL, GrayCode::GrayToBinary(6LL));
    EXPECT_EQ(5LL, GrayCode::GrayToBinary(7LL));
    EXPECT_EQ(6LL, GrayCode::GrayToBinary(5LL));
    EXPECT_EQ(7LL, GrayCode::GrayToBinary(4LL));
    EXPECT_EQ(8LL, GrayCode::GrayToBinary(12LL));
    EXPECT_EQ(9LL, GrayCode::GrayToBinary(13LL));
    EXPECT_EQ(10LL, GrayCode::GrayToBinary(15LL));
    EXPECT_EQ(11LL, GrayCode::GrayToBinary(14LL));
    EXPECT_EQ(12LL, GrayCode::GrayToBinary(10LL));
    EXPECT_EQ(13LL, GrayCode::GrayToBinary(11LL));
    EXPECT_EQ(14LL, GrayCode::GrayToBinary(9LL));
    EXPECT_EQ(15LL, GrayCode::GrayToBinary(8LL));
}
