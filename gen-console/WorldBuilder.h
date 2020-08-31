#pragma once

#include "Population.h"

/// <summary>
/// Class that will build a new world
/// </summary>
class WorldBuilder
{
public:
	WorldBuilder();
	~WorldBuilder() = default;

	void Run();

private:
	void GenerateInitialPopulation();

private:
	Population population;
};

