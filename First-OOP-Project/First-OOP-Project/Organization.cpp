#include "Organization.h"

using namespace std;
Organization::Organization()
{	
	allRentingProcesses = vector<RentingProcess>(100);
	allCars=vector<Car>(100);

}

void Organization::readFiles()
{

	
	ifstream readFile("Users.txt");
	int id,totalMoney;
	string currentCar, rentingProcessString,carString,inboxString, name, password;

	allCars = readCars();
	allNotifications = readNotifications();
	allRentingProcesses = readRentingProcesss();


		
	while (readFile.peek() != EOF) {
		User* user;
		readFile >> id;
		readFile >> name;
		readFile >> password;
		readFile >> totalMoney;

		if (id % 2 == 0) {
			//Owner
			readFile>> currentCar;
			readFile>> rentingProcessString;
			vector<string>RentingProcessAsId=formatAsVectorOfString(rentingProcessString);
			vector<RentingProcess>rp;

			for (int i = 0; i < RentingProcessAsId.size(); i++) {

				rp.push_back(allRentingProcesses[i]);
			}



			user = new Renter(to_string(id),name,password,totalMoney,currentCar,rp);

		}
		else {
			//Renter
			readFile >> carString;
			readFile >> inboxString;
			vector<string>carIdsAsVector = formatAsVectorOfString(carString);
			vector<string>inboxAsVector = formatAsVectorOfString(inboxString);
		
			vector<Car>userCar;
			vector<Notification>userInbox;


			for (auto notification : allNotifications) {

				for (auto j : inboxAsVector) {
					if (notification.checkId(j)) {
						userInbox.push_back(notification);
					}
				}

			}
			for (int i = 0; i < carIdsAsVector.size(); i++) {

				userCar.push_back(allCars[stoi(carIdsAsVector[i])]);
			}

			
			user = new Owner(to_string(id), name, password, totalMoney, userCar, userInbox);
	
		}

		allUsers.push_back(user);
	}
	readFile.close();

}

void Organization::writeFiles()
{

	ofstream myFile;
	myFile.open("Users.txt");

	for (int i = 0; i < allUsers.size(); i++) {
		string s=allUsers[i]->toBeWrittenInFile();
		myFile << s;
		
	}
	myFile.close();
}



vector<Car> Organization::readCars()
{

	// (1) will implement this car File is called 'Cars'

	return vector<Car>();
}



User* Organization::signUp(string _userName, string _password, int response)
{
	User* user;
	int id = User::makeNewID(response);
	
	if (response == 1) {
		
		user = new Renter( to_string(id),_userName,_password,0);
	}
	else {
		user = new Owner(to_string(id),_userName,_password,0);
	}

	allUsers.push_back(user);
	return user;

}


User* Organization::authenticate(string userName, string password)
{
	for (auto i : allUsers) {
		if (i->checkUsernameWithPassword(userName,password)) {
			
			return i;
		}
	}
	
	return NULL;

}

vector<string> Organization::formatAsVectorOfString(string s)
{
	// (1) will  return {1654,48,56} as vector of strings v[0]="1654" v[1]="48" v[2]="56"
	return vector<string>();
}

vector<Notification> Organization::readNotifications()
{

	// (2) will implement this 

	return vector<Notification>();
}

vector<RentingProcess> Organization::readRentingProcesss()
{
	// (3) will implement this 
	// don't forget you will add the Car with the same id 
	return vector<RentingProcess>();
}



// ÈÚÏíä ÇáãÝÑæÖ äÝßÑ ÇÒÇí äÎáí ÇáÝÇäßÔä Ïí Ýí  ÇáÑíäÊÑ ÈÓ ÚÔÇä Ïå ãÔ ãßÇä ÕÍ 
Car Organization::showAllCars()
{
	// display All Cars and wait response 

	int n;
	cin >> n;
	
	if (allCars[n].getIsRented() == false) {
		return allCars[n];
	}
	else {
		Car c1;
		
		return c1;
	}
}




