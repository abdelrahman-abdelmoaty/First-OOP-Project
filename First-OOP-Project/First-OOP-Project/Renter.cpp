#include "Renter.h"
#include<iostream>

Renter::Renter(string _id, string _userName, string _password, int _totalMoney, string _currentCar, vector<RentingProcess> _rentingProcesses)
	:User(_id,_userName,_password,_totalMoney)
{
	this->currentCar = _currentCar;
	this->rentingProcesses = _rentingProcesses;
}

Renter::Renter():User("-1","dummy","dummy") {


}

Renter::Renter(string _id, string _userName, string _password, int _totalMoney):User(_id, _userName, _password, _totalMoney)
{
	this->currentCar = "-1";

}


void Renter::displayInfo()
{
	// logic of Renter
	system("cls");
	cout << "\t\t\t\t\t Hello " << username << "\n\n\n\n";
	cout << "total Money Paid:" << totalMoney << "\n\n";
	cout << "1-See available cars\n";
	cout << "2-View my history\n";
	if (currentCar != "-1") {
		cout << "3-End my Rent";
	}
	int inp;
	cin >> inp;

	if (inp) {
			
	}


}

string Renter::toBeWrittenInFile()
{
	
	string s = User::toBeWrittenInFile();
	s += currentCar;
	s += " ";
	///
	/// this will be discussed later
	s += "{}\n";
	//
	return s;

}

