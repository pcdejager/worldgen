#pragma once

#include <memory>

class INameGenerator;
typedef std::shared_ptr<INameGenerator> INameGeneratorPtr;

class Individual;
class Parents;

typedef std::shared_ptr<Individual> IndividualPtr;
typedef std::shared_ptr<Parents> ParentsPtr;

class Race;
typedef std::shared_ptr<Race> RacePtr;

class AgeTraits;
typedef std::shared_ptr<AgeTraits> AgeTraitsPtr;

