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

unsigned __int64 WorldTime::Seconds()
{
	return (ticks / WORLD_TIME_TICKSPERSECOND) % WORLD_TIME_SECONDSPERMINUTE;
}

unsigned __int64 WorldTime::Minutes()
{
	return (ticks / (WORLD_TIME_TICKSPERSECOND * WORLD_TIME_SECONDSPERMINUTE)) % WORLD_TIME_MINUTESPERHOUR;
}

unsigned __int64 WorldTime::Hours()
{
	return (ticks / (WORLD_TIME_TICKSPERSECOND * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_MINUTESPERHOUR)) % WORLD_TIME_HOURSPERDAY;
}

unsigned __int64 WorldTime::Days()
{
	return (ticks / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND)) % WORLD_TIME_DAYSPERYEAR;
}


unsigned __int64 WorldTime::TotalSeconds()
{
	return ticks / WORLD_TIME_TICKSPERSECOND;
}

unsigned __int64 WorldTime::TotalMinutes()
{
	return ticks / (WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalHours()
{
	return ticks / (WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalDays()
{
	return ticks / (WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

unsigned __int64 WorldTime::TotalYears()
{
	return ticks / (WORLD_TIME_DAYSPERYEAR * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND);
}

