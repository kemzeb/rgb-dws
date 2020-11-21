/**
*
*	Manual-testing file
* 	for stat implementations
*
*/
#include <iostream>
#include <vector>
#include <cstdlib>

#include "rgbhlr.h"
#include "rgbstats.h"
using namespace rgb_dws;

// struct Color {
// 	Color() : color(0)
// 	{}
// 	Color(uint8_t c) : color(c) 
// 	{}

// 	uint8_t color;
// }

int main() {
	srand(time(NULL));
	std::vector<RGB> d; 
	d.resize(30);

std::cout << "Red\tGreen\tBlue\n";

	for(int i = 0; i < d.size(); i++) {
		d[i].red 	= rand() % 256;
		d[i].green 	= rand() % 256;
		d[i].blue 	= rand() % 256;
		std::cout << d[i].red << "\t" << d[i].green << "\t" << d[i].blue << "\n";
	}


	RGBCalc test = samp_mean(d);
	std::cout << "\n";
	std::cout << test.red << " " << test.green << " " << test.blue << "\n";
	return 0;
}
