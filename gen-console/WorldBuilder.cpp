#include "pch.h"
#include "WorldBuilder.h"
#include "WorldProperties.h"
#include "Types.h"
#include "Logger.h"
#include "Individual.h"
#include "Parents.h"
#include "GeneGenerator.h"
#include "MathUtils.h"
#include "WorldConstants.h"
#include "PopulationStatistics.h"
#include "PopulationFilterFactory.h"

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

    IPopulationFilterPtr maleMarry = PopulationFilterFactory::MaleMarry();
    IPopulationFilterPtr femaleMarry = PopulationFilterFactory::FemaleMarry();

    while (population.Size() > 0)
    {
        WorldProperties::Properties()->AdvanceTime(TimeSpan(0LL, 1LL, 0LL, 0LL, 0LL));
        if (WorldProperties::Properties()->Now().Days() == 1)
        {
            logger->Log(L"New year");
        }
        population.CheckDeaths();

        auto males = population.Filter(maleMarry.get());
        logger->Log(L"M: ", males.size());
        auto females = population.Filter(femaleMarry.get());
        logger->Log(L"F: ", females.size());
    }
}