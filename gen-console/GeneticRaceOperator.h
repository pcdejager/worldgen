#pragma once

#include "IGeneticOperator.h"

class GeneticRaceOperator : public IGeneticOperator
{
public:
    virtual ~GeneticRaceOperator() = default;

public:
    virtual void Apply(const Genes & father, const Genes & mother, const GenePosition & position, Genes & result);
};

