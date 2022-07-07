#include <iostream>
#include <string>
#include "product.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"
using namespace std;
int main() {

	//Product p(10.41, 13.28, 65, 7, 3.60);
	//p.showProduct();
	APU apu(10.41, 13.28, 65, 7, 3.60, "Ryzen 7 4700G", 8, 16, "AM4", "Radeon Graphics", 4, "DirectX 11");
	apu.showAPU();

	return 0;
}