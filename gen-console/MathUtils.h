#pragma once

class MathUtils
{
private:
    MathUtils() = delete;
    ~MathUtils() = delete;

public:
    static __int64 ScaleInt(__int64 min, __int64 max, double index);

    static __int64 RandomInt(__int64 min, __int64 max);
    static double RandomDouble();
private:
    static std::mt19937 randomGenerator;
};

