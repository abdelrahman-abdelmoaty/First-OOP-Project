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

	if (inp==1) {
				
		
		showAvailableCars();

	}
	else {
		if (inp == 2) {
			
			for (auto r : rentingProcesses) {

				r.displayInfo();
			}
			

		}

		
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

void Renter::showAvailableCars()
{	
	system("cls");
	Organization org;
	
	Car choosenCar =org.showAllCars();


	if (choosenCar.getModel() !="dummy") {
		
		
		cout << "Are you sure you want to rent this car with id ?" << choosenCar.getID() << '\n';
		int response;
		cin >> response;
		if (response == 1) {

			currentCar = choosenCar.getID();
			choosenCar.setIsRented();
			// we should get the Date
			// I think we should here start a renting process and make an attribute called isTheRenting still Running or not
			// and when the renter end the rent we calculate the fees using the date 


			return;
		}
		else {
			// we will see wether we will call the function again or end 

		}

	}


}

