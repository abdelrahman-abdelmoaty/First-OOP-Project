#pragma once
#include <string>
#include<vector>
using namespace std;
class User
{
public:
	string id;
	string username;
	string password;
	int totalMoney;
	static int nOfUsers;
public:
	User(string _id, string _username, string _password,int _totalMoney=0);
	User(string _username, string _password);
	bool checkUsernameWithPassword(string _username,string _password);
	virtual void displayInfo();
	static int makeNewID(int i);
	virtual string toBeWrittenInFile();

};

