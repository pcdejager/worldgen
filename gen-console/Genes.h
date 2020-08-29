#pragma once

#include "GenePosition.h"

class Genes
{
public:
    Genes();
    Genes(const Genes& rhs) = default;
    ~Genes() = default;
    Genes& operator=(const Genes& rhs) = default;

public:
    std::size_t End() const;
    bool ReadBool(std::size_t index) const;
    __int64 ReadInt(const GenePosition& position) const;
    double ReadDouble(const GenePosition& position) const;

    void SetBool(std::size_t index, bool value);
    void SetGenes(const GenePosition& position, __int64 value);
    void SetGenes(const GenePosition& position, double value);
private:
    void Initialize() noexcept;

private:
    unsigned char* genes;
};

