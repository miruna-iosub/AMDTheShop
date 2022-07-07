#pragma once
#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
#include "Login.h"
using namespace std;
class User:public Login {
protected:
    string username;
    string password;
    unsigned int role;
    unsigned int id;
public:
    User();
    User(string username, string password, int role, int id) {
        this->username = username;
        this->password = password;
        this->role = role;
        this->id = id;
    }

    virtual void addItem();
    virtual void deleteItem();
};

class Administrator :public User {
public:
    Administrator():User(){}
    void addAdmin();
    void addItem() override {

    }

    void deleteItem() override {

    }

};

class Client :public User {
public:
    void addItem() override {

    }

    void deleteItem() override {

    }
};