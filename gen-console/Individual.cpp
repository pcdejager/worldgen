#include "pch.h"
#include "Individual.h"
#include "WorldProperties.h"
#include "INameGenerator.h"
#include "AgeCategory.h"
#include "Race.h"
#include "MathUtils.h"
#include "AgeTraits.h"
#include "Pregnancy.h"

/*static*/ IndividualPtr Individual::NullIndividual = nullptr;

Individual::Individual()
    : parents(nullptr)
    , name()
    , born(WorldTime())
    , died(WorldTime())
    , genome()
    , partner(nullptr)
    , pregnant(nullptr)
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

TimeSpan Individual::GetAge() const
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

TimeSpan Individual::GetMaximumAge() const
{
    return genome.MaximumAge();
}

AgeCategory Individual::GetAgeCategory() const
{
    if (!IsAlive())
    {
        return AgeCategory::Dead;
    }
    TimeSpan age = GetAge();
    if (age.IsZero())
    {
        return AgeCategory::Dead;
    }
    RacePtr race = GetRace();
    AgeTraitsPtr ageTraits = race->Traits().ageRanges;
    return ageTraits->Categorize(age);
}

bool Individual::IsMarried() const
{
    return (partner != nullptr);
}

void Individual::Marry(const IndividualPtr& individual)
{
    partner = individual;
}

bool Individual::IsPregnant() const
{
    return (pregnant != nullptr);
}

void Individual::Inpregnate(const IndividualPtr& father, const IndividualPtr& mother)
{
    WorldTime conceived = WorldProperties::Properties()->Now();
    RacePtr race = GetRace();
    double random = MathUtils::RandomDouble();
    __int64 duration = race->Traits().pregnancy.Value(random);
    pregnant = std::make_shared<Pregnancy>(father, mother, conceived, TimeSpan(duration));
}

void Individual::IndividualDied(const WorldTime& time)
{
    died = time;
}

