#include "pch.h"
#include "Individual.h"

/*static*/ IndividualPtr Individual::NullIndividual = nullptr;

Individual::Individual()
    : parents(nullptr)
    , born(WorldTime())
{
    ;
}

Individual::Individual(const ParentsPtr& parentsObject, const WorldTime& bornDate)
    : parents(parentsObject)
    , born(bornDate)
{
    ;
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

TimeSpan Individual::Age(const WorldTime& now)
{
    if (now < born) 
    {
        return TimeSpan();
    }
    return now - born;
}