#pragma once

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
    __int64 ReadInt(std::size_t from, std::size_t size) const;
    double ReadDouble(std::size_t from, std::size_t size) const;

    void SetBool(std::size_t index, bool value);
    void SetGenes(std::size_t from, std::size_t size, __int64 value);
private:
    void Initialize() noexcept;

private:
    unsigned char* genes;
};

