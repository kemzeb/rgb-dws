#include "rgbhlr.h"

//////////////////////////////////////////////////
// RGB methods
//////////////////////////////////////////////////

// Constructors
rgb_dws:: RGB::RGB() : red(0), green(0), blue(0) 
{}

rgb_dws:: RGB::RGB(short r, short g, short b) : red(r), green(g), blue(b) 
{}

//////////////////////////////////////////////////
// RGBCalc methods
//////////////////////////////////////////////////

// Constructors
rgb_dws:: RGBCalc::RGBCalc() : red(0), green(0), blue(0)
{}

rgb_dws:: RGBCalc::RGBCalc(double r, double g, double b) : red(r), green(g), blue(b)
{}

rgb_dws:: RGBCalc::RGBCalc(const rgb_dws::RGBCalc& c) : red(c.red), green(c.green), blue(c.blue)
{}
	
