#pragma once

#include "MultiPointValue.h"

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
    std::tuple<bool, MultiPointValue> ReadMultiPointValue(const std::wstring& propertyName);
    bool End() { return (position >= lines.size()); }

#ifdef UNITTEST
public:
#else
private:
#endif
    __int64 ConvertToInt(const std::wstring& value) const;

private:
    std::string filename;
    bool initialized;
    std::vector<std::wstring> lines;
    std::size_t position;
};

