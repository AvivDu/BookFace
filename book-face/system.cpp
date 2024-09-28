#include "system.h"
#include<vector>
#include<iostream>
#include <algorithm>
#include <sstream>
using namespace std;



System::System()
{
	//default users of BookFace
	defaultUsers();
}

System::System(const System& other) {
	// Delete existing dynamic memory
	for (auto& friendPtr : friendLst) {
		delete friendPtr;
	}
	friendLst.clear();

	for (auto& fanpagePtr : fanpages) {
		delete fanpagePtr;
	}
	fanpages.clear();

	// Copy dynamic memory for friendLst
	for (const auto& friendPtr : other.friendLst) {
		friendLst.push_back(new FriendClass(*friendPtr));
	}

	// Copy dynamic memory for fanpages
	for (const auto& fanpagePtr : other.fanpages) {
		fanpages.push_back(new Fanpage(*fanpagePtr));
	}
}

System::~System() {
	// Delete dynamic memory for friendLst
	for (auto& friendPtr : friendLst) {
		delete friendPtr;
	}
	friendLst.clear();  // Clear the vector after deleting the objects

	// Delete dynamic memory for fanpages
	for (auto& fanpagePtr : fanpages) {
		delete fanpagePtr;
	}
	fanpages.clear();// Clear the vector after deleting the objects
}

System& System::operator=(const System& other) {
	if (this != &other) { // Check for self-assignment
		// Copy dynamic memory from other object
		vector<FriendClass*> newFriendLst;
		vector<Fanpage*> newFanpages;

		for (const auto& friendPtr : other.friendLst) {
			newFriendLst.push_back(new FriendClass(*friendPtr));
		}

		for (const auto& fanpagePtr : other.fanpages) {
			newFanpages.push_back(new Fanpage(*fanpagePtr));
		}

		// Delete existing dynamic memory
		for (auto& friendPtr : friendLst) {
			delete friendPtr;
		}
		friendLst.clear();  // Clear the vector after deleting the objects

		for (auto& fanpagePtr : fanpages) {
			delete fanpagePtr;
		}
		fanpages.clear(); // Clear the vector after deleting the objects

		// Assign new values
		friendLst = move(newFriendLst);
		fanpages = move(newFanpages);
	}
	return *this;
}

void System::defaultUsers()
{
	// initialize users
	friendLst.push_back(new FriendClass("Niv", 23, 9, 1995));
	friendLst.push_back(new FriendClass("Aviv", 22, 10, 1998));
	friendLst.push_back(new FriendClass("Amit", 15, 10, 2000));
	fanpages.push_back(new Fanpage("Iron Man Fanpage"));
	fanpages.push_back(new Fanpage("Adir Miller Fanpage"));
	fanpages.push_back(new Fanpage("IDF Fanpage"));
	//connect aviv and amit
	*friendLst[1] += (*friendLst[2]);
	*friendLst[2] += (*friendLst[1]);
	//niv likes idf fan page
	*fanpages[2] += (*friendLst[0]);
	*friendLst[0] += (*fanpages[2]);
	//aviv likes iron man fanpage
	*fanpages[0] += (*friendLst[1]);
	*friendLst[1] += (*fanpages[0]);

	// add statuses
	//status of aviv
	(*friendLst[1]).defaultStatuses("hi i'm aviv");
	(*friendLst[1]).defaultStatuses("building this project took a lot of time");
	//status of niv
	(*friendLst[0]).defaultStatuses("BookFace is the best");
	(*friendLst[0]).defaultStatuses("i dont like facebook");
	//status of amit
	(*friendLst[2]).defaultStatuses("hi i'm amit");
	(*friendLst[2]).defaultStatuses("bookface is fun there's no ads");
	//statuses of iron man fanpage
	(*fanpages[0]).defaultStatuses("iron man 1 was the best iron man movie");
	(*fanpages[0]).defaultStatuses("iron man is the best superhero");
	//statuses of adir miller fanpage
	(*fanpages[1]).defaultStatuses("next show is saturday");
	(*fanpages[1]).defaultStatuses("adir miller is so funny");
	//statuses of idf fanpage
	(*fanpages[2]).defaultStatuses("the strongest in the world");
	(*fanpages[2]).defaultStatuses("we salute all the brave soldiers");
	//connect aviv and niv
	*friendLst[1] += (*friendLst[0]);
	*friendLst[0] += (*friendLst[1]);
	//connect amit and niv
	*friendLst[2] += (*friendLst[0]);
	*friendLst[0] += (*friendLst[2]);

	//testing > func (there is a func in friendclass that is only for this so its under comment)
	/*if (*friendLst[1] > *friendLst[2]) {
		cout << friendLst[1]->getname();
	}
	else {
		cout << friendLst[2]->getname();
	}
	cout << " has more friends" << endl;
	if (*fanpages[0] > *fanpages[1]) {
		cout << fanpages[0]->getname();
	}
	else {
		cout << fanpages[1]->getname();
	}
	cout << " has more fans" << endl;*/

	//testing == func
	/*(*friendLst[0]).defaultStatuses("i dont like facebook");
	friendLst[0]->statComp();*/
}

