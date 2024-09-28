#pragma once
#include<vector>
#include<iostream>

#include"Time.h"
#include"profileBoard.h"
#include "user.h"

//forward declaration
//class User;
class Fanpage;

class FriendClass : public User
{

	Date birthday;//FriendClass

	vector<Fanpage*> fanedpages;


public:

	FriendClass(string name, size_t day, size_t month, size_t year);

	template<class T>
	friend void printAllList(const vector<T*>& vec);

	//chooses which action to use from menu
	void makechoice(size_t choice);

	//adds friend to friendLst
	friend const FriendClass& operator +=(FriendClass& user, FriendClass& newfriend);

	//removes friend from friendLst
	void removefriend(FriendClass& disfriend);

	bool checkConnection(FriendClass& potFriend);//checks if friends are connected

	void showLatestFriendsStatuses();

	//fan page related func's
	
	//adds fanpage to fanedpages
	friend const FriendClass& operator +=(FriendClass& user, Fanpage& fanpage);

	//removes fanpage from fanedpages
	void unlikePage(Fanpage& fanpage);

	//checks if friend is a fan of this fanpage
	bool checkFan(Fanpage& fanpage);

	//func for testing
	bool statComp();

};

