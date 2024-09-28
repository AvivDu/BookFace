#include "gamemenu.h"
#include"system.h"



Gamemenu::Gamemenu()
{
	this->bookfacemenu();
};


//printing book-face name
void Gamemenu::printscreen() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << ".----------------.  .----------------.  .----------------.  .----------------." << endl;
	cout << "| .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << "| |   ______     | || |     ____     | || |     ____     | || |  ___  ____   | |" << endl;
	cout << "| |  |_   _ \\    | || |   .'    `.   | || |   .'    `.   | || | |_  ||_  _|  | |" << endl;
	cout << "| |    | |_) |   | || |  /  .--.  \\  | || |  /  .--.  \\  | || |   | |_/ /    | |" << endl;
	cout << "| |    |  __'.   | || |  | |    | |  | || |  | |    | |  | || |   |  __'.    | |" << endl;
	cout << "| |   _| |__) |  | || |  \\  `--'  /  | || |  \\  `--'  /  | || |  _| |  \\ \\_  | |" << endl;
	cout << "| |  |_______/   | || |   `.____.'   | || |   `.____.'   | || | |____| |___\\ | |" << endl;
	cout << "| |              | || |              | || |              | || |              | |" << endl;
	cout << "| '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << "'----------------'  '----------------'  '----------------'  '----------------'" << endl;

	cout << "	.----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
	cout << "	|| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << "	|| |              | || |  _________   | || |      __      | || |     ______   | || |  _________   | |" << endl;
	cout << "	|| |              | || | |_   ___  |  | || |     /  \\     | || |   .' ___  |  | || | |_   ___  |  | |" << endl;
	cout << "	|| |    ______    | || |   | |_  \\_|  | || |    / /\\ \\    | || |  / .'   \\_|  | || |   | |_  \\_|  | |" << endl;
	cout << "	|| |   |______|   | || |   |  _|      | || |   / ____ \\   | || |  | |         | || |   |  _ | _   | |" << endl;
	cout << "	|| |              | || |  _| |_       | || | _/ /    \\ \\_ | || |  \\ `.___.'\\  | || |  _| |___/ |  | |" << endl;
	cout << "	|| |              | || | |_____|      | || ||____|  |____|| || |   `._____.'  | || | |_________|  | |" << endl;
	cout << "	|| |              | || |              | || |              | || |              | || |              | |" << endl;
	cout << "	|| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << "	'----------------'  '----------------'  '----------------'  '----------------'  '----------------'" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl;

}

void Gamemenu::bookfacemenu()
{
	printscreen();
	//clearscreen
	bool choice = false;
	System system;
	while (!choice)
	{
		//clearscreen
		displaymenu();
		getmenuechoice(choice, system);
		//clearscreen

	}



}
void Gamemenu::displaymenu()// menu loop uses kbhit
{
	cout << endl;
	cout << "    book-face" << endl;
	cout << "-----------------" << endl;
	cout << "press (1) for creating new friend" << endl;
	cout << "press (2) for creating a new fanpage" << endl;
	cout << "press (3) for adding status to a specific entity" << endl;
	cout << "press (4) to show all statuses of a specific user" << endl;
	cout << "press (5) to show the 10 latest status of a specific friend" << endl;
	cout << "press (6) to connect friends" << endl;
	cout << "press (7) to disconnect friends" << endl;
	cout << "press (8) to add a fan to a fanpage" << endl;
	cout << "press (9) to remove a fan from a fanpage" << endl;
	cout << "press (10) show all users in the system" << endl;
	cout << "press (11) show all friends/fans of a user/fanpage" << endl;
	cout << "press (12) exit" << endl;
}


void Gamemenu::getmenuechoice(bool& exitflag, System& system) //the switch it self
{
	size_t choice;
	cout << "please enter choice" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		system.addFriend();
		break;
	case 2:
		system.addFanPage();
		break;
	case 3:
		system.chooselist(choice);
		break;
	case 4:
		system.chooselist(choice);
		break;
	case 5:
		system.LatestStatuses();
		break;
	case 6:
		system.connectFriends();
		break;
	case 7:
		system.disconnectFriends();
		break;
	case 8:
		system.addFan();
		break;
	case 9:
		system.removeFan();
		break;
	case 10:
		system.ShowAllInSystem();
		break;
	case 11:
		system.chooselist(choice);
		break;
	case 12:
		exitflag = true;
		//flag->true->means exit
		//the detructor frees up relavant data
		break;
	default:
		cout << "unvalid choice please choose a valid number choice (from 1-12)" << endl;
		break;
	}


}


