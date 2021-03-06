#include "pch.h"
#include "..\Genome.h"
#include "..\Genes.h"
#include "..\GenePositions.h"
#include "..\GrayCode.h"
#include "..\Races.h"
#include "..\Race.h"
#include "..\AgeTraits.h"
#include "..\AgeSexRangeValue.h"
#include "TestUtils.h"


TEST(GenomeTest, Constructor_genes)
{
    Genes genes;
    Genes empty;
    genes.SetGenes(GenePosition(GeneCategory::DOUBLE, 0LL, 16LL), 123456LL);

    Genome test1;
    EXPECT_TRUE(test1.GetGenes() != genes);
    EXPECT_TRUE(test1.GetGenes() == empty);

    Genome test2(genes);
    EXPECT_TRUE(test2.GetGenes() == genes);
    EXPECT_TRUE(test2.GetGenes() != empty);
}
TEST(GenomeTest, GetRace)
{
    Genome test;
    Genes genes;

    std::size_t numberOfRaces = Races::GetRaces()->NumberOfRaces();
    for (__int64 count = 0; count < TestUtils::RaceMaxNumber(); ++count)
    {
        genes.SetGenes(GenePositions::GetPosition(GeneType::Race), count);
        test.ReplaceGenes(genes);

        auto race = test.GetRace();
        ASSERT_TRUE(race != nullptr);

        auto compare = Races::GetRaces()->FindRaceByGene(count);
        ASSERT_TRUE(compare != nullptr);

        EXPECT_EQ(race->GetName(), compare->GetName());
    }
}

TEST(GenomeTest, GetSex)
{
    Genome test;
    Genes genes;
    TestUtils::SetGenes_Male(genes);
    test.ReplaceGenes(genes);
    EXPECT_TRUE(test.GetSex().IsMale());
    EXPECT_FALSE(test.GetSex().IsFemale());

    TestUtils::SetGenes_Female(genes);
    test.ReplaceGenes(genes);
    EXPECT_FALSE(test.GetSex().IsMale());
    EXPECT_TRUE(test.GetSex().IsFemale());
}

TEST(GenomeTest, GetHeight_Male)
{
    Genome test;
    Genes genes;

    std::vector<AgeCategory> ageCategories = { 
        AgeCategory::NewBorn, 
        AgeCategory::Toddler, 
        AgeCategory::Child, 
        AgeCategory::Teenager, 
        AgeCategory::YoungAdult, 
        AgeCategory::Adult, 
        AgeCategory::OldAdult, 
        AgeCategory::Elder };

    std::vector<std::wstring> races = Races::GetRaces()->AllRaceNames();
    for (std::size_t raceCount = 0; raceCount < races.size(); ++raceCount)
    {
        auto race = Races::GetRaces()->FindRaceByName(races[raceCount]);
        for (std::size_t raceID = 0; raceID < race->GetTraits().gene.Count(); ++raceID)
        {
            genes.SetGenes(GenePositions::GetPosition(GeneType::Race), race->GetTraits().gene.Value(raceID));
            TestUtils::SetGenes_Male(genes);
            genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0LL);
            test.ReplaceGenes(genes);
            std::wcout << "Race: " << test.GetRace()->GetName() << std::endl;

            // Check name
            EXPECT_EQ(test.GetRace()->GetName(), races[raceCount]);

            for (std::size_t ageCount = 0; ageCount < ageCategories.size(); ++ageCount)
            {
                AgeCategory category = ageCategories[ageCount];
                TimeSpan start = race->GetTraits().ageRanges->AgeStart(category);

                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0.0);
                test.ReplaceGenes(genes);
                __int64 height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->MaleRange().Value(ageCount).Minimum());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0.51);
                test.ReplaceGenes(genes);
                height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->MaleRange().Value(ageCount).Average());
            
                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 1.0);
                test.ReplaceGenes(genes);
                height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->MaleRange().Value(ageCount).Maximum());
            }
        } // raceID
    } // raceCount
}

TEST(GenomeTest, GetHeight_Female)
{
    Genome test;
    Genes genes;

    std::vector<AgeCategory> ageCategories = {
        AgeCategory::NewBorn,
        AgeCategory::Toddler,
        AgeCategory::Child,
        AgeCategory::Teenager,
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult,
        AgeCategory::Elder };

    std::vector<std::wstring> races = Races::GetRaces()->AllRaceNames();
    for (std::size_t raceCount = 0; raceCount < races.size(); ++raceCount)
    {
        auto race = Races::GetRaces()->FindRaceByName(races[raceCount]);
        for (std::size_t raceID = 0; raceID < race->GetTraits().gene.Count(); ++raceID)
        {
            genes.SetGenes(GenePositions::GetPosition(GeneType::Race), race->GetTraits().gene.Value(raceID));
            TestUtils::SetGenes_Female(genes);
            genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0LL);
            test.ReplaceGenes(genes);
            std::wcout << "Race: " << test.GetRace()->GetName() << std::endl;

            // Check name
            EXPECT_EQ(test.GetRace()->GetName(), races[raceCount]);

            for (std::size_t ageCount = 0; ageCount < ageCategories.size(); ++ageCount)
            {
                AgeCategory category = ageCategories[ageCount];
                TimeSpan start = race->GetTraits().ageRanges->AgeStart(category);

                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0.0);
                test.ReplaceGenes(genes);
                __int64 height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->FemaleRange().Value(ageCount).Minimum());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 0.51);
                test.ReplaceGenes(genes);
                height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->FemaleRange().Value(ageCount).Average());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Height), 1.0);
                test.ReplaceGenes(genes);
                height = test.GetHeight(start);
                EXPECT_EQ(height, race->GetTraits().height->FemaleRange().Value(ageCount).Maximum());
            }
        } // raceID
    } // raceCount
}

