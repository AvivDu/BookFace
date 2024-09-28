#pragma once
#include <ctime>



class Date
{
protected:
	size_t day;
	size_t month;
	size_t year;
  
public:

	Date();//for status/fanpage without time

	Date(size_t day, size_t month, size_t year);//for friend
	
	bool isValidDate(size_t day, size_t month, size_t year);
	bool isLeapYear(size_t year);

	void getDate() const;

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

	void birthdayInput(size_t& day, size_t& month, size_t& year);
};
