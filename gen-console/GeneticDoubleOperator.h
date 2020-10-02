#pragma once
#include "IGeneticOperator.h"

class GeneticDoubleOperator : public IGeneticOperator
{
public:
    GeneticDoubleOperator(double mutate = 0.001);
    virtual ~GeneticDoubleOperator() = default;

public:
    virtual void Crossover(const Genes & father, const Genes & mother, const GenePosition & position, Genes & result);
    virtual void Mutate(const GenePosition& position, Genes& child);

private:
    double mutation;
};

