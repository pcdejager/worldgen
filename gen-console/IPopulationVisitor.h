#pragma once

class Individual;

class IPopulationVisitor
{
protected:
    IPopulationVisitor() = default;

public:
    virtual ~IPopulationVisitor() = default;

public:
    virtual void VisitIndividual(Individual* individual) = 0;
};