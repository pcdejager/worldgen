#pragma once

#include "IPopulationFilter.h"

class PopulationFilterFactory
{
private:
    PopulationFilterFactory() = delete;
    
public:
    static IPopulationFilterPtr MaleMarry();
    static IPopulationFilterPtr FemaleMarry();
};

