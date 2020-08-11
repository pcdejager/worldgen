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
	unsigned __int64 TicksPerSecond();
	unsigned __int64 TicksPerMinute();
	unsigned __int64 TicksPerHour();
	unsigned __int64 TicksPerDay();

private:
	static std::shared_ptr<WorldProperties> properties;
};

