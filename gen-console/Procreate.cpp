#include "pch.h"
#include "Procreate.h"
#include "Logger.h"

void Procreate::Reset()
{
    matrix.clear();
}

void Procreate::Add(__int64 maleRaceID, __int64 femaleRaceID, const std::vector<__int64>& raceIDs, const std::vector<double>& chance)
{
    Pairing pairing = std::make_pair(maleRaceID, femaleRaceID);
    PairingResult result = std::make_pair(raceIDs, chance);
    matrix.insert(std::make_pair(pairing, result));
}

__int64 Procreate::Lookup(__int64 father, __int64 mother, double roll)
{
    Pairing pairing = std::make_pair(father, mother);
    auto find = matrix.find(pairing);
    if (find != matrix.end())
    {
        //  0    1    2
        //0.8 0.90 0.99

        PairingResult result = find->second;
        std::size_t index = result.second.size() - 1;
        __int64 raceID = -1;
        for (std::size_t index = result.second.size() - 1; (index > 0) && (raceID == -1); ++index)
        {
            if (roll > result.second[index])
            {
                raceID = result.first[index];
            }
        }
        if (raceID == -1)
        {
            raceID = result.first[0];
        }
        return raceID;
    }
    return 0;
}

void Procreate::LogMatrix() const
{
    LoggerPtr log = Logger::GetLogger();

    log->Log(L"Procreate Matrix:");
    for (auto item : matrix)
    {
        log->Log(L"  Male  : ", item.first.first);
        log->Log(L"  Female: ", item.first.second);

        std::wstringstream ids;
        ids << L"[";
        for (auto id : item.second.first)
        {
            ids << id << L" ";
        }
        ids << L"]";
        log->Log(ids.str());

        std::wstringstream chance;
        chance << L"[";
        for (auto percentage : item.second.second)
        {
            chance << percentage << L" ";
        }
        chance << L"]";
        log->Log(chance.str());
    }
}