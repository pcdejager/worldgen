#pragma once

// Genome positions

// Race
constexpr std::size_t RaceGenesStart = 0;
constexpr std::size_t RaceGenesSize = 2;

// Sex
constexpr std::size_t SexGenesStart = RaceGenesStart + RaceGenesSize;
constexpr std::size_t SexGenesSize = 8;

// Height
constexpr std::size_t HeightGenesStart = SexGenesStart + SexGenesSize;
constexpr std::size_t HeightGenesSize = 16;

// Weight
constexpr std::size_t WeightGenesStart = HeightGenesStart + HeightGenesSize;
constexpr std::size_t WeightGenesSize = 16;

// Final result
constexpr std::size_t NumberOfBits = 128;
constexpr std::size_t NumberOfBytes = (NumberOfBits / 8) + 1;


