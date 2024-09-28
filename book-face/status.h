#pragma once

#include"Time.h"
#include<iostream>
#include <string>

using namespace std;

class Status
{
	string text;
	string media;
	Time postTime;

public:
	Status() = delete;
	Status(const string& text, const string& media = "0");
	void displayStatus() const;
	const Time& getPostTime() const;
	friend bool operator==(Status& status1, Status& status2);
	friend bool operator!=(Status& status1, Status& status2);

};


