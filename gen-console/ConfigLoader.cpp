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
    std::size_t newPosition = position;
    while (newPosition < lines.size())
    {
        if (lines[newPosition].size() > propertyName.length())
        {
            std::wstring possible = lines[newPosition].substr(0, propertyName.length());
            if (possible == propertyName)
            {
                position = newPosition;
                return true;
            }
        }
        ++newPosition;
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
        return std::make_tuple(found, 0LL);
    }
    __int64 intValue = ConvertToInt(value);
    return std::make_tuple(true, intValue);
}

std::tuple<bool, ValueRange> ConfigLoader::ReadValueRange(const std::wstring& propertyName)
{
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, ValueRange());
    }
    ValueRange rangeValue = ConvertToValueRange(value);
    return std::make_tuple(true, rangeValue);
}

std::tuple<bool, MultiPointValueInt> ConfigLoader::ReadMultiPointValueInt(const std::wstring& propertyName)
{
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, MultiPointValueInt());
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
    return std::make_tuple(true, MultiPointValueInt(values));
}

std::tuple<bool, MultiPointValueRange> ConfigLoader::ReadMultiPointValueRange(const std::wstring& propertyName)
{
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, MultiPointValueRange());
    }
    std::vector<ValueRange> values;
    auto find = value.find(L',');
    while (find != std::wstring::npos)
    {
        std::wstring first = value.substr(0, find);
        values.push_back(ConvertToValueRange(first));
        value = value.substr(find + 1);
        find = value.find(L',');
    }
    values.push_back(ConvertToValueRange(value));
    return std::make_tuple(true, MultiPointValueRange(values));
}

std::tuple<bool, std::vector<__int64>> ConfigLoader::ReadIntVector(const std::wstring& propertyName)
{
    std::vector<__int64> result;
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, result);
    }
    if ((value[0] != L'[') || (value[value.size() - 1] != L']'))
    {
        return std::make_tuple(false, result);
    }
    result = ConvertToIntArray(value.substr(1, value.length() - 2));
    return std::make_tuple(false, result);
}

std::tuple<bool, std::vector<double>> ConfigLoader::ReadDoubleVector(const std::wstring& propertyName)
{
    std::vector<double> result;
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, result);
    }
    if ((value[0] != L'[') || (value[value.size() - 1] != L']'))
    {
        return std::make_tuple(false, result);
    }
    result = ConvertToDoubleArray(value.substr(1, value.length() - 2));
    return std::make_tuple(false, result);
}

std::tuple<bool, std::map<__int64, double>> ConfigLoader::ReadIntDoubleMap(const std::wstring& propertyName)
{
    std::map<__int64, double> result;
    auto [found, value] = ReadString(propertyName);
    if (!found)
    {
        return std::make_tuple(found, result);
    }
    if ((value[0] != L'[') || (value[value.size() - 1] != L']'))
    {
        return std::make_tuple(false, result);
    }
    std::wstring work = value.substr(1, value.length() - 2);
    std::size_t index = work.find(L"][");
    while (index != std::wstring::npos)
    {
        result.insert(ConvertToIntDoublePair(work.substr(0, index)));
        work = work.substr(index + 2);
        index = work.find(L"][");
    }
    result.insert(ConvertToIntDoublePair(work));
    return std::make_tuple(true, result);
}

__int64 ConfigLoader::ConvertToInt(const std::wstring& value) const
{
    std::wstring work = value;
    if (work.empty())
    {
        return 0LL;
    }
    if (work[0] == L'D')
    {
        // Duration
        work = work.substr(1);
        __int64 year = 0LL;
        std::size_t index = work.find(L"Y");
        if (index != std::wstring::npos)
        {
            auto yearString = work.substr(0, index);
            year = std::stoll(yearString);
            work = work.substr(index + 1);
        }
        __int64 day = 0LL;
        index = work.find(L"D");
        if (index != std::wstring::npos)
        {
            auto dayString = work.substr(0, index);
            day = std::stoll(dayString);
            work = work.substr(index + 1);
        }
        __int64 hour = 0LL;
        index = work.find(L"H");
        if (index != std::wstring::npos)
        {
            auto hourString = work.substr(0, index);
            hour = std::stoll(hourString);
            work = work.substr(index + 1);
        }
        __int64 minute = 0LL;
        index = work.find(L"M");
        if (index != std::wstring::npos)
        {
            auto minuteString = work.substr(0, index);
            minute = std::stoll(minuteString);
            work = work.substr(index + 1);
        }
        __int64 second = 0LL;
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

std::vector<__int64> ConfigLoader::ConvertToIntArray(const std::wstring& value) const
{
    std::vector<__int64> result;
    std::wstring work = value;
    std::size_t index = work.find(L",");
    while (index != std::wstring::npos)
    {
        std::wstring elementString = work.substr(0, index);
        __int64 intValue = std::stoll(elementString);
        result.push_back(intValue);

        work = work.substr(index + 1);
        index = work.find(L",");
    }
    __int64 intValue = std::stoll(work);
    result.push_back(intValue);
    return result;
}

std::vector<double> ConfigLoader::ConvertToDoubleArray(const std::wstring& value) const
{
    std::vector<double> result;
    std::wstring work = value;
    std::size_t index = work.find(L",");
    while (index != std::wstring::npos)
    {
        std::wstring elementString = work.substr(0, index);
        double doubleValue = std::stod(elementString);
        result.push_back(doubleValue);

        work = work.substr(index + 1);
        index = work.find(L",");
    }
    double doubleValue = std::stod(work);
    result.push_back(doubleValue);
    return result;
}

ValueRange ConfigLoader::ConvertToValueRange(const std::wstring& value) const
{
    std::wstring work = value;
    if (work.empty())
    {
        return ValueRange();
    }
    if (work[0] == L'[')
    {
        std::size_t index1 = work.find(L"-");
        std::size_t index2 = work.find(L"-", index1 + 1);
        std::size_t index3 = work.find(L"]", index2 + 1);
        if ((index1 != std::wstring::npos) &&
            (index2 != std::wstring::npos) &&
            (index3 != std::wstring::npos))
        {
            __int64 minimum = ConvertToInt(work.substr(1, index1 - 1));
            __int64 average = ConvertToInt(work.substr(index1 + 1, index2 - index1 - 1));
            __int64 maximum = ConvertToInt(work.substr(index2 + 1, index3 - index1 - 1));

            ValueRange test(minimum, average, maximum);
            return test;
        }
    }
    return ValueRange();
}

std::pair<__int64, double> ConfigLoader::ConvertToIntDoublePair(const std::wstring& value) const
{
    std::size_t index = value.find(L",");
    if (index != std::wstring::npos)
    {
        __int64 value1 = std::stoll(value.substr(0, index));
        double value2 = std::stod(value.substr(index + 1));
        return std::make_pair(value1, value2);
    }
    return std::make_pair(0LL, 0.0);
}