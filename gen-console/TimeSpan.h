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
	__int64 Ticks() const { return span; }

	__int64 Seconds() const;
	__int64 Minutes() const;
	__int64 Hours() const;
	__int64 Days() const;
	__int64 Years() const;
	bool Negative() const;

	__int64 TotalSeconds() const;
	__int64 TotalMinutes() const;
	__int64 TotalHours() const;
	__int64 TotalDays() const;
	__int64 TotalYears() const;

public:
	TimeSpan& operator+=(const TimeSpan& rhs);
	TimeSpan& operator-=(const TimeSpan& rhs);
	TimeSpan& operator*=(__int64 value);
	TimeSpan& operator/=(__int64 value);
private:
	__int64 span;
};

