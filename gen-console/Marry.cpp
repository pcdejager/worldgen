#include "pch.h"
#include "Marry.h"
#include "Logger.h"

Marry::Marry(const std::map<__int64, double>& marryMale, const std::map<__int64, double>& marryFemale)
    : male(marryMale)
    , female(marryFemale)
{
    ;
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