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
    Genome(const Genome& rhs) = default;
    ~Genome() = default;
    Genome& operator=(const Genome& rhs) = default;

public:
    RacePtr GetRace() const;
    Sex GetSex() const;
    __int64 GetHeight(const TimeSpan& age) const;
    __int64 GetWeight(const TimeSpan& age) const;

#ifdef UNITTEST
public:
    void ReplaceGenes(const Genes& newGenes);
#endif
    
private:
    void InitializeRaces() const;

private:
    Genes genes;

#ifdef UNITTEST
public:
#else
private:
#endif
    static std::map<__int64, std::wstring> genomeRaces;
};

