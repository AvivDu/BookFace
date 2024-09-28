#pragma once

#include<vector>
#include<iostream>
#include <iterator>
#include<string>


#include "profileBoard.h"
#include "user.h"
#include"fanpage.h"
#include"friendclass.h"


//forward declaration
class Fanpage;
class FriendClass;


class System
{

	vector<FriendClass*> friendLst;

	vector<Fanpage*> fanpages;

	ProfileBoard board;

	//System(const System& user) = default;


public:

	System();
	
	System(const System& other);

	~System();

	System& operator=(const System& other);

	void defaultUsers();

	void setfriendNum(const int) {}

	//creation func's
	void addFanPage();
	void birthdayInput(size_t& day, size_t& month, size_t& year);
	void addFriend();

	//valid name func's
	bool validFanpageName(string fanpagename);
	bool validFriendName(string fanpagename);

	//getter func's
	vector <FriendClass*> getfriendlst() { return friendLst; }
	vector <Fanpage*> getfanpageslst() { return fanpages; }

	//printing lists
	template<class T>
	friend void printAllList(const vector<T*>& vec);

	void chooselist(size_t syschoice);

	//shows all entity's that are signed up to BookFace
	void ShowAllInSystem();

	//all friend related func's
	void LatestStatuses();
	void connectFriends();
	void connectnow(size_t friend1, size_t friend2);
	void disconnectFriends();
	void disconnectnow(size_t friend1, size_t friend2);

	//validity func's
	bool checkConection(size_t friend1, size_t friend2);//checks if the friends are already connected or not
	bool validChoice(size_t friendID, size_t numFriends);//checks if the number is in range
	bool checkFan(size_t fanpage, size_t fan);//checks if the fan already likes this page

	//all related fanpage
	void addFan();
	void likeFanPage(size_t fanPage, size_t fan);
	void removeFan();
	void unlikeFanPage(size_t fanPage, size_t fan);

};
