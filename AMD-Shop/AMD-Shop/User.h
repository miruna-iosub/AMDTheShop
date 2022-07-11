#pragma once
#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
#include "Login.h"
#include "APU.h"
#include "GPU.h"
#include "CPU.h"
#include <fstream>
using namespace std;

class User
{
public:
    int m_id;
    string username;
    string password;
    string role;
public:
    User() {
        int id = 0;
        m_id = id++;
    }
    User(string username, string password, string role) {
        this->username = username;
        this->password = password;
        this->role = role; 
    }
    virtual void addProduct(Product* p) = 0;
    virtual void deleteProduct(Product* p) = 0;
    virtual void chooseProduct() = 0;
}; 

class Administrator : public User   
{
public:
    Administrator() {
        role = "administrator ";
    }
    Administrator(string username, string password, string role);

    void addAdmin();
    void addProduct(Product* p) override { 
        {
            std::ofstream fout;
            fout.open("ProductsData.txt", ios::app);

            fout << "Type of product: " << p->getType() << "\n";

            fout << "Name: " << p->getName() << "\n";
            
            fout << "Weight: " << p->getWeight()<< "\n";
            
            fout << "Height: " << p->getHeight()<< "\n";
            
            fout << "TDP: " << p->getTDP() << " W" << "\n";
            
            fout << "Nm: " << p->getNms() << "\n";
            
            fout << "Memory: " << p->getMemory() << "\n";
            
            fout << "Frequency: " << p->getFrequency() << " MHz" << "\n";

            if (p->getType() == "APU")
            {
                fout << "Cores: " << p->getCores() << "\n";
                
                fout << "Threads: " << p->getThreads() << "\n";
                
                fout << "Socket: " << p->getSocket() << "\n";
                
                fout << "Maximum Resolution: " << p->getMaxRes() << "\n";
                
                fout << "Technology supported: " << ToString(p->getTech()) << "\n\n";
            }


            if (p->getType() == "GPU")
            {
                fout << "Maximum Resolution: " << p->getMaxRes() << "\n";
                fout << "Technology supported: " << ToString(p->getTech()) << "\n\n";
            }

            if (p->getType() == "CPU")
            {
                fout << "Cores: " << p->getCores() << "\n";
                
                fout << "Threads: " << p->getThreads() << "\n";
                
                fout << "Socket: " << p->getSocket() << "\n\n";
            }


            fout.close();
        }
    }
    void chooseProduct();
};

class Client : public User
{
public:
    Client() {
        role = "client";
    }
    Client(string username, string password, string role);

    void chooseProduct() override;
    void addProduct(Product* p) override {
        {
            string line;
            ofstream fout;
            fout.open("Cart.txt", ios::app);
            fout << p->getName() << endl;
            fout << p->getType() << endl;
            fout.close();
        }
    }
    void deleteProduct(Product* p) override {

    }
};