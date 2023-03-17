#pragma once
#include <string>
#include<vector>
using namespace std;
class User
{
private:
	string id;
	string username;
	string password;
	static int nOfUsers;
	string type;

	//string registerationDate;
public:
	User(string _id, string _username, string _password);
	static string makeId();
	

};

