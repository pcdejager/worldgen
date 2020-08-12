#include "pch.h"
#include "TimeSpan.h"
#include "WorldConstants.h"

TimeSpan::TimeSpan()
	: span(0L)
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

TimeSpan::TimeSpan(const TimeSpan&& rhs) noexcept
	: span(rhs.span)
{
	;
}

TimeSpan& TimeSpan::operator=(const TimeSpan&& rhs) noexcept
{
	if (&rhs != this)
	{
		span = rhs.span;
	}
	return *this;
}

__int64 TimeSpan::Seconds()
{
	return (((span < 0) ? -span : span) / WORLD_TIME_TICKSPERSECOND) % WORLD_TIME_SECONDSPERMINUTE;
}

__int64 TimeSpan::Minutes()
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_MINUTESPERHOUR;
}

__int64 TimeSpan::Hours()
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_HOURSPERDAY;
}

__int64 TimeSpan::Days()
{
	return (((span < 0) ? -span : span) / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_DAYSPERYEAR;
}

__int64 TimeSpan::Years()
{
	return ((span < 0) ? -span : span) / static_cast<__int64>(WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

bool TimeSpan::Negative()
{
	return span < 0L;
}

__int64 TimeSpan::TotalSeconds()
{
	return span / static_cast<__int64>(WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalMinutes()
{
	return span / static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalHours()
{
	return span / static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalDays()
{
	return span / static_cast<__int64>(WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

__int64 TimeSpan::TotalYears()
{
	return span / static_cast<__int64>(WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs)
{
	span += rhs.span;
	return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs)
{
	span -= rhs.span;
	return *this;
}

TimeSpan& TimeSpan::operator*=(__int64 value)
{
	span *= value;
	return *this;
}

TimeSpan& TimeSpan::operator/=(__int64 value)
{
	span /= value;
	return *this;
}
