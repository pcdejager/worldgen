#include "pch.h"
#include "ValueRange.h"

ValueRange::ValueRange()
    : minimum(0L)
    , average(0L)
    , maximum(0L)
{
    ;
}

ValueRange::ValueRange(__int64 min, __int64 avg, __int64 max)
    : minimum(min)
    , average(avg)
    , maximum(max)
{
    ;
}

bool ValueRange::operator==(const ValueRange& rhs) const
{
    return (minimum == rhs.minimum) &&
        (average == rhs.average) &&
        (maximum == rhs.maximum);
}

bool ValueRange::operator!=(const ValueRange& rhs) const
{
    return (minimum != rhs.minimum) ||
        (average != rhs.average) ||
        (maximum != rhs.maximum);
}