void System::addFanPage()
{
	string fanPageName;
	cout << "please enter a fanpage name" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fanPageName);
	if (fanpages.empty())
	{
		fanpages.push_back(new Fanpage(fanPageName));
	}
	else {

		while (validFanpageName(fanPageName))
		{

			cout << "name already taken, please pick other name for your fanpage" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, fanPageName);
		}
		fanpages.push_back(new Fanpage(fanPageName));
	}
}

void System::addFriend()
{
	string friendName;
	size_t day = 0, month = 0, year = 0;
	cout << "please enter your name" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, friendName);
	if (friendLst.empty()) {
		birthdayInput(day, month, year);
		friendLst.push_back(new FriendClass(friendName, day, month, year));
	}
	else {
		while (validFriendName(friendName)) {
			cout << "name already taken, please pick other name for your user" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, friendName);
		}
		birthdayInput(day, month, year);
		friendLst.push_back(new FriendClass(friendName, day, month, year));
	}
}

void System::birthdayInput(size_t& day, size_t& month, size_t& year) {

	string birthday;

	// Prompt the user to enter their birthday
	cout << "Enter your birthday (dd/mm/yyyy): " << endl;
	cin >> birthday;


	// Remove '/' from the input
	birthday.erase(remove(birthday.begin(), birthday.end(), '/'), birthday.end());

	// Check if the input has the correct length (ddmmyyyy)
	if (birthday.length() == 8) {
		// Extract day, month, and year
		string dayStr = birthday.substr(0, 2);
		string monthStr = birthday.substr(2, 2);
		string yearStr = birthday.substr(4, 4);

		// Convert strings to integers
		day = stoi(dayStr);
		month = stoi(monthStr);
		year = stoi(yearStr);
	}
}

bool System::validFanpageName(string fanpagename)
{
	for (auto& page : fanpages)
	{
		if (page->getname() == fanpagename)
		{
			return true;
		}

	}

	return false;
}

bool System::validFriendName(string friendName)
{
	for (auto& page : friendLst)
	{
		if (page->getname() == friendName)
		{
			return true;
		}

	}

	return false;
}

template<class T>
void printAllList(const vector<T*>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << "(" << i + 1 << ") " << vec[i]->getname() << std::endl;
	}
}

//func chooses a friend/fanpage and returns pointer to that entity
template<class T>
T& chooseFromlist(const vector<T*>& vec)
{
	size_t j;
	if (typeid(T) == typeid(FriendClass))
		cout << "choose friend" << endl;
	else
		cout << "choose fanpage" << endl;
	cin >> j;
	//valid check (if(j=<0||j>vec.size()-1)
	return *(vec[j - 1]);
}

void System::chooselist(size_t syschoice)
{
	size_t choice;//add validfunc
	cout << "please choose list " << endl << "(1) for friend" << endl << "(2) for fanpages" << endl;
	cin >> choice;
	//TODO validcheck
	//choose entity
	switch (choice)
	{
	case 1:
		printAllList(friendLst);

		(chooseFromlist(friendLst)).makechoice(syschoice);
		break;
	case 2:

		printAllList(fanpages);

		(chooseFromlist(fanpages)).makechoice(syschoice);
		break;
	}
}

void System::ShowAllInSystem()
{
	cout << "all friends in book-face" << endl;
	printAllList(friendLst);
	cout << "all fanpages in book-face" << endl;
	printAllList(fanpages);
}

