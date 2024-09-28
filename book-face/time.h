#pragma once

#include"Date.h"
#include <iostream>

class Time :public Date
{
private:

	size_t minutes;
	size_t  hours;
 
public:

	Time();

	size_t getHours() const;
	size_t getMinutes() const;
	void displayTimeDate() const;

	friend bool operator>= (const Time& left, const Time& right);
};

