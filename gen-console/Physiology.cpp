#include "pch.h"
#include "Physiology.h"
#include "Individual.h"
#include "Race.h"

Physiology::Physiology(const Individual* individual)
{
    race = individual->GetRace();
    periodCycle = individual->genome.GetPeriodCycle();
    fertility = individual->genome.GetFertility();
}

Physiology::Physiology(Physiology&& rhs) noexcept
    : periodCycle(rhs.periodCycle)
    , fertility(rhs.fertility)
{
    ;
}

Physiology& Physiology::operator=(Physiology&& rhs)
{
    if (&rhs != this)
    {
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
        return fertility > 0.05;
    }

    // TODO : Check period

    return false;
}

