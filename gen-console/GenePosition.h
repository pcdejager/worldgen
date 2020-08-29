#pragma once

class GenePosition
{
public:
    constexpr GenePosition(std::size_t start, std::size_t size)
        : startPosition(start)
        , geneSize(size)
    {
        ;
    }

    constexpr std::size_t Start() const { return startPosition; }
    constexpr std::size_t Size() const { return geneSize; }
    constexpr std::size_t End() const { return startPosition + geneSize; }

private:
    std::size_t startPosition;
    std::size_t geneSize;
};

