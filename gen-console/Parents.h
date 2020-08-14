#pragma once

#include "Types.h"

class Parents
{
public:
    Parents(const IndividualPtr& bioFather, const IndividualPtr& bioMother);
    Parents(const Parents&) = delete;
    virtual ~Parents() = default;
    Parents& operator=(const Parents&) = delete;

public:
    /// <summary>
    /// Creates a parents container with null individual father and mother
    /// </summary>
    /// <returns>Container with null parents</returns>
    static ParentsPtr CreateNoParents();

public:
    IndividualPtr BiologicalFather() const { return biologicalFather; }
    IndividualPtr BiologicalMother() const { return biologicalMother; }

private:
    IndividualPtr biologicalFather;
    IndividualPtr biologicalMother;
};

