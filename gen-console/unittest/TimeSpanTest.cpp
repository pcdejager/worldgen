#include "pch.h"
#include "..\TimeSpan.h"
#include "..\WorldConstants.h"

TEST(TimeSpanTest, Constructor)
{
	TimeSpan test;
	EXPECT_EQ(test.Ticks(), 0LL);
}

TEST(TimeSpanTest, Constructor_s_positive)
{
	__int64 value = 1234567890LL;
	TimeSpan test(value);
	EXPECT_EQ(test.Ticks(), value);
}

TEST(TimeSpanTest, Constructor_s_negative)
{
	__int64 value = -9876543210LL;
	TimeSpan test(value);
	EXPECT_EQ(test.Ticks(), value);
}

TEST(TimeSpanTest, Constructor_hms_positive)
{
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(hours, minutes, seconds);
	EXPECT_EQ(test.Ticks(), (((((hours *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_hms_negative)
{
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(hours, minutes, seconds, true);
	EXPECT_EQ(test.Ticks(), -(((((hours *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_dhms_positive)
{
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(days, hours, minutes, seconds);
	EXPECT_EQ(test.Ticks(), (((((((days * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_dhms_negative)
{
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Ticks(), -(((((((days * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) * 
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds) * 
		static_cast<__int64>(WORLD_TIME_TICKSPERSECOND)));
}

TEST(TimeSpanTest, Constructor_ydhms_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
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
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
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
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Seconds(), seconds);
}

TEST(TimeSpanTest, Seconds_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Seconds(), seconds);
}

TEST(TimeSpanTest, Minutes_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Minutes(), minutes);
}

TEST(TimeSpanTest, Minutes_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Minutes(), minutes);
}

TEST(TimeSpanTest, Hours_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Hours(), hours);
}

TEST(TimeSpanTest, Hours_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Hours(), hours);
}

TEST(TimeSpanTest, Days_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Days(), days);
}

TEST(TimeSpanTest, Days_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Days(), days);
}

TEST(TimeSpanTest, Years_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.Years(), years);
}

TEST(TimeSpanTest, Years_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.Years(), years);
}

TEST(TimeSpanTest, Negative_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_FALSE(test.Negative());
}

TEST(TimeSpanTest, Negative_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_TRUE(test.Negative());
}

TEST(TimeSpanTest, IsZero)
{
	TimeSpan test1(0LL, 0LL, 0LL, 0LL, 0LL);
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test2(years, days, hours, minutes, seconds, true);
	TimeSpan test3;

	EXPECT_TRUE(test1.IsZero());
	EXPECT_FALSE(test2.IsZero());
	EXPECT_TRUE(test3.IsZero());
}

TEST(TimeSpanTest, TotalSeconds_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalSeconds(), ((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds));
}

TEST(TimeSpanTest, TotalSeconds_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalSeconds(), -((((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes) * 
		static_cast<__int64>(WORLD_TIME_SECONDSPERMINUTE)) + seconds));
}

TEST(TimeSpanTest, TotalMinutes_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalMinutes(), ((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes));
}

TEST(TimeSpanTest, TotalMinutes_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalMinutes(), -((((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours) *
		static_cast<__int64>(WORLD_TIME_MINUTESPERHOUR)) + minutes));
}

TEST(TimeSpanTest, TotalHours_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalHours(), ((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours));
}

TEST(TimeSpanTest, TotalHours_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalHours(), -((((years * 
		static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days) * 
		static_cast<__int64>(WORLD_TIME_HOURSPERDAY)) + hours));
}

TEST(TimeSpanTest, TotalDays_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalDays(), ((years * static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days));
}

TEST(TimeSpanTest, TotalDays_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalDays(), -((years * static_cast<__int64>(WORLD_TIME_DAYSPERYEAR)) + days));
}

TEST(TimeSpanTest, TotalYears_positive)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds);
	EXPECT_EQ(test.TotalYears(), years);
}

TEST(TimeSpanTest, TotalYears_negative)
{
	__int64 years = 8LL;
	__int64 days = 9LL;
	__int64 hours = 10LL;
	__int64 minutes = 11LL;
	__int64 seconds = 12LL;
	TimeSpan test(years, days, hours, minutes, seconds, true);
	EXPECT_EQ(test.TotalYears(), -years);
}

TEST(TimeSpanTest, ToString_positive)
{
	TimeSpan test(1LL, 2LL, 3LL, 4LL, 5LL, false);
	EXPECT_EQ(L"1Y2D3H4M5S", test.ToString());
}

TEST(TimeSpanTest, ToString_negative)
{
	TimeSpan test(1LL, 2LL, 3LL, 4LL, 5LL, true);
	EXPECT_EQ(L"-1Y2D3H4M5S", test.ToString());
}

TEST(TimeSpanTest, OperatorPlusEQ)
{
	TimeSpan value1(1234LL);
	TimeSpan value2(-234LL);
	value1 += value2;
	EXPECT_EQ(value1.Ticks(), 1000LL);
	EXPECT_EQ(value2.Ticks(), -234LL);
	value2 += value1;
	EXPECT_EQ(value1.Ticks(), 1000LL);
	EXPECT_EQ(value2.Ticks(), 766LL);
}

TEST(TimeSpanTest, OperatorPlus)
{
	TimeSpan value1(1234LL);
	TimeSpan value2(-234LL);
	TimeSpan result = value1 + value2;
	EXPECT_EQ(result.Ticks(), 1000LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), -234LL);
	result = result + value1;
	EXPECT_EQ(result.Ticks(), 2234LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), -234LL);
	result = result + value2;
	EXPECT_EQ(result.Ticks(), 2000LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), -234LL);
}

TEST(TimeSpanTest, OperatorMinusEQ)
{
	TimeSpan value1(1234LL);
	TimeSpan value2(234LL);
	value1 -= value2;
	EXPECT_EQ(value1.Ticks(), 1000LL);
	EXPECT_EQ(value2.Ticks(), 234LL);
	value2 -= value1;
	EXPECT_EQ(value1.Ticks(), 1000LL);
	EXPECT_EQ(value2.Ticks(), -766LL);
}

TEST(TimeSpanTest, OperatorMinus)
{
	TimeSpan value1(1234LL);
	TimeSpan value2(234LL);
	TimeSpan result = value1 - value2;
	EXPECT_EQ(result.Ticks(), 1000LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), 234LL);
	result = result - value1;
	EXPECT_EQ(result.Ticks(), -234LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), 234LL);
	result = result - value2;
	EXPECT_EQ(result.Ticks(), -468LL);
	EXPECT_EQ(value1.Ticks(), 1234LL);
	EXPECT_EQ(value2.Ticks(), 234LL);
}

TEST(TimeSpanTest, OperatorMultiplyEQ)
{
	TimeSpan value(1234LL);
	value *= 2LL;
	EXPECT_EQ(value.Ticks(), 2468LL);
	value *= -3LL;
	EXPECT_EQ(value.Ticks(), -7404LL);
}

TEST(TimeSpanTest, OperatorMultiply)
{
	TimeSpan value(1234LL);
	TimeSpan result = value * 2LL;
	EXPECT_EQ(result.Ticks(), 2468LL);
	EXPECT_EQ(value.Ticks(), 1234LL);
	result = result * -3LL;
	EXPECT_EQ(result.Ticks(), -7404LL);
	EXPECT_EQ(value.Ticks(), 1234LL);
}

TEST(TimeSpanTest, OperatorDivideEQ)
{
	TimeSpan value(7404LL);
	value /= 3LL;
	EXPECT_EQ(value.Ticks(), 2468LL);
	value /= -2LL;
	EXPECT_EQ(value.Ticks(), -1234LL);
}

TEST(TimeSpanTest, OperatorDivide)
{
	TimeSpan value(7404LL);
	TimeSpan result = value / 3LL;
	EXPECT_EQ(result.Ticks(), 2468LL);
	EXPECT_EQ(value.Ticks(), 7404LL);
	result = result / -2LL;
	EXPECT_EQ(result.Ticks(), -1234LL);
	EXPECT_EQ(value.Ticks(), 7404LL);
}

TEST(TimeSpanTest, OperatorEQ)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan diff(1234567890LL);
	EXPECT_TRUE(base == same);
	EXPECT_FALSE(base == diff);
}

TEST(TimeSpanTest, OperatorNEQ)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan diff(1234567890LL);
	EXPECT_FALSE(base != same);
	EXPECT_TRUE(base != diff);
}

TEST(TimeSpanTest, OperatorLT)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan less(234567890LL);
	TimeSpan more(1234567890LL);
	EXPECT_FALSE(base < same);
	EXPECT_FALSE(base < less);

	EXPECT_FALSE(more < base);
	EXPECT_FALSE(more < less);

	EXPECT_TRUE(base < more);
	EXPECT_TRUE(less < base);
	EXPECT_TRUE(less < more);
}

TEST(TimeSpanTest, OperatorLTEQ)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan less(234567890LL);
	TimeSpan more(1234567890LL);
	EXPECT_TRUE(base <= same);

	EXPECT_FALSE(base <= less);

	EXPECT_FALSE(more <= base);
	EXPECT_FALSE(more <= less);

	EXPECT_TRUE(base <= more);
	EXPECT_TRUE(less <= base);
	EXPECT_TRUE(less <= more);
}

TEST(TimeSpanTest, OperatorGT)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan less(234567890LL);
	TimeSpan more(1234567890LL);
	EXPECT_FALSE(base > same);
	EXPECT_FALSE(base > more);

	EXPECT_TRUE(more > base);
	EXPECT_TRUE(more > less);
	EXPECT_TRUE(base > less);

	EXPECT_FALSE(less > base);
	EXPECT_FALSE(less > more);
}

TEST(TimeSpanTest, OperatorGTEQ)
{
	TimeSpan base(1030507090LL);
	TimeSpan same(1030507090LL);
	TimeSpan less(234567890LL);
	TimeSpan more(1234567890LL);
	EXPECT_TRUE(base >= same);

	EXPECT_FALSE(base >= more);

	EXPECT_TRUE(more >= base);
	EXPECT_TRUE(more >= less);
	EXPECT_TRUE(base >= less);

	EXPECT_FALSE(less >= base);
	EXPECT_FALSE(less >= more);
}