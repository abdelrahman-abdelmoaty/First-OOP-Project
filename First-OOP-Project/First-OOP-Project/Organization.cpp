#include "Organization.h"

using namespace std;
Organization::Organization()
{	
		
}

void Organization::readFiles()
{
	ifstream readFile("Users.txt");
	int id,totalMoney;
	string currentCar, rentingProcessNOT,carNOT,inboxNOT, name, password;
	//
	
	while (readFile.peek() != EOF) {
		User* user;
		readFile >> id;
		readFile >> name;
		readFile >> password;
		readFile >> totalMoney;

		if (id % 2 == 0) {
			//Owner
			readFile>> currentCar;
			readFile>> rentingProcessNOT;
			//  we will see wether we will read the Renting Processes as Ids or as objects
			vector<RentingProcess>rp;
			///
			user = new Renter(to_string(id),name,password,totalMoney,currentCar,rp);

		}
		else {
			//Renter
			readFile >> carNOT;
			readFile >> inboxNOT;
			//  we will see wether we will read the Cars and Inbox as Ids or as objects
			vector<Car>cars;
			vector<Notification>inbox;
			user = new Owner(to_string(id), name, password, totalMoney, cars, inbox);
	
		}

		users.push_back(user);
	}
	readFile.close();

}

void Organization::writeFiles()
{

	ofstream myFile;
	myFile.open("Users.txt");

	for (int i = 0; i < users.size(); i++) {
		string s=users[i]->toBeWrittenInFile();
		myFile << s;
		
	}
	myFile.close();
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

	users.push_back(user);
	return user;

}


User* Organization::authenticate(string userName, string password)
{
	for (auto i : users) {
		if (i->checkUsernameWithPassword(userName,password)) {
			
			return i;
		}
	}
	
	return NULL;

}
