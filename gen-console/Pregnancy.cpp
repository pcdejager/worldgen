#include "pch.h"
#include "Pregnancy.h"

Pregnancy::Pregnancy(const IndividualPtr& theFather, const IndividualPtr& theMother, const WorldTime& conceivedDate, const TimeSpan& pregnancyDuration)
    : father(theFather)
    , mother(theMother)
    , conceived(conceivedDate)
    , duration(pregnancyDuration)
{
    ;
}
