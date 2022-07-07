#pragma once
#include "product.h"
#include <iostream>
#include <string>
using namespace std;
class GPU :public Product {
protected:
	string m_modelGraphics;
	int m_maxResolution;
	string m_TechVersion;
public:
	GPU() :Product() {}

	GPU(double weight, double height, int TDP, int nms, double frequency, string modelGraphics, int maxResolution, string TechVersion) :Product(weight, height, TDP, nms, frequency) {
		m_maxResolution = maxResolution;
		m_TechVersion = TechVersion;
		m_modelGraphics = modelGraphics;
	}

	~GPU();
	void showGPU() {
		cout << m_modelGraphics << ", " << m_TechVersion << ", " << m_maxResolution << "k Resolution" << endl;
	}
	void showGPUProduct() {
		cout << m_modelGraphics << ", " << m_TechVersion << ", " << m_maxResolution << "k Resolution" << endl;
		Product::showProduct();
	}
};