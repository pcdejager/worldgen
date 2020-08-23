#pragma once

#include "RacialTraits.h"

class Race
{
private:
    Race() = delete;

public:
    Race(const std::wstring& raceName, const RacialTraits& raceTraits);
    Race(const Race& rhs) = delete;
    ~Race() = default;
    Race& operator=(const Race& rhs) = delete;

public:
    std::wstring Name() const { return name; }

private:
    std::wstring name;
    RacialTraits traits;
};




