#pragma once

class IndividualName
{
public:
    IndividualName() = default;
    IndividualName(const std::wstring& first, const std::wstring& last);
    IndividualName(const IndividualName&) = default;
    IndividualName(IndividualName&& rhs) noexcept;
    ~IndividualName() = default;

    IndividualName& operator=(const IndividualName&) = default;
    IndividualName& operator=(IndividualName&& rhs) noexcept;

public:
    bool IsValid() const;
    std::wstring FirstName() const { return firstName; }
    std::wstring LastName() const { return lastName; }
    std::wstring ToString() const;
private:
    std::wstring firstName;
    std::wstring lastName;
};

