#pragma once

#include "WorldTime.h"

class Individual
{
public:
    Individual(const WorldTime& bornDate);
    Individual(const Individual&) = delete;
    ~Individual() = default;
    Individual& operator=(const Individual&) = delete;

public:
    WorldTime Born() { return born; }
    TimeSpan Age(const WorldTime& now);

private:
    WorldTime born;
};

