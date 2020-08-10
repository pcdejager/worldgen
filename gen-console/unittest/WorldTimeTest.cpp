#include "pch.h"
#include "..\WorldTime.h"

TEST(WorldTimeTest, Constructor) {
	WorldTime test;
	EXPECT_EQ(test.GetTicks(), 0UL);
}