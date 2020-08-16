#include "pch.h"
#include "WorldProperties.h"
#include "WorldConstants.h"
#include "NumberNameGenerator.h"

/*static*/ std::shared_ptr<WorldProperties> WorldProperties::properties(nullptr);

WorldProperties::WorldProperties()
	: nameGenerator(nullptr)
	, now(WorldTime::Minimum())
{
	; 
}

/*static*/ std::shared_ptr<WorldProperties> WorldProperties::Properties()
{
	if (properties == nullptr)
	{
		properties = std::shared_ptr<WorldProperties>(new WorldProperties());
		INameGeneratorPtr nameGenerator = INameGeneratorPtr(new NumberNameGenerator());
		properties->Initialize(nameGenerator);
	}
	return properties;
}

void WorldProperties::Initialize(INameGeneratorPtr newNameGenerator)
{
	nameGenerator = newNameGenerator;
}

void WorldProperties::ResetTime()
{
	now = WorldTime::Minimum();
}

void WorldProperties::AdvanceTime(const TimeSpan& span)
{
	if (span.Negative())
	{
		now -= span;
	}
	else
	{
		now += span;
	}
}