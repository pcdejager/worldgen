#pragma once

class WorldProperties
{
private:
	WorldProperties();
	WorldProperties(const WorldProperties&) = delete;
	WorldProperties& operator=(const WorldProperties&) = delete;

public:
	~WorldProperties() { ; }

public:
	static std::shared_ptr<WorldProperties> Properties();

public:
	unsigned __int64 TicksPerSecond() { return ticksPerSecond; }
	unsigned __int64 TicksPerMinute() { return secondsPerMinute * ticksPerSecond; }
	unsigned __int64 TicksPerHour() { return minutesPerHour * secondsPerMinute * ticksPerSecond; }
	unsigned __int64 TicksPerDay() { return hoursPerDay * minutesPerHour * secondsPerMinute * ticksPerSecond; }

private:
	unsigned __int64 ticksPerSecond;
	unsigned __int64 secondsPerMinute;
	unsigned __int64 minutesPerHour;
	unsigned __int64 hoursPerDay;

private:
	static std::shared_ptr<WorldProperties> properties;
};

