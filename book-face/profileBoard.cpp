#include "profileBoard.h"


ProfileBoard::ProfileBoard()
{

}

void ProfileBoard::addstatus(const string& text,const string &media)
{
	//add a new atatus and push that one inside vector
	Status temp(text, media);
	stat.push_back(temp);
}

void ProfileBoard::showAllStat()
{
	int counter = 1;
	for (const auto& status : stat)
	{
		cout << "(" << counter << ") ";
		status.displayStatus();
		counter++;
	}
}

const vector<Status> ProfileBoard::getStatuses() const
{
	return stat;
}

const Status ProfileBoard::getStatus(size_t ind) const
{
	return stat[ind];
}

