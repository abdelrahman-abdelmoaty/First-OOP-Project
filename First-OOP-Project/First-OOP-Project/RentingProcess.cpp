#include "RentingProcess.h"
#include <fstream>


RentingProcess::RentingProcess(string _id ,Car* _car, Date _beginningDate , bool _isRunning){
	id = _id;
	car = _car;
	beginningDate = _beginningDate;
	isRunning = _isRunning;
}
RentingProcess::RentingProcess() {}


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



string RentingProcess::getWhatToWrite() {
	return(id + " " + carOwner + " " + car->getID() + " " + to_string(beginningDate.day) + "/" + to_string(beginningDate.month) + "/" + to_string(beginningDate.year) + " " + to_string(cost) + " " + to_string(isRunning) + " " + to_string(duration));
}