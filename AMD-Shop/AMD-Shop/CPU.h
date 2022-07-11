#pragma once
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;


class CPU : virtual public Product
{
protected:
	int cores;
	int threads;
	string socket;

public:
	CPU(){}
	CPU(int cores, int threads, string socket, string name = "", float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0) {
		this->cores = cores;
		this->threads = threads;
		this->socket = socket;
	}
	int getCores() override {
		return this->cores;
	}
	void setCores(int cores) override {
		this->cores = cores;
	}

	int getThreads() override {
		return this->threads;
	}           
	void setThreads(int threads) override {
		this->threads = threads;
	}

	string getSocket() override {
		return this->socket;
	}
	void setSocket(string socket) override {
		this->socket = socket;
	}

	string getMaxRes() override;
	void setMaxRes(string maxRes) override;

	Technology getTech() override {
		return Technology();
	}
	void setTech(Technology tech) override;

	string getType() override {
		return typeid(*this).name();
	}
};