/**
*
*
*   
*
*
*/
#include "RGB.h"
#include <iostream>
#include <cstdint>

namespace rgb_lsd {
	RGB::RGB() {
		red = 0, green = 0, blue = 0;
	}

    RGB::RGB(uint8_t r, uint8_t g, uint8_t b) {
    	red = r, green = g, blue = b;
    } // need to implement input checking
}