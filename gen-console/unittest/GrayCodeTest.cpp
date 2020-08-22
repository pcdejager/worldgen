#include "pch.h"
#include "../GrayCode.h"

TEST(GrayCodeTest, BinaryToGray_2)
{
    EXPECT_EQ(0L, GrayCode::BinaryToGray(0L));
    EXPECT_EQ(1L, GrayCode::BinaryToGray(1L));
    EXPECT_EQ(3L, GrayCode::BinaryToGray(2L));
    EXPECT_EQ(2L, GrayCode::BinaryToGray(3L));
}

TEST(GrayCodeTest, BinaryToGray_3)
{
    EXPECT_EQ(0L, GrayCode::BinaryToGray(0L));
    EXPECT_EQ(1L, GrayCode::BinaryToGray(1L));
    EXPECT_EQ(3L, GrayCode::BinaryToGray(2L));
    EXPECT_EQ(2L, GrayCode::BinaryToGray(3L));
    EXPECT_EQ(6L, GrayCode::BinaryToGray(4L));
    EXPECT_EQ(7L, GrayCode::BinaryToGray(5L));
    EXPECT_EQ(5L, GrayCode::BinaryToGray(6L));
    EXPECT_EQ(4L, GrayCode::BinaryToGray(7L));
}

TEST(GrayCodeTest, BinaryToGray_4)
{
    EXPECT_EQ(0L, GrayCode::BinaryToGray(0L));
    EXPECT_EQ(1L, GrayCode::BinaryToGray(1L));
    EXPECT_EQ(3L, GrayCode::BinaryToGray(2L));
    EXPECT_EQ(2L, GrayCode::BinaryToGray(3L));
    EXPECT_EQ(6L, GrayCode::BinaryToGray(4L));
    EXPECT_EQ(7L, GrayCode::BinaryToGray(5L));
    EXPECT_EQ(5L, GrayCode::BinaryToGray(6L));
    EXPECT_EQ(4L, GrayCode::BinaryToGray(7L));
    EXPECT_EQ(12L, GrayCode::BinaryToGray(8L));
    EXPECT_EQ(13L, GrayCode::BinaryToGray(9L));
    EXPECT_EQ(15L, GrayCode::BinaryToGray(10L));
    EXPECT_EQ(14L, GrayCode::BinaryToGray(11L));
    EXPECT_EQ(10L, GrayCode::BinaryToGray(12L));
    EXPECT_EQ(11L, GrayCode::BinaryToGray(13L));
    EXPECT_EQ(9L, GrayCode::BinaryToGray(14L));
    EXPECT_EQ(8L, GrayCode::BinaryToGray(15L));
}

TEST(GrayCodeTest, GrayToBinary_2)
{
    EXPECT_EQ(0L, GrayCode::GrayToBinary(0L));
    EXPECT_EQ(1L, GrayCode::GrayToBinary(1L));
    EXPECT_EQ(2L, GrayCode::GrayToBinary(3L));
    EXPECT_EQ(3L, GrayCode::GrayToBinary(2L));
}

TEST(GrayCodeTest, GrayToBinary_3)
{
    EXPECT_EQ(0L, GrayCode::GrayToBinary(0L));
    EXPECT_EQ(1L, GrayCode::GrayToBinary(1L));
    EXPECT_EQ(2L, GrayCode::GrayToBinary(3L));
    EXPECT_EQ(3L, GrayCode::GrayToBinary(2L));
    EXPECT_EQ(4L, GrayCode::GrayToBinary(6L));
    EXPECT_EQ(5L, GrayCode::GrayToBinary(7L));
    EXPECT_EQ(6L, GrayCode::GrayToBinary(5L));
    EXPECT_EQ(7L, GrayCode::GrayToBinary(4L));
}
TEST(GrayCodeTest, GrayToBinary_4)
{
    EXPECT_EQ(0L, GrayCode::GrayToBinary(0L));
    EXPECT_EQ(1L, GrayCode::GrayToBinary(1L));
    EXPECT_EQ(2L, GrayCode::GrayToBinary(3L));
    EXPECT_EQ(3L, GrayCode::GrayToBinary(2L));
    EXPECT_EQ(4L, GrayCode::GrayToBinary(6L));
    EXPECT_EQ(5L, GrayCode::GrayToBinary(7L));
    EXPECT_EQ(6L, GrayCode::GrayToBinary(5L));
    EXPECT_EQ(7L, GrayCode::GrayToBinary(4L));
    EXPECT_EQ(8L, GrayCode::GrayToBinary(12L));
    EXPECT_EQ(9L, GrayCode::GrayToBinary(13L));
    EXPECT_EQ(10L, GrayCode::GrayToBinary(15L));
    EXPECT_EQ(11L, GrayCode::GrayToBinary(14L));
    EXPECT_EQ(12L, GrayCode::GrayToBinary(10L));
    EXPECT_EQ(13L, GrayCode::GrayToBinary(11L));
    EXPECT_EQ(14L, GrayCode::GrayToBinary(9L));
    EXPECT_EQ(15L, GrayCode::GrayToBinary(8L));
}
