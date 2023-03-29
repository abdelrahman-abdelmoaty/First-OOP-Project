#pragma once
class Date {
public:
	int minutes;
	int hour;
	int day;
	int month;
	int year;
	Date();
	Date(int _minutes, int _hour, int _day, int _month, int _year);
	static Date getCurrentDate();
	void displayDate();
	Date(string _date);




};
