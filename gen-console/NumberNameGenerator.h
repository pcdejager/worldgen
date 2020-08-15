#pragma once

#include "INameGenerator.h"

class NumberNameGenerator :
    public INameGenerator
{
public:
    NumberNameGenerator();
    virtual ~NumberNameGenerator() = default;

public:
    virtual std::wstring GenerateName();

private:
    __int64 counter;
};

