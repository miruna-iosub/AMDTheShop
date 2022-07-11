#pragma once
#include "product.h"
#include <iostream>
#include <string>
using namespace std;


class GPU : virtual public Product
{
protected:
	std::string maxRes;
	Technology tech;

public:
	GPU(){}
	GPU(string maxRes, Technology tech, string name = "", float weight = 0.0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0) {

		this->maxRes = maxRes;
		this->tech = tech;
	}
	int getCores() override {
		return 0;
	}
	void setCores(int cores) override{}

	int getThreads() override {
		return 0;
	}               
	void setThreads(int threads) override {
	}

	string getSocket() override{}
	void setSocket(string socket) override;

	std::string getMaxRes() override {
		return this->maxRes;
	}
	void setMaxRes(std::string maxRes) override {

		this->maxRes = maxRes;
	}

	Technology getTech() override {
		return this->tech;
	}
	void setTech(Technology tech) override {
		this->tech = tech;
	}

	string getType() override {
		return typeid(*this).name();
	}
};
