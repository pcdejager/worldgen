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

TEST(RacesTest, AllRaces)
{
    auto test = Races::GetRaces()->AllRaces();
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

TEST(RacesTest, FindRace)
{
    auto test = Races::GetRaces();
    EXPECT_EQ(test->FindRace(L"Human")->Name(), L"Human");
    EXPECT_EQ(test->FindRace(L"Elf")->Name(), L"Elf");
    EXPECT_EQ(test->FindRace(L"Half-elf")->Name(), L"Half-elf");

    EXPECT_EQ(test->FindRace(L"Unknown"), nullptr);
}