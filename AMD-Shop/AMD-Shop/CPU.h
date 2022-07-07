#pragma once
#pragma once
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class CPU :public Product {
protected:
	string m_modelProcessor;
	int m_numberCores;
	double m_numberThreads;
	string m_socket;
public:
	CPU() :Product() {}
	CPU(double weight, double height, int TDP, int nms, double frequency, string modelProcessor, int numberCores, double numberThreads, string socket) :Product(weight, height, TDP, nms, frequency) {
		m_modelProcessor = modelProcessor;
		m_numberCores = numberCores;
		m_numberThreads = numberThreads;
		m_socket = socket;
	}

	void showCPU() {
		cout << "AMD " << m_modelProcessor << " , " << m_numberCores << " Cores, " << m_numberThreads << " Threads, " << " " << m_socket << " socket, " << endl;
		Product::showProduct();
	}

};