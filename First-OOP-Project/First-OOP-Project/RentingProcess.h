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
	bool isRunning;
	float cost;
	float duration;

public:
	RentingProcess(string _id, Car* _car, Date _beginningDate, bool _isRunning);
	RentingProcess();
	RentingProcess(string _id ,string _carOwner,Car* _car, Date _beginningDate,float cost,float duration, bool _isRunning);
	void displayInfo();	
	Car* getCar();
	string getWhatToWrite();

};

