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