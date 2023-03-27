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
	else if (inp == 2) {		
		for (auto r : rentingProcesses) {
			r.displayInfo();
		}
	}
	else if (inp == 3 && currentCar != "-1") {

		endRent();


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

void Renter::showAvailableCars() {	
	system("cls");	
	int i = 0;
	int h = 0;
	vector<int>key(Organization::allCars.size());
	vector<Car> cars = Organization::allCars;
	for (auto car : cars) {
		if (!car.getIsRented()) {
			cout << i + 1 << ". ";
			car.displayInfo();
			key[i] = h;
			i++;
		}
		h++;
	}
	cout << "Choose car: ";
	int n;
	cin >> n;
	n--;
	n = key[n];
	Car car = cars[n];
	if (currentCar != "-1") {
		cout << "You can't access a new car while renting another, please first end your current renting proccess\n";
		return;
	}
	Date date = Date::getCurrentDate();
	car.setIsRented();
	int sz = Organization::allRentingProcesses.size();
	RentingProcess rentingProcess = RentingProcess(to_string(sz),car, date, true);
	rentingProcesses.push_back(rentingProcess);
	
	Organization::allRentingProcesses.push_back(rentingProcess);

	return;

}

void Renter::endRent() {

	RentingProcess lastRentingProcess = rentingProcesses[rentingProcesses.size() - 1];
	Car* car = lastRentingProcess.getCar();
	car->setIsRented();

	


}

