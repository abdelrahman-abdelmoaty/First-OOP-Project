#pragma once
#include<string>
#include<vector>
#include "RentingProcess.h"
using namespace std;
class Car
{
private:
	string id;
	string model;
	string carOwnerID;
	//  we may not need it 

	
	int maxSpeed;
	bool isRented;
	int rentingPrice;
	//vector<RentingProcess>rentingProcesses;
	// most probably will not need it  
	bool isVerified;
	// initializedWithFalse
	

	//string owner;
public:
	Car();
	Car(string _model, int _maxSpeed, int _rentingPrice);
	void setIsRented();
	bool getIsRented();
	void displayInfo();
	string getModel();
	string getID();

};

