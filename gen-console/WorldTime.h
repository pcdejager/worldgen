#pragma once

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
	unsigned __int64 Ticks() { return ticks; }

	unsigned __int64 Seconds();
	unsigned __int64 Minutes();
	unsigned __int64 Hours();
	unsigned __int64 Days();

	unsigned __int64 TotalSeconds();
	unsigned __int64 TotalMinutes();
	unsigned __int64 TotalHours();
	unsigned __int64 TotalDays();
	unsigned __int64 TotalYears();

private:
	unsigned __int64 ticks;
};

