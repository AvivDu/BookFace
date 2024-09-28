#pragma warning(disable : 4996) 
#include"status.h"
#include<iostream>
using namespace std;

// Constructor that receives text and saves the current time
Status::Status(const string& text, const string& media)
	: text(text), media(media), postTime()
{
	// The postTime object will be initialized with the current date and time

}

void Status::displayStatus() const
{
	// Display status and post time
	cout << "Status: " << text << endl;
	//checks for media in status
	if (media != "0") {
		string mediaFolder = "./project_media/";
		string fullPath = mediaFolder + media;
		string command = "start " + fullPath;
		system(command.c_str());
		cout << "displayed media "<< endl;
	}
	cout << "Posted at: ";
	postTime.displayTimeDate();
	cout << endl;
}

const Time& Status::getPostTime() const //changed Date& to Time& for operand overload
{
	return postTime;
}

bool operator==(Status& status1, Status& status2) {
	return status1.text == status2.text;
}

bool operator!=(Status& status1, Status& status2) {
	return status1.text != status2.text;
}

