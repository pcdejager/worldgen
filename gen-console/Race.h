#pragma once

#include "RacialTraits.h"

class Race
{
private:
    Race() = delete;

public:
    Race(const std::wstring& raceName, __int64 raceID, const RacialTraits& raceTraits);
    Race(const Race& rhs) = delete;
    ~Race() = default;
    Race& operator=(const Race& rhs) = delete;

public:
    std::wstring Name() const { return name; }
    __int64 ID() const { return id; }
    const RacialTraits& Traits() const { return traits; }

private:
    std::wstring name;
    __int64 id;
    RacialTraits traits;
};




