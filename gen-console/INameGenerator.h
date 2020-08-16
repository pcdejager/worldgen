#pragma once

#include "IndividualName.h"

class INameGenerator
{
protected:
    INameGenerator() = default;
public:
    virtual ~INameGenerator() = default;

private:
    INameGenerator(const INameGenerator&) = delete;
    INameGenerator& operator=(const INameGenerator&) = delete;

public:
    virtual IndividualName GenerateName() = 0;
};