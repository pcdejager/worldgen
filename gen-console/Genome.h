#pragma once

#include "Genes.h"
#include "Sex.h"

/// <summary>
/// Genome is a utility class to extract information from the genes for the individual
/// </summary>
class Genome
{
public:
    Genome();
    Genome(const Genome& rhs) = default;
    ~Genome() = default;
    Genome& operator=(const Genome& rhs) = default;

public:
    Sex GetSex() const;

#ifdef UNITTEST
public:
    void ReplaceGenes(const Genes& newGenes);
#endif
    
private:
    Genes genes;
};

