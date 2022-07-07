#pragma once
#pragma once
#include"CPU.h"
#include"GPU.h"

class APU : public CPU, public GPU {

public:
	APU() :CPU(), GPU() {}
	APU(double weight, double height, int TDP, int nms, double frequency, string modelProcessor, int numberCores, double numberThreads, string socket, string modelGraphics, int maxResolution, string TechVersion) :
		CPU(weight, height, TDP, nms, frequency, modelProcessor, numberCores, numberThreads, socket),
		GPU(weight, height, TDP, nms, frequency, modelGraphics, maxResolution, TechVersion) {

	}

	void showAPU() {
		CPU::showCPU();
		GPU::showGPU();
	}
};