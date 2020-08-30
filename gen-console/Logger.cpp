#include "pch.h"
#include "Logger.h"
#include "WorldProperties.h"

/*static*/ LoggerPtr Logger::instance;

/*static*/ LoggerPtr Logger::GetLogger()
{
    if (instance == nullptr)
    {
        instance = LoggerPtr(new Logger());
    }
    return instance;
}

void Logger::Log(const std::wstring& message)
{
    WorldTime time = WorldProperties::Properties()->Now();
    std::wcout << L"[" << time.ToString() << L"] " << message << std::endl;
}

void Logger::Log(const std::wstring& message, const MultiPointValueInt& value)
{
    std::wstringstream stream;
    stream << message << L"[";
    for (std::size_t count = 0; count < value.Count(); ++count)
    {
        stream << value.Value(count) << L" ";
    }
    stream << L"]";
    Log(stream.str());
}

void Logger::Log(const std::wstring& message, const MultiPointValueRange& value)
{
    std::wstringstream stream;
    stream << message << L"[";
    for (std::size_t count = 0; count < value.Count(); ++count)
    {
        stream << value.Value(count).ToString() << L" ";
    }
    stream << L"]";
    Log(stream.str());
}