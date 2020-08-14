#pragma once

#include "Types.h"
#include "WorldTime.h"

class Individual
{
private:
    Individual();
public:
    Individual(const ParentsPtr& parentsObject, const WorldTime& bornDate);
    Individual(const Individual&) = delete;
    ~Individual() = default;
    Individual& operator=(const Individual&) = delete;

public:
    /// <summary>
    /// Returns the null individual singleton
    /// </summary>
    /// <returns>The null individual which is not a valid individual</returns>
    static IndividualPtr GetNullIndividual();

public:
    bool IsValid() const;
    ParentsPtr Parents() const { return parents; }
    WorldTime Born() { return born; }
    TimeSpan Age(const WorldTime& now);

private:
    static IndividualPtr NullIndividual;

private:
    ParentsPtr parents;
    WorldTime born;

/*
* parents - mother, father (step parents over time?)
* siblings - full (dna), half mother/father side (1/2 dna), step (no dna)
* children (dna)
*/
};



