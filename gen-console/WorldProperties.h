#pragma once

#include "Types.h"

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

private:
	static std::shared_ptr<WorldProperties> properties;
	
private:
	INameGeneratorPtr nameGenerator;
};

