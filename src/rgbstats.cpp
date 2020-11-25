/**
*
*
*   
*
*
*/
#include <vector>
#include <algorithm>

#include "rgbhlr.h"
#include "rgbstats.h"
using namespace rgb_dws;

RGB rgb_dws::samp_mean(std::vector<RGB> data) {
	RGB color;
	int sum_red = 0, sum_green = 0, sum_blue = 0;

	// Sum the squared RGB values
	for(int i = 0; i < data.size(); i++) {
		sum_red 	+= data[i].red; 
		sum_green 	+= data[i].green;
		sum_blue 	+= data[i].blue;
	}
	// Compute their means
	color.red		= (short)sum_red/data.size();
	color.green		= (short)sum_green/data.size();
	color.blue		= (short)sum_blue/data.size();

	return color;
}
