#pragma once

#include "MultiPointValue.h"
#include "ValueRange.h"

class ConfigLoader
{
#ifdef UNITTEST
public:
    ConfigLoader(const std::vector<std::wstring>& inputLines);
#else
private:
    ConfigLoader() = delete;
#endif

public:
    ConfigLoader(const std::string& file);
private:
    ConfigLoader(const ConfigLoader&) = delete;
public:
    ~ConfigLoader() = default;
private:
    ConfigLoader& operator=(const ConfigLoader&) = delete;

public:
    bool Initialize();
    bool MoveTo(const std::wstring& propertyName);
    void MoveOn() { ++position; }
    std::tuple<bool, std::wstring> ReadString(const std::wstring& propertyName);
    std::tuple<bool, __int64> ReadInt(const std::wstring& propertyName);
    std::tuple<bool, ValueRange> ReadValueRange(const std::wstring& propertyName);
    std::tuple<bool, MultiPointValueInt> ReadMultiPointValueInt(const std::wstring& propertyName);
    std::tuple<bool, MultiPointValueRange> ReadMultiPointValueRange(const std::wstring& propertyName);
    std::tuple<bool, std::vector<__int64>> ReadIntVector(const std::wstring& propertyName);
    std::tuple<bool, std::vector<double>> ReadDoubleVector(const std::wstring& propertyName);
    std::tuple<bool, std::map<__int64, double>> ReadIntDoubleMap(const std::wstring& propertyName);
    bool End() { return (position >= lines.size()); }

#ifdef UNITTEST
public:
#else
private:
#endif
    __int64 ConvertToInt(const std::wstring& value) const;
    std::vector<__int64> ConvertToIntArray(const std::wstring& value) const;
    std::vector<double> ConvertToDoubleArray(const std::wstring& value) const;
    ValueRange ConvertToValueRange(const std::wstring& value) const;
    std::pair<__int64, double> ConvertToIntDoublePair(const std::wstring& value) const;

private:
    std::string filename;
    bool initialized;
    std::vector<std::wstring> lines;
    std::size_t position;
};

