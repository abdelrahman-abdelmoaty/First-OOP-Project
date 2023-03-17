#pragma once
#include<string>
#include<vector>
#include "RentingProcess.h"
using namespace std;
class Car
{
private:
	string model;
	int maxSpeed;
	bool isRented;
	int rentingPrice;
	vector<RentingProcess>rentingProcesses;
	bool isVerified;
	//string owner;
public:
	Car(string _model, int _maxSpeed, int _rentingPrice);
	void setIsRented();
	bool getIsRented();
	void displayInfo();

};

