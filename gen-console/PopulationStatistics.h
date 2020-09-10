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
    unsigned __int64 MalesOfRace(__int64 raceID) const;
    unsigned __int64 FemalesOfRace(__int64 raceID) const;

public:
    virtual void VisitIndividual(const IndividualPtr& individual);

private:
    void SetupContainers();

private:
    unsigned __int64 total;
    unsigned __int64 males;
    unsigned __int64 females;
    std::map<__int64, unsigned __int64> maleRace;
    std::map<__int64, unsigned __int64> femaleRace;
};

