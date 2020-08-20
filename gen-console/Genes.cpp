#include "pch.h"
#include "Genes.h"

constexpr std::size_t NumberOfBits = 128;
constexpr std::size_t NumberOfBytes = 128 / 8;

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
            genes[byte] &= (!mask);
        }
    }
}