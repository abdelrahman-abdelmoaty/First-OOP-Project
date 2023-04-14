#include "Admin.h"
#include "Organization.h"
#include<vector>

using namespace std;	
#include <iostream>

float Admin::totalMoney = 0;
void Admin::displayAllCars(Organization* org)
{

	int counter = 1;
	vector<int>key(org->allCars.size()+1);
	for (int i = 0; i < org->allCars.size(); i++) {

		if ((org->allCars[i]).getVerification()) {
			cout << counter << ":\n";
			cout << org->allUsers[stoi(org->allCars[i].getCarOwnerID())-300]->username<<"\n";

			org->allCars[i].displayInfo();
			key[counter] = i;
			cout << '\n';
			counter++;
		}

	}
	
	int inp;
	cin >> inp;
	
	system("cls");
	inp = key[inp];
	Car choosenCar = org->allCars[inp];
	counter = 1;
		
	cout << "\t\t";
	cout << "Car:" << choosenCar.getModel()<<"\n\n\n";

	for (int i = 0; i < choosenCar.getRentingProcesses().size();i++) {

		cout << counter << '\n';
		choosenCar.getRentingProcesses()[i]->displayInfo();
	}

}
void Admin::displayAllUsers(Organization* org,int flag)
{
	// flag=3 renters 
	// flag==4 owners
	//
	int counter = 1;
	int i2 = 0;
	vector<int>key(org->allUsers.size()+1);
	for (auto i : org->allUsers) {
		if (((stoi(i->id)/100) % 10  <3&&flag==3)||(flag==4&& (stoi(i->id) / 100) % 10 >= 3)) {

			cout << counter<< ":\n";
			// it should be displayData
			
			i->displayData();
			
			key[counter] = i2;
			counter++;

		}
		i2++;

	}


	// There will be while Here akeed ya 3am omar 
	
	int inp;
	cin >> inp;
	inp = key[inp];
	User* choosenRenter = org->allUsers[inp];
	
	choosenRenter->displayTheUniqueHistory();


}
void Admin::showCarsToBeVerified(Organization* org)
{

	int key[100] = { 0 };
	int k = 1;
	for (int i = 0; i < carsToBeVerified.size();i++) {

		if (!carsToBeVerified[i]->isSeenByTheAdmin) {
			cout << i + 1 << ": ";
			carsToBeVerified[i]->displayInfo();
			key[k] = i;
			k++;
		}
	}
	int inp1;
	cin >> inp1;
	inp1 = key[inp1];
	cout << "Do you want to accept it?\n";
	int inp2;
	cin >> inp2;
	// we should add notification for the user
	string type;
	if (inp2 == 1) {
		carsToBeVerified[inp1 ]->isSeenByTheAdmin = true;
		carsToBeVerified[inp1 ]->setVerification(true);
		type = "newCarAdded";
	}
	else {
			
		type = "carVerification";
		carsToBeVerified[inp1 ]->isSeenByTheAdmin = true;
		carsToBeVerified[inp1 ]->setVerification(false);	
	}

	
	
	User* owner = org->allUsers[stoi(carsToBeVerified[inp1]->getCarOwnerID())-300];
	Date d = Date::getCurrentDate();
	Notification n(type, to_string(org->allNotifications.size()), (carsToBeVerified[inp1]->getModel()), "-1", d.getString1());
	org->allNotifications.push_back(n);
	owner->changeMoney(0, org);
	


}
void Admin::displayInfo(Organization *org)
{

	cout << "\t\t\t\tHello ADMIN\n";
	cout << totalMoney << '\n';
	cout << "1-Cars To be verified\n";
	cout << "2-show all Cars\n";
	cout << "3-show all Renter\n";
	cout << "4-show all Owners\n";
	int inp;
	cin >> inp;
	
	if (inp == 1) {
	
		if (carsToBeVerified.size() == 0) {
			cout << "EMPTY\n";
		}
		
		showCarsToBeVerified(org);
		return;
	}

	if(inp==2){
		displayAllCars(org);
		return;
	}


	if (inp == 3||inp==4) {
		displayAllUsers(org,inp);
		return;
	}

}

Admin::Admin(Organization *org)
{

	for (int i = 0; i < org->allCars.size();i++) {
		if (!(org->allCars[i].isSeenByTheAdmin)) {
		
			carsToBeVerified.push_back(&org->allCars[i]);

		}
	}

}
