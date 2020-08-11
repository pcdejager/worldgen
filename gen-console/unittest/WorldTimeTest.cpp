#include "pch.h"
#include "..\WorldTime.h"
#include "..\WorldConstants.h"

TEST(WorldTimeTest, Constructor) 
{
	WorldTime test;
	EXPECT_EQ(test.Ticks(), 0UL);
}

TEST(WorldTimeTest, Constructor_t)
{
	unsigned __int64 value = 1234567890UL;
	WorldTime test(value);
	EXPECT_EQ(test.Ticks(), value);
}
TEST(WorldTimeTest, Constructor_hmd)
{
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(hour, minute, second);
	EXPECT_EQ(test.Ticks(), (((((hour * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND));
}

TEST(WorldTimeTest, Constructor_dhmd)
{
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(days, hour, minute, second);
	EXPECT_EQ(test.Ticks(), (((((((days * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND));
}

TEST(WorldTimeTest, Constructor_ydhmd)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.Ticks(), (((((((((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second) * WORLD_TIME_TICKSPERSECOND));
}

TEST(WorldTimeTest, Seconds)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.Seconds(), second);
}

TEST(WorldTimeTest, Minutes)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.Minutes(), minute);
}

TEST(WorldTimeTest, Hours)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.Hours(), hour);
}

TEST(WorldTimeTest, Days)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.Days(), days);
}

TEST(WorldTimeTest, TotalSeconds)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.TotalSeconds(), ((((((((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute) * WORLD_TIME_SECONDSPERMINUTE) + second));
}

TEST(WorldTimeTest, TotalMinutes)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.TotalMinutes(), ((((((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hour) * WORLD_TIME_MINUTESPERHOUR) + minute));
}

TEST(WorldTimeTest, TotalHours)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.TotalHours(), (((years * WORLD_TIME_DAYSPERYEAR) + days) * WORLD_TIME_HOURSPERDAY) + hour);
}

TEST(WorldTimeTest, TotalDays)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.TotalDays(), (years * WORLD_TIME_DAYSPERYEAR) + days);
}

TEST(WorldTimeTest, TotalYears)
{
	unsigned __int64 years = 8UL;
	unsigned __int64 days = 9UL;
	unsigned __int64 hour = 10UL;
	unsigned __int64 minute = 11UL;
	unsigned __int64 second = 12UL;
	WorldTime test(years, days, hour, minute, second);
	EXPECT_EQ(test.TotalYears(), years);
}