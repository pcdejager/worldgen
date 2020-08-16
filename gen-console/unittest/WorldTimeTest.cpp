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

TEST(WorldTimeTest, Undefined)
{
	WorldTime test = WorldTime::Undefined();
	EXPECT_EQ(test.Ticks(), 0UL);
}

TEST(WorldTimeTest, Minimum)
{
	WorldTime minimum = WorldTime::Minimum();
	EXPECT_EQ(minimum.Ticks(), ((WORLD_TIME_DAYSPERYEAR + 1UL) * WORLD_TIME_HOURSPERDAY * WORLD_TIME_MINUTESPERHOUR * WORLD_TIME_SECONDSPERMINUTE * WORLD_TIME_TICKSPERSECOND));
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

TEST(WorldTimeTest, OperatorSubractWorldTimes)
{
	WorldTime one(1234567890UL);
	WorldTime two(1030507090UL);
	TimeSpan result = one - two;
	EXPECT_EQ(result.Ticks(), 204060800L);
	EXPECT_EQ(one.Ticks(), 1234567890UL);
	EXPECT_EQ(two.Ticks(), 1030507090UL);
	result = two - one;
	EXPECT_EQ(result.Ticks(), -204060800L);
	EXPECT_EQ(one.Ticks(), 1234567890UL);
	EXPECT_EQ(two.Ticks(), 1030507090UL);
}

TEST(WorldTimeTest, OperatorPlusEQTimeSpan)
{
	WorldTime one(1030507090UL);
	TimeSpan span1(204060800L);
	TimeSpan span2(-204060800L);
	one += span1;
	EXPECT_EQ(one.Ticks(), 1234567890UL);
	EXPECT_EQ(span1.Ticks(), 204060800L);
	EXPECT_EQ(span2.Ticks(), -204060800L);
	one += span2;
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), 204060800L);
	EXPECT_EQ(span2.Ticks(), -204060800L);
}

TEST(WorldTimeTest, OperatorPlusEQTimeSpan_negative)
{
	WorldTime one(1030507090UL);
	TimeSpan span(-10204060800L);
	one += span;
	EXPECT_EQ(one.Ticks(), 0UL);
	EXPECT_EQ(span.Ticks(), -10204060800L);
}

TEST(WorldTimeTest, OperatorPlusTimeSpan)
{
	WorldTime one(1030507090UL);
	TimeSpan span1(204060800L);
	TimeSpan span2(-204060800L);
	WorldTime result = one + span1;
	EXPECT_EQ(result.Ticks(), 1234567890UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), 204060800L);
	EXPECT_EQ(span2.Ticks(), -204060800L);
	result = result + span2;
	EXPECT_EQ(result.Ticks(), 1030507090UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), 204060800L);
	EXPECT_EQ(span2.Ticks(), -204060800L);
}

TEST(WorldTimeTest, OperatorPlusTimeSpan_negative)
{
	WorldTime one(1030507090UL);
	TimeSpan span(-10204060800L);
	WorldTime result = one + span;
	EXPECT_EQ(result.Ticks(), 0UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span.Ticks(), -10204060800L);
}

TEST(WorldTimeTest, OperatorMinusEQTimeSpan)
{
	WorldTime one(1030507090UL);
	TimeSpan span1(-204060800L);
	TimeSpan span2(204060800L);
	one -= span1;
	EXPECT_EQ(one.Ticks(), 1234567890UL);
	EXPECT_EQ(span1.Ticks(), -204060800L);
	EXPECT_EQ(span2.Ticks(), 204060800L);
	one -= span2;
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), -204060800L);
	EXPECT_EQ(span2.Ticks(), 204060800L);
}

TEST(WorldTimeTest, OperatorMinusEQTimeSpan_negative)
{
	WorldTime one(1030507090UL);
	TimeSpan span(10204060800L);
	one -= span;
	EXPECT_EQ(one.Ticks(), 0UL);
	EXPECT_EQ(span.Ticks(), 10204060800L);
}

TEST(WorldTimeTest, OperatorMinusTimeSpan)
{
	WorldTime one(1030507090UL);
	TimeSpan span1(-204060800L);
	TimeSpan span2(204060800L);
	WorldTime result = one - span1;
	EXPECT_EQ(result.Ticks(), 1234567890UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), -204060800L);
	EXPECT_EQ(span2.Ticks(), 204060800L);
	result = result - span2;
	EXPECT_EQ(result.Ticks(), 1030507090UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span1.Ticks(), -204060800L);
	EXPECT_EQ(span2.Ticks(), 204060800L);
}

TEST(WorldTimeTest, OperatorMinusTimeSpan_negative)
{
	WorldTime one(1030507090UL);
	TimeSpan span(10204060800L);
	WorldTime result = one - span;
	EXPECT_EQ(result.Ticks(), 0UL);
	EXPECT_EQ(one.Ticks(), 1030507090UL);
	EXPECT_EQ(span.Ticks(), 10204060800L);
}

TEST(WorldTimeTest, OperatorEQ)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime diff(1234567890UL);
	EXPECT_TRUE(base == same);
	EXPECT_FALSE(base == diff);
}

TEST(WorldTimeTest, OperatorNEQ)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime diff(1234567890UL);
	EXPECT_FALSE(base != same);
	EXPECT_TRUE(base != diff);
}

TEST(WorldTimeTest, OperatorLT)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime less(234567890UL);
	WorldTime more(1234567890UL);
	EXPECT_FALSE(base < same);
	EXPECT_FALSE(base < less);

	EXPECT_FALSE(more < base);
	EXPECT_FALSE(more < less);

	EXPECT_TRUE(base < more);
	EXPECT_TRUE(less < base);
	EXPECT_TRUE(less < more);
}

TEST(WorldTimeTest, OperatorLTEQ)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime less(234567890UL);
	WorldTime more(1234567890UL);
	EXPECT_TRUE(base <= same);

	EXPECT_FALSE(base <= less);

	EXPECT_FALSE(more <= base);
	EXPECT_FALSE(more <= less);

	EXPECT_TRUE(base <= more);
	EXPECT_TRUE(less <= base);
	EXPECT_TRUE(less <= more);
}

TEST(WorldTimeTest, OperatorGT)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime less(234567890UL);
	WorldTime more(1234567890UL);
	EXPECT_FALSE(base > same);
	EXPECT_FALSE(base > more);

	EXPECT_TRUE(more > base);
	EXPECT_TRUE(more > less);
	EXPECT_TRUE(base > less);

	EXPECT_FALSE(less > base);
	EXPECT_FALSE(less > more);
}

TEST(WorldTimeTest, OperatorGTEQ)
{
	WorldTime base(1030507090UL);
	WorldTime same(1030507090UL);
	WorldTime less(234567890UL);
	WorldTime more(1234567890UL);

	EXPECT_TRUE(base >= same);

	EXPECT_FALSE(base >= more);

	EXPECT_TRUE(more >= base);
	EXPECT_TRUE(more >= less);
	EXPECT_TRUE(base >= less);

	EXPECT_FALSE(less >= base);
	EXPECT_FALSE(less >= more);
}