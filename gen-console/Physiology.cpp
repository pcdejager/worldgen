#include "pch.h"
#include "Physiology.h"
#include "Individual.h"
#include "Race.h"

Physiology::Physiology(const Individual* individual)
{
    race = individual->GetRace();
    age = individual->GetAge();
    periodCycle = individual->genome.GetPeriodCycle();
    fertility = individual->genome.GetFertility();
}

Physiology::Physiology(Physiology&& rhs) noexcept
    : race(rhs.race)
    , age(rhs.age)
    , periodCycle(rhs.periodCycle)
    , fertility(rhs.fertility)
{
    ;
}

Physiology& Physiology::operator=(Physiology&& rhs) noexcept
{
    if (&rhs != this)
    {
        race = rhs.race;
        age = std::move(rhs.age);
        periodCycle = std::move(rhs.periodCycle);
        fertility = rhs.fertility;
    }
    return *this;
}

bool Physiology::IsFertile() const
{
    // If no period cycle, just check fertility
    if (periodCycle.IsZero())
    {
        return fertility > 0.01;
    }

    // Else check if character is in 20% band in the middle of the period cycle
    __int64 cyclePosition = age.Ticks() % periodCycle.Ticks();
    double value = static_cast<double>(cyclePosition) / static_cast<double>(periodCycle.Ticks());
    if ((value > 0.4) && (value < 0.6))
    {
        return fertility > 0.001;
    }
    return false;
}

