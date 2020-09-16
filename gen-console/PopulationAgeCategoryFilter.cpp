#include "pch.h"
#include "PopulationAgeCategoryFilter.h"
#include "Individual.h"

PopulationAgeCategoryFilter::PopulationAgeCategoryFilter()
    : ages()
{
    ;
}

PopulationAgeCategoryFilter::~PopulationAgeCategoryFilter()
{
    ;
}


bool PopulationAgeCategoryFilter::Allow(Individual* individual)
{
    AgeCategory category = individual->AgeCategory();
    if (ages.find(category) != ages.end())
    {
        return true;
    }
    return false;
}

void PopulationAgeCategoryFilter::AddCategory(AgeCategory category)
{
    ages.insert(category);
}

