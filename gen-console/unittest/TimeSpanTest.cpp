#include "pch.h"
#include "..\TimeSpan.h"
#include "..\WorldConstants.h"

TEST(TimeSpanTest, Constructor)
{
	TimeSpan test;
	EXPECT_EQ(test.Ticks(), 0L);
}

TEST(TimeSpanTest, Constructor_s_positive)
{
	__int64 value = 1234567890L;
	TimeSpan test(value);
	EXPECT_EQ(test.Ticks(), value);
}

TEST(TimeSpanTest, Constructor_s_negative)
{
	__int64 value = -9876543210L;
	TimeSpan test(value);
	EXPECT_EQ(test.Ticks(), value);
}

TEST(TimeSpanTest, Constructor_hms_positive)
{
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(hours, minutes, seconds);
	EXPECT_EQ(test.Ticks(), (((((hours *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_hms_negative)
{
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(hours, minutes, seconds, true);
	EXPECT_EQ(test.Ticks(), -(((((hours *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_dhms_positive)
{
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(days, hours, minutes, seconds);
	EXPECT_EQ(test.Ticks(), (((((((days * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_dhms_negative)
{
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Ticks(), -(((((((days * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) * 
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_ydhms_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Ticks(), (((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_ydhms_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Ticks(), -(((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Seconds_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Seconds(), seconds);
}

TEST(TimeSpanTest, Seconds_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Seconds(), seconds);
}

TEST(TimeSpanTest, Minutes_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Minutes(), minutes);
}

TEST(TimeSpanTest, Minutes_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Minutes(), minutes);
}

TEST(TimeSpanTest, Hours_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Hours(), hours);
}

TEST(TimeSpanTest, Hours_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Hours(), hours);
}

TEST(TimeSpanTest, Days_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Days(), days);
}

TEST(TimeSpanTest, Days_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Days(), days);
}

TEST(TimeSpanTest, Years_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Years(), years);
}

TEST(TimeSpanTest, Years_negative)
{
	__int64 years = 8UL;
	__int64 days = 9UL;
	__int64 hours = 10UL;
	__int64 minutes = 11UL;
	__int64 seconds = 12UL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Years(), years);
}

TEST(TimeSpanTest, Negative_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_FALSE(test.Negative());
}

TEST(TimeSpanTest, Negative_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_TRUE(test.Negative());
}

TEST(TimeSpanTest, TotalSeconds_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalSeconds(), ((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds));
}

TEST(TimeSpanTest, TotalSeconds_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalSeconds(), -((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds));
}

TEST(TimeSpanTest, TotalMinutes_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalMinutes(), ((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes));
}

TEST(TimeSpanTest, TotalMinutes_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalMinutes(), -((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes));
}

TEST(TimeSpanTest, TotalHours_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalHours(), ((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours));
}

TEST(TimeSpanTest, TotalHours_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalHours(), -((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours));
}

TEST(TimeSpanTest, TotalDays_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalDays(), ((years * static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days));
}

TEST(TimeSpanTest, TotalDays_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalDays(), -((years * static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days));
}

TEST(TimeSpanTest, TotalYears_positive)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalYears(), years);
}

TEST(TimeSpanTest, TotalYears_negative)
{
	__int64 years = 8L;
	__int64 days = 9L;
	__int64 hours = 10L;
	__int64 minutes = 11L;
	__int64 seconds = 12L;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalYears(), -years);
}

TEST(TimeSpanTest, OperatorPlusEQ)
{
	TimeSpan value1(1234L);
	TimeSpan value2(-234L);
	value1 += value2;
	EXPECT_EQ(value1.Ticks(), 1000L);
	EXPECT_EQ(value2.Ticks(), -234L);
	value2 += value1;
	EXPECT_EQ(value1.Ticks(), 1000L);
	EXPECT_EQ(value2.Ticks(), 766L);
}

TEST(TimeSpanTest, OperatorMinusEQ)
{
	TimeSpan value1(1234L);
	TimeSpan value2(234L);
	value1 -= value2;
	EXPECT_EQ(value1.Ticks(), 1000L);
	EXPECT_EQ(value2.Ticks(), 234L);
	value2 -= value1;
	EXPECT_EQ(value1.Ticks(), 1000L);
	EXPECT_EQ(value2.Ticks(), -766L);
}

TEST(TimeSpanTest, OperatorMultiplyEQ)
{
	TimeSpan value(1234L);
	value *= 2L;
	EXPECT_EQ(value.Ticks(), 2468L);
	value *= -3L;
	EXPECT_EQ(value.Ticks(), -7404L);
}

TEST(TimeSpanTest, OperatorDivideEQ)
{
	TimeSpan value(7404L);
	value /= 3L;
	EXPECT_EQ(value.Ticks(), 2468L);
	value /= -2L;
	EXPECT_EQ(value.Ticks(), -1234L);
}

