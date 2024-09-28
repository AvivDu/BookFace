#pragma once
#include <iostream>
#include <string>
#include"profileBoard.h"


//forward declaration
class FriendClass;

class User
{
protected:
	string name;

	ProfileBoard board;

	vector<FriendClass*> friendsOrFans;

public:
	//c'tor
	User(string name);
	//add status
	void addstatus();
	//sets default statuses for default users
	void defaultStatuses(string text);

	string getname()const { return name; }

	ProfileBoard getBoard() const { return board; }

	vector<FriendClass*>& getFriendsOrFans() { return friendsOrFans; }

	friend bool operator >(User& friend1, User& friend2);

};

