#pragma once

#include "..\GenePositions.h"
#include "..\Genes.h"
#include "..\Types.h"

class TestUtils
{
public:
    static __int64 RaceMaxNumber();

public:
    static void SetGenes_Race(Genes& genes, const RacePtr& race);
    static void SetGenes_Male(Genes& genes);
    static void SetGenes_Female(Genes& genes);
    static void SetGenes_Fertile(Genes& genes, double value);
    static void SetGenes_Period(Genes& genes, double value);

    static void SetGenes_MaximumLife(Genes& genes, double value);

    static IndividualPtr CreateIndividual(const std::wstring& raceName, bool male, double period, double fertile, double maxLife);
};

