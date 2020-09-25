#pragma once

#include "TimeSpan.h"
#include "Types.h"

class Physiology
{
private:
    Physiology() = delete;
public:
    Physiology(const Individual* individual);
    Physiology(const Physiology& rhs) = default;
    Physiology(Physiology&& rhs) noexcept;
    ~Physiology() = default;
    Physiology& operator=(const Physiology& rhs) = default;
    Physiology& operator=(Physiology&& rhs);

public:
    bool IsFertile() const;

#ifdef UNITTEST
public:
    RacePtr Race() const { return race; }
    TimeSpan PeriodCycle() const { return periodCycle; }
    double Fertility() const { return fertility; }
#endif

private:
    RacePtr race;
    TimeSpan periodCycle;
    double fertility;
};

