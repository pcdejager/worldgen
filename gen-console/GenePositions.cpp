#include "pch.h"
#include "GenePositions.h"

/*static*/ std::map<GeneType, GenePosition> GenePositions::genes;

/*static*/ GenePosition GenePositions::GetPosition(GeneType type)
{
    Initialize();
    auto iter = genes.find(type);
    if (iter == genes.end())
    {
        return GenePosition(GeneCategory::DOUBLE, 0, 0);
    }
    return iter->second;
}

/*static*/ const std::map<GeneType, GenePosition>& GenePositions::AllGenes()
{
    Initialize();
    return genes;
}

/*static*/ void GenePositions::Initialize()
{
    if (genes.empty())
    {
        constexpr GenePosition race(GeneCategory::RACE, 0, 2);
        constexpr GenePosition sex(GeneCategory::DOUBLE, race.End(), 8); 
        constexpr GenePosition period(GeneCategory::DOUBLE, sex.End(), 8); 
        constexpr GenePosition fertility(GeneCategory::DOUBLE, period.End(), 8); 
        constexpr GenePosition height(GeneCategory::DOUBLE, fertility.End(), 16); 
        constexpr GenePosition weight(GeneCategory::DOUBLE, height.End(), 16); 
        constexpr GenePosition maximumLife(GeneCategory::DOUBLE, weight.End(), 16); 


        genes.insert(std::make_pair(GeneType::Race, race));
        genes.insert(std::make_pair(GeneType::Sex, sex));
        genes.insert(std::make_pair(GeneType::Period, period));
        genes.insert(std::make_pair(GeneType::Fertility, fertility));
        genes.insert(std::make_pair(GeneType::Height, height));
        genes.insert(std::make_pair(GeneType::Weight, weight));
        genes.insert(std::make_pair(GeneType::MaximumLife, maximumLife));


    }
}