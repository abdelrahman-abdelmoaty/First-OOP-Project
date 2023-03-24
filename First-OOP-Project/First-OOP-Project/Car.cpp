#include "Car.h"

Car::Car()
{
	model = "dummy";
}

Car::Car(string _model, int _maxSpeed, int _rentingPrice):model(_model), maxSpeed(_maxSpeed),
isRented(false), rentingPrice(_rentingPrice)
{
}

void Car::setIsRented() {

	isRented = !isRented;
}

bool Car::getIsRented() {

	return isRented;
}
void Car::displayInfo()
{
}
string Car::getModel() {

	return model;
}

string Car::getID()
{
	return id;
}

