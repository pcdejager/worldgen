#include "pch.h"
#include "..\WorldProperties.h"

TEST(WorldPropertiesTest, Singleton)
{
	auto value = WorldProperties::Properties();
	EXPECT_NE(value, nullptr);
}

TEST(WorldPropertiesTest, NameGenerator)
{
	auto generator = WorldProperties::Properties()->NameGenerator();
	EXPECT_NE(generator, nullptr);
}

TEST(WorldPropertiesTest, Now)
{
	WorldProperties::Properties()->ResetTime();
	auto time = WorldProperties::Properties()->Now();
	EXPECT_TRUE(time != WorldTime::Undefined());
	EXPECT_TRUE(time == WorldTime::Minimum());
}

TEST(WorldPropertiesTest, ResetTime)
{
	WorldProperties::Properties()->AdvanceTime(TimeSpan(100UL));
	auto time = WorldProperties::Properties()->Now();
	EXPECT_TRUE(time > WorldTime::Minimum());
	WorldProperties::Properties()->ResetTime();
	time = WorldProperties::Properties()->Now();
	EXPECT_TRUE(time == WorldTime::Minimum());
}

TEST(WorldPropertiesTest, AdvanceTime_positive)
{
	WorldProperties::Properties()->ResetTime();
	auto time = WorldProperties::Properties()->Now();
	auto start = WorldTime::Minimum();
	EXPECT_TRUE(time == start);
	TimeSpan adjust(1234567890LL);
	WorldProperties::Properties()->AdvanceTime(adjust);
	time = WorldProperties::Properties()->Now();
	EXPECT_TRUE(time > WorldTime::Minimum());
	EXPECT_EQ(time, start + adjust);
}

TEST(WorldPropertiesTest, AdvanceTime_negative)
{
	WorldProperties::Properties()->ResetTime();
	auto time = WorldProperties::Properties()->Now();
	auto start = WorldTime::Minimum();
	EXPECT_TRUE(time == start);
	TimeSpan adjust(-1234LL);
	WorldProperties::Properties()->AdvanceTime(adjust);
	time = WorldProperties::Properties()->Now();
	EXPECT_TRUE(time > WorldTime::Minimum());
	EXPECT_EQ(time, start - adjust);
}
