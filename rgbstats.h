/**
*
*
*   
*
*
*/

#ifndef RGB_STATS_HANDLER_H
#define RGB_STATS_HANDLER_H

#include "rgbhlr.h"
#include <vector>

//
	// A collection of methods encompassing statistical anaylsis for 
	// live data readings of RGB values
//
namespace rgb_dws {

	// Methods for RGB data
	RGB samp_mean(std::vector<RGB> data);
	RGB mode(std::vector<RGB> data);
	RGBCalc variance(std::vector<RGB> data, double mean);
	RGBCalc samp_stand_dev(std::vector<RGB> data, double mean);

	// Methods for individual color data
		// Note that the mean of individual
		// colors can also be computed from 
		// the 'samp_mean' method
	double r_mean(std::vector<RGB> clr);
	double r_median(std::vector<RGB> clr);
	double r_variance(std::vector<RGB> clr, double rMean);
	double r_stand_dev(std::vector<RGBr> clr, double rMean);

	double g_mean(std::vector<RGB> clr);
	double g_median(std::vector<RGB> clr);
	double g_variance(std::vector<RGB> clr, double gMean);
	double g_stand_dev(std::vector<RGBr> clr, double gMean);

	double b_mean(std::vector<RGB> clr);
	double b_median(std::vector<RGB> clr);
	double b_variance(std::vector<RGB> clr, double bMean);
	double b_stand_dev(std::vector<RGBr> clr, double bMean);

// Needed statistical computations:
	// Finding the sample mean
	// Finding median (only viable for individual color values)
	// Finding variance 
	// Finding sample standard deviation
	// Partitioning distribution using quartiles (calculate quartiles)
	// Calculate IQR
	// Calculate Five Number Summary
	// Calculate outliers
		// For both the left and right of the distribution
// Questions to ask:
	// Should we determine the overall average color? ANS: Yes
	// Should we determine the averages of red, green,
		// and blue? ANS: Yes 
	// Should the RGB values be ordered in sep. arrays
		//  of three? ANS: We will need to consider three distributions if thats the case
}
#endif