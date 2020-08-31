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
    WorldTime finish(2, 0, 0, 0, 0);
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
}