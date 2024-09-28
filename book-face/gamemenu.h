#pragma once

#include <windows.h>
#include <process.h>
#include <iostream>
#include <conio.h>
#include "FriendClass.h"
#include"fanpage.h"
#include "system.h"
using namespace std;


class Gamemenu
{ 
	bool exit = false;
	// every time new member or page is created he/it will be added to System (opteniol using vector)
	enum choice{ADD_FRIEND=1,ADD_FAN_PAGE,ADD_STAT,SHOW_ALL_STAT,LAST_TEN,LNK_FRIENDS
		,UNLNK_FRIENDS,ADD_FAN,REMOVE_FAN,SHOW_System,SHOW_ALL_FRIENDS_OR_FANS,EXIT};
	void printscreen() ;
	//bool exit() { return true;};


public:
	//exit();
	Gamemenu();//print the screen and start the menu loop//making mainfriend+System+initillize freind...
	
	void displaymenu();
	void getmenuechoice(bool& exitflag, System& system);
		//size_t validchoice(size_t choice);
		
	void showAllSystem();//using hash of strings
	
	void bookfacemenu();


}; 

