#pragma once

#include <memory>

class INameGenerator;
typedef std::shared_ptr<INameGenerator> INameGeneratorPtr;

class Individual;
class Parents;

typedef std::shared_ptr<Individual> IndividualPtr;
typedef std::shared_ptr<Parents> ParentsPtr;
