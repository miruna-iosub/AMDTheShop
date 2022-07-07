#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Product {
private:
	double m_weight;
	double m_height;
	int m_TDP;
	int m_nms;
	double m_frequency;
public:
	Product() {}
	Product(double weight, double height, int TDP, int nms, double frequency) {
		m_weight = weight;
		m_height = height;
		m_TDP = TDP;
		m_nms = nms;
		m_frequency = frequency;
	}

	void showProduct() {
		cout << m_weight << " lbs, " << m_height << " inches, " << m_nms << " nm, " << m_frequency << " GHz, " << m_TDP << " W, " << endl;
	}
};

