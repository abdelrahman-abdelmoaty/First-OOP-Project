#include "Date.h"
#include <iostream>
#include <ctime>



Date Date::getCurrentDate() {
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    day = local_time.tm_mday + 1;
    month = local_time.tm_mon + 1;
    year = local_time.tm_year + 1900;
    Date x;
    return x;
}