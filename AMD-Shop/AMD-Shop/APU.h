#pragma once
#pragma once
#include"CPU.h"
#include"GPU.h"
using namespace std;

class APU : public CPU, public GPU
{
public:
	APU();
	APU(string name, float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, string socket, string maxRes, Technology tech);

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

	string getMaxRes() override {
		return this->maxRes;
	}
	void setMaxRes(string maxRes) override {
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


