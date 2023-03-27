#include "RentingProcess.h"
#include <fstream>

RentingProcess::RentingProcess() {

}

RentingProcess::RentingProcess(string s1, string s2, Date start, Date time) {
	carOwner = s1;
	carRenter = s2;
	beginningDate = start;
	endDate = time;
	isRunning = checkRunning(endDate);
}

bool RentingProcess::checkRunning(Date end) {
	Date curr;
	if (end.year < curr.year) 
		return false;
	if (end.year > curr.year)
		return true;
	if (end.month < curr.month)
		return false;
	if (end.month > curr.month)
		return true;
	if (end.day < curr.day)
		return false;
	return true;
}

void RentingProcess::displayInfo()
{
	cout << "car owner:  " << carOwner << endl;
	cout << "car renter:  " << carRenter << endl;
	cout << "Beginning of the contract:  ";
	beginningDate.displayDate();
	cout << "ending of the contract:  ";
	endDate.displayDate();
	//rentedCar.displayinfo();
}
vector<RentingProcess> RentingProcess::readF() {
	vector<RentingProcess> v;
	ifstream readf("RentingProcess.txt");
	string owner, renter;
	int carID;
	int d, m, y;
	while (readf.peek() != EOF) {
		readf >> owner;
		readf >> renter;
		readf >> carID;
		readf >> d >> m >> y;
		Date startDate(d, m, y);
		readf >> d >> m >> y;
		Date endDate(d, m, y);
		//for (Car it : allCars) {
		//	if (carID == stoi(it.getID())) {
		//		RentingProcess r(owner, renter, it, startDate, endDate);
		//		v.push_back(r);
		//	}
		//}
	}
	readf.close();
	return v;
}
string RentingProcess::getWhatToWrite() {
	string s = carOwner;
	s += " " + carRenter;
	s += " " + carOwner;
	s += " " + beginningDate.day;
	s += " " + beginningDate.month;
	s += " " + beginningDate.year;
	s += " " + endDate.day;
	s += " " + endDate.month;
	s += " " + endDate.year;
	//s += " " + rentedCar.getID();
	return s;
}