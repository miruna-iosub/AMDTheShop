#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "products.h"
#include "menu.h"
using namespace std;

void ElementeProduct(char weight[], char height[], char TDP[], char nm[], char memory[], char freq[], char price[], char releasedate[]) {
	cout << "\n\t\t-> Weight: " << weight << "mm; ";
	cout << "\n\t\t-> Height: " << height << "mm; ";
	cout << "\n\t\t-> TDP: " << TDP << ';';
	cout << "\n\t\t-> nm: " << nm << ';';
	cout << "\n\t\t-> Memory: " << memory << "GB;";
	cout << "\n\t\t-> Clock Frequency: " << freq << "GHz; ";
	cout << "\n\t\t-> Price: " << price << "Eur; ";
	cout << "\n\t\t-> Release Date: " << releasedate << ';';
}
void ElementeCPU(char core[], char threads[], char socket[]) {
	cout << "\n\t\t-> Core: " << core << ';';
	cout << "\n\t\t-> Threads: " << threads << ';';
	cout << "\n\t\t-> Socket: " << socket << ';';
}
void ElementeGPU(char max_resolurion[], char tech[]) {
	cout << "\n\t\t-> Max Resolution: " << max_resolurion << ';';
	cout << "\n\t\t-> Support Technologies: " << tech << ';';
}  

void ListProduct(string filename) {
	string	type;
	char name[100], weight[10], height[10], tdp[10], freq[10], price[10], nm[10], memory[10], core[10], threads[10], releasedate[25], tech[25], socket[10], max_resolution[15];
	fstream read_from_file;
	read_from_file.open(filename, fstream::in);
	int i = 0;
	while (read_from_file >> type) {
		i++;
		read_from_file.getline(name, 100, ';');
		cout << '\n' << i << ". " << name << ": ";
		if (type == "CPU") {
			read_from_file.getline(core, 10, ';');
			read_from_file.getline(threads, 10, ';');
			read_from_file.getline(socket, 10, ';');
			ElementeCPU(core, threads, socket);
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
		else if (type == "GPU") {
			read_from_file.getline(max_resolution, 15, ';');
			read_from_file.getline(tech, 25, ';');
			ElementeGPU(max_resolution, tech);
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
		else {
			read_from_file.getline(core, 10, ';');
			read_from_file.getline(threads, 10, ';');
			read_from_file.getline(socket, 10, ';');
			ElementeCPU(core, threads, socket);
			read_from_file.getline(max_resolution, 15, ';');
			read_from_file.getline(tech, 25, ';');
			ElementeGPU(max_resolution, tech);
			read_from_file.getline(weight, 10, ';');
			read_from_file.getline(height, 10, ';');
			read_from_file.getline(tdp, 10, ';');
			read_from_file.getline(nm, 10, ';');
			read_from_file.getline(memory, 10, ';');
			read_from_file.getline(freq, 10, ';');
			read_from_file.getline(price, 10, ';');
			read_from_file.getline(releasedate, 10, ';');
			ElementeProduct(weight, height, tdp, nm, memory, freq, price, releasedate);
		}
	}
	read_from_file.close();
} 


void AddProduct(char product_name[],string username) {
	string type;
	char name[100], weight[10], height[10], tdp[10], freq[10], price[10], nm[10], memory[10], core[10], threads[10], releasedate[25], tech[25], socket[10], max_resolution[15];
	fstream readproduct;
	readproduct.open("products.txt", fstream::in);
	while (readproduct >> type) {
		readproduct.ignore();
		readproduct.getline(name, 100, ';');
		if ((strcmp(name, product_name)) == 0)
		{
			if (type == "CPU") {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else if (type == "GPU") {
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			else {
				readproduct.getline(core, 10, ';');
				readproduct.getline(threads, 10, ';');
				readproduct.getline(socket, 10, ';');
				readproduct.getline(max_resolution, 15, ';');
				readproduct.getline(tech, 25, ';');
				readproduct.getline(weight, 10, ';');
				readproduct.getline(height, 10, ';');
				readproduct.getline(tdp, 10, ';');
				readproduct.getline(nm, 10, ';');
				readproduct.getline(memory, 10, ';');
				readproduct.getline(freq, 10, ';');
				readproduct.getline(price, 10, ';');
				readproduct.getline(releasedate, 10, ';');
			}
			fstream writef;
			string filename;
			filename = username + "_cart.txt";
			writef.open(filename, fstream::app | fstream::out);
			writef << type << ' ' << name << "; ";
			if (type == "CPU") {
				writef << core << "; " << threads << "; " << socket << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			else if (type == "GPU") {
				writef << max_resolution << "; " << tech << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			else {
				writef << core << "; " << threads << "; " << socket << "; " << max_resolution << "; " << tech << "; " << weight << "; " << height << "; " << tdp << "; " << nm << "; " << memory << "; " << freq << "; " << price << "; " << releasedate << "; \n";
			}
			writef.close();
		}
	}
	readproduct.close();
	cout << "Success!!"; Sleep(700);
}
void DeleteProduct(char product_name[], string filename) {
	fstream readproduct;
	readproduct.open(filename, fstream::in);
	string type;
	char name[100];
	bool valid = 0;
	char str[5000];
	while (readproduct >> type) {
		readproduct.getline(name, 100, ';');
		strcpy_s(name, name + 1);
		if (strcmp(product_name, name))
		{
			fstream writeproduct;
			writeproduct.open("temp.txt", fstream::app | fstream::out);
			writeproduct << type << ' ' << name << "; ";
			readproduct.getline(str, 5000, '\n');
			writeproduct << str << '\n';
			writeproduct.close();
		}
		else {
			valid = 1;
			readproduct.ignore(5000, '\n');
		}

	}
	readproduct.close();
	if (valid) {
		cout << "\nSuccess";
		char filenm[100];
		strcpy_s(filenm, filename.c_str());
		Sleep(700);
	}
	else {
		cout << "\nNu s-a gasit produsul"; Sleep(700);
	}
	cin.ignore();

}
