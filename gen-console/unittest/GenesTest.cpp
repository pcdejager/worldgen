#include "pch.h"
#include "../Genes.h"
#include "../GenePositions.h"
#include "../GenePosition.h"

TEST(GenesTest, Constructor)
{
    Genes test;
    EXPECT_EQ(test.End(), 128);
}

TEST(GenesTest, ReadBool)
{
    Genes test;
    for (std::size_t count = 0; count < test.End(); ++count)
    {
        EXPECT_EQ(test.ReadBool(count), false);
        test.SetBool(count, true);
        EXPECT_EQ(test.ReadBool(count), true);
        test.SetBool(count, false);
        EXPECT_EQ(test.ReadBool(count), false);
    }
}

TEST(GenesTest, ReadInt)
{
    Genes test;
    for (__int64 value = 0LL; value < 1024LL; ++value)
    {
        test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), value);
        EXPECT_EQ(test.ReadInt(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), value);
    }
}

TEST(GenesTest, ReadDouble)
{
    Genes test;
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 0.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 1LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 1.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 3LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 3.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 7LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 7.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 15LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 15.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 31LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 31.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 63LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 63.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 127LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 127.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 255LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 255.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 511LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 511.0 / 1023.0);

    test.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL), 1023LL);
    EXPECT_EQ(test.ReadDouble(GenePosition(GeneCategory::DOUBLE, 0LL, 10LL)), 1023.0 / 1023.0);
}

TEST(GenesTest, SetBool)
{
    Genes test;
    
    for (std::size_t count = 0; count < NumberOfBits; ++count)
    {
        EXPECT_FALSE(test.ReadBool(count));
        if (count > 0)
        {
            EXPECT_TRUE(test.ReadBool(count - 1));
        }
        if (count < (NumberOfBits - 1))
        {
            EXPECT_FALSE(test.ReadBool(count + 1));
        }
        test.SetBool(count, true);
        EXPECT_TRUE(test.ReadBool(count));
        if (count > 0)
        {
            EXPECT_TRUE(test.ReadBool(count - 1));
        }
        if (count < (NumberOfBits - 1))
        {
            EXPECT_FALSE(test.ReadBool(count + 1));
        }
    }
}

TEST(GenesTest, OperatorEQ)
{
    Genes test1;
    Genes test2;

    EXPECT_TRUE(test1 == test2);

    test1.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 16LL), 12345LL);

    EXPECT_FALSE(test1 == test2);

    test2.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 16LL), 12345LL);

    EXPECT_TRUE(test1 == test2);
}

TEST(GenesTest, OperatorNE)
{
    Genes test1;
    Genes test2;

    EXPECT_FALSE(test1 != test2);

    test1.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 16LL), 12345LL);

    EXPECT_TRUE(test1 != test2);

    test2.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 16LL), 12345LL);

    EXPECT_FALSE(test1 != test2);
}