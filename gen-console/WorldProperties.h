#pragma once

#include "Types.h"
#include "WorldTime.h"

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

private:
	void Initialize(INameGeneratorPtr newNameGenerator);

public:
	INameGenerator* NameGenerator() { return nameGenerator.get(); }

///  Time methods
public:
	/// <summary>
	/// Get the current time in the world
	/// </summary>
	/// <returns>Current time</returns>
	WorldTime Now() const { return now; }

	/// <summary>
	/// Reset the world time going back to the beginning
	/// </summary>
	void ResetTime();

	/// <summary>
	/// Advanced the world time with the specified duration
	/// Note: The sign of the duration is ignored!
	/// </summary>
	/// <param name="span">The duration to advance with</param>
	void AdvanceTime(const TimeSpan& span);
	void AdvanceToNextDay();
private:
	static std::shared_ptr<WorldProperties> properties;
	
private:
	INameGeneratorPtr nameGenerator;
	WorldTime now;
};

