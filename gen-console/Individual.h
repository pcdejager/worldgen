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
    /// <summary>
    /// Check to see if the individual is valid (born date is set)
    /// Note: The NullIndividual is considered invalid
    /// </summary>
    /// <returns>True if valid, else false</returns>
    bool IsValid() const;

    /// <summary>
    /// Check to see if the individual is alive
    /// Note: If the individual is invalid, it is not considered alive
    /// </summary>
    /// <returns>True if alive, else false</returns>
    bool IsAlive() const;

    ParentsPtr Parents() const { return parents; }
    WorldTime Born() { return born; }
    TimeSpan Age(const WorldTime& now);

private:
    friend class Population;
    void Died(const WorldTime& date);

private:
    static IndividualPtr NullIndividual;

private:
    ParentsPtr parents;
    WorldTime born;
    WorldTime died;
/*
* parents - mother, father (step parents over time?)
* siblings - full (dna), half mother/father side (1/2 dna), step (no dna)
* children (dna)
*/
};



