#pragma once
#include <iostream>
#include <vector>
#include <string>
#include"status.h"
using namespace std;


class ProfileBoard
{
	
	vector<Status> stat;

public:
	ProfileBoard();
	void addstatus(const string& status,const string& media = "0");//in ctor of status updating the time and date.//updatenumofstat
	void showAllStat();//using next and show them one by one //printing how much you see of how many you dont.//show them until you press exit once using itr to begin the while loop 

	const vector<Status> getStatuses() const; //gets all the statuses

	const Status getStatus(size_t ind) const;

};

