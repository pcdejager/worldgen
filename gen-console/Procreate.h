#pragma once

class Procreate
{
private:
    typedef std::vector<__int64> RaceIDs;
    typedef std::vector<double> PercentageChance;
    typedef std::pair<__int64, __int64> Pairing;
    typedef std::pair<RaceIDs, PercentageChance> PairingResult;

public:
    Procreate() = default;
    ~Procreate() = default;

public:
    void Reset();
    void Add(__int64 maleRaceID, __int64 femaleRaceID, const std::vector<__int64>& raceIDs, const std::vector<double>& chance);

public:
    __int64 Lookup(__int64 father, __int64 mother, double roll);

public:
    void LogMatrix() const;

#ifdef UNITTEST
public:
    std::map<Pairing, PairingResult>& Test_Matrix() { return matrix; }
#endif

private:
    std::map<Pairing, PairingResult> matrix;
};

