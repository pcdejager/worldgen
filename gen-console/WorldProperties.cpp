#include "pch.h"
#include "WorldProperties.h"
#include "WorldConstants.h"

/*static*/ std::shared_ptr<WorldProperties> WorldProperties::properties(nullptr);

WorldProperties::WorldProperties() 
{
	; 
}

/*static*/ std::shared_ptr<WorldProperties> WorldProperties::Properties()
{
	if (properties == nullptr)
	{
		properties = std::shared_ptr<WorldProperties>(new WorldProperties());
	}
	return properties;
}

unsigned __int64 WorldProperties::TicksPerSecond() 
{ 
	return WORLD_TIME_TICKSPERSECOND; 
}

unsigned __int64 WorldProperties::TicksPerMinute() 
{ 
	return WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND; 
}

unsigned __int64 WorldProperties::TicksPerHour() 
{ 
	return WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND; 
}

unsigned __int64 WorldProperties::TicksPerDay() 
{ 
	return WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND; 
}
