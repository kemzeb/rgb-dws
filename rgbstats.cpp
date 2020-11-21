/**
*
*
*   
*
*
*/
#include <vector>

#include "rgbhlr.h"
#include "rgbstats.h"
using namespace rgb_dws;

RGBCalc rgb_dws::samp_mean(std::vector<RGB> data) {
	RGBCalc color;
	int sum_red = 0, sum_green = 0, sum_blue = 0;

	// Sum the squared RGB values
	for(int i = 0; i < data.size(); i++) {
		sum_red 	+= data[i].red * data[i].red; 
		sum_green 	+= data[i].green * data[i].green;
		sum_blue 	+= data[i].blue * data[i].red;
	}
	// Sqrt the mean of their squared values to compute average color
	color.red 	= sqrt(sum_red/data.size());
	color.green = sqrt(sum_green/data.size());
	color.blue 	= sqrt(sum_blue/data.size());

	return color;
}