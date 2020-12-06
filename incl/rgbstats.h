/***********************************
*	rgbstats.h
* 
* 
* @author Kemal Zebari
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

	/// Methods for RGB data
	
	RGB samp_mean(std::vector<RGB> data);
	RGBCalc median(const std::vector<RGB>& data);
	RGB mode(const std::vector<RGB>& data);
	RGB range(const std::vector<RGB>& data);
	RGB min(const std::vector<RGB>& data);
	RGB max(const std::vector<RGB>& data);
	RGBCalc samp_variance(const std::vector<RGB>& data);
	RGBCalc samp_stand_dev(const std::vector<RGB>& data);

	/// Printing methods
	void freq_dist_RGB(const std::vector<RGB>& data); 

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

} // END OF NAMESPACE 'rgb_dws'
#endif
