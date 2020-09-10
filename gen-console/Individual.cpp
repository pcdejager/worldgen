#include "pch.h"
#include "Individual.h"
#include "WorldProperties.h"
#include "INameGenerator.h"

/*static*/ IndividualPtr Individual::NullIndividual = nullptr;

Individual::Individual()
    : parents(nullptr)
    , name()
    , born(WorldTime())
    , died(WorldTime())
    , genome()
    , partner(nullptr)
{
    ;
}

Individual::Individual(const ParentsPtr& parentsObject, const Genes& genes)
    : parents(parentsObject)
    , died(WorldTime())
    , genome(genes)
{
    name = WorldProperties::Properties()->NameGenerator()->GenerateName();
    born = WorldProperties::Properties()->Now();
}

/*static*/ IndividualPtr Individual::GetNullIndividual()
{
    if (NullIndividual == nullptr)
    {
        NullIndividual = IndividualPtr(new Individual());
    }
    return NullIndividual;
}

bool Individual::IsValid() const
{
    return (born > WorldTime::Undefined());
}

bool Individual::IsAlive() const
{
    if (!IsValid())
    {
        return false;
    }
    return (died == WorldTime::Undefined());
}

TimeSpan Individual::Age() const
{
    // If diead
    if (died != WorldTime::Undefined())
    {
        return died - born;
    }
    // Else alive
    WorldTime now = WorldProperties::Properties()->Now();
    if (now < born) 
    {
        return TimeSpan();
    }
    return now - born;
}

TimeSpan Individual::MaximumAge() const
{
    return genome.MaximumAge();
}

bool Individual::IsMarried() const
{
    return (partner != nullptr);
}

void Individual::Marry(const IndividualPtr& individual)
{
    partner = individual;
}

void Individual::IndividualDied(const WorldTime& time)
{
    died = time;
}