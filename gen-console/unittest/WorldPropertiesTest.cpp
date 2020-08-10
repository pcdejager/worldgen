#include "pch.h"
#include "..\WorldProperties.h"

TEST(WorldPropertiesTest, Singleton)
{
	auto value = WorldProperties::Properties();
	ASSERT_NE(value, nullptr);
}

TEST(WorldPropertiesTest, TicksPerSecond)
{
	EXPECT_EQ(WorldProperties::Properties()->TicksPerSecond(), 1000UL);
}

TEST(WorldPropertiesTest, TicksPerMinute)
{
	EXPECT_EQ(WorldProperties::Properties()->TicksPerMinute(), 60000UL);
}

TEST(WorldPropertiesTest, TicksPerHour)
{
	EXPECT_EQ(WorldProperties::Properties()->TicksPerHour(), 3600000UL);
}

TEST(WorldPropertiesTest, TicksPerDay)
{
	EXPECT_EQ(WorldProperties::Properties()->TicksPerDay(), 86400000UL);
}