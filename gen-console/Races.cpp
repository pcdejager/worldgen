#include "pch.h"
#include "Races.h"

void Races::Initialize()
{
    std::string filename = "E:\\Dev\\worldgen\\gen-console\\Config\\Races.txt";
    std::wcout << L"Reading Races:" << std::endl;
    std::wifstream file(filename);

    std::size_t numberOfRaces = 0;
    file >> numberOfRaces;
    std::wcout << L"  #Races = " << numberOfRaces << std::endl;

    for (std::size_t count = 0; count < numberOfRaces; ++count)
    {
        std::wstring name;
        RacialTraits traits;
        file >> name;
        file >> traits.minPregnancyDays;
        file >> traits.maxPregnancyDays;
        std::wcout << L"  Race #" << count << std::endl;
        std::wcout << L"    Name = " << name << std::endl;
        std::wcout << L"    Pregnancy = [" << traits.minPregnancyDays << L" .. " << traits.maxPregnancyDays << L"]" << std::endl;
    }
}