#include "RentingProcess.h"
#include <fstream>

RentingProcess::RentingProcess(string _id ,Car* _car, Date _beginningDate , bool _isRunning){
	id = _id;
	car = _car;
	beginningDate = _beginningDate;
	isRunning = _isRunning;
}
RentingProcess::RentingProcess() {

}

RentingProcess::RentingProcess(string _id, string _carOwner, Car* _car, Date _beginningDate, float _cost, float _duration, bool _isRunning)
{

	id = _id;
	carOwner = _carOwner;
	car = _car;
	beginningDate = _beginningDate;
	cost = _cost;
	duration = _duration;
	isRunning = _isRunning;


}

//RentingProcess::RentingProcess(string s1, string s2, Date start, Date time) {
//	carOwner = s1;
//	carRenter = s2;
//	beginningDate = start;
//	endDate = time;
//	isRunning = checkRunning(endDate);
//}



Car* RentingProcess::getCar(){
	return car;
}

void RentingProcess::displayInfo()
{
	cout << "Car owner:  " << carOwner << endl;
	cout << "Beginning of the contract:  ";
	beginningDate.displayDate();
	cout << "\nEnding of the contract:  ";
	//rentedCar.displayinfo();
}