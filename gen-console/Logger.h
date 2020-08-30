#pragma once

#include "Types.h"
#include "MultiPointValue.h"

class Logger
{
private:
    Logger() = default;

public:
    ~Logger() = default;

public:
    static LoggerPtr GetLogger();

public:
    void Log(const std::wstring& message);
    void Log(const std::wstring& message, const MultiPointValueInt& value);
    void Log(const std::wstring& message, const MultiPointValueRange& value);
    template<class T> void Log(const std::wstring& message, const T& value);

private:
    static LoggerPtr instance;
};

template<class T> void Logger::Log(const std::wstring& message, const T& value)
{
    std::wstringstream stream;
    stream << message << value;
    Log(stream.str());
}

