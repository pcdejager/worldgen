#pragma once

#include "INameGenerator.h"

class NumberNameGenerator :
    public INameGenerator
{
public:
    NumberNameGenerator();
    virtual ~NumberNameGenerator() = default;

public:
    virtual IndividualName GenerateName();

private:
    __int64 counter;
};

