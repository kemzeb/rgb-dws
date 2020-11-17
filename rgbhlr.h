/**
*
*
*   
*
*
*/

#ifndef RGB_HANDLER_H
#define RGB_HANDLER_H

#include <cstdlib>

namespace rgb_dws {
    struct RGB {
        //
        // Constructors
        RGB();
        RGB(uint8_t r, uint8_t g, uint8_t b);

        //
        // Methods

        // A conversion method from input of the color sensor to accurate RGB value needed?

        //
        // Fields
        uint8_t red, green, blue;
    };

    // struct for calculations on RGB values (i.e mean, stand. dev., etc)
    struct RGBCalc {
        RGBCalc(double r, double g, double b);

        double red, green, blue;

    };

} // END OF NAMESPACE 'rgb_dws'

#endif