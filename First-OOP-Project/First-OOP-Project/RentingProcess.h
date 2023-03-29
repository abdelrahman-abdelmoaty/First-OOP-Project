#pragma once
#include <iostream>
#include <string>
#include "Car.h"
#include "Date.h"
using namespace std;

class RentingProcess
{
private:
	string id;
	string carOwner;
	Car* car;
	Date beginningDate;
	bool isRunning;
	float cost;
	float duration;

public:
	RentingProcess();
	RentingProcess(string _id ,Car* _car, Date _beginningDate, bool _isRunning);
	void displayInfo();
	bool checkRunning(Date end);
	Car* getCar();
	string getWhatToWrite();

};

