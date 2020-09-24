#pragma once

#include "TimeSpan.h"

class Sex
{
private:
    Sex() = delete;
public:
    Sex(bool isMale, bool isFemale, const TimeSpan& period, double fertile);
    Sex(const Sex& rhs) = default;
    ~Sex() = default;
    Sex& operator=(const Sex& rhs) = default;

public:
    bool IsMale() const { return male; }
    bool IsFemale() const { return female; }
    bool IsFertile() const;

    TimeSpan PeriodCycle() const { return periodCycle; }

private:
    bool male;
    bool female;
    TimeSpan periodCycle;
    double fertility;
};

