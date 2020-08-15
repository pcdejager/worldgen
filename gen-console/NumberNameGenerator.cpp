#include "pch.h"
#include "NumberNameGenerator.h"

NumberNameGenerator::NumberNameGenerator()
    : counter(0L)
{
    ;
}

/*virtual*/ std::wstring NumberNameGenerator::GenerateName()
{
    ++counter;
    std::wstringstream stream;
    stream << L"Name_" << counter;
    return stream.str();
}