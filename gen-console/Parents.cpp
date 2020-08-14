#include "pch.h"
#include "Parents.h"
#include "Individual.h"

Parents::Parents(const IndividualPtr& bioFather, const IndividualPtr& bioMother)
    : biologicalFather(bioFather)
    , biologicalMother(bioMother)
{
    ;
}

/*static*/ ParentsPtr Parents::CreateNoParents()
{
    return std::make_shared<Parents>(Individual::GetNullIndividual(), Individual::GetNullIndividual());
}
