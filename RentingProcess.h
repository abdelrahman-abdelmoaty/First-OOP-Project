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
	string carOwner;
	string carRenter;
	//Car rentedCar;
	Date beginningDate;
	Date endDate;
	bool isRunning;

public:
	RentingProcess();
	static vector<RentingProcess> readF();
	void displayInfo();
	bool checkRunning(Date end);
	RentingProcess(string s1, string s2, Date start, Date time);
	string getWhatToWrite();

};

