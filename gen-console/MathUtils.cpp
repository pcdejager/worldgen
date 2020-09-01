#include "pch.h"
#include "MathUtils.h"

/*static*/ std::mt19937 MathUtils::randomGenerator = std::mt19937(std::random_device()());

/*static*/ __int64 MathUtils::ScaleInt(__int64 min, __int64 max, double index)
{
    if (index <= 0.0)
    {
        return min;
    }
    else if (index >= 1.0)
    {
        return max;
    }
    double temp = static_cast<double>(min) + (index * (static_cast<double>(max - min)));
    return static_cast<__int64>(temp);
}

/*static*/ __int64 MathUtils::RandomInt(__int64 min, __int64 max)
{
    std::uniform_int_distribution<__int64> raceDistribution(min, max);
    return raceDistribution(randomGenerator);
}

/*static*/ double MathUtils::RandomDouble()
{
    std::uniform_real<> realDistribution(0.0, 1.0);
    return realDistribution(randomGenerator);
}