TEST(GenomeTest, GetWeight_Male)
{
    Genome test;
    Genes genes;

    std::vector<AgeCategory> ageCategories = {
        AgeCategory::NewBorn,
        AgeCategory::Toddler,
        AgeCategory::Child,
        AgeCategory::Teenager,
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult,
        AgeCategory::Elder };

    std::vector<std::wstring> races = Races::GetRaces()->AllRaceNames();
    for (std::size_t raceCount = 0; raceCount < races.size(); ++raceCount)
    {
        auto race = Races::GetRaces()->FindRaceByName(races[raceCount]);
        for (std::size_t raceID = 0; raceID < race->GetTraits().gene.Count(); ++raceID)
        {
            genes.SetGenes(GenePositions::GetPosition(GeneType::Race), race->GetTraits().gene.Value(raceID));
            TestUtils::SetGenes_Male(genes);
            genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0LL);
            test.ReplaceGenes(genes);
            std::wcout << "Race: " << test.GetRace()->GetName() << std::endl;

            // Check name
            EXPECT_EQ(test.GetRace()->GetName(), races[raceCount]);

            for (std::size_t ageCount = 0; ageCount < ageCategories.size(); ++ageCount)
            {
                AgeCategory category = ageCategories[ageCount];
                TimeSpan start = race->GetTraits().ageRanges->AgeStart(category);

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0.0);
                test.ReplaceGenes(genes);
                __int64 weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->MaleRange().Value(ageCount).Minimum());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0.51);
                test.ReplaceGenes(genes);
                weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->MaleRange().Value(ageCount).Average());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 1.0);
                test.ReplaceGenes(genes);
                weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->MaleRange().Value(ageCount).Maximum());
            }
        } // raceID
    } // raceCount
}

TEST(GenomeTest, GetWeight_Female)
{
    Genome test;
    Genes genes;

    std::vector<AgeCategory> ageCategories = {
        AgeCategory::NewBorn,
        AgeCategory::Toddler,
        AgeCategory::Child,
        AgeCategory::Teenager,
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult,
        AgeCategory::Elder };

    std::vector<std::wstring> races = Races::GetRaces()->AllRaceNames();
    for (std::size_t raceCount = 0; raceCount < races.size(); ++raceCount)
    {
        auto race = Races::GetRaces()->FindRaceByName(races[raceCount]);
        for (std::size_t raceID = 0; raceID < race->GetTraits().gene.Count(); ++raceID)
        {
            genes.SetGenes(GenePositions::GetPosition(GeneType::Race), race->GetTraits().gene.Value(raceID));
            TestUtils::SetGenes_Female(genes);
            genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0LL);
            test.ReplaceGenes(genes);
            std::wcout << "Race: " << test.GetRace()->GetName() << std::endl;

            // Check name
            EXPECT_EQ(test.GetRace()->GetName(), races[raceCount]);

            for (std::size_t ageCount = 0; ageCount < ageCategories.size(); ++ageCount)
            {
                AgeCategory category = ageCategories[ageCount];
                TimeSpan start = race->GetTraits().ageRanges->AgeStart(category);

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0.0);
                test.ReplaceGenes(genes);
                __int64 weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->FemaleRange().Value(ageCount).Minimum());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 0.51);
                test.ReplaceGenes(genes);
                weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->FemaleRange().Value(ageCount).Average());

                genes.SetGenes(GenePositions::GetPosition(GeneType::Weight), 1.0);
                test.ReplaceGenes(genes);
                weight = test.GetWeight(start);
                EXPECT_EQ(weight, race->GetTraits().weight->FemaleRange().Value(ageCount).Maximum());
            }
        } // raceID
    } // raceCount
}

TEST(GenomeTest, MaximumAge)
{
    Genome test;
    Genes genes;

    std::vector<std::wstring> races = Races::GetRaces()->AllRaceNames();
    for (std::size_t raceCount = 0; raceCount < races.size(); ++raceCount)
    {
        auto race = Races::GetRaces()->FindRaceByName(races[raceCount]);
        for (std::size_t raceID = 0; raceID < race->GetTraits().gene.Count(); ++raceID)
        {
            genes.SetGenes(GenePositions::GetPosition(GeneType::Race), race->GetTraits().gene.Value(raceID));
            TestUtils::SetGenes_Male(genes);
            genes.SetGenes(GenePositions::GetPosition(GeneType::MaximumLife), 0.0);
            test.ReplaceGenes(genes);

            TimeSpan result = test.MaximumAge();
            EXPECT_EQ(result.Ticks(), race->GetTraits().ageRanges->AgeStart(AgeCategory::Elder));

            genes.SetGenes(GenePositions::GetPosition(GeneType::MaximumLife), 1.0);
            test.ReplaceGenes(genes);

            result = test.MaximumAge();
            EXPECT_EQ(result.Ticks(), race->GetTraits().ageRanges->NextAgeStart(AgeCategory::Elder));
        }
    }
}