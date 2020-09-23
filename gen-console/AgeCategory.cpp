#include "pch.h"
#include "AgeCategory.h"

/*static*/ AgeCategory AgeCategoryUtils::CategoryBefore(AgeCategory age)
{
    switch (age)
    {
    case AgeCategory::NewBorn: return AgeCategory::Dead;
    case AgeCategory::Toddler: return AgeCategory::NewBorn;
    case AgeCategory::Child: return AgeCategory::Toddler;
    case AgeCategory::Teenager: return AgeCategory::Child;
    case AgeCategory::YoungAdult: return AgeCategory::Teenager;
    case AgeCategory::Adult: return AgeCategory::YoungAdult;
    case AgeCategory::OldAdult: return AgeCategory::Adult;
    case AgeCategory::Elder: return AgeCategory::OldAdult;
    default:
        return AgeCategory::Dead;
    }
}

/*static*/ AgeCategory AgeCategoryUtils::CategoryAfter(AgeCategory age)
{
    switch (age)
    {
    case AgeCategory::NewBorn: return AgeCategory::Toddler;
    case AgeCategory::Toddler: return AgeCategory::Child;
    case AgeCategory::Child: return AgeCategory::Teenager;
    case AgeCategory::Teenager: return AgeCategory::YoungAdult;
    case AgeCategory::YoungAdult: return AgeCategory::Adult;
    case AgeCategory::Adult: return AgeCategory::OldAdult;
    case AgeCategory::OldAdult: return AgeCategory::Elder;
    case AgeCategory::Elder: return AgeCategory::Dead;
    default:
        return AgeCategory::Dead;
    }
}

/*static*/ std::vector<AgeCategory> AgeCategoryUtils::AliveCategories()
{
    std::vector<AgeCategory> result =
    {
        AgeCategory::NewBorn,
        AgeCategory::Toddler,
        AgeCategory::Child,
        AgeCategory::Teenager,
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult,
        AgeCategory::Elder
    };
    return result;
}

/*static*/ std::vector<AgeCategory> AgeCategoryUtils::MarryCategories()
{
    std::vector<AgeCategory> result =
    {
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult,
        AgeCategory::Elder
    };
    return result;
}

/*static*/ std::vector<AgeCategory> AgeCategoryUtils::PregnantCategories()
{
    std::vector<AgeCategory> result =
    {
        AgeCategory::YoungAdult,
        AgeCategory::Adult,
        AgeCategory::OldAdult
    };
    return result;
}