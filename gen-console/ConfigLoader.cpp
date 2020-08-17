#include "pch.h"
#include "ConfigLoader.h"

ConfigLoader::ConfigLoader(const std::string& file)
    : filename(file)
    , initialized(false)
    , lines()
{
    ;
}

bool ConfigLoader::Initialize()
{
    if (initialized)
    {
        return false;
    }
    std::wifstream stream(filename);
    while (!stream.eof())
    {
        std::wstring line;
        stream >> line;
        if (!line.empty())
        {
            if (line[0] != L'#')
            {
                lines.push_back(line);
            }
        }
    }
    initialized = true;
    return true;
}

bool ConfigLoader::MoveTo(const std::wstring& propertyName)
{
    if (!initialized)
    {
        return false;
    }
    if (position >= lines.size())
    {
        return false;
    }
    while (position < lines.size())
    {
        if (lines[position].size() > propertyName.length())
        {
            std::wstring possible = lines[position].substr(0, propertyName.length());
            if (possible == propertyName)
            {
                return true;
            }
        }
        ++position;
    }
    return false;
}

std::tuple<bool, std::wstring> ConfigLoader::ReadString(const std::wstring& propertyName)
{
    if (!initialized)
    {
        return std::make_tuple(false, std::wstring(L""));
    }
    if (position >= lines.size())
    {
        return std::make_tuple(false, std::wstring(L""));
    }
    std::size_t count = position;
    while (count < lines.size())
    {
        if (lines[count].size() > propertyName.length())
        {
            std::wstring possible = lines[count].substr(0, propertyName.length());
            if (possible == propertyName)
            {
                std::wstring result = lines[count].substr(propertyName.length() + 1);
                return std::make_tuple(true, result);
            }
        }
        ++count;
    }
    return std::make_tuple(false, std::wstring(L""));
}

std::tuple<bool, __int64> ConfigLoader::ReadInt(const std::wstring& propertyName)
{
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, 0L);
    }
    __int64 intValue = std::stoll(value);
    return std::make_tuple(true, intValue);
}

std::tuple<bool, MultiPointValue> ConfigLoader::ReadMultiPointValue(const std::wstring& propertyName)
{
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, MultiPointValue());
    }
    std::vector<__int64> values;
    auto find = value.find(L',');
    while (find != std::wstring::npos)
    {
        std::wstring first = value.substr(0, find);
        values.push_back(std::stoll(first));
        value = value.substr(find + 1);
        find = value.find(L',');
    }
    values.push_back(std::stoll(value));
    return std::make_tuple(true, MultiPointValue(values));
}
