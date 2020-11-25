#include "rgbhlr.h"

//////////////////////////////////////////////////
// RGB methods
//////////////////////////////////////////////////

// Constructors
rgb_dws:: RGB::RGB() : red(0), green(0), blue(0) 
{}

rgb_dws:: RGB::RGB(short r, short g, short b) : red(r), green(g), blue(b) 
{}

rgb_dws:: RGB::RGB(const RGB& c) : red(c.red), green(c.green), blue(c.blue)
{}

//////////////////////////////////////////////////
// RGBCalc methods
//////////////////////////////////////////////////

// Constructors
rgb_dws:: RGBCalc::RGBCalc() : redC(0), greenC(0), blueC(0)
{}

rgb_dws:: RGBCalc::RGBCalc(double r, double g, double b) : redC(r), greenC(g), blueC(b)
{}

rgb_dws:: RGBCalc::RGBCalc(const rgb_dws::RGBCalc& c) : redC(c.redC), greenC(c.greenC), blueC(c.blueC)
{}
	
