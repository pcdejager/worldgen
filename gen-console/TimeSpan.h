#pragma once

class TimeSpan
{
public:
	/// <summary>
	/// Default contructor
	/// </summary>
	TimeSpan();

	/// <summary>
	/// Construct a TimeSpan with a specified number of ticks
	/// </summary>
	/// <param name="totalSpan">Number of ticks in the span</param>
	TimeSpan(__int64 totalSpan);

	/// <summary>
	/// Construct a TimeSpan with a set duration
	/// </summary>
	/// <param name="hours">Number of hours</param>
	/// <param name="minutes">Number of minutes</param>
	/// <param name="seconds">Number of seconds</param>
	/// <param name="negative">Is the duration negative?</param>
	TimeSpan(__int64 hours, __int64 minutes, __int64 seconds, bool negative = false);

	/// <summary>
	/// Construct a TimeSpan with a set duration
	/// </summary>
	/// <param name="days">Number of days</param>
	/// <param name="hours">Number of hours</param>
	/// <param name="minutes">Number of minutes</param>
	/// <param name="seconds">Number of seconds</param>
	/// <param name="negative">Is the duration negative?</param>
	TimeSpan(__int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative = false);

	/// <summary>
	/// Construct a TimeSpan with a set duration
	/// </summary>
	/// <param name="years">Number of years</param>
	/// <param name="days">Number of days</param>
	/// <param name="hours">Number of hours</param>
	/// <param name="minutes">Number of minutes</param>
	/// <param name="seconds">Number of seconds</param>
	/// <param name="negative">Is the duration negative?</param>
	TimeSpan(__int64 years, __int64 days, __int64 hours, __int64 minutes, __int64 seconds, bool negative = false);

	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="rhs">The TimeSpan to copy</param>
	TimeSpan(const TimeSpan& rhs) = default;

	/// <summary>
	/// Move constructor
	/// </summary>
	/// <param name="rhs">The TimeSpan to move</param>
	/// <returns></returns>
	TimeSpan(TimeSpan&& rhs) noexcept;

	~TimeSpan() = default;

	/// <summary>
	/// Assignment operator
	/// </summary>
	/// <param name="rhs">The TimeSpan to assign to this one</param>
	/// <returns>The new TimeSpan</returns>
	TimeSpan& operator=(const TimeSpan& rhs) = default;

	/// <summary>
	/// Move assignment operator
	/// </summary>
	/// <param name="rhs">The TimeSpan to move to this one</param>
	/// <returns>The new TimeSpan</returns>
	TimeSpan& operator=(TimeSpan&& rhs) noexcept;

public:
	/// <summary>
	/// Get the number of ticks in the duration
	/// </summary>
	/// <returns>The total number of ticks</returns>
	__int64 Ticks() const { return span; }

	/// <summary>
	/// Get the number of seconds [0..number of seconds in a minute)
	/// </summary>
	/// <returns>Number of seconds in the duration</returns>
	__int64 Seconds() const;

	/// <summary>
	/// Get the number of minutes [0..number of minutes in an hour)
	/// </summary>
	/// <returns>Number of minutes in the duration</returns>
	__int64 Minutes() const;

	/// <summary>
	/// Get the number of hours [0..number of hours in a day)
	/// </summary>
	/// <returns>Number of hours in the duration</returns>
	__int64 Hours() const;

	/// <summary>
	/// Get the number of days [0..number of days in a year)
	/// </summary>
	/// <returns>Number of yuears in the duration</returns>
	__int64 Days() const;

	/// <summary>
	/// Get the number of years
	/// </summary>
	/// <returns>Number of years in the duration</returns>
	__int64 Years() const;

	/// <summary>
	/// Is the duration negative?
	/// </summary>
	/// <returns>True if negative, else false</returns>
	bool Negative() const;

	/// <summary>
	/// Get the total number of seconds in the duration
	/// </summary>
	/// <returns>Number of seconds</returns>
	__int64 TotalSeconds() const;

	/// <summary>
	/// Get the total number of minutes in the duration
	/// </summary>
	/// <returns>Number of minutes</returns>
	__int64 TotalMinutes() const;

	/// <summary>
	/// Get the total number of hours in the duration
	/// </summary>
	/// <returns>Number of hours</returns>
	__int64 TotalHours() const;

	/// <summary>
	/// Get the total number of days in the duration
	/// </summary>
	/// <returns>Number of days</returns>
	__int64 TotalDays() const;

	/// <summary>
	/// Get the total number of years in the duration
	/// </summary>
	/// <returns>Number of years</returns>
	__int64 TotalYears() const;

public:
	TimeSpan& operator+=(const TimeSpan& rhs);
	TimeSpan operator+(const TimeSpan& rhs);
	TimeSpan& operator-=(const TimeSpan& rhs);
	TimeSpan operator-(const TimeSpan& rhs);
	TimeSpan& operator*=(__int64 value);
	TimeSpan operator*(__int64 value);
	TimeSpan& operator/=(__int64 value);
	TimeSpan operator/(__int64 value);

public:
	bool operator==(const TimeSpan& rhs) const;
	bool operator!=(const TimeSpan& rhs) const;
	bool operator<(const TimeSpan& rhs) const;
	bool operator<=(const TimeSpan& rhs) const;
	bool operator>(const TimeSpan& rhs) const;
	bool operator>=(const TimeSpan& rhs) const;

private:
	__int64 span;
};

