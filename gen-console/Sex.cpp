#include "pch.h"
#include "Sex.h"

Sex::Sex(bool isMale, bool isFemale, double fertile)
    : male(isMale)
    , female(isFemale)
    , fertility(fertile)
{
    ;
}

bool Sex::IsFertile() const
{
    return fertility > 0.05;
}