#include "pch.h"
#include "Races.h"
#include "Race.h"
#include "ConfigLoader.h"
#include "RacialTraits.h"
#include "TimeSpan.h"
#include "AgeTraits.h"

/*static*/ RacesPtr Races::instance = nullptr;

/*static*/ RacesPtr Races::GetRaces()
{
    if (instance == nullptr)
    {
        instance = RacesPtr(new Races());
        instance->Initialize();
    }
    return instance;
}

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

        auto [found, name] = loader.ReadString(L"Race");
        std::wcout << L"    Name: " << name << std::endl;

        RacialTraits traits;
        MultiPointValueInt ages;
        std::tie(found, ages) = loader.ReadMultiPointValueInt(L"AgeRanges");
        std::wcout << L"    AgeRanges = [";
        for (std::size_t count = 0; count < ages.Count(); ++count)
        {
            std::wcout << TimeSpan(ages.Value(count)).ToString() << L" ";
        }
        std::wcout << L"]" << std::endl;
        traits.ageRanges = std::make_shared<AgeTraits>(ages);

        std::tie(found, traits.pregnancy) = loader.ReadMultiPointValueInt(L"Pregnancy");

        std::wcout << L"    Pregnancy = [";
        for (std::size_t count = 0; count < traits.pregnancy.Count(); ++count)
        {
            std::wcout << TimeSpan(traits.pregnancy.Value(count)).ToString() << L" ";
        }
        std::wcout << L"]" << std::endl;

        RacePtr newRace = RacePtr(new Race(name, traits));
        races.insert(std::make_pair(name, newRace));

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

std::vector<std::wstring> Races::AllRaces() const
{
    std::vector<std::wstring> result;
    for (auto item : races)
    {
        result.push_back(item.first);
    }
    return result;
}

bool Races::HasRace(const std::wstring& name) const
{
    if (races.find(name) != races.end())
    {
        return true;
    }
    return false;
}

RacePtr Races::FindRace(const std::wstring& name) const
{
    auto find = races.find(name);
    if (find != races.end())
    {
        return find->second;
    }
    return nullptr;
}