#include "Owner.h"
#include "Organization.h"
#include"OpeningUI.h"

Owner::Owner(string _id, string _userName, string _password, int _totalMoney, vector<Car*> _cars, vector<Notification*> _inbox)
	:User(_id, _userName, _password, _totalMoney)
{
	this->cars = _cars;
	this->inbox = _inbox;


}

Owner::Owner(string _id, string _userName, string _password, int _totalMoney) :User(_id, _userName, _password, _totalMoney)
{


}


void Owner::displayInfo(Organization* org)
{
	int i = 0;
	while (true) {
		system("cls");
		if (i)
			cout << "unvalid input please try again" << endl;
		i++;
		cout << "total money: " << totalMoney << '\n';
		cout << "1-Add New Cars\n";
		cout << "2-See My Cars\n";
		cout << "3-inbox: ";
		if (inbox.size() > 0)
			cout << inbox.size();
		else cout << "0";
		cout << '\n';
		cout << "4-go back\n";

		string input = "0";
		cin >> input;
		if (input == "1") {
			addNewCar(org);
		}
		else if (input == "2") {
			showMyCars(org);
		}
		else if (input == "3") {
			showInbox(org);
		}
		else if (input == "4") {
			openingUI(org);
		}
	}

}

string Owner::toBeWrittenInFile()
{
	string s = User::toBeWrittenInFile();
	///
	/// this will be discussed later
	/// 
	s += "{";

	for (int i = 0; i < cars.size(); i++) {
		if (i)
			s += ",";

		s += cars[i]->ID;

	}

	s += "}";

	int counter = 0;
	s += " ";
	s += "{";
	for (auto i : inbox) {
		if (counter)
			s += ',';
		s += i->getID();
		counter++;
	}

	s += '}';
	//
	return s;

}

void Owner::addNewCar(Organization* org) {

	system("cls");


	Car c;

	c.getCarInput(org->allCars.size(), stoi(id));
	org->allCars.push_back(c);

	cars.push_back(&(org->allCars[org->allCars.size() - 1]));


}

void Owner::showMyCars(Organization* org)
{
	system("cls");
	int key[100] = { 0 };
	int j = 1;
	int i = 0;
	for (; i < cars.size(); i++) {
		if (cars[i]->getVerification()) {
			cout << i << " ";
			cars[i]->displayInfo();
			cout << '\n';
			key[j] = i;
			j++;
		}
	}

	bool flag = false;
	string s = "0";
	int n = 0;
	while (!flag) {
		cout << "Choose car no to show or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(org);
		else if (s[0] < '9' && s[0] > '0') {
			flag = true;
			if (s.size() > 1) {
				if (s[1] < '9' && s[1] > '0') {
				}
				else flag = false;
			}
		}
		if (flag)
			n = stoi(s) - 1;
		else {
			system("cls");
			cout << "unvalid input please try again" << endl;
		}
	}
	if (n >= i)
		cout << "unavailabe car id \n";
	else {
		n = key[n];
		Car* choosen = cars[n];
		for (int i = 0; i < choosen->getRentingProcesses().size(); i++) {

			cout << i + 1 << " ";
			choosen->getRentingProcesses()[i]->displayInfo();
			cout << '\n';
		}
	}
	string ss = "0";
	while (ss != "1" && ss != "2") {
		cout << "do you want to show another car\n";
		cout << "1- yes\n";
		cout << "2- no\n";
		cin >> ss;
		if (ss == "1")
			showMyCars(org);
		else if (ss == "2")
			displayInfo(org);
		else {
			system("cls");
			cout << "unvlaid input please enter 1 or 2\n";
		}
	}

}

void Owner::showInbox(Organization* org)
{

	for (int i = 0; i < inbox.size(); i++) {

		inbox[i]->displayInfo();

	}
	inbox.clear();


}

void Owner::changeMoney(float money, Organization* org)
{
	totalMoney += money;
	inbox.push_back(&org->allNotifications[org->allNotifications.size() - 1]);


}

void Owner::displayData()
{
	User::displayData();
	cout << "Number Of cars:" << cars.size() << '\n';

}

void Owner::displayTheUniqueHistory()
{

	for (int i = 0; i < cars.size(); i++) {
		cout << i + 1 << ": ";
		cars[i]->displayInfo();
		cout << "\n";

	}

	system("pause");
}


