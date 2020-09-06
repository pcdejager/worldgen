#include "pch.h"
#include "Races.h"
#include "Race.h"
#include "ConfigLoader.h"
#include "RacialTraits.h"
#include "TimeSpan.h"
#include "AgeTraits.h"
#include "AgeSexRangeValue.h"
#include "Logger.h"

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
    proceateMatrix.Reset();

    LoggerPtr logger = Logger::GetLogger();
    std::string filename = "E:\\Dev\\worldgen\\gen-console\\Config\\Races.txt";
    ConfigLoader loader(filename);
    if (!loader.Initialize())
    {
        return; // failure?
    }

    logger->Log(L"Reading Races:");
    std::wifstream file(filename);

    std::size_t counter = 0;
    bool ok = loader.MoveTo(L"RaceName");
    while (ok)
    {
        counter++;
        logger->Log(L"  Race #", counter);

        auto [found, name] = loader.ReadString(L"RaceName");
        logger->Log(L"    Name: ", name);

        __int64 id = -1;
        std::tie(found, id) = loader.ReadInt(L"RaceID");

        RacialTraits traits;

        // Gene
        std::tie(found, traits.gene) = loader.ReadMultiPointValueInt(L"Gene");
        logger->Log(L"    Gene = ", traits.gene);

        // AgeRanges
        MultiPointValueInt ages;
        std::tie(found, ages) = loader.ReadMultiPointValueInt(L"AgeRanges");
        logger->Log(L"    AgeRanges = ", ages);
        traits.ageRanges = std::make_shared<AgeTraits>(ages);

        // Pregnancy
        std::tie(found, traits.pregnancy) = loader.ReadMultiPointValueInt(L"Pregnancy");
        logger->Log(L"    Pregnancy = ", traits.pregnancy);

        // Height
        {
            MultiPointValueRange maleRange;
            std::tie(found, maleRange) = loader.ReadMultiPointValueRange(L"HeightMale");
            MultiPointValueRange femaleRange;
            std::tie(found, femaleRange) = loader.ReadMultiPointValueRange(L"HeightFemale");
            logger->Log(L"    Height =   Male [", maleRange);
            logger->Log(L"    Height = Female [", femaleRange);

            traits.height = std::make_shared<AgeSexRangeValue>(maleRange, femaleRange, traits.ageRanges);
        }

        // Weight
        {
            MultiPointValueRange maleRange;
            std::tie(found, maleRange) = loader.ReadMultiPointValueRange(L"WeightMale");
            MultiPointValueRange femaleRange;
            std::tie(found, femaleRange) = loader.ReadMultiPointValueRange(L"WeightFemale");
            logger->Log(L"    Weight =   Male [", maleRange);
            logger->Log(L"    Weight = Female [", femaleRange);

            traits.weight = std::make_shared<AgeSexRangeValue>(maleRange, femaleRange, traits.ageRanges);
        }

        // Marry
        {
            std::tie(found, traits.marry) = loader.ReadIntDoubleMap(L"Marry");
            std::wstringstream result;
            for (auto item : traits.marry)
            {
                result << L"[" << item.first << "," << item.second << "]";
            }
            logger->Log(L"    Marry = ", result.str());
        }

        RacePtr newRace = RacePtr(new Race(name, id, traits));
        races.insert(std::make_pair(id, newRace));
        racesByName.insert(std::make_pair(name, id));

        for (std::size_t count = 0; count < traits.gene.Count(); ++count)
        {
            racesByGene.insert(std::make_pair(traits.gene.Value(count), id));
        }

        loader.MoveOn();
        ok = loader.MoveTo(L"RaceName");
    }

    for (auto maleRaceID : races)
    {
        for (auto femaleRaceID : races)
        {
            bool found = false;
            std::vector<__int64> raceIDs;
            {
                std::wstringstream property;
                property << L"MateResultM" << maleRaceID.first << L"F" << femaleRaceID.first;
                std::tie(found, raceIDs) = loader.ReadIntVector(property.str());
            }
            std::vector<double> chance;
            {
                std::wstringstream property;
                property << L"MateChanceM" << maleRaceID.first << L"F" << femaleRaceID.first;
                std::tie(found, chance) = loader.ReadDoubleVector(property.str());
            }
            proceateMatrix.Add(maleRaceID.first, femaleRaceID.first, raceIDs, chance);
        }
    }
    proceateMatrix.LogMatrix();

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
        result.push_back(item.second->Name());
    }
    return result;
}

bool Races::HasRace(const std::wstring& name) const
{
    if (racesByName.find(name) != racesByName.end())
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
        __int64 id = find->second;
        auto raceFind = races.find(id);
        if (raceFind != races.end())
        {
            return raceFind->second->Name();
        }
    }
    return L"";
}

RacePtr Races::FindRaceByGene(__int64 value) const
{
    auto find = racesByGene.find(value);
    if (find != racesByGene.end())
    {
        return FindRaceByID(find->second);
    }
    return nullptr;
}

RacePtr Races::FindRaceByID(__int64 id) const
{
    auto find = races.find(id);
    if (find != races.end())
    {
        return find->second;
    }
    return nullptr;
}

RacePtr Races::FindRaceByName(const std::wstring& name) const
{
    auto find = racesByName.find(name);
    if (find != racesByName.end())
    {
        __int64 raceID = find->second;
        auto raceFind = races.find(raceID);
        if (raceFind != races.end())
        {
            return raceFind->second;
        }
    }
    return nullptr;
}