#include "pch.h"
#include "WorldTime.h"
#include "WorldConstants.h"

WorldTime::WorldTime()
	: ticks(0UL)
{
	;
}

WorldTime::WorldTime(unsigned __int64 totalTicks)
	: ticks(totalTicks)
{
	;
}

WorldTime::WorldTime(unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second)
{
	ticks = ((((hour * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND;
}

WorldTime::WorldTime(unsigned __int64 days, unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second)
{
	ticks = ((((((days * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND;
}

WorldTime::WorldTime(unsigned __int64 years, unsigned __int64 days, unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second)
{
	ticks = ((((((((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND;
}

WorldTime::WorldTime(const WorldTime&& rhs) noexcept
	: ticks(rhs.ticks)
{
	;
}

WorldTime& WorldTime::operator=(const WorldTime&& rhs) noexcept
{
	if (&rhs != this)
	{
		ticks = rhs.ticks;
	}
	return *this;
}

unsigned __int64 WorldTime::Seconds() const
{
	return (ticks / WORLD_TIME_TICKSPERSECOND) % WORLD_TIME_SECONDSPERMINUTE;
}

unsigned __int64 WorldTime::Minutes() const
{
	return (ticks / (WORLD_TIME_TICKSPERSECOND * WORLD_TIME_SECONDSPERMINUTE)) % WORLD_TIME_MINUTESPERHOUR;
}

unsigned __int64 WorldTime::Hours() const
{
	return (ticks / (WORLD_TIME_TICKSPERSECOND * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_MINUTESPERHOUR)) % WORLD_TIME_HOURSPERDAY;
}

unsigned __int64 WorldTime::Days() const
{
	return (ticks / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_DAYSPERYEAR;
}

unsigned __int64 WorldTime::TotalSeconds() const
{
	return ticks / WORLD_TIME_TICKSPERSECOND;
}

unsigned __int64 WorldTime::TotalMinutes() const
{
	return ticks / (WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalHours() const
{
	return ticks / (WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalDays() const
{
	return ticks / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalYears() const
{
	return ticks / (WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

TimeSpan WorldTime::operator-(const WorldTime& rhs) const
{
	return TimeSpan(static_cast<__int64>(ticks) - static_cast<__int64>(rhs.ticks));
}

WorldTime& WorldTime::operator+=(const TimeSpan& span) 
{
	__int64 newTime = static_cast<__int64>(ticks) + span.Ticks();
	if (newTime < 0L)
	{
		newTime = 0L;
	}
	ticks = static_cast<unsigned __int64>(newTime);
	return *this;
}

WorldTime WorldTime::operator+(const TimeSpan& span) const
{
	__int64 newTime = static_cast<__int64>(ticks) + span.Ticks();
	if (newTime < 0L)
	{
		newTime = 0L;
	}
	return WorldTime(static_cast<unsigned __int64>(newTime));
}

WorldTime& WorldTime::operator-=(const TimeSpan& span) 
{
	__int64 newTime = static_cast<__int64>(ticks) - span.Ticks();
	if (newTime < 0L)
	{
		newTime = 0L;
	}
	ticks = static_cast<unsigned __int64>(newTime);
	return *this;
}

WorldTime WorldTime::operator-(const TimeSpan& span) const
{
	__int64 newTime = static_cast<__int64>(ticks) - span.Ticks();
	if (newTime < 0L)
	{
		newTime = 0L;
	}
	return WorldTime(static_cast<unsigned __int64>(newTime));
}

bool WorldTime::operator==(const WorldTime& rhs) const
{
	return ticks == rhs.ticks;
}

bool WorldTime::operator!=(const WorldTime& rhs) const
{
	return ticks != rhs.ticks;
}

bool WorldTime::operator<(const WorldTime& rhs) const
{
	return ticks < rhs.ticks;
}

bool WorldTime::operator<=(const WorldTime& rhs) const
{
	return ticks <= rhs.ticks;
}

bool WorldTime::operator>(const WorldTime& rhs) const
{
	return ticks > rhs.ticks;
}

bool WorldTime::operator>=(const WorldTime& rhs) const
{
	return ticks >= rhs.ticks;
}
