#pragma once
class Date {
	int minutes;
	int hour;
	int day;
	int month;
	int year;
public:
	Date();
	Date(int _minutes, int _hour, int _day, int _month, int _year);
	static Date getCurrentDate();
	void displayDate();
};
