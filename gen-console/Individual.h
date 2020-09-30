#pragma once

#include "Types.h"
#include "IndividualName.h"
#include "WorldTime.h"
#include "Genome.h"
#include "Genes.h"
#include "Sex.h"
#include "AgeCategory.h"
#include "Physiology.h"

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

    ParentsPtr GetParents() const { return parents; }
    IndividualName GetName() const { return name; }
    WorldTime GetBorn() const { return born; }
    WorldTime GetDied() const { return died; }

    /// <summary>
    /// Returns the age of the individual
    /// Note: If the individual is dead, the age at death will be returned
    /// Note: If born date is in the future, an age of 0 will be returned
    /// </summary>
    /// <returns>Age of the individual</returns>
    TimeSpan GetAge() const;    
    TimeSpan GetMaximumAge() const;
    AgeCategory GetAgeCategory() const;

    RacePtr GetRace() const { return genome.GetRace(); }
    Sex GetSex() const { return genome.GetSex(); }
    Physiology GetPhysiology() const { return Physiology(this); }

public:
    bool IsMarried() const;
    IndividualPtr GetPartner() const { return partner; }
    void Marry(const IndividualPtr& individual);

public:
    bool IsPregnant() const;
    void Inpregnate(const IndividualPtr& father, const IndividualPtr& mother);

private:
    friend class Physiology;
    friend class Population;
    friend class Genetics;

    void IndividualDied(const WorldTime& time);

private:
    static IndividualPtr NullIndividual;

private:
    ParentsPtr parents;
    IndividualName name;
    WorldTime born;
    WorldTime died;
    Genome genome;

    IndividualPtr partner;

    PregnancyPtr pregnant;
/*
* parents - mother, father (step parents over time?)
* siblings - full (dna), half mother/father side (1/2 dna), step (no dna)
* children (dna)
*/
};



