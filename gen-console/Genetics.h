#pragma once

#include "Types.h"

class Genetics
{
public:
    static IndividualPtr CreateChild(const IndividualPtr& father, const IndividualPtr& mother);

private:
    static void Initialize();

private:
    static std::map<GeneCategory, IGeneticOperatorPtr> operators;
};

