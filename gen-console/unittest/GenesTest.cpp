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

    test.SetBool(9, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 1.0 / 1023.0);

    test.SetBool(8, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 3.0 / 1023.0);

    test.SetBool(7, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 7.0 / 1023.0);

    test.SetBool(6, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 15.0 / 1023.0);

    test.SetBool(5, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 31.0 / 1023.0);

    test.SetBool(4, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 63.0 / 1023.0);

    test.SetBool(3, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 127.0 / 1023.0);

    test.SetBool(2, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 255.0 / 1023.0);

    test.SetBool(1, true);
    EXPECT_EQ(test.ReadDouble(0, 10), 511.0 / 1023.0);

    test.SetBool(0, true);
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