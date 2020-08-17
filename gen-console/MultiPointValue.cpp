#include "pch.h"
#include "MultiPointValue.h"

MultiPointValue::MultiPointValue()
    : values()
{
    ;
}

MultiPointValue::MultiPointValue(const std::vector<__int64>& input)
    : values(input)
{
    std::sort(values.begin(), values.end());
}

MultiPointValue::MultiPointValue(MultiPointValue&& rhs) noexcept
    : values(std::move(rhs.values))
{
    ;
}

MultiPointValue& MultiPointValue::operator=(MultiPointValue&& rhs) noexcept
{
    if (this != &rhs)
    {
        values = std::move(rhs.values);
    }
    return *this;
}

void MultiPointValue::Set(const std::vector<__int64>& input)
{
    values = input;
    std::sort(values.begin(), values.end());
}

__int64 MultiPointValue::Minimum() const
{
    if (values.empty())
    {
        return 0L;
    }
    return values[0];
}

__int64 MultiPointValue::Maximum() const
{
    if (values.empty())
    {
        return 0L;
    }
    return values[values.size() - 1];
}

__int64 MultiPointValue::Value(std::size_t index) const 
{ 
    if (index >= values.size())
    {
        return 0L;
    }
    return values[index]; 
}
