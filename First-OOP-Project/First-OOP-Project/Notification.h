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
	Date rentingDate;
	bool isVerified;
public:
	Notification(string _id, string _renter, string _rentedCar,Date _rentingDate ,bool _isVerified, string _type) {
		id = _id;
		renter = _renter;
		rentedCar = _rentedCar;
		rentingDate = _rentingDate;
		isVerified = _isVerified;
		type = _type;
	}
	bool checkId(string _id);
	// 0 or 1
	// (2) will care about all of the Notifications 



};

