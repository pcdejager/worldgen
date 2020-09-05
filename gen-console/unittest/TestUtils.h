#pragma once

#include "..\GenePositions.h"
#include "..\Genes.h"

class TestUtils
{
public:
    static __int64 RaceMaxNumber();

public:
    static void SetGenes_MaleFertile(Genes& genes);
    static void SetGenes_MaleInfertile(Genes& genes);
    static void SetGenes_FemaleFertile(Genes& genes);
    static void SetGenes_FemaleInfertile(Genes& genes);
};
