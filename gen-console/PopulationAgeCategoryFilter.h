#pragma once

#include "IPopulationFilter.h"
#include "AgeCategory.h"

class PopulationAgeCategoryFilter
{
public:
    PopulationAgeCategoryFilter();
    virtual ~PopulationAgeCategoryFilter();

// IPopulationFilter
public:
    virtual bool Allow(Individual* individual);

public:
    void AddCategory(AgeCategory category);

#ifdef UNITTEST
public:
    std::set<AgeCategory>& AgeCategories() { return ages; }
#endif

private:
    std::set<AgeCategory> ages;
};

