#pragma once

#include "Types.h"
#include "WorldTime.h"
#include "TimeSpan.h"

class Pregnancy
{
public:
    Pregnancy(const IndividualPtr& theFather, const IndividualPtr& theMother, const WorldTime& conceivedDate, const TimeSpan& pregnancyDuration);
    ~Pregnancy() = default;

public:

#ifdef UNITTEST
public:
#endif

private:
    IndividualPtr father;
    IndividualPtr mother;
    WorldTime conceived;
    TimeSpan duration;
};

