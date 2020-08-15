#include "pch.h"
#include "..\WorldProperties.h"

TEST(WorldPropertiesTest, Singleton)
{
	auto value = WorldProperties::Properties();
	ASSERT_NE(value, nullptr);
}

TEST(WorldPropertiesTest, NameGenerator)
{
	auto generator = WorldProperties::Properties()->NameGenerator();
	ASSERT_NE(generator, nullptr);
}
