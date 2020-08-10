#include "pch.h"
#include "WorldProperties.h"

/*static*/ std::shared_ptr<WorldProperties> WorldProperties::properties(nullptr);

WorldProperties::WorldProperties() 
	: ticksPerSecond(1000UL)
	, secondsPerMinute(60UL)
	, minutesPerHour(60UL)
	, hoursPerDay(24UL)
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
