#include "User.h"
#include<iostream>


int User::nOfUsers = 0;
User::User(string _id, string _username, string _password,int _totalMoney)
{

	id = _id;
	username = _username;
	password = _password;
	totalMoney = _totalMoney;
	nOfUsers++;
}

User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	totalMoney = 0;
	nOfUsers++;
}

bool User::checkUsernameWithPassword(string _username, string _password)
{
	if (this->username == _username && this->password == _password)
		return true;
		
	return false;
}


void User::displayInfo()
{
	cout << "This shouldn't be called\n";
}

int User::makeNewID(int i)
{	
	int h=nOfUsers+110;
	if (h % 2 == i)
		return h;
	else
		return h + 1;

}

string User::toBeWrittenInFile()
{
	string s;
	s += this->id;
	s += " ";
	s += username;
	s += " ";
	s += password;
	s += " ";
	s += to_string(totalMoney);
	s += " ";
	return s;


}



	

