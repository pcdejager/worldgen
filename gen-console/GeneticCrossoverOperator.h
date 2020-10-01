#pragma once
#include "IGeneticOperator.h"

class GeneticCrossoverOperator : public IGeneticOperator
{
public:
    virtual ~GeneticCrossoverOperator() = default;

public:
    virtual void Apply(const Genes & father, const Genes & mother, const GenePosition & position, Genes & result);
};

