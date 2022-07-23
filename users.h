#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class User {
public:
	int m_id = 0;
	string m_username;
	string m_password;
	bool m_roleType = 0;

	void AddMod(string username) {
		string password, usern;
		int lgid, roletype;
		bool valid = 0;
		fstream read_user, write_user;
		read_user.open("users.txt", fstream::in);
		write_user.open("temp.txt", fstream::app |fstream::out);
		while (read_user >> lgid >> usern >> password >> roletype) {
			write_user << lgid << ' ';
			write_user << usern << ' ';
			write_user << password << ' ';
			if (usern == username) {
				roletype = 1;
				valid = 1;
			}
			write_user << roletype;
			write_user << '\n';
		}
		if (valid)
			cout << "\nSuccess!!";
		else
			cout << "\nUsername not found.";
		read_user.close();
		write_user.close();
		remove("users.txt");
	}
};

void signup(User& x);
bool login(User& x);