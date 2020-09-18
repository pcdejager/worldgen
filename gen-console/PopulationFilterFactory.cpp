#include "pch.h"
#include "PopulationFilterFactory.h"
#include "PopulationAgeCategoryFilter.h"
#include "PopulationCompositeFilter.h"
#include "PopulationSexFilter.h"
#include "PopulationMarryFilter.h"
#include "AgeCategory.h"

/*static*/ IPopulationFilterPtr PopulationFilterFactory::MaleMarry()
{
    PopulationCompositeFilter* filter = new PopulationCompositeFilter();
    IPopulationFilterPtr result = IPopulationFilterPtr(filter);

    // Add sex
    IPopulationFilterPtr sexFilter = IPopulationFilterPtr(new PopulationSexFilter(true, false));
    filter->AddFilter(sexFilter);

    // Add not married
    IPopulationFilterPtr marryFilter = IPopulationFilterPtr(new PopulationMarryFilter(false));
    filter->AddFilter(marryFilter);

    // Add age categories
    {
        PopulationAgeCategoryFilter* newFilter = new PopulationAgeCategoryFilter();
        IPopulationFilterPtr ageFilter = IPopulationFilterPtr(newFilter);
        filter->AddFilter(ageFilter);
        auto ages = AgeCategoryUtils::MarryCategories();
        for (auto ageCategory : ages)
        {
            newFilter->AddCategory(ageCategory);
        }
    }

    return result;
}

/*static*/ IPopulationFilterPtr PopulationFilterFactory::FemaleMarry()
{
    PopulationCompositeFilter* filter = new PopulationCompositeFilter();
    IPopulationFilterPtr result = IPopulationFilterPtr(filter);

    // Add sex
    IPopulationFilterPtr sexFilter = IPopulationFilterPtr(new PopulationSexFilter(false, true));
    filter->AddFilter(sexFilter);

    // Add not married
    IPopulationFilterPtr marryFilter = IPopulationFilterPtr(new PopulationMarryFilter(false));
    filter->AddFilter(marryFilter);

    // Add age categories
    {
        PopulationAgeCategoryFilter* newFilter = new PopulationAgeCategoryFilter();
        IPopulationFilterPtr ageFilter = IPopulationFilterPtr(newFilter);
        filter->AddFilter(ageFilter);
        auto ages = AgeCategoryUtils::MarryCategories();
        for (auto ageCategory : ages)
        {
            newFilter->AddCategory(ageCategory);
        }
    }

    return result;
}
