#include "pch.h"
#include "TestUtils.h"
#include "..\GenePositions.h"
#include "..\Race.h"
#include "..\Races.h"
#include "..\Individual.h"
#include "..\Parents.h"

// Races use 2 bits
constexpr __int64 GeneTest_Race_Max = (1LL << static_cast<__int64>(GenePositions::Race().Size())) - 1LL;

// Sex uses 8 bits
constexpr __int64 GeneTest_Male = 0LL;         // all bits disabled
constexpr __int64 GeneTest_Female = (1LL << static_cast<__int64>(GenePositions::Sex().Size())) - 1LL;     // all bits enabled

/*static*/ __int64 TestUtils::RaceMaxNumber()
{
    return GeneTest_Race_Max;
}

/*static*/ void TestUtils::SetGenes_Race(Genes& genes, const RacePtr& race)
{
    auto raceGene = race->GetTraits().gene.Value(0);
    genes.SetGenes(GenePositions::Race(), raceGene);
}

/*static*/ void TestUtils::SetGenes_Male(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male);
}

/*static*/ void TestUtils::SetGenes_Female(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Female);
}

/*static*/ void TestUtils::SetGenes_Fertile(Genes& genes, double value)
{
    genes.SetGenes(GenePositions::Fertility(), value);
}

/*static*/ void TestUtils::SetGenes_Period(Genes& genes, double value)
{
    genes.SetGenes(GenePositions::Period(), value);
}

/*static*/ void TestUtils::SetGenes_MaximumLife(Genes& genes, double value)
{
    genes.SetGenes(GenePositions::MaximumLife(), value);
}

/*static*/ IndividualPtr TestUtils::CreateIndividual(const std::wstring& raceName, bool male, double period, double fertile, double maxLife)
{
    Genes genes;
    RacePtr race = Races::GetRaces()->FindRaceByName(raceName);
    TestUtils::SetGenes_Race(genes, race);
    TestUtils::SetGenes_Period(genes, period);
    TestUtils::SetGenes_Fertile(genes, fertile);

    if (male)
    {
        TestUtils::SetGenes_Male(genes);
    }
    else 
    {
        TestUtils::SetGenes_Female(genes);
    }
    TestUtils::SetGenes_MaximumLife(genes, maxLife);
    
    return IndividualPtr(new Individual(Parents::CreateNoParents(), genes));
}