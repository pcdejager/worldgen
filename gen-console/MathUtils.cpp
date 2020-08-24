#include "pch.h"
#include "MathUtils.h"

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