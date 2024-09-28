#pragma once
#include "fanpage.h"
#include "time.h"
#include<iostream>
#include<string>
#include"FriendClass.h"
using namespace std;
#pragma warning(disable: 4996)

Fanpage::Fanpage(string name) :User(name){}

void Fanpage::makechoice(size_t choice)
{
	switch (choice)
	{
	case 3:
		addstatus();
		break;
	case 4:
		board.showAllStat();
		break;
	case 11:
		printAllList(friendsOrFans);
		break;
	default:
		break;
	}
}

const Fanpage& operator +=( Fanpage& fanpage, FriendClass& fan) {
	fanpage.friendsOrFans.push_back(&fan);
	return fanpage;
}

//bool operator >(Fanpage& fanpage1, Fanpage& fanpage2) {
//	return fanpage1.fanLst.size() > fanpage2.fanLst.size();
//}

void Fanpage::removeFan(FriendClass& fan)
{
	for (auto it = friendsOrFans.begin(); it != friendsOrFans.end(); ++it)
	{
		if (*it == &fan)
		{
			friendsOrFans.erase(it);
			return; // Exit loop after erasing the element
		}
	}
}