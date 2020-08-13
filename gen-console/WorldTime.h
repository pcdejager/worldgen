#pragma once

#include "TimeSpan.h"

/// <summary>
/// WorldTime class for the time used in the world
/// </summary>
class WorldTime
{
public:
	WorldTime();
	WorldTime(unsigned __int64 totalTicks);
	WorldTime(unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second);
	WorldTime(unsigned __int64 days, unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second);
	WorldTime(unsigned __int64 years, unsigned __int64 days, unsigned __int64 hour, unsigned __int64 minute, unsigned __int64 second);
	WorldTime(const WorldTime&) = default;
	WorldTime(const WorldTime&& rhs) noexcept;
	~WorldTime() { ; }

	WorldTime& operator=(const WorldTime&) = default;
	WorldTime& operator=(const WorldTime&&) noexcept;

public:
	unsigned __int64 Ticks() const { return ticks; }

	unsigned __int64 Seconds() const;
	unsigned __int64 Minutes() const;
	unsigned __int64 Hours() const;
	unsigned __int64 Days() const;

	unsigned __int64 TotalSeconds() const;
	unsigned __int64 TotalMinutes() const;
	unsigned __int64 TotalHours() const;
	unsigned __int64 TotalDays() const;
	unsigned __int64 TotalYears() const;

public:
	TimeSpan operator-(const WorldTime& rhs) const;
	WorldTime& operator+=(const TimeSpan& span);
	WorldTime operator+(const TimeSpan& span) const;
	WorldTime& operator-=(const TimeSpan& span);
	WorldTime operator-(const TimeSpan& span) const;

private:
	unsigned __int64 ticks;
};
