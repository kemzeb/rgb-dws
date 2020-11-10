/**
*
*
*   
*
*
*/

#ifndef STAT_HANDLER_H
#define STAT_HANDLER_H

#include "RGB.h"
#include <cstdlib>

//
	// A collection of methods encompassing statistical anaylsis for 
	// live data readings of RGB values
//
namespace rgb_lsd {
	//
	// Methods for RGB data
	double samp_mean(RGB* data);
	double variance(RGB* data, double mean, uint32_t observ);
	double samp_stand_dev(RGB* data, double mean, uint32_t observations);

	// Methods for individual color data
	double clr_mean(uint8_t* clr);
	double clr_median(uint8_t* clr);
	double clr_variance(uint8_t* clr, double m, uint32_t observations);
	double clr_stand_dev(int8_t* clr, double m, uint32_t observations);

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