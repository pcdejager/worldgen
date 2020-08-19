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
{
    ;
}

Individual::Individual(const ParentsPtr& parentsObject)
    : parents(parentsObject)
    , died(WorldTime())
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

TimeSpan Individual::Age()
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

void Individual::IndividualDied()
{
    died = WorldProperties::Properties()->Now();
}