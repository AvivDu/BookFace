#include "time.h"
using namespace std;
#pragma warning(disable: 4996)


Time::Time() :Date()
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    this->hours = localTime->tm_hour;
    this->minutes = localTime->tm_min;
}

size_t Time::getHours() const {
    return hours;
}

size_t Time::getMinutes() const {
    return minutes;
}

void Time::displayTimeDate() const 
{
    if (minutes < 10) {
        cout << hours << ":0" << minutes << " " << day << "/" << month << "/" << year;
    }
    else {
        cout << hours << ":" << minutes << " " << day << "/" << month << "/" << year;
    }
}


bool operator>= (const Time& left, const Time& right)
{
    //intiallize variables
    size_t yearLeft = left.getYear();
    size_t monthLeft = left.getMonth();
    size_t dayLeft = left.getDay();
    size_t hoursLeft = left.getHours();
    size_t minutesLeft = left.getMinutes();

    size_t yearRight = right.getYear();
    size_t monthRight = right.getMonth();
    size_t dayRight = right.getDay();
    size_t hoursRight = right.getHours();
    size_t minutesRight = right.getMinutes();

    // First, compare the date
    if (yearLeft > yearRight || (yearLeft == yearRight && monthLeft > monthRight) ||
        (yearLeft == yearRight && monthLeft == monthRight && dayLeft > dayRight)) {
        return true;
    }
    else if (yearLeft == yearRight && monthLeft == monthRight && dayLeft == dayRight) {
        // If the dates are equal, compare the time
        if (hoursLeft == hoursRight) {
            return (minutesLeft >= minutesRight);
        }
        else {
            return (hoursLeft > hoursRight);
        }
    }

    return false;
}
