#include "pch.h"
#include "NumberNameGenerator.h"

NumberNameGenerator::NumberNameGenerator()
    : counter(0LL)
{
    ;
}

/*virtual*/ IndividualName NumberNameGenerator::GenerateName()
{
    ++counter;
    std::wstringstream stream;
    stream << counter;
    return IndividualName(L"First_" + stream.str(), L"Last_" + stream.str());
}