#include "pch.h"
#include "..\Races.h"
#include "..\Race.h"

TEST(RacesTest, GetRaces)
{
    auto test = Races::GetRaces();
    EXPECT_TRUE(test != nullptr);
}

TEST(RacesTest, NumberOfRaces)
{
    EXPECT_EQ(Races::GetRaces()->NumberOfRaces(), 3);
}

TEST(RacesTest, AllRaceNames)
{
    auto test = Races::GetRaces()->AllRaceNames();
    EXPECT_EQ(test.size(), 3u);
    for (std::size_t count = 0; count < test.size(); ++count)
    {
        EXPECT_TRUE(Races::GetRaces()->HasRace(test[count]));
    }
}

TEST(RacesTest, AllRaceIDs)
{
    auto test = Races::GetRaces()->AllRaceIDs();
    EXPECT_EQ(test.size(), 3u);
    for (std::size_t count = 0; count < test.size(); ++count)
    {
        EXPECT_TRUE(Races::GetRaces()->HasRace(test[count]));
    }
}

TEST(RacesTest, HasRace)
{
    auto test = Races::GetRaces();
    EXPECT_TRUE(test->HasRace(L"Human"));
    EXPECT_TRUE(test->HasRace(L"Elf"));
    EXPECT_TRUE(test->HasRace(L"Half-elf"));
    EXPECT_FALSE(test->HasRace(L"Unknown"));
}

TEST(RacesTest, FindRaceName)
{
    auto test = Races::GetRaces();
    EXPECT_EQ(test->FindRaceName(0LL), L"Human");
    EXPECT_EQ(test->FindRaceName(1LL), L"Human");
    EXPECT_EQ(test->FindRaceName(2LL), L"Elf");
    EXPECT_EQ(test->FindRaceName(3LL), L"Half-elf");

    EXPECT_EQ(test->FindRaceName(4LL), L"");
}

TEST(RacesTest, FindRaceByGene)
{
    auto test = Races::GetRaces();
    EXPECT_EQ(test->FindRaceByGene(0LL)->Name(), L"Human");
    EXPECT_EQ(test->FindRaceByGene(1LL)->Name(), L"Human");
    EXPECT_EQ(test->FindRaceByGene(2LL)->Name(), L"Elf");
    EXPECT_EQ(test->FindRaceByGene(3LL)->Name(), L"Half-elf");

    EXPECT_EQ(test->FindRaceByGene(4LL), nullptr);
}

TEST(RacesTest, FindRaceByID)
{
    auto test = Races::GetRaces();
    EXPECT_EQ(test->FindRaceByID(0LL)->Name(), L"Human");
    EXPECT_EQ(test->FindRaceByID(1LL)->Name(), L"Elf");
    EXPECT_EQ(test->FindRaceByID(2LL)->Name(), L"Half-elf");

    EXPECT_EQ(test->FindRaceByName(L"Unknown"), nullptr);
}

TEST(RacesTest, FindRaceByName)
{
    auto test = Races::GetRaces();
    EXPECT_EQ(test->FindRaceByName(L"Human")->Name(), L"Human");
    EXPECT_EQ(test->FindRaceByName(L"Elf")->Name(), L"Elf");
    EXPECT_EQ(test->FindRaceByName(L"Half-elf")->Name(), L"Half-elf");

    EXPECT_EQ(test->FindRaceByName(L"Unknown"), nullptr);
}