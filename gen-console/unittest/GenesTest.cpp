#include "pch.h"
#include "../Genes.h"
#include "../GenePositions.h"

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

TEST(GenesTest, ReadDouble)
{
    Genes test;
    EXPECT_EQ(test.ReadDouble(0, 10), 0.0);

    test.SetGenes(0, 10, 1L);
    EXPECT_EQ(test.ReadDouble(0, 10), 1.0 / 1023.0);

    test.SetGenes(0, 10, 3L);
    EXPECT_EQ(test.ReadDouble(0, 10), 3.0 / 1023.0);

    test.SetGenes(0, 10, 7L);
    EXPECT_EQ(test.ReadDouble(0, 10), 7.0 / 1023.0);

    test.SetGenes(0, 10, 15L);
    EXPECT_EQ(test.ReadDouble(0, 10), 15.0 / 1023.0);

    test.SetGenes(0, 10, 31L);
    EXPECT_EQ(test.ReadDouble(0, 10), 31.0 / 1023.0);

    test.SetGenes(0, 10, 63L);
    EXPECT_EQ(test.ReadDouble(0, 10), 63.0 / 1023.0);

    test.SetGenes(0, 10, 127L);
    EXPECT_EQ(test.ReadDouble(0, 10), 127.0 / 1023.0);

    test.SetGenes(0, 10, 255L);
    EXPECT_EQ(test.ReadDouble(0, 10), 255.0 / 1023.0);

    test.SetGenes(0, 10, 511L);
    EXPECT_EQ(test.ReadDouble(0, 10), 511.0 / 1023.0);

    test.SetGenes(0, 10, 1023L);
    EXPECT_EQ(test.ReadDouble(0, 10), 1023.0 / 1023.0);
}

TEST(GenesTest, SetBool)
{
    Genes test;
    
    for (int count = 0; count < NumberOfBits; ++count)
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

