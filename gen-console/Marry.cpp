#include "pch.h"
#include "Marry.h"
#include "Logger.h"

Marry::Marry(const std::map<__int64, double>& marryMale, const std::map<__int64, double>& marryFemale)
    : male(marryMale)
    , female(marryFemale)
{
    ;
}

double Marry::ChanceToMarryMale(__int64 raceID)
{
    auto find = male.find(raceID);
    if (find != male.end())
    {
        return find->second;
    }
    return 0.0;
}

double Marry::ChanceToMarryFemale(__int64 raceID)
{
    auto find = female.find(raceID);
    if (find != female.end())
    {
        return find->second;
    }
    return 0.0;
}

void Marry::Log() const
{
    LoggerPtr logger = Logger::GetLogger();

    {
        std::wstringstream result;
        for (auto item : male)
        {
            result << L"[" << item.first << "," << item.second << "]";
        }
        logger->Log(L"    Marry Male = ", result.str());
    }
    {
        std::wstringstream result;
        for (auto item : female)
        {
            result << L"[" << item.first << "," << item.second << "]";
        }
        logger->Log(L"    Marry Female = ", result.str());
    }
}