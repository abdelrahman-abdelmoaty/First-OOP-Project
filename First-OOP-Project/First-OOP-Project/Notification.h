#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Notification {
private:
	string id;
	string renter;
	string rentedCar;
	string type; // carVerification - newCarAdded - carRented
	string rentingDate;
	string isVerified;
public:
	Notification(string _type, string _id , string _rentedCar, string _renter, string _isVerified, string _rentingDate) {
		id = _id;
		renter = _renter;
		rentedCar = _rentedCar;
		rentingDate = _rentingDate;
		isVerified = _isVerified;
		type = _type;
	}
	bool checkId(string _id);


};

