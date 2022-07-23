#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "users.h"
#include "products.h"
#include "menu.h"
using namespace std;

User x;

void Menu(void) {

	int option;
	cout << "AMD Shop Menu:\n";
start:
	cout << "\n\nSelect Option:\n\n";
	cout << "1. SignUp\n";
	cout << "2. SignIn and Enter to your menu\n";
	cout << "3. Exit\n\n";
	cout << "Your choice: "; fflush(stdin);
	cin >> option;
	switch (option) {
	case 1: {system("cls"); signup(x); goto start; }
	case 2: {system("cls"); UserMenu(login(x)); goto start; }
	case 3: {system("cls"); exit(-99); }
	default: { cout << "No valid option!!\n"; fflush(stdin); Sleep(700); system("cls"); goto start; }
	}

}
void UserMenu(bool type) {
	while (~0) {
		if (type)
		{
			int option;
			cout << "\n1. Add a product in database\n";
			cout << "2. List of products from database\n";
			cout << "3. Delete a product from database\n";
			cout << "4. Add admin\n";
			cout << "5. Return to Main Menu\n\n";
			cout << "Your choice: ";
			cin >> option;
			switch (option) {
			case 1: { system("cls"); MeniuTipProdus(); break; }
			case 2: { system("cls"); ListProduct("products.txt"); break; }
			case 3: {
				char product_name[100];
				cout << "Product name: "; cin.ignore();
				cin.getline(product_name, 100, '\n');
				DeleteProduct(product_name, "products.txt");
				//system("cls"); 
				break;
			}
			case 4: {
				fflush(stdin);
				string username;
				cout << "\n username: ";
				cin >> username;
				x.AddMod(username); system("cls"); break;
			}
			case 5: {system("cls"); Menu(); break; }
			default: { cout << "No valid option!!\n"; Sleep(700); system("cls"); break; }
			}
		}
		else {
			int option;
			cout << "\n1. List of Products\n";
			cout << "2. Add a product to cart\n";
			cout << "3. Show the cart\n";
			cout << "4. Delete a product from cart\n";
			cout << "5. Return to Main Menu\n";
			cout << "Your choice: ";
			cin >> option;


			switch (option) {
			case 1: {
				system("cls");
				ListProduct("products.txt");
				break;
			}
			case 2: {
				char nameproduct[100];
				cin.ignore();
				cout << "\nName of product: "; fflush(stdin);
				cin.getline(nameproduct, 100, '\n');
				AddProduct(nameproduct, x.m_username);
				system("cls");
				break;
			}
			case 3: { system("cls");
				string filename = x.m_username + "_cart.txt";
				ListProduct(filename); break;
			}
			case 4: { char product_name[100];
				cout << "Product name: "; cin.ignore();
				cin.getline(product_name, 100);
				string filename = x.m_username + "_cart.txt";
				DeleteProduct(product_name, filename);  system("cls"); break;
			}
			case 5: {
				system("cls");
				Menu();
				break;
			}
		
			default: { cout << "No valid option!!\n"; Sleep(700); system("cls"); fflush(stdin); cin.ignore(); break; }
			}
		}
	}



}
void MeniuTipProdus(void) {
	int option;
	cout << "Choose type of product:";
	cout << "\n1. CPU\n";
	cout << "2. GPU\n";
	cout << "3. APU\n";
	cout << "Your choice: ";
	cin >> option;
	switch (option) {
	case 1: {
				CPU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break; 
			}
	case 2: {
				GPU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break; 
			}
	case 3: {
				APU y; y.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break; 
			}
	}
}