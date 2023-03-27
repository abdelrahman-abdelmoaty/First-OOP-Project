#include "Date.h"
#include <iostream>
#include <ctime>

using namespace std;
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
Date::Date() {
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    day = local_time.tm_mday + 1;
    month = local_time.tm_mon + 1;
    year = local_time.tm_year + 1900;
}
void Date::displayDate() {
    cout << "day:  " << day << " , ";
    cout << "month:  " << month << " , ";
    cout << "year:  " << year << endl;
}