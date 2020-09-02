#pragma once

#include "IPopulationVisitor.h"

class PopulationStatistics : public IPopulationVisitor
{
public:
    PopulationStatistics();
    virtual ~PopulationStatistics() = default;

public:
    void Reset();

public:
    unsigned __int64 Total() const { return total; }
    unsigned __int64 Males() const { return males; }
    unsigned __int64 Females() const { return females; }

public:
    virtual void VisitIndividual(const IndividualPtr& individual);

private:
    unsigned __int64 total;
    unsigned __int64 males;
    unsigned __int64 females;
};

