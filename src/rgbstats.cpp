/***********************************
*	rgbstats.cpp
* Implementation of rgbstats.h
* 
* 
* @author Kemal Zebari
*
*/
#include <iostream>
#include <vector>


#include "rgbhlr.h"
#include "rgbstats.h"

using namespace rgb_dws;

/*****
*	samp_mean
* @param data Dataset of collected RGB colors.
*
* @return Average non-floating value for the red, green, and blue values.
*/
RGB rgb_dws::samp_mean(std::vector<RGB> data) {
	RGB color;

	if(data.size() == 0)
		return color;

	if(data.size() == 1) {
		color.red	= data[0].red;
		color.green = data[0].green;
		color.blue	= data[0].blue;

	} else {
	// Sum the RGB values (summation done by adding from both ends and heading to middle)
	for(int i = 0; i < data.size(); i++) {
		color.red		+= data[i].red; 
		color.green 	+= data[i].green;
		color.blue		+= data[i].blue;
	}
	// Compute their means
	color.red		= color.red/data.size();
	color.green		= color.green/data.size();
	color.blue		= color.blue/data.size();
	}
	return color;
}

/*****
*	median
*		Computes the medians from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Median of the red, green, and blue values.
*/
RGBCalc rgb_dws::median(const std::vector<RGB>& data) {
	RGBCalc medians;
	int size = data.size();
	std::vector<RGB> sortedData = data;

	if(size == 0) // avoid invalid address access
		return medians;

	/* Sort the red values */
	std::sort(sortedData.begin(), sortedData.end(), 
		[ ](const RGB& c1, const RGB& c2) {
			return c1.red < c2.red;
		});

	/// Compute median for red values
	// If oddly-sized dataset
	if(sortedData.size() % 2 != 0)
		medians.redC = sortedData[size / 2].red;
	// If evenly-sized dataset
	else {
		medians.redC = (sortedData[(size - 1) / 2].red + sortedData[size / 2].red) / 2.0;
	}

	/* Now sort the green values */
	std::sort(sortedData.begin(), sortedData.end(), 
		[ ](const RGB& c1, const RGB& c2) {
			return c1.green < c2.green;
		});

	/// Compute median for green values
	if(sortedData.size() % 2 != 0)
		medians.greenC = sortedData[size / 2].green;
	else {
		medians.greenC = (sortedData[(size - 1) / 2].green + sortedData[size / 2].green) / 2.0;
	}

	/* Now sort the blue values */
	std::sort(sortedData.begin(), sortedData.end(), 
		[ ](const RGB& c1, const RGB& c2) {
			return c1.blue < c2.blue;
		});

	/// Compute median for blue values
	if(sortedData.size() % 2 != 0)
		medians.blueC = sortedData[size / 2].blue;
	else {
		medians.blueC = (sortedData[(size - 1) / 2].blue + sortedData[size / 2].blue) / 2.0;
	}
	return medians;
}

/*****
*	mode	
*		Computes the modes from an unsorted RGB vector.
*
* Note: Due the nature of struct RGB, this method
*		will become computationally extensive.
*		This is due to the fact that we must keep
*		the order of the dataset the same
*		but for certain computations sort
*		by red, green, and blue values.
*
* @param data Dataset of collected RGB colors.
*
* @return Interval of mode values averaged for the red, green, and blue values.
*/
// To be implemented

/*****
*	range	
*		Computes the ranges from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Range value of the red, green, and blue values.
*/
RGB rgb_dws::range(const std::vector<RGB>& data) {
	RGB ranges;
	RGB max = rgb_dws::max(data);
	RGB min = rgb_dws::min(data);

	ranges.red		= max.red - min.red;
	ranges.green	= max.green - min.green;
	ranges.blue		= max.blue - min.blue;

	return ranges;
}

/*****
*	min	
*		Computes the mins from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Min value of the red, green, and blue values.
*/
RGB rgb_dws::min(const std::vector<RGB>& data) {
	RGB mins(0,0,0);

	if(data.size() >= 1) {
		mins.red = data[0].red;
		mins.green = data[0].green;
		mins.blue = data[0].blue;

		// Retrieve minimum values for each individual color
		for(int i = 1; i < data.size(); i++) {

			if(data[i].red < mins.red)
				mins.red = data[i].red;

			if(data[i].green < mins.green)
				mins.green = data[i].green;

			if(data[i].blue < mins.blue)
				mins.blue = data[i].blue;
		}
		return mins;
	}
	return mins;
}

/*****
*	max
*		Computes the maxes from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Max value of the red, green, and blue values.   
*/
RGB rgb_dws::max(const std::vector<RGB>& data) {
	RGB maxes(0,0,0);

	if(data.size() >= 1) {
		maxes.red = data[0].red;
		maxes.green = data[0].green;
		maxes.blue = data[0].blue;

		// Retrieve minimum values for each individual color
		for(int i = 1; i < data.size(); i++) {

			if(data[i].red > maxes.red)
				maxes.red = data[i].red;

			if(data[i].green > maxes.green)
				maxes.green = data[i].green;

			if(data[i].blue > maxes.blue)
				maxes.blue = data[i].blue;
		}
		return maxes;
	}
	return maxes;
}

/*****
*	variance
*		Computes the sample variance from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Sampel variance value of the red, green, and blue values. 
*/
RGBCalc rgb_dws::samp_variance(const std::vector<RGB>& data) {
	RGB xBar = rgb_dws::samp_mean(data);
	RGBCalc svari;

	for(int i = 0; i < data.size(); i++) {
		svari.redC		+= (data[i].red - xBar.red) * (data[i].red - xBar.red);
		svari.greenC	+= (data[i].green - xBar.green) * (data[i].green - xBar.green);
		svari.blueC		+= (data[i].blue - xBar.blue) * (data[i].blue - xBar.blue);
	}
	svari.redC		= svari.redC / (data.size()-1);
	svari.greenC	= svari.greenC / (data.size()-1);
	svari.blueC		= svari.blueC / (data.size()-1);

	return svari;
}

/*****
*	variance
*		Computes the sample standard deviation from an unsorted RGB vector.
* @param data Dataset of collected RGB colors.
*
* @return Sample standard deviation value of the red, green, and blue values. 
*/
RGBCalc rgb_dws::samp_stand_dev(const std::vector<RGB>& data) {

	/// Store sample variance into sStandDev
	RGBCalc sStandDev = samp_variance(data);

	/// Solve for standard deviation
	sStandDev.redC= sqrt(sStandDev.redC);
	sStandDev.greenC = sqrt(sStandDev.greenC);
	sStandDev.blueC = sqrt(sStandDev.blueC);

	return sStandDev;
}

/*****
*	freq_dist_RGB
*		Prints a frequency distribution of the RGB dataset.
*		Grouped using class-limit groupint
* @param data Dataset of collected RGB colors.
*
* @return None.
*/
void rgb_dws::freq_dist_RGB(const std::vector<RGB>& data) {

}


