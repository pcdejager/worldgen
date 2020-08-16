#include "pch.h"
#include "Races.h"
#include "ConfigLoader.h"

void Races::Initialize()
{
    std::string filename = "E:\\Dev\\worldgen\\gen-console\\Config\\Races.txt";
    ConfigLoader loader(filename);
    if (!loader.Initialize())
    {
        return; // failure?
    }

    std::wcout << L"Reading Races:" << std::endl;
    std::wifstream file(filename);

    std::size_t counter = 0;
    bool ok = loader.MoveTo(L"Race");
    while (ok)
    {
        counter++;
        std::wcout << L"  Race #" << counter << std::endl;

        auto [found, value] = loader.ReadString(L"Race");
        std::wcout << L"    Name: " << value << std::endl;

        RacialTraits traits;
        std::tie(found, traits.minPregnancyDays) = loader.ReadInt(L"MinPreg");
        if (!found)
        {
            traits.minPregnancyDays = 0;
        }
        std::tie(found, traits.avgPregnancyDays) = loader.ReadInt(L"AvgPreg");
        if (!found)
        {
            traits.avgPregnancyDays = 0;
        }
        std::tie(found, traits.maxPregnancyDays) = loader.ReadInt(L"MaxPreg");
        if (!found)
        {
            traits.maxPregnancyDays = 0;
        }

        std::wcout << L"    Pregnancy = [" << traits.minPregnancyDays << L" .. " << traits.avgPregnancyDays << L" .. " << traits.maxPregnancyDays << L"]" << std::endl;

        loader.MoveOn();
        ok = loader.MoveTo(L"Race");
    }


    //std::size_t numberOfRaces = 0;
    //file >> numberOfRaces;

    //for (std::size_t count = 0; count < numberOfRaces; ++count)
    //{
    //    std::wstring name;
    //    RacialTraits traits;
    //    file >> name;
    //    file >> traits.minPregnancyDays;
    //    file >> traits.maxPregnancyDays;
    //    std::wcout << L"  Race #" << count << std::endl;
    //    std::wcout << L"    Name = " << name << std::endl;
    //    std::wcout << L"    Pregnancy = [" << traits.minPregnancyDays << L" .. " << traits.maxPregnancyDays << L"]" << std::endl;
    //}
}