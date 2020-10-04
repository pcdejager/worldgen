#pragma once

#include <memory>

enum class GeneCategory { RACE, DOUBLE };

class IPopulationFilter;
class IPopulationVisitor;

class Logger;
typedef std::shared_ptr<Logger> LoggerPtr;

class AgeSexRangeValue;
typedef std::shared_ptr<AgeSexRangeValue> AgeSexRangeValuePtr;

class AgeTraits;
typedef std::shared_ptr<AgeTraits> AgeTraitsPtr;

class INameGenerator;
typedef std::shared_ptr<INameGenerator> INameGeneratorPtr;

class Individual;
typedef std::shared_ptr<Individual> IndividualPtr;

class Pregnancy;
typedef std::shared_ptr<Pregnancy> PregnancyPtr;

class Marry;
typedef std::shared_ptr<Marry> MarryPtr;

class Parents;
typedef std::shared_ptr<Parents> ParentsPtr;

class Race;
typedef std::shared_ptr<Race> RacePtr;

class Races;
typedef std::shared_ptr<Races> RacesPtr;

class IGeneticOperator;
typedef std::shared_ptr<IGeneticOperator> IGeneticOperatorPtr;