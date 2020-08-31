#include "pch.h"
#include "IndividualName.h"

IndividualName::IndividualName(const std::wstring& first, const std::wstring& last)
    : firstName(first)
    , lastName(last)
{
    ;
}

IndividualName::IndividualName(IndividualName&& rhs) noexcept
    : firstName(std::move(rhs.firstName))
    , lastName(std::move(rhs.lastName))
{
    ;
}

IndividualName& IndividualName::operator=(IndividualName&& rhs) noexcept
{
    if (this != &rhs)
    {
        firstName = std::move(rhs.firstName);
        lastName = std::move(rhs.lastName);
    }
    return *this;
}

bool IndividualName::IsValid() const
{
    if (firstName.empty() || lastName.empty())
    {
        return false;
    }
    return true;
}

std::wstring IndividualName::ToString() const
{
    return firstName + L" " + lastName;
}