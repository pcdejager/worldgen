#pragma once

#include "Types.h"

class IPopulationVisitor
{
protected:
    IPopulationVisitor() = default;

public:
    virtual ~IPopulationVisitor() = default;

public:
    virtual void VisitIndividual(const IndividualPtr& individual) = 0;
};