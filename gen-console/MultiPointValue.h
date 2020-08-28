#pragma once

#include "ValueRange.h"

template<class T>
class MultiPointValue
{
public:
    MultiPointValue()
        : values()
    {
        ;
    }
    MultiPointValue(const std::vector<T>& input)
        : values(input)
    {
        ;
    }
    MultiPointValue(const MultiPointValue&) = default;
    MultiPointValue(MultiPointValue&& rhs) = default;
    ~MultiPointValue() = default;

    MultiPointValue& operator=(const MultiPointValue&) = default;
    MultiPointValue& operator=(MultiPointValue&& rhs) = default;

public:
    void Set(const std::vector<T>& input)
    {
        values = input;
    }

    std::size_t Count() const { return values.size(); }
    T Minimum() const
    {
        if (values.empty())
        {
            return T(0);
        }
        return values[0];
    }
    T Maximum() const
    {
        if (values.empty())
        {
            return T(0);
        }
        return values[values.size() - 1];
    }
    T Value(std::size_t index) const
    {
        if (index >= values.size())
        {
            return T(0);
        }
        return values[index];
    }

private:
    std::vector<T> values;
};

typedef MultiPointValue<__int64> MultiPointValueInt;
typedef MultiPointValue<ValueRange> MultiPointValueRange;