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

Individual::Individual(const ParentsPtr& parentsObject, const WorldTime& bornDate)
    : parents(parentsObject)
    , born(bornDate)
    , died(WorldTime())
{
    name = WorldProperties::Properties()->NameGenerator()->GenerateName();
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

TimeSpan Individual::Age(const WorldTime& now)
{
    if (now < born) 
    {
        return TimeSpan();
    }
    return now - born;
}

void Individual::IndividualDied(const WorldTime& date)
{
    died = date;
}