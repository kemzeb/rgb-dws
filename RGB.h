/**
*
*
*   
*
*
*/

#ifndef RGB_H
#define RGB_H

//
// Headers
#include <cstdlib>


namespace rgb_lsd { // Beginning of namespace rgb_lsd

    struct RGB {
    
    //
    //Constructors
    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);

    //
    // Fields
    uint8_t red, green, blue;


    };
} // End of namespace rgb_lsd

#endif