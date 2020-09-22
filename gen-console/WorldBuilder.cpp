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
        logger->Log(L"New individual: ", individual->Name().ToString());
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

    __int64 marriedCount = 0;
    while (population.Size() > 0)
    {
        WorldProperties::Properties()->AdvanceTime(TimeSpan(0LL, 1LL, 0LL, 0LL, 0LL));
        if (WorldProperties::Properties()->Now().Days() == 1)
        {
            logger->Log(L"New year");
        }
        population.CheckDeaths();

        Marry();
    }
}

void WorldBuilder::Marry()
{
    static IPopulationFilterPtr maleMarry = PopulationFilterFactory::MaleMarry();
    static IPopulationFilterPtr femaleMarry = PopulationFilterFactory::FemaleMarry();

    LoggerPtr logger = Logger::GetLogger();
    auto males = population.Filter(maleMarry.get());
    logger->Log(L"M: ", males.size());
    auto females = population.Filter(femaleMarry.get());
    logger->Log(L"F: ", females.size());

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
        auto femaleRace = female->Race();
        auto maleRace = male->Race();
        double chance1 = femaleRace->Traits().marry->ChanceToMarryMale(maleRace->ID());
        double chance2 = maleRace->Traits().marry->ChanceToMarryFemale(femaleRace->ID());
        double roll1 = MathUtils::RandomDouble();
        double roll2 = MathUtils::RandomDouble();
        if ((roll1 <= chance1) && (roll2 <= chance2))
        {
            logger->Log(L"Match F:" + pair.first->Name().ToString() + L" M" + pair.second->Name().ToString() + L" C:");
            female->Marry(male);
            male->Marry(female);
        }
}

}