#pragma once

// Genome positions
#include "GenePosition.h"

enum class GeneType 
{ 
    Race = 0, 
    Sex = 1, 
    Period = 2, 
    Fertility = 3, 
    Height = 4, 
    Weight = 5, 
    MaximumLife = 6
};

// Final result
constexpr std::size_t NumberOfBits = 128;
constexpr std::size_t NumberOfBytes = (NumberOfBits / 8) + 1;

class GenePositions
{
public:
    // Race
    //static constexpr GenePosition Race() { return GenePosition(GeneCategory::RACE, 0, 2); }
    //static constexpr GenePosition Sex() { return GenePosition(GeneCategory::DOUBLE, Race().End(), 8); }
    //static constexpr GenePosition Period() { return GenePosition(GeneCategory::DOUBLE, Sex().End(), 8); }
    //static constexpr GenePosition Fertility() { return GenePosition(GeneCategory::DOUBLE, Period().End(), 8); }
    //static constexpr GenePosition Height() { return GenePosition(GeneCategory::DOUBLE, Fertility().End(), 16); }
    //static constexpr GenePosition Weight() { return GenePosition(GeneCategory::DOUBLE, Height().End(), 16); }
    //static constexpr GenePosition MaximumLife() { return GenePosition(GeneCategory::DOUBLE, Weight().End(), 16); }

    static GenePosition GetPosition(GeneType type);
    static const std::map<GeneType, GenePosition>& AllGenes();

private:
    static void Initialize();

private:
    static std::map<GeneType, GenePosition> genes;
};