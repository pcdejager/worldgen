#pragma once

class Procreate
{
public:
    Procreate() = default;
    ~Procreate() = default;

public:
    void Reset();
    void Add(__int64 maleRaceID, __int64 femaleRaceID, const std::vector<__int64>& raceIDs, const std::vector<double>& chance);

public:
    void LogMatrix() const;

private:
    typedef std::vector<__int64> RaceIDs;
    typedef std::vector<double> PercentageChance;
    typedef std::pair<__int64, __int64> Pairing;
    typedef std::pair<RaceIDs, PercentageChance> PairingResult;
    std::map<Pairing, PairingResult> matrix;
};

