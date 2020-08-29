#include "pch.h"
#include "Races.h"
#include "Race.h"
#include "ConfigLoader.h"
#include "RacialTraits.h"
#include "TimeSpan.h"
#include "AgeTraits.h"
#include "AgeSexRangeValue.h"

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

        // Gene
        std::tie(found, traits.gene) = loader.ReadMultiPointValueInt(L"Gene");
        std::wcout << L"    Gene = [";
        for (std::size_t count = 0; count < traits.gene.Count(); ++count)
        {
            std::wcout << traits.gene.Value(count) << L" ";
        }
        std::wcout << L"]" << std::endl;

        // AgeRanges
        MultiPointValueInt ages;
        std::tie(found, ages) = loader.ReadMultiPointValueInt(L"AgeRanges");
        std::wcout << L"    AgeRanges = [";
        for (std::size_t count = 0; count < ages.Count(); ++count)
        {
            std::wcout << TimeSpan(ages.Value(count)).ToString() << L" ";
        }
        std::wcout << L"]" << std::endl;
        traits.ageRanges = std::make_shared<AgeTraits>(ages);

        // Pregnancy
        std::tie(found, traits.pregnancy) = loader.ReadMultiPointValueInt(L"Pregnancy");

        std::wcout << L"    Pregnancy = [";
        for (std::size_t count = 0; count < traits.pregnancy.Count(); ++count)
        {
            std::wcout << TimeSpan(traits.pregnancy.Value(count)).ToString() << L" ";
        }
        std::wcout << L"]" << std::endl;

        // Height
        {
            MultiPointValueRange maleRange;
            std::tie(found, maleRange) = loader.ReadMultiPointValueRange(L"HeightMale");
            MultiPointValueRange femaleRange;
            std::tie(found, femaleRange) = loader.ReadMultiPointValueRange(L"HeightFemale");

            std::wcout << L"    Height =   Male [";
            for (std::size_t count = 0; count < maleRange.Count(); ++count)
            {
                std::wcout << maleRange.Value(count).ToString() << L" ";
            }
            std::wcout << L"]" << std::endl;
            std::wcout << L"    Height = Female [";
            for (std::size_t count = 0; count < femaleRange.Count(); ++count)
            {
                std::wcout << femaleRange.Value(count).ToString() << L" ";
            }
            std::wcout << L"]" << std::endl;

            traits.height = std::make_shared<AgeSexRangeValue>(maleRange, femaleRange, traits.ageRanges);
        }

        // Weight
        {
            MultiPointValueRange maleRange;
            std::tie(found, maleRange) = loader.ReadMultiPointValueRange(L"WeightMale");
            MultiPointValueRange femaleRange;
            std::tie(found, femaleRange) = loader.ReadMultiPointValueRange(L"WeightFemale");

            std::wcout << L"    Weight =   Male [";
            for (std::size_t count = 0; count < maleRange.Count(); ++count)
            {
                std::wcout << maleRange.Value(count).ToString() << L" ";
            }
            std::wcout << L"]" << std::endl;
            std::wcout << L"    Weight = Female [";
            for (std::size_t count = 0; count < femaleRange.Count(); ++count)
            {
                std::wcout << femaleRange.Value(count).ToString() << L" ";
            }
            std::wcout << L"]" << std::endl;

            traits.weight = std::make_shared<AgeSexRangeValue>(maleRange, femaleRange, traits.ageRanges);
        }

        RacePtr newRace = RacePtr(new Race(name, traits));
        races.insert(std::make_pair(name, newRace));

        for (std::size_t count = 0; count < traits.gene.Count(); ++count)
        {
            racesByGene.insert(std::make_pair(traits.gene.Value(count), name));
        }

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

std::wstring Races::FindRaceName(__int64 value) const
{
    auto find = racesByGene.find(value);
    if (find != racesByGene.end())
    {
        return find->second;
    }
    return L"";
}

RacePtr Races::FindRace(__int64 value) const
{
    auto find = racesByGene.find(value);
    if (find != racesByGene.end())
    {
        return FindRace(find->second);
    }
    return nullptr;
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