#pragma once
#include <iostream>
#include <string>
using namespace std;


#pragma once
#include <string>
#include <string>
using namespace std;

enum Technology { OpenGL = 1, DirectX = 2 };
const char* ToString(Technology t);

class Product
{
protected:
	string name;
	float weight;
	int height;
	int TDP;
	int nms;
	int memory; 
	float frequency;

public:
	Product() {}
	Product(string name, float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0) {
		this->name = name;
		this->weight = weight;
		this->height = height;
		this->TDP = TDP;
		this->nms = nms;
		this->memory = memory;
		this->frequency = frequency;
	}

	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}

	float getWeight() {
		return weight;
	}
	void setWeight(float weight) {
		this->weight = weight;
	}

	int getHeight() {
		return height;
	}
	void setHeight(int height) {
		this->height = height;
	}

	int getTDP() {
		return TDP;
	}
	void setTDP(int TDP) {
		this->TDP = TDP;
	}

	int getNms() {
		return nms;
	}
	void setNms(int nms) {
		this->nms = nms;
	}

	int getMemory() {
		return memory;
	}
	void setMemory(int memory) {

		this->memory = memory;
	}

	float getFrequency() {
		return frequency;
	}
	void setFrequency(float frequency) {
		this->frequency = frequency;
	}

	virtual int getCores() = 0;
	virtual void setCores(int cores) = 0;

	virtual int getThreads() = 0;
	virtual void setThreads(int threads) = 0;

	virtual string getSocket() = 0;
	virtual void setSocket(string socket) = 0;

	virtual string getMaxRes() = 0;
	virtual void setMaxRes(string maxRes) = 0;

	virtual Technology getTech() = 0;
	virtual void setTech(Technology tech) = 0;

	virtual string getType() = 0;
};
