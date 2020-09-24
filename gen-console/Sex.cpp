#include "pch.h"
#include "Sex.h"

Sex::Sex(bool isMale, bool isFemale, const TimeSpan& period, double fertile)
    : male(isMale)
    , female(isFemale)
    , periodCycle(period)
    , fertility(fertile)
{
    ;
}

bool Sex::IsFertile() const
{
    return fertility > 0.05;
}