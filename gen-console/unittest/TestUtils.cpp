#include "pch.h"
#include "TestUtils.h"
#include "..\GenePositions.h"

// Races use 2 bits
constexpr __int64 GeneTest_Race_Max = (1LL << static_cast<__int64>(GenePositions::Race().Size())) - 1LL;

// Sex uses 8 bits
constexpr __int64 GeneTest_Male_Fertile = 0LL;         // all bits disabled
constexpr __int64 GeneTest_Male_Infertile = ((1LL << static_cast<__int64>(GenePositions::Sex().Size())) / 2LL) - 1LL;
constexpr __int64 GeneTest_Female_Fertile = (1LL << static_cast<__int64>(GenePositions::Sex().Size())) - 1LL;     // all bits enabled
constexpr __int64 GeneTest_Female_Infertile = ((1LL << static_cast<__int64>(GenePositions::Sex().Size())) / 2LL) + 1LL;

/*static*/ __int64 TestUtils::RaceMaxNumber()
{
    return GeneTest_Race_Max;
}

/*static*/ void TestUtils::SetGenes_MaleFertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male_Fertile);
}

/*static*/ void TestUtils::SetGenes_MaleInfertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Male_Infertile);
}

/*static*/ void TestUtils::SetGenes_FemaleFertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Female_Fertile);
}

/*static*/ void TestUtils::SetGenes_FemaleInfertile(Genes& genes)
{
    genes.SetGenes(GenePositions::Sex(), GeneTest_Female_Infertile);
}
