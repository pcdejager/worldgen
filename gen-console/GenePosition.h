#pragma once

#include "Types.h"

class GenePosition
{
public:
    constexpr GenePosition(GeneCategory GeneCategory, std::size_t start, std::size_t size)
        : startPosition(start)
        , geneSize(size)
        , type(GeneCategory)
    {
        ;
    }

    constexpr GenePosition(const GenePosition& rhs) = default;
    constexpr GenePosition& operator=(const GenePosition& rhs) = default;

    constexpr bool operator==(const GenePosition& rhs) const
    {
        return ((startPosition == rhs.startPosition) &&
            (geneSize == rhs.geneSize) &&
            (type == rhs.type));
    }

    constexpr bool operator!=(const GenePosition& rhs) const
    {
        return ((startPosition != rhs.startPosition) ||
            (geneSize != rhs.geneSize) ||
            (type != rhs.type));
    }

    constexpr std::size_t Start() const { return startPosition; }
    constexpr std::size_t Size() const { return geneSize; }
    constexpr std::size_t End() const { return startPosition + geneSize; }
    constexpr GeneCategory Type() const { return type; }

private:
    std::size_t startPosition;
    std::size_t geneSize;
    GeneCategory type;
};

