#pragma once

class ValueRange
{
public:
    ValueRange();
    ValueRange(__int64 constant);
    ValueRange(__int64 min, __int64 avg, __int64 max);
    ValueRange(const ValueRange&) = default;
    ValueRange(ValueRange&& rhs) = default;
    ~ValueRange() = default;

    ValueRange& operator=(const ValueRange&) = default;
    ValueRange& operator=(ValueRange&&) = default;

public:
    __int64 Minimum() { return minimum; }
    __int64 Average() { return average; }
    __int64 Maximum() { return maximum; }

    /// <summary>
    /// Get the value in the range min to max given a double value that
    /// can range from -1.0 to 1.0 where:
    /// Value = -1.0 returns minimum
    /// Value = 0.0 returns average
    /// Value = 1.0 returns maximum
    /// </summary>
    /// <param name="value">The value index</param>
    /// <returns></returns>
    __int64 Value(double value);

    std::wstring ToString() const;

public:
    bool operator==(const ValueRange& rhs) const;
    bool operator!=(const ValueRange& rhs) const;
    bool operator<(const ValueRange& rhs) const;
    bool operator<=(const ValueRange& rhs) const;
    bool operator>(const ValueRange& rhs) const;
    bool operator>=(const ValueRange& rhs) const;

private:
    __int64 minimum;
    __int64 average;
    __int64 maximum;
};

