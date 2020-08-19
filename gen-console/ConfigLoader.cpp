#include "pch.h"
#include "ConfigLoader.h"
#include "TimeSpan.h"

#ifdef UNITTEST
ConfigLoader::ConfigLoader(const std::vector<std::wstring>& inputLines) 
    : filename()
    , initialized(true)
    , lines(inputLines)
    , position(0)
{
    ;
}
#endif

ConfigLoader::ConfigLoader(const std::string& file)
    : filename(file)
    , initialized(false)
    , lines()
    , position(0)
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
    __int64 intValue = ConvertToInt(value);
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
        values.push_back(ConvertToInt(first));
        value = value.substr(find + 1);
        find = value.find(L',');
    }
    values.push_back(ConvertToInt(value));
    return std::make_tuple(true, MultiPointValue(values));
}

__int64 ConfigLoader::ConvertToInt(const std::wstring& value) const
{
    std::wstring work = value;
    if (work.empty())
    {
        return 0L;
    }
    if (work[0] == L'D')
    {
        // Duration
        work = work.substr(1);
        __int64 year = 0L;
        std::size_t index = work.find(L"Y");
        if (index != std::wstring::npos)
        {
            auto yearString = work.substr(0, index);
            year = std::stoll(yearString);
            work = work.substr(index + 1);
        }
        __int64 day = 0L;
        index = work.find(L"D");
        if (index != std::wstring::npos)
        {
            auto dayString = work.substr(0, index);
            day = std::stoll(dayString);
            work = work.substr(index + 1);
        }
        __int64 hour = 0L;
        index = work.find(L"H");
        if (index != std::wstring::npos)
        {
            auto hourString = work.substr(0, index);
            hour = std::stoll(hourString);
            work = work.substr(index + 1);
        }
        __int64 minute = 0L;
        index = work.find(L"M");
        if (index != std::wstring::npos)
        {
            auto minuteString = work.substr(0, index);
            minute = std::stoll(minuteString);
            work = work.substr(index + 1);
        }
        __int64 second = 0L;
        index = work.find(L"S");
        if (index != std::wstring::npos)
        {
            auto secondString = work.substr(0, index);
            second = std::stoll(secondString);
            work = work.substr(index + 1);
        }
        TimeSpan span(year, day, hour, minute, second);
        return span.Ticks();
    }
    else
    {
        return std::stoll(work);
    }
}
