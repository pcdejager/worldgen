#include "pch.h"
#include "WorldBuilder.h"
#include "WorldProperties.h"
#include "Types.h"
#include "Logger.h"
#include "Individual.h"
#include "Parents.h"
#include "Race.h"
#include "Marry.h"
#include "GeneGenerator.h"
#include "MathUtils.h"
#include "WorldConstants.h"
#include "PopulationStatistics.h"
#include "PopulationFilterFactory.h"
#include "MathUtils.h"

WorldBuilder::WorldBuilder()
    : population()
{
    ;
}

void WorldBuilder::Run()
{
    WorldProperties::Properties()->ResetTime();

    LoggerPtr logger = Logger::GetLogger();
    logger->Log(L"Starting world generation:");

    GenerateInitialPopulation();
}

void WorldBuilder::GenerateInitialPopulation()
{
    WorldTime finish(10, 0, 0, 0, 0);
    LoggerPtr logger = Logger::GetLogger();
    auto parents = Parents::CreateNoParents();
    for (__int64 count = 0; count < 1000LL; ++count)
    {
        Genes genes = GeneGenerator::Random();
        IndividualPtr individual = IndividualPtr(new Individual(parents, genes));
        logger->Log(L"New individual: ", individual->GetName().ToString());
        population.Add(individual);

        // Increase time
        WorldTime now = WorldProperties::Properties()->Now();
        TimeSpan diff = finish - now;
        if (diff.Ticks() < WORLD_TIME_TICKSPERSECOND)
        {
            diff = TimeSpan(WORLD_TIME_TICKSPERSECOND);
        }
        TimeSpan increase(MathUtils::RandomInt(1, diff.Ticks() / (1000LL - count)));
        WorldProperties::Properties()->AdvanceTime(increase);
    }

    logger->Log(L"Initial population done");
    PopulationStatistics stats;
    population.Visit(&stats);
    logger->Log(L"  Total=", stats.Total());
    logger->Log(L"  Males=", stats.Males());
    logger->Log(L"Females=", stats.Females());

    WorldProperties::Properties()->AdvanceToNextDay();

    __int64 marriedCount = 0;
    while (population.Size() > 0)
    {
        WorldProperties::Properties()->AdvanceTime(TimeSpan(0LL, 1LL, 0LL, 0LL, 0LL));
        if (WorldProperties::Properties()->Now().Days() == 1)
        {
            logger->Log(L"New year");
        }
        population.CheckDeaths();

        // Create
        static IPopulationFilterPtr female = PopulationFilterFactory::PossiblePregnant();
        auto possible = population.Filter(female.get());
        for (IndividualPtr mother : possible)
        {
            if (mother->GetPhysiology().IsFertile())
            {
                //logger->Log(L"Fertile: " + mother->GetName().ToString());
                if (mother->GetPartner()->GetPhysiology().IsFertile())
                {
                    //logger->Log(L"Both ok");
                    if (MathUtils::RandomDouble() < 0.01)
                    {
                        logger->Log(L"PREGNANT F:" + mother->GetName().ToString() + L" M:" + mother->GetPartner()->GetName().ToString());
                        mother->Inpregnate(mother->GetPartner(), mother);
                    }
                }
            }
        }

        // Couple
        Marry();
    }
}

void WorldBuilder::Marry()
{
    static IPopulationFilterPtr maleMarry = PopulationFilterFactory::MaleMarry();
    static IPopulationFilterPtr femaleMarry = PopulationFilterFactory::FemaleMarry();

    LoggerPtr logger = Logger::GetLogger();
    auto males = population.Filter(maleMarry.get());
    //logger->Log(L"M: ", males.size());
    auto females = population.Filter(femaleMarry.get());
    //logger->Log(L"F: ", females.size());

    // Find possible matches
    std::vector<std::pair<IndividualPtr, IndividualPtr>> possible;
    for (IndividualPtr female : females)
    {
        double looking = MathUtils::RandomDouble();
        double cutoff = 0.5;
        if (looking < cutoff)
        {
            for (IndividualPtr male : males)
            {
                looking = MathUtils::RandomDouble();
                if (looking < cutoff)
                {
                    possible.push_back(std::make_pair(female, male));
                }
            }
        }
    }

    // Marry
    for (auto pair : possible)
    {
        IndividualPtr female = pair.first;
        IndividualPtr male = pair.second;
        if (female->IsMarried() || male->IsMarried())
        {
            continue;
        }
        auto femaleRace = female->GetRace();
        auto maleRace = male->GetRace();
        double chance1 = femaleRace->GetTraits().marry->ChanceToMarryMale(maleRace->GetID());
        double chance2 = maleRace->GetTraits().marry->ChanceToMarryFemale(femaleRace->GetID());
        double roll1 = MathUtils::RandomDouble();
        double roll2 = MathUtils::RandomDouble();
        if ((roll1 <= chance1) && (roll2 <= chance2))
        {
            logger->Log(L"MARRIED F:" + pair.first->GetName().ToString() + L" M" + pair.second->GetName().ToString() + L" C:");
            female->Marry(male);
            male->Marry(female);
        }
}

}