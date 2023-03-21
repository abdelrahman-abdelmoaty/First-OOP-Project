#pragma once
#include<vector>
#include "User.h"
#include "Car.h"
#include "Renter.h"
#include "Owner.h"
#include <fstream>
#include<string>

using namespace std;
class Organization
{
private:
	vector<User*> users;
	vector<Car>cars;

public:
	Organization();
	void readFiles();
	void writeFiles();
	User* signUp(string _userName, string _password,int response);
	User* authenticate(string userName, string password);
};

