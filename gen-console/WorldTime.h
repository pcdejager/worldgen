#pragma once

/// <summary>
/// WorldTime class for the time used in the world
/// </summary>
class WorldTime
{
public:
	WorldTime();
	~WorldTime() { ; }

public:
	unsigned __int64 GetTicks() { return ticks; }

private:
	unsigned __int64 ticks;
};

