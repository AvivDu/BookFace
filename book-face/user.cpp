#include "user.h"

using namespace std;

User::User(string name) :name(name) {}

void User::addstatus()
{
	string text, mediaLoc;
	int choice;
	cout << "what kind of status would you like to post?" << endl;
	cout << "(1) text" << endl;
	cout << "(2) text and media" << endl;
	cin >> choice;
	cout << endl << "please enter text:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//clears buffer
	getline(cin, text);
	switch (choice) {
	case 1:
		board.addstatus(text);
		break;
	case 2:
		cout << endl <<"media file name including .type: " << endl;//for testing write dogGeneral.jpg
		getline(cin, mediaLoc);
		board.addstatus(text, mediaLoc);
	}

}

void User::defaultStatuses(string text) {
	board.addstatus(text);
}

bool operator >(User& friend1, User& friend2) {
	return friend1.friendsOrFans.size() > friend2.friendsOrFans.size();
}