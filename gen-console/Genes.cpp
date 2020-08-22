#include "pch.h"
#include "Genes.h"
#include "GenePositions.h"
#include "GrayCode.h"

Genes::Genes()
{
    Initialize();
}

void Genes::Initialize() noexcept
{
    genes = new unsigned char[NumberOfBytes];
    for (std::size_t count = 0; count < NumberOfBytes; ++count)
    {
        genes[count] = 0;
    }
}

std::size_t Genes::End() const
{
    return NumberOfBits;
}

bool Genes::ReadBool(std::size_t index) const
{
    bool result = false;
    if (index < NumberOfBits)
    {
        std::size_t byte = index / 8;
        std::size_t bit = index % 8;
        if ((genes[byte] & (1 << bit)) > 0)
        {
            result = true;
        }
    }
    return result;
}

double Genes::ReadDouble(std::size_t from, std::size_t to) const
{
    std::size_t length = to - from;
    __int64 value = 0L;
    std::size_t byte = from / 8;
    std::size_t bit = from % 8;
    unsigned char mask = 1 << bit;
    for (std::size_t index = from; index < to; ++index)
    {
        value <<= 1;
        if ((genes[byte] & mask) > 0)
        {
            value += 1L;
        }
        mask <<= 1;
        if (mask == 0)
        {
            mask = 1;
            ++byte;
        }
    }
    value = GrayCode::GrayToBinary(value);
    double max = std::pow(2.0, static_cast<double>(length)) - 1.0;
    double result = static_cast<double>(value) / max;
    return result;
}

void Genes::SetBool(std::size_t index, bool value)
{
    if (index < NumberOfBits)
    {
        std::size_t byte = index / 8;
        std::size_t bit = index % 8;
        unsigned char mask = 1 << bit;
        if (value)
        {
            genes[byte] |= mask;
        }
        else
        {
            mask = ~mask;
            genes[byte] &= mask;
        }
    }
}

void Genes::SetGenes(std::size_t from, std::size_t to, __int64 value)
{
    std::size_t index = to;
    __int64 work = GrayCode::BinaryToGray(value);
    while (index != from)
    {
        --index;
        bool enable = (work % 2) == 1;
        SetBool(index, enable);
        work /= 2;
    }
}