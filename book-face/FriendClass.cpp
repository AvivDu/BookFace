#include "FriendClass.h"
#include<iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)


FriendClass::FriendClass(string name, size_t day, size_t month, size_t year)
	:User(name), birthday(day, month, year) {}

void FriendClass::makechoice(size_t choice)
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

const FriendClass& operator +=(FriendClass& user, FriendClass& newfriend) {
	user.friendsOrFans.push_back(&newfriend);
	return user;
}

void FriendClass::removefriend(FriendClass& disfriend)
{
	for (auto it = friendsOrFans.begin(); it != friendsOrFans.end(); ++it)
	{
		if (*it == &disfriend)
		{
			friendsOrFans.erase(it);
			return; // Exit loop after erasing the element
		}
	}
}

bool FriendClass::checkConnection(FriendClass& potFriend)
{
	for (auto it = friendsOrFans.begin(); it != friendsOrFans.end(); ++it)
	{
		if (*it == &potFriend)
		{
			return true;//if they are friends return true
		}
	}
	return false;//if they aren't friends returns false
}

const FriendClass& operator +=(FriendClass& user, Fanpage& fanpage) {
	user.fanedpages.push_back(&fanpage);
	return user;
}

void FriendClass::unlikePage(Fanpage& fanpage)
{
	for (auto it = fanedpages.begin(); it != fanedpages.end(); ++it)
	{
		if (*it == &fanpage)
		{
			fanedpages.erase(it);
			return; // Exit loop after erasing the element
		}
	}
}

bool FriendClass::checkFan(Fanpage& fanpage) {
	for (auto it = fanedpages.begin(); it != fanedpages.end(); ++it)
	{
		if (*it == &fanpage)
		{
			return true; // if the fanpage appear's in the liked fan pages of this friend
		}
	}
	return false;
}


void FriendClass::showLatestFriendsStatuses()
{
	const int size = 10;
	Status* arr[size]; //an arr of pointers to statuses
	bool newer = true;

	//sets arr to null
	for (int i = 0; i < size; i++) {
		arr[i] = nullptr;
	}

	//go over all friends in friendslist
	for (FriendClass* currFriend : friendsOrFans)
	{
		ProfileBoard fBoard = currFriend->getBoard();//get status board of this friend
		vector<Status> fStatuses = fBoard.getStatuses();//get the vector of the statuses

		// Iterate through the friend's statuses
		for (const Status status : fStatuses)
		{
			// Find an empty slot in the array or replace an older status
			for (int i = 0; i < size; ++i)
			{
				if (arr[i] != nullptr) {
					newer = status.getPostTime() >= arr[i]->getPostTime();//checks which statues is newer
				}
				if (arr[i] == nullptr || newer)
				{
					if (newer) {
						//push the older status into the end of the arr
						for (int j = size - 1; j > i; j--) {
							arr[j] = arr[j - 1];
						}

					}
					// Replace the older status or insert into an empty slot
					arr[i] = nullptr;
					arr[i] = new Status(status); // Copy the latest status
					break;
				}
			}
		}

	}

	// Display the latest statuses in the array
	cout << "Latest Statuses for " << name << ":" << endl << endl;
	for (int i = 0; i < size && arr[i] != nullptr; ++i)
	{
		cout << "[" << i + 1 << "] ";
		arr[i]->displayStatus();
		cout << endl;
	}

	// Clean up memory allocated for the array
	for (int i = 0; i < size; ++i)
	{
		delete arr[i];
	}
}

//func for testing > operator
/*bool FriendClass::statComp()
{
	int pick1, pick2, size;
	vector<Status> allStatus = board.getStatuses();
	size = allStatus.size();
	board.showAllStat();
	cout << "choose 2 Statuses to compare" << endl;
	cin >> pick1 >> pick2;
	pick1--;
	pick2--;
	while (pick1 < 0 || pick2 < 0 || pick1 >= size || pick2 >= size)
	{
		cout << "invalid choice please choose again 2 Statuses to compare" << endl;
		board.showAllStat();
		cin >> pick1 >> pick2;
		pick1--;
		pick2--;
	}

	return allStatus[pick1] == allStatus[pick2];

}*/