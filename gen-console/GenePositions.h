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
    static constexpr GenePosition Race() { return GenePosition(GeneType::RACE, 0, 2); }
    static constexpr GenePosition Sex() { return GenePosition(GeneType::DOUBLE, Race().End(), 8); }
    static constexpr GenePosition Period() { return GenePosition(GeneType::DOUBLE, Sex().End(), 8); }
    static constexpr GenePosition Fertility() { return GenePosition(GeneType::DOUBLE, Period().End(), 8); }
    static constexpr GenePosition Height() { return GenePosition(GeneType::DOUBLE, Fertility().End(), 16); }
    static constexpr GenePosition Weight() { return GenePosition(GeneType::DOUBLE, Height().End(), 16); }
    static constexpr GenePosition MaximumLife() { return GenePosition(GeneType::DOUBLE, Weight().End(), 16); }

    static const std::vector<GenePosition>& AllGenes();

private:
    static std::vector<GenePosition> genes;
};