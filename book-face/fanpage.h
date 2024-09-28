#pragma once
#include<vector>
#include<iostream>

#include"Time.h"
#include"profileBoard.h"
#include "user.h"

//forward declaration
class FriendClass;

class Fanpage: public User
{

public:

	Fanpage(string name);

	void  makechoice(size_t choice);

	template<class T>
	friend void printAllList(const std::vector<T*>& vec);

	// adds fan to fanpage
	friend const Fanpage& operator +=(Fanpage& fanpage, FriendClass& fan);

	void removeFan(FriendClass& fan);
};