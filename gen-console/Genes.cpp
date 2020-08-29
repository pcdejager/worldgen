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

__int64 Genes::ReadInt(const GenePosition& position) const
{
    std::size_t to = position.End();
    __int64 value = 0L;
    std::size_t byte = position.Start() / 8;
    std::size_t bit = position.Start() % 8;
    unsigned char mask = 1 << bit;
    for (std::size_t index = position.Start(); index < to; ++index)
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
    return GrayCode::GrayToBinary(value);
}

double Genes::ReadDouble(const GenePosition& position) const
{
    __int64 value = ReadInt(position);
    double max = std::pow(2.0, static_cast<double>(position.Size())) - 1.0;
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

void Genes::SetGenes(const GenePosition& position, __int64 value)
{
    std::size_t to = position.End();
    std::size_t index = to;
    __int64 work = GrayCode::BinaryToGray(value);
    while (index != position.Start())
    {
        --index;
        bool enable = (work % 2) == 1;
        SetBool(index, enable);
        work /= 2;
    }
}