#pragma once

#include "Types.h"

class Genetics
{
public:
    static IndividualPtr CreateChild(const IndividualPtr& father, const IndividualPtr& mother);
};

