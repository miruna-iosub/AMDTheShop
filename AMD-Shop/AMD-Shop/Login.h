#pragma once
#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
using namespace std;
class Login
{ 
protected: 
    string username;
    string password;
    unsigned int role;
    unsigned int id; 
public:
    void login(string  un, string pw) 
    { 
        ifstream fs("logindata.txt", ios::in);   
        while (!fs.eof())
        {
            fs >> username >> password >> role;
           
            if (username == un && password == pw) {
                if (role == 1)
                 {
                     cout << "Welcome to client : " << username << endl;
                     break;
                 }
                 else if (role == 2)
                 {
                     cout << "Welcome to admin : " << username;
                     
                 }
             }
        }
        fs.close();
    }

    string getRoleIfLogin(string  un, string pw) {
        ifstream fs("logindata.txt", ios::in);
        while (!fs.eof())
        {
            fs >> username >> password >> role;
            if (username == un && password == pw) {
                if (role == 1)
                {
                    return "client";
                }
                else if (role == 2)
                {
                    return "administrator";
                }
            }
        }
        fs.close();
    }

    string getUsernameIfLogin(string  un, string pw) {
        ifstream fs("logindata.txt", ios::in);
        while (!fs.eof())
        {
            fs >> username >> password >> role;
            
            if (username == un && password == pw) {
                return username;
            }
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