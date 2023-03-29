#include "Organization.h"
#include "RentingProcess.h"
#include<string>
using namespace std;

Organization::Organization(){

	
}

/*Organization::Organization(int nOfCars, int nOfRentings) {
	allRentingProcesses = vector<RentingProcess>(nOfRentings);
	allCars = vector<Car>(nOfCars);
}
*/

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
			//Renter
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
			//Owner
			readFile >> carString;
			readFile >> inboxString;
			vector<string>carIdsAsVector = formatAsVectorOfString(carString);
			vector<string>inboxAsVector = formatAsVectorOfString(inboxString);
		
			vector<Car*>userCar;
			vector<Notification>userInbox;


			for (auto notification : allNotifications) {
				//{verification 1  45 sa fhhf jk, add car 2 ,3,4,5,6}
				
				for (auto j : inboxAsVector) {
					if (notification.checkId(j)) {
						userInbox.push_back(notification);
					}
				}
			}
			for (int i = 0; i < carIdsAsVector.size(); i++) {

				userCar.push_back(&allCars[stoi(carIdsAsVector[i])]);
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

	ofstream carsFiles("Cars.txt");
	for (int i = 0; i < allCars.size(); i++) {
				
		//allCars[i].getWhatTobeWrittenInFile();
		
	}

	for (int i = 0; i < allRentingProcesses.size(); i++) {

		//allRentingProcesses[i].getWhatTobeWrittenInFile();

	}
	
	for (int i = 0; i < allNotifications.size(); i++) {

		//allNotifications[i].getWhatTobeWrittenInFile();
				
	}


	ofstream counterFile;
	counterFile.open("counter.txt");
	counterFile << allCars.size() << " " << allRentingProcesses.size();
	counterFile.close();



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

vector<Notification> Organization::readNotifications(){
	vector <Notification> notifications;
	ifstream file("Notifications.txt");
	string fields[6];
	// type - id - car  - renter  -  isVerified - date
	if (file.is_open()) {
		while (file >> fields[0] >> fields[1] >> fields[2] >> fields[3] >> fields[4] >> fields[5]) {
			notifications.push_back(Notification(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5]));
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}

	return notifications;
}

vector<RentingProcess> Organization::readRentingProcesss() {
	vector<RentingProcess> rp;
	ifstream readf("RentingProcess.txt");
	string idd, carOwner, car, BeginningDate;
	float  cost;
	bool isRunning;
	float duration;

	while (readf.peek() != EOF) {
		readf >> idd;
		readf >> carOwner;
		readf >> car;
		readf >> BeginningDate;
		readf >> cost >> isRunning >> duration;

		
		Date d(BeginningDate);
		

		RentingProcess r(idd, " re ", allCars[1], d, cost, duration, isRunning);
	}

	readf.close();
	return rp;
	
	
	
}



