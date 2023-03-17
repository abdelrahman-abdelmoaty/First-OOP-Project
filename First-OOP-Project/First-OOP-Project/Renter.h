#pragma once
#include "User.h"
#include "RentingProcess.h"
class Renter:public User
{
private:
	bool isRenting;
	vector<RentingProcess>rentingProcesses;
	


};

