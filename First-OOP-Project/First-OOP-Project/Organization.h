#pragma once
#include<vector>
#include "User.h"
#include "Car.h"
#include<string>
using namespace std;
class Organization
{
private:
	vector<User*> users;
	vector<Car>cars;

public:
	User* auth(string _name, string _password);


};

