#pragma once

#include "Types.h"
#include "Genes.h"
#include "Sex.h"
#include "TimeSpan.h"

/// <summary>
/// Genome is a utility class to extract information from the genes for the individual
/// </summary>
class Genome
{
public:
    Genome();
    Genome(const Genes& inputGenes);
    Genome(const Genome& rhs) = default;
    ~Genome() = default;
    Genome& operator=(const Genome& rhs) = default;

public:
    RacePtr GetRace() const;
    Sex GetSex() const;
    __int64 GetHeight(const TimeSpan& age) const;
    __int64 GetWeight(const TimeSpan& age) const;
    TimeSpan MaximumAge() const;

private:
    TimeSpan GetPeriodCycle() const;

#ifdef UNITTEST
public:
    void ReplaceGenes(const Genes& newGenes);
    const Genes& GetGenes() const { return genes; }
#endif
    
private:
    Genes genes;
};

