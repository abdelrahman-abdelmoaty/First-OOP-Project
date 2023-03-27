#include <iostream>
#include "User.h"
#include "Renter.h"
#include "Owner.h"
#include"Organization.h"
using namespace std;


int main(){
    

    int numberOfCars, numberOfRentings;
    ifstream myFile("counter.txt");
    myFile >> numberOfCars >> numberOfRentings;
    myFile.close();

    Organization org(numberOfCars,numberOfRentings);
    
    org.readFiles();
    cout << "\t\t\t\t\t\t\tHello\n\n";
    cout << "1->sign in \n";
    cout << "2->sign up \n";
    
    
    int n;
    cin >> n;
    system("cls");
    if (n == 1) {
        cout << "UserName: ";
        string name, password;
        cin >> name;
        cout << "Password: ";
        cin >> password;

        User* user;
        user = org.authenticate(name,password);

        if (user==NULL) {
            cout << "Wrong\n";
            return 0;
        }

        user->displayInfo();


    }
    else {
        cout << "UserName: ";
        string name, password;
        cin >> name;
        cout << "Password: ";
        cin >> password;
        cout << "Are You :\n" << "1-Renter\n" << "2-Car Owner\n";
        int response;
        cin >> response;
        response--;
        User* user;
        user =org.signUp(name, password, response);
        user->displayInfo();
    }

    
    org.writeFiles();

}
