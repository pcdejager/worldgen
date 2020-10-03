#pragma once

enum class GeneType { RACE, DOUBLE };

class GenePosition
{
public:
    constexpr GenePosition(GeneType geneType, std::size_t start, std::size_t size)
        : startPosition(start)
        , geneSize(size)
        , type(geneType)
    {
        ;
    }

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
    constexpr GeneType Type() const { return type; }

private:
    std::size_t startPosition;
    std::size_t geneSize;
    GeneType type;
};

