#include <iostream>
#include "openningUI.h"
#include <string>
#include "User.h"
#include "Renter.h"
#include "Owner.h"
#include"Organization.h"
using namespace std;
void openingUI() {
    Organization org;
    org.readFiles();
    string n = "0";
    int i = 0;
    while (true) {
        system("cls");
        if (i)
            cout << "unvalid input please try again" << endl;
        i++;
        cout << "*******************\n";
        cout << "**     welcome   **\n";
        cout << "** 1 -> sign in\t **\n";
        cout << "** 2 -> sign up\t **\n";
        cout << "** 3 -> admin    **\n";
        cout << "** 4 -> close    **\n";
        cout << "*******************\n";
        cin >> n;
        system("cls");
        if (n == "1") {
            User* user = NULL;
            while (user == NULL) {
                system("cls");
                cout << "UserName: ";
                string name, password;
                cin >> name;
                cout << "Password: ";
                cin >> password;
                user = org.authenticate(name, password);
                if (user == NULL) {
                    cout << "account does not exist\n";
                    char c = '0';
                    cout << "1->try again" << endl;
                    cout << "2->go back" << endl;
                    cin >> c;
                    if (c == '2')
                    {
                        openingUI();
                    }
                }
                else
                    user->displayInfo(&org);
            }
        }
        else  if (n == "2") {
            cout << "UserName: ";
            string name, password;
            cin >> name;
            cout << "Password: ";
            cin >> password;
            cout << "Are You :\n" << "1-Renter\n" << "2-Car Owner\n";
            int response;
            cin >> response;
            User* user;
            user = org.signUp(name, password, response);
            user->displayInfo(&org);
        }
        else if (n == "3") {
            string name, password;
            while (name != "admin" || password != "pass") {
                system("cls");
                cout << "UserName: ";
                cin >> name;
                cout << "Password: ";
                cin >> password;
                if (name == "admin" && password == "pass") {
                    Admin a(&org);
                    a.displayInfo(&org);
                }
                else {
                    char c = '0';
                    cout << "1->try again" << endl;
                    cout << "2->go back" << endl;
                    cin >> c;
                    if (c == '2')
                    {
                        openingUI();
                    }
                }
            }
        }
        else if (n == "4") {
            cout << "are you sure you want to exit\n";
            cout << "1-> exit\n";
            cout << "2-> continue\n";
            char ss;
            cin >> ss;
            if (ss == '1')
            {
                cout << "THANK YOU FOR USING THE APPLICATION\n";
                exit(0);
            }
        }
    }
    org.writeFiles();
}