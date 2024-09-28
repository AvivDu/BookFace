#pragma warning(disable: 4996)
#include "Date.h"
#include <iostream>
#include<string>
using namespace std;

Date::Date()
{
	time_t now = time(0);
	tm* localTime = localtime(&now);
	this->day = localTime->tm_mday;
	this->month = localTime->tm_mon + 1;
	this->year = localTime->tm_year + 1900;

}

Date::Date(size_t day, size_t month, size_t year)
{
	//validity check of input before the obj created
	size_t localDay, localMonth, localYear;
	if (isValidDate(day, month, year))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		do {
			cout << "invalid birth date please insert valid one " << endl;
			birthdayInput(localDay, localMonth, localYear);

		} while (!isValidDate(localDay, localMonth, localYear));
		this->day = localDay;
		this->month = localMonth;
		this->year = localYear;

	}

}

void Date::getDate() const
{
	cout << day << "/" << month << "/" << year;
}

bool Date::isValidDate(size_t day, size_t month, size_t year) {
	time_t nowtime = time(0);
	tm* localTime = localtime(&nowtime);
	if (month < 1 || month > 12 || year <= 1904 || year > localTime->tm_year + 1900) {
		return false; // Month or year out of range
	}
	static const size_t daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	size_t maxDays = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year)) {
		maxDays = 29; // February in a leap year
	}
	return day >= 1 && day <= maxDays;
}

// Function to check if a year is a leap year

bool Date::isLeapYear(size_t year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::birthdayInput(size_t& day, size_t& month, size_t& year) {

	string birthday;

	// Prompt the user to enter their birthday
	cout << "Enter your birthday (dd/mm/yyyy): ";
	cin >> birthday;

	// Remove '/' from the input
	birthday.erase(remove(birthday.begin(), birthday.end(), '/'), birthday.end());

	// Check if the input has the correct length (ddmmyyyy)
	if (birthday.length() == 8) {
		// Extract day, month, and year
		string dayStr = birthday.substr(0, 2);
		string monthStr = birthday.substr(2, 2);
		string yearStr = birthday.substr(4, 4);

		// Convert strings to integers
		day = stoi(dayStr);
		month = stoi(monthStr);
		year = stoi(yearStr);
	}
}

size_t Date::getDay() const {
	return day;
}
size_t Date::getMonth() const {
	return month;
}
size_t Date::getYear() const {
	return year;
}