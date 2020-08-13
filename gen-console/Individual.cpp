#include "pch.h"
#include "Individual.h"

Individual::Individual(const WorldTime& bornDate)
    : born(bornDate)
{
    ;
}

TimeSpan Individual::Age(const WorldTime& now)
{
    if (now < born) 
    {
        return TimeSpan();
    }
    return now - born;
}