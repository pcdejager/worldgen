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
    WorldTime DueDate() const;

#ifdef UNITTEST
public:
    IndividualPtr Father() const { return father; }
    IndividualPtr Mother() const { return mother; }
    WorldTime Conceived() const { return conceived; }
    TimeSpan Duration() const { return duration; }
#endif

private:
    IndividualPtr father;
    IndividualPtr mother;
    WorldTime conceived;
    TimeSpan duration;
};

