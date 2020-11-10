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

namespace rgb_lsd {

	//
	// Methods
	double samp_mean(uint8_t r, uint8_t g, uint8_t b);
	double samp_median(uint8_t r, uint8_t g, uint8_t b);
	double variance(RGB* data, double mean, uint32_t observations);
	double samp_stand_dev(RGB* data, double mean, uint32_t observations);


// Needed statistical computations:
	// Finding the sample mean
	// Finding variance
	// Finding sample standard deviation
	// Partitioning distribution using quartiles (calculate quartiles)
	// Calculate IQR
	// Calculate Five Number Summary
	// Calculate outliers
		// For both the left and right of the distribution
// Questions to ask:
	// Should we determine the overall average color?	Yes
	// Should we determine the averages of red, green,
		// and blue?									Possibly 
	// Should the RGB values be ordered in sep. arrays
		//  of three?									We will need to consider three distributions then
}
#endif