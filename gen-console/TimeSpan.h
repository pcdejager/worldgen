#pragma once

class TimeSpan
{
public:
	TimeSpan();
	TimeSpan(__int64 totalSpan);
	TimeSpan(__int64 hours, __int64 minutes, __int64 seconds, bool negative = false);
	TimeSpan(__int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative = false);
	TimeSpan(__int64 years, __int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative = false);
	TimeSpan(const TimeSpan&) = default;
	TimeSpan(const TimeSpan&&) noexcept;
	~TimeSpan() = default;

	TimeSpan& operator=(const TimeSpan&) = default;
	TimeSpan& operator=(const TimeSpan&&) noexcept;

public:
	__int64 Ticks() { return span; }

	__int64 Seconds();
	__int64 Minutes();
	__int64 Hours();
	__int64 Days();
	__int64 Years();
	bool Negative();

	__int64 TotalSeconds();
	__int64 TotalMinutes();
	__int64 TotalHours();
	__int64 TotalDays();
	__int64 TotalYears();

public:
	TimeSpan& operator+=(const TimeSpan& rhs);
	TimeSpan& operator-=(const TimeSpan& rhs);
	TimeSpan& operator*=(__int64 value);
	TimeSpan& operator/=(__int64 value);
private:
	__int64 span;
};

