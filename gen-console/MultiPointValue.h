#pragma once

class MultiPointValue
{
public:
    MultiPointValue();
    MultiPointValue(const std::vector<__int64>& input);
    MultiPointValue(const MultiPointValue&) = default;
    MultiPointValue(MultiPointValue&& rhs) noexcept;
    ~MultiPointValue() = default;

    MultiPointValue& operator=(const MultiPointValue&) = default;
    MultiPointValue& operator=(MultiPointValue&& rhs) noexcept;

public:
    void Set(const std::vector<__int64>& input);

    std::size_t Count() const { return values.size(); }
    __int64 Minimum() const;
    __int64 Maximum() const;
    __int64 Value(std::size_t index) const;

private:
    std::vector<__int64> values;
};

