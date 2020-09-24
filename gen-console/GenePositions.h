#pragma once

// Genome positions
#include "GenePosition.h"

// Final result
constexpr std::size_t NumberOfBits = 128;
constexpr std::size_t NumberOfBytes = (NumberOfBits / 8) + 1;

class GenePositions
{
public:
    // Race
    static constexpr GenePosition Race() { return GenePosition(0, 2); }
    static constexpr GenePosition Sex() { return GenePosition(Race().End(), 8); }
    static constexpr GenePosition Period() { return GenePosition(Sex().End(), 8); }
    static constexpr GenePosition Fertility() { return GenePosition(Period().End(), 8); }
    static constexpr GenePosition Height() { return GenePosition(Fertility().End(), 16); }
    static constexpr GenePosition Weight() { return GenePosition(Height().End(), 16); }
    static constexpr GenePosition MaximumLife() { return GenePosition(Weight().End(), 16); }
};