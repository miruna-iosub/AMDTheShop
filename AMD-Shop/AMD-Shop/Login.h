#pragma once
#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
using namespace std;
class Login
{
protected:
    char username[50];
    char password[50];
    unsigned int role;
public:

    void login(char  un[], char pw[])
    {
        ifstream fs("logindata.txt", ios::in);
        while (!fs.eof())
        {
            fs >> username >> password >> role;

            if (strcmp(un, this->username) == 0 && strcmp(pw, this->password) == 0)
            {
                if (role == 1)
                {
                    cout << "Welcome to student : " << username << endl;
                    break;
                }
                else if (role == 2)
                {
                    cout << "Welcome to admin : " << username;
                    break;
                }
            }
            else
                cout << "Acces denied.";

        }
        fs.close();
    }

    void Register()
    {

        ofstream fs("logindata.txt", ios::app);
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Press 1. Client 2. Admin " << endl;
        cin >> role;
        fs << username << " " << password << " " << role << " " << endl;
        fs.close();
    }
};