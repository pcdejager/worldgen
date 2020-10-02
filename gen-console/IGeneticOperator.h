#pragma once

#include "Genes.h"
#include "GenePosition.h"

class IGeneticOperator
{
public:
    virtual ~IGeneticOperator() = default;

public:
    virtual void Crossover(const Genes& father, const Genes& mother, const GenePosition& position, Genes& result) = 0;
    virtual void Mutate(const GenePosition& position, Genes& child) = 0;
};

typedef std::shared_ptr<IGeneticOperator> IGeneticOperatorPtr;