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
    auto raceGene = race->Traits().gene.Value(0);
    genes.SetGenes(GenePositions::Race(), raceGene);
}

/*static*/ void TestUtils::SetGenes_MaleFertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male);
    genes.SetGenes(GenePositions::Fertility(), 1.0);
}

/*static*/ void TestUtils::SetGenes_MaleInfertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male);
    genes.SetGenes(GenePositions::Fertility(), 0.0);
}

/*static*/ void TestUtils::SetGenes_FemaleFertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Female);
    genes.SetGenes(GenePositions::Fertility(), 1.0);
}

/*static*/ void TestUtils::SetGenes_FemaleInfertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Female);
    genes.SetGenes(GenePositions::Fertility(), 0.0);
}

/*static*/ void TestUtils::SetGenes_MaximumLife(Genes& genes, double value)
{
    genes.SetGenes(GenePositions::MaximumLife(), value);
}

/*static*/ IndividualPtr TestUtils::CreateIndividual(const std::wstring& raceName, bool male, bool fertile)
{
    Genes genes;
    RacePtr race = Races::GetRaces()->FindRaceByName(raceName);
    TestUtils::SetGenes_Race(genes, race);

    if (male && fertile)
    {
        TestUtils::SetGenes_MaleFertile(genes);
    }
    else if (male && !fertile)
    {
        TestUtils::SetGenes_MaleInfertile(genes);
    }
    else if (!male && fertile)
    {
        TestUtils::SetGenes_FemaleFertile(genes);
    }
    else if (!male && !fertile)
    {
        TestUtils::SetGenes_FemaleInfertile(genes);
    }
    
    return IndividualPtr(new Individual(Parents::CreateNoParents(), genes));
}