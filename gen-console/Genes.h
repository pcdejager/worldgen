#pragma once

#include "GenePosition.h"

class Genes
{
public:
    Genes();
    Genes(const Genes& rhs);
    Genes(Genes&& rhs) noexcept;
    ~Genes();
    Genes& operator=(const Genes& rhs);
    Genes& operator=(Genes&& rhs);

public:
    std::size_t End() const;
    bool ReadBool(std::size_t index) const;
    __int64 ReadInt(const GenePosition& position) const;
    double ReadDouble(const GenePosition& position) const;

    void SetBool(std::size_t index, bool value);
    void SetGenes(const GenePosition& position, __int64 value);
    void SetGenes(const GenePosition& position, double value);

public:
    bool operator==(const Genes& rhs) const;
    bool operator!=(const Genes& rhs) const;

private:
    void Initialize(unsigned char* genes) noexcept;

private:
    unsigned char* genes;
};

