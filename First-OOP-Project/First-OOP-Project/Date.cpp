#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

Date::Date(){
    minutes = hour = day = month = year = 0;
}

Date::Date(int _minutes, int _hour, int _day, int _month, int _year){
    minutes = _minutes;
    hour = _hour;
    day = _day;
    month = _month;
    year = _year;
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    int _minutes = local_time.tm_min;
    int _hour = local_time.tm_hour;
    int _day = local_time.tm_mday + 1;
    int _month = local_time.tm_mon + 1;
    int _year = local_time.tm_year + 1900;
    Date currentDate(_minutes, _hour, _day, _month, _year);
    return currentDate;
}

void Date::displayDate(){
    cout << day << "/" << month << "/" << year << " " << hour << ":" << minutes;
}
