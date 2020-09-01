#pragma once

#include "Types.h"
#include "IndividualName.h"
#include "WorldTime.h"
#include "Genome.h"
#include "Genes.h"
#include "Sex.h"

class Individual
{
private:
    Individual();
public:
    Individual(const ParentsPtr& parentsObject, const Genes& genes);
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
    IndividualName Name() const { return name; }
    WorldTime Born() { return born; }
    WorldTime Died() { return died; }

    /// <summary>
    /// Returns the age of the individual
    /// Note: If the individual is dead, the age at death will be returned
    /// Note: If born date is in the future, an age of 0 will be returned
    /// </summary>
    /// <returns>Age of the individual</returns>
    TimeSpan Age() const;

    Sex Sex() const { return genome.GetSex(); }

private:
    friend class Population;
    void IndividualDied();

private:
    static IndividualPtr NullIndividual;

private:
    ParentsPtr parents;
    IndividualName name;
    WorldTime born;
    WorldTime died;
    Genome genome;
/*
* parents - mother, father (step parents over time?)
* siblings - full (dna), half mother/father side (1/2 dna), step (no dna)
* children (dna)
*/
};



