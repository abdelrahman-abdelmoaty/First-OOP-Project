#include "Owner.h"
#include <iostream>


Owner::Owner(string _id, string _userName, string _password, int _totalMoney, vector<Car> _cars, vector<Notification> _inbox)
	:User(_id, _userName, _password, _totalMoney)
{
	this->cars = _cars;
	this->inbox = _inbox;


}

Owner::Owner(string _id, string _userName, string _password, int _totalMoney) :User(_id, _userName, _password, _totalMoney)
{
}


void Owner::displayInfo()
{
	//some logic here
}

string Owner::toBeWrittenInFile()
{
	string s = User::toBeWrittenInFile();
	///
	/// this will be discussed later
	/// 
	s +="{}";
	s += " ";
	s += "{}\n";
	//
	return s;

}
