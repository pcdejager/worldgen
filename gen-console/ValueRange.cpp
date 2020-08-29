#include "pch.h"
#include "ValueRange.h"
#include "MathUtils.h"

ValueRange::ValueRange()
    : minimum(0LL)
    , average(0LL)
    , maximum(0LL)
{
    ;
}

ValueRange::ValueRange(__int64 constant)
    : minimum(constant)
    , average(constant)
    , maximum(constant)
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

std::wstring ValueRange::ToString() const
{
    std::wstringstream stream;
    stream << L"[" << minimum << L"-" << average << L"-" << maximum << L"]";
    return stream.str();
}

__int64 ValueRange::Value(double value) const
{
    if (value < 0.0)
    {
        return MathUtils::ScaleInt(minimum, average, value + 1.0);
    }
    return MathUtils::ScaleInt(average, maximum, value);
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

bool ValueRange::operator<(const ValueRange& rhs) const
{
    return average < rhs.average;
}

bool ValueRange::operator<=(const ValueRange& rhs) const
{
    return average <= rhs.average;
}

bool ValueRange::operator>(const ValueRange& rhs) const
{
    return average > rhs.average;
}

bool ValueRange::operator>=(const ValueRange& rhs) const
{
    return average >= rhs.average;
}