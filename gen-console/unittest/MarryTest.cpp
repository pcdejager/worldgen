#include "pch.h"
#include "..\Marry.h"
#include "..\Races.h"
#include "..\Race.h"

TEST(MarryTest, Constructor)
{
    std::map<__int64, double> maleMap;
    maleMap.insert(std::make_pair(1LL, 1.1));
    std::map<__int64, double> femaleMap;
    Marry test(maleMap, femaleMap);
    EXPECT_EQ(test.Test_Male().size(), 1u);
    EXPECT_EQ(test.Test_Female().size(), 0u);
}

TEST(MarryTest, ChanceToMarryMale)
{
    RacePtr humanRace = Races::GetRaces()->FindRaceByName(L"Human");
    RacePtr elfRace = Races::GetRaces()->FindRaceByName(L"Elf");

    EXPECT_EQ(humanRace->Traits().marry->ChanceToMarryMale(humanRace->ID()), 0.98);
    EXPECT_EQ(humanRace->Traits().marry->ChanceToMarryMale(elfRace->ID()), 0.015);

    EXPECT_EQ(elfRace->Traits().marry->ChanceToMarryMale(humanRace->ID()), 0.001);
    EXPECT_EQ(elfRace->Traits().marry->ChanceToMarryMale(elfRace->ID()), 0.90);
}

TEST(MarryTest, ChanceToMarryFemale)
{
    RacePtr humanRace = Races::GetRaces()->FindRaceByName(L"Human");
    RacePtr elfRace = Races::GetRaces()->FindRaceByName(L"Elf");

    EXPECT_EQ(humanRace->Traits().marry->ChanceToMarryFemale(humanRace->ID()), 0.95);
    EXPECT_EQ(humanRace->Traits().marry->ChanceToMarryFemale(elfRace->ID()), 0.005);

    EXPECT_EQ(elfRace->Traits().marry->ChanceToMarryFemale(humanRace->ID()), 0.005);
    EXPECT_EQ(elfRace->Traits().marry->ChanceToMarryFemale(elfRace->ID()), 0.95);
}