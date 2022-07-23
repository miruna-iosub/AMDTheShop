#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "users.h"
using namespace std;

class Product {
protected:
	char m_name[100];
	float m_weight;
	float m_height;
	float m_TDP;
	int m_nm;
	int m_memory;
	float m_clock_freq;
	float m_price;
	char m_release_date[25];

public:
	Product& SetName() {
		cin.ignore();
		cout << "Name: ";
		cin.getline(m_name, 100);
		return *this;
	}
	Product& SetWeight() {
		cout << "Weight: ";
		cin >> m_weight;
		return *this;
	}
	Product& SetHeight() {
		cout << "Height: ";
		cin >> m_height;
		return *this;
	}
	Product& SetTDP() {
		cout << "TDP: ";
		cin >> m_TDP;
		return *this;
	}
	Product& SetNM() {
		cout << "nm: ";
		cin >> m_nm;
		return *this;
	}
	Product& SetMemory() {
		cout << "Memory: ";
		cin >> m_memory;
		return *this;
	}
	Product& SetFreq() {
		cout << "Clock Frequency: ";
		cin >> m_clock_freq;
		return *this;
	}
	Product& SetPrice() {
		cout << "Price: ";
		cin >> m_price;
		return *this;
	}
	Product& SetReleaseDate() {
		cin.ignore();
		cout << "Release date: ";
		cin.getline(m_release_date, 25);
		return *this;
	}
	string GetName(void) {
		return m_name;
	}
	float GetWeight(void) {
		return m_weight;
	}
	float GetHeight(void) {
		return m_height;
	}
	float GetTDP(void) {
		return m_TDP;
	}
	int GetNM(void) {
		return m_nm;
	}
	int GetMemory(void) {
		return m_memory;
	}
	float GetFreq(void) {
		return m_clock_freq;
	}
	float GetPrice(void) {
		return m_price;
	}
	string GetReleaseDate(void) {
		return m_release_date;
	}
};
class CPU :public virtual Product {
protected:
	int m_core = 0;
	int m_threads = 0;
	string m_socket;

public:
	CPU& SetCore() {
	cout << "Core: ";
	cin >> m_core;
	return *this;
	}
	CPU& SetThreads() {
	cout << "Treads: ";
	cin >> m_threads;
		return*this;
	}
	CPU& SetSocket() {
		cout << "Socket: ";
		cin.ignore();
		cin >> m_socket;
		return *this;
	}
	int GetCore(void) {
		return m_core;
	}
	int GetThreads(void) {
		return m_threads;
	}
	string GetSocket(void) {
		return m_socket;
	}
	CPU& AddProduct(void) {
		SetName();
		SetCore().SetThreads().SetSocket().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
		cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(string filename) {
		fstream recordP;
		recordP.open(filename, fstream::app | fstream::out);
		recordP << "CPU ";
		recordP << GetName() << "; ";
		recordP << GetCore() << "; ";
		recordP << GetThreads() << "; ";
		recordP << GetSocket() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};
class GPU :public virtual Product {
protected:
	string m_max_resolution;
	char m_tech[25];
public:
	GPU& SetMaxResolution() {
		cout << "Max Resolution: ";
		cin >> m_max_resolution;
		return *this;
	}
	GPU& SetTechnologies() {
		cin.ignore();
		cout << "Support Technologies (OpenGL, DirectX): ";
		cin.getline(m_tech, 25);
		return *this;
	}
	string GetTechnologies(void) {
		return m_tech;
	}
	string GetMaxResolution(void) {
		return m_max_resolution;
	}
	GPU& AddProduct(void) {
		SetName();
		SetMaxResolution().SetTechnologies().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
	cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(string filename) {
	fstream recordP;
		recordP.open(filename, std::fstream::app | std::fstream::out);
		recordP << "GPU ";
		recordP << GetName() << "; ";
		recordP << GetMaxResolution() << "; ";
		recordP << GetTechnologies() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};
class APU : public CPU, public GPU {
public:
	APU& AddProduct(void) {
		SetName();
		SetCore().SetThreads().SetSocket();
		SetMaxResolution().SetTechnologies().SetWeight().SetHeight().SetTDP().SetNM().SetMemory().SetFreq().SetPrice().SetReleaseDate();
		cout << "Succes!!\n";
		Sleep(700);
		return *this;
	}
	void RegisterProduct(string filename) {
		fstream recordP;
		recordP.open(filename, fstream::app | fstream::out);
		recordP << "APU ";
		recordP << GetName() << "; ";
		recordP << GetCore() << "; ";
		recordP << GetThreads() << "; ";
		recordP << GetSocket() << "; ";
		recordP << GetMaxResolution() << "; ";
		recordP << GetTechnologies() << "; ";
		recordP << GetWeight() << "; ";
		recordP << GetHeight() << "; ";
		recordP << GetTDP() << "; ";
		recordP << GetNM() << "; ";
		recordP << GetMemory() << "; ";
		recordP << GetFreq() << "; ";
		recordP << GetPrice() << "; ";
		recordP << GetReleaseDate() << ";\n";
		recordP.close();
	}
};

void ElementeProduct(char weight[], char height[], char TDP[], char nm[], char memory[], char freq[], char price[], char releasedate[]);
void ElementeCPU(char core[], char threads[], char socket[]);
void ElementeGPU(char max_resolurion[], char tech[]);

void ListProduct(string filename);
void DeleteProduct(char product_name[], string filename);
void AddProduct(char product_name[], string username);