void System::LatestStatuses()
{
	size_t friend1;
	printAllList(friendLst);
	cout << "choose friend" << endl;
	cin >> friend1;
	//validity check
	while (!validChoice(friend1, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> friend1;
	}
	friend1--;
	friendLst[friend1]->showLatestFriendsStatuses();
}

void System::connectFriends()
{
	size_t friend1, friend2;
	printAllList(friendLst);
	cout << "choose friend" << endl;
	cin >> friend1;
	//validity check
	while (!validChoice(friend1, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> friend1;
	}

	//choosing friend2
	printAllList(friendLst);
	cout << "choose other friend" << endl;
	cin >> friend2;
	//validity check
	while (!validChoice(friend2, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> friend2;
	}
	//because vector placement starts at 0 not 1
	friend1--;
	friend2--;
	if (friend1 == friend2) {
		cout << "you can't choose the same person" << endl;
	}
	//check if these friends are already connected
	else if (checkConection(friend1, friend2)) {
		cout << "they are already connected" << endl;
	}
	else {
		connectnow(friend1, friend2);
	}
}
void System::connectnow(size_t friend1, size_t friend2)
{
	*friendLst[friend1] += *friendLst[friend2];
	*friendLst[friend2] += *friendLst[friend1];
}


void System::disconnectFriends()
{

	size_t friend1, friend2;
	printAllList(friendLst);
	cout << "choose friend" << endl;
	cin >> friend1;
	//validity check
	while (!validChoice(friend1, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> friend1;
	}
	printAllList(friendLst);
	cout << "choose other friend" << endl;
	cin >> friend2;
	//validity check
	while (!validChoice(friend2, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> friend2;
	}
	//because vector placement starts at 0 not 1
	friend1--;
	friend2--;
	if (friend1 == friend2) {
		cout << "you can't choose the same person" << endl;
	}
	//check if they're friends in the first place 
	else if (checkConection(friend1, friend2)) {
		disconnectnow(friend1, friend2);
	}
	else {
		cout << "they weren't connected in the first place" << endl;
	}

	//supposed to go back to main menu
}
void System::disconnectnow(size_t friend1, size_t friend2)
{
	friendLst[friend1]->removefriend(*friendLst[friend2]);
	friendLst[friend2]->removefriend(*friendLst[friend1]);
}

bool System::checkConection(size_t friend1, size_t friend2)
{
	return (friendLst[friend1]->checkConnection(*friendLst[friend2]));

}
bool System::validChoice(size_t chosenUser, size_t numUsers)
{
	return (chosenUser >= 1 && chosenUser <= numUsers);
}
bool System::checkFan(size_t fanpage, size_t fan)
{
	return friendLst[fan]->checkFan(*fanpages[fanpage]);
}

void System::addFan() {

	size_t fan, fanpage;
	//choose fanpage
	printAllList(fanpages);
	cout << "choose a fanpage you want to add a fan to" << endl;
	cin >> fanpage;
	//validity check
	while (!validChoice(fanpage, fanpages.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> fanpage;
	}
	//choose fan for fanpage
	printAllList(friendLst);
	cout << "choose a fan" << endl;
	cin >> fan;
	//validity check
	while (!validChoice(fan, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> fan;
	}
	//because vector placement starts at 0 not 1
	fanpage--;
	fan--;
	//check if hes already a fan
	if (checkFan(fanpage, fan)) {
		cout << "this friend is already a fan of this page" << endl;
	}
	else {
		likeFanPage(fanpage, fan);
	}
}
void System::likeFanPage(size_t fanpage, size_t fan) {
	*fanpages[fanpage] += *friendLst[fan];
	*friendLst[fan] += *fanpages[fanpage];
}

void System::removeFan()
{
	size_t fan, fanpage;
	//choose fanpage
	printAllList(fanpages);
	cout << "choose a fanpage you want to remove a fan from" << endl;
	cin >> fanpage;
	//validity check
	while (!validChoice(fanpage, fanpages.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> fanpage;
	}
	//choose fan for fanpage
	printAllList(friendLst);
	cout << "choose a fan" << endl;
	cin >> fan;
	//validity check
	while (!validChoice(fan, friendLst.size())) {
		cout << "invalid choice, please try again" << endl;
		cin >> fan;
	}
	//because vector placement starts at 0 not 1
	fanpage--;
	fan--;
	//check if hes not a fan
	if (checkFan(fanpage, fan)) {
		unlikeFanPage(fanpage, fan);
	}
	else {
		cout << "this friend wasn't a fan of this page" << endl;
	}

}
void System::unlikeFanPage(size_t fanpage, size_t fan) {
	fanpages[fanpage]->removeFan(*friendLst[fan]);
	friendLst[fan]->unlikePage(*fanpages[fanpage]);
}


