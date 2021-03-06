#pragma once

#include "IGeneticOperator.h"

class GeneticRaceOperator : public IGeneticOperator
{
public:
    virtual ~GeneticRaceOperator() = default;

public:
    virtual void Crossover(const Genes & father, const Genes & mother, const GenePosition & position, Genes & result);
    virtual void Mutate(const GenePosition& position, Genes& child);
};

