#pragma once
#include <iostream>
#include <string>
#include "Car.h"
#include "Date.h"
using namespace std;

class RentingProcess
{
private:
	// Omar Ahmed 
	// it will contain class attribute 
	string id;
	string carOwner;
	//string carRenter;
	Car* car;
	Date beginningDate;
	Date endDate;
	bool isRunning;

public:
	RentingProcess();
	RentingProcess(string _id ,Car* _car, Date _beginningDate, bool _isRunning);
	static vector<RentingProcess> readF();
	void displayInfo();
	bool checkRunning(Date end);
	Car* getCar();
	RentingProcess(string s1, string s2, Date start, Date time);
	string getWhatToWrite();

};

