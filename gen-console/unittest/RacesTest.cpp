#include "pch.h"
#include "..\Races.h"
#include "..\Race.h"

TEST(RacesTest, Initialize)
{
    Races test;
    test.Initialize();
    EXPECT_EQ(test.NumberOfRaces(), 3);
}

TEST(RacesTest, NumberOfRaces)
{
    Races test;
    test.Initialize();
    EXPECT_EQ(test.NumberOfRaces(), 3);
}

TEST(RacesTest, HasRace)
{
    Races test;
    test.Initialize();
    EXPECT_TRUE(test.HasRace(L"Human"));
    EXPECT_TRUE(test.HasRace(L"Elf"));
    EXPECT_TRUE(test.HasRace(L"Half-elf"));
    EXPECT_FALSE(test.HasRace(L"Unknown"));
}

TEST(RacesTest, FindRace)
{
    Races test;
    test.Initialize();

    EXPECT_EQ(test.FindRace(L"Human")->Name(), L"Human");
    EXPECT_EQ(test.FindRace(L"Elf")->Name(), L"Elf");
    EXPECT_EQ(test.FindRace(L"Half-elf")->Name(), L"Half-elf");

    EXPECT_EQ(test.FindRace(L"Unknown"), nullptr);
}