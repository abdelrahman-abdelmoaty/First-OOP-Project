#include "Car.h"
using namespace std;

Car::Car()
{
	isVerified = false;
	isSeenByTheAdmin = false;
	totalMoneyGotFromTheCar = 0;

}



Car::Car(string _model, int _maxSpeed, int _rentingPrice,vector<RentingProcess*>_rentingProcesses) :model(_model), maxSpeed(_maxSpeed),
isRented(false), rentingPrice(_rentingPrice)
{
	this->RentingProcesses = _rentingProcesses;

}

void Car::setIsRented() {

	isRented = !isRented;
}

bool Car::getIsRented() {

	return isRented;
}
void Car::displayInfo()
{

	cout << "\t\t model:" << model << endl << "\t\tRentingPrice" << rentingPrice << " EGP\n" << "\t\t HorsePower" << horsePower << " HP\n" << "\t\t\toruq" << torque << " N-m\n" << "\t\t\t\n";
	cout << "\t\tisRented"<<isRented<<'\n';
	cout << "\t\tisVerified" << isVerified << '\n';
	cout << "\ttotalMoneyFromTheCar" << totalMoneyGotFromTheCar << '\n';


}
string Car::getModel() {

	return model;
}

string Car::getID()
{
	return ID;
}

string Car::getCarOwnerID()
{
	return carOwnerID;
}

string Car::getCarType()
{
	return carType;
}

string Car::getGear()
{
	return gear;
}

int Car::getHorsePower()
{
	return horsePower;
}

int Car::getTorque()
{
	return torque;
}

int Car::getRentingPrice()
{
	return rentingPrice;
}

int Car::getMAxSpeed() {
	return maxSpeed;
}

bool Car::getRentingStatus()
{
	return isRented;
}

float Car::getCommision()
{
	return commision;
}

vector<RentingProcess*> Car::getRentingProcesses()
{
	return RentingProcesses;
}

string Car::getWhatToBeWrittenInFile()
{
	string s;
	s += ID; s += " ";
	s += model; s += " ";
	s += carOwnerID; s += " ";
	s += "{";
	int c = 0;
	for (auto i : RentingProcesses) {
		if (c)
			s += ",";
		s += i->getID();
		c++;
		
	}
	s += "} ";
	s += to_string(horsePower); s += " ";
	s += to_string(torque); s += " ";
	s += carType; s += " ";
	s += gear; s += " ";
	s += to_string(maxSpeed); s += " ";
	s += to_string(isRented); s += " ";
	s += to_string(rentingPrice); s += " ";
	s += to_string(isVerified); s += " ";
	s += to_string(commision); s += " ";
	s += to_string(totalMoneyGotFromTheCar); s += " ";
	s += to_string(isSeenByTheAdmin);
	return s;
}

bool Car::getVerification()
{
	return isVerified;
}


void Car::setID(string id)
{
	ID = id;
}

void Car::setCarOwnerID(string idd)
{
	carOwnerID = idd;
}

void Car::setCarType(string t)
{
	carType = t;
}

void Car::setGear(string g)
{
	gear = g;
}

void Car::setModel(string m) {
	model = m;
}

void Car::setHorsePower(int hp)
{
	horsePower = hp;
}

void Car::setTorque(int tor)
{
	torque = tor;
}

void Car::setRentingPrice(int p)
{
	rentingPrice = p;
}

void Car::setMaxSpeed(int s)
{
	maxSpeed = s;
}

void Car::setRentingStatus(bool r)
{
	isRented = r;
}

void Car::setCommision(float c)
{
	commision = c;
}

void Car::getCarInput(int _id,int _carOwnerID)
{
	
	this->ID = to_string(_id);
	isVerified = false;
	this->carOwnerID = to_string(_carOwnerID);
	cout << "Model: ";
	cin >> model;
	cout << "HorsePower:";
	cin >> horsePower;
	cout << "Torque:";
	cin >> torque;
	cout << "Car Type:";
	cin >> carType;
	cout << "Gear:";
	cin >> gear;
	cout << "Speed:";
	cin >> maxSpeed;
	cout << "CarPricePerH";
	cin >> rentingPrice;
	cout << "Commision:";
	cin >> commision;
	
	
}

void Car::setRentingProcesses(vector<RentingProcess*> _rps)
{
	this->RentingProcesses = _rps;
}

void Car::pushToRentingProcesses(RentingProcess* rp)
{
	RentingProcesses.push_back(rp);
}



void Car::setVerification(bool v)
{
	isVerified = v;
}