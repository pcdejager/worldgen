#include "pch.h"
#include "TimeSpan.h"
#include "WorldConstants.h"

TimeSpan::TimeSpan()
	: span(0LL)
{
	;
}

TimeSpan::TimeSpan(__int64 totalSpan)
	: span(totalSpan)
{
	;
}

TimeSpan::TimeSpan(__int64 hours, __int64 minutes, __int64 seconds, bool negative /*= false*/)
{
	span = ((((hours * WORLD_TIME_MINUTESPERHOUR) + minutes) * WORLD_TIME_SECONDSPERMINUTE) + seconds) * WORLD_TIME_TICKSPERSECOND;
	span = (negative) ? -span : span;
}

TimeSpan::TimeSpan(__int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative /*= false*/)
{
	span = ((((((days * WORLD_TIME_HOURSPERDAY) + hours) * WORLD_TIME_MINUTESPERHOUR) + minutes) * WORLD_TIME_SECONDSPERMINUTE) + seconds) * WORLD_TIME_TICKSPERSECOND;
	span = (negative) ? -span : span;
}

TimeSpan::TimeSpan(__int64 years, __int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative /*= false*/)
{
	span = ((((((((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hours) * WORLD_TIME_MINUTESPERHOUR) + minutes) * WORLD_TIME_SECONDSPERMINUTE) + seconds) * WORLD_TIME_TICKSPERSECOND;
	span = (negative) ? -span : span;
}

TimeSpan::TimeSpan(TimeSpan&& rhs) noexcept
	: span(rhs.span)
{
	;
}

TimeSpan& TimeSpan::operator=(TimeSpan&& rhs) noexcept
{
	if (&rhs != this)
	{
		span = rhs.span;
	}
	return *this;
}

__int64 TimeSpan::Seconds() const
{
	return (((span < 0) ? -span : span) / WORLD_TIME_TICKSPERSECOND) % WORLD_TIME_SECONDSPERMINUTE;
}

__int64 TimeSpan::Minutes() const
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_MINUTESPERHOUR;
}

__int64 TimeSpan::Hours() const
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_HOURSPERDAY;
}

__int64 TimeSpan::Days() const
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_DAYSPERYEAR;
}

__int64 TimeSpan::Years() const
{
	return ((span < 0) ? -span : span) / static_cast<__int64>(WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

bool TimeSpan::Negative() const
{
	return span < 0LL;
}

__int64 TimeSpan::TotalSeconds() const
{
	return span / static_cast<__int64>(WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalMinutes() const
{
	return span / static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalHours() const
{
	return span / static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalDays() const
{
	return span / static_cast<__int64>(WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalYears() const
{
	return span / static_cast<__int64>(WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

std::wstring TimeSpan::ToString() const
{
	std::wstringstream stream;
	if (Negative())
	{
		stream << L"-";
	}
	stream << Years() << L"Y" << Days() << L"D" << Hours() << L"H" << Minutes() << L"M" << Seconds() << L"S";
	return stream.str();
}
TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs)
{
	span += rhs.span;
	return *this;
}

TimeSpan TimeSpan::operator+(const TimeSpan& rhs)
{
	TimeSpan result(*this);
	result += rhs;
	return result;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs)
{
	span -= rhs.span;
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan& rhs)
{
	TimeSpan result(*this);
	result -= rhs;
	return result;
}

TimeSpan& TimeSpan::operator*=(__int64 value)
{
	span *= value;
	return *this;
}

TimeSpan TimeSpan::operator*(__int64 value)
{
	TimeSpan result(*this);
	result *= value;
	return result;
}

TimeSpan& TimeSpan::operator/=(__int64 value)
{
	span /= value;
	return *this;
}

TimeSpan TimeSpan::operator/(__int64 value)
{
	TimeSpan result(*this);
	result /= value;
	return result;
}

bool TimeSpan::operator==(const TimeSpan& rhs) const
{
	return span == rhs.span;
}

bool TimeSpan::operator!=(const TimeSpan& rhs) const
{
	return span != rhs.span;
}

bool TimeSpan::operator<(const TimeSpan& rhs) const
{
	return span < rhs.span;
}

bool TimeSpan::operator<=(const TimeSpan& rhs) const
{
	return span <= rhs.span;
}

bool TimeSpan::operator>(const TimeSpan& rhs) const
{
	return span > rhs.span;
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const
{
	return span >= rhs.span;
}
