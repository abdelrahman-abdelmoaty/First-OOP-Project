#pragma once
#include<vector>
#include "User.h"
#include "Car.h"
#include "Renter.h"
#include "Owner.h"
#include <fstream>
#include<iostream>	
#include<string>
using namespace std;

class Organization {

public:
	static vector<User*> allUsers;
	static vector<Car> allCars;
	static vector<Notification> allNotifications;
	static vector<RentingProcess> allRentingProcesses;
	Organization();
	Organization(int nOfCars,int nOfRentings);
	static void readFiles();
	static void writeFiles();
	static vector<Car> readCars();
	static User* signUp(string _userName, string _password,int response);
	static User* authenticate(string userName, string password);
	static vector<string> formatAsVectorOfString(string s);
	static vector<Notification> readNotifications();
	static vector<RentingProcess>readRentingProcesss();
	static Car showAllCars();
};